//*****************************************
//		Random Generator for GameBoy. 
// Programmed by jduranmaster a.k.a. Ryoga
//*****************************************
#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>
#include <rand.h>
#include <gb/console.h>
#include <gb/drawing.h>

#include "pc18966_2.h"

unsigned int r,seed,key;

void clscr();
void main_loop();
void print_title();
void print_marquee();
void print_solid_marquee();
void print_message_INTRO();
void print_message_usage();
void print_messageAtXY(int x, int y, char *c);
void plot_intro_image(unsigned char *tile_data, unsigned char *map_data);

void main(){
	
	plot_intro_image(pc18966_2_tile_data, pc18966_2_map_data);
	
	print_marquee();
	print_title();
	print_message_INTRO();
	waitpad(J_START);
	
	clscr();
	print_solid_marquee();
	main_loop();
}

void main_loop(){
	
	seed=0;
	key=0;
	r=0;
	
	while(1){
		print_messageAtXY(1,2, "Press A Button !");
		if(joypad() == J_A){
  			while(joypad() == J_A){seed++; if(seed>=255)seed=1;}
  			initrand(seed);
  			print_messageAtXY(1,4, " ");
  			gprintf("Seed = %u ",seed);
  			if(!0){
   				r=rand();
   				print_messageAtXY(1,5, " ");
   				gprintf("Rand = %u  ",r);
  			}
		}
		if(joypad() == J_B){
			// do nothing
		}
		if(joypad() == J_SELECT){
			clscr();
			print_solid_marquee();
		}
		if(joypad() == J_START){
			clscr();
			print_marquee();
			print_title();
			print_message_usage();
			waitpad(J_START);
	
			clscr();
			print_solid_marquee();
		}
		delay(35);
	}
}

void print_marquee(){
	gotoxy(0, 0);
	color(BLACK, WHITE, SOLID);
	box(156,140,2,2,M_NOFILL);
	box(154,138,4,4,M_NOFILL);
	box(152,136,6,6,M_NOFILL);
}

void print_solid_marquee(){
	gotoxy(0, 0);
	color(BLACK, WHITE, SOLID);
	box(156,140,2,2,M_NOFILL);
	box(155,139,3,3,M_NOFILL);
	box(154,138,4,4,M_NOFILL);
	box(153,137,5,5,M_NOFILL);
	box(152,136,6,6,M_NOFILL);
}

void plot_intro_image(unsigned char *tile_data, unsigned char *map_data){
	set_bkg_data(0, 0, tile_data);
	set_bkg_tiles(0, 0, 20, 18, map_data);
	SHOW_BKG;
	DISPLAY_ON;
	delay(5000);
	clscr();
}

void print_messageAtXY(int x, int y, char *c){
	gotogxy(x,y);
	gprintf(c);
}

void print_title(){
	print_messageAtXY(3,1,"Rand Generator");
}

void print_message_usage(){
	print_messageAtXY(1,3,"Controls:");
	print_messageAtXY(1,4,"");
	print_messageAtXY(1,5,"A - Gen. Number");
	print_messageAtXY(1,7,"SELECT - Erase SCR");
	print_messageAtXY(1,8,"START - HOW TO...");
	print_messageAtXY(4,11,"PRESS START!");
	print_messageAtXY(8,14,"2014");
	print_messageAtXY(4,15,"Programmed by");
	print_messageAtXY(8,16,"Ryoga");
}

void print_message_INTRO(){
	print_messageAtXY(1,3,"This is a homebrew");
	print_messageAtXY(1,4,"software for the");
	print_messageAtXY(1,5,"Game Boy console.");
	print_messageAtXY(1,6," ");
	print_messageAtXY(1,7,"Controls:");
	print_messageAtXY(2,8,"A - Gen. Number");
	print_messageAtXY(4,11,"PRESS START!");
	print_messageAtXY(8,14,"2014");
	print_messageAtXY(4,15,"Programmed by");
	print_messageAtXY(8,16,"Ryoga");
}

void clscr(){
	int x, y;
  	for(y = 0; y < 20; y++){
    	for(x = 0; x < 30; x++){
      		gotoxy(x, y);
      		gprintf(" ");
		}
	}
	gotoxy(0,0);
}