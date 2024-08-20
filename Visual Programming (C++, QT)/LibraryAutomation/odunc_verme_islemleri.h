#ifndef ODUNC_VERME_ISLEMLERI_H
#define ODUNC_VERME_ISLEMLERI_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>
#include <QModelIndex>
#include <QModelIndexList>
#include <QDate>

namespace Ui {
class odunc_verme_islemleri;
}

class odunc_verme_islemleri : public QDialog
{
    Q_OBJECT

public:
    explicit odunc_verme_islemleri(QSqlDatabase veriTabani, QWidget *parent = nullptr);
    ~odunc_verme_islemleri();

    void closeEvent(QCloseEvent *event);

    void oduncAlinanKitaplariListelemeFOnksiyonu();

    void teslsimEdilenKitaplariListelemeFonksiyonU();

private slots:
    void on_tableView_Odunc_Alinan_Kitaplar_Listesi_clicked(const QModelIndex &index);

    void on_pushButton_Odunc_Kitap_Teslim_Et_clicked();

private:
    Ui::odunc_verme_islemleri *ui;

    QSqlQuery *sorguOduncAlinan;

    QSqlQueryModel *modelOduncAlinan;

    QSqlQuery *sorguTeslimEdilen;

    QSqlQueryModel *modelTeslimEdilen;

    QSqlQuery *insertQuery;

    QSqlQuery *deleteQuery;


};

#endif // ODUNC_VERME_ISLEMLERI_H
