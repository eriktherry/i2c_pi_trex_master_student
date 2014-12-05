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
    	this->setStartByte(char start);
    	this->setErrorFlags(char error);
    	this->setBatteryVoltage(double voltage);
    	this->setMotorCurrent(Side side, double current);
    	this->setEncoderCount(Side side, int count);
    	this->setAcceleroMeter(AcceleroMeter accelero);
    	this->setImpact(Impact impact);

	}

	std::string toJSON(void){

	}

    void fromJSON(std::string json){
    	return 0;
    }
    

}