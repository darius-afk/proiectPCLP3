#include <stdio.h>
#include <stdlib.h>

void encryptFile(const char* inputFileName, const char* outputFileName, const char* key) {// functia pentru criptare a fisierului primeste numele fisierului de intrare, de iesire si cheia
    FILE *inputFile = fopen(inputFileName, "rt");// fisierele sunt de tip text
    FILE *outputFile = fopen(outputFileName, "wt");

    if (inputFile == NULL || outputFile == NULL) {// daca nu s-au putut deschide fisierele
        printf("Eroare la deschiderea fisierelor!\n");
        return;
    }

    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile); // returneaza pozitiaa curenta a indicatorului
    rewind(inputFile); //seteaza pozitia curenta a indicatorului de fisier la inceputul fisierului

    unsigned char* buffer = (unsigned char*)malloc(fileSize);// alocam memorie pentru buffer
    fread(buffer, 1, fileSize, inputFile); // citim din fisier in buffer

}

void decryptFile(const char* inputFileName, const char* outputFileName, const char* key) {
    
}

int main() {
    

    return 0;
}
