#include "DataPacket.h"
#include "Side.h"
#include "AcceleroMeter.h"

#ifndef TREX_STATUS_DATA_PACKET_H
#define TREX_STATUS_DATA_PACKET_H

namespace TRexLib{
	class MyStatusDataPacket: public StatusDataPacket{

        	 std::string toJSON(void) = 0;
        	 void fromJSON(std::string json) = 0;
        	 void toTRex(char * buffer) = 0;
        	 void fromTRex(char * data) = 0;

	};

}