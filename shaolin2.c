#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define JUMP_UP 3
#define JUMP_DOWN 4

int solvable(int n, bool print)
{
	int c = n;
	int tc = 0;
	if (print) printf("tc=%d c=%d\n", tc, c);
	if (print) printf("############\n");
	// jump down until cross half
	while (c > n / 2) {
		c -= JUMP_DOWN;
		tc++;
		if (print) printf("tc=%d c=%d\n", tc, c);
	}
	if (c <= 0-JUMP_DOWN) return 0;
	if (print) printf("############\n");
	// jump up until on top
	while (c < n) {
		c += JUMP_UP;
		tc++;
		if (print) printf("tc=%d c=%d\n", tc, c);
	}
	if (c > n) {
		if (print) printf("c=%d->%d\n", c, n);
		c = n;
	}
	if (print) printf("############\n");
	// jump all the way down
	while (c > 0) {
		c -= JUMP_DOWN;
		tc++;
		if (print) printf("tc=%d c=%d\n", tc, c);
	}
	if (c < 0) {
		if (print) printf("c=%d->0\n", c);
		c = 0;
	}
	if (print) printf("############\n");
	// jump all the way up
	while (c < n) {
		c += JUMP_UP;
		tc++;
		if (print) printf("tc=%d c=%d\n", tc, c);
	}
	if (c > n) {
		if (print) printf("c=%d->%d\n", c, n);
		c = n;
	}
	return tc;
}

#define N 99
#define K 15

static int m[200];
static int nn[200];

void search_space()
{
	for (int n = 1; n <= N; n++) {
		int tc = solvable(n, false);
		if (tc > 0) {
			// printf("tc=%02d, n=%d\n", tc, n);
			m[tc]++;
			nn[tc] = n;
		}
	}
	for (int i=0; i<200; i++) {
		if (m[i] == 1) {
			printf("n=%d, tc=%02d\n", nn[i], i);
		}
	}
}

int main(int argc, char const *argv[])
{
	// search_space();
	solvable(40, true);
	return 0;
}