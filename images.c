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

void loadImage(FILE *loadfp, int boundRows, int boundCols, int* rows, int* cols, int size, char string[]);
void saveToArray(FILE *loadfp, int size, char string[], int rows, int cols, int image[][cols]);
void displayImage(int rows, int cols, int image[][cols]);
void editImage();
void cropImage();
void dimImage();
void brightenImage();
void rotateImage();
void saveImage();

int main(){
	int choice, defaultRow, defaultCol, row, col, picture[row][col];
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
			loadImage(fptr, MAXSIZER, MAXSIZEC, &row, &col, LENGTH, fileName);
			saveToArray(fptr, LENGTH, fileName, row, col, picture);
		}
		
		//if the user enters 2, display the image
		else if(choice == 2){
			printf("\nDisplay was selected.\n\n");
			displayImage(row, col, picture);
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
void loadImage(FILE *loadfp, int boundRows, int boundCols, int* rows, int* cols, int size, char string[]){


	// Declaring input here, as we need to make sure the loop only picks out nums.
	
	int totalRows = 0, totalCols = 0, testArray[boundRows][boundCols];
  	char input;


	// Name of file
   	printf("Enter the name of the image file: ");
   	scanf("%s", string);

	// Opening file
   	loadfp = fopen(string, "r");
    
    	// Return
  	if (loadfp == NULL) {
     		printf("Could not open file.\n");
       		return;
    	}



	
	
	// Make sure that we are reading SOMETHING from the input.
    	while (fscanf(loadfp, "%c", &input) == 1) {
        	if (input >= '0' && input <= '4') {
            	testArray[totalRows][totalCols++] = input;
        } else if (input == '\n') {
 
            	if (totalRows == 0) {
                	*cols = totalCols;
           	 }
            	totalRows++;
        }
    }

   //Tallying up totalRow and converting to pointer
    *rows = totalRows;
    

    printf("Reading: Rows = %d, Cols = %d\n", *rows, *cols);

    fclose(loadfp);
}
//DJ and Rajat
void saveToArray(FILE *loadfp, int size, char string[], int rows, int cols, int image[][cols]){

	int image[100][100] = {0};

	// Opening file
   	loadfp = fopen(string, "r");
   	
   	// Return
  	if (loadfp == NULL) {
     		printf("Could not open file.\n");
       		return;
    	}
    	
	
	for(int i = 0; i<rows; i++){
		for(int g = 0; g<cols; g++){

			fscanf(loadfp, "%d", &image[i][g]);
		}
	}
	printf("Sucess!\n");
	fclose(loadfp);
}

void displayImage(int rows, int cols, int image[][cols]){
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			switch (image[i][j]) {
				case 0:
					printf(" ");
					break;
				case 1: 
					printf(".");
					break;
				case 2: 
					printf("o");
					break;
				case 3:
					printf("O");
					break;
				case 4:
					printf("0");
					break;
				default:
					printf(" ");
					break;
			}
		}
		printf("\n");
	}
    
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
