/*										   							  
                        **************************
***************************** C HEADER FILE *********************************
                        **************************	
** 	project 	: 			   			   ** 
**	filename 	:						   **
** 	version 	: 						   **
** 	date 		: 						   **
** 									   **
*****************************************************************************
**    									   **
** 	Copyright (c)  		   					   **
** 	All rights reserved.    	  		                   **
**    									   **
*****************************************************************************
VERSION HISTORY:
Version 	: 	
Date 		: 	
Revised by 	: 	
Description : 	
*/
#ifndef _TPL_INCLUDED
#define _TPL_INCLUDED
/****************************************************************************/
/** 									   **/
/** 				MODULES USED				   **/
/** 						    		   	   **/
/****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
/****************************************************************************/
/**  									   **/
/** 				DEFINITIONS AND MACROS 			   **/
/** 									   **/
/****************************************************************************/
#define row 10
#define col 10
/****************************************************************************/
/** 									   **/
/** 				TYPEDEFS AND STRUCTURES		       	   **/
/** 									   **/
/****************************************************************************/
 /**** C type extensions ****/
typedef unsigned char 		bool;
typedef unsigned char 		uint8;
typedef char 				int8;
typedef unsigned int 		uint16;
typedef int 				int16;
typedef unsigned long 		uint32;
typedef long 				int32;
typedef float 				float32;
typedef double 				float64;
/**** Struct 			****/
struct Player
{
	char 			name[20];
	unsigned int 	win;
	unsigned int 	draw;
	unsigned int 	lose;
	float 			rating;	
};
typedef struct	Player player;
extern 			player p1;
extern struct 	Player *pt;
extern struct 	Player *new_player;
/****************************************************************************/
/** 									   **/
/** 			EXPORTED VARIABLES				   **/
/** 									   **/
/****************************************************************************/
extern int8 	stt;
extern int8 	count;
extern int8 	a[row][col];
extern uint8 	pl1;
extern uint8 	pl2;
extern uint8 	add1;
extern uint8 	add2;
extern uint16 	person;
extern uint16 	old_person;
#ifndef _TPL_C_SRC
#endif
/****************************************************************************/
/**    									   **/
/** 			EXPORTED FUNCTIONS 				   **/ 
/** 									   **/
/****************************************************************************/
void 	update	(struct Player *p,int a,int b,struct Player *pl,unsigned char i1,unsigned char i2);
void 	input_data(struct Player *p,struct Player *player1,int *win);
void 	check	(char x);
void 	play	(char *stt);
void 	start	(struct Player *p,struct Player *pl,unsigned char pl1,unsigned char pl2,unsigned char add1,unsigned char add2);
void 	compare	(struct Player *p1, struct Player *p, char *name);
void 	info	(struct Player *new_player, int *win);
int 	check_win();
int 	check_draw();
void 	display();
void 	player_info();
#endif
/****************************************************************************/
/** 									   **/
/** 			EOF	               	   			   **/
/**    									   **/
/****************************************************************************/
