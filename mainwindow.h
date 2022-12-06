#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"avion.h"
#include <QMainWindow>
#include "webaxwidget.h"
#include <QMainWindow>
#include <QFileDialog>
#include <QSystemTrayIcon>
#include <qsystemtrayicon.h>
#include <QDialog>
#include <QMouseEvent>
#include <QPoint>
#include <QMainWindow>
#include <QtCharts>
#include <QDialog>
#include <QSettings>
#include <QDataStream>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void update_id();

    int G_PVS1();
    int G_PVS2();
    int G_PVS3();
    int G_PVS4();
    int G_PVS5();

    QChartView* piechart();
private slots:
    void on_pushButton_clicked();
    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_tabWidget_2_tabBarClicked(int index);

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_4_clicked();

private:
    avion a;
    int id_p=0;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
