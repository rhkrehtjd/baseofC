#include <stdio.h>
#include <stdlib.h>

typedef struct node{    
  char name[10];	   // 이름
  int year;	         // 학년
  char dept[10];     // 학과
  int age;           // 나이 
  struct node *next; // 자기 참조 구조체 포인터 변수
}Node;               // linked list structure

Node *head = NULL;   // data를 넣을 처음 변수

// 객체를 연결(=저장)
void Add(Node node){
  Node *add = (Node*)malloc(sizeof(Node));// 메모리 할당
  *add = node;      // 인자로 받은 data를 메모리 할당한 변수에 저장
  add->next = head; // 객체를 맨 앞에 연결
  head = add;       // 새로 연결한 객체를 맨 앞으로 만듦
}

// linked list에 있는 전체 data를 print
void Show(){

  Node *loop = head;

  while(loop!=NULL){
    printf("이름: %s\t학년:%d\t학과:%s\t나이:%d\n",
    loop->name, loop->year, loop->dept, loop-> age);
    loop = loop-> next;
  }
}


int main(){	

  FILE *fp = fopen("studentdata1.txt","r");
  Node temp;

  while(1){
    // 파일에서 다음 data가 없을 때까지 읽어오기
    if(fscanf(fp,"%s%d%s%d", &temp.name,&temp.year,&temp.dept,&temp.age)==EOF)
    break;// 다음 data가 없다면 break
    Add(temp);
  }

  Show();
  fclose(fp);
  return 0;
  }