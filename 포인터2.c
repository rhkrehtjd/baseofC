다차원 포인터 변수의 선언과 사용

review!!
연산자 *는 메모리의 주소 앞에서 사용된 경우, 메모리 공간에 저장된 값을
참조하는 연산자 역할을 한다
- 따라서 포인터(주소가 저장되어 있는 식별자?)앞에 *연산자를 붙여줄 경우 해당 포인터에 할당된 
값을 참조하게 된다. 

연산자 &는 해당 연산자의 메모리 주소를 가르쳐줌

#include <stdio.h>
int main()
{
  int num1=10; 
  int* ip1=NULL; 
  int** ip2=NULL; 
  int*** ip3=NULL;
  
  ip1=&num1; 
  ip2=&ip1;
  ip3=&ip2; 
  
  printf("%d %d %d %d \n", num1, *ip1, **ip2, ***ip3);
  printf("%d %d %d %d \n", &num1, ip1, *ip2, *ip3);
  printf("%x %x %x \n", &ip1, ip2, *ip3);
  printf("%x %x \n", &ip2, ip3);

  printf("%d %d \n", sizeof(int), sizeof(int*));
  printf("%d %d \n", sizeof(int**), sizeof(int***));

  printf("%d %d \n", sizeof(num1), sizeof(ip1));
  printf("%d %d \n", sizeof(ip2), sizeof(ip3));

  return 0;
  }

  summary!!
  ip3==&ip2
  *ip3==ip2==&ip1
  **ip3==*ip2==ip1==&num1
  ***ip3==**ip2==*ip1==num1==10



### 주소의 가감산.

#include <stdio.h> 
int main( )
{
char c='A';
char* cp=NULL;
char** cpp=NULL;

cp=&c; 
cpp=&cp;

//%x => 16진수
printf("%x %x %x %x \n", &c , cp , &cp, &cpp); 
printf("%x %x %x \n", &c+1, &cp+1, &cpp+1);
printf("%c %x %x \n", c, cp, cpp); 
printf("%c %x %x \n", c+1, cp+1, cpp+1); 
return 0;
}

#include <stdio.h> 
int main( )
{
int num=10; 
int* ip=NULL; 
int** ipp=NULL;

ip=&num; 
ipp=&ip;
printf("%x %x %x \n", &num, &ip, &ipp); 
printf("%x %x %x \n", &num+1, &ip+1, &ipp+1);
printf("%d %x %x \n", num, ip, ipp); 
printf("%d %x %x \n", num+1, ip+1, ipp+1); 

return 0;
}


#include <stdio.h> 
int main( )
{
int array[3]={10,20,30}; 
int* ip=NULL;
int** ipp=NULL;
ip=array; //,,,위에서 int형이 저장된 변수의 주소는 &연산자를 통해 포인터에
// 저장해줬었는데 array는 &연산자 없어도 array의 주소가 포인터에 저장이 되나봄
ipp=&ip;
printf("%d %d %d \n", array[0], array[1], array[2]); 
printf("%x \n", ip);
//ㅇㅇ맞네
//int형이 저장된 변수는 주소 불러오는 연산자 &를 써줬었어야 하는데
// array가 저장된 변수는 주소 불러오는 연산자 &사용하지 않아도 된당
printf("%d %d %d \n", *(ip+0), *(ip+1), *(ip+2)); 
printf("%d %d %d \n", *(*ipp+0), *(*ipp+1), *(*ipp+2));
return 0;
}

### 함수 포인터
- 함수 이름은 함수의 시작 주소..

#include <stdio.h>
int main(void)
{
  printf("%x %x %x \n", main, printf, scanf);
  return 0;
}

- 함수 포인터 : 함수의 시작 주소를 저장하는 변수
자료형 - 함수 포인터 이름 - 인수 자료형 목록
- 자료형 : 가리키는 대상이 되는 함수의 자료형을 설정
- 함수 포인터 이름 : 괄호와 *을 반드시 사용
- 인수 자료형 목록 : 가리키는 대상이 되는 함수의 인수들의 자료형 목록

#include <stdio.h>
void add(double num1, double num2); 
int main( )
{
  double x=3.1, y=5.1;
  void (*pointer) (double, double); // 함수 포인터 선언
  // 함수 포인터만 선언한 것이고 아직 이 포인터를 add라는 함수에 할당해주진 않았음
  printf("add 함수의 주소 : %x\n", add); 
  printf("함수 포인터의 주소 : %x \n", &pointer);
  
  pointer=add;
  pointer(x, y); // 함수 포인터를 이용한 호출
  return 0; }

void add(double num1, double num2)
{double result;
result=num1+num2;
printf("%lf + %lf = %lf입니다.\n", num1, num2, result);
}

--------------------------------------------
포인팅 대상 함수 void add (double num1, double num2)
함수 포인터 void (*pointer) (double, double)
함수포인터(pointer)에 함수 시작 주소(add) 저장 pointer = add;
함수포인터를 이용한 함수 호출 pointer(3.1,5,1)
--------------------------------------------

함수 포인터의 필요성
1. 일반적인 함수 호출보다 빠른 처리 속도를 기대한다.
2. 사용분야 : 컴파일러, 인터프리터, 게임 프로그래밍과 같은 시스템 프로그래밍 분야


