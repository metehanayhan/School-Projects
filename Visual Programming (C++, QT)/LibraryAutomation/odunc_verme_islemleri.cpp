#include "odunc_verme_islemleri.h"
#include "ui_odunc_verme_islemleri.h"
#include "mainwindow.h"


odunc_verme_islemleri::odunc_verme_islemleri(QSqlDatabase veriTabani, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::odunc_verme_islemleri)
{
    ui->setupUi(this);
    sorguOduncAlinan = new QSqlQuery(veriTabani);
    sorguTeslimEdilen = new QSqlQuery(veriTabani);
    oduncAlinanKitaplariListelemeFOnksiyonu();
    teslsimEdilenKitaplariListelemeFonksiyonU();
}


odunc_verme_islemleri::~odunc_verme_islemleri()
{
    delete ui;
}


void odunc_verme_islemleri::oduncAlinanKitaplariListelemeFOnksiyonu()
{
    sorguOduncAlinan->prepare("select * from odunc_alinan_tablosu");

    if(!sorguOduncAlinan->exec()){
        QMessageBox::critical(this,"Hata",sorguOduncAlinan->lastError().text(),"Ok");
        return;
    }

    modelOduncAlinan = new QSqlQueryModel();
    modelOduncAlinan->setQuery(*sorguOduncAlinan);
    ui->tableView_Odunc_Alinan_Kitaplar_Listesi->setModel(modelOduncAlinan);
}


void odunc_verme_islemleri::teslsimEdilenKitaplariListelemeFonksiyonU()
{
    sorguTeslimEdilen->prepare("SELECT uye_no, kitap_no, verme_tarihi, alma_tarihi, borc FROM odunc_teslim_edilen_tablosu");

    if(!sorguTeslimEdilen->exec()){
        QMessageBox::critical(this, "Hata", sorguTeslimEdilen->lastError().text(), "Ok");
    }

    modelTeslimEdilen = new QSqlQueryModel();
    modelTeslimEdilen->setQuery(*sorguTeslimEdilen);
    ui->tableView_Teslim_Edilen_Kitaplar_Listesi->setModel(modelTeslimEdilen);

    // Ilgili sutunların basliklarini ayarla
    modelTeslimEdilen->setHeaderData(0, Qt::Horizontal, tr("Üye No"));
    modelTeslimEdilen->setHeaderData(1, Qt::Horizontal, tr("Kitap No"));
    modelTeslimEdilen->setHeaderData(2, Qt::Horizontal, tr("Verme Tarihi"));
    modelTeslimEdilen->setHeaderData(3, Qt::Horizontal, tr("Alma Tarihi"));
    modelTeslimEdilen->setHeaderData(4, Qt::Horizontal, tr("Borç"));

    // Sutun genisliklerini ayarla (istege bagli)
    ui->tableView_Teslim_Edilen_Kitaplar_Listesi->setColumnWidth(0, 80);
    ui->tableView_Teslim_Edilen_Kitaplar_Listesi->setColumnWidth(1, 80);
    ui->tableView_Teslim_Edilen_Kitaplar_Listesi->setColumnWidth(2, 120);
    ui->tableView_Teslim_Edilen_Kitaplar_Listesi->setColumnWidth(3, 120);
    ui->tableView_Teslim_Edilen_Kitaplar_Listesi->setColumnWidth(4, 80);
}


void odunc_verme_islemleri::on_tableView_Odunc_Alinan_Kitaplar_Listesi_clicked(const QModelIndex &index)
{
    ui->lineEdit_Uye_No->setText(modelOduncAlinan->index(index.row(),0).data().toString());
    ui->lineEdit_Kitap_No->setText(modelOduncAlinan->index(index.row(),1).data().toString());
}


void odunc_verme_islemleri::on_pushButton_Odunc_Kitap_Teslim_Et_clicked()
{
    int uyeNo = ui->lineEdit_Uye_No->text().toInt();
    int kitapNo = ui->lineEdit_Kitap_No->text().toInt();

    // Tarih bilgilerini al
    QDate almaTarihi = modelOduncAlinan->index(ui->tableView_Odunc_Alinan_Kitaplar_Listesi->currentIndex().row(), 2).data().toDate();
    QDate vermeTarihi = ui->dateEdit_Odunc_Verme_Tarihi->date();

    // Borc hesaplama
    int gunSayisi = vermeTarihi.daysTo(QDate::currentDate());
    double borc = 0.0;

    if (gunSayisi > 15){
        borc = (gunSayisi - 15) * 1.0;
    }

    // Teslim edilen kitabı odunc_alinan_tablosu isimli veri tabanından silme islemi.
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM odunc_alinan_tablosu WHERE uye_no = :uyeNo AND kitap_no = :kitapNo");
    deleteQuery.bindValue(":uyeNo", uyeNo);
    deleteQuery.bindValue(":kitapNo", kitapNo);

    if (!deleteQuery.exec()){
        QMessageBox::critical(this, "Hata", "Ödünç alınan kitap silinemedi!", "Ok");
        return;
    }

    // Teslim edilen kitabı odunc_teslim_edilen_tablosu isimli veri tabanına ekleme islemi.
    QSqlQuery insertQuery;

    insertQuery.prepare("INSERT INTO odunc_teslim_edilen_tablosu (uye_no, kitap_no, alma_tarihi, verme_tarihi, borc) "
                        "VALUES (:uyeNo, :kitapNo, :almaTarihi, :vermeTarihi, :borc)");
    insertQuery.bindValue(":uyeNo", uyeNo);
    insertQuery.bindValue(":kitapNo", kitapNo);
    insertQuery.bindValue(":vermeTarihi", vermeTarihi);
    insertQuery.bindValue(":almaTarihi", almaTarihi);
    insertQuery.bindValue(":borc", borc);

    if (!insertQuery.exec()){
        QMessageBox::critical(this, "Hata", "Ödünç teslim edilen kayıt oluşturulamadı!", "Ok");
        return;
    }

    // Kitap stok durumunu guncelleme islemi
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE kitap_tablosu SET kitap_sayisi = kitap_sayisi + 1 WHERE kitap_no = :kitapNo");
    updateQuery.bindValue(":kitapNo", kitapNo);

    if (!updateQuery.exec()){
        QMessageBox::critical(this, "Hata", "Kitap stok durumu güncellenemedi!", "Ok");
        return;
    }

    teslsimEdilenKitaplariListelemeFonksiyonU();
    oduncAlinanKitaplariListelemeFOnksiyonu();

    QMessageBox::information(this, "Bilgi", "Kitap başarıyla teslim edildi.", "Ok");
}


void odunc_verme_islemleri::closeEvent(QCloseEvent *event)
{
    this->close();
    MainWindow *dialog = new MainWindow();
    dialog->show();
}
