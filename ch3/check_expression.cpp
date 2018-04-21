#include <stdio.h>
#include <string.h>
#define maxn 100+10

int top_of_stack = -1;
char stack[maxn];

void judge(char ch) {
	switch(ch) {
		case ')': if(stack[top_of_stack--] != '(') printf("Error !\n");
			break;
		case ']': if(stack[top_of_stack--] != '[') printf("Error !\n");
			break;
		case '}': if(stack[top_of_stack--] != '{') printf("Error !\n");
			break;
	}
}

int main() {
	int ch;

	while((ch=getchar()) != EOF) {
		if(ch=='(' || ch=='[' || ch=='{') {
			stack[++top_of_stack] = ch;
		}
		else if(ch==')' || ch==']' || ch=='}') {
			if(top_of_stack == -1) {
				printf("Error !\n");
				break;
			}	
			judge(ch);

		}
	} 
	if(top_of_stack != -1) printf("Error !");

	return 0;
}