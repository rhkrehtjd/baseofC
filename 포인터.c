//포인터란 무엇인가?
//컴퓨팅세계에서 택배아저씨와 같은 일을 하는 변수
//포인터 변수(포인터라고도 부름)
//-메모리의 주소를 저장하고 있다가 해당 주소로 데이터를 전달하는 일
//-메모리의 주소를 저장하고 있다가 해당 주소로 데이터를 참조하는 일

//포인터란
//주소를 저장하는 변수
//c언어의 장점 중에 하나가 바로 포인터이다. 

//포인터 변수의 선언
//int* p1=NULL; //int형 주소를 저장하는 포인터 변수
//char* p2=NULL; //char형 주소를 저장하는 포인터 변수
//double* p3=NULL; // double형 주소를 저장하는 포인터 변수

#include <stdio.h>
int main(void)
{
  //포인터 변수 선언
  char* cp=NULL;
  int* ip=NULL;

  printf("%x %x %x\n", &cp, cp, *&cp);
  printf("%x %x %x\n", &ip, ip, *&ip);

  printf("%d %d \n", sizeof(char*), sizeof(int*)); // 모든 포인터 변수는 4바이트이다. 
  printf("%d %d \n", sizeof(cp), sizeof(ip));

  return 0;
}
//포인터 변수는 4바이트라고 했는데...
//왜 8이 출력되지?

#include <stdio.h>
int main()
{
  char c= 'A';
  char* cp = NULL;
  
  cp=&c; // 주소 저장
  
  printf("%c %c %c \n", &c, c, *&c);
  printf("%x %x %x\n", &cp, cp, *&cp);

  printf("%c \n", c);// 직접 접근
  printf("%c \n", *cp);//간접 접근
  return 0;
}

// 같은 메모리 공간의 이름
// c == *&c == *cp

#include <stdio.h>
int main()
{
  int a=0, b=0, c=0;
  int* ip=NULL; // 포인터 변수 선언

  ip=&a; // 주소 저장
  *ip=10;
  printf("%d %d %d %d\n",a,b,c,*ip);

  ip=&b; // 주소 저장 변경
  *ip=20;
  printf("%d %d %d %d\n",a,b,c,*ip);
  
  ip=&a; // 주소 저장 변경
  *ip=30;
  printf("%d %d %d %d\n",a,b,c,*ip);
  
return 0;
}
//ip의 주소가 처음엔 NULL에서 a의 주소, b의 주소, c의 주소로 변경

#include <stdio.h>
int main()
{
  int num=10;
  int* ip=NULL; //포인터 변수 선언

  ip = &num;//num의 메모리 주소를 ip에 저장

  printf("%x %x %d\n", &*&ip, *&ip, **&ip);
  printf("%x %x %d\n", &ip, ip, *ip);

  return 0;
}
//*&는 서로 상쇄된다.

#include <stdio.h>
int main()
{
  int num1=10;
  int num2=0;
  int* ip=NULL;// 포인터 변수 선언
   
  ip=&num1; // 주소 저장 // 변수 num1의 메모리 주소를 ip라는 포인터에 할당

  num2 = *ip + num1;
  printf("%d %d %d\n", *ip, num1, num2);

  //ip자체는 주소임!
  return 0;


//잘못 사용된 포인터1
//포인터 변수에 주소를 저장하지 않은 경우
#include <stdio.h> 
int main(void)
{
int* ip=NULL; 
*ip=10000; 
return 0;
// 포인터에 주소를 할당하고 
// *ip=1000을 했어야 함
}

//잘못 사용된 포인터2
//포인터 변수에 이상한 주소 저장
#include <stdio.h> 
int main(void)
{
  int* ip=14592343;
  //이때 윗줄에서 포인터에 임의의 주소를 지정해서 error 발생
  *ip=1020
  return 0; }

//포인터 변수의 초기화 방법 2가지

//1번째
//포인터 변수의 선언과 초기화를 개별적으로 수행
#include <stdio.h>
int main(void)
{ int num=10;
int* ip=NULL;
ip=&num;//num이라는 변수의 주소를 &로 불러와서 ip라는 포인터변수에 저장
return 0;
}

//2번째
//포인터 변수의 선언과 초기화를 동시에 수행
#include <stdio.h> 
int main(void)
{ int num=10;
int* ip=&num;//포인터 변수의 선언과 초기화를 동시에 수행
return 0;
} 




//다차원 포인터 변수의 선언과 사용
//다차원 포인터 변수란?
//2차원 이상의 포인터 변수를 의미한다. 

//review : 1차원 포인터 변수의 역할 : 일반 변수의 주소를 저장

#include <stdio.h>
int main(void)
{
  int num=10;
  int* p1=NULL;
  p1 = &num;
  return 0;
}

//2차원 포인터 변수의 역할 : 1차원 포인터 변수의 주소를 저장?

#include <stdio.h>
int main(void)
{
  int num =10;
  int* p1=NULL;
  int** p2=NULL;

  p1=*num;
  p2=&p1;//1차원 포인터 변수의 주소를 저장중!
  return 0;
}

//THEN
//3차원 포인터 변수의 역할 : 2차원 포인터 변수의 주소를 저장
#include <stdio.h>
int main(void)
{
  int num=10;
  int* p1=NUll;
  int** p2=NUll;
  int*** p3=NUll;

  p1 = &num;
  p2 = &p1;
  p3 = &p2;//2차원 포인터 변수의 주소를 3차원 포인터 변수에 저장

  return 0;
}

#include <stdio.h>
int main()
{
  char c1 = 'A';
  char* cp = NULL;
  char** cpp=NULL;

  cp=&c1;
  cpp=&cp;

  printf("%c %x %x\n", c1, cp, cpp);
  printf("%c %x %x\n", &c1, &cp, &cpp);
  printf("%c %x %x\n", c1, *cp, **cpp);
}

#include <stdio.h> 
int main( )
{
int num1=10; 
int* ip=NULL; 
int** ipp=NULL;

ip=&num1; 
ipp=&ip;
printf("%d %x %x \n", num1, ip, ipp); 
printf("%x %x %x \n", &num1, &ip, &ipp); 
printf("%d %x %x \n", *&num1, *&ip, *&ipp);
printf("%d %d %d \n", num1, *ip, **ipp);
printf("%x %x %x \n", &num1, ip, *ipp);
return 0; }