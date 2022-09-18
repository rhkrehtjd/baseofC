배열 포인터
- 배열을 지정할 수 있는 포인터(배열을 가리키는 포인터)
- int (*p) [3];
- 자료형 : 배열 포인터 변수가 저장하는 배열의 자료형
- 배열 포인터 변수 이름 : *연산자와 배열 포인터 변수 이름을 함께 괄호로 묶음
  - 배열 포인터 말고 그냥 변수 포인터는 자료형이 *연산자 붙였던 것 같음
- 열의 길이 : 배열 포인터 변수가 가리키는 배열의 열의 길이를 지정

배열 포인터 변수를 통한 2차원 배열의 접근

#include <stdio.h> 
int main(void)
{
int array[2][3]={10,20,30,40,50,60};
int (*p)[3]=NULL; // 배열 포인터 변수 p 선언
p=array; // 포인터 변수에 배열의 시작 주소 저장
printf("%d %d %d \n", p[0][0], p[0][1], p[0][2]); 
printf("%d %d %d \n", p[1][0], p[1][1], p[1][2]); 
return 0;
}

# 비교
포인터 배열
- 주소를 저장하는 배열을 만들어보자
- 지금 바로 아래 : 이렇게 포인터를 만들면 관리하기 힘들다라는 예시
- 아래아래 예시가 포인터를 이렇게 관리하자라는 포인터 배열을 말해주는 예시
int* pointer [3];

자료형 : 포인터 배열의 자료형을 지정, 자료형 다음에 *연산자를 붙임
포인터 배열 이름 : 주소를 저장할 배열의 이름을 지정
배열 길이 : 주소를 저장할 배열의 전체 길이를 지정

#include <stdio.h> 
int main(void)
{
int a=10, b=20, c=30; 

int* ap=NULL;
int* bp=NULL;
int* cp=NULL;

ap=&a; 
bp=&b; 
cp=&c;

printf("%d %d %d \n", a, b, c); 
printf("%d %d %d \n", *ap, *bp, *cp);
printf("%x %x %x \n", &a, &b, &c); 
printf("%x %x %x \n", ap, bp, cp); 
printf("%x %x %x \n", &ap, &bp, &cp); 
return 0;
}

# 포인터가 많아지면 위처럼 관리하는 것이 아니라 아래처럼 관리해야 한다!

#include <stdio.h> 
int main(void)
{
int a=10, b=20, c=30;
int* ap[3]={NULL, NULL, NULL}; //포인터 배열
ap[0]=&a; ap[1]=&b; ap[2]=&c;

printf("%x %x %x \n", &a, &b, &c);
printf("%x %x %x \n", ap[0], ap[1], ap[2]); 
printf("%x %x %x \n", *(ap+0), *(ap+1), *(ap+2)); 
printf("--------------\n");
printf("%d %d %d \n", *&a, *&b, *&c);
printf("%d %d %d \n", *ap[0], *ap[1], *ap[2] ); 
printf("%d %d %d \n", **(ap+0), **(ap+1), **(ap+2) ); 
return 0;
}


!!!!!!
< 포인터 배열과 배열 포인터의 차이>

- 배열 포인터 변수
  - 3열 가진 2차원 배열의 시작 주소를 저장
    - int (*p)[3]=NULL;
- 포인터 배열 변수
  - 괄호가 생략되어 있으며, 주소를 저장할 수 있는 배열
    - int* p[3]={NULL,NULL,NULL};


포인터와 문자 그리고 포인터와 문자열

#include <stdio.h> 
int main(void)
{
  char array1[ ]={'A', 'B', 'C', 'D'}; 
  char* p=NULL;
  
  p=array1;
  printf("%c %c %c %c \n", p[0], p[1], p[2], p[3]);
  printf("%d %d %d %d \n", p[0], p[1], p[2], p[3]); 
  printf("%c %c %c %c \n", *(p+0), *(p+1), *(p+2), *(p+3) );
  printf("%d %d %d %d \n", *(p+0), *(p+1), *(p+2), *(p+3) ); 
  return 0;

}
- 문자열을 배정했으니 %d가 아니라 %c로 반환받자


