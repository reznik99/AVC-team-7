#include <stdio.h>
#include "E101.h"
int main (){
	init();
	int counter = 0; //debugging
	 while(true){
	 	checkPath();
	 	sleep1(1/30);
	 	counter ++; //debugging
	 	if(counter == 30){
	 		break;
	 	}
	 }
	return 0;
}

int checkPath(){
	take_picture(); //takes picture
	int centered = checkPicture();
	if(centered == 0){// if off trajectory
		adjustTrajectory(); //adjust it
	}
	return 0;
}

int checkPicture(){//this function returns 0 if off trajectory and 1 if on trajectory
	int[] pictureArray = new int[21600];
	for(int i=0;i<240;i+2){//image is 360x240
		for(int j=0;j<360;j+=2){// check every 2 pixels
			int pixelColor = get_pixel(i,j,3);
			pictureArray[j*i] = pixelColor;
		}
	}
}

int adjustTrajectory(){
	set_motor(0,255);
	set_motor(1,255);
  // here we will adjust the trajectory using functions like 15 degrees oand 30 degrees etc..
}
