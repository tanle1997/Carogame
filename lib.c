/*
                            **********************
******************************* C SOURCE FILE ********************************
** 							********************** 							**
** 																			**
** project : Caro Games														**
** filename : lib.c															**
** version : 1.1 															**
** date : July 10, 2019														**
**    																		**
******************************************************************************
** 																			**
** Copyright (c) 2019				 										**
** All rights reserved. 													**
** 																			**
******************************************************************************
VERSION HISTORY:
----------------
Version : 1.1
Date :
Revised by :
Description : Original version.
                                                                             */
#define _LIB_C
/******************************************************************************
*** 																		***
*** 						MODULES USED 									***
*** 																		***
******************************************************************************/
#include "../Play/lib/lib.h"
/******************************************************************************
*** 																		***
*** 						DEFINITIONS AND MACROS 							***
*** 																		***
******************************************************************************/
/******************************************************************************
*** 																		***
*** 						TYPEDEFS AND STRUCTURES 						***
***    																		***
******************************************************************************/ 
/******************************************************************************
*** 																		***
***    						PROTOTYPES OF LOCAL FUNCTIONS 					***
*** 																		***
******************************************************************************/
/******************************************************************************
*** 																		***
*** 						EXPORTED VARIABLES 								***
***    																		***
******************************************************************************/
/******************************************************************************
***    																		***
*** 						GLOBAL VARIABLES 								***
*** 																		***
******************************************************************************/
/******************************************************************************
*** 																		***
*** 						EXPORTED FUNCTIONS 								***
***    																		***
******************************************************************************/
/* Xoa mang du lieu choi
 * Tham so:--------------------------------------------------------------------
 * arr[] la mang con tro tuong duong voi mang hai chieu
 * pointer dung de luu du lieu ban co trong luc hai nguoi dang choi
 * va hien thi ra man hinh vi tri choi tuong ung, xoa du lieu khi bat dau choi lai */
void eraseData(uint8 *arr[])
{
    uint8 i;
    for(i=0;i<row;i++)
    {
        memset(arr[i],0,sizeof(uint8)*col);
    }
}
void eraseArr(uint8 **pointer)
{
    memset(*pointer,0,sizeof(uint8)*row*col);
}
/* Hien thi ten hai nguoi choi hien tai
 * Tham so *player la struct pointer luu hai nguoi choi hien tai */
