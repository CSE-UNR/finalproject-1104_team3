/**
*Authors: DJ DeLucca and Rajat Sharma
*Date: 5/3/2024
*Purpose: Create an image processing program
*/

#include <stdio.h>
#include <stdbool.h>

#define LENGTH 100
#define MAXSIZER 500
#define MAXSIZEC 500

void loadImage(FILE *loadfp, int boundRows, int boundCols, int* rows, int* cols, int size, char string[], int image[][MAXSIZEC]);
void saveToArray(FILE *loadfp, int size, char string[], int rows, int cols, int image[][MAXSIZEC]);
void brightenImage(int rows, int cols, int image[][MAXSIZEC]);
void displayImage(int rows, int cols, int image[][MAXSIZEC]);
void editImage(int rows, int cols, int image[][MAXSIZEC]);
void cropImage();
void dimImage(int rows, int cols, int image[][MAXSIZEC]);
void rotateImage();
void saveImage(FILE *loadfp, int size, char string[], int rows, int cols, int image[][MAXSIZEC]);

int main(){
    int choice, row, col;
    char fileName[LENGTH + 1];
    FILE *fptr;
    int picture[MAXSIZER][MAXSIZEC]; // Declaring the picture array

    do {
        printf("**ERINSTAGRAM**\n");
        printf("1: Load image\n");
        printf("2: Display image\n");
        printf("3: Edit image\n");
        printf("0: Exit\n");
        printf("\nChoose from one of the options above: ");
        scanf("%d", &choice);
        
        
  	switch (choice) {
		case 0:
			printf("\nGoodbye!\n\n");
			break;
        	case 1:
      			loadImage(fptr, MAXSIZER, MAXSIZEC, &row, &col, LENGTH, fileName, picture);
		        saveToArray(fptr, LENGTH, fileName, row, col, picture);
        		break;
        	case 2:
        	      	printf("\nDisplay was selected.\n\n");
            		displayImage(row, col, picture);
            		break;
            	case 3:
            		editImage(row, col, picture);
            		break;
            	default:
            		printf("Invalid option, please try again:\n\n");
            		break;
        
        }
    } while(choice != 0);
    
    return 0;
}


void loadImage(FILE *loadfp, int boundRows, int boundCols, int* rows, int* cols, int size, char string[], int image[][MAXSIZEC]){
    // Declaring input here, as we need to make sure the loop only picks out nums.
    int totalRows = 0, totalCols = 0;
    char input;

    // Name of file
    printf("What is the name of the image file? ");
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
            image[totalRows][totalCols++] = input;
        } else if (input == '\n') {
            if (totalRows == 0) {
                *cols = totalCols;
            }
            totalRows++;
            totalCols = 0;
        }
    }
    *rows = totalRows;
    fclose(loadfp);
}


void saveToArray(FILE *loadfp, int size, char string[], int rows, int cols, int image[][MAXSIZEC]){
    // Opening file
    loadfp = fopen(string, "r");

    // Return
    if (loadfp == NULL) {
        printf("Could not open file.\n");
        return;
    }

    for(int i = 0; i < rows; i++) {
        for(int g = 0; g < cols; g++) {
            fscanf(loadfp, "%1d", &image[i][g]);
        }
    }
    printf("\nImage successfuly saved!\n\n");
    fclose(loadfp);
}

void displayImage(int rows, int cols, int image[][MAXSIZEC]){
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
void editImage(int rows, int cols, int image[][MAXSIZEC]){
    int choice;
    do {
        printf("**EDITING**\n");
        printf("1: Crop image\n");
        printf("2: Dim image\n");
        printf("3: Brighten image\n");
        printf("4: Rotate image\n");
        printf("0: Exit\n");
        printf("\nChoose from one of the options above: ");
        scanf("%d", &choice);
        
        switch (choice) {
        	case 0:
        		break;
        	case 1:
        		printf("\nCrop was selected.\n\n");
        		break;
        	case 2:
        		printf("\nDim was selected.\n\n");
        		dimImage(rows, cols, image);
        		displayImage(rows, cols, image);
        		break;
        	case 3:
        		printf("\nBrighten was selected.\n\n");
        		brightenImage(rows, cols, image);
        		displayImage(rows, cols, image);
        		break;
        	case 4: 
        		printf("\nRotate was selected.\n\n");
        		break;
        	default:
        		printf("\nInvalid option, please try again.\n\n");
        		break;
        }
    } while(choice != 0);
}



//DJ
void saveImage(FILE *loadfp, int size, char string[], int rows, int cols, int image[][MAXSIZEC]){
    char select;

	printf("Save to file?(Y/N): ");
	scanf(" %c", &select);
	
	if(select == 'y' || select == 'Y'){		
		// Opening file
		loadfp = fopen(string, "w");

		// Return
		if (loadfp == NULL) {
			printf("Could not open file.\n");
			return;
		}
		for (int r = 0; r < rows; r++){
			for(int c = 0; c < cols; c++){
				fprintf(loadfp, "%d ", image[r][c]);
			}
		}
		fclose(loadfp);
	}		
    else if(select == 'n' || select == 'N'){
    	printf("Goodbye!");
    }
}

void brightenImage(int rows, int cols, int image[][MAXSIZEC]) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (image[i][j] < 4) {
				image[i][j]++;
			}
		}
	}
}


void dimImage(int rows, int cols, int image[][MAXSIZEC]) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (image[i][j] > 0) {
				image[i][j]--;
			}
		}
	}
}