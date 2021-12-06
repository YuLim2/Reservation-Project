#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Order{
   int order;
   struct Order *nextorder;
}Order;

typedef struct {
   Order * head;
}OrderHead;

OrderHead *createorderhead();
void freeorderhead(OrderHead *orderhead);
void printorder(OrderHead *orderhead);
void delorder(OrderHead *orderhead, int s_num);
void insertorder(OrderHead *orderhead, int s_num);
void searchorder(OrderHead *orderhead, int s_num);

int main(){
  int Todo, s_num;
   OrderHead *orderhead;
   orderhead = createorderhead();
   while(1) {
    printf("\n세탁기 예약 프로그램!\n원하시는 서비스의 번호를 입력해주세요!\n\n");
    printf("\n1. 예약하기\n");
    printf("2. 확인하기\n");
    printf("3. 완료 체크하기\n");
    printf("4. 모두보기\n");
    printf("5. 프로그램 종료하기\n\n");

    scanf("%d", &Todo);

    if (Todo == 1) {
      printf("\n학번을 입력해주세요.\n");
      scanf("%d", &s_num);
      insertorder(orderhead, s_num);
    }
    else if (Todo == 2) {
      printf("\n찾으시고자 하시는 학번을 입력해주세요.\n");
      scanf("%d", &s_num);
      searchorder(orderhead, s_num);
    }

    else if (Todo == 3) {
      printf("\n제거하고자 하시는 학번을 입력해주세요.\n\n");
      scanf("%d", &s_num);
      delorder(orderhead, s_num);
    }

    else if (Todo == 4) {
      printorder(orderhead);
    }

    else if (Todo == 5) {
      return 0;
    }

    else {
      printf("\n다시 입력해주세요.\n");
    }
  }
   return 0;
}

OrderHead *createorderhead(){
   OrderHead* orderhead;
   orderhead = (OrderHead*)malloc(sizeof(OrderHead));
   orderhead -> head = NULL;
   return orderhead;
}

void freeorderhead(OrderHead *orderhead){
   Order* temp;
   while (orderhead -> head != NULL) {
      temp = orderhead -> head;
      orderhead -> head = orderhead -> head -> nextorder;
      free(temp);
      temp = NULL;
   }
}

void printorder(OrderHead *orderhead){
   Order* temp;
   temp = orderhead -> head;
    printf("현재 순서: ");
   while (temp != NULL) {
      printf ("%d", temp -> order);
      temp = temp -> nextorder;
      if (temp != NULL) printf (" -> ");
   }
  printf("\n");
}

void delorder(OrderHead *orderhead, int s_num){
  Order *temp;
  if (orderhead -> head -> order == s_num) {
    temp = orderhead -> head;
    orderhead -> head = temp -> nextorder;
    free(temp);
    return ;
  }

   Order *temp2, *del;
   temp = orderhead -> head;
  temp2 = NULL;
   while (temp != NULL) {
      if (temp -> order == s_num) {
      del = temp;
      temp2 -> nextorder = temp -> nextorder;
      free(del);
      return ;
    }
    temp2 = temp;
    temp = temp -> nextorder;
   }
  printf("\n찾으시는 학번 %d번은 없습니다.\n", s_num);
}

void insertorder(OrderHead *orderhead, int s_num){
  Order *order;
   order = (Order*)malloc(sizeof(order));
   order -> order = s_num;
  order -> nextorder = NULL;
  if (orderhead -> head == NULL) {
    orderhead -> head = order;
    return ;
  }
   Order *temp;
  temp = orderhead -> head;
   while(temp -> nextorder != NULL) {
    temp = temp -> nextorder;
  }
  temp -> nextorder = order;
}

void searchorder(OrderHead *orderhead, int s_num){
  int i = 1;
   Order *temp;
   temp = orderhead -> head;
   while (temp != NULL) {
      if (temp -> order == s_num) {
      printf("\n학번 %d번의 %d번째 입니다.\n\n", s_num, i);
      return ;
    }
      temp = temp -> nextorder;
    i++;
   }
   printf("\n학번 %d번은 없습니다.\n\n", s_num);
}
