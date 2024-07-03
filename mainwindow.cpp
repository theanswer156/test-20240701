#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QLabel *textDisplayLabel = new QLabel(this);
    textDisplayLabel->setObjectName("textDisplayLabel");
    textDisplayLabel->setWordWrap(true); // 对于 QLabel 开启自动换行
    textDisplayLabel->setFixedWidth(300); // 设置 QLabel 的宽度
    textDisplayLabel->setFixedHeight(200); // 设置 QLabel 的高度
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(textDisplayLabel); // 或 layout->addWidget(textDisplayTextEdit);
    setLayout(layout);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,tr("Open Image"), \
                                                      QDir::homePath(),tr("(*.jpg)\n(*.bmp)\n(*.png)"));
        qDebug()<<"filename:"<<filename;
        QImage image=QImage(filename); //图片初始化
        qDebug()<<"image:"<<image;
        if(!image.isNull()){
            ui->statusBar->showMessage(tr("Open Image Success!"),3000);
        }
        else{
            ui->statusBar->showMessage(tr("Save Image Failed!"),3000);
            return;
        }
        QImage image2=image.scaled(ui->label->width(),ui->label->height(),Qt::KeepAspectRatio); //图片缩放
        ui->label->setPixmap(QPixmap::fromImage(image2)); //显示图片textButton = new QPushButton("Open Text Document", this);
}
void MainWindow::onOpenTextButtonClicked() {
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Text File"), QDir::homePath(), tr("Text Files (*.txt)"));
    if (!filename.isEmpty()) {
        QFile file(filename);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString text = in.readAll();
            file.close();

            // 假设你有一个 QLabel 来显示文本
//            ui->textDisplayLabel->setText(text);
        } else {
            ui->statusBar->showMessage(tr("Failed to open file."), 3000);
        }
    } else {
        // 用户取消选择文件
        ui->statusBar->showMessage(tr("No file selected."), 3000);
    }
}
