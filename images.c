/**
*Authors: DJ DeLucca and Rajat Sharma
*Date: 5/3/2024
*Purpose: Create an image processing program
*/

#include <stdio.h>

#define LENGTH 100
#define MAXSIZER 500
#define MAXSIZEC 500

void loadImage(FILE *loadfp, int* rows, int* cols, int size, char string[], int image[][MAXSIZEC]);
void saveToArray(FILE *loadfp, int size, char string[], int rows, int cols, int image[][MAXSIZEC]);
void displayImage(int rows, int cols, int image[][MAXSIZEC]);
void editImage(FILE *loadfp, int size, char string[], int rows, int cols, int image[][MAXSIZEC]);
void cropImage(int rows, int cols, int image[][MAXSIZEC]);
void brightOrDim(int rows, int cols, int image[][MAXSIZEC], int option);
void rotateImage(int rows, int cols, int image[][MAXSIZEC]);
void saveImage(FILE *loadfp, int size, char string[], int rows, int cols, int image[][MAXSIZEC]);
void repositionedSaver(int rows, int cols, int image[][MAXSIZEC]);

int main(){
    int choice, row, col;
    char fileName[LENGTH + 1],saveFile[LENGTH + 1];
    FILE *fptr;
    int picture[MAXSIZER][MAXSIZEC]; // Declaring the picture array
	
	// Printing the menu while choice is not 0
    do {
        printf("**ERINSTAGRAM**\n");
        printf("1: Load image\n");
        printf("2: Display image\n");
        printf("3: Edit image\n");
        printf("0: Exit\n");
        printf("\nChoose from one of the options above: ");
        scanf("%d", &choice);
        
     	// Options based on choice made from menu including invalid entry
  		switch (choice) {
			case 0:
				printf("\nGoodbye!\n\n");
				break;
        	case 1:
      			loadImage(fptr,&row, &col, LENGTH, fileName, picture);
		        saveToArray(fptr, LENGTH, fileName, row, col, picture);
        		break;
        	case 2:
        	    printf("\nDisplay was selected.\n\n");
            	displayImage(row, col, picture);
            	break;
            	case 3:
            	editImage(fptr, LENGTH, saveFile, row, col, picture);
            	break;
            default:
            	printf("Invalid option, please try again:\n\n");
            	break;
        
        }
    } while(choice != 0);
    
    return 0;
}

// Gets the user's file they want to access
void loadImage(FILE *loadfp, int* rows, int* cols, int size, char string[], int image[][MAXSIZEC]){
    // Declaring input here, as we need to make sure the loop only picks out nums.
    int totalRows = 0, totalCols = 0;
    char input;

    // Prompting the user for the filename
    printf("What is the name of the image file? ");
    scanf("%s", string);

    // Opening file
    loadfp = fopen(string, "r");

    // Check if file can be accessed
    if (loadfp == NULL) {
        printf("Could not open file.\n");
        return;
    }

    // Make sure that we are reading SOMETHING from the input.
    while (fscanf(loadfp, "%c", &input) == 1) {
        if (input >= '0' && input <= '4') {
            image[totalRows][totalCols++] = input;
        } else if (input == '\n') {
            if (totalRows == 0) {
                *cols = totalCols;
            }
            totalRows++;
        }
    }
    *rows = totalRows;
    fclose(loadfp);
}

// Uses the previously saved filename from the loadIMage function to read the file contents and store to a 2D array
void saveToArray(FILE *loadfp, int size, char string[], int rows, int cols, int image[][MAXSIZEC]){
    // Opening file
    loadfp = fopen(string, "r");

    // Check if file can be accessed
    if (loadfp == NULL) {
        printf("Could not open file.\n");
        return;
    }
	
	// Loop through file and save to the image array, close when complete
    for(int i = 0; i < rows; i++) {
        for(int g = 0; g < cols; g++) {
            fscanf(loadfp, "%1d", &image[i][g]);
        }
    }
    printf("\nImage successfully saved!\n\n");
    fclose(loadfp);
}

