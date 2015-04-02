#define DEBUG
#include "nxtclass.h"

#include <qdebug>
NXTcom::NXTcom(QString Sport, QObject *parent)
    :QObject(parent)
{
    com=new QextSerialPort(Sport);
    //connect(port, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    com->setBaudRate(BAUD9600);//38400
    com->setFlowControl(FLOW_OFF);
    com->setParity(PAR_NONE);
    com->setDataBits(DATA_8);
    com->setStopBits(STOP_2);
    connect(com, SIGNAL(dsrChanged(bool)), this, SLOT(onDsrChanged(bool)));

//    qDebug()<<com->portName()<<com->isOpen();
/*    com->setBaudRate(BAUD9600);
    com->setFlowControl(FLOW_OFF);
    com->setParity(PAR_NONE);
    com->setDataBits(DATA_8);
    com->setStopBits(STOP_1);*/

}

void NXTcom::onDsrChanged(bool status)
{
    if (status)
        qDebug() << "device was turned on";
    else
    {
        qDebug() << "device was turned off";
        Close();
    }
    emit NewChange();
}

NXTcom::~NXTcom()
{
    Close();
}

bool NXTcom:: portIsReady()
{
    return QString::compare(com->portName(),"COM0");
}
QString NXTcom:: getport()
{
    return com->portName();
}
bool NXTcom::setport(int port_)
{
/*    if (com->isOpen())
    {
        return false;
    }
    else
    {*/
        QString Sport;
        Sport.setNum(port_);
        com->setPortName(QString("COM").append(Sport));
        return true;
    //}
}
bool NXTcom::setport(QString Sport)
{
/*    if (com->isOpen())
    {
        return false;
    }
    else
    {*/
        com->setPortName(Sport);
        return true;
    //}
}

bool NXTcom::isConnected()
{
    return com->isOpen();
}

bool NXTcom::Open()
{
    if (!com->isOpen())
    {
        qDebug()<<"Openning COMport: "<<com->portName();
        if (com->open(QIODevice::ReadWrite))
        {
            if (!(com->lineStatus() & LS_DSR))
                printf("warning: device is not turned on. ");
            printf("COM is open.\n");

            return 1;
        }
        else
        {
            com->close();
            printf("ERROR: FailOpenComPort.\n");
            return 0;
        }
    }
    else
    {
        printf("COMport is ready open.\n");
        return 0;
    }
}

bool NXTcom::Reset()
{
    com->flush();
    return 0;
}

bool NXTcom::Close()
{
    //if (com->isOpen())
    {
        printf(" closing...");
        com->disconnect();
        com->close();
        printf(";\n");
        return 1;
    }
    return 0;
}


bool NXTcom::Read(char * buf,int lenbuf)
{
    if (!com->isReadable())
        return 0;
    return com->read(buf,lenbuf);
}

bool NXTcom::Write(char * buf,int lenbuf)
{
    if (!com->isWritable())
        return 0;
    qDebug()<<"c"<<(int)buf[0]<<" "<<(int)buf[1];
    char * mess=new char[lenbuf+2];
    memcpy(mess+2,buf,lenbuf);
    mess[0]=32;
    mess[1]=0;
    //printf(mess+2);
    bool re=com->write(mess,lenbuf+2);
    delete mess;
    //printf("%d;\n",re);
    return re;
}


//------------------------------------------
//          NXTclass
//------------------------------------------

NXTclass::NXTclass(int Numder_,char * BTaddr_,QString Sport)
    :NXTcom(Sport)
{
    authenticated=false;
    Number=Numder_;
    Name[0]=0;
    if (BTaddr_)
        memcpy(BTaddr,BTaddr_,18);
    else
        memcpy(BTaddr,(char *)DEF_BT_ADDR,18);
}
NXTclass::~NXTclass()
{

}
bool NXTclass::SetBTaddr(QString str)
{
    while (str[0]==' ')
        str.remove(0,1);
    for(int i=0; i<17; i++)
    {
        if ((i+1)%3)
        {
            if ( ((str[i]>='0')&&(str[i]<='9'))||
                 ((str[i]>='a')&&(str[i]<='f'))||
                 ((str[i]>='A')&&(str[i]<='F')) )
            {
                BTaddr[i]=str.toUtf8()[i];
            }
            else
            {
                memcpy(BTaddr,(char *)DEF_BT_ADDR,18);
                return 0;
            }
        }
        else
        {
            if (str[i]==':')
            {
                BTaddr[i]=':';
            }
            else
            {
                memcpy(BTaddr,(char *)DEF_BT_ADDR,18);
                return 0;
            }
        }
    }
    BTaddr[17]=0;
    return 1;
}

bool NXTclass::ZeroBTaddr()
{
    return memcmp(BTaddr,(char *)DEF_BT_ADDR,18);
}
