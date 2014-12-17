#include "DataPacket.h"
#include "Side.h"
#include "AcceleroMeter.h"


namespace TRexLib{

	void MyStatusDataPacket::toTRex(char * buffer){
		return 0;
	}

    void MyStatusDataPacket::fromTRex(char * data){		//haald de informatie op en steekt ze in char *data
    	
    	this->setStartByte(data[0]);
    	this->setErrorFlags(data[1]);
    	this->setBatteryVoltage((data[StatusDataPacketFields::STATUS_BATTERY_MSB]*256 + data[StatusDataPacketFields::STATUS_BATTERY_LSB])/100.0;
    	this->setMotorCurrent(Side side, double current);
    	this->setEncoderCount(Side side, int count);
    	AcceleroMeter accelero;
        this->setAcceleroMeter(accelero);
    	this->setImpact(Impact impact);

	}

	std::string MyStatusDataPacket::toJSON(void){		//haald informatie uit *data en steekt ze json string

	}

    void MyStatusDataPacket::fromJSON(std::string json){
    	return 0;
    }
    

}