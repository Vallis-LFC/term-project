#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

FILE* converted;
FILE* csv;

int get_length(char str[1000]){
    FILE* input;
    int count = 0;
    char buffer[1000];
    input = fopen(str, "r");
    while(fgets(buffer,sizeof(buffer),input)){ 
        count+=1; 
    }
    fclose(input);
    return count-2;
}

void printStrArray(char *input,int count){
    for(int i = 0;i<=count;i++){
        for(int x = 0; x<=(sizeof(input[i])/sizeof(input[0]));x++){
            printf("%c",input[i][x]);
        }
        
    }
}

int main(){
    char buffer[1000];
    char *data;
    int count = 0;
    
    count = get_length("GlobalTemperatures.csv");
    char dates[count][20];

    converted = fopen("GlobalTemperatures.txt","w");
    csv = fopen("GlobalTemperatures.csv","r");
    if(!csv){
        printf("Error: could not open file");
        return 0;
    }

    fgets(buffer,sizeof(buffer),csv);

    data = strtok(buffer,",");

        fprintf(converted, "%s", data);
        for(int i = 0;i<8;i++){
            data = strtok(NULL, ",");
            fprintf(converted, " %s",data);
            
        }

    int index = 0;
   while(fgets(buffer,sizeof(buffer),csv)){    
        data = strtok(buffer,",");
        strcpy(dates[count],data);
        fprintf(converted, "%s",data);

        for(int i = 0;i<=7;i++){
            data = strtok(NULL, ",");
            if (data!=NULL){
                fprintf(converted, " %s",data);
            }     
        }
   }
   printArray(*dates, count);
    fclose(csv);
    
    

    return 0;
}