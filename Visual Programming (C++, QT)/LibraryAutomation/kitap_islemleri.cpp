#include "kitap_islemleri.h"
#include "ui_kitap_islemleri.h"
#include "mainwindow.h"

kitap_islemleri::kitap_islemleri(QSqlDatabase veriTabani, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::kitap_islemleri)
{
    ui->setupUi(this);

    sorguKitapCekAl = new QSqlQuery(veriTabani);
    sorguOduncAlinanKitap = new QSqlQuery(veriTabani);
    sorguTeslimEdilenKitap = new QSqlQuery(veriTabani);
    silmeSorgusuTablolarKontrol = new QSqlQuery(veriTabani);
    kitaplariListelemeFonksiyonu();
    oduncAlinanVeTeslimEdilenlerinSorgusu();
}


kitap_islemleri::~kitap_islemleri()
{
    delete ui;
}

void kitap_islemleri::kitaplariListelemeFonksiyonu()
{
    sorguKitapCekAl->prepare("select * from kitap_tablosu");

    if(!sorguKitapCekAl->exec()){
        QMessageBox::critical(this, "Hata", sorguKitapCekAl->lastError().text(), "Ok");
        return;
    }

    modelKitapCekAl = new QSqlQueryModel();
    modelKitapCekAl->setQuery(*sorguKitapCekAl);
    ui->tableView_Kitaplar->setModel(modelKitapCekAl);
}


void kitap_islemleri::oduncAlinanVeTeslimEdilenlerinSorgusu()
{
    sorguOduncAlinanKitap->prepare("select * from odunc_alinan_tablosu where kitap_no=?");
    sorguOduncAlinanKitap->addBindValue(ui->lineEdit_Kitap_No->text().toInt());

    if(!sorguOduncAlinanKitap->exec()){
        QMessageBox::critical(this, "Hata", sorguOduncAlinanKitap->lastError().text(), "Ok");
        return;
    }
    modelOduncAlinanKitap = new QSqlQueryModel();
    modelOduncAlinanKitap->setQuery(*sorguOduncAlinanKitap);
    ui->tableView_Odunc_Alinma->setModel(modelOduncAlinanKitap);


    sorguTeslimEdilenKitap->prepare("select * from odunc_teslim_edilen_tablosu where kitap_no=?");
    sorguTeslimEdilenKitap->addBindValue(ui->lineEdit_Kitap_No->text().toInt());
    if(!sorguTeslimEdilenKitap->exec()){
        QMessageBox::critical(this, "Hata", sorguTeslimEdilenKitap->lastError().text(), "Ok");
        return;
    }
    modelTeslimEdilenKitap = new QSqlQueryModel();
    modelTeslimEdilenKitap->setQuery(*sorguTeslimEdilenKitap);
    ui->tableView_Daha_Onceden_Odunc_Alinma->setModel(modelTeslimEdilenKitap);
}


void kitap_islemleri::on_pushButton_Yeni_Kayit_clicked()
{
    if (ui->lineEdit_Kitap_Ad->text() == "" or ui->lineEdit_Stok->text() =="" ){
        QMessageBox::critical(this, "Hata!", "Gerekli alanlari doldurunuz!", "Ok");
    }
    else{
        sorguKitapCekAl->prepare("insert into kitap_tablosu(kitap_ad, kitap_sayisi) values(?,?)");
        sorguKitapCekAl->addBindValue(ui->lineEdit_Kitap_Ad->text());
        sorguKitapCekAl->addBindValue(ui->lineEdit_Stok->text().toInt());

        if(!sorguKitapCekAl->exec()){
            QMessageBox::critical(this,"Hata",sorguKitapCekAl->lastError().text(),"Okay");
        }

        kitaplariListelemeFonksiyonu();

        ui->lineEdit_Kitap_No->setText("");
        ui->lineEdit_Kitap_Ad->setText("");
        ui->lineEdit_Stok->setText("");
    }
}


void kitap_islemleri::on_pushButton_Guncelle_clicked()
{
    if (ui->lineEdit_Kitap_Ad->text() == "" or ui->lineEdit_Stok->text() =="" ){
        QMessageBox::critical(this, "Hata!", "Gerekli alanlari doldurunuz!", "Ok");
    }
    else{
        sorguKitapCekAl->prepare("update kitap_tablosu set kitap_ad=?,kitap_sayisi=? where kitap_no=?");
        sorguKitapCekAl->addBindValue(ui->lineEdit_Kitap_Ad->text());
        sorguKitapCekAl->addBindValue(ui->lineEdit_Stok->text().toInt());
        sorguKitapCekAl->addBindValue(ui->lineEdit_Kitap_No->text().toInt());

        if(!sorguKitapCekAl->exec()){
            QMessageBox::critical(this,"Hata",sorguKitapCekAl->lastError().text(),"Okay");
        }

        kitaplariListelemeFonksiyonu();

        ui->lineEdit_Kitap_No->setText("");
        ui->lineEdit_Kitap_Ad->setText("");
        ui->lineEdit_Stok->setText("");
     }
}


void kitap_islemleri::on_pushButton_Sil_clicked()
{
    if (ui->lineEdit_Kitap_No->text().isEmpty()){
        QMessageBox::critical(this, "Hata!", "Gerekli alanları doldurunuz!", "Ok");
    }
    else{
        silmeSorgusuTablolarKontrol->prepare("SELECT * FROM odunc_alinan_tablosu WHERE kitap_no = ?");
        silmeSorgusuTablolarKontrol->addBindValue(ui->lineEdit_Kitap_No->text().toInt());

        if (silmeSorgusuTablolarKontrol->exec() && silmeSorgusuTablolarKontrol->next()){
            QMessageBox::critical(this, "Hata", "Bu kitap silinemez. Bu kitap bir üyeye ödünç verilmiştir.", "Ok");
        }
        else{
            silmeSorgusuTablolarKontrol->clear();
            silmeSorgusuTablolarKontrol->prepare("DELETE FROM kitap_tablosu WHERE kitap_no = ?");
            silmeSorgusuTablolarKontrol->addBindValue(ui->lineEdit_Kitap_No->text().toInt());

            if (!silmeSorgusuTablolarKontrol->exec()){
                QMessageBox::critical(this, "Hata", silmeSorgusuTablolarKontrol->lastError().text(), "Ok");
            }
            else{
                kitaplariListelemeFonksiyonu();
            }
        }

        ui->lineEdit_Kitap_No->setText("");
        ui->lineEdit_Kitap_Ad->setText("");
        ui->lineEdit_Stok->setText("");
    }
}




void kitap_islemleri::on_tableView_Kitaplar_clicked(const QModelIndex &index)
{
        ui->lineEdit_Kitap_No->setText(modelKitapCekAl->index(index.row(),0).data().toString());
        ui->lineEdit_Kitap_Ad->setText(modelKitapCekAl->index(index.row(),1).data().toString());
        ui->lineEdit_Stok->setText(modelKitapCekAl->index(index.row(),2).data().toString());
        kitaplariListelemeFonksiyonu();
        oduncAlinanVeTeslimEdilenlerinSorgusu();
}


void kitap_islemleri::closeEvent(QCloseEvent *event)
{
    this->close();
    MainWindow *dialog = new MainWindow();
    dialog->show();
}
