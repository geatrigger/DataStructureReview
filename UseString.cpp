#include "UseString.h"
#include <iostream>
#include <cstdio>
//#include <string>
#include <chrono>

using namespace std;
UseString::UseString()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	globalVariable = 0;
	char buffer[4096];
	memset(buffer, 0, sizeof(buffer));
	buffer[0] = '0'; // 출력용 문자
	chrono::system_clock::time_point start;
	chrono::system_clock::time_point end;
	chrono::duration<double> sec;
	cin >> globalVariable; //입력용, 출력시 주석처리
	start = chrono::system_clock::now();
	for (int i = 0; i < 1000; i++)
	{
		//1 1 1 1 1 ...을 입력으로 함
		//fread(buffer, sizeof(char), 2, stdin); //0.000071seconds
		//scanf("%d", &buffer[0]); //0.000676seconds
		//cin >> globalVariable; //0.002716seconds

		//fwrite(buffer, sizeof(char), 1, stdout); //0.024174seconds
		//printf("%c", buffer[0]); //0.023961seconds
		//cout << buffer[0]; //0.023974seconds
	}
	end = chrono::system_clock::now();
	sec = end - start;
	printf("\n%lfseconds\n", sec.count());
	//string cs('a'); char형으로 string만들기 불가
	/*
	string s("asdf"); //const char*
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	*/
}

void UseString::print()
{
	//printf("asdfsd");
}