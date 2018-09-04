//// Running this program successfully would ensure the following behavior of the controller:
//// 		- checks if controller pins are initialised correctly
//// 		- checks if up-down-left-right button and 'A' button works
////		- checks for polling behavior of controller input
////		- cursor updates correctly
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
//void draw(int x, int y){
//	matrix.drawCircle(x+4, 4+y, 3, matrix.Color333(165,42,42));
//}
//
//void clearDrawing(int x, int y){
//	matrix.drawCircle(x+4, 4+y, 3, matrix.Color333(0, 0, 0));
//}
//
//void poll_input(void){
//	    if (snes.pressed(snes.read(), snes.SNES_BUTTON_LEFT_ARROW)){
//	    	draw(0, 0);
//            matrix_delay(100);
//            clearDrawing(0, 0);
//        } else if (snes.pressed(snes.read(), snes.SNES_BUTTON_RIGHT_ARROW)){
//            draw(12, 0);
//            matrix_delay(100);
//            clearDrawing(0, 0);
//        } else if (snes.pressed(snes.read(), snes.SNES_BUTTON_UP_ARROW)){
//	    	draw(23, 0);
//            matrix_delay(100);
//            clearDrawing(0, 0);
//        } else if (snes.pressed(snes.read(), snes.SNES_BUTTON_DOWN_ARROW)){
//	    	draw(30, 0);
//            matrix_delay(100);
//            clearDrawing(0, 0);
//        } else if (snes.pressed(snes.read(), snes.SNES_BUTTON_A)) {
//        	draw(40, 0);
//            matrix_delay(100);
//            clearDrawing(0, 0);
//        }
//        matrix_delay(100);
//
//}
//
//
//int main() {
//	while(1) {
//		poll_input();
//	}
//}