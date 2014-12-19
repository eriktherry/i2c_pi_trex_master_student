#include "MyStatusDataPacket.h"
#include "StatusDataPacket.h"
#include "DataPacket.h"
#include "Side.h"
#include "AcceleroMeter.h"
#include "JsonClass.h"


namespace TRexLib{

	void MyStatusDataPacket::toTRex(char * buffer){

	}

    void MyStatusDataPacket::fromTRex(char * data){		//haald de informatie op en steekt ze in char *data
    	
    	this->setStartByte(data[STATUS_START]);
    	this->setErrorFlags(data[STATUS_ERROR]);
    	this->setBatteryVoltage((data[STATUS_BATTERY_MSB]*256 + data[STATUS_BATTERY_LSB])/100.0);
    	this->setMotorCurrent(LEFT, (data[STATUS_LEFT_MOTOR_CURRENT_MSB] * 256 + data[STATUS_LEFT_MOTOR_CURRENT_LSB])/1000.0);
        this->setMotorCurrent(RIGHT, (data[STATUS_RIGHT_MOTOR_CURRENT_MSB] * 256 + data[STATUS_RIGHT_MOTOR_CURRENT_LSB])/1000.0);
    	this->setEncoderCount(LEFT, (data[STATUS_LEFT_ENCODER_COUNT_MSB] * 256 + data[STATUS_LEFT_ENCODER_COUNT_LSB]));
        this->setEncoderCount(RIGHT, (data[STATUS_RIGHT_ENCODER_COUNT_MSB] * 256 + data[STATUS_RIGHT_ENCODER_COUNT_LSB]));

    	AcceleroMeter accelero;
        accelero.x=((data[STATUS_ACCELEROMETER_X_MSB] * 256 + data[STATUS_ACCELEROMETER_X_LSB]));
        accelero.y=((data[STATUS_ACCELEROMETER_Y_MSB] * 256 + data[STATUS_ACCELEROMETER_Y_LSB]));
        accelero.z=((data[STATUS_ACCELEROMETER_Z_MSB] * 256 + data[STATUS_ACCELEROMETER_Z_LSB]));
        this->setAcceleroMeter(accelero);

        Impact impact;
        impact.x=((data[STATUS_IMPACT_X_MSB] * 256 + data[STATUS_IMPACT_X_LSB]));
        impact.y=((data[STATUS_IMPACT_Y_MSB] * 256 + data[STATUS_IMPACT_Y_LSB]));
        impact.z=((data[STATUS_IMPACT_Z_MSB] * 256 + data[STATUS_IMPACT_Z_LSB]));
    	this->setImpact(impact);

	}

	std::string MyStatusDataPacket::toJSON(void){		//haald informatie uit *data en steekt ze json string

        JsonClass json; 
        char * data;

        json.trexData(this->getBatteryVoltage(), this->getMottorCurrent(LEFT), this->getMottorCurrent(RIGHT), this->getEncoderCount(LEFT), this->getEncoderCount(RIGHT), this->getAcceleroMeter(), this->getImpact(),data);

        return data;

	}

    void MyStatusDataPacket::fromJSON(std::string json){
    }
    

}