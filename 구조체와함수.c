1. 구조체를 함수의 인자로 전달하기
  - 값에 의한 호출과 주소에 의한 호출
2. 구조체를 함수의 반환형으로 전달하기
  - 값 반환과 주소 반환

## 값에 의한 호출

#include<stdio.h>
struct point // 구조체 정의
{
int x;
int y; };

void function (struct point call); // 함수의 선언

int main(void){
struct point p = {10, 20}; 
function(p);
return 0;}

void function (struct point call) // 함수의 정의
{printf("%d %d \n", call.x, call.y);}
//p는 call에 복사됨

## 주소에 의한 호출
#include<stdio.h>
struct point
{
int x;
int y; };

void function (struct point* call); // 함수의 선언 

int main(void)
{
struct point p = {10, 20}; 
function(&p); // 주소에 의한 호출(call by reference)
return 0; }

void function (struct point* call) // 함수의 정의
{
printf("%d %d \n", call->x, call->y); 
printf("%d %d \n", (*call).x, (*call).y);}

- p의 주소가 포인터 변수 call에 저장

## 구조체의 값을 반환하는 함수

#include <stdio.h>
struct point
{ int x,y;};

struct point function(void); // 함수의 선언

int main(void){
  struct  point p;
  p=function();
  printf("%d %d \n", p.x, p.y);
  return 0;}

struct point(function(void)){
  struct point call = {10,20};
  return call;
}


## 공용체와 열거형
- 멤버 변수들 중 가장 큰 메모리 공간을 공유해서 사용
  - union 키워드 사용
  - 공용체 멤버 변수의 선언 : 구조체와 동일
  - 공용체 변수의 선언 : 구조체와 동일
  - 멤버 변수 접근 : 구조체와 동일

- 멤버 변수들 중 가장 큰 메모리 공간을 공유해서 사용?
  - 예를 들어 union에 int, char, double 변수를 사용했을 때
  - 메모리 공간이 가장 큰 double을 공유하는 것

#include<stdio.h>
union point
{
int x;
int y; }; // 공용체 정의

struct student
{
int a;
int b; }; // 구조체 정의

int main(void)
{ 
  printf("%d %d \n",sizeof(union point), sizeof(struct student) );
  return 0; }

#include <stdio.h>
union point{
  int x,y;
}; // 공용체 정의

int main(void){
  union point p;// 공용체 변수 선언
  p.x = 10;

  printf("%d %d \n", p.x, p.y);
  return 0;
}
- x만 선언해줬는데 y까지..10?
- 메모리 공간을 공유해서 그런가?

## 열거형 
- 변수가 갖는 값에 의미를 부여
- 프로그램의 가독성이 높아짐
- 컴파일러는 실제로 열거형 멤버들을 정수형 상수로 인식

정의 방법 : 
enum week {one, two, three, four, five, six};

#include<stdio.h>
enum week {ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN}; 
enum season {SPRING, SUMMER=2, FALL, WINTER};

int main(void)
{
  enum week p1, p2, p3; // 열거형 변수 p1, p2, p3 선언 
  enum season s1, s2, s3, s4; // 열거형 변수 s1, s2, s3, s4 선언

  p1 = ONE; p2 = TWO; p3 = THREE;
  
  printf("%d %d %d \n", ONE, TWO, THREE ); 
  printf("%d %d %d \n", p1, p2, p3 );

  s1 = SPRING; s2 = SUMMER; s3 = FALL;
  s4 = WINTER;

  printf("%d %d %d %d \n", SPRING, SUMMER, FALL, WINTER ); printf("%d %d %d %d \n", s1, s2, s3, s4 );
  return 0; }