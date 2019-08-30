# DataStructureReview
# 자료구조 복습
## 모든 예시는 main.cpp에서 시작
1. example
  * example.cpp, example.h
  * main.cpp에서 Example class가 잘 생성되는지 테스트
  ```
#include "example.h"
void main()
{
  Example* ex = new Example();
  ex->print();
  (*ex).print();
}
  ```
2. 정수형 자료의 표현
  * TwosComplement.cpp, TwosComplement.h
  * 정수형 자료(char, int, long long등)이 음수일 때 어떻게 표현되는지, 사칙연산은 어떻게 하는지 확인
  * 음수의 경우 2의 보수로 나타냄
    *ex) char형에서 -7은 7의 모든 비트를 뒤집고 1을 더한값(0b00000111->0b11111000->0b11111001)
  * 결과값이 해당범위를 벗어날 때 벗어난 범위의 값은 사라짐(오버플로)
    * (-128) + (-1) = 127 (0b10000000 + 0b11111111 = 0b01111111)
  * +, -, * 연산은 음수에 대해서도 똑같이 적용되지만, /, % 는 부호비트 따로 숫자비트 따로 계산한다.
    * (-128) / (-3) = 42, (-128) % (-3) = -2
3. 실수형 자료의 표현
