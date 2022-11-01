#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "billet.h"
#include <QMainWindow>

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
    void on_pushButton_valider_ajout_clicked();

    void on_pushButton_valider_supp_clicked();

    void on_pushButton_b_clicked();

    void on_pushButton_valider_login_clicked();

    void on_pushButton_ab_clicked();

    void on_pushButton_affb_clicked();

    void on_pushButton_eb_clicked();

    void on_pushButton_mb_clicked();

    void on_pushButton_annuler_login_clicked();

    void on_pushButton_annuler_ajout_clicked();

    void on_pushButton_annuler_aff_clicked();

    void on_pushButton_annuler_supp_clicked();

    void on_pushButton_annuler_mod_clicked();

    void on_pushButton_a_clicked();

    void on_pushButton_valider_mod_clicked();

private:
    Ui::MainWindow *ui;
    Billet etmp;
};
#endif // MAINWINDOW_H
