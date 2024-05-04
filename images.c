/**
*Authors: DJ DeLucca and Rajat Sharma
*Date: 5/3/2024
*Purpose: Make an image processing program
*/

#include <stdio.h>
#include <stdbool.h>
#define LENGTH 100
#define MAXSIZER 500
#define MAXSIZEC 500

void loadImage(FILE *loadfp, int boundRows, int boundCols, int* rows, int* cols, int size, char string[], int image[][boundCols]);
void displayImage();
void editImage();
void cropImage();
void dimImage();
void brightenImage();
void rotateImage();
void saveImage();

int main(){
	int choice, defaultRow, defaultCol, row, col, picture [MAXSIZER] [MAXSIZEC];
	char fileName[LENGTH + 1];
	FILE *fptr; 
	
	do{
		//print main menu
		printf("**ERINSTAGRAM**\n");
		printf("1: Load image\n");
		printf("2: Display image\n");
		printf("3: Edit image\n");
		printf("0: Exit\n");
		printf("\nChoose from one of the options above: ");
		scanf("%d", &choice);
		
		//if the user enters 1, load the image
		if(choice == 1){
			loadImage(fptr, MAXSIZER, MAXSIZEC, &row, &col, LENGTH, fileName, picture);
		}
		
		//if the user enters 2, display the image
		else if(choice == 2){
			printf("\nDisplay was selected.\n\n");
		}
		//if the user enters 3, edit the image
		else if(choice == 3){
			editImage();
		}
		//invalid case
		else if(choice != 1 && choice != 2 && choice != 3 && choice != 0){
			printf("\nInvalid option, please try again.\n\n");
		}
		
	}while(choice != 0);
	//if the user enters 0, the program ends
	if(choice == 0){
		printf("\nGoodbye!\n\n");
	}
	
	return 0;
}

//DJ
void loadImage(FILE *loadfp, int boundRows, int boundCols, int* rows, int* cols, int size, char string[], int image[][boundCols]){
	int totalRows = 0, totalCols = 0;
	
	printf("What is the name of image file? ");
	scanf("%s", string);
	
	loadfp = fopen(string, "r");
	if(loadfp == NULL){
		printf("Can't open file\n");
	}
	else{
		bool column = false;
		bool row = false;
		
		for (int i = 0; column != true; i++) {
			for (int g = 0; row != true; i++) {
				fscanf(loadfp, "%d", &image[boundRows][boundCols]);
				totalCols++;
				if (image[i][g] == '\n') {
					row = true;
				}
				else if(image[i][g] == '\0'){
					column = true;
				}
				
			}
			totalRows++;
			row = false;
		}
		//while loop that checks if bool 2 is true
		//while loop that checks for if bool is true
			//fscanf to grab new character
			//if statement that checks if newest char in line is a newline
				// if if statement is true set bool to true to stop loop
			//g++
		//i++
		//if statement that checks if first character on next row is null if so set bool 2 to true to stop loop
		*rows = totalRows;
		*cols = totalCols;
		printf("Rows: %d, Columns: %d\n", *rows, *cols);
	}
	fclose(loadfp);
}

//DJ and Rajat
void displayImage(){

}

//DJ
void editImage(){
	int option;
	do{
		//print edit menu
		printf("**EDITING**\n");
		printf("1: Crop image\n");
		printf("2: Dim image\n");
		printf("3: Brighten image\n");
		printf("4: Rotate image\n");
		printf("0: Exit\n");
		printf("\nChoose from one of the options above: ");
		scanf("%d", &option);
		
		//if the user enters 1, crop the image
		if(option == 1){
			printf("\nCrop was selected.\n\n");
		}
		
		//if the user enters 2, dim the image
		else if(option == 2){
			printf("\nDim was selected.\n\n");
		}
		//if the user enters 3, brighten the image
		else if(option == 3){
			printf("\nBrighten was selected.\n\n");
		}
		//if the user enters 4, rotate the image
		else if(option == 4){
			printf("\nRotate was selected.\n\n");
		}
		//invalid case
		else if(option != 1 && option != 2 && option != 3 && option != 4 && option != 0){
			printf("\nInvalid option, please try again.\n\n");
		}
		
	}while(option != 0);
	//if the user enters 0, the function returns to the main menu
	if(option == 0){
		printf("\nReturning to main menu\n\n");
	}
}

//Rajat
void cropImage(){

}

//Rajat
void dimImage(){

}

//Rajat
void brightenImage(){

}

//DJ and Rajat
void rotateImage(){

}

//DJ
void saveImage(){

}
