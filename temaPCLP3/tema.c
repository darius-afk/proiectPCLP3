#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    int keyLength = strlen(key);// lungimea cheii
    int keyIndex = 0;// indexul cheii folosit pentru criptare

    for (long i = 0; i < fileSize; i++) {// parcurgem bufferul si criptam
        buffer[i] ^= key[keyIndex];// criptam cu xor
        keyIndex = (keyIndex + 1) % keyLength;// incrementam indexul cheii keyIndex este actualizată pentru a parcurge ciclic cheia. Folosesc modulo pentru a fi sigur ca raman in intervalul [0, keyLength)
    }

    fwrite(buffer, 1, fileSize, outputFile);// scriem continutul bufferului in fisierul de iesire

    fclose(inputFile);// inchidem fisierele
    fclose(outputFile);

    free(buffer);// eliberam memoria alocata
}

void decryptFile(const char* inputFileName, const char* outputFileName, const char* key) {
    encryptFile(inputFileName, outputFileName, key);// criptarea si decriptarea sunt aceleasi operatii
}

int main() {
    const char* inputFileName = "input.txt";// fisierul ce urmeaza sa fie criptat
    const char* encryptedFileName = "encrypted.txt";// fisierul criptat
    const char* decryptedFileName = "decrypted.txt";// fisierul decriptat
    char key[256];// cheia dupa care se cripteaza
    
    printf("Introduceți cheia de criptare/decriptare: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Elimină caracterul newline de la sfârșitul șirului introdus

    encryptFile(inputFileName, encryptedFileName, key);// criptam fisierul
    printf("Fișierul a fost criptat cu succes.\n");

    decryptFile(encryptedFileName, decryptedFileName, key);// decriptam fisierul
    printf("Fișierul a fost decriptat cu succes.\n");

    return 0;
}
