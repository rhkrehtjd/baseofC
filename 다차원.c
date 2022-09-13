//다차원?
// 2차원 이상의 배열을 의미
// 2차원이면 matrix, 3차원이면,,, ?

//2차원 배열의 선언
//[자료형] [배열이름] [배열길이]

//2차원 배열의 선언
#include<stdio.h>
int main(void)
{
// 2차원 배열의 선언
int array[4][3]; // 4행 3열의 배열 길이 선언
array[0][0]=1; array[0][1]=2; array[0][2]=3;
array[1][0]=4; array[1][1]=5; array[1][2]=6;
array[2][0]=7; array[2][1]=8; array[2][2]=9;
array[3][0]=10; array[3][1]=11; array[3][2]=12;
printf("%d %d %d \n",array[0][0], array[0][1], array[0][2]); // 0행 출력
printf("%d %d %d \n",array[1][0], array[1][1], array[1][2]); // 1행 출력
printf("%d %d %d \n",array[2][0], array[2][1], array[2][2]); // 2행 출력
printf("%d %d %d \n",array[3][0], array[3][1], array[3][2]); // 3행 출력
return 0;
}

//2차원 배열 선언과 동시에 데이터 저장(데이터 저장 과정을 초기화라고도 한다.)

#include<stdio.h>
int main(void)
{
    //아 굳이 tab해서 들여쓰기 하지 않아도 되네
    //중괄호로 묶여있어서?

// 2차원 배열 선언 과 동시에 데이터 저장(초기화)
int array1[4][3]={1,2,3,4,5,6,7,8,9,10,11,12};
int array2[4][3]={1,2,3,4,5};
// array2에서 배열하지 않은 원소들은 0으로 자동 배정된다. 

// 2차원 배열 array1의 데이터 출력
printf("%d %d %d \n",array1[0][0], array1[0][1], array1[0][2]); // 0행 출력
printf("%d %d %d \n",array1[1][0], array1[1][1], array1[1][2]); // 1행 출력
printf("%d %d %d \n",array1[2][0], array1[2][1], array1[2][2]); // 2행 출력
printf("%d %d %d \n",array1[3][0], array1[3][1], array1[3][2]); // 3행 출력
printf("--------------------\n");
// 2차원 배열 array2의 데이터 출력
printf("%d %d %d \n",array2[0][0], array2[0][1], array2[0][2]); // 0행 출력
printf("%d %d %d \n",array2[1][0], array2[1][1], array2[1][2]); // 1행 출력
printf("%d %d %d \n",array2[2][0], array2[2][1], array2[2][2]); // 2행 출력
printf("%d %d %d \n",array2[3][0], array2[3][1], array2[3][2]); // 3행 출력
return 0;
}

//다차원 배열의 응용
#include<stdio.h>
int main(void)
{
int array1[4][3]={{1,2},{3},{4},{5}};
//아 중괄호로 묶으면 한 행 단위로 초기화 가능!
int array2[4][3]={{1,2,3},{4,5,6},{7,8,9},{10}};
printf("%d %d %d \n",array1[0][0], array1[0][1], array1[0][2]);
printf("%d %d %d \n",array1[1][0], array1[1][1], array1[1][2]);
printf("%d %d %d \n",array1[2][0], array1[2][1], array1[2][2]);
printf("%d %d %d \n",array1[3][0], array1[3][1], array1[3][2]);
printf("--------------------\n");
printf("%d %d %d \n",array2[0][0], array2[0][1], array2[0][2]);
printf("%d %d %d \n",array2[1][0], array2[1][1], array2[1][2]);
printf("%d %d %d \n",array2[2][0], array2[2][1], array2[2][2]);
printf("%d %d %d \n",array2[3][0], array2[3][1], array2[3][2]);
return 0;
}

//다차원 배열의 응용2
#include<stdio.h>
int main(void)
{
// 2차원 배열의 선언
int array[2][2];
int i,j;
// 2차원 배열에 데이터 입력
for(i=0;i<2;i++)
{
for(j=0; j<2; j++)
{
printf("정수를 입력하세요: ");
scanf("%d", &array[i][j]);
}
}
//2차원 배열에 데이터 출력
for(i=0;i<2;i++)
{
for(j=0; j<2; j++)
{
printf("%3d",array[i][j]);
}
printf("\n");
}
return 0;
}


