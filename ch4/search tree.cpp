//C无引用，所以一般用返回类型来修改参数
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef int element_type;
typedef struct node *position;
typedef struct node *tree;
struct node {
	element_type element;
	tree left;
	tree right;
};
position find(element_type x, tree t) {
	while(t != NULL && t->element != x) {
		if(x < t->element)
			t = t->left; 
		else
			t = t->right;
	}
	return t;
}

position find_previous(element_type x, tree t) {
	position p;

	while(t != NULL && t->element != x) {
		p = t;
		if(x < t->element)
			t = t->left;
		else
			t = t->right;
	}
	return p;	
}

position find_min(tree t) {
	while(t != NULL && t->left != NULL)
		t = t->left;
	return t;
}

position find_max(tree t) {
	while(t != NULL && t->right != NULL)
		t = t->right;
	return t;
}

position insert(element_type x, tree t) {
	if(t == NULL) {
		t = (struct node*)malloc(sizeof(struct node));
		if(t == NULL)
			printf("Out of Space !\n");
		else {
			t->element = x;
			t->left = t->right = NULL;
		}
	}
	else
	if(x < t->element)
		t->left = insert(x,t->left);
	else
	if(x > t->element)
		t->right = insert(x,t->right);

	return t;

}

int child_number(position p) {
	int n;

	n = 0;
	if(p->left != NULL)
		n++;
	if(p->right != NULL) 
		n++;
	return n;
}
/*
void remove(element_type x, tree t) {
	position p, rear, front;

	p = find(x,t);
	if(p == NULL) {
		printf("Illegal Operation!\n");
		return ;
	}
	if(child_number(p) == 0) {
		front = find_previous(x,t);
		if(x < front->element)
			front->left = NULL;
		else
			front->right = NULL;
		free(p);
	}
	else
	if(child_number(p) == 1) {
		front = find_previous(x,t);
		if(p->left != NULL)
			rear = p->left;
		else
			rear = p->right;
		if(x < front->element)
			front->left = rear;
		else
			front->right = rear;
		free(p);
	}
	else
	if(child_number(p) == 2){
		rear = p;
		while(rear->left != NULL) {
			front = rear;
			rear = rear->left;
		}
		p->element = rear->element;
		front->left = NULL;
		free(rear);

	}
}*/
/* 用递归写remove ，以增加少量风险来增加代码可读性。*/
//key point:利用返回类型。
position remove(element_type x, tree t) {
	position temp;

	if(t == NULL)
		printf("Illegal Operation !\n");
	else
	if(x < t->element) 
		t->left = remove(x,t->left);
	else
	if(x > t->element)
		t->right = remove(x,t->right);
	else
	if(t->left && t->right) {
		temp = find_min(t->right);
		t->element = temp->element;
		t->right = remove(temp->element,t->right);
	}
	else
	if(t->left == NULL || t->right == NULL) {
		temp = t;
		if(t->left)
			t = t->left;
		else
			t  = t->right;
		free(temp);
	}

	return t;
}

void print(tree t) {
	if(t == NULL)
		return ;
	print(t->left);
	//printf("!");
	printf("%d ", t->element);
	print(t->right);

	return ;
}


int main() {
	tree t;
	t = NULL;
	t = insert(4,t);
	insert(8,t);
	insert(2,t);
	insert(1,t);
	t = remove(2,t);
	print(t);
}