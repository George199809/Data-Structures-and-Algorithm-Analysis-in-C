#include <stdio.h>
#define MAXN 100 + 10

typedef int element_type;
typedef element_type ptr_to_node;
typedef ptr_to_node list;
typedef ptr_to_node position;

struct node {
	element_type element;
	position next;
};

struct node cursor_space[MAXN];

void initialize_cursor_space();
position cursor_alloc();
void cursor_free();
list create_list();
int is_empty(list l);
int is_last(position p);
position find(list l, element_type x);
position find_previous(list l, element_type x);
void insert(position p, element_type x);
void remove(list l, element_type x);
void print_list(list l);




void initialize_cursor_space() {
	for(int i = 0; i < MAXN; i++) {
		cursor_space[i].next = i+1;
	}
	cursor_space[MAXN-1].next = 0;
}

position cursor_alloc() {
	position p;

	p = cursor_space[0].next;
	cursor_space[0].next = cursor_space[p].next;
	cursor_space[p].next = 0;
	
	return p;
}
void cursor_free(position p) {
	p = cursor_space[0].next;
	cursor_space[0].next = p;
}

list create_list() {
	list l;
	
	l = cursor_alloc();
	if(l == 0) printf("Out of Space !!\n");

	return l;
}

int is_empty(list l) {
	return cursor_space[l].next == 0;
}

int is_last(position p) {
	return cursor_space[p].next == 0;
}

position find(list l, element_type x) {
	position p;

	p = cursor_space[l].next;
	while(!is_last(p) && cursor_space[p].element!=x) 
		p = cursor_space[p].next;

	return p;
}

position find_previous(list l, element_type x) {
	position p;

	p = cursor_space[l].next;
	while(!is_last(p) && cursor_space[p].element!=x)
		p = cursor_space[p].next;

	return p;
}

void insert(position p, element_type x) {
	position temp;

	temp = cursor_alloc();
	if(temp == 0) printf("Out of Space !!\n");
	cursor_space[temp].element = x;
	cursor_space[temp].next = cursor_space[p].next;
	cursor_space[p].next = temp;

}

void remove(list l, element_type x) {
	position p, temp;

	p = find_previous(l,x);
	if(!is_last(temp)) {
		p = cursor_space[p].next;
		cursor_free(temp);
	}
	else
		printf("Illigal Data !!\n");
}

void print_list(list l) {
	position p;

	p = cursor_space[l].next;
	while(!is_last(p)) {
		printf("%d\t", cursor_space[p].element);
		p = cursor_space[p].next;
	}
	printf("%d\n", cursor_space[p].element);
}




int main() {
	list l, l2;
	position p;

	initialize_cursor_space();
	l = create_list();
	insert(l,1);
	insert(l,2);
	print_list(l);
	p = find_previous(l,1);
	insert(p,0);
	print_list(l);

	l2 = create_list();
	insert(l2,1);
	print_list(l2);

	return 0;
}