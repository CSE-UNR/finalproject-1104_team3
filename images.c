/**
*Authors: DJ DeLucca and Rajat Sharma
*Date: 5/3/2024
*Purpose: Make an image processing program
*/

#include <stdio.h>

void loadImage();
void displayImage();
void editImage();
void cropImage();
void dimImage();
void brightenImage();
void rotateImage();
void saveImage();

int main(){
	int choice;
	
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
			printf("\nLoad was selected.\n\n");
		}
		//if the user enters 2, display the image
		else if(choice == 2){
			printf("\nDisplay was selected.\n\n");
		}
		//if the user enters 3, edit the image
		else if(choice == 3){
			printf("\nEdit was selected.\n\n");
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
void loadImage(){

}

//DJ and Rajat
void displayImage(){

}

//DJ
void editImage(){

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
