#include "TwosComplement.h"
#include <stdio.h>
#include <iostream>

using namespace std;
TwosComplement::TwosComplement()
{
  char a, b; //음수끼리 덧셈, 뺄셈하는 것도 일반 덧셈이랑 과정 똑같음, 표현범위 넘어서면 버려짐(overflow)
  a = -128;
  printf("a ");
  printBinary(a);
  b = 1;
  printf("b ");
  printBinary(b);
  a = a - b;
  printf("a - b ");
  printBinary(a);

  char c, d; //음수끼리 곱하는 것도 일반 곱셈이랑 과정 똑같음
  c = -3;
  printf("c ");
  printBinary(c);
  d = -2;
  printf("d ");
  printBinary(d);
  c = c * d;
  printf("c * d ");
  printBinary(c);

  char e, f; //음수끼리 곱해서 오버플로 나도 계산 과정은 똑같음
  e = -128;
  printf("e ");
  printBinary(e);
  f = -127;
  printf("f ");
  printBinary(f);
  e = e * f;
  printf("e * f ");
  printBinary(e);

  char g, h; // /, %연산은 부호, 숫자따로 연산하는 듯
  g = -128;
  printf("g ");
  printBinary(g);
  h = -3;
  printf("h ");
  printBinary(h);
  g = g / h;
  printf("g / h ");
  printBinary(g);

  g = -128;
  printf("g ");
  printBinary(g);
  h = -3;
  printf("h ");
  printBinary(h);
  g = g % h;
  printf("g %% h ");
  printBinary(g);
}

template <typename T>
void TwosComplement::printBinary(T number)
{
  if (sizeof(T) >= 8)
    printf(": %lld, 0b", number);
  else if (sizeof(T) >= 4)
    printf(": %d, 0b", number);
  else
    printf(": %d, 0b:", number);
  int bitSize = sizeof(T) * 8;
  unsigned long long tmp = 1ULL << (bitSize - 1);
  for (int i = 0; i < bitSize; i++)
  {
    if ((number & tmp) == tmp)
      printf("1");
    else
      printf("0");
    number = number << 1;
  }
  printf("\n");
}