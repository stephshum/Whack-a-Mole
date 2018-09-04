//// Running this program successfully would ensure the following behavior:
//// 		- checks if game state initialises correctly
//// 		- checks if game state ends correctly
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
//int game_state;
//
//SNESController snes(PTC3, PTC2, PTA2);
//RGBmatrixPanel matrix(ur1,ug1,ub1,lr2,lg2,lb2,a,b,c,clk,latch,oe,false);
//
//int timer = 0;
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
//void game_init(void){
//	game_state = GAME_INIT;
//	draw(0, 0);
//	game_run();
//}
//
//void game_end(void){
//	clearDrawing(0, 0);
//}
//
//
//void game_run(void){
//	game_state = 0;
//	// main game implemented here
//	while(!game_end){
//		switch(game_state){
//			case GAME_INIT:
//				game_state = GAME_START;
//				break;
//			case GAME_START:
//				if (timer > 99999999) {
//					game_state = GAME_END;
//				}
//				break;
//			case GAME_END:
//				while (1){
//		        	clearDrawing(0, 0);
//	        	}
//				break;
//			default:
//				break;
//		}
//	}
//}
//
//int main() {
//	game_init();
//}
//
