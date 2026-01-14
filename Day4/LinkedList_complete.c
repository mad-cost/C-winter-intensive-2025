#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  struct node *nowAdd;
  int data;
  struct node *nextAdd;
} node;

int inputData();
void insertData(node *head);
void deleteData(node *head);
void printData(node *head);
void freeList(node *head);

int main(void)
{


  node *head = (node *)malloc(sizeof *head);
  head->nextAdd = NULL;

  int roop = 1;
  while (roop)
  {
    int result = inputData();
    if (result == 1) insertData(head);
    else if(result == 2) deleteData(head);
    else if(result == 3) printData(head);
    else if(result == 4){
      printf("프로그램 종료"); 
      roop = 0;
    } else{
      printf("1 ~ 4 사이의 숫자 입력 \n\n");
    }
  }

  freeList(head);
  return 0;
}

void insertData(node *head)
{
    int saveNum;
    printf("저장할 데이터 : ");
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

int inputData()
{
  printf("----- LinkedList ----- \n");
  printf("1.입력\t2.삭제\t3.확인\t4.종료\n");
  printf("메뉴선택: ");

  int input;
  scanf("%d", &input);

  return input;
}

void printData(node *head){
  if(head->nextAdd == NULL) {
    printf("head is NULL \n\n");
    return;
  }

  node *temp = head->nextAdd;
  while (temp != NULL)
  { 
    printf("(%p) %d (%p)", temp->nowAdd, temp->data, temp->nextAdd);
    if(temp->nextAdd != NULL){
      printf(" - ");
    }
    temp = temp -> nextAdd;
  }
  printf("\n\n");
}

void deleteData(node *head){
  if(head->nextAdd == NULL) {
    printf("head is NULL \n\n");
    return;
  }

  int deleteNum;
  printf("삭제할 데이터 : ");
  scanf("%d", &deleteNum);

  node *prev = head;
  node *temp = head -> nextAdd;

  if (temp==NULL)
  {
    printf("Number %d Not Found\n\n", deleteNum);
    return;
  }

    while (temp != NULL && temp->data != deleteNum)
  {
    prev = temp;
    temp = temp->nextAdd;
  }

  prev->nextAdd = temp->nextAdd;
  free(temp);
  printf("\n");
}

void freeList(node *head)
{
    node *temp = head->nextAdd;
    while (temp != NULL) {
        node *next = temp->nextAdd;
        free(temp);
        temp = next;
    }
    free(temp);
    free(head);
}