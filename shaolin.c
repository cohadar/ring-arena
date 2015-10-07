#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define JUMP_UP 3
#define JUMP_DOWN 4

int solvable(int n, int k, bool print)
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
	// jump up k times
	for (int i = 0; i < k; i++) {
		c += JUMP_UP;
		tc++;
		if (print) printf("tc=%d c=%d\n", tc, c);
	}
	if (c >= n + JUMP_UP) return 0;
	if (c > n) c = n;
	if (print) printf("############\n");
	// jump all the way down
	while (c > 0) {
		c -= JUMP_DOWN;
		tc++;
		if (print) printf("tc=%d c=%d\n", tc, c);
	}
	c = 0;
	if (print) printf("############\n");
	// jump all the way up
	while (c < n) {
		c += JUMP_UP;
		tc++;
		if (print) printf("tc=%d c=%d\n", tc, c);
	}
	return tc;
}

#define N 99
#define K 15

static int m[200][200];

void search_space()
{
	for (int n = 1; n <= N; n++) {
		for (int k = 5; k <= K; k++) {
			int tc = solvable(n, k, false);
			if (tc > 0 && tc == 30) {
				printf("k=%02d, tc=%02d, n=%d\n", k, tc, n);
				m[k][tc]++;
			}
		}
	}
	for (int i=0; i<200; i++) {
		for (int j=0; j<200; j++) {
			if (m[i][j] == 1) {
				printf("k=%02d, tc=%02d\n", i, j);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	// search_space();
	solvable(33, 6, true);
	return 0;
}