void playerInfo(struct Player *player)
{
    printf("%s <%c> - %s <%c> \n",player->name,PLAYER1,(player+1)->name,PLAYER2);
}
/* Hien thi cac nuoc co ma hai nguoi choi dang choi
 * x: vi tri trong mang m_Data chua du lieu vi tri danh de in ra man hinh
*/
void checkEmpty(uint8 x)
{
    if(x == 0x00)
    {
        printf("   ");
    }
    else
    {
        printf(" %c ",x);
    }
}
/* Kiem tra nguoi choi cu */
void    checkOldplayer(struct Player **p,struct Player *newplayer)
{
    unsigned char i;
    for(i=0;i<m_oldPerson;i++)
    {
        if(strcmp((*p+i)->name,newplayer->name)==0)
        {
            printf("%s la nguoi choi cu!\n",newplayer->name);
            printf("Thang %d tran, hoa %d tran, thua %d tran, ti le %.3f\n",(*p+i)->win,(*p+i)->draw,(*p+i)->lose,(double)(*p+i)->rating);
            newplayer->win		=	(*p+i)->win;
            newplayer->draw	=	(*p+i)->draw;
            newplayer->lose	=	(*p+i)->lose;
            newplayer->rating	=	(*p+i)->rating;
            m_Pl1=1;	// flag
            m_Add1=i; //vi tri nguoi choi cu
        }
        if(strcmp((*p+i)->name,(newplayer+1)->name)==0)
        {
            printf("%s la nguoi choi cu!\n",(newplayer+1)->name);
            printf("Thang %d tran, hoa %d tran, thua %d tran, ti le %.3f\n",(*p+i)->win,(*p+i)->draw,(*p+i)->lose,(double)(*p+i)->rating);
            m_Pl2=1;	//flag
            (newplayer+1)->win		=	(*p+i)->win;
            (newplayer+1)->draw	=	(*p+i)->draw;
            (newplayer+1)->lose	=	(*p+i)->lose;
            (newplayer+1)->rating	=	(*p+i)->rating;
            m_Add2=i;	//vi tri nguoi choi cu
        }
    }
}
/* Nhap nuoc co cua hai nguoi choi va luu vao mang m_Data de hien thi, luu lai vi tri hai nguoi choi tung danh
 * de goi ham replayGames.
 * Cac tham so:----------------------------------------------------------------------------------------------
 * stt: Thu tu nguoi choi mot/hai
 * rowcheck,colcheck : vi tri ma hai nguoi choi chon vao ban co, yeu cau nhap lai neu trung vi tri da danh
 * dataarr[]: mang luu vi tri hai nguoi choi de in ra man hinh
 * pointcheck: 1 Byte luu giu lieu vi tri hang, cot trong lan danh cua moi nguoi choi
*/
void playGames(uint8 *rowcheck,uint8 *colcheck,uint8 *dataarr[],uint8 *pointcheck)
{
    if(m_Stt==0)
    {
        do
        {   // kiem tra chi so mang hop le
            printf("Player 1: ");
            scanf("%d %d",rowcheck,colcheck);
            fflush(stdin); // xoa bo nho dem
        }
        while( (*rowcheck>=row ) || (*colcheck>=col ) || *(dataarr[*rowcheck]+*colcheck)!=0);
        if(*(dataarr[*rowcheck]+*colcheck)==0)
        {
         *(dataarr[*rowcheck]+*colcheck)	=	PLAYER1;
         *(pointcheck+m_Count) = (uint8)(((*rowcheck)<<4) | *colcheck);
         m_Count++;
        }
    }
    else
    {
        do
        {
            printf("Player 2: ");
            scanf("%d %d",rowcheck,colcheck);
            fflush(stdin);
        }
        while( (*rowcheck>=row) || (*colcheck>=col) || *(dataarr[*rowcheck]+*colcheck)!=0);
        if(*(dataarr[*rowcheck]+*colcheck)==0)
        {
         *(dataarr[*rowcheck]+*colcheck)	=	PLAYER2;
         *(pointcheck+m_Count) = (uint8)(((*rowcheck)<<4) | *colcheck);
         m_Count++;
        }
    }
    m_Stt	=	!m_Stt;
}
/* Hien thi ban co */
void displayBoard(struct Player *player,uint8 *a[])
{
    playerInfo(player);
    uint8 i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            checkEmpty(*(a[i]+j));
            printf("|");
        }
        printf("\n");
        for(j=0;j<13;j++)
        {
            printf("---");
        }
        printf("\n");
    }
}
/* Kiem tra dieu kien thang/thua cua tung nguoi, neu di het ban co ma khong ai thang se tra ket qua ve hoa
 * a[]: mang luu vi tri danh
 * r,c: du lieu hang/cot vua danh
 * ham tra ve 1 neu nguoi choi mot thang, tra ve -1 neu nguoi choi hai thang
 */
