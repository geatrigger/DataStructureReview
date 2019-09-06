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
	a += 1; // 유효숫자 표현가능범위 0b1.111~111((2^24 - 1)*2^(-23))을 넘어서면 범위 넘어선 값 버려짐
	printf("a ");
	printBinary(a);
	a += 1; // 계속 더해도 범위 넘어선 값 버려져서 같은 값이 됨, 1.00001은 더하면 값이 변함
	printf("a ");
	printBinary(a);

	a = pow(2.0f, 127.0f);
	printf("a ");
	printBinary(a);
	a = pow(2.0f, 127.0f);
	a *= 1.99999999; // 지수 표현가능범위 2^128 - 1을 넘어서면 무조건 0b01111111100000000000000000000000로 저장되고 inf출력함
	printf("a ");
	printBinary(a);

	a = pow(2.0f, -127.0f - 22.0f);
	printf("a ");
	printBinary(a);
	a = pow(2.0f, -127.0f - 22.0f);
	a /= 2; // 지수 표현가능범위 2^(-127-23)보다 같거나 작으면 무조건 0b00000000000000000000000000000000로 저장됨
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