#include <stdio.h>
int main(){
  int tax;

  printf("과세 표준 금액을 입력하시오 (단, 단위는 만원입니다.) :\n");
  scanf("%d",&tax);

  if(tax<=1200){
    printf("근로소득세 금액 : %f만원 입니다.\n",0.06*tax);}
  else if(tax>1200 && tax <=4600){
    printf("근로소득세 금액 : %f만원 입니다.\n",72 + 0.15*tax);}
  else if(tax>4600 && tax <=8800){
    printf("근로소득세 금액 : %f만원 입니다.\n",582 + 0.24*tax);}
  else if(tax>8800 && tax <=15000){
    printf("근로소득세 금액 : %f만원 입니다.\n",1590 + 0.35*tax);}
  else if(tax>15000 && tax <=30000){
    printf("근로소득세 금액 : %f만원 입니다.\n",3760 + 0.38*tax);}
  else if(tax>30000 && tax <=50000){
    printf("근로소득세 금액 : %f만원 입니다.\n",9460 + 0.4*tax);}
  else if(tax>50000){
    printf("근로소득세 금액 : %f만원 입니다.\n",17460 + 0.42*tax);}

  return 0;
}