#include "MyTRex.h"
#include "StatusDataPacket.h"
#include "MyStatusDataPacket.h"
#include "wait.h"

namespace TRexLib{

    /*
     * Constructor
     *
     * @i2c the I2C representing the bus on which the slave is connected.
     * @i2cAddress the address of the slave
     */
    MyTRex::MyTRex(I2C* i2c, int i2cAddress):TRex(i2c,i2cAddress)
    {

    }

    bool MyTRex::readStatus(StatusDataPacket * status)
    {
        int j=0;
        char data[StatusDataPacket::SIZE_STATUS_DATA_PACKET];
        
        //De TRex gaan uitlezen en in data zetten.
        i2c->read(i2cAddress,data,StatusDataPacket::SIZE_STATUS_DATA_PACKET);

        //data omvormen volgens MyStatusDataPacket.
        status->fromTRex(data);
        if(data[0]!=0x0F){
            //probeer 5 keer te herlezen met een wachttijd van 100ms. Indien dit niet lukt wordt er een false gereturned.
            for(j=0;j==5;j++){
                wait(0.100);
                i2c->read(i2cAddress,data,StatusDataPacket::SIZE_STATUS_DATA_PACKET);
                status->fromTRex(data);
                if(data[0]==0x0F){
                    return true;
                }
            }
            return false;
        }
        else{
            return true;
        }
    }

    bool MyTRex::writeCommand(CommandDataPacket * command)
    {
        char buffer[]={"testCommand"};
        int i=0;
        i=i2c->write(i2cAddress,buffer,sizeof(buffer));
        if(i==0){
            return false;
        }
        else{
            return true;
        }
    }
}