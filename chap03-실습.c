#include <stdio.h>

int main(){
  char c='A';
  int i=0;

  for(i=0;i<26;i++){
    printf("%c\n ",c++);
  }

  return 0;

}


#include <stdio.h>

int main(){
  char c='A';
  int i=0;

  for(i=0;i<26;i++){
    printf("%c %d\n ",c,c++);
  }

  return 0;

}

#include <stdio.h>

int main(){
  char c='0';
  int i=0;

  for(i=0;i<10;i++){
    printf("%c\n ",c++);
  }

  return 0;

}

#include <stdio.h>

int main(){

  int i=0,j;

  for(j=0;j<10;j++){
    i+=5;
    printf("%d\n ",i);
  }

  return 0;

}


#include <stdio.h>

int main(){

  int i=0,k=0,j;

  for(j=0;j<10;j++){
    i+=5;
    k=k+i;
    printf("%d %d\n ",i,k);
  }

  return 0;

}