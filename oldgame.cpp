//#include "mbed.h"
//#include "RGBmatrixPanel.h" // Hardware-specific library
//#include "game.h"
//#include <cstdlib>
//#include "SNESController.h"
//#include "utils.h"
//
//int game_state = 0;
//int game_end = 0;
//int score = 0;
//int answer_key = 0;
//int key_pressed = 0;
//uint8_t controller_input = 0;
//DigitalIn sw2(SW2);
//DigitalIn sw3(SW3);
//
//
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
//
//
//SNESController snes(PTC3, PTC2, PTA2);
//
//RGBmatrixPanel matrix(ur1,ug1,ub1,lr2,lg2,lb2,a,b,c,clk,latch,oe,false);
////RGBmatrixPanel(r1, g1, b1, r2, g2, b2, a, b, c, sclk, latch, oe, enable double_buffer);
//
//
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
//
////void draw_mole(int x){
////  //Face
////  matrix.drawCircle(x, 7, 7, matrix.Color333(165,42,42));
////  //Nose
////  matrix.drawCircle(x, 6, 1, matrix.Color333(255, 192, 203));
////  //Right eye
////  matrix.drawCircle(x-2, 10, 0, matrix.Color333(0, 0, 7));
////  //Left eye
////  matrix.drawCircle(x+2, 10, 0, matrix.Color333(0, 0, 7));
////  //Right top whisker
////  matrix.drawLine(x-2, 7, x-3, 8, matrix.Color333(220,220,220));
////  //Right middle whisker
////  matrix.drawLine(x-2, 6, x-3, 6, matrix.Color333(220,220,220));
////  //Right bottom whisker
////  matrix.drawLine(x-2, 5, x-3, 4, matrix.Color333(220,220,220));
////  
////  //Left top whisker
////  matrix.drawLine(x+2, 7, x+3, 8, matrix.Color333(220,220,220));
////  //Left middle whisker
////  matrix.drawLine(x+2, 6, x+3, 6, matrix.Color333(220,220,220));
////  //Left bottom whisker
////  matrix.drawLine(x+2, 5, x+3, 4, matrix.Color333(220,220,220));
////}
//
//void draw_score(int x){
//        matrix.setCursor(13, 9);   // start at top left, with one pixel of spacing
//        matrix.setTextSize(0);    // size 1 == 8 pixels high
//        matrix.setTextColor(matrix.Color333(7,0,0));
//        if (x == 1){
//            matrix.putc('1');
//        } else if (x == 2){
//            matrix.putc('2');
//        } else if (x == 3){
//            matrix.putc('3');
//        } else if (x == 4){
//            matrix.putc('4');
//        } else if (x == 5){
//            matrix.putc('5');
//        } else if (x == 6){
//            matrix.putc('6');
//        } else if (x == 7){
//            matrix.putc('7');
//        } else if (x == 8){
//            matrix.putc('8');
//        } else if (x == 9){
//            matrix.putc('9');
//        } else {
//            matrix.putc('0');
//        }
//}
//
//void draw_mole(int x){
//    //Face
//    matrix.drawCircle(x, 7, 7, matrix.Color333(165,42,42));
//    //Nose
//    matrix.drawCircle(x, 8, 1, matrix.Color333(255, 192, 203));
//    //Right eye
//    matrix.drawCircle(x-2, 4, 0, matrix.Color333(0, 0, 7));
//    //Left eye
//    matrix.drawCircle(x+2, 4, 0, matrix.Color333(0, 0, 7));
//    //Right top whisker
//    matrix.drawLine(x-2, 7+2, x-3, 8+2, matrix.Color333(220,220,220));
//    //Right middle whisker
//    matrix.drawLine(x-2, 6+2, x-3, 6+2, matrix.Color333(220,220,220));
//    //Right bottom whisker
//    matrix.drawLine(x-2, 5+2, x-3, 4+2, matrix.Color333(220,220,220));
//    
//    //Left top whisker
//    matrix.drawLine(x+2, 7+2, x+3, 8+2, matrix.Color333(220,220,220));
//    //Left middle whisker
//    matrix.drawLine(x+2, 6+2, x+3, 6+2, matrix.Color333(220,220,220));
//    //Left bottom whisker
//    matrix.drawLine(x+2, 5+2, x+3, 4+2, matrix.Color333(220,220,220));
//}
//
//
//
//void draw_redmole(int x){
//    //Face
//    matrix.drawCircle(x, 7, 7, matrix.Color333(255, 0 ,0));
//    //Nose
//    matrix.drawCircle(x, 8, 1, matrix.Color333(255, 0 ,0));
//    //Right eye
//    matrix.drawCircle(x-2, 4, 0, matrix.Color333(255, 0 ,0));
//    //Left eye
//    matrix.drawCircle(x+2, 4, 0, matrix.Color333(255, 0 ,0));
//    //Right top whisker
//    matrix.drawLine(x-2, 7+2, x-3, 8+2, matrix.Color333(255, 0 ,0));
//    //Right middle whisker
//    matrix.drawLine(x-2, 6+2, x-3, 6+2, matrix.Color333(255, 0 ,0));
//    //Right bottom whisker
//    matrix.drawLine(x-2, 5+2, x-3, 4+2, matrix.Color333(255, 0 ,0));
//    
//    //Left top whisker
//    matrix.drawLine(x+2, 7+2, x+3, 8+2, matrix.Color333(255, 0 ,0));
//    //Left middle whisker
//    matrix.drawLine(x+2, 6+2, x+3, 6+2, matrix.Color333(255, 0 ,0));
//    //Left bottom whisker
//    matrix.drawLine(x+2, 5+2, x+3, 4+2, matrix.Color333(255, 0 ,0));
//}
//
//
//
//void draw_greenmole(int x){
//    //Face
//    matrix.drawCircle(x, 7, 7, matrix.Color333(0, 255 ,0));
//    //Nose
//    matrix.drawCircle(x, 8, 1, matrix.Color333(0, 255 ,0));
//    //Right eye
//    matrix.drawCircle(x-2, 4, 0, matrix.Color333(0, 255 ,0));
//    //Left eye
//    matrix.drawCircle(x+2, 4, 0, matrix.Color333(0, 255 ,0));
//    //Right top whisker
//    matrix.drawLine(x-2, 7+2, x-3, 8+2, matrix.Color333(0, 255 ,0));
//    //Right middle whisker
//    matrix.drawLine(x-2, 6+2, x-3, 6+2, matrix.Color333(0, 255 ,0));
//    //Right bottom whisker
//    matrix.drawLine(x-2, 5+2, x-3, 4+2, matrix.Color333(0, 255 ,0));
//    
//    //Left top whisker
//    matrix.drawLine(x+2, 7+2, x+3, 8+2, matrix.Color333(0, 255 ,0));
//    //Left middle whisker
//    matrix.drawLine(x+2, 6+2, x+3, 6+2, matrix.Color333(0, 255 ,0));
//    //Left bottom whisker
//    matrix.drawLine(x+2, 5+2, x+3, 4+2, matrix.Color333(0, 255 ,0));
//}
//
//void selector(int x, int y){
//    matrix.drawCircle(x, y, 2, matrix.Color333(0, 0, 255));
//}
//
//
//void evaluateAnswer() {
//    if (key_pressed != answer_key) {
//        if (answer_key == KEY_LEFT){
//            draw_redmole(7);
//            matrix_delay(1000);     
//        } else {
//            draw_redmole(24);
//            matrix_delay(1000);     
//        }
//        if (score == 0){
//        } else {
//            score--;
//        }
//
//        matrix.fillScreen(matrix.Color333(0,0,0));
//        draw_score(score);
//        matrix_delay(1000);
//
//
//    } else {
//        if (answer_key == KEY_LEFT){
//            draw_greenmole(7);
//            matrix_delay(1000);     
//        } else {
//            draw_greenmole(24);
//            matrix_delay(1000);     
//        }
//
//        score++;
//
//
//        matrix.fillScreen(matrix.Color333(0,0,0));
//        draw_score(score);
//        
//        matrix_delay(1000);
//
//    }
//}
//void game_init(void){
//
//    game_state = GAME_INIT;
//    game_run();
//}
//
//void game_run(void){
//    game_end = 0;
//    // main game implemented here
//    while(!game_end){
//        switch(game_state){
//            case GAME_INIT:
//                game_state = GAME_START;
//                break;
//            case GAME_START:
//                game_update_beta();
//                break;
//            case GAME_END:
//                matrix_delay(1000);
//
//                game_end = 1;
//                break;
//            default:
//                break;
//        }
//    }
//}
//
//int draw_moles (void) {
//    int pos = rand() % 2;
//    int key = (pos == 0) ? KEY_LEFT : KEY_RIGHT;
//    return key;
//}
//
//void game_update_beta(void) {
//    // draw moles
//    key_pressed = 0;
//    answer_key = draw_moles(); // draw moles function updates display, and also returns key
//    // poll for x seconds for the right key
//    int time = 0;
//
//    while (key_pressed == 0 && time < 3) {
//      if (sw2==0) {
//          key_pressed = KEY_RIGHT;
//      } else if (sw3 == 0) {
//          key_pressed = KEY_LEFT;
//      }
//        if (answer_key == KEY_LEFT){
//            draw_mole(7);
//            matrix_delay(1000);     
//        } else {
//            draw_mole(24);
//            matrix_delay(1000);     
//        }
//        time++; // wait
//    }
//
//    evaluateAnswer();
//}
//
//
//
//int main() {
//
//    game_init();
//}
//
