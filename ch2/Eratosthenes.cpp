#include <stdio.h>
#include <string.h>
#include <math.h>
#define maxn 100000+5
int is_prime[maxn]; // 1:is prime.
int n;

void Eratosthenes() {
    memset(is_prime,1,sizeof(is_prime));
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) printf("%d\n", i);
        for(int j = i*i; j <= n; j += i) {
            is_prime[j] = 0;
        }
    }
}

/*
void Eratosthenes() {
    memset(is_prime,1,sizeof(is_prime));
    int m = floor(n+0.5);
    for(int i = 2; i <= m; i++) {
        if(is_prime[i]) printf("%d\n", i);
        for(int j = 2*i; j <= n; j += i) {
            is_prime[j] = 0;
        }
    }
}
*/

// Are the two functions different?

int main() {
    n = 1232;
    Eratosthenes();
    return 0;
}