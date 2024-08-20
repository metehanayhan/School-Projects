#include "uye_islemleri.h"
#include "ui_uye_islemleri.h"
#include "mainwindow.h"

uye_islemleri::uye_islemleri(QSqlDatabase veriTabani, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uye_islemleri)
{
    ui->setupUi(this);

    sorgu = new QSqlQuery(veriTabani);
    sorguOduncAlinanVarMi = new QSqlQuery(veriTabani);
    uyeleriListelemeFonksiyonu();
}


uye_islemleri::~uye_islemleri()
{
    delete ui;
}


void uye_islemleri::on_tableView_Uyeler_clicked(const QModelIndex &index)
{
    ui->lineEdit_Uye_No->setText(model->index(index.row(),0).data().toString());
    ui->lineEdit_Uye_Ad->setText(model->index(index.row(),1).data().toString());
    ui->lineEdit_Uye_Soyad->setText(model->index(index.row(),2).data().toString());
}


void uye_islemleri::uyeleriListelemeFonksiyonu()
{
    sorgu->prepare("select * from uye_tablosu");

    if(!sorgu->exec()){
        QMessageBox::critical(this, "Hata", sorgu->lastError().text(), "Ok");
        return;
    }

    model = new QSqlQueryModel();
    model->setQuery(*sorgu);
    ui->tableView_Uyeler->setModel(model);
}


void uye_islemleri::on_pushButton_Yeni_Kayit_clicked()
{
    if (ui->lineEdit_Uye_Ad->text() == "" or ui->lineEdit_Uye_Soyad->text() ==""){
        QMessageBox::critical(this, "Hata!", "Gerekli alanlari doldurunuz!", "Ok");
    }
    else{
        sorgu->prepare("insert into uye_tablosu(uye_ad,uye_soyad) values(?,?)");
        sorgu->addBindValue(ui->lineEdit_Uye_Ad->text());
        sorgu->addBindValue(ui->lineEdit_Uye_Soyad->text());

        if(!sorgu->exec()){
            QMessageBox::critical(this,"Hata",sorgu->lastError().text(),"Okay");
        }

        uyeleriListelemeFonksiyonu();

        ui->lineEdit_Uye_Ad->setText("");
        ui->lineEdit_Uye_Soyad->setText("");
        ui->lineEdit_Uye_No->setText("");
    }
}


void uye_islemleri::on_pushButton_Guncelle_clicked()
{
    if (ui->lineEdit_Uye_Ad->text() == "" or ui->lineEdit_Uye_Soyad->text() =="" ){
        QMessageBox::critical(this, "Hata!", "Gerekli alanlari doldurunuz!", "Ok");
    }
    else{
        sorgu->prepare("update uye_tablosu set uye_ad=?,uye_soyad=? where uye_no=?");
        sorgu->addBindValue(ui->lineEdit_Uye_Ad->text());
        sorgu->addBindValue(ui->lineEdit_Uye_Soyad->text());
        sorgu->addBindValue(ui->lineEdit_Uye_No->text().toInt());

        if(!sorgu->exec()){
            QMessageBox::critical(this,"Hata",sorgu->lastError().text(),"Okay");
        }

        uyeleriListelemeFonksiyonu();

        ui->lineEdit_Uye_Ad->setText("");
        ui->lineEdit_Uye_Soyad->setText("");
        ui->lineEdit_Uye_No->setText("");
     }
}


void uye_islemleri::on_pushButton_Sil_clicked()
{
    if (ui->lineEdit_Uye_No->text().isEmpty()){
        QMessageBox::critical(this, "Hata!", "Listeden bir kayıt seçiniz!", "Ok");
    }
    else{
        sorguOduncAlinanVarMi->prepare("SELECT * FROM odunc_alinan_tablosu WHERE uye_no = ?");
        sorguOduncAlinanVarMi->addBindValue(ui->lineEdit_Uye_No->text().toInt());

        if (sorguOduncAlinanVarMi->exec() && sorguOduncAlinanVarMi->next()){
            QMessageBox::critical(this, "Hata", "Bu üye silinemez. Üyenin henüz teslim etmediği kitaplar vardır.", "Ok");
        }
        else{
            sorgu->prepare("DELETE FROM uye_tablosu WHERE uye_no = ?");
            sorgu->addBindValue(ui->lineEdit_Uye_No->text().toInt());

            if (!sorgu->exec()){
                QMessageBox::critical(this, "Hata", sorgu->lastError().text(), "Ok");
            }
            else{
                uyeleriListelemeFonksiyonu();
            }
        }

        ui->lineEdit_Uye_Ad->setText("");
        ui->lineEdit_Uye_Soyad->setText("");
        ui->lineEdit_Uye_No->setText("");
    }
}


void uye_islemleri::closeEvent(QCloseEvent *event)
{
    this->close();
    MainWindow *dialog = new MainWindow();
    dialog->show();
}
