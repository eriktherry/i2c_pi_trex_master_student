#include "MyTRex.h"

#ifndef TREX_H
#define TREX_H

namespace TRexLib{

    class TRex{
        public:
            /*
             * Constructor
             *
             * @i2c the I2C representing the bus on which the slave is connected.
             * @i2cAddress the address of the slave
             */
            TRex(I2C* i2c, int i2cAddress);

            /*
             * Read the status of the TRex controller.
             *
             * @status pointer to the StatusDataPacket that contains the values read from the controller.
             *
             * @return true if the read action was successful
             */
            bool readStatus(StatusDataPacket * status) = 0;

            /*
             * Write command to the TRex controller.
             *
             * @command pointer to the CommandDataPacket that contains the values that should be send to the controller.
             *
             * @return true if the write action was successful
             */
            bool writeCommand(CommandDataPacket * command) = 0; 
    };
}

#endif