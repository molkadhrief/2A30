#ifndef AZ_H
#define AZ_H

#include <QDialog>

namespace Ui {
class az;
}

class az : public QDialog
{
    Q_OBJECT

public:
    explicit az(QWidget *parent = nullptr);
    ~az();

private slots:
    void on_pb_ajouter_clicked();

private:
    Ui::az *ui;
};

#endif // AZ_H
