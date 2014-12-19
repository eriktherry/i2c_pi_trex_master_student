#include <string.h>

//hier maak je de "{data}"
void eindeBuildData(char data[],char eindebuilddata[]);

//hier maak je "datatype:datawaarde"
void buildData(char datatype[],char datawaarde[],char builddata[]);

//hier maak je "data,data" append je meerdere data aan elkaar.
void appendData(char builddata1[], char builddata2[],char appenddata[]);

//hardcoded macaddres,cpu_temp,freetemp doorsturen.
void piData(char macaddress[],char cpu_temp[],char free_memory[],char piData[]);

//hardcoded trexData aanmaken.
void trexData(char battery_voltage[], char motor_current_left[], char motor_current_right[], char encoder_count_left[], char encoder_count_right[], char accelero[], char impact[], char trexData[]);

//decode en haal je de "{data}" eruit.
void deBuildEindeData(char data[],char debuildata[]);

//je krijgt een int terug van hoeveel data types in de verstuurddata zit.
//Dit wordt in een array string gestoken. 
int deAppendData(char * data,std::string deappenddata[]);

//de datatype en datawaarde onderscheiden.
void deBuildData(char data[],char datatype[],char datawaarde[]);