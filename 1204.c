- 구조체
  - 여러 자료형 변수들의 집합체
struct student{
  int id;
  char name[20];
  float GPA;
};

struct student s1,s2;
struct student s1={1234,"홍길동",3.2};

아니면 정의와 함께 선언해도 됨

struct student{
  int id;
  char name[20];
  float GPA;
} s1,s2;

구조체 대입
- 같은 자료형의 구조체 변수간의 대입이 가능하며, 이 경우 모든 멤버가 한 번에 대입된다.
- 예) s2 = s1

다르게 정의된 구조체에서 생성된 변수는 대입 불가능
- 당연히 그러겠지? 멤버 구성이 다를테니


- typedef 사용하기
typedef struct{
  int id;
  char name[20];
  float GPA;
} STUD;

원래 struct 안 했으면 
struct STUD sd1,sd2 이렇게 했어야 되는데
그냥 STUD sd1,sd2 이렇게만 해도 됨 (typedef를 사용했으니까)

구조체 포인터
- 구조체에 대한 포인터를 이용하여 구조체 참조 가능
  - 예) struct student stud1,*p1 (typdef 사용하지 않은 경우)
  - p = &stud1;
  - *p는 p가 가리키는 구조체
  - (*p).id : p -> id
  - (*p).name : p -> name
    - 이렇게 멤버 변수에 접근할 수도 있겠지?
    - 그리고 괄호도 꼭 필요함


구조체를 위한 동적 기억장소 할당
p = (struct student *)malloc(sizeof(struct student));

함수와 구조체
- 구조체 자체 혹은 구조체 포인터를 매개변수로 전달할 수 있다. 
(1) 구조체 자체를 매개변수로 전달하는 방법
  - 함수를 정의할 때 구조체를 매개변수로 선언하고
  - 함수가 호출될 때 인수로 구조체를 전달
  - 인수 구조체의 모든 값이 매개변수에 그대로 복사
(2) 구조체 포인터를 매개변수로 전달하는 방법
  - 구조체의 포인터를 매개변수로 전달하여
  - 이 포인터로 구조체를 참조하는 방법
  - 구조체 전체를 복사할 필요가 없으므로 시간이 적게든다. 


구조체를 반환할 수도 있고, 구조체에 대한 포인터를 반환할 수도 있다. 

구조체 배열
- 구조체 배열의 각 원소는 하나의 구조체이다.
- struct student s[100];
- 구조체 배열 초기화 예
  - struct student stud[]={
    {123123,"afgwef",234.4},
    {123123,"afgwef",234.4},
    {123123,"afgwef",234.4}
  }

구조체 포인터 배열
struct student *s[100]
- 구조체의 배열이 아니라
- 구조체 포인터의 배열

중첩 구조체
- 구조체의 맴버로서 다른 구조체를 사용할 수 있다. 

공용체
- 구조체와 비슷하게 여러 개의 멤버 변수로 구성된다. 
- 한 순간에 하나의 멤버 변수만 사용할 수 있다. 
union price{
  int won;
  float dollar;
  float euro;
}sale;

## 멤버 변수 won, dollar, euro 모두 한 기억공간을 공유
- 공용체 내의 다른 멤버 변수에 새로이 데이터를 대입하면 기존의 데이터는 지워진다. 
- dollar 값을 대입하면 won 값은 지워진다. 
sale.won = 10000;
sale.dollar = 39.99;
즉, 한 순간에 하나의 멤버 변수만 사용할 수 있다. 