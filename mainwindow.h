#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "BtPCModul.h"
#include "nxtclass.h"
#include "Qsocket.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
  BtPCModul * btmodul;
  NXTclass ** nxtclass;
  Qserver * qserver;
private:
  Ui::MainWindow *ui;
  int max_device;
  int RobActNom;
public:
    explicit MainWindow(BtPCModul * btmodul_,NXTclass ** nxtclass_,int max_device_,Qserver *qserver_,QWidget *parent = 0);
    ~MainWindow();    
//---sys---
private:
  void refresh();
private slots:
  void NewChange();
  void on_comboBox_activated(int index);
//---AUT---
private slots:
  void on_B_AUT_clicked();
//---Search
private slots:
  void on_B_SEARCH_clicked();
  void on_listWidget_doubleClicked(const QModelIndex &index);
  void on_Search_back_clicked();
  void SearchingNewDevice(); //out
//---com---
private slots:
  void on_B_Connect_clicked();
  void on_B_Disconnect_clicked();
  void on_B_Reset_clicked();
  void on_B_Send_clicked();
//---RC---
private slots:
  void on_B_remcontrol_clicked();
  void on_B_RC_back_clicked();
  void RC_send(void);
private:
    void keyPressEvent(QKeyEvent *key);
    void keyReleaseEvent(QKeyEvent * key);
    QTimer *timer;
    int keys[256];
    int key_shift;
};
#endif // MAINWINDOW_H
