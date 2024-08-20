#ifndef UYE_ISLEMLERI_H
#define UYE_ISLEMLERI_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>

namespace Ui {
class uye_islemleri;
}

class uye_islemleri : public QDialog
{
    Q_OBJECT

public:
    explicit uye_islemleri(QSqlDatabase veriTabani, QWidget *parent = nullptr);
    ~uye_islemleri();

    void uyeleriListelemeFonksiyonu();

    void closeEvent(QCloseEvent *event);


private slots:
    void on_pushButton_Yeni_Kayit_clicked();

    void on_pushButton_Guncelle_clicked();

    void on_pushButton_Sil_clicked();

    void on_tableView_Uyeler_clicked(const QModelIndex &index);

private:
    Ui::uye_islemleri *ui;

    QSqlQuery *sorgu;

    QSqlQueryModel *model;

    QSqlQuery *sorguOduncAlinanVarMi;

};

#endif // UYE_ISLEMLERI_H