int checkWin(uint8 *a[],unsigned short int r,unsigned short int c)
{
    unsigned short int i=r,j=c,Count1=0,Count2=0,Count3=0,Count4=0;
    if(j<(col-1))	// Kiem tra hang
    while(*(a[i]+j)==*(a[i]+j+1)    &&	*(a[i]+j)!=0)
    {
        Count1++;
        j++;
        if(j==(col-1))
            break;
    }
    i=r;	j=c;
    while(*(a[i]+j)==*(a[i]+j-1)	&&	*(a[i]+j)!=0)
    {
        Count1++;
        j--;
        if(j==0)
            break;
    }
    i=r;	j=c;	Count2=0; 	// Kiem tra cot
    if(i<(row-1))
    {
        while(*(a[i]+j)==*(a[i+1]+j) &&	*(a[i]+j)!=0)
        {
            Count2++;
            i++;
            if(i==(row-1))
                break;
        }
    }
    i=r;	j=c;
    if(i>0)
    {
        while(*(a[i]+j)==*(a[i-1]+j) &&	*(a[i]+j)!=0)
        {
            Count2++;
            i--;
            if(i==0)
                break;
        }
    }
    i=r;	j=c;	Count3=0; 	//	Kiem tra hang cheo
    if(i<(row-1) && j<(col-1))
    {
        while(*(a[i]+j)==*(a[i+1]+j+1)	&&	*(a[i]+j)!=0)
        {
            Count3++;
            i++;
            j++;
            if(i==(row-1)||j==(col-1))
                break;
        }
    }
    i=r;	j=c;
    if(i>0 && j>0)
    {
        while(*(a[i]+j)==*(a[i-1]+j-1)	&&	*(a[i]+j)!=0)
        {
            Count3++;
            i--;
            j--;
            if(i==0||j==0)
                break;
        }
    }
    i=r;	j=c;	Count4=0;
    if(i<(row-1) && j<(col-1)&&i>0&&j>0)
    {
        while(*(a[i]+j)==*(a[i-1]+j+1)	&&	*(a[i]+j)!=0)
        {
            Count4++;
            i--;
            j++;
            if(i==0||j==(col-1))
                break;
        }
    }
    i=r;	j=c;
    if(i>0 && j>0 && i<(row-1) && j<(col-1))
    {
        while(*(a[i]+j)==*(a[i+1]+j-1)	&&	*(a[i]+j)!=0)
        {
            Count4++;
            i++;
            j--;
            if(i==(row-1)||j==0)
                break;
        }
    }
    if(Count1>=4||Count2>=4||Count3>=4||Count4>=4)
    {
        if(*(a[r]+c)==PLAYER1)
            return 1;
        else
            return -1;
    }
    return 0;
}
/* Kiem tra dieu kien hoa cua hai nguoi khi di het ban co ma khong co nguoi thang cuoc */
int checkDraw(void)
{
    if(m_Count==(row*col))
    {
        m_Count=0;
        return 1;
    }
    else
        return 0;
}
/* Nhap du lieu hai nguoi choi hien tai vao con tro player1, cap phat them vung nho neu co nguoi choi moi
 * va thuc hien luu ket qua khi choi xong tro lai con tro player1
 * Cac tham so:-----------------------------------------------------------------------------------------
 * **p: con tro struct Player luu tru toan bo du lieu nguoi choi co trong file ini va hien tai
 * *player1: con tro struct luu tru du lieu hai nguoi choi hien tai
 * *win: trang thai thang, thua. win=1(nguoi choi 1 thang), win=2(nguoi choi 2 thang) */
