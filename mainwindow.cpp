#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <Qstring>
#include <QKeyEvent>
#include <QTimer>

#include <QDebug>

#define MAX_DEVICE max_device
//--------------------INI----------------
MainWindow::MainWindow(BtPCModul * btmodul_,NXTclass ** nxtclass_,int max_device_,Qserver *qserver_, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qserver=qserver_;
    max_device=max_device_;
//    MAX_DEVICE=;
    nxtclass=nxtclass_;
    btmodul=btmodul_;
    RobActNom=1;
    ui->setupUi(this);
//RemControl
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(RC_send()));
    for(int i=0; i<256; i++)
        keys[i]=0;
    key_shift=0;

    connect(btmodul,SIGNAL(NewDevice()),this,SLOT(SearchingNewDevice()));
    connect(qserver,SIGNAL(NewChange()),this,SLOT(NewChange()));
    for (int i=0; i<=MAX_DEVICE; i++)
        connect(nxtclass[i],SIGNAL(NewChange()),this,SLOT(NewChange()));
    ui->GB_search->setHidden(1);
//    ui->GB_search->setHidden(1);
    ui->GB_search->setGeometry(0,0,300,200);
    this->setGeometry(300,300,300,220);
    ui->GB_remote->setHidden(1);
    ui->GB_remote->setGeometry(0,0,300,200);
    refresh();
}
MainWindow::~MainWindow()
{
    delete ui;
}
//---------------------sys----------------------------------
void MainWindow::NewChange()
{
    refresh();
}
void MainWindow::on_comboBox_activated(int index)
{
  RobActNom=index+1;
  qDebug()<<RobActNom;
  btmodul->GetDeviceInfo(nxtclass[RobActNom]);
  refresh();
}

void MainWindow::refresh()
{
    ui->lineEdit->setText(nxtclass[RobActNom]->BTaddr);
    ui->lineEdit_2->setText(nxtclass[RobActNom]->getport());
    ui->checkBox->setChecked(nxtclass[RobActNom]->authenticated);
    ui->C_Connect->setChecked(nxtclass[RobActNom]->isConnected());
    ui->B_Send->setEnabled(nxtclass[RobActNom]->authenticated && (nxtclass[RobActNom]->portIsReady()));
    ui->B_Connect->setEnabled(nxtclass[RobActNom]->authenticated && (nxtclass[RobActNom]->portIsReady()));
    ui->B_Disconnect->setEnabled(nxtclass[RobActNom]->authenticated && (nxtclass[RobActNom]->portIsReady()));
    ui->B_Reset->setEnabled(nxtclass[RobActNom]->authenticated && (nxtclass[RobActNom]->portIsReady()));

    ui->B_SEARCH->setEnabled(!nxtclass[RobActNom]->isConnected());
    ui->B_AUT->setEnabled(!nxtclass[RobActNom]->isConnected());


    ui->B_remcontrol->setEnabled(nxtclass[RobActNom]->isConnected());
    ui->C_pipe->setChecked(qserver->IsConnected());
    {
        ui->comboBox->clear();
        char temp[BLUETOOTH_MAX_SIZE_NAME+3];
        for(int i=1; i<=MAX_DEVICE;i++)
        {
            ZeroMemory(temp,BLUETOOTH_MAX_SIZE_NAME+3);
            memcpy(temp+3,nxtclass[i]->Name,BLUETOOTH_MAX_SIZE_NAME);
            if (i<10)
            {
                temp[0]='0'+i;
                temp[1]=' ';
                temp[2]=' ';
            }
            else
            {
                temp[0]='0'+(i/10)%10;
                temp[1]='0'+i%10;
                temp[2]=' ';
            }
            ui->comboBox->addItem(temp);
        }
        ui->comboBox->setCurrentIndex(RobActNom-1);
    }
    repaint();
}

