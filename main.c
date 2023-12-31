#include <stdio.h>
#include <stack.h>
#include "stack.h"

#define MAX_N 10


char maze[MAX_N][MAX_N] ={
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 0, 0, 0, 1, 1, 0, 1, 1, 0, 1 },
  { 1, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
  { 1, 1, 1, 0, 1, 1, 0, 1, 1, 1 },
  { 1, 0, 1, 1, 1, 0, 0, 1, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
  { 1, 0, 1, 1, 1, 1, 1, 0, 0, 1 },
  { 1, 0, 0, 0, 1, 0, 0, 0, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};
char mark[9][9] = {0};

axis_t findMove(stack_t *stackPtr, axis_t position){
  for(int dx = -1;dx <= 1;dx++){
    for(int dy = -1;dy <= 1;dy++){
      if((dx == -1 || dx == 1) && (dy == -1||dy == 1))
        continue;
      else if(!(dx == 0 && dy == 0))
        axis_t space;
        space.x = position.x + dx;
        space.y = position.y + dy;
        //check
        if(mesh[space.x][space.y] == 0 && mark[space.x][space.y] != '*')
          mark[space.x][space.y] = '*';
          push(stackPtr, space);
    }
  }
  return pop(stackPtr);
}

int main(){
  stack_t myStack;
  axis_t current_position;
  axis_t entry = {1,1};
  axis_t out = {7,7};
  axis_t no_exit = {-1,-1};
  
  myStack.pop = -1;
  current_position = entry;
  mark[current_position.x][current_position.y] = '*';
  
  while(!EQU(current_position,out)){
    current_position = findMove(&myStack, current_position);
    if(EQU(current_position,no_exit))
      printf("no Exit axis!!\n");
      break;
    printf("move to %d, %d\n", current_position.x, current_position.y);
  }
}

