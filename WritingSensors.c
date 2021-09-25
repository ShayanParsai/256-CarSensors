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
    while (true) {
        delay(1);
        SwitchRandomSensors();
    }
    return 0;
}

SwitchRandomSensors() { // Switches 20 random sensors true>false / false>true
    for(i = 0; i < 21; i++) {
        int x = (rand() % (upper - lower + 1)) + lower;
        if (sensors[x] == true){
            sensors[x] = false;
        } else {
            sensors[x] = true;
        }
    }
    fptr = fopen("C:\\SensorFiles\\SensorFile.txt","w");
    for(i = 0; i < 236; i++) {
        fwrite(sensors[i] ? "1" : "0", sizeof(char), 1, fptr);
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

delay(int number_of_seconds) { // Creates a time delay 
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}