void inputData(struct Player **p,struct Player *player1,uint8 *win,uint8 *arr[],uint8 *pointcheck)
{   // du lieu hang, cot vua duoc danh
    unsigned char *rowcheck;
    unsigned char *colcheck;
    rowcheck=(unsigned char*)calloc(1,sizeof(unsigned char));
    colcheck=(unsigned char*)calloc(1,sizeof(unsigned char));
    m_totalPerson=0;
    if(m_Pl1 ==	0)     // *player luu gia struct hai nguoi choi da duoc cap nhat
    {
        m_totalPerson++;
        player1->win		=	0;
        player1->draw		=	0;
        player1->lose		=	0;
        player1->rating		=	0.0;
    }
    if(m_Pl2 ==	0)
    {
        m_totalPerson++;
        (player1+1)->win	=	0;
        (player1+1)->draw	=	0;
        (player1+1)->lose	=	0;
        (player1+1)->rating	=	0.0;
    }
    realloc(*p,sizeof(struct Player)*(m_oldPerson+m_totalPerson));
    while(1)
    {
        system("cls");
        displayBoard(player1,arr);
        if(checkWin(arr,*rowcheck,*colcheck)==1)
        {
            printf("%s win!\n",player1->name);
            player1->win		+=	1;
            (player1+1)->lose	+=	1;
            *win				=	1;
            break;
        }
        if(checkWin(arr,*rowcheck,*colcheck)==-1)
        {
            printf("%s win!\n",(player1+1)->name);
            (player1+1)->win	+=	1;
            player1->lose		+=	1;
            *win				=	2;
            break;
        }
        if(checkDraw()==1)
        {
            printf("Draw!\n");
            player1->draw		+=	1;
            (player1+1)->draw	+=	1;
            *win				=	0;
            break;
        }
        playGames(rowcheck,colcheck,m_Data,pointcheck);
    }
}
/* Hien thi thong tin nhung nguoi choi co ti le thang gan nhau */
void infoSamePoint(struct Player *newplayer,uint8 *win)
{
    FILE 	*fp;
    float32	*f=NULL;
    struct 	Player	*p;
    uint8 	i=0,j=0;
    float64	min; // Gia tri nho nhat cua hieu so ti le cua nguoi thang voi cac nguoi choi con lai
    uint8 	add = 0;
    if(newplayer==NULL || win==NULL)
    {
        return;
    }
    else
    {
        f	=	(float32 *)calloc((m_oldPerson+m_totalPerson),sizeof(float32));
        p	=	(struct Player *)calloc((m_totalPerson+m_oldPerson),sizeof(struct Player));
        if(f==NULL || p==NULL)
        {
            return;
        }
        fp	=	fopen("info.ini","rb");
        if(fp==NULL)
        {
            printf("File can not open!\n");
            return;
        }
        fread(p,sizeof(struct Player),(m_oldPerson+m_totalPerson),fp); //luu thong tin nguoi choi vao *p
        fclose(fp);
        for(i=0; i<(m_oldPerson+m_totalPerson); i++)
        {
            if(*win == 1)
            {
                if(strcmp(newplayer->name,(p+i)->name)==0) // so sanh ten nguoi choi thang
                    add	=	i;
            }
            else if(*win == 2)
            {
                if(strcmp((newplayer+1)->name,(p+i)->name)==0)
                    add	=	i;
            }
        }
        min = 2.0;
        for(i=0; i<(m_oldPerson+m_totalPerson); i++)
        {
            float64 temp;
            temp	=	fabs((float64)((p+add)->rating) - (float64)((p+i)->rating));
            if(i	==	add)
                continue;
            else if(temp <= min)
                min	 = fabs((float64)((p+add)->rating) - (float64)((p+i)->rating));
        }
        printf("Nhung nguoi choi gan trinh do nhat la:\n");
        for(i=0; i<(m_oldPerson+m_totalPerson); i++)
        {
            if(	(i != add) && (min == (fabs((float64)((p+add)->rating) - (float64)((p+i)->rating)))	))
            {
                printf("%20s\t",(p+i)->name);
                printf("thang %4d\t hoa %4d\t thua %4d\t voi ti le thang %4.3f\n",(p+i)->win,(p+i)->draw,(p+i)->lose,(double)(p+i)->rating);
                *(f+j)=(p+i)->rating; //Mang du lieu nhung nguoi cung ti le thang
                j++;
            }
        }
        free(f);
        free(p);
    }
}
/* Tinh so luong nguoi choi co trong file ini */
void checkTotalPerson(void)
{
    FILE *f;
    int16 	num;
    f 	= 	fopen("info.ini","rb");
    if(f==NULL)
    {
        printf("File does not exist!!\n");
        m_totalPerson	=	0;
        m_oldPerson     =	0;
        return;
    }
    else
    {
        fseek(f, 0, SEEK_END);
        num		=	ftell(f);
        m_oldPerson	=	(uint8)num/(sizeof(struct Player));
    }
    fclose(f);
}
/* Hien thi toan bo thong tin cua nguoi choi co trong file ini */
void printHistory(struct Player *p)
{
    uint8 i;
    printf("History!\n");
    for(i=0;i<(m_oldPerson+m_totalPerson);i++)
    {
        printf("%20s Win: %4d Draw: %4d Lose: %4d Rating: %4.3f\n",(p+i)->name,(p+i)->win,(p+i)->draw,(p+i)->lose,(double)(p+i)->rating);
    }
}
/* Ham replay lan choi gan nhat
 * *rp:luu du lieu vi tri nguoi choi tu lan dau tien toi khi ket thuc van choi
 * *player: du lieu hai nguoi choi hien tai
 * *a[]: mang luu vi tri danh cua hai nguoi choi */
void replayGames(uint8 *rp,struct Player *player,uint8 *a[],uint8 *win)
{
    uint8 c=0;
    if(rp==NULL)
        return;
    uint8 i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            *(a[i]+j)=0;
        }
    }
    while(m_Count--)
    {
        system("cls");
        if(c%2==0)
        {
            *(a[*(rp+c)>>4]+(*(rp+c)&0x0f))=PLAYER1;
        }
        else
        {
            *(a[*(rp+c)>>4]+(*(rp+c)&0x0f))=PLAYER2;
        }
        playerInfo(player);
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                checkEmpty(*(a[i]+j));
                printf("|");
            }
            printf("\n");
            for(j=0;j<13;j++)
            {
                printf("---");
            }
            printf("\n");
        }
        c++;
        Sleep(1500);
    }
    infoSamePoint(player,win);
    system("pause");
}
/******************************************************************************
***    																		***
*** 						LOCAL FUNCTIONS 								***
*** 																		***
******************************************************************************/
/******************************************************************************
*** 																		***
*** 							EOF   										***
*** 																		***
******************************************************************************/
