#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;

stack<int> s;
int is_number(char ch) {
	if(ch >= 48 && ch <= 57)
		return 1;
	return 0;
}

void func(char ch) {
	int a = s.top(); s.pop();
	int b = s.top(); s.pop();
	int c;
	switch (ch) {
		case '+': c = b + a;
			break;
		case '-': c = b - a;
			break;
		case '*': c = b * a;
			break;
		case '/': c = b / a;
			break;
	}
	s.push(c);
}
int main() {
	char a[30];

	scanf("%s", &a);
	for(int i = 0; i < strlen(a); i++) {
		if(is_number(a[i]))
			s.push((int)a[i]-48);
		else {
			func(a[i]);
		}
	}
	printf("%d\n", s.top());

	return 0;
}