/*
                        **************************
***************************** C HEADER FILE *********************************
                        **************************
**  project     :                                                          **
**  filename    :                                                          **
**  version     :                                                          **
**  date        :                                                          **
**                                                                         **
*****************************************************************************
**                                                                         **
**  Copyright (c)                                                          **
**  All rights reserved.                                                   **
**                                                                         **
*****************************************************************************
VERSION HISTORY:
Version     :
Date        :
Revised by  :
Description :
*/
#ifndef _FILE_MANAGER_
#define _FILE_MANAGER_
/*****************************************************************************
***                                                                        ***
***                         MODULES USED                                   ***
***                                                                        ***
*****************************************************************************/
#include "../Play/lib/lib.h"
/*****************************************************************************
***                                                                        ***
***                         DEFINITIONS AND MACROS                         ***
***                                                                        ***
*****************************************************************************/
/*****************************************************************************
***                                                                        ***
***                         TYPEDEFS AND STRUCTURES                        ***
***                                                                        ***
*****************************************************************************/
/*****************************************************************************
***                                                                        ***
***                        EXPORTED VARIABLES                              ***
***                                                                        ***
*****************************************************************************/
#ifndef _FILE_MANAGER_SRC_
#endif
/*****************************************************************************
***                                                                        ***
***                        EXPORTED FUNCTIONS                              ***
***                                                                        ***
*****************************************************************************/
void    writeData(struct Player *p,struct Player *pl);
void    getInfo(struct Player **p,struct Player *player,uint8 *win,\
            uint8 *data[],uint8 *pp);
#endif
/*****************************************************************************
***                                                                        ***
***                        EOF                                             ***
***                                                                        ***
*****************************************************************************/
