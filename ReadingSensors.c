#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

FILE *fptr;
int i = 0;
bool currentSensors [235];
bool newSensors [235];

int main() {
    for (i = 0; i < 236; i++) {
        currentSensors[i] = false;
    }
    for (i = 0; i < 236; i++) {
        newSensors[i] = false;
    }

    
    while (true) {
        delay(2);
        fptr = fopen("C:\\SensorFiles\\SensorFile.txt","r");
        // newSensors = take values from file
        CheckActiveSensors();
        currentSensors = newSensors;
        fclose(fptr);
    }
    
    return 0;
}

CheckActiveSensors() { // Check and alarm active sensors
    for (i = 0; i < 236; i++) {
        if (currentSensors[i] != newSensors[i]) {
            printf("\nSensor number %d has switched state", i);
        }
    }
}

delay(int number_of_seconds) { // Creates a time delay 
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}
