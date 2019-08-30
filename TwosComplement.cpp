#include "TwosComplement.h"
#include <stdio.h>
#include <iostream>

using namespace std;
TwosComplement::TwosComplement()
{
  char a, b; //�������� ����, �����ϴ� �͵� �Ϲ� �����̶� ���� �Ȱ���, ǥ������ �Ѿ�� ������(overflow)
  a = -128;
  printf("a ");
  printBinary(a);
  b = 1;
  printf("b ");
  printBinary(b);
  a = a - b;
  printf("a - b ");
  printBinary(a);

  char c, d; //�������� ���ϴ� �͵� �Ϲ� �����̶� ���� �Ȱ���
  c = -3;
  printf("c ");
  printBinary(c);
  d = -2;
  printf("d ");
  printBinary(d);
  c = c * d;
  printf("c * d ");
  printBinary(c);

  char e, f; //�������� ���ؼ� �����÷� ���� ��� ������ �Ȱ���
  e = -128;
  printf("e ");
  printBinary(e);
  f = -127;
  printf("f ");
  printBinary(f);
  e = e * f;
  printf("e * f ");
  printBinary(e);

  char g, h; // /, %������ ��ȣ, ���ڵ��� �����ϴ� ��
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