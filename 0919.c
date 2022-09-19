# 변수의 초기화
- 변수를 선언하면서 그 초기값을 정할 수도 있다. 
- 변수 초기화는 반드시 해야하는 것은 아니며 선택사항이다.
- 그 예를 살펴보자

char c = 'A';
int score = 0;
float rate = 3093.123;
int sum = 0, a , b = 4;

이때 바로 위 줄에서 int sum = 0 , a , b = 4라고 되어 있는데
이는 int로 sum,a,b를 선언할 것이며, a만 초기화하지 않고 sum이랑 b만
초기화 진행한 것이다. 

--------------------------------------------------------

# 대입문
- 변수이름 = 수식
- 변수에 값을 대입한다.
- 변수에 새로운 값을 저장함으로써 기존 값을 변경한다.
- 대입 연산자의 오른쪽 식이 계산되고, 그 결과 값이 왼쪽 변수에 저장된다. 

#include <stdio.h>
int main()
{
  int score = 0; // 변수의 초기화

  score = 70; // 변수에 값 대입
  printf("첫 번째 점수는 %d 입니다. \n", score);
  // %d => 뒤에 주어지는 변수의 값을 정수로 출력하라. 십진수!
  score = 50; // 변수에 값 대입
  printf("두 번째 점수는 %d 입니다. \n", score);
  score = 34;
  printf("세 번째 점수는 %d 입니다. \n", score);
  return 0;
}

#include <stdio.h>
int main()
{
  int mid, final, total;

  mid = 60;
  printf("중간 점수는 %d 입니다. \n",mid);

  final = 100;
  printf("기말 점수는 %d 입니다. \n", final);

  total = mid + final;
  printf("총점은 %d 입니다. \n", total);

  return 0;
}

--------------------------------------------------------

# 변수 값의 증가
- 대입문 오른쪽과 왼쪽에 나타난 변수는 다른 의미
  - 대입문 오른쪽 변수는 그 변수로부터 읽어온 값을 의미
  - 대입문 왼쪽 변수는 그 변수에 저장 의미
  - x = x+1
  - 이는 다음과 같다
  - x++
  - 변수에 접근은 그 값을 변경시키지 않음
    - 당연, 변수를 그냥 읽는 건데 당연히 변경되지 않음
  - 변수에 대입(쓰기)은 이전 데이터를 새로운 데이터로 대체

#include <stdio.h>
int main()
{
  int sum = 0, score;

  score = 70;
  sum = sum + score;
  printf("첫 번째 점수 : %d, 누적 합 : %d\n", score,sum);
  
  score = 7340;
  sum = sum + score;
  printf("첫 번째 점수 : %d, 누적 합 : %d \n", score,sum);
  
  score = 72340;
  sum = sum + score;
  printf("첫 번째 점수 : %d, 누적 합 : %d \n", score,sum);
  
  return 0;
}
--------------------------------------------------------

# 상수
- 프로그램이 실행되는 동안 값이 변경되지 않는 데이터
- 정수형 상수, 문자형 상수, 무동소수형 상수로 구분할 수 있다. 
- 리터럴 상수의 예
  - 'A', 'x'는 문자형 상수 : 인용부호()로 묶는 것에 주의
  - 10, -32, 3 : 정수형 상수
  - 3.234, 134.12 : 부동소수형 상수

- 기호 상수
  - 상수에 이름이 부여되어 있는 것
  - 기호 상수는 이름이 있으므로 변수와 유사하지만 상수이므로 값을 변경할 수 없다. 
  - 기호 상수의 정의
    - #define MAX_STUDENT 20000
    - #define PI 3.12

#include <stdio.h>
int main()
{
  const float PI = 3.14;
  #define PI 123483543.231452463
  double r, area;

  r = 40.4;
  area = PI * r * r;
  printf("반지름 %8.2f인 원의 면적 : %8.2f \n", r, area);
  //8.2f : 부동 소수형으로 전체자리수 8자리 출력할 건데, 소수점 아래는 2자리만 출력한다. 
  
  printf("PI=%3.3f \n ",PI);
  
  return 0;
}

# 그렇다면 const와 define의 차이?
- define은 메모리에 올라가지 않는다.
- const는 type을 지정해줄 수 있으므로 프로그래머가 error를 확인하기 용이하다. 

--------------------------------------------------------

# 정수형
- char, short, int, long, long long
- 기억공간 할당
  - 정수형 종류에 따라 해당 변수에 다른 크기로 할당
- sizeof()  
  - 자료형의 크기를 나타내는 연산자
  - ex : sizeof(char)

#include <stdio.h>
int main()
{
  printf("char의 크기: %d\n", sizeof(char));
  printf("short의 크기: %d\n", sizeof(short));
  printf("int의 크기: %d\n", sizeof(int));
  printf("long의 크기: %d\n", sizeof(long));
  printf("float의 크기: %d\n",sizeof(float));

  return 0;
}
- 컴파일러마다 크기는 다를 수 있음

#include <stdio.h>
int main()
{
  short no_univ = 234;
  int population = 13414241241;
  long budget = 2341234123122134L;

  puts("대한민국에 대한 데이터입니다");
  printf("대학 수: %d\n", no_univ);
  printf("인구: %d\n",population);
  printf("예산: %ld\n",budget);

  return 0;
}

자료형이 long이어서 출력이 이상하게 됨
long long으로 바꾸어보자


#include <stdio.h>
int main()
{
  short no_univ = 234;
  int population = 51269544;
  long long budget = 12341234123234324L;

  puts("대한민국에 대한 데이터입니다");
  printf("대학 수: %d\n", no_univ);
  printf("인구: %d\n",population);
  printf("예산: %lld\n",budget);

  return 0;
}

-----------------------------------------------
# 정수 표현
- 8비트를 이용한 양수와 음수 표현 예
  - 첫 번째 비트는 부호 비트로서 0은 양수, 1은 음수는 나타낸다.
  - 나머지 7개의 비트들은 수의 크기를 나타낸다. 

- 음수 표현
  - 연산의 효율성을 위해 수의 크기를 2의 보수 형태로 나타낸다. 




???근데 뒤에 L은 왜 붙이지?
출력할 때 ld, lld 차이?
보수???
그 뭐냐 그 %7.2f??? 전체자리수 7자리가 뭔말이지?