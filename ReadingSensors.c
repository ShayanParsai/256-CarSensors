#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

FILE *fptr;
int i = 0;
int x = 0;
unsigned char currentSensors [30];
unsigned char newSensors [30];

int main() {
    resetArrays();

    while (true) {
        delay(2);
        fptr = fopen("C:\\SensorFiles\\SensorFile.txt","r");
        ////////////////////// Todo : Read from file, put content in newSensors as unsigned char
        
        for (x = 0; x < 30; x++) {
            int bit_pos_value = 128;
            int bit_value = 0;
            for (i = 0; i < 8; i++) {
                if( 'thefile[0-7]' == '1'){
                    
                }
            }
        newSensors[x] = bit_value;
        }
    }
        ////////////////////// Todo ^
        CheckActiveSensors();
        currentSensors = newSensors;
        fclose(fptr);
    }
    return 0;
}

CheckActiveSensors() { // Check and alarm switched sensors
    for (i = 0; i < 30; i++) {
        if (currentSensors[i] != newSensors[i]) {
            printf("\nSensor number %d has switched state", i); // todo : dosent work right now
        }
    }
}

delay(int number_of_seconds) { // Creates a time delay 
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

resetArrays() {
    for (i = 0; i < 30; i++) {
        currentSensors[i] = 0;
        newSensors[i] = 0;
    }
}
