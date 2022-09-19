구조체 : 하나 이상의 변수를 묶어 그룹화하는 사용자 정의 자료형

구조체 정의

#include <stdio.h>
struct group // 구조체 정의
{
int a;
double b;
};
int main(void)
{
struct group g1; // 구조체 변수 g1 선언
g1.a=10; // 구조체 변수로 멤버 변수 접근
g1.b=1.1234; // 구조체 변수로 멤버 변수 접근

printf("g1.a의 값: %d \n", g1.a);
printf("g1.b의 값: %lf \n", g1.b);
return 0;
}


- scanf 활용하기

#include <stdio.h>
struct group // 구조체 정의
{
int a;
double b;
};
int main(void)
{
struct group g1; // 구조체 변수 g1 선언
scanf("%d %lf", &g1.a, &g1.b); // 데이터 입력
printf("g1.a의 값: %d \n", g1.a);
printf("g1.b의 값: %lf \n", g1.b);
return 0;}

구조체 변수를 사용하는 법
- g1.a;
- g1 = 구조체 변수 : 멤버 변수에 접근하게 해주는 구조체 변수의 이름을 지정
- . = 접근 연산자 : 구조체 변수로 멤버 변수에 접근하는 연산자 지정
- a = 멤버 변수 : 접근하려는 멤버 변수의 이름을 지정

- 구조체 변수의 초기화
#include <stdio.h>
struct point
{
int x;
int y;
};
int main(void)
{
struct point p1={10, 20}; // 구조체 변수의 초기화
printf("%d %d \n", p1.x, p1.y);
return 0;
}

#include <stdio.h>
struct point
{
int x;
int y;
};
int main(void)
{
struct point p1={10, 20};
struct point p2={30, 40};
struct point p3={0, 0};
p3.x = p2.x - p1.x;
p3.y = p2.y - p1.y;
printf("%d %d \n", p3.x , p3.y);
return 0;
}

# 구조체 변수의 초기화
- 중괄호를 이용한 구조체 변수의 초기화 시 주의사항
  - 구조체 변수의 선언과 구조체 변수의 초기화를 따로 하면 에러가 발생
  - 배열 선언과 동시에 초기화를 해야한다!

  - struct point p1;
  - p1 = {10,20};
  - 이렇게 작성 시 error가 발생한다.

  그런데 중괄호로 초기화하지 않을 땐 선언과 초기화를 동시에 하지 않아도 된다.
  struct point p1;
  p1.x=10;
  p1.y=20;
  - 이건 정상 코드

  # 구조체 변수의 복사
  - 일반 변수의 복사와 같이 구조체 변수 간 복사 가능

  int a=3;
  int b=4;
  b=a;//변수의 복사
  
  - 이처럼 구조체도 복사가 가능하다
  struct point p1={10,20};
  struct point p2={0,0};
  p2 = p1 // 구조체 변수의 복사

#include <stdio.h>
struct point//구조체 이름을 위에선 group으로 여기선 point로 지정
{
int x;
int y;
};
int main(void)
{
struct point p1={10, 20};
struct point p2={0, 0};
p2=p1; // 구조체 변수 p2에 p1을 복사
printf("%d %d \n", p1.x, p1.y);
printf("%d %d \n", p2.x, p2.y);
return 0;
}


- 구조체 간 복사는 가능
- 구조체 간 연산은 불가능
  - p1+p2는 불가능
  - p3.x = p2.x - p1.x;
  - p3.y = p2.y - p1.y;
  - 는 가능!


-----------------------------------------------
# 중첩 구조체
- 구조체 내에 구조체가 포함
  - 구조체 변수를 멤버변수로 사용하는 것
  - 예시 코드를 살펴보자

#include <stdio.h>
struct score
{ double math, english, total; };
struct student
{
  int no;
  struct score s ;
};
int main(void)
{
struct student stu;
stu.no=20101323;
stu.s.math=90;
stu.s.english=80;
stu.s.total=stu.s.math+stu.s.english;
//이렇게 멤버변수간 산술연산은 가능하나, 구조체 간 산술연산은 불가능하다. 
printf("학번: %d \n", stu.no);
printf("총점: %lf \n", stu.s.total);
return 0;
}

--------------------------------------------------------
/*
잠깐 샛길 새자!
16진수에서, 12ff58다음에 4바이트 더해주려면 9 -> a -> b -> c
따라서 그 다음 메모리 주소는 12ff5c가 된다. 
그럼 또 여기서 4바이트 더해주면 12ff60이 된다. 
*/
--------------------------------------------------------

# 중첩 구조체의 초기화

#include <stdio.h>
struct score
{double math, english, total;};
struct student
{ int no;
  struct score s;};
