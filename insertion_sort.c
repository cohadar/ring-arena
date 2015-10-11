#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void insertion_sort(char *x, size_t n)
{
	for (int j = 1; j < n; j++) {
		char t = x[j];
		int i = j;
		while (i > 0 && x[i-1] > t) {
			x[i] = x[i-1];
			i--;
		}
		x[i] = t;
	}
}

int main(int argc, char const *argv[])
{
	char c[] = "mighty cohadar";
	insertion_sort(c, strlen(c));
	printf("%s\n", c);
	return 0;
}