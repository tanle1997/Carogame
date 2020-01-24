// Library
#include "file_manager.h"
// Struct
player p1;
struct Player* pt;
struct Player* newPlayerPtr;
// Variables
uint8  m_Stt   = 0;
uint8  m_Count = 0;
uint8  m_Pl1   = 0;
uint8  m_Pl2   = 0;
uint8  m_Add1;
uint8  m_Add2;
uint16 m_totalPerson;
uint16 m_oldPerson;
uint8* m_Data[row];
// main
int main()
{   // khai bao cac bien va cap bo nho
  uint8  i;
  int    selectedOption;
  uint8* point = NULL;
  uint8* win;
  /* Khoi tao gia tri */
  m_Stt          = 0;
  m_Count        = 0;
  pt             = (struct Player*)calloc(20, sizeof(struct Player));
  win            = (uint8*)calloc(1, sizeof(uint8));
  point          = (uint8*)calloc(100, sizeof(uint8));
  *win           = 0;
  selectedOption = '\0';
  newPlayerPtr   = (struct Player*)calloc(2, sizeof(struct Player));
  for(i = 0; i < row; i++)
  {
    m_Data[i] = (uint8 *)calloc(col, sizeof(uint8));
    if(NULL == m_Data[i])
    {
      printf("Not enough memory!\n");

      return 0;
    }
  }
  // kiem tra da cap bo nho thanh cong hay chua
  if( (NULL ==pt) || (NULL == newPlayerPtr) || (NULL == point))
  {
    printf("Not enough memory!\n");

    return 0;
  }
  checkTotalPerson();  // Load so luong nguoi choi cu co trong file
  do
  {
    eraseArr(&point); // xoa mang du lieu choi
    /* goi ham lay thong tin va bat dau choi */
    getInfo(&pt, newPlayerPtr, win, m_Data, point);
    fflush(stdin); // xoa bo dem stdin va kiem tra ky tu tiep theo
    printf("Tiep tuc<1>\tKet thuc<2>\tReplay<3>\n");
    selectedOption = getchar();
    if('3' == selectedOption)
    {
      replayGames(point, newPlayerPtr, m_Data, win);
      break;
    }
    if('2' == selectedOption)
    {
      infoSamePoint(newPlayerPtr, win);
      break;
    }
  }
  while('1' == selectedOption);
  printHistory(pt);
  free(newPlayerPtr);    // free memory
  free(win);
  free(point);
  free(pt);
  for(i = 0; i < row; i++)
  {
    free(m_Data[i]);
  }

  return 0;
}
