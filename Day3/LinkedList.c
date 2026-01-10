#include <stdio.h>
#include <stdlib.h> // malloc(), free()

typedef struct node
{
  struct node *nowAdd;
  int data;
  struct node *nextAdd;
} node;

int inputData();
void insertData(node *head);
void deleteData(int *top, int arr[]);
void print(int *top, int arr[]);

int main(void)
{
  node *head = (node *)malloc(sizeof *head);
  head->nextAdd = NULL;

  int roop = 1;
  while (roop)
  {
    int result = inputData();
    if (result == 1) insertData(head);
    // else if (result == 2)
    //   deleteData(&top, arr);
    // else if (result == 3)
    //   print(&top, arr);
    else if (result == 4)
    {
      printf("프로그램 종료");
      roop = 0;
    }
  }
  return 0;
}

int inputData()
{
  printf("----- STACK ----- \n");
  printf("1.입력\t2.삭제\t3.확인\t4.종료\n");
  printf("메뉴선택: ");

  int input;
  scanf("%d", &input);


  return input;
}

void insertData(node *head)
{
    int saveNum;
    printf("저장할데이터 : ");
    scanf("%d", &saveNum);

    node *newNode = malloc(sizeof *newNode);
    newNode->nowAdd = newNode;
    newNode->data = saveNum;
    newNode->nextAdd = NULL;

    node *temp = head;
    while (temp->nextAdd != NULL && temp->nextAdd->data < saveNum) {
        temp = temp->nextAdd;
    }
    newNode->nextAdd = temp->nextAdd;
    temp->nextAdd = newNode;
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