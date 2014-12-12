#include "DataPacket.h"
#include "Side.h"
#include "AcceleroMeter.h"

#ifndef TREX_STATUS_DATA_PACKET_H
#define TREX_STATUS_DATA_PACKET_H

namespace TRexLib{

	void toTRex(char * buffer){
		return 0;
	}

    void fromTRex(char * data){		//haald de informatie op en steekt ze in char *data
    	
    	this->setStartByte(data[0]);
    	this->setErrorFlags(data[1]);
    	this->setBatteryVoltage((data[StatusDataPacketFields::STATUS_BATTERY_MSB]*256 + data[StatusDataPacketFields::STATUS_BATTERY_LSB])/100.0;
    	this->setMotorCurrent(Side side, double current);
    	this->setEncoderCount(Side side, int count);
    	this->setAcceleroMeter(AcceleroMeter accelero);
    	this->setImpact(Impact impact);

	}

	std::string toJSON(void){		//haald informatie uit *data en steekt ze json string

	}

    void fromJSON(std::string json){
    	return 0;
    }
    

}
#endif