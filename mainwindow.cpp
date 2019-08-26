#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QtAndroidExtras/QAndroidJniObject>
#include <QtAndroidExtras/QAndroidJniEnvironment>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


   ui->spinBox->setStyleSheet("QSpinBox::up-button {width: 96px;}"
                              "QSpinBox::down-button {width: 96px;}");

 }

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonRead_clicked()
{

    if (devCount>0)
    {
        unsigned char value = QAndroidJniObject::callStaticMethod<jshort>("org/qtproject/usbexample/MyFTDIClass","Read_USB", "()S");
        ui->lcdNumber->display(value);
        ui->lcdNumber->show();
    }
}

void MainWindow::on_pushButtonSend_clicked()
{

    if (devCount>0)
    {


        unsigned char sendValue= ui->spinBox->value();


        //--------------Show how to handle a byte array via JNI-----------

        QAndroidJniEnvironment env;

        jbyteArray jBuff = env->NewByteArray(1);
        jbyte a[] = {0};
        a[0]= (jbyte) sendValue;


        env->SetByteArrayRegion(jBuff, 0, 1, a);  //SetByteArrayRegion(JNIEnvironment env, int arrayJREF, int startIndex, int length, Address bufAddress)

        QAndroidJniObject::callStaticMethod<void>("org/qtproject/usbexample/MyFTDIClass","Write_USB","([B)V", jBuff);

        env->DeleteLocalRef(jBuff); // IMPORTANT TO AVOID MEMORY LEAK!

    }



}

void MainWindow::on_pushButtonInit_clicked()
{

    devCount = QAndroidJniObject::callStaticMethod<jint>("org/qtproject/usbexample/MyFTDIClass","initFTDI", "()I");
    ui->labelInit->setText("Devicse found: " + QString::number(devCount) );

}



