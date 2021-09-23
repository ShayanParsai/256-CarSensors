#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

FILE *fptr;
int i = 0;
bool sensors [235];

int main() {
    
    fptr = fopen("C:\\SensorFiles\\SensorFile.txt","r");


    fclose(fptr);
    return 0;
}

CheckActiveSensors() { // Check and alarm active sensors
    for (i = 0; i <= 236; i++) {
        if (sensors[i]) {
            printf("\nSensor number %d is active", i);
        }
    }
}
