/*
  			****************************
******************************* C SOURCE FILE ********************************
** 			****************************			    **
** 									    **
** project 	: Caro Games						    **
** filename 	: file_manager.c					    **
** version 	: 1.1 							    **
** date 	: July 10, 2019						    **
**    									    **
******************************************************************************
** 									    **
** Copyright (c) 2019				 			    **
** All rights reserved. 						    **
** 									    **
******************************************************************************
VERSION HISTORY:
----------------
Version 	: 1.1
Date 		:
Revised by 	:
Description 	: Original version.
*/
/******************************************************************************
***                                                                         ***
*** 				MODULES USED 				    ***
*** 									    ***
******************************************************************************/
#include "file_manager.h"
/******************************************************************************
*** 									    ***
*** 				DEFINITIONS AND MACROS 			    ***
*** 									    ***
******************************************************************************/
/******************************************************************************
*** 									    ***
*** 				TYPEDEFS AND STRUCTURES 		    ***
***    									    ***
******************************************************************************/
/******************************************************************************
*** 									    ***
***    				PROTOTYPES OF LOCAL FUNCTIONS 		    ***
*** 									    ***
******************************************************************************/
/******************************************************************************
*** 									    ***
*** 				EXPORTED VARIABLES 			    ***
***    									    ***
******************************************************************************/
/******************************************************************************
***    									    ***
*** 				GLOBAL VARIABLES 			    ***
*** 									    ***
******************************************************************************/
/******************************************************************************
*** 									    ***
*** 				EXPORTED FUNCTIONS 			    ***
***    									    ***
*******************************************************************************/
void writeData(struct Player *p,struct Player *pl)
{
	FILE *fp;
	if(p==NULL || pl==NULL)
	{
		return;
	}
    	if(m_Pl1==1)
	{
		(p+m_Add1)->win		=	pl->win;
		(p+m_Add1)->draw	=	pl->draw;
		(p+m_Add1)->lose	=	pl->lose;
		(p+m_Add1)->rating 	=	(float)pl->win/(pl->win+pl->draw+pl->lose);
	}
    	if(m_Pl2==1)
	{
		(p+m_Add2)->win		=	(pl+1)->win;
		(p+m_Add2)->draw	=	(pl+1)->draw;
		(p+m_Add2)->lose	=	(pl+1)->lose;
		(p+m_Add2)->rating 	=	(float)(pl+1)->win/((pl+1)->win+(pl+1)->draw+(pl+1)->lose);
	}
    	if(m_Pl1==0 && m_Pl2==0)
	{
		strcpy((p+m_oldPerson)->name,pl->name);
		(p+m_oldPerson)->win	=	pl->win;
		(p+m_oldPerson)->draw	=	pl->draw;
		(p+m_oldPerson)->lose	=	pl->lose;
		(p+m_oldPerson)->rating =	(float)pl->win/(pl->win+pl->draw+pl->lose);

		strcpy((p+m_oldPerson+1)->name,(pl+1)->name);
		(p+m_oldPerson+1)->win		=	(pl+1)->win;
		(p+m_oldPerson+1)->draw		=	(pl+1)->draw;
		(p+m_oldPerson+1)->lose		=	(pl+1)->lose;
		(p+m_oldPerson+1)->rating	=	(float)(pl+1)->win/((pl+1)->win+(pl+1)->draw+(pl+1)->lose);
	}
	else
	{
		if(m_Pl1==0 && m_Pl2==1)
		{
		    strcpy((p+m_oldPerson)->name,pl->name);
		    (p+m_oldPerson)->win	=	pl->win;
		    (p+m_oldPerson)->draw	=	pl->draw;
		    (p+m_oldPerson)->lose	=	pl->lose;
		    (p+m_oldPerson)->rating 	=	(float)pl->win/(pl->win+pl->draw+pl->lose);
		}
		else if(m_Pl1==1 && m_Pl2==0)
			{
			    strcpy((p+m_oldPerson)->name,(pl+1)->name);
			    (p+m_oldPerson)->win	=	(pl+1)->win;
			    (p+m_oldPerson)->draw	=	(pl+1)->draw;
			    (p+m_oldPerson)->lose	=	(pl+1)->lose;
			    (p+m_oldPerson)->rating 	=	(float)(pl+1)->win/((pl+1)->win+(pl+1)->draw+(pl+1)->lose);
			}
	}
	fp=fopen("info.ini","wb");
	if(fp==NULL)
	{
		printf("Can not open file!!\n");
		return;
	}
	else
	{
        	fwrite(p,sizeof(struct Player),m_oldPerson+m_totalPerson,fp);
	}
	fclose(fp);
}
void getInfo(struct Player **p,struct Player *player,uint8 *win,uint8 *data[],uint8 *pp)
{
	FILE *f;
	uint8 	i=0;
    	m_Pl1	=0; m_Pl2=0; m_Stt=0;    m_Count=0;
	eraseData(data); //xoa mang du lieu
	f=fopen("info.ini","rb+");
	if(p==NULL || player==NULL)
		return;
	if(f==NULL)
	{
		printf("No data!\n");
		m_oldPerson	=0;
		m_totalPerson	=0;
	}
	checkTotalPerson();	// Lay so nguoi choi hien tai trong file ini
	// nhap ten hai nguoi choi
	printf("Player 1 name: ");
	gets(player->name);
	fflush(stdin);
	printf("Player 2 name: ");
	gets((player+1)->name);
	fflush(stdin);
	// doc du lieu nguoi choi cu
	fread(*p,sizeof(struct Player),m_oldPerson,f);
	for(i=0;i<m_oldPerson;i++)
	{
		if(strcmp((*p+i)->name,player->name)==0)
		{
			printf("%s la nguoi choi cu!\n",player->name);
			printf("Thang %d tran, hoa %d tran, thua %d tran, ti le %.3f\n",(*p+i)->win,(*p+i)->draw,(*p+i)->lose,(double)(*p+i)->rating);
			player->win	=	(*p+i)->win;
			player->draw	=	(*p+i)->draw;
			player->lose	=	(*p+i)->lose;
			player->rating	=	(*p+i)->rating;
			m_Pl1=1;	// flag
			m_Add1=i; //vi tri nguoi choi cu
		}
		if(strcmp((*p+i)->name,(player+1)->name)==0)
		{
			printf("%s la nguoi choi cu!\n",(player+1)->name);
            		printf("Thang %d tran, hoa %d tran, thua %d tran, ti le %.3f\n",(*p+i)->win,(*p+i)->draw,(*p+i)->lose,(double)(*p+i)->rating);
            		m_Pl2=1;	//flag
			(player+1)->win		=	(*p+i)->win;
			(player+1)->draw	=	(*p+i)->draw;
			(player+1)->lose	=	(*p+i)->lose;
			(player+1)->rating	=	(*p+i)->rating;
            		m_Add2=i;	//vi tri nguoi choi cu
		}
	}
	fclose(f);
	system("pause");
	inputData(p,player,win,data,pp);
	writeData(*p,player);
}
/******************************************************************************
***    									    ***
*** 				LOCAL FUNCTIONS 			    ***
*** 									    ***
******************************************************************************/
/******************************************************************************
*** 									    ***
***                             EOF   					    ***
*** 									    ***
******************************************************************************/
