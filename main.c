#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <string.h>

FILE* temp;
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



int main(){
    char buffer[1000];
    char *data;
    int count = 0;
    int temp_count = 0;
    char *dataptr;
    
    
    count = get_length("GlobalTemperatures.csv");
    char dates[count][20];
    double landAvg[count];
    double landAvgUn[count];
    double landMax[count];
    double landMaxUn[count];
    double landMin[count];
    double landMinUn[count];
    double land_seaAvg[count];
    double land_seaAvgUn[count];


    temp = fopen("GlobalTemperatures.txt","w");
    csv = fopen("GlobalTemperatures.csv","r");
    if(!csv){
        printf("Error: could not open file");
        return 0;
    }

//Loops through the first line once to get rid of the labels
    fgets(buffer,sizeof(buffer),csv);
    data = strtok(buffer,",");
    for(int i = 0;i<8;i++){
        data = strtok(NULL, ",");
    }

//gets all the data and sorts them into arrays
    int index = 0;

   while(fgets(buffer,sizeof(buffer),csv)){    
        data = strtok(buffer,",");
        strcpy(dates[index],data);
        //fprintf(temp, "%s",data);
        

        for(int i = 0;i<=7;i++){
            double converted;
            data = strtok(NULL, ",");
            if (data!=NULL){
                converted = strtod(data, &dataptr);
                switch (i)
                {
                case /* constant-expression */:
                    /* code */
                    break;
                
                default:
                    break;
                }
                fprintf(temp, " %lf",converted);

            }     
        }
        index+=1;
   }
    printf("%s", dates[1]);
    fclose(csv);
    
    

    return 0;
}