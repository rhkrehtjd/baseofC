#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{ // 학생 데이터를 담을 구조체를 새로운 타입 element로 정의  
  char name[10];	   // 이름
  int year;	         // 학년
  char dept[10];     // 학과
  int age;           // 나이 
}element;   

typedef struct DListNode{
  struct DListNode* llink;
  element data;
  struct DListNode* rlink;
}DListNode;

// 필요 함수 원형
void init(DListNode* phead); // 처음에 노드를 초기화
DListNode* dinsert_node(DListNode* before, DListNode* new_node);// 새로운 노드를 before 노드 다음에 삽입
void display(DListNode* phead); // 연결 리스트 전체 출력
void free_node(DListNode* phead);// 동적 할당된 메모리 반환
void reversedisplay(DListNode* phead);// 역 출력

int main(){
  FILE* fp;
  DListNode* head = (DListNode*)malloc(sizeof(DListNode));//헤드노드 생성 
  DListNode* tmp; //임시로 데이터를 입력받을 노드
  element tmpdata; // 임시 데이터 입력 받는 구조체
  int flag; //입력받는 메뉴

  init(head); // 연결 리스트 초기화

  //파일 열기
  fp = fopen("studentdata1.txt","rt");
  if(fp==NULL){
    printf("file not found\n");
    return 0;
  }

  //파일로부터 데이터 입력받아 tmp 노드에 저장 후 노드 삽입
  while(!feof(fp)){
    fscanf(fp,"%s%d%s%d", &tmpdata.name,&tmpdata.year,&tmpdata.dept,&tmpdata.age);
    tmp = (DListNode*)malloc(sizeof(DListNode));
    tmp->data = tmpdata;

    dinsert_node(head, tmp); //head에 새로 만든 tmp를 insert
  }

  //메뉴 선택하여 조건에  맞게 함수 호출
  while(1){
    printf("\n종료(0) 차례대로 출력(1) 역순 출력(2)\n");
    printf("메뉴 입력:");
    scanf("%d", &flag);

    switch(flag)
    {
      case 0:// 0인 경우 종료
      exit(1);
      break;

      case 1://차례대로 출력
      printf("\n차례대로 목록보기\n");
      printf("------------------\n");
      display(head);
      printf("------------------\n");
      exit(1);
      break;

      case 2://역 출력
      printf("\n역순으로 목록보기\n");
      printf("------------------\n");
      reversedisplay(head);
      printf("------------------\n");
      exit(1);
      break;
    
      default : break;
    }
  }
  free_node(head);
  fclose(fp);
}

void init(DListNode* phead){
  phead->llink = phead;
  phead->rlink = phead;
}


DListNode* dinsert_node(DListNode* before, DListNode* new_node){
  new_node->llink = before;
  new_node->rlink = before->rlink;

  before->rlink->llink = new_node;
  before->rlink = new_node;
}

void display(DListNode* phead){
  for (DListNode* p = phead->llink; p!=phead;p=p->llink){
    printf("%s%d%s%d \n", p->data.name, p->data.year, p->data.dept,p->data.age );
  }
}

void reversedisplay(DListNode* phead){
  for (DListNode* p = phead->rlink; p!=phead;p=p->rlink){
    printf("%s%d%s%d \n", p->data.name, p->data.year, p->data.dept,p->data.age );
  }
}

void free_node(DListNode* phead){
  DListNode* p = phead->rlink, * next;
  while (p!=phead){
    next = p;
    free(p);
    p = p->rlink;  }
}