// Displays the user's image using the 2D array from the saveToArray function
void displayImage(int rows, int cols, int image[][MAXSIZEC]){
    // Loop through 2D array and print converted values of 0-4 to screen
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

// Displays the edit menu and uses edit/save functions
void editImage(FILE *loadfp, int size, char string[], int rows, int cols, int image[][MAXSIZEC]){
    int choice;
    printf("**EDITING**\n");
    printf("1: Crop image\n");
    printf("2: Dim image\n");
    printf("3: Brighten image\n");
    printf("4: Rotate image\n");
    printf("0: Exit\n");
    printf("\nChoose from one of the options above: ");
    scanf("%d", &choice);
    
    // Options based on choice made from edit menu including invalid entry
    switch (choice) {
       	case 0:
       		// Save image
       		saveImage(loadfp, size, string, rows, cols, image);
       		break;
       	case 1:
       		// Display current status of image and then crop image
       		printf("\nCrop was selected.\n\n");
        	displayImage(rows, cols, image);
       		cropImage(rows, cols, image);
        	break;
        case 2:
        	// Dim image, display result and save results
        	printf("\nDim was selected.\n\n");
			brightOrDim(rows, cols, image, choice);
        	displayImage(rows, cols, image);
        	saveImage(loadfp, size, string, rows, cols, image);
        	break;
        case 3:
        	// Brighten image, display result and save results
        	printf("\nBrighten was selected.\n\n");
		brightOrDim(rows, cols, image, choice);
        	displayImage(rows, cols, image);
        	saveImage(loadfp, size, string, rows, cols, image);
        	break;
        case 4: 
        	// Perform a rotation on the image
        	printf("\nRotate was selected.\n\n");
        	rotateImage(rows, cols, image);
        	break;
        default:
        	printf("\nInvalid option, returning to main menu...\n\n");
        	break;
        }
   
}

// Crops the image from specifed coordinates in the image's 2D array
void cropImage(int rows, int cols, int image[][MAXSIZEC]) {
    int leftCol, rightCol, topRow, botRow;

    printf("\nThe image you want to crop is %d x %d.\n", rows, cols);
    printf("\nThe row and column values start in the upper lefthand corner.\n\n");

    printf("\nWhich column do you want to be the new left side? ");
    scanf("%d", &leftCol);
    while (leftCol < 0 || leftCol >= cols) {
        printf("Invalid column value. Choose a value between 0 and %d: ", cols);
        scanf("%d", &leftCol);
    }

    printf("\nWhich column do you want to be the new right side? ");
    scanf("%d", &rightCol);
    while (rightCol <= leftCol || rightCol > cols) {
        printf("Invalid column value. Choose a value between %d and %d: ", leftCol + 1, cols);
        scanf("%d", &rightCol);
    }

    printf("\nWhich row do you want to be the new top? ");
    scanf("%d", &topRow);
    while (topRow < 0 || topRow >= rows) {
        printf("Invalid row value. Choose a value between 0 and %d: ", rows);
        scanf("%d", &topRow);
    }

    printf("\nWhich row do you want to be the new bottom? ");
    scanf("%d", &botRow);
    while (botRow <= topRow || botRow > rows) {
        printf("Invalid row value. Choose a value between %d and %d: ", topRow + 1, rows);
        scanf("%d", &botRow);
    }

	leftCol--;
	topRow--;
	int croppedImage[MAXSIZER][MAXSIZEC];
	int croppedRows = botRow - topRow;
	int croppedCols = rightCol - leftCol;

    for (int i = 0; i < croppedRows; i++) {
    	for (int j = 0; j < croppedCols; j++) {
    		croppedImage[i][j] = image[topRow + i][leftCol + j];
    	
		}
    }
    
    displayImage(croppedRows, croppedCols, croppedImage);
	repositionedSaver(croppedRows, croppedCols, croppedImage);
}

// Brightens or dims the image
void brightOrDim(int rows, int cols, int image[][MAXSIZEC], int option) {
	// Options based off of user input from the edit menu
	switch (option) {
		case 2: 
			// Dim image by decrementing indivdual vales but not changing if read value is 0
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					if (image[i][j] > 0) {
					image[i][j]--;
					}
				}
			}
			break;
		case 3:
			// Brighten image by incrementing indivdual vales but not changing if read value is 4
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					if (image[i][j] < 4) {
						image[i][j]++;
					}
				}
			}
			break;
		default:
        	printf("\nInvalid option, returning to main menu.\n\n");
        	break;
	}
}

// Rotates the image clockwise 90 degrees
void rotateImage(int rows, int cols, int image[][MAXSIZEC]) {
	int rotatingArray[MAXSIZER][MAXSIZEC];
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
            	rotatingArray[j][rows - 1 - i] = image[i][j];
        }
    }

	int tempRows = rows;
	rows = cols;
	cols = tempRows;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            	image[i][j] = rotatingArray[i][j];
        }
    }

    displayImage(rows, cols, rotatingArray);
    repositionedSaver(rows, cols, rotatingArray);
}

// Saves the user's photo to a file
void saveImage(FILE *loadfp, int size, char string[], int rows, int cols, int image[][MAXSIZEC]){
    char select;
    
	// Prompt the user to save their changes to a file
	printf("Would you like to save the file? (y/n) ");
	scanf(" %c", &select);
	
	// Options based on if the user wants to save or not inlcuding an invalid entry
	switch (select){
		case 'Y':
		case 'y':	
			// Prompting the user for a filename	
			printf("What do you want to name the image file? (include the extension) ");
    		scanf("%s", string);
    		
    		// Opening file
			loadfp = fopen(string, "w");

			// Check if file can be accessed
			if (loadfp == NULL) {
				printf("Could not open file.\n");
				return;
			}
			
			// Print to specified document and close doc
			for (int r = 0; r < rows; r++){
				for(int c = 0; c < cols; c++){
					fprintf(loadfp, "%d", image[r][c]);
				}
				fprintf(loadfp, "\n");
			}
			printf("\nImage successfully saved!\n\n");
			fclose(loadfp);
			break;
		case 'N':
		case 'n':
			break;
		default:
			printf("\nReturning to main menu...\n\n");
			break;
	}		
}

// Saves the user's photo to a file after crop or rotate has been completed
void repositionedSaver(int rows, int cols, int image[][MAXSIZEC]) {
	char fileString[LENGTH + 1];
	char choice;
	
	// Prompt the user to save their changes to a file
	printf("Would you like to save the file? (y/n) ");
	scanf(" %c", &choice);
	
	// Options based on if the user wants to save or not inlcuding an invalid entry
	switch (choice) {
		case 'Y':
		case 'y':
			// Prompting the user for a filename
			printf("What do you want to name the image file? (include the extension) ");
			scanf("%s", fileString);
			
			// File pointer declaration and opening file
			FILE *filePtr = fopen(fileString, "w");
			
			// Check if file can be accessed
			if (filePtr == NULL) {
				printf("Could not open file. Please try again.\n");
				return;
			}
			
			// Print to specified document and close doc
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					fprintf(filePtr, "%d", image[i][j]);
				}
				fprintf(filePtr, "\n");
			}
			printf("\nImage successfully saved!\n\n");
			fclose(filePtr);
			break;
		case 'N':
		case 'n':
			break;
		default:
			printf("\nReturning to main menu...\n\n");
			break;
	}
}
