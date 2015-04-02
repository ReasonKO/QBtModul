//-----------------------------------------------------
//Класс NXT
//Содержащий основные параметры,
//ассоциируемые с конкретным устройством
//-----------------------------------------------------
#ifndef NXTCLASS_H
#define NXTCLASS_H

#define BLUETOOTH_MAX_SIZE_NAME 248
#define DEF_GUID {4353,268435456,-2147483520,-80438433}
#define DEF_PIN "1234"
#define DEF_BT_ADDR "00:00:00:00:00:00"

#define NXT_MESS_SIZE 32
#include <QString>

#include <QThread>
#include "src/qextserialport.h"

class NXTcom:public QObject
{
    Q_OBJECT
public:
    bool portIsReady();
    bool setport(int port_);
    bool NXTcom::setport(QString Sport);
    QString NXTcom:: getport();
    bool isConnected(); //Подключение действительно.
private:
    QextSerialPort * com;
public: //конструктор
    explicit NXTcom(QString Sport,QObject *parent=0);
    ~NXTcom();
public: //контроль
    bool Open();
    bool Close();
    bool Reset();
    bool Write(char * buf,int lenbuf=NXT_MESS_SIZE);
    bool Read (char * buf,int lenbuf=NXT_MESS_SIZE);
signals:
    void ReadyRead(char * buf);
private slots:
    void onDsrChanged(bool status);
signals:
    void NewChange();
};

class NXTclass:public NXTcom
{
    Q_OBJECT
public:
    QString ProgAddr;
    char BTaddr[18];//"00:00:00:00:00:00"
    char Name[BLUETOOTH_MAX_SIZE_NAME];//[BLUETOOTH_MAX_NAME_SIZE]
    int Number;
    bool authenticated; //Аутентефикация пройдена.
public:
    NXTclass(int Number_=0, char * BTaddr_=0,QString Sport="COM0");
    ~NXTclass();
public:
    bool SetBTaddr(QString str);
    bool ZeroBTaddr();
};

#endif // NXTCLASS_H
