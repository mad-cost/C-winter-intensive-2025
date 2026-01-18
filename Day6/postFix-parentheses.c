#include <stdio.h>

#define SIZE 20

int checkOperand(char inputdata);
int openParenthese(char inputData, char stack[], int *stackTop);
int closeParenthese(char inputData, char result[], int *resultTop, char stack[], int *stackTop);
int handleOperatorOrOperand(char inputData, char result[], int *resultTop, char stack[],  int *stackTop);
void printResult(char result[], int *resultTop, char stack[], int *stackTop);

int main(void)
{
  char input[SIZE];
  char result[SIZE];
  char stack[SIZE];

  int resultTop = 0;
  int stackTop = -1;

  printf("수식 입력: ");
  scanf("%s", input);

  for (int i = 0; input[i] != '\0'; i++)
  {
    char inputData = input[i];
    if (openParenthese(inputData, stack, &stackTop)) continue;
    if (closeParenthese(inputData, result, &resultTop, stack, &stackTop)) continue;

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
    return 3; // 피연산자
}

int openParenthese(char inputData, char stack[], int *stackTop)
{
  if (inputData == '(')
  {
    stack[++(*stackTop)] = '(';
    return 2; // main에서 continue 하기 위해 (return 1은 에러를 표기하는 걸로 오해할까봐 2를 사용하였음)
  }
  return 0;
}

int closeParenthese(char inputData, char result[], int *resultTop, char stack[], int *stackTop)
{
  if (inputData == ')')
  {
    while (*stackTop != -1 && stack[*stackTop] != '(')
    {
      result[(*resultTop)++] = stack[(*stackTop)--];
    }

    // 남아있는 '(' 제거
    if (*stackTop != -1 && stack[*stackTop] == '(')
      (*stackTop)--;

    return 2; // 처리 완료(main에서 continue용)
  }
  return 0; // 처리 안 함
}

int handleOperatorOrOperand(char inputData, char result[], int *resultTop, char stack[],  int *stackTop)
{
  int checkedData = checkOperand(inputData);

  if (checkedData == 3) // 피연산자 처리
  {
    result[(*resultTop)++] = inputData;
    return 2; // 처리 완료
  }

  // 연산자 처리
  while (*stackTop != -1 &&
          stack[*stackTop] != '(' &&
          checkOperand(stack[*stackTop]) >= checkedData)
  {
    result[(*resultTop)++] = stack[(*stackTop)--];
  }
  stack[++(*stackTop)] = inputData;
  return 2; // 처리 완료
}


void printResult(char result[], int *resultTop, char stack[], int *stackTop)
{
  // 남은 연산자 출력 '(' 괄호는 버림
  while (*stackTop != -1)
  {
    if (stack[*stackTop] != '(')
      result[(*resultTop)++] = stack[*stackTop];
    (*stackTop)--;
  }
  result[*resultTop] = '\0';
  printf("postFix 출력: %s\n", result);
}
