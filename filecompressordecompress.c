#include<stdio.h>
#include<stdlib.h>

//funtion to compress the file using RLE

void compressFile(char *sourceFile, char *destFile) {
	FILE *inFile = fopen(sourceFile, "r");
	FILE *outFile = fopen(destFile, "w");
	
	if (inFile == NULL || outFile == NULL) {
		printf("Error opening file!\n");
		return;
	}
	
	char currentChar, nextChar;
	int count;
	
	currentChar = fgetc(inFile);
	while (currentChar != EOF) {
		count = 1;
		nextChar = fgetc(inFile);
		
		while (currentChar == nextChar && count < 255) {// limit count to 255
			count++;
			nextChar= fgetc(inFile);
		}
		//write a compressed data: character + char
		fputc(currentChar, outFile);
		fputc(count, outFile);
		currentChar = nextChar;
	}
	
	fclose(inFile);
	fclose(outFile);
	printf("File compressed successfully!\n");
}
// function to decompress file using RLE

void decompressFile(char *sourceFile, char *destFile) {
	FILE *inFile = fopen(sourceFile, "r");
	FILE *outFile = fopen(destFile, "w");
	
	if (inFile == NULL || outFile == NULL) {
		printf("Error opening file!\n");
		return;
	}
	
	char currentChar;
	int count;
	
	currentChar = fgetc(inFile);
	while (currentChar != EOF) {
		count = fgetc(inFile); // read count
		//write the character 'count' times in the output file 
		for (int i = 0; i < count; i++) {
			fputc(currentChar, outFile);
		}
		
		currentChar = fgetc(inFile); // read next character
	}
	
	fclose(inFile);
	fclose(outFile);
	printf("File decompressed successfully!\n");
}

int main() {
	int choice;
	char sourceFile[100], destFile[100];
	
	printf("1. Compress file\n");
	printf("2. Decpmress file\n");
	scanf("%d", &choice);
	
	printf("Enter source file name: ");
	scanf("%s", destFile);
	if (choice == 1) {
		compressFile(sourceFile, destFile);
	}	else if (choice == 2) {
		decompressFile(sourceFile, destFile);
	} else {
		printf("Invalid input\n");
	}
	
	return 0;
}
