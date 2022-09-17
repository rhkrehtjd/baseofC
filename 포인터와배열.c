# 포인터와 1차원 배열

잠깐 샛길..
- main 함수는 프로그램 작성 시 기능(함수)들을 수행하기 위한 처음 시작점이다. 
- 모든 프로그램은 하나의 시작점만을 가지고 있기 때문에, main 함수는 언제나 항상, 하나의 프로그램내에서는 1애여야만 한다.
- 다른 이름은 허용하지 않는다.
  - 항상 main만 가능하다.
- main 함수가 1개라는 말은 2개도, 3개도 0개도 허용하지 않는다.
  - main 함수가 없다면 프로그램은 시작점을 찾을 수 없다. 

#include <stdio.h>
int main(void)
{
  int array[3]={10,20,30};

  printf("%x %x %x \n",array, array+0, &array[0]);
  printf("%x %x \n",array + 1, &array[1]);
  printf("%x %x \n",array + 2, array[2]);

  return 0;
}

array = array + 0 = &array[0]
array + 1 = &array[1]
array + 2 = &array[2]

# 포인터 변수를 통한 1차원 배열 요소의 주소 접근
#include <stdio.h>
int main(void)
{
  int array[3] = {10,20,30};
  int* p=NULL; // p라는 이름의 포인터 선언

  p=array;  // p = &array[0];

  printf("%x %d %x %x %x %x \n",array,array[0],&array[0], p, p+0, &p[0]);
  printf("%x %x %x \n", p+1, &p[1]);
  printf("%x %x %x \n", p+2, &p[2]);
  return 0;
}

%d : 10진수로 출력, 정수형
%f : 실수형
%x : 16진수
...

#포인터 변수를 통한 1차원 배열 요소의 값 접근

#include <stdio.h> 
int main(void)
{
int array[3]={10, 20, 30}; 
int* p=NULL;
p=array; // p=&array[0];

// 주소에 *연산자를 붙임
printf("%d %d %d \n", *p, *(p+0), *&p[0]); 
printf("%d %d \n", *(p+1), *&p[1]); 
printf("%d %d \n", *(p+2), *&p[2]); 
return 0;

//*&는 서로 상쇄된다!
//*p = *(p+0)=*&p[0]=p[0]

}


#include <stdio.h> 
int main(void)
{
int array[3]={10, 20, 30}; 
int i=0;
int* p=NULL;

p=array; // p=&array[0]; 
for(i=0; i<3; i++)
printf("%d %d %d \n", *(p+i), *&p[i], p[i] );
printf("--------------------\n");

for(i=0; i<3; i++)
printf("%d %d %d \n", *(array+i), *&array[i], array[i]); 
return 0;
}

#include <stdio.h> 
int main(void)
{
int array[3][3]={10,20,30,40,50,60,70,80,90};
printf("%x %x %x \n", &array[0][0], &array[0][1], &array[0][2]); 
printf("%x %x %x \n", &array[1][0], &array[1][1], &array[1][2]); 
printf("%x %x %x \n", &array[2][0], &array[2][1], &array[2][2]); 
printf("---------------\n");

printf("%d %d %d \n", *&array[0][0], *&array[0][1], *&array[0][2]); 
printf("%d %d %d \n", *&array[1][0], *&array[1][1], *&array[1][2]); 
printf("%d %d %d \n", *&array[2][0], *&array[2][1], *&array[2][2]); 
printf("---------------\n");

printf("%d %d %d \n", array[0][0], array[0][1], array[0][2]); 
printf("%d %d %d \n", array[1][0], array[1][1], array[1][2]); 
printf("%d %d %d \n", array[2][0], array[2][1], array[2][2]);
return 0;
}

# 포인터 변수를 통한 2차원 배열의 접근
#include <stdio.h> 
int main(void)
{
int array[2][3]={10,20,30,40,50,60}; 
int* p=NULL;
p=array; // p=&array[0][0]; // p=array[0]; // 포인터 변수에 시작 주소 저장
printf("------------\n");

printf("%x %x %x \n", &p[0], &p[1], &p[2]); 
printf("%x %x %x \n", &p[3], &p[4], &p[5]);
printf("------------\n");
printf("%d %d %d \n", p[0], p[1], p[2]); // printf("%d %d %d \n", *(p+0), *(p+1), *(p+2)); 
printf("%d %d %d \n", p[3], p[4], p[5]); // printf("%d %d %d \n", *(p+3), *(p+4), *(p+5)); 
return 0;
}

!! 1차원 포인터 변수p는 2차원 배열을 1차원으로만 접근할 수 있다. 
!! 1차원 포인터 변수p에 2차원 배열의 첫 주소를 저장할 순 있지만
!! 접근은 1차원으로만 가능하다
!! 그 예시는 아래와 같다.

#include <stdio.h> 
int main(void)
{
int array[2][3]={10,20,30,40,50,60}; 
int* p=NULL; // int** p;
p=array; // 1차원 포인터 변수에 2차원 배열의 시작 주소 저장

printf("%d %d %d \n", p[0][0], p[0][1], p[0][2]); // 에러 
printf("%d %d %d \n", p[1][0], p[1][1], p[1][2]); // 에러 
return 0;
}

+ 2차원 포인터 변수p는 1차원 포인터의 주소만 저장할 수 있다. 
 

### 19장부터 하면 됨