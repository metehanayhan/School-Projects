#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_Uye_Islemleri_clicked();

    void on_pushbutton_Kitap_Islemleri_clicked();

    void on_pushbutton_Odunc_Alma_Islemleri_clicked();

    void on_pushbutton_Odunc_Verme_Islemleri_clicked();

private:
    Ui::MainWindow *ui;

    QSqlDatabase veriTabani = QSqlDatabase::addDatabase("QSQLITE");

};
#endif // MAINWINDOW_H
