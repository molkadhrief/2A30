#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"popup.h"
#include <QMainWindow>
#include"vol.h"
//#include"statistiques.h"
#include"arduino.h"

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
    void on_pb_ajouter_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

   void on_pushButton_4_clicked();

   void on_pushButton_5_clicked();

   void on_pushButton_6_clicked();

  // void on_pb_stat_clicked();

   void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    Vol Vt;
     PopUp *popUp;
 // statistiques *s;
     int ret;
     Arduino A;
     QByteArray data;
};

#endif // MAINWINDOW_H
