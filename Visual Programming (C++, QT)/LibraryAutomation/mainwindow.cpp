#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "kitap_islemleri.h"
#include "uye_islemleri.h"
#include "odunc_alma_islemleri.h"
#include "odunc_verme_islemleri.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    veriTabani.setDatabaseName("GP_Odev2_Veritabani.db");
    if(!veriTabani.open()){
        ui->statusbar->showMessage("Veri tabanına bağlanılamadı!");
    }
    else{
         ui->statusbar->showMessage("Veri tabanına bağlanıldı!");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Uye_Islemleri_clicked()
{
    this->hide();
    uye_islemleri *uye = new uye_islemleri(veriTabani);
    uye->show();
}


void MainWindow::on_pushbutton_Kitap_Islemleri_clicked()
{
    this->hide();
    kitap_islemleri *ders = new kitap_islemleri(veriTabani);
    ders->show();
}


void MainWindow::on_pushbutton_Odunc_Alma_Islemleri_clicked()
{
    this->hide();
    odunc_alma_islemleri *oduncAl = new odunc_alma_islemleri(veriTabani);
    oduncAl->show();
}


void MainWindow::on_pushbutton_Odunc_Verme_Islemleri_clicked()
{
    this->hide();
    odunc_verme_islemleri *oduncVer = new odunc_verme_islemleri(veriTabani);
    oduncVer->show();
}

