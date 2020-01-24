/*
                            **********************
******************************* C SOURCE FILE ********************************
**                          **********************                          **
**                                                                          **
** project : Caro Games                                                     **
** filename : file_manager.c                                                **
** version : 1.1                                                            **
** date : July 10, 2019                                                     **
**                                                                          **
******************************************************************************
**                                                                          **
** Copyright (c) 2019                                                       **
** All rights reserved.                                                     **
**                                                                          **
******************************************************************************
VERSION HISTORY:
----------------
Version : 1.1
Date :
Revised by :
Description : Original version.                                             */
#define _FILE_MANAGER_SRC_
/******************************************************************************
***                                                                         ***
***                         MODULES USED                                    ***
***                                                                         ***
******************************************************************************/
#include "file_manager.h"
/******************************************************************************
***                                                                         ***
***                         DEFINITIONS AND MACROS                          ***
***                                                                         ***
******************************************************************************/
/******************************************************************************
***                                                                         ***
***                         TYPEDEFS AND STRUCTURES                         ***
***                                                                         ***
******************************************************************************/
/******************************************************************************
***                                                                         ***
***                         PROTOTYPES OF LOCAL FUNCTIONS                   ***
***                                                                         ***
******************************************************************************/
/******************************************************************************
***                                                                         ***
***                         EXPORTED VARIABLES                              ***
***                                                                         ***
******************************************************************************/
/******************************************************************************
***                                                                         ***
***                         GLOBAL VARIABLES                                ***
***                                                                         ***
******************************************************************************/
/******************************************************************************
***                                                                         ***
***                         EXPORTED FUNCTIONS                              ***
***                                                                         ***
*******************************************************************************/
/* Kiem tra du lieu nguoi choi cu/moi, sau do ghi du lieu tu mang nguoi choi
 *  hien tai sang mang luu toan bo nguoi choi, sau do thuc hien ghi vao file,
 * ket thuc chuong trinh */
void writeData(struct Player *p, struct Player *pl)
{
  FILE *fp;

  if((NULL == p) || (NULL == pl))
  {
    return;
  }
  if(1u == m_Pl1)    // neu nguoi choi 1 la nguoi choi cu
  {
    (p + m_Add1)->win    = pl->win;
    (p + m_Add1)->draw   = pl->draw;
    (p + m_Add1)->lose   = pl->lose;
    (p + m_Add1)->rating = (float)pl->win/(pl->win + pl->draw + pl->lose);
  }
  if(1u == m_Pl2)    // neu nguoi choi 2 la nguoi choi cu
  {
    (p + m_Add2)->win    = (pl + 1u)->win;
    (p + m_Add2)->draw   = (pl + 1u)->draw;
    (p + m_Add2)->lose   = (pl + 1u)->lose;
    (p + m_Add2)->rating = (float)(pl + 1u)->win/((pl + 1u)->win + \
      (pl + 1u)->draw + (pl + 1u)->lose);
  }
  if((0 == m_Pl1) && (0 == m_Pl2))    // neu hai nguoi choi la nguoi choi moi
  {
    strcpy((p + m_oldPerson)->name, pl->name);
    (p + m_oldPerson)->win    = pl->win;
    (p + m_oldPerson)->draw   = pl->draw;
    (p + m_oldPerson)->lose   = pl->lose;
    (p + m_oldPerson)->rating = (float)pl->win/(pl->win + pl->draw + \
      pl->lose);

    strcpy((p + m_oldPerson + 1u)->name, (pl+1)->name);
    (p + m_oldPerson + 1u)->win    = (pl + 1u)->win;
    (p + m_oldPerson + 1u)->draw   = (pl + 1u)->draw;
    (p + m_oldPerson + 1u)->lose   = (pl + 1u)->lose;
    (p + m_oldPerson + 1u)->rating = (float)(pl + 1u)->win/(\
      (pl + 1u)->win + (pl + 1u)->draw + (pl + 1u)->lose);
  }
  else
  {   // neu chi co mot nguoi choi moi
    if((0 == m_Pl1) && (0 == m_Pl2))
    {
      strcpy((p + m_oldPerson)->name, pl->name);
      (p + m_oldPerson)->win    = pl->win;
      (p + m_oldPerson)->draw   = pl->draw;
      (p + m_oldPerson)->lose   = pl->lose;
      (p + m_oldPerson)->rating = (float)pl->win/(pl->win + pl->draw + \
        pl->lose);
    }
    else if((1u == m_Pl1) && (0 == m_Pl2))
    {
      strcpy((p + m_oldPerson)->name, (pl + 1u)->name);
      (p + m_oldPerson)->win    = (pl + 1u)->win;
      (p + m_oldPerson)->draw   = (pl + 1u)->draw;
      (p + m_oldPerson)->lose   = (pl + 1u)->lose;
      (p + m_oldPerson)->rating = (float)(pl + 1u)->win/(\
        (pl + 1u)->win + (pl + 1)->draw + (pl + 1u)->lose);
    }
  }
  fp=fopen("info.ini", "wb");
  if(NULL == fp)
  {
    printf("Can not open file!!\n");

    return;
  }
  else
  {   // ghi du lieu vao file ini
    fwrite(p, sizeof(struct Player), m_oldPerson + m_totalPerson, fp);
  }
  fclose(fp);
}
/* Ham nhap ten va kiem tra nguoi choi cu, sau do tien hanh tai du lieu
 * nguoi choi cu vao vi tri tuong ung trong con tro struct Player vao du
 * lieu nguoi choi hien tai */
void getInfo(struct Player **p, struct Player *player, uint8 *win, \
  uint8 *data[], uint8 *pp)
{
  FILE *f;

  m_Pl1   = 0;
  m_Pl2   = 0;
  m_Stt   = 0;
  m_Count = 0;
  eraseData(data); //xoa mang du lieu
  f = fopen("info.ini", "rb+");
  if( (NULL == p) || (NULL == player) )
    return;
  if(NULL == f)
  {
    printf("No data!\n");
    m_oldPerson   = 0;
    m_totalPerson = 0;
  }
  checkTotalPerson(); // Lay so nguoi choi hien tai trong file ini
  // nhap ten hai nguoi choi
  printf("Player 1 name: ");
  gets(player->name);
  fflush(stdin);
  printf("Player 2 name: ");
  gets((player + 1u)->name);
  fflush(stdin);
  // doc du lieu nguoi choi cu
  fread(*p, sizeof(struct Player), m_oldPerson, f);
  checkOldplayer(p, player);
  fclose(f);
  system("pause");
  inputData(p, player, win, data, pp);
  writeData(*p, player);
}
/******************************************************************************
***                                                                         ***
***                             LOCAL FUNCTIONS                             ***
***                                                                         ***
******************************************************************************/
/******************************************************************************
***                                                                         ***
***                             EOF                                         ***
***                                                                         ***
******************************************************************************/
