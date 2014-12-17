#include "StatusDataPacket.h"
#include "Side.h"
#include "AcceleroMeter.h"

#ifndef TREX_MYSTATUS_DATA_PACKET_H
#define TREX_MYSTATUS_DATA_PACKET_H

namespace TRexLib{
	class MyStatusDataPacket: public StatusDataPacket{

        	 std::string toJSON(void);
        	 void fromJSON(std::string json);
        	 void toTRex(char * buffer);
        	 void fromTRex(char * data);
	};
}
#endif