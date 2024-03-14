#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

FILE* temp;
FILE* csv;

//function to get the amount of rows
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
    char *dataptr;
    double converted;
    int index = 0;
    
    //intializes the arrays
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


    csv = fopen("GlobalTemperatures.csv","r");
    //checks if the file is valid
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
    
    printf("%d ",count);
   while(fgets(buffer,sizeof(buffer),csv)){    
        data = strtok(buffer,",");
        strcpy(dates[index],data); //copys the dates to the array

        //loops through 7 times to get the values
        for(int i = 0;i<=7;i++){
            
            data = strtok(NULL, ","); //uses comma as delimitter and parses through
            if (data!=NULL){ //checks if value is Null
                converted = strtod(data, &dataptr); //converts the data to a double 
                switch (i)  //uses a switch statement to determine which data goes into which array
                {
                case 0:
                    landAvg[index] = converted;
                    break;
                case 1:
                    landAvgUn[index] = converted;
                    break;
                case 2:
                    landMax[index] = converted;
                    break;
                case 3:
                    landMaxUn[index] = converted;
                    break;
                case 4:
                    landMin[index] = converted;
                    break;
                case 5:
                    landMinUn[index] = converted;
                    break;
                case 6:
                    land_seaAvg[index] = converted;
                    break;
                case 7:
                    land_seaAvgUn[index] = converted;
                    break;
                default:
                    printf("something wrong happened");
                    break;
                }

            }     
        }
        index+=1;
   }
    fclose(csv);
    
    

    return 0;
}