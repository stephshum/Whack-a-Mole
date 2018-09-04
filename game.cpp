#include "mbed.h"
#include "RGBmatrixPanel.h" // Hardware-specific library
#include "game.h"
#include <cstdlib>
#include "SNESController.h"
//latch PTC3
//clock PTC2
//data PTA2

int game_state = 0;
int game_end = 0;
int score = 0;
int answer_key = 0;
int key_pressed = 0;
uint8_t controller_input = 0;
//DigitalIn sw2(SW2);
//DigitalIn sw3(SW3);
int x = 0;
int y = 0;
bool moleArray[5] = {false, false, false, false, false};


PinName ur1=PTB18;
PinName ug1=PTB19;
PinName ub1=PTD1;
PinName lr2=PTD3;
PinName lg2=PTD2;
PinName lb2=PTD0;
PinName a = PTB2;
PinName b = PTB3;
PinName c = PTB10;
PinName latch = PTB11;
PinName clk = PTB23;
PinName oe = PTB9;



SNESController snes(PTC3, PTC2, PTA2);

RGBmatrixPanel matrix(ur1,ug1,ub1,lr2,lg2,lb2,a,b,c,clk,latch,oe,false);
//RGBmatrixPanel(r1, g1, b1, r2, g2, b2, a, b, c, sclk, latch, oe, enable double_buffer);



void matrix_delay(int x){
    //Written with the help of Michael Xiao
    int i=0;
    while(i<x){
        wait_us(10);
        matrix.updateDisplay();
        i++;
    }
}



void draw_score(int x){
		matrix.setCursor(13, 9);   // start at top left, with one pixel of spacing
        matrix.setTextSize(0);    // size 1 == 8 pixels high
        matrix.setTextColor(matrix.Color333(7,0,0));
        if (x == 1){
        	matrix.putc('1');
        } else if (x == 2){
        	matrix.putc('2');
        } else if (x == 3){
        	matrix.putc('3');
        } else if (x == 4){
        	matrix.putc('4');
        } else if (x == 5){
        	matrix.putc('5');
        } else if (x == 6){
        	matrix.putc('6');
        } else if (x == 7){
        	matrix.putc('7');
        } else if (x == 8){
        	matrix.putc('8');
        } else if (x == 9){
        	matrix.putc('9');
    	} else {
    		matrix.putc('0');
    	}
}


void clr_draw_score(int x){
		matrix.setCursor(13, 9);   // start at top left, with one pixel of spacing
        matrix.setTextSize(0);    // size 1 == 8 pixels high
        matrix.setTextColor(matrix.Color333(0,0,0));
        if (x == 1){
        	matrix.putc('1');
        } else if (x == 2){
        	matrix.putc('2');
        } else if (x == 3){
        	matrix.putc('3');
        } else if (x == 4){
        	matrix.putc('4');
        } else if (x == 5){
        	matrix.putc('5');
        } else if (x == 6){
        	matrix.putc('6');
        } else if (x == 7){
        	matrix.putc('7');
        } else if (x == 8){
        	matrix.putc('8');
        } else if (x == 9){
        	matrix.putc('9');
    	} else {
    		matrix.putc('0');
    	}
}


void draw_smallmole(int x, int y){
	matrix.drawRect(x+1, y+1, 7, 7, matrix.Color333(0, 0, 50));
	//Face
	matrix.drawCircle(x+4, 4+y, 3, matrix.Color333(165,42,42));
	//Nose
	matrix.drawCircle(x+4, 5+y, 0, matrix.Color333(255, 192, 203));
	//Right eye
	matrix.drawCircle(x+3, 4+y, 0, matrix.Color333(0, 0, 7));
	//Left eye
	matrix.drawCircle(x+5, 4+y, 0, matrix.Color333(0, 0, 7));
}

void clr_smallmole(int x, int y){
	matrix.drawRect(x+1, y+1, 7, 7, matrix.Color333(0, 0, 0));
	//Face
	matrix.drawCircle(x+4, 4+y, 3, matrix.Color333(0, 0, 0));
	//Nose
	matrix.drawCircle(x+4, 5+y, 0, matrix.Color333(0, 0, 0));
	//Right eye
	matrix.drawCircle(x+3, 4+y, 0, matrix.Color333(0, 0, 0));
	//Left eye
	matrix.drawCircle(x+5, 4+y, 0, matrix.Color333(0, 0, 0));
}

void clr_game_mole(int x){
	if (x==0){
		clr_smallmole(0, 0);
	} else if (x ==1){
		clr_smallmole(12, 0);
	} else if (x==2){
		clr_smallmole(23, 0);
	} else if (x==3){
		clr_smallmole(0, 8);
	} else if (x==4){
		clr_smallmole(23, 8);
	}
}

void game_mole(int x){
	if (x==0){
		draw_smallmole(0, 0);
	} else if (x ==1){
		draw_smallmole(12, 0);
	} else if (x==2){
		draw_smallmole(23, 0);
	} else if (x==3){
		draw_smallmole(0, 8);
	} else if (x==4){
		draw_smallmole(23, 8);
	}
}

