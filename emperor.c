#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

double comb(int n, int k)
{
	if (n < k) return 0.0;
	if (k == 1) return n;
	if (k == 2) return n * (n - 1) / 2.0;
	if (k == 3) return n * (n - 1) * (n - 2) / 6.0;
	assert(0);
	return 0.0;
}

double two_black(int w, int b, int r)
{
	return comb(b, 2) * comb(w + r, 1) / comb(w + b + r, 3);
}

// you die if 3 white or 2 red or 1 black
double survive(int w, int b, int r)
{
	assert(w + b + r >= 3);
	double tc = comb(w + b + r, 3);
	return 1.0 - (comb(w, 3) + comb(r, 2) * comb(b + w, 1) / tc + comb(b, 1) * comb(w + r, 2) / tc) / tc;
}

double life_chance(int w1, int b1, int r1, int w2, int b2, int r2, int w3, int b3, int r3)
{
	return (survive(w1, b1, r1) + survive(w2, b2, r2) + survive(w3, b3, r3)) / 3.0;
}

static double m[100][100];

// TODO: vaza struct
void search_subspace(int w, int b, int r)
{
	for (int w1 = 0; w1 <= w; w1++) {
	for (int w2 = 0; w2 <= w - w1; w2++) {
			int w3 = w - w1 - w2;
			assert(w1 + w2 + w3 == w);
			for (int b1 = 0; b1 <= b; b1++) {
			for (int b2 = 0; b2 <= b - b1; b2++) {
				int b3 = b - b1 - b2;
				assert(b1 + b2 + b3 == b);
				for (int r1 = 0; r1 <= r; r1++) {
				for (int r2 = 0; r2 <= r - r1; r2++) {
					int r3 = r - r1 - r2;
					assert(r1 + r2 + r3 == r);
					if (w1 + b1 + r1 != w) continue;
					if (w2 + b2 + r2 != w) continue;
					if (w3 + b3 + r3 != w) continue;
					if (w1 == 2) continue; // asshole king
					if (w2 < w1) continue;
					if (w3 < w2) continue;
					double p = life_chance(w1, b1, r1, w2, b2, r2, w3, b3, r3);
					//if (p > m[w][b]) {
						m[w][b] = p;
						printf("wbr=3*%02d, p=%.6lf, (%d, %d, %d), (%d, %d, %d), (%d, %d, %d)\n", w, p, w1, b1, r1, w2, b2, r2, w3, b3, r3);
					//}
				}
				}
			}
			}
	}
	}
}

void search_space(void)
{
	for (int c = 3; c <= 21; c += 3) {
		search_subspace(c, c, c);
	}
}

int main(int argc, char const *argv[])
{
	// search_space();
	search_subspace(6, 6, 6);
	return 0;
}