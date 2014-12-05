#include "JsonClass.h"

#include <string.h>

void eindeBuildData(char data[],char eindebuilddata[]){

    sprintf(eindebuilddata,"{%s}",data);

}

void buildData(char datatype[],char datawaarde[],char builddata[]){

    sprintf(builddata,"%s:%s",datatype,datawaarde);

}

void appendData(char builddata1[], char builddata2[],char appenddata[]){

    sprintf(appenddata,"%s,%s",builddata1,builddata2);

}

void piData(char macaddress[],char cpu_temp[],char free_memory[],char piData){

    char data1,data2,data3,data4,data5;

    buildData("macaddress",macaddress,data1);
    buildData("cpu_temp",cpu_temp,data2);
    buildData("freememory",free_memory,data3);

    appendData(data1,data2,data4);
    appendData(data4,data3,data5);

    eindeBuildData(data5,piData);
}