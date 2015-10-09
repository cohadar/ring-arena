/*
 * Longest Common Substring
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>

char* malloc4_lcs(const char *a, const char *b)
{
	assert(a);
	assert(b);
	size_t la = strlen(a);
	size_t lb = strlen(b);
	size_t ll = (la < lb) ? la : lb;
	char *ret = calloc(1, ll + 1);
	assert(ret);
	return ret;
}

size_t max3(size_t a, size_t b, size_t c) {
	if (b > a) {
		return (c > b) ? c : b;
	} else {
		return (c > a) ? c : a;
	}
}

size_t lcs(char *c, const char *a, const char *b)
{
	size_t *m[2];
	size_t la = strlen(a);
	size_t lb = strlen(b);
	m[0] = calloc(lb + 1,  sizeof(*m[0]));
	m[1] = calloc(lb + 1,  sizeof(*m[1]));
	for (int yy = la - 1; yy >= 0; yy--) {
	for (int x = lb - 1; x >= 0; x--) {
		size_t y = yy % 2;
		size_t y1 = (yy + 1) % 2;
		m[y][x] = max3(
			(a[yy] == b[x]) + m[y1][x+1],
			m[y][x+1],
			m[y1][x]
		);
	}
	}
	size_t ret = m[0][0];
	size_t v = ret;
	size_t i = 0;
	size_t j = 0;
	for (int d = 0; d < lb; d++) {
		printf("%zd", m[0][d]);
	}
	printf("\n");
	while (v > 0) {
		while (m[0][i] == v) i++;
		c[j++] = b[i-1];
		v--;
	}
	c[j] = 0;
	free(m[0]);
	free(m[1]);
	return ret;
}

int main(int argc, char const *argv[])
{
	char *x = "ABCBDAB";
	char *y = "BDCABC";
	char *z = malloc4_lcs(y, x);
	size_t len = lcs(z, y, x);
	printf("'%s', %zd\n", z, len);
	free(z);
	return 0;
}