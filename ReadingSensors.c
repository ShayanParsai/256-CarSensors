#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

FILE *fptr;
int c;
unsigned int currentSensors [15];
unsigned int newSensors [15];

int main() {
    resetArrays();

    // Loop This
    fptr = fopen("C:\\SensorFiles\\SensorFile.txt","r");
    char tempChunk [17] = "";
    int i = 0;
    int x = 0;

    while ((c = getc(fptr)) != EOF) {
        char tmp = (char)c;
        size_t len = strlen(tempChunk);
        snprintf(tempChunk + len, sizeof tempChunk - len, "%c", tmp);
        x++;
        if (x == 16) {
            newSensors[i] = convert(atoll(tempChunk));
            memset(&tempChunk[0], 0, sizeof(tempChunk));
            x = 0;
            i++;
        }
    }
    fclose(fptr);
    CheckActiveSensors();
    overwriteArrays();
    // Loop This ^

    return 0;
}

long decimalToBinary(int decimalnum) {
    long binarynum = 0;
    int rem, temp = 1;
    while (decimalnum!=0)
    {
        rem = decimalnum%2;
        decimalnum = decimalnum / 2;
        binarynum = binarynum + rem*temp;
        temp = temp * 10;
    }
    return binarynum;
}

CheckActiveSensors() { // Check and alarm switched sensors
    int i = 0;
    int j = 0;
    for (i = 0; i <= 15; i++) {
        if (currentSensors[i] != newSensors[i]) {
            char currentNewSensors[17] = atoll(decimalToBinary(newSensors[i])); // Atoll wants const char *
            char currentCurrentSensors[17] = atoll(decimalToBinary(currentSensors[i])); // Atoll wants const char *
            for (j = 0; j <=15; j++) {
                if (currentCurrentSensors[j] != currentNewSensors[j]) {
                    printf("\nSensor number %d has switched state", j);
                }
            }
        }
    }
}

delay(int number_of_seconds) { // Creates a time delay 
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

resetArrays() {
    int i = 0;
    for (i = 0; i <= 15; i++) {
        currentSensors[i] = 0;
        newSensors[i] = 0;
    }
}

overwriteArrays() {
    int i = 0;
    for (i = 0; i < 15; i++) {
        currentSensors[i] = newSensors[i];
    }
}

int convert(long long n) {
    int dec = 0, i = 0, rem;
    while (n != 0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    return dec;
}