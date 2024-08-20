#ifndef UYEISLEMLERI_H
#define UYEISLEMLERI_H

#include <QDialog>

namespace Ui {
class uyeislemleri;
}

class uyeislemleri : public QDialog
{
    Q_OBJECT

public:
    explicit uyeislemleri(QWidget *parent = nullptr);
    ~uyeislemleri();

private:
    Ui::uyeislemleri *ui;
};

#endif // UYEISLEMLERI_H