int main(void)
{
struct student stu={20101323, {90, 80, 0}};
// 중괄호로 초기화땐, 선언과 동시에 초기화를 진행해야 한다. 
// struct student stu={20101323, 90, 80, 0};
stu.s.total=stu.s.math+stu.s.english;
printf("학번: %d \n", stu.no);
printf("총점: %lf \n", stu.s.total);
return 0;
}

# typedef를 이용한 구조체의 재정의
- 사용방법
typedef int mytype
1. typedef : 자료형의 재정의를 알리는 키워드
2. int : 기존 자료형
3. mytype : 새이름

#include <stdio.h>
typedef struct score
{
double math;
double english;
double average;
} SCORE; 
// 구조체 정의와 동시에 typedef 선언
// 원래는 score였는데 SCORE로 재정의 하는 것.
// 그래서 아래에서 SCORE s라고 하는 것. 
struct student
{
int no;
SCORE s; // struct socre s;
};
// 이건 구조체 정의와 개별적으로 typedef 선언
typedef struct student STUDENT ;

int main(void)
{
STUDENT stu={20101323, {90, 80, 0}};
stu.s. average=(stu.s.math+stu.s.english)/2;
printf("학번: %d \n", stu.no);
printf("평균점수: %lf \n", stu.s.average);
return 0;
}

# 구조체 재정의에는 두가지 방법이 있다.
1) 구조체 정의와 동시에 typedef 선언
2) 구조체 정의와 개별적으로 typedef 선언


# 구조체와 배열
1. 멤버 변수로 배열 사용하기

#include <stdio.h>
struct student
{
char no[10]; // 학번 (멤버변수에 배열 사용)
char name[20]; // 이름 (멤버변수에 배열 사용)
double math, english, total;
};
int main(void)
{
struct student stu1={"20101323", "Park", 80, 80, 0}; // 학생 1의 정보
struct student stu2={"20101324", "Kim", 95, 85, 0}; // 학생 2의 정보
struct student stu3={"20101325", "Lee", 100, 90, 0}; // 학생 3의 정보

stu1.total=stu1.math+stu1.english;
printf("학번: %s, 이름: %s \n", stu1.no, stu1.name);
printf("총점: %lf \n", stu1.total);
printf("\n");
stu2.total=stu2.math+stu2.english;
printf("학번: %s, 이름: %s \n", stu2.no, stu2.name);
printf("총점: %lf \n", stu2.total);
printf("\n");
stu3.total=stu3.math+stu3.english;
printf("학번: %s, 이름: %s \n", stu3.no, stu3.name);
printf("총점: %lf \n", stu3.total);
return 0;
}


- 구조체 변수로 배열 사용하기
#include <stdio.h>
struct student
{char no[10];//여긴 멤버 변수로 배열 사용하는 곳
char name[20];//여긴 멤버 변수로 배열 사용하는 곳
double math, english,total;};

int main(void)
{
int i=0;
struct student stu[3]={
//구조체 변수로 배열 사용하는 곳
//구조체 변수가 3개?
{"20101323", "Park", 80, 80, 0},
{"20101324", "Kim", 95, 85, 0},
{"20101325", "Lee", 100, 90, 0}
};

for(i=0; i<3; i++)
{
stu[i].total=stu[i].math+stu[i].english;
printf("학번: %s, 이름: %s \n", stu[i].no, stu[i].name);
printf("총점: %lf \n", stu[i].total);
printf("\n");
}
return 0;
}

### 멤버 변수로 배열을 사용할 때 주의사항
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
stu.no="20101323"; // 에러
stu.name="Park"; // 에러
printf("학번: %s, 이름: %s \n", stu.no, stu.name);
return 0;
}

??왜 error??
- stu.no = 배열의 시작 주소임
- stu.no = "102321312"
  - 이건 배열의 시작 주소에 문자열을 입력한 것과 동일
  - 따라서 error가 발생!

error 해결?
첫 번째 솔루션 : strcpy()함수 사용
두 번째 솔루션 : 멤버 변수로 포인터 선언

첫 번째 솔루션 : 
#include <stdio.h>
#include <string.h> //strcpy 불러오기
struct student
{
char no[10]; // 멤버 변수로 배열 선언
char name[20]; // 멤버 변수로 배열 선언
};
int main(void)
{
int i=0;
struct student stu;
strcpy (stu.no, "20101323");
strcpy (stu.name, "Park");
printf("학번: %s, 이름: %s \n", stu.no, stu.name);
return 0;
}

두 번째 솔루션 :
#include <stdio.h>
struct student
{
char* no; // 멤버 변수로 포인터 선언
char* name; // 멤버 변수로 포인터 선언
};
int main(void)
{
int i=0;
struct student stu;
stu.no = "12312";
stu.name = "1232";

printf("학번: %s, 이름: %s \n", stu.no, stu.name);
return 0;
}

- 구조체와 포인터부터 하면 됨