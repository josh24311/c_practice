/*
LC10_minstack
實作一資料結構Stack，且實作出求該Stack內最小值的函式
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
  //int data[100];
  int* data;
  int size; 
} MinStack;
MinStack* minStackCreate(){
  MinStack* s = malloc(sizeof(MinStack));
  s->data = NULL;
  s->size = 0;
  return s;
}
void minStackPush(MinStack* obj, int x){
  obj->data = realloc(obj->data, sizeof(int)*(obj->size+1));
  obj->data[obj->size] = x;
  obj->size++;
}
void minStackFree(MinStack* obj){
  free(obj->data);
  free(obj);
}

void minStackPop(MinStack* obj){
  obj->size--;
}
int minStackTop(const MinStack* obj){
  return obj->data[obj->size-1];
}
int minStackGetMin(MinStack* obj){
  int min  = obj->data[0];
  for(int i = 1 ; i < obj->size; i++){
    if(obj->data[i] < min){
      min = obj->data[i];
    }
  }
  return min;
}
void PrintStack(const MinStack* s){
  for(int i = 0 ; i < s->size; i++){
    printf("%d ",s->data[i]);
  }
  printf("\n");
}
int main() {
  //Stack s;
  MinStack *s = minStackCreate();
  
  minStackPush(s,10);
  PrintStack(s);
  minStackPush(s,20);
  PrintStack(s);
  minStackPush(s,5);
  PrintStack(s);
  minStackPush(s,30);
  PrintStack(s);
  minStackPop(s);
  PrintStack(s);

  
  printf("Top is %d\n",minStackTop(s));
  printf("Min is %d\n",minStackGetMin(s));
  minStackCreate(s);
  return 0;
}
