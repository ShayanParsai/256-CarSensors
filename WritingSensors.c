#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

FILE *fptr;
int i = 0;
bool sensors [235];

int main() {
    srand(time(NULL));

    for(i = 0; i<=235; i++) {
        sensors[i] = rand() % 2;
    }

    SwitchRandomSensors();
     
    return 0;
}

SwitchRandomSensors() {
    fptr = fopen("C:\\SensorFiles\\SensorFile.txt","w");

    for(i = 0; i < 236; i++) {
        fwrite(sensors[i] ? "1" : "0", sizeof(char), 1, fptr);
    }

    fclose(fptr);
}

//int lower = 0, upper = 235, count = 1;
//while (true) {} 
// int x = (rand() % (upper - lower + 1)) + lower;