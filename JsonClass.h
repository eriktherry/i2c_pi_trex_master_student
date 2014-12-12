#include <string>

//hier maak je de "{data}"
void eindeBuildData(char data[],char eindebuilddata[]);

//hier maak je "datatype:datawaarde"
void buildData(char datatype[],char datawaarde[],char builddata[]);

//hier maak je "data,data" append je meerdere data aan elkaar.
void appendData(char builddata1[], char builddata2[],char appenddata[]);

//hardcoded macaddres,cpu_temp,freetemp doorsturen.
void piData(char macaddress[],char cpu_temp[],char free_memory[],char piData[]);

//decode en haal je de "{data}" eruit.
void deBuildEindeData(char data[],char debuildata[]);

//je krijgt een int terug van hoeveel data types in de verstuurddata zit.
//Dit wordt in een array string gestoken. 
int deAppendData(char * data,string deappenddata[]);

//de datatype en datawaarde onderscheiden.
void deBuildData(char data[],char datatype[],char datawaarde[]);