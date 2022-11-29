#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"etudiant.h"
#include <QMainWindow>
#include "QSerialPort"
#include "QSerialPortInfo"
#include "arduino.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void on_pushButton_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_sup_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pb_ajouter_8_clicked();

    void on_pb_ajouter_4_clicked();

    void on_pb_ajouter_7_clicked();

    void on_pb_ajouter_6_clicked();

    void on_pb_ajouter_5_clicked();

    void on_pushMailing_clicked();

    void on_pushMailing_2_clicked();

    void on_secu_clicked();
    void on_insertimg_clicked();

private:
    Ui::MainWindow *ui;
    arduino a;

    Etudiant etmp;


};

#endif // MAINWINDOW_H
