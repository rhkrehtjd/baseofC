#include <stdio.h>
enum day{
  sun,mon,tue,wed,thu,fri,sat};

int main()
{
  enum day d;
  d = sun;
  printf("%d\n",d);
  d = mon;
  printf("%d\n",d);
  d = tue;
  printf("%d\n",d);
  return 0;
}
// 열거형은 정수형 상수에 이름을 붙여서 코드를 이해하기 쉽게 해준다
// 예를 들면
const int ValueA = 1;
const int ValueB = 2;
const int ValueC = 3;
ValueA,ValueB,ValueC라는 정수형 상수를 선언한다면 두세 개까지는 괜찮지만
개수가 많아지면 일일이 선언하기가 귀찮아진다. 

-> 이때, 열거형을 사용하면 정수형 상수를 좀 더 편하게 정의할 수 있다.

??????????????
#include <stdio.h>
enum day{
  sun,mon,tue,wed,thu,fri,sat};

int main()
{
  enum day d;
  d = sun;
  printf("%d\n",d);
  d = mon;
  printf("%d\n",d);
  //또는 다음과 같이 할 수 있다?...
  d = day() (d+1);
  printf("%d\n",d);
  return 0;
}

- 상수 값 지정
  - 임의의 상수 값 지정 가능
  - 열거형 정의하면서 동시에 변수 선언도 가능
- enum을 사용하여 변수를 만들고 멤버변수에서 특정 멤버변수로 지정할 수도 있다.

#include <stdio.h>
enum week
{
  sun, mon, tue, wed, thu, fri, sat
};

int main(void)
{
  enum week what = thu;
  printf("what의 값은?: %d \n", thu);

  return 0;
}

- 또한 typedef를 사용할 수도 있다. 
#include <stdio.h>
typedef enum week{
  SUN,MON,TUE,WED,THU,FRI,SAT}WEEK;

  int main(void){
    WEEK what = TUE;
    printf("what의 값 ?:%d\n",what);
    return 0;}



- 형 정의
  - typedef : 자료형에 새로운 이름으르 만들기 위해 사용되는 예약어
  ///....


4장..?
## 입출력과 전처리

- 전처리기 지시자 : #로 시작하는 문장
- 표준입출력 : printf(), scanf
- 버퍼 : 임시저장 장치

전처리기(preprocessor)
  - 컴파일러가 프로그램을 번역하기 전에 소스 프로그램을 처리하는 프로그램
전처리기 지시자
  - 전처리기에게 특정 작업을 지시하는 유사명령어
  - 실제로 실행시간에 수행되는 명령어가 아님
  - #으로 시작함
중요한 전처리기 지시자
  - #include : 다른 파일의 내용을 현재 파일에 포함시킴
  - #define : 특정 단어를 다른 문자열로 바꿈

#include 
  - 파일 포함 지시자
  - 헤어 파일
    - 다른 파일에 포함시킬 목적으로 작성된 파일
    - include file이라고도 함
<표준 헤더파일>
  - 시스템의 특별한 위치에 존재
<일반 헤더파일>
  - 소스파일과 같은 위치에서 찾을 수 있는 파일

#include <stdio.h>

int X = 101;

int main(){
  printf("X = %d\n",X);
  return X;
}

?? 헤더파일 만드는 법 알아보기


#include <stdio.h>
int main(){
  
  int i = 2;
  double pi = 3.141592349193491394;
  char c = '5';

  printf("i = %10d\n",i);
  printf("f = %14.13f\n",pi);
  printf("c = %10c\n",c);

  return 0;
}

#include <stdio.h>
int main(){
  int n = 0;

  scanf("%d", &n); //주소연산자 &를 사용한 점에 주의하자
  printf("entered n = %d\n",n);
  return 0;
}

문자 입출력
getchar, putchar: 문자 입출력

#include <stdio.h>
#include <ctype.h>
int main(){

 char c;
 printf("소문자를 입력하세요:");
 c = getchar();
 printf("의 대문자는: ");
 putchar(toupper(c));
 return 0;
}