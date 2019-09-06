#include "RealNumber.h"
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
RealNumber::RealNumber()
{
	float a;
	a = 1.0f;
	printf("a ");
	printBinary(a);
	a = 2.0f;
	printf("a ");
	printBinary(a);
	a = 0.5f;
	printf("a ");
	printBinary(a);
	a = 0.25f;
	printf("a ");
	printBinary(a);
	a = 0.4f;
	printf("a ");
	printBinary(a);
	a = 0.6f;
	printf("a ");
	printBinary(a);
	a = 0.7f;
	printf("a ");
	printBinary(a);

	a = pow(2.0f, 23.0f);
	a += 1;
	printf("a ");
	printBinary(a);
	a = pow(2.0f, 24.0f);
	a += 1; // ��ȿ���� ǥ�����ɹ��� 0b1.111~111((2^24 - 1)*2^(-23))�� �Ѿ�� ���� �Ѿ �� ������
	printf("a ");
	printBinary(a);
	a += 1; // ��� ���ص� ���� �Ѿ �� �������� ���� ���� ��, 1.00001�� ���ϸ� ���� ����
	printf("a ");
	printBinary(a);

	a = pow(2.0f, 127.0f);
	printf("a ");
	printBinary(a);
	a = pow(2.0f, 127.0f);
	a *= 1.99999999; // ���� ǥ�����ɹ��� 2^128 - 1�� �Ѿ�� ������ 0b01111111100000000000000000000000�� ����ǰ� inf�����
	printf("a ");
	printBinary(a);

	a = pow(2.0f, -127.0f - 22.0f);
	printf("a ");
	printBinary(a);
	a = pow(2.0f, -127.0f - 22.0f);
	a /= 2; // ���� ǥ�����ɹ��� 2^(-127-23)���� ���ų� ������ ������ 0b00000000000000000000000000000000�� �����
	printf("a ");
	printBinary(a);
}

template <typename T>
void RealNumber::printBinary(T number)
{
	printf(": %67.27f 0b", number);
	int bitSize = sizeof(T) * 8;
	unsigned long long numberLL = *(unsigned long long*)(&number);
	unsigned long long tmp = 1ULL << (bitSize - 1);
	for (int i = 0; i < bitSize; i++)
	{
		if ((numberLL & tmp) == tmp)
			printf("1");
		else
			printf("0");
		numberLL = numberLL << 1;
	}
	printf("\n");
}