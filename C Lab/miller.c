#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long power(long long a, long long d, long long n) {
    long long res = 1;
    a %= n;
    while (d > 0) {
        if (d & 1)
            res = (res * a) % n;
        d >>= 1;
        a = (a * a) % n;
    }
    return res;
}

int millerTest(long long d, long long n) {
    long long a = 2 + rand() % (n - 4);
    long long x = power(a, d, n);

    if (x == 1 || x == n - 1)
        return 1;

    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;
        if (x == 1)
            return 0;
        if (x == n - 1)
            return 1;
    }
    return 0;
}

int isPrime(long long n, int k) {
    if (n <= 1 || n == 4)
        return 0;
    if (n <= 3)
        return 1;

    long long d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
        if (!millerTest(d, n))
            return 0;

    return 1;
}

int main() {
    long long n;
    int k;
    scanf("%lld%d", &n, &k);
    srand(time(0));
    if (isPrime(n, k))
        printf("Probably Prime\n");
    else
        printf("Composite\n");
    return 0;
}bfs.c
