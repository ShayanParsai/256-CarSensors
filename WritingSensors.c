#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int lower = 0, upper = 235, count = 1; 
FILE *fptr;
int i = 0;
bool sensors [235];

int main() {
    srand(time(NULL));

    CreateSensors();
    SwitchRandomSensors();

    return 0;
}



SwitchRandomSensors() { // Switches 20 random sensors true>false / false>true
    fptr = fopen("C:\\SensorFiles\\SensorFile.txt","w");

    for(i = 0; i < 21; i++) {
        int x = (rand() % (upper - lower + 1)) + lower;
    }

    fclose(fptr);
}

CreateSensors() { // Creates 236 sensors and writes them to a file with random outcome on true/false
    fptr = fopen("C:\\SensorFiles\\SensorFile.txt","w");
    for(i = 0; i < 236; i++) {
        sensors[i] = rand() % 2;
        fwrite(sensors[i] ? "1" : "0", sizeof(char), 1, fptr);
    }
    fclose(fptr);
}