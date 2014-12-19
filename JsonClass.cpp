#include "JsonClass.h"

#include <string.h>
#include <stdio.h>


namespace TRexLib{

    JsonClass::JsonClass(void){

    }

    void JsonClass::eindeBuildData(char data[],char eindebuilddata[]){

        sprintf(eindebuilddata,"{%s}",data);
    }

    

    void JsonClass::buildData(char datatype[],char datawaarde[],char builddata[]){

        sprintf(builddata,"\"%s\":\"%s\"",datatype,datawaarde);

    }

    void JsonClass::appendData(char builddata1[], char builddata2[],char appenddata[]){

        sprintf(appenddata,"%s,%s",builddata1,builddata2);

    }

    void JsonClass::piData(char macaddress[],char cpu_temp[],char free_memory[],char piData[]){

        char * data1,*data2,*data3,*data4,*data5;

        buildData("macaddress",macaddress,data1);
        buildData("cpu_temp",cpu_temp,data2);
        buildData("freememory",free_memory,data3);

        appendData(data1,data2,data4);
        appendData(data4,data3,data5);

        eindeBuildData(data5,piData);
    }

    void JsonClass::trexData(char battery_voltage[], char motor_current_left[], char motor_current_right[], char encoder_count_left[], char encoder_count_right[], char accelero[], char impact[], char trexData[]){

        char * dataBat, *dataML, *dataMR, *dataEL, *dataER, *dataAc, *dataIm, *data1; 

        buildData("Batttery_voltage",battery_voltage,dataBat);
        buildData("Motor_current_left",motor_current_left,dataML);
        buildData("Motor_current_right",motor_current_right,dataMR);
        buildData("Encoder_count_left",encoder_count_left,dataEL);
        buildData("Encoder_count_right",encoder_count_right,dataER);
        buildData("Accelero",accelero,dataAc);
        buildData("Impact",impact,dataIm);

        appendData(dataBat,dataML,data1);
        appendData(data1,dataMR,data1);
        appendData(data1,dataEL,data1);
        appendData(data1,dataER,data1);
        appendData(data1,dataAc,data1);
        appendData(data1,dataIm,data1);

        eindeBuildData(data1,trexData);

    }

    void JsonClass::deBuildEindeData(char data[],char debuilddata[]){

        sscanf(data,"{%s}",debuilddata);
    }
/*
    int JsonClass::deAppendData(char * data,std::string deappenddata[]){

        char* s;
        int i=0;
        s= strtok(data,",");
        while(s != NULL){
            deappenddata[i]=s;
            s=strtok(NULL,",");
            i++;
        }
        return i;
    }
*/
    void JsonClass::deBuildData(char data[],char datatype[],char datawaarde[]){

        sscanf(data,"\"%s\":\"%s\"",datatype,datawaarde);
    }
}