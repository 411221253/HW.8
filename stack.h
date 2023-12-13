#IF


typedef struck axis{
  int x;
  int y;  
} axis_t;

typedef struck stack{
  axis_t element[M_SIZE*M_SIZE];
  int top;
} stack_t;

void push(stack_t *stack, axis_t axis);
axis_t pop(stack_t *stack);
int isEmpty(stack_t *stack);



