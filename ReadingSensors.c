#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

FILE *fptr;
int i = 0;
int x = 0;
int c;
unsigned int currentSensors [15];
unsigned int newSensors [15];
struct {
   unsigned int testSensors : 16;
} testSensors;

int main() {
    testSensors.testSensors = 65535;
    resetArrays();

    fptr = fopen("C:\\SensorFiles\\SensorFile.txt","r");
    
    char tempChunk [16] = "";

    while ((c = getc(fptr)) != EOF) {
        char tmp = (char)c;
        size_t len = strlen(tempChunk);
        snprintf(tempChunk + len, sizeof tempChunk - len, "%c", tmp);
        printf("\n%s",tempChunk);
        x++;
        if (x == 16) {
            testSensors.testSensors = atoi(tempChunk);
        }
    }
      
    
    CheckActiveSensors();

    fclose(fptr);
    overwriteArrays();
    return 0;
}

CheckActiveSensors() { // Check and alarm switched sensors
    for (i = 0; i < 15; i++) {
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
    for (i = 0; i < 15; i++) {
        currentSensors[i] = 0;
        newSensors[i] = 0;
    }
}

overwriteArrays() {
    for (i = 0; i < 15; i++) {
        currentSensors[i] = newSensors[i];
    }
}

