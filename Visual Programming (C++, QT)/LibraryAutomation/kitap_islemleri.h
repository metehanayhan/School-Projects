#ifndef KITAP_ISLEMLERI_H
#define KITAP_ISLEMLERI_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>

namespace Ui {
class kitap_islemleri;
}

class kitap_islemleri : public QDialog
{
    Q_OBJECT

public:
    explicit kitap_islemleri(QSqlDatabase veriTabani, QWidget *parent = nullptr);
    ~kitap_islemleri();

    void kitaplariListelemeFonksiyonu();

    void oduncAlinanVeTeslimEdilenlerinSorgusu();

    void closeEvent(QCloseEvent *event);


private slots:
    void on_pushButton_Yeni_Kayit_clicked();

    void on_pushButton_Guncelle_clicked();

    void on_pushButton_Sil_clicked();

    void on_tableView_Kitaplar_clicked(const QModelIndex &index);

private:
    Ui::kitap_islemleri *ui;

    QSqlQuery *sorguKitapCekAl;

    QSqlQueryModel *modelKitapCekAl;

    QSqlQuery *sorguOduncAlinanKitap;

    QSqlQueryModel *modelOduncAlinanKitap;

    QSqlQuery *sorguTeslimEdilenKitap;

    QSqlQueryModel *modelTeslimEdilenKitap;

    QSqlQuery *silmeSorgusuTablolarKontrol;
};

#endif // KITAP_ISLEMLERI_H
