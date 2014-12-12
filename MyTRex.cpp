#include "MyTRex.h"

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

    MyTrex::readStatus(MyStatusDataPacket * status)
    {
        return false;
    }
    writeCommand(CommandDataPacket * command)
    {
        return false;
    }
}