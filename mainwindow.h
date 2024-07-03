#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent=nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void onOpenTextButtonClicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
