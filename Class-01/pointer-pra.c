#include <stdio.h>

void push(int *top, int arr[]);
void pop(int *top, int arr[]);
void print(int *top, int arr[]);

int main(void)
{
  int top = 0;
  int arr[10] = {0};

  int roop = 1;
  printf("----- STACK ----- \n");

  while (roop)
  {
    printf("1.push\t2.pop\t3.확인\t4.종료\n");
    printf("메뉴선택: ");

    int input;
    scanf("%d", &input);

    if(input == 1) push(&top, arr);
    else if (input == 2) pop(&top, arr);
    else if (input == 3) print(&top, arr);
    else if (input == 4) {
      printf("프로그램 종료"); 
      roop = 0;
    }
  }
  return 0;
}

void push(int *top, int arr[])
{
  if(*top >= 10)
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

void pop(int *top, int arr[])
{
  if(top <= 0)
  {
    printf("꺼낼 데이터가 없습니다.\n\n");
    return;
  }
  (*top)--;
  printf("마지막 데이터를 스택에서 꺼냈습니다\n\n");
}

void print(int *top, int arr[])
{
  if(*top <= 0)
  {
    printf("스택이 비어 있습니다.\n\n");
    return;
  }

  printf("스택에는\n");
  for(int i = 0; i < *top; i++){
    printf("%d ", arr[i]);
  }
  printf("이 저장되어 있습니다\n\n");
}