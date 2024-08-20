#include "uyeislemleri.h"
#include "ui_uyeislemleri.h"

uyeislemleri::uyeislemleri(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uyeislemleri)
{
    ui->setupUi(this);
}

uyeislemleri::~uyeislemleri()
{
    delete ui;
}
