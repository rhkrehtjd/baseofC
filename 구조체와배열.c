# 멤버 변수로 배열을 사용할 때 주의 사항

#include <stdio.h> 
struct student
{
  char no[10]; // 멤버 변수로 배열 선언
  char name[20]; // 멤버 변수로 배열 선언
};
int main(void)
{
int i=0;
struct student stu;
stu.no="20101323"; //에러
stu.name="Park";//에러

printf("학번: %s, 이름: %s \n", stu.no, stu.name); return 0;
}

왜 에러??
- 배열의 시작 주소에 문자열을 입력한 꼴!
- 그렇다면 어떻게 수정해야 할까??
  - #include <string.h>
  - strcpy를 이용한다.


#include <stdio.h> 
#include <string.h>
struct student
{
  char no[10]; // 멤버 변수로 배열 선언
  char name[20]; // 멤버 변수로 배열 선언
};
int main(void)
{
int i=0;
struct student stu;

strcpy(stu.no,"20101323");
strcpy(stu.name,"parlk");

printf("학번: %s, 이름: %s \n", stu.no, stu.name); return 0;
}

- 혹은 어떻게 해결?

#include <stdio.h> 

struct student
{ 
  char* no // 멤버 변수로 포인터 선언
  char* name // 멤버 변수로 포인터 선언
};
int main(void)
{
int i=0;
char* no; char* name;

struct student stu;
stu.no = "20101323";
stu.name = "Park";
printf("학번: %s, 이름: %s \n", stu.no, stu.name);
return 0; }

## 구조체와 포인터
- 멤버 변수로 포인터 사용하기

#include <stdio.h>
struct point
{
  int* y; // 1차원 포인터 멤버변수
  int* x; // 1차원 포인터 멤버변수
};

int main(void)
{
  int num1=4;
  int num2=5;
  
  struct point p1; 
  p1.x=&num1;
  p1.y=&num2;

  printf("%d %d \n", num1, num2); 
  printf("%d %d \n", *p1.x, *p1.y); 
  return 0;
}
- .연산자가 *연산자보다 우선순위가 높다. 

#include<stdio.h> 
struct point
{ 
  int* x; // 1차원 포인터 멤버 변수
  int** y; // 2차원 포인터 멤버 변수
};
int main(void)
{
  int num1 = 3; 
  struct point p1;
  p1.x = &num1; 
  p1.y = &p1.x;
printf("%d %d %d \n", num1, *p1.x, **p1.y); 
return 0;
}


#include<stdio.h>
struct point
{
  int x;
  int y; };

int main(void)
{
  struct point p1={20,30};
  printf("구조체 변수 p1의 주소: %x \n", &p1); 
  printf("멤버 변수 p1.x의 주소: %x \n", &p1.x);
  
  return 0; }

  - &p1.x == &p1


## 구조체 변수로 포인터 사용하기
#include<stdio.h>
struct student
{
  char no[10];
  char name[20]; 
  double total;
};
int main(void)
{
  struct student stu = {"20101323", "Park", 160};
  struct student* p=NULL; // 1차원 구조체 포인터 변수 선언
 
  p = &stu; // 1차원 구조체 포인터 변수에 stu 주소 저장
  printf("%s %s %lf \n",stu.no, stu.name, stu.total);
  printf("%s %s %lf \n",(*p).no, (*p).name, (*p).total); 
  printf("%s %s %lf \n",p->no, p->name, p->total);
return 0; }

즉, 
(*p).no == p ->no 


# 자기 참조 구조체와 외부 참조 구조체

#include<stdio.h>
struct point {
int x; // x좌표
int y; // y좌표 };
struct student { char name[20];
struct point* link;
};
int main(void)
{
}
return 0;
C언어 기초
69/94
struct student stu1 = {"Kim", NULL}; struct student stu2 = {"Lee", NULL}; struct point p1 = {30, 40};
struct point p2 = {60, 80};
stu1.link = &p1; stu2.link = &p2;
printf("%s %d %d \n", stu1.name, stu1.link->x, stu1.link->y);
printf("%s %d %d \n", stu2.name, stu2.link->x, stu2.link->y);

#include<stdio.h>
struct point {
int x; // x좌표
int y; // y좌표 
};
struct student { 
  char name[20];
  struct point* link; // 외부 참조 구조체
};
int main(void)
{
struct student stu1 = {"Kim", NULL}; 
struct student stu2 = {"Lee", NULL}; 
struct point p1 = {30, 40};
struct point p2 = {60, 80};

stu1.link = &p1; 
stu2.link = &p2;
printf("%s %d %d \n", stu1.name, stu1.link->x, stu1.link->y);
printf("%s %d %d \n", stu2.name, stu2.link->x, stu2.link->y);
return 0;
}

## 구조체와 함수
- 구조체를 함수의 인자로 전달하기
  - 값에 의한 호출과 주소에 의한 호출
- 구조체를 함수의 반환형으로 전달하기
  - 값 반환과 주소 반환