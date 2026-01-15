#include <stdio.h>

#define SIZE 20

int checkOperand(char inputdata);

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
    int checkedData = checkOperand(inputData);

    if (checkedData == 3) // 피연산자 배열에 저장
    {
      result[resultTop++] = inputData;
    }    
    else // 연산자 처리
    {
      while (stackTop != -1 && checkOperand(stack[stackTop]) >= checkedData) // 스택이 비어있지 않고, 2>=1이면
      {
        result[resultTop++] = stack[stackTop--];
      }
      stack[++stackTop] = inputData;
    }
  }

  while (stackTop != -1) // 연산자 처리
  {
    result[resultTop++] = stack[stackTop--];
  }

  result[resultTop] = '\0'; // 널 종료 문자 추가
  printf("postFix 출력: %s\n", result);
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