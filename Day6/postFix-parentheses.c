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

  printf("수식 입력: "); // (A+B)*C -> AB+C*
  scanf("%s", input);

  for (int i = 0; input[i] != '\0'; i++)
  {
    char inputData = input[i];
    // 1) 여는 괄호 '(' 처리
    if (inputData == '(')
    {
      stack[++stackTop] = inputData;
      continue;
    }

    // 2) 닫는 괄호 ')' 처리
    if (inputData == ')')
    {
      while (stackTop != -1 && stack[stackTop] != '(')
      {
        result[resultTop++] = stack[stackTop--];
      }
      // 남아있는 '(' 제거
      if (stackTop != -1 && stack[stackTop] == '(')
        stackTop--;
      continue;
    }

    int checkedData = checkOperand(inputData);

    if (checkedData == 3) // 피연산자
    {
      result[resultTop++] = inputData;
    }
    else // 연산자
    {
      // '(' 는 우선순위 비교에서 경계 역할: '(' 위로는 pop하지 않음
      while (stackTop != -1 &&
            stack[stackTop] != '(' &&
            checkOperand(stack[stackTop]) >= checkedData)
      {
        result[resultTop++] = stack[stackTop--];
      }
      stack[++stackTop] = inputData;
    }
  }

  // 남은 연산자 pop (괄호는 버림)
  while (stackTop != -1)
  {
    if (stack[stackTop] != '(')
      result[resultTop++] = stack[stackTop];
    stackTop--;
  }

  result[resultTop] = '\0';
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