//// This file tests for the LED panel in the following ways:
//// 		- checks if LED panel initialises correctly
////		- checks for draw and clear functions
//// 		- checks if numbers are drawn correctly
//// 		- checks if moles are drawn correctly at the right positions
//// 
//
//#include "mbed.h"
//#include "RGBmatrixPanel.h" // Hardware-specific library
//#include "game.h"
//#include <cstdlib>
//#include "SNESController.h"
//
//PinName ur1=PTB18;
//PinName ug1=PTB19;
//PinName ub1=PTD1;
//PinName lr2=PTD3;
//PinName lg2=PTD2;
//PinName lb2=PTD0;
//PinName a = PTB2;
//PinName b = PTB3;
//PinName c = PTB10;
//PinName latch = PTB11;
//PinName clk = PTB23;
//PinName oe = PTB9;
//
//SNESController snes(PTC3, PTC2, PTA2);
//RGBmatrixPanel matrix(ur1,ug1,ub1,lr2,lg2,lb2,a,b,c,clk,latch,oe,false);
//
//void matrix_delay(int x){
//    //Written with the help of Michael Xiao
//    int i=0;
//    while(i<x){
//        wait_us(10);
//        matrix.updateDisplay();
//        i++;
//    }
//}
//
//void draw_smallmole(int x, int y){
//	matrix.drawRect(x+1, y+1, 7, 7, matrix.Color333(0, 0, 50));
//	//Face
//	matrix.drawCircle(x+4, 4+y, 3, matrix.Color333(165,42,42));
//	//Nose
//	matrix.drawCircle(x+4, 5+y, 0, matrix.Color333(255, 192, 203));
//	//Right eye
//	matrix.drawCircle(x+3, 4+y, 0, matrix.Color333(0, 0, 7));
//	//Left eye
//	matrix.drawCircle(x+5, 4+y, 0, matrix.Color333(0, 0, 7));
//}
//
//void clr_smallmole(int x, int y){
//	matrix.drawRect(x+1, y+1, 7, 7, matrix.Color333(0, 0, 0));
//	//Face
//	matrix.drawCircle(x+4, 4+y, 3, matrix.Color333(0, 0, 0));
//	//Nose
//	matrix.drawCircle(x+4, 5+y, 0, matrix.Color333(0, 0, 0));
//	//Right eye
//	matrix.drawCircle(x+3, 4+y, 0, matrix.Color333(0, 0, 0));
//	//Left eye
//	matrix.drawCircle(x+5, 4+y, 0, matrix.Color333(0, 0, 0));
//}
//
//void draw_score(int x){
//		matrix.setCursor(13, 9);   // start at top left, with one pixel of spacing
//        matrix.setTextSize(0);    // size 1 == 8 pixels high
//        matrix.setTextColor(matrix.Color333(7,0,0));
//        if (x == 1){
//        	matrix.putc('1');
//        } else if (x == 2){
//        	matrix.putc('2');
//        } else if (x == 3){
//        	matrix.putc('3');
//        } else if (x == 4){
//        	matrix.putc('4');
//        } else if (x == 5){
//        	matrix.putc('5');
//        } else if (x == 6){
//        	matrix.putc('6');
//        } else if (x == 7){
//        	matrix.putc('7');
//        } else if (x == 8){
//        	matrix.putc('8');
//        } else if (x == 9){
//        	matrix.putc('9');
//    	} else {
//    		matrix.putc('0');
//    	}
//}
//
//
//void clr_draw_score(int x){
//		matrix.setCursor(13, 9);   // start at top left, with one pixel of spacing
//        matrix.setTextSize(0);    // size 1 == 8 pixels high
//        matrix.setTextColor(matrix.Color333(0,0,0));
//        if (x == 1){
//        	matrix.putc('1');
//        } else if (x == 2){
//        	matrix.putc('2');
//        } else if (x == 3){
//        	matrix.putc('3');
//        } else if (x == 4){
//        	matrix.putc('4');
//        } else if (x == 5){
//        	matrix.putc('5');
//        } else if (x == 6){
//        	matrix.putc('6');
//        } else if (x == 7){
//        	matrix.putc('7');
//        } else if (x == 8){
//        	matrix.putc('8');
//        } else if (x == 9){
//        	matrix.putc('9');
//    	} else {
//    		matrix.putc('0');
//    	}
//}
//
//int main() {
//	// moles
//	draw_smallmole(0, 0);
//	wait_us(5000000);
//	clr_smallmole(0, 0);
//
//	// numbers
//	int counter = 0;
//	while (counter < 10) {
//		draw_score(counter);
//		wait_us(5000000);
//		clr_draw_score(counter);
//		counter++;
//	}
//
//}