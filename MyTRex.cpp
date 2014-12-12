#include "MyTRex.h"
#include "MyStatusDataPacket.h"

namespace TRexLib{

    /*
     * Constructor
     *
     * @i2c the I2C representing the bus on which the slave is connected.
     * @i2cAddress the address of the slave
     */
    MyTRex::MyTRex(I2C* i2c, int i2cAddress):Trex(i2c,i2cAddress)
    {
        //this->i2c = i2c;
        //this->i2cAddress = i2cAddress;
    }

    bool MyTRex::readStatus(MyStatusDataPacket * status)
    {
        char data[StatusDataPacket::SIZE_STATUS_DATA_PACKET];
        
        i2c.read(i2cAddress,data,StatusDataPacket::SIZE_STATUS_DATA_PACKET);
        status->fromTRex(data);
        if(data[0]!=0x0F){
            for(int i=0;i=5;i++){
                wait_ms(100);
                i2c.read(i2cAddress,data,StatusDataPacket::SIZE_STATUS_DATA_PACKET);
                status->fromTRex(data);
                if(data[0]==0x0F){
                    return true;
                }
            }
        }
        else{
            return true;
        }
    }

    bool MyTRex::writeCommand(CommandDataPacket * command)
    {
        return false;
    }
}