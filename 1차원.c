//이때 #include <stdio.h>를 써주어야 printf를 사용할 수 있다
//파이썬에서 필요한 numpy나 pandas를 import해야 해당 라이브러리를 사용할 수 있는 
//것과 같은 개념인 것 같다. 

// stdio는 standard input output의 약어이다.

// void = '변수 없다'라는 뜻
// int = 정수형 자료형을 의미
// char = 문자형 자료형
// float = 실수형 자료형

// int main(void)
// 아 그럼, y=f(x)라는 함수라 쳤을 때 x는 void가 되고, y는 int가 되는 것
// 즉, main함수에 아무것도 넣지 않고 정수형 자료결과를 내보내는 함수란 뜻이다. 

// void main(void) = void main() = main(void) = main



#include <stdio.h>
int main(void)
{
    int student[5];
    //당연히 student는 임의의 이름으로서 다른 이름으로 대체 가능하다

    student[0] = 90;
    student[1] = 80;
    student[2] = 70;
    
    //같은 자료형만 한 배열에 포함시킬 수 있다. 


    printf("첫 번째 학생의 점수 : %d \n", student[0]);

    return 0;
}

#include <stdio.h>
int main(void)
{
    int array[3]={12,212,12};
    int i, total=0;

    for(i=0;i<3;i++)
    {
        total = total + array[i];
        printf("배열의 요소 array[%d]의 값: %d \n",i,array[i]);

    }

    printf("총점은 %d이고", total);
    printf("평균은 %.2lf 입니다\n",(double)total/3);

    return 0;
}

//배열 선언과 동시에 저장(초기화)
#include <stdio.h>
int main(void)
{
    int array1[5]= {12,12,312,3123,123};
    //배열을 선언함과 동시에 그 배열의 원소들을 저장해주었음

    printf("%d %d %d %d %d",array1[0],array1[1],array1[2],array1[3],array1[4]);
    
    return 0;
}


// 배열은 3개하고 1개만 지정하면 어떻게 돼?
#include <stdio.h>
int main(void)
{
    int array[2];
    array[0]=2;

    printf("%d",array[2]);
    return 0;
}
// 안 되는 것 같은데?
// 0으로 배정되는 게 아니라?


//배열 선언 시 주의할 점
#include <stdio.h>
int main(void)
{
    int array[2]; 
    //배열 길이는 2
    array[0]=123;
    array[1]=1243;
    //array[2]=1234
    //배당준 건 길이가 2인 array인데 세개를 배정하니 error 발생한다. 
    printf("지정이 잘 됐는지 확인해볼까?\n");
    printf("내가 지정한 array라는 이름의 array의 첫 번째 원소는 %d 입니다", array[0]);

    return 0;
}

//배열 선언시 주의할 점
// 배열 초기화를 중괄호로 할 때, 배열의 선언과 초기화가 개별적으로 이루어져서는 안 된다. 
#include <stdio.h>//printf할 수 있게 해줌
int main(void)
{
    //정상적인 배열 선언과 배열 초기화 과정
    int array1[3]={12,23,45};
    int array2[3];//이렇게 선언은 해놓고 초기화는
    //array2={123,123,123} 개별적으로 하면 안 됨

    //뭐 암튼 배열 선언과 중괄호를 통한 배열 초기화는 동시에 이루어져야 한다.
    
    return 0;
}

//배열 길이를 변수로 설정하면 안 된다
// 배열의 길이는 상수로 설정해야 한다.

#include <stdio.h>
#define MAX 10 //심볼릭 상수 선언
int main(void)
{
    int a=3;
    const int SIZE=20; // 심볼릭 상수 선언
    int array1[MAX]; // 정상!(배열 길이를 심볼릭 상수로 설정)
    int array2[SIZE]; // 정상!(배열 길이를 심볼릭 상수로 설정)
    //아래처럼 하면 error 발생
    //int array3[a];
    //위 명령은 매열 길이를 변수로 설정한 것임

    return 0;
}

// 1차원 배열의 주소와 값의 참조
// &는 주소를 참조하는 연산자
// 주소 연산자로서 메모리 공간의 주소를 표현

//사용법을 알아보자
#include <stdio.h>
int main(void)
{
    int a=10, b=20;
    printf("%x \n", &a);
    printf("%x \n", &b);
    return 0;

    //a와 b의 주소를 알 수 있음

}

// 위는 변수의 주소 표현이었다면
// 아래는 배열의 주소 표현이다.
#include <stdio.h>
int main(void)
{
    int array[2]={10,20};
    printf("%x \n", &array[0]); //array[0]의 주소
    printf("%x \n", &array[1]); //array[1]의 주소
    

    return 0;
}

#include<stdio.h>
int main(void)
{
    int array1[3] = {1,2,3}; 
    char array2[3] = {'A','B','C'};
    printf("%x %x %x \n", &array1[0], &array1[1], &array1[2]);
    printf("%x %x %x \n", &array2[0], &array2[1], &array2[2]);
    
    return 0; 
    }

// 연산자 *
// 메모리의 주소 앞에 사용된 경우, 메모리 공간에 저장된 값을 참조하는 연산자 역할을 한다.
#include<stdio.h>
int main(void)
{
    int a=10, b=20;
    printf("%d \n",*&a);
    printf("%d \n",*&b);
    return 0; 
    }

// 즉,,,,
// *&array[0] = array[0]
// *과 &는 상쇄된다고 생각할 수 있는 것이다.

#include<stdio.h>
int main(void)
{
    int array[3] = {1,2,3};
    printf("%x %x %x \n", array+0, array+1, array+2); 
    printf("%d %d %d \n",*(array+0),*(array+1),*(array+2)); 
    printf("%d %d \n", *(array+0), *array);
    return 0; }

// 결론 : 반드시 숙지해야 할 사항
// *(array + i) = array[i] = *&array[i]