//-----------------AUT-------------------------
void MainWindow::on_B_AUT_clicked()
{
    btmodul->Authenticating(nxtclass[RobActNom]);
    btmodul->InstalDriver(nxtclass[RobActNom]);
    btmodul->GetDeviceInfo(nxtclass[RobActNom]);
    btmodul->PortSearch(nxtclass[RobActNom]);
    refresh();
}
//--------------------------------------------
//                  Search
//--------------------------------------------
void MainWindow:: SearchingNewDevice()
{
    ui->listWidget->clear();
    for(int i=0; i<btmodul->m_device_id; i++)
    {
        ui->listWidget->addItem(QString(btmodul->BTaddr[i]).append(" - ").append(btmodul->SaveName[i]));
    }
    repaint();
}

void MainWindow::on_B_SEARCH_clicked()
{
    ui->GB_search->setHidden(0);
    ui->GB_ost->setHidden(1);
    SearchingNewDevice();
    btmodul->start();
}
void MainWindow::on_Search_back_clicked()
{
    btmodul->terminate();
    ui->GB_search->setHidden(1);
    ui->GB_ost->setHidden(0);
    refresh();
}
void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    int N=*((int*)(&index));
    memcpy((nxtclass[RobActNom])->Name,btmodul->SaveName[N],BLUETOOTH_MAX_SIZE_NAME);
    memcpy((nxtclass[RobActNom])->BTaddr,btmodul->BTaddr[N],18);
    btmodul->GetDeviceInfo(nxtclass[RobActNom]);
    btmodul->PortSearch(nxtclass[RobActNom]);
    on_Search_back_clicked();
}
//----------------------------------------------
//                      com
//----------------------------------------------
void MainWindow::on_B_Connect_clicked()
{
    nxtclass[RobActNom]->Open();
    refresh();
}

void MainWindow::on_B_Disconnect_clicked()
{
    nxtclass[RobActNom]->Close();
    refresh();
}

void MainWindow::on_B_Send_clicked()
{
    qDebug()<<nxtclass[RobActNom]->Write(ui->lineEdit_3->text().toUtf8().data());
    refresh();
}


void MainWindow::on_B_Reset_clicked()
{
    nxtclass[RobActNom]->Reset();
    refresh();
}

//-----------------------------------------------
//              remotecontrol
//-----------------------------------------------
void MainWindow::on_B_RC_back_clicked()
{
    ui->GB_remote->setHidden(1);
    ui->GB_ost->setHidden(0);
    timer->stop();
    refresh();
}
void MainWindow::on_B_remcontrol_clicked()
{
    ui->GB_remote->setHidden(0);
    ui->GB_ost->setHidden(1);
    this->setFocus();
    timer->start(30);
    refresh();
}


void MainWindow::keyPressEvent(QKeyEvent * key)
{
    if (key->key()<256)
        keys[key->key()]=1;
    if (key->key()==Qt::Key_Escape)
    {
        on_B_RC_back_clicked();
    }
    if (key->key()==Qt::Key_Shift)
    {
        key_shift=1;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent * key)
{
    if (key->key()<256)
        keys[key->key()]=0;
    if (key->key()==Qt::Key_Shift)
    {
        key_shift=0;
    }
}


void MainWindow::RC_send(void)
{
    char buf[32]="       ";
    int L=0,R=0,S=0,K=0,P=0;
    if (keys['W'])
    {
        L+=50;
        R+=50;
    }
    if (keys['S'])
    {
        L-=50;
        R-=50;
    }
    if (keys['A'])
    {
        L-=25;
        R+=25;
    }
    if (keys['D'])
    {
        L+=25;
        R-=25;
    }
    if (keys[' ']||keys['Q'])
        K=1;
    if (keys['E'])
        K=-1;
    if (keys['Z']||keys['B'])
        P=1;
    if (key_shift)
    {
        L=L*2;
        R=R*2;
        if (abs(L)>100) L=L/abs(L)*100;
        if (abs(R)>100) R=R/abs(R)*100;
    }
    qDebug()<<L<<" "<<R<<" "<<K<<P<<S<<endl;
    buf[0]=L;
    buf[1]=R;
    buf[2]=K;
    buf[3]=P;
    buf[4]=S;
    nxtclass[RobActNom]->Write(buf);
}
