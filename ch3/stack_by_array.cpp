#include <stdio.h>
#include <malloc.h>

#define empty_tos -1;
struct node;
typedef struct node *stack;
typedef int element_type;


struct node {
    int capacity;
    int top_of_stack;
    element_type *array;
};
stack create_stack() {
    stack s;

    s = (node*)malloc(sizeof(struct node));
    if(s == NULL) printf("Out of Space !!\n");
    printf("Input the capacity: \n");
    scanf("%d", &s->capacity);
    s->array = (element_type*) malloc(s->capacity*sizeof(element_type));
    s->top_of_stack = -1;

    return s;
}

void dispose_stack(stack s) {
    if(s != NULL) {
        free(s->array);
        free(s);
    }
}

int is_empty(stack s) {
    return s->capacity == empty_tos;
}

int is_full(stack s) {
    return s->top_of_stack == s->capacity-1;
}

void push(stack s, element_type x) {
    if(is_full(s)) 
        printf("Out of Space !!\n");
    else
        s->array[++s->top_of_stack] = x;
}

element_type pop(stack s) {
    element_type x;

    if(is_empty(s)) {
        printf("Illegal operation !!\n");
        x = -1;
    }
    else
        x = s->array[s->top_of_stack--];
    
    return x;
}

element_type top(stack s) {
    return s->array[s->top_of_stack];
}



int main() {
    stack s;
    element_type x;

    s = create_stack();
    while(scanf("%d", &x) == 1)
        push(s,x);
    printf("No.1: %d\n", top(s));
    pop(s);
    printf("No.2: %d\n", top(s));

    return 0;
}