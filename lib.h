/*
                        **************************
***************************** C HEADER FILE *********************************
                        **************************
** 	project 	: 											   			   **
**	filename 	:										   				   **
** 	version 	: 										   				   **
** 	date 		: 												   		   **
** 																		   **
*****************************************************************************
**    																	   **
** 	Copyright (c)  									   					   **
** 	All rights reserved. 					  		                       **
**    																	   **
*****************************************************************************
VERSION HISTORY:
Version 	:
Date 		:
Revised by 	:
Description :
*/
#ifndef _LIB_H
#define _LIB_H
/*****************************************************************************
*** 																	   ***
*** 						MODULES USED    							   ***
*** 																       ***
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <windows.h>
/*****************************************************************************
***  																	   ***
*** 						DEFINITIONS AND MACROS 						   ***
*** 																	   ***
*****************************************************************************/
#define PLAYER1 'X'
#define PLAYER2 'O'
#define row 10
#define col 10
/*****************************************************************************
*** 																	   ***
***                     	TYPEDEFS AND STRUCTURES 				       ***
*** 																	   ***
*****************************************************************************/
 /**** C type extensions ****/
typedef unsigned char   boolean;
typedef unsigned char 	uint8;
typedef char            int8;
typedef unsigned int    uint16;
typedef int             int16;
typedef unsigned long   uint32;
typedef long            int32;
typedef float           float32;
typedef double          float64;
/**** Struct 			****/
struct Player
{
    char 			    name[20];
    unsigned int 	win;
    unsigned int 	draw;
    unsigned int	lose;
    float 			  rating;
};
typedef struct	Player player;
extern 			    player p1;
extern struct 	Player *pt;
extern struct 	Player *newPlayer;
/*****************************************************************************
*** 																	   ***
***                         EXPORTED VARIABLES 							   ***
*** 																	   ***
*****************************************************************************/
extern uint8 	m_Stt;
extern uint8 	m_Count;
extern uint8 	*m_Data[row];
extern uint8 	m_Pl1;
extern uint8 	m_Pl2;
extern uint8 	m_Add1;
extern uint8 	m_Add2;
extern uint16 	m_totalPerson;
extern uint16 	m_oldPerson;
#ifndef _LIB_C
#endif
/*****************************************************************************
***    																	   ***
*** 						EXPORTED FUNCTIONS 							   ***
*** 																	   ***
*****************************************************************************/
void 	inputData(struct Player **p,struct Player *player1,uint8 *win,uint8 *arr[],uint8 *pointcheck);
void 	checkEmpty(uint8 x);
void    checkOldplayer(struct Player **p,struct Player *newplayer);
void 	playGames(uint8 *rowcheck,uint8 *colcheck,uint8 *dataarr[],uint8 *pointcheck);
int 	checkWin(uint8 *a[],unsigned short int r,unsigned short int c);
int 	checkDraw(void);
void 	displayBoard(struct Player *player,uint8 *a[]);
void 	playerInfo(struct Player *player);
void 	eraseData(uint8 *arr[]);
void 	eraseArr(uint8 **pointer);
void    infoSamePoint(struct Player *newplayer,uint8 *win);
void	checkTotalPerson(void);
void    printHistory(struct Player *p);
void	replayGames(uint8 *rp,struct Player *player,uint8 *a[],uint8 *win);
#endif
/*****************************************************************************
*** 																	   ***
*** 								EOF	                 	   			   ***
***    																	   ***
*****************************************************************************/
