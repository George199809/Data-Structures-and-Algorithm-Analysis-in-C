#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;

typedef char element_type;
struct tree_node;
typedef struct tree_node *ptr_to_node;
typedef ptr_to_node tree;

struct tree_node { //析构函数失效
	element_type element;
	tree left;
	tree right;
};


int legal(char ch) {
	if(ch >=48 && ch <=57)
		return 1;
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
		return 1;
	return 0;
}
void print(tree p) {
	if(p->element < 48 || p->element >57) {
		printf("(");
		print(p->left);
		printf("%c",p->element);
		print(p->right);
		printf(")");
	}
	else
		printf("%c", p->element);
}
int main() {
	char ch;
	stack<tree> s;
	tree temp;
	while((ch=getchar()) != EOF) { 
		if(!legal(ch))
			continue;
		temp = (tree_node *) malloc(sizeof(struct tree_node));
		temp->left = NULL;
		temp->right = NULL;
		temp->element = ch;
		if(ch < 48 || ch > 57) {
			tree t2 = s.top(); s.pop();
			tree t1 = s.top(); s.pop();
			temp->left = t1;
			temp->right = t2;
		}
		s.push(temp);
	}

	tree p = s.top();
	print(p);
	return 0;
}