//将中缀表达式转化成后缀表达式

#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;

stack<char> s;
int is_numner(char ch) {
	if(ch >= 48 && ch <= 57)
		return 1;
	return 0;
}
int level(char ch) {
	switch (ch) {
		case '(': return 0;
		case '-': return 1;
		case '+': return 1;
		case '*': return 2;
		case '/': return 2;
		case ')': return 3;
	}
}
void func(char ch) {
	if(level(ch) > 0 && level(ch) < 3) {
		while(!s.empty()) {
			if(level(s.top()) < level(ch)) 
				break;
			printf("%c", s.top());
			s.pop();
		}
	}
	if(level(ch) == 3) {
		while(!s.empty()) {
			if(level(s.top()) == 0) {
				s.pop();
				break;
			}
			printf("%c", s.top());
			s.pop();
		}
	}
	if(level(ch) == 0) {
		while(!s.empty()) {
			if(level(s.top()) == 0) {
				break;
			}
			printf("%c", s.top());
			s.pop();
		}
	}
	if(level(ch) != 3)
		s.push(ch);
}

int main() {
	char ch[30];

	scanf("%s", ch);
	for(int i = 0; i < strlen(ch); i++) { //No ch.strlen()
		 {
			if(is_numner(ch[i]))
				printf("%c", ch[i]);
			else
				func(ch[i]);
		}
	}
	while(!s.empty()) {
		printf("%c", s.top());
		s.pop();
	}

	return 0;
}