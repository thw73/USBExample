#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
    void on_pushButtonRead_clicked();

    void on_pushButtonSend_clicked();

    void on_pushButtonInit_clicked();


private:
    Ui::MainWindow *ui;

    int devCount;
};

#endif // MAINWINDOW_H