// 2차원 배열 선언 시 주의사항
// 열의 길이는 반드시 설정한다.
int array1[ ][ ]={1, 2, 3, 4, 5, 6, ,7 ,8 ,9, 10, 11, 12}; // 에러!
int array2[4][ ]={1, 2, 3, 4, 5, 6, ,7 ,8 ,9, 10, 11, 12}; // 에러!
int array3[ ][3]={1, 2, 3, 4, 5, 6, ,7 ,8 ,9, 10, 11, 12}; // 정상
int array4[ ][4]={1, 2, 3, 4, 5, 6, ,7 ,8 ,9, 10, 11, 12}; // 정상
int array5[ ][2]={1, 2, 3, 4, 5, 6, ,7 ,8 ,9, 10, 11, 12}; // 정상

//3차원 배열의 이해
// int array[면][행][열]
#include <stdio.h>
int main(void)
{
int i, j, k;
//행 단위로 배열 초기화 
int array[3][3][3]={ {1,2,3,4,5,6,7,8,9},
{10,11,12,13,14,15,16,17,18},
{19,20,21,22,23,24,25,26,27}
};
for(i=0; i<3; i++) // 0면, 1면, 2면
// 일단 0면에 대해 배열 설정!
//0면의 3행 3열을 1~9로 초기화한다.
{
for(j=0; j<3; j++) // 0행, 1행, 2행
{
for(k=0; k<3; k++) // 0열, 1열, 2열
{
printf("%d ", array[i][j][k]);
}
printf("\n");
}
printf("---------------\n");
}}

// & 연산자
//2차원 배열의 주소와 값의 참조
//2차원 배열 요소의 주소를 참조하는 연산자.
#include<stdio.h>
int main(void)// main 함수에 아무것도 넣지 않고 정수형 자료 결과를 내보내는 함수
{
int array[2][3]={1,2,3,4,5,6};
printf("%x %x %x \n", &array[0][0],&array[0][1],&array[0][2]);
printf("%x %x %x \n", &array[1][0],&array[1][1],&array[1][2]);
return 0;
}

//2차원 배열의 다양한 주소 표현
#include<stdio.h>
int main(void)
{
int array[2][2] = {10,20,30,40};
printf("%x %x \n", array, array+0); // 0행의 주소
// array나 array+0 이나 둘다 동일하게 0행의 주소를 의미한다. 
printf("%x \n", array+1); // 1행의 주소
return 0;
}

//2차원 배열의 첫 번째 행의 요소는 행을 대표하는 주소이다. 
#include<stdio.h>
int main(void)
{
int array[2][2] = {10,20,30,40};
printf("%x %x\n", array[0], &array[0][0]);
printf("%x %x\n", array[1], &array[1][0]);
return 0;
}

//2차원 배열에서 array[i]= *(array + i)는 주소이다. 
#include<stdio.h>
int main(void)
{
int array[2][2] = {10,20,30,40};
printf("%x %x %x\n", array[0],*(array+0), *array);
printf("%x %x \n", array[1],*(array+1));
return 0;
}

#include<stdio.h>
int main(void)
{
int array[2][2] = {10,20,30,40};
printf("%d %d \n", *&array[0][0],*&array[0][1]);
printf("%d %d \n", *&array[1][0],*&array[1][1]);
printf("-------------------\n");
printf("%d %d \n", *array[0]+0, *array[0]+1 );
printf("%d %d \n", *array[1]+0, *array[1]+1 );
printf("-------------------\n");
printf("%d %d \n", **(array+0)+0, **(array+0)+1 );
printf("%d %d \n", **(array+1)+0, **(array+1)+1 );
return 0;
}

//위 덩어리와 비교해보면
//괄호유무차이임을 알 수 있다. 
#include<stdio.h>
int main(void)
{
int array[2][2] = {10,20,30,40};
printf("%d %d \n", *&array[0][0],*&array[0][1]);
printf("%d %d \n", *&array[1][0],*&array[1][1]);
printf("-------------------\n");
printf("%d %d \n", *(array[0]+0), *(array[0]+1));
printf("%d %d \n", *(array[1]+0), *(array[1]+1));
printf("-------------------\n");
printf("%d %d \n", *(*(array+0)+0), *(*(array+0)+1));
printf("%d %d \n", *(*(array+1)+0), *(*(array+1)+1));
return 0;
}

//아 괄호 잘치자~