문자열과 NULL문자
- 문자열의 특징
  - ""내에 포함된 하나 이상의 문자
  - 문자열의 끝에는 문자열의 끝을 알리는 NULL 문자 즉, 종료문자(\0) 삽입
  - 문자열의 시작 주소를 알면 저장된 문자들에 접근 가능
  - 문자열은 문자열 상수와 문자열 변수로 구분
  - 문자열을 입력하고 출력할 때 서식문자 %s를 사용

아래 두 예시를 비교해보자

1) 첫 번째 예시
#include <stdio.h> 
int main(void)
{
// 문자 출력
char array[ ]="ABCD";
// 문자열 배열 선언
printf("%c %c %c %c %c \n", array[0], array[1], array[2], array[3], array[4]);
printf("%d %d %d %d %d \n", array[0], array[1], array[2], array[3], array[4]);
 // 문자열 크기 출력 
printf("%d \n", sizeof(array)); 
return 0;
}

#include <stdio.h>
int main(void)
{
  char array[]={'A','B','C','D','\0','WER'};
  //문자열 배열 선언

  //문자 출력
  printf("%c %c %c %c %c \n", array[0],array[1],array[2],array[3],array[4]);
  printf("%s\n", array);
  return 0;
}

포인터와 문자열

포인터 : 문자열의 시작 주소를 저장한다, 문자열의 특정 문자 위치를 저장한다
문자열의 특징
  - 메모리 공간에 연속으로 저장되어 있어 주소가 연속적이다.
  - 문자열의 시작 주소를 알면 모든 문자들에 접근 가능하다.
  - 서식문자 %s로 문자열을 일괄 출력할 수 있다. 
  - %s는 문자열의 시작 주소부터 종료문자인 \0을 만날 때까지 문자열을 출력한다.


#include <stdio.h> 
int main(void)
{
  char* p="ABCD";

  printf("%s\n",p);
  printf("%s\n",p+1);
  printf("%s\n",p+2);
  printf("%s\n",p+3);
return 0; }




//포인터 배열 선언
char* array[2] = {"Goog morning","C=language"};
//위와 같은 표현
char* array[2] = {&"Goog morning",&"C=language"};

# 포인터 변수의 상수화
- const 키워드를 이용해 포인터 변수를 상수화

- 포인터 변수의 상수화의 의미
  - 포인터 변수에 다른 주소를 저장하지 못하게 한다.
  - 포인터 변수를 통해 메모리 공간의 값을 변경하지 못하게 한다. 
  - 1과 2 둘 다 못하게 한다. 

1의 의미?
  - 포인터 변수에 다른 주소를 저장하지 못하게 한다?

#include <stdio.h> 
int main(void)
{
char a='A'; 
char b='B';
char* const p=&a; // p=&a 상수화

*p='C'; // 변경 가능 
printf("%c \n", *p); 
printf("%c \n", a);
//p=&b; // 에러
return 0; }

즉, 값을 변경하는 것은 되지만 p=&b를 통해서 메모리주소를 변경하진 못한다.

2의 의미?
  - 포인터 변수를 통해 메모리 공간의 값을 변경하지 못하게 한다?

#include <stdio.h> 
int main(void)
{
char a='A';
char b='B';
const char* p=&a;\// *p를 상수화

printf("%c \n", *p); 
printf("%c \n", a);
p=&b; // 변경 가능, 상수화 한 것은 *p임.

printf("%c \n", *p); 
printf("%c \n", b);

a=’X’; 
b='C'; 
//*p='D'; //여기서 error 발생함.

return 0;
}

3의 의미?
  - 포인터 변수를 통해 메모리 공간의 주소와 값 모두 변경하지 못하게 한다.
  - 위의 두 코드에서 const char* const p=&a;
  를 통해
  - p=&b도 불가능
  - 8p='D'도 불가능
  - 즉, 메모리 공간의 주소와 값 모두 변경하지 못하게 하는 것이다. 