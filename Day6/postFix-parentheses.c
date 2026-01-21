#include <stdio.h>

#define SIZE 20

int checkOperand(char inputdata);
int openParenthese(char inputData, char stack[], int *stackTop, int *parent);
int closeParenthese(char inputData, char result[], int *resultTop, char stack[], int *stackTop, int *parent);
int handleOperatorOrOperand(char inputData, char result[], int *resultTop, char stack[], int *stackTop);
void printResult(char result[], int *resultTop, char stack[], int *stackTop);

int main(void)
{
  char input[SIZE];
  char result[SIZE];
  char stack[SIZE];

  int resultTop = 0;
  int stackTop = -1;
  int parent = 0;

  printf("수식 입력: ");
  scanf("%s", input);

  for (int i = 0; input[i] != '\0'; i++)
  {
    char inputData = input[i];
    if (openParenthese(inputData, stack, &stackTop, &parent)) continue;
    
    int checkParent = closeParenthese(inputData, result, &resultTop, stack, &stackTop, &parent);
      if (checkParent == 2) continue;
      if (checkParent == -1)
      {
        printf("괄호검사: 불합격");
        return 1;
      }
    handleOperatorOrOperand(inputData, result, &resultTop, stack, &stackTop);
  }
  printResult(result, &resultTop, stack, &stackTop);
  return 0;
}

int checkOperand(char inputdata)
{
  if (inputdata == '+' || inputdata == '-')
    return 1;
  else if (inputdata == '*' || inputdata == '/')
    return 2;
  else
    return 3;
}

int openParenthese(char inputData, char stack[], int *stackTop, int *parent)
{
  if (inputData == '(')
  {
    stack[++(*stackTop)] = '(';
    (*parent++);
    return 2;
  }
  return 0;
}

int closeParenthese(char inputData, char result[], int *resultTop, char stack[], int *stackTop, int *parent)
{
  if (inputData != ')')
    return 0; // ')'가 아닌 경우 처리안함

  // ')'의 개수가 안 맞는 경우 return -1;
  (*parent)--;
  if (*parent == -1) return -1; // ex: )AB+C(

  // ')'가 맞는 경우
  while (*stackTop != -1 && stack[*stackTop] != '(')
    result[(*resultTop)++] = stack[(*stackTop)--];

  // 스택에 '('가 없다면 매칭 실패(불합격)
  if (*stackTop == -1)
    return -1; // 닫는 괄호가 더 많음

  (*stackTop)--;  // '(' 제거
  return 2;
}

int handleOperatorOrOperand(char inputData, char result[], int *resultTop, char stack[], int *stackTop)
{
  int checkedData = checkOperand(inputData);

  if (checkedData == 3)
  {
    result[(*resultTop)++] = inputData;
    return 2;
  }


  while (*stackTop != -1 &&
          stack[*stackTop] != '(' &&
          checkOperand(stack[*stackTop]) >= checkedData)
  {
    result[(*resultTop)++] = stack[(*stackTop)--];
  }
  stack[++(*stackTop)] = inputData;
  return 2; 
}

void printResult(char result[], int *resultTop, char stack[], int *stackTop)
{
  while (*stackTop != -1)
  {
    if (stack[*stackTop] != '(')
      result[(*resultTop)++] = stack[*stackTop];
    (*stackTop)--;
  }
  result[*resultTop] = '\0';
  printf("괄호 검사: 합격\n");
  printf("postFix 출력: %s\n", result);
}
