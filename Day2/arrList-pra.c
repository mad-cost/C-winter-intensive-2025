#include <stdio.h>

void inputData(int *top, int arr[]);
void deleteData(int *top, int arr[]);
void print(int *top, int arr[]);

int main(void)
{
  int top = 0;
  int arr[10] = {0};

  int roop = 1;
  printf("----- STACK ----- \n");

  while (roop)
  {
    printf("1.입력\t2.삭제\t3.확인\t4.종료\n");
    printf("메뉴선택: ");

    int input;
    scanf("%d", &input);

    if (input == 1)
      inputData(&top, arr);
    else if (input == 2)
      deleteData(&top, arr);
    else if (input == 3)
      print(&top, arr);
    else if (input == 4)
    {
      printf("프로그램 종료");
      roop = 0;
    }
  }
  return 0;
}

void inputData(int *top, int arr[])
{
  if (*top >= 10)
  {
    printf("스택이 가득차 있습니다\n\n");
    return;
  }

  int saveNum;
  printf("저장할데이터 : ");
  scanf("%d", &saveNum);
  arr[*top] = saveNum;
  (*top)++;

  printf("\n");
}

void deleteData(int *top, int arr[])
{
  int deleteNum;
  printf("삭제 데이터 입력 : ");
  scanf("%d", &deleteNum);

  int idx = -1;
  for (int i = 0; i < *top; i++)
  {
    if (arr[i] == deleteNum)
    {
      idx = i;
      break;
    }
  }

  if (idx == -1)
  {
    printf("%d는 List에 존재하지 않습니다. \n\n", deleteNum);
    return;
  }

  for (int j = idx; j < (*top) - 1; j++)
  {
    arr[j] = arr[j + 1];
  }
  (*top)--;

  printf("삭제 완료\n\n");
}

void print(int *top, int arr[])
{
  if (*top <= 0)
  {
    printf("스택이 비어 있습니다.\n\n");
    return;
  }

  printf("스택에는\n");
  for (int i = 0; i < *top; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("이 저장되어 있습니다\n\n");
}