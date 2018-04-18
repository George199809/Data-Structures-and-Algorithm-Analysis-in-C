#include <stdio.h>
#include <stdlib.h>

struct node;
typedef int element_type;
typedef struct node *ptr_to_node;
typedef ptr_to_node position;
typedef ptr_to_node stack;


//prototype
int is_empty(stack s);
void push(stack s, element_type x);
element_type pop(stack s);
element_type top(stack s);
stack create_stack();
void make_empty(stack s);



struct node {
	element_type element;
	ptr_to_node next;
};

int is_empty(stack s) {
	return s->next == NULL;
}
void push(stack s, element_type x) {
	position p; // typedef struct node* position
	
	p = (node *)malloc(sizeof(struct node));
	if(p == NULL) printf("Out of Space !!\n");
	else {
		p->element = x;
		p->next = s->next;
		s->next = p;
	}
}

element_type pop(stack s) {
	position p;
	element_type temp;

	if(is_empty(s)) printf("Illegal operation !!\n");
	p = s->next;
	s->next = s->next->next;
	temp = p->element;
	free(p);

	return temp;
}

element_type top(stack s) {
	element_type temp;

	temp = s->next->element;

	return temp;
}

stack create_stack() {
	stack s;

	s = new node;
	if(s == NULL) printf("Out of Space !!\n");
	else s->next = NULL;

	return s;
}

void make_empty(stack s) {
	while(!is_empty(s))
		pop(s);
	s->next = NULL;
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