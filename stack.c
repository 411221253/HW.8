#include "stack.h"


void push(stack_t *stackPtr, axis_t element){
  if(isFULL(stackPtr))
    return;
    
  stackPtr->top++;
  stackPtr->elements[stackPtr->top] = element;
}

axis_t pop(stack_t *stackPtr){
  axis_t temp = {-1,-1};
  if(isEmpty(stackPtr))
    return temp;
  return stackPtr->elements[stackPtr->top--];//等同下三行
  //temp = stackPtr->elements[stackPtr->top];
  //stackPtr->top--;
  //return temp;
}

//判斷是否為空
int isEmpty(stack_t *stackPtr){
  if(stackPtr->top == -1)
    return 1;
  return 0;
}

//判斷是否滿了
int isFULL(stack_t *stackPtr){
  if(top)
}
