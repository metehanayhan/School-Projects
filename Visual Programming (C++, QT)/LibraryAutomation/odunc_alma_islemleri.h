#ifndef ODUNC_ALMA_ISLEMLERI_H
#define ODUNC_ALMA_ISLEMLERI_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>

namespace Ui {
class odunc_alma_islemleri;
}

class odunc_alma_islemleri : public QDialog
{
    Q_OBJECT

public:
    explicit odunc_alma_islemleri(QSqlDatabase veriTabani, QWidget *parent = nullptr);
    ~odunc_alma_islemleri();

    void listele();

    void closeEvent(QCloseEvent *event);

    void uyeleriListelemeFonksiyonu();

    void kitaplariListelemeFonksiyonu();

    void oduncAlinanKitaplariListelemeFonksiyonu();

private slots:
    void on_pushButton_Odunc_Al_clicked();

    void on_tableView_Tum_Kitaplar_clicked(const QModelIndex &index);

    void on_tableView_Tum_Uyeler_clicked(const QModelIndex &index);

private:
    Ui::odunc_alma_islemleri *ui;

    QSqlQuery *genelSorgu;

    QSqlQueryModel *modelUye;

    QSqlQuery *sorguKitap;

    QSqlQueryModel *modelKitap;

    QSqlQuery *sorguOduncAlinan;

    QSqlQueryModel *modelOduncAlinan;

    QSqlQuery *sorguAyniKitapOduncAlinmisMi;

};

#endif // ODUNC_ALMA_ISLEMLERI_H
