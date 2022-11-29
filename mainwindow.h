#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "billet.h"
#include "arduino.h"
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




    void on_pushButton_b_clicked();

    void on_pushButton_valider_login_clicked();

    void on_pushButton_ab_clicked();

    void on_pushButton_affb_clicked();

    void on_pushButton_eb_clicked();

    void on_pushButton_mb_clicked();

    void on_pushButton_annuler_login_clicked();

    void on_AJOUTER_clicked();

    void on_modifier_clicked();

    void on_comboBox_currentIndexChanged(QString);

    void on_SUPRIMER_clicked();


    void on_CHERCHER_textChanged(const QString &arg1);

    void on_TRIE_ID_clicked();

    void on_TRIE_CLASS_clicked();

    void on_STAT_clicked();

    void on_excel_clicked();

    //void on_qr_code_clicked();



    void on_comboBox_2_currentIndexChanged(QString);



    void on_qr_code_clicked();

    void on_arduino_clicked();

private:
    Ui::MainWindow *ui;
    Billet etmp;
    QByteArray data; // variable contenant les données reçues
    int ret;
    Arduino A; // objet temporaire
};
#endif // MAINWINDOW_H
