#include "odunc_alma_islemleri.h"
#include "ui_odunc_alma_islemleri.h"
#include "mainwindow.h"


odunc_alma_islemleri::odunc_alma_islemleri(QSqlDatabase veriTabani, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::odunc_alma_islemleri)
{
    ui->setupUi(this);

    genelSorgu = new QSqlQuery(veriTabani);
    sorguOduncAlinan = new QSqlQuery(veriTabani);
    sorguKitap = new QSqlQuery(veriTabani);
    sorguAyniKitapOduncAlinmisMi = new QSqlQuery(veriTabani);
    uyeleriListelemeFonksiyonu();

    kitaplariListelemeFonksiyonu();

    oduncAlinanKitaplariListelemeFonksiyonu();
}

odunc_alma_islemleri::~odunc_alma_islemleri()
{
    delete ui;
}

void odunc_alma_islemleri::uyeleriListelemeFonksiyonu()
{
    genelSorgu->prepare("select * from uye_tablosu");

    if(!genelSorgu->exec()){
        QMessageBox::critical(this,"Hata",genelSorgu->lastError().text(),"Ok");
        return;
    }

    modelUye = new QSqlQueryModel();
    modelUye->setQuery(*genelSorgu);
    ui->tableView_Tum_Uyeler->setModel(modelUye);
}

void odunc_alma_islemleri::kitaplariListelemeFonksiyonu()
{
    sorguKitap->prepare("select * from kitap_tablosu");

    if(!sorguKitap->exec()){
        QMessageBox::critical(this,"Hata",sorguKitap->lastError().text(),"Ok");
        return;
    }

    modelKitap = new QSqlQueryModel();
    modelKitap->setQuery(*sorguKitap);
    ui->tableView_Tum_Kitaplar->setModel(modelKitap);
}

void odunc_alma_islemleri::oduncAlinanKitaplariListelemeFonksiyonu()
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


void odunc_alma_islemleri::on_tableView_Tum_Kitaplar_clicked(const QModelIndex &index)
{
    ui->lineEdit_Kitap_No->setText(modelKitap->index(index.row(),0).data().toString());
}


void odunc_alma_islemleri::on_tableView_Tum_Uyeler_clicked(const QModelIndex &index)
{
    ui->lineEdit_Uye_No->setText(modelUye->index(index.row(),0).data().toString());
}


void odunc_alma_islemleri::on_pushButton_Odunc_Al_clicked()
{
    genelSorgu->prepare("SELECT kitap_sayisi FROM kitap_tablosu WHERE kitap_no = :kitap_no");
    genelSorgu->bindValue(":kitap_no", ui->lineEdit_Kitap_No->text().toInt());

    if (!genelSorgu->exec()) {
        QMessageBox::critical(this, "Hata", "Sorgu çalıştırılamadı!", "Tamam");
        return;
    }

    if (genelSorgu->next()) {
        int stokSayisi = genelSorgu->value("kitap_sayisi").toInt();

        if (stokSayisi <= 0) {
            QMessageBox::warning(this, "Uyarı", "Seçili kitap stokta bulunmamaktadır!", "Tamam");
            return;
        }

        sorguAyniKitapOduncAlinmisMi->prepare("SELECT * FROM odunc_alinan_tablosu WHERE kitap_no = :kitap_no AND uye_no = :uye_no");
        sorguAyniKitapOduncAlinmisMi->bindValue(":kitap_no", ui->lineEdit_Kitap_No->text().toInt());
        sorguAyniKitapOduncAlinmisMi->bindValue(":uye_no", ui->lineEdit_Uye_No->text().toInt());

        if (sorguAyniKitapOduncAlinmisMi->exec() && sorguAyniKitapOduncAlinmisMi->next()){
            QMessageBox::information(this, "Hata", "Bu üye bu kitabın bir tanesini şu an ödünç almış, tekrar ödünç verilemez!", "Tamam");
        }
        else{
            genelSorgu->prepare("INSERT INTO odunc_alinan_tablosu (uye_no, kitap_no, odunc_alma_tarihi) VALUES (?, ?, ?)");
            genelSorgu->addBindValue(ui->lineEdit_Uye_No->text().toInt());
            genelSorgu->addBindValue(ui->lineEdit_Kitap_No->text().toInt());
            genelSorgu->addBindValue(ui->dateEdit_Odunc_Alma_Tarihi->date().toString("dd.MM.yyyy"));

            if (!genelSorgu->exec()){
                QMessageBox::critical(this, "Hata", "Ekleme sorgusu çalışmıyor!", "Tamam");
                return;
            }

            // Stok sayısını bir azalt
            genelSorgu->prepare("UPDATE kitap_tablosu SET kitap_sayisi = kitap_sayisi - 1 WHERE kitap_no = :kitap_no");
            genelSorgu->bindValue(":kitap_no", ui->lineEdit_Kitap_No->text().toInt());

            if (!genelSorgu->exec()) {
                QMessageBox::critical(this, "Hata", "Stok güncelleme sorgusu çalışmıyor!", "Tamam");
                return;
            }

            oduncAlinanKitaplariListelemeFonksiyonu();
        }
    }
}


void odunc_alma_islemleri::closeEvent(QCloseEvent *event)
{
    this->close();
    MainWindow *dialog = new MainWindow();
    dialog->show();
}