int checkSingleHit(int mole){
	if (mole==0){
		if ((0<x) && (x<=7) && (0<y) && (y<=7)){
			return 1;
		} else {
			return 0;
		}
	} else if (mole ==1){
		if ((12<x) && (x<=19) && (0<y) && (y<=7)){
			return 1;
		} else {
			return 0;
		}
	} else if (mole==2){
		if ((23<x) && (x<=30) && (0<y) && (y<=7)){
			return 1;
		} else {
			return 0;
		}
	} else if (mole==3){
		if ((0<x) && (x<=7) && (8<y) && (y<=15)){
			return 1;
		} else {
			return 0;
		}
	} else if (mole==4){
		if ((23<x) && (x<=30) && (8<y) && (y<=15)){
			return 1;
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}

void cursor(int x, int y){
	matrix.drawPixel(x, y, matrix.Color333(0, 255, 0));
}

void clearCursor(int x, int y){
	matrix.drawPixel(x, y, matrix.Color333(0, 0, 0));
}

void update_cursor(void){
	    if (snes.pressed(snes.read(), snes.SNES_BUTTON_LEFT_ARROW)){
	    	clearCursor(x,y);
            x=x-1;
            matrix_delay(100);
        } else if (snes.pressed(snes.read(), snes.SNES_BUTTON_RIGHT_ARROW)){
            clearCursor(x,y);
            x=x+1;
            matrix_delay(100);
        } else if (snes.pressed(snes.read(), snes.SNES_BUTTON_UP_ARROW)){
	    	clearCursor(x,y);
            y=y-1;
            matrix_delay(100);
        } else if (snes.pressed(snes.read(), snes.SNES_BUTTON_DOWN_ARROW)){
	    	clearCursor(x,y);
            y=y+1;
            matrix_delay(100);
        }
        cursor(x, y);
        matrix_delay(100);

}


void game_init(void){

	game_state = GAME_INIT;
	game_run();
}

void game_run(void){
	game_end = 0;
	// main game implemented here
	while(!game_end){
		switch(game_state){
			case GAME_INIT:
				game_state = GAME_START;
				break;
			case GAME_START:
				game_update_beta();
				break;
			case GAME_END:
				while (1){
					matrix.setCursor(1, 9);   // next line
		        	matrix.setTextColor(matrix.Color333(0,7,7));
		        	matrix.putc('*');
		        	matrix.setTextColor(matrix.Color333(0,4,7));
		        	matrix.putc('W');
		        	matrix.setTextColor(matrix.Color333(0,0,7));
		        	matrix.putc('I');
		        	matrix.setTextColor(matrix.Color333(4,0,7));
		        	matrix.putc('N');
		        	matrix.setTextColor(matrix.Color333(7,0,4));
		        	matrix.putc('*');
		        	matrix_delay(100);
	        	}
				break;
			default:
				break;
		}
	}
}


int check_equal(int a, int b){
	if (a==b){
		return 1;
	} else {
		return 0;
	}
}

void generateMoles (void) {
	int pos1 = rand() % 5;
	int pos2 = rand() % 5;
	int pos3 = rand() % 5;
	if (check_equal(pos1, pos2)){
		if (check_equal(pos1, pos3)){
			moleArray[pos1] = true;
		} else {
			moleArray[pos1] = true;
			moleArray[pos3] = true;
		}
	} else if (check_equal(pos2, pos3)){
			moleArray[pos1] = true;
			moleArray[pos2] = true;
	} else if (check_equal(pos3, pos1)){
			moleArray[pos1] = true;
			moleArray[pos2] = true;
	} else {
			moleArray[pos1] = true;
			moleArray[pos2] = true;
			moleArray[pos3] = true;
	}
}

void clearMoleArray(void){
	moleArray[0] = false;
	moleArray[1] = false;
	moleArray[2] = false;
	moleArray[3] = false;
	moleArray[4] = false;
}

int checkNotEmptyArray(void){
	return (moleArray[0] || moleArray[1] || moleArray[2] || moleArray[3] || moleArray[4]);
}


void game_update_beta(void) {
	draw_score(score);
	clearMoleArray();
	generateMoles();
	matrix_delay(100);
	for (int i = 0; i < 5; ++i) {
		if (moleArray[i]){
			game_mole(i);
		}
	}
	int time = 0;
	while ((time < 15) && checkNotEmptyArray()){
		update_cursor();
		if (snes.pressed(snes.read(), snes.SNES_BUTTON_A)){
			for (int i = 0; i < 5; ++i) {
				if (moleArray[i]){
					if (checkSingleHit(i)){
						moleArray[i] = false;
						clr_game_mole(i);
						clr_draw_score(score);
						score++;
						draw_score(score);
						matrix_delay(1000);
					}
				}
			}
		}
		for (int i = 0; i < 5; ++i) {
			if (moleArray[i]){
				game_mole(i);
			}
		}
		draw_score(score);
		matrix_delay(1000);
		time++;
	}
	clearMoleArray();
	for (int i = 0; i < 5; ++i) {
		clr_game_mole(i);
	}
	if (score == 9){
		matrix.fillScreen(matrix.Color333(0,0,0));
		matrix_delay(10);
		game_state = GAME_END;
	}
		
	
}


int main() {
	game_init();
}
