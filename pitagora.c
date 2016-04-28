#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>


int main(int argc, char const *argv[])
{
	int squares[1000];
	for (int i = 0; i < 1000; i++) {
		squares[i] = i * i;
	}
	for (int a = 2; a < 30; a++) {
		for (int b = 2; b < 30; b++) {
			double cc = a * a + b * b;
			double c = sqrt(cc);
			if (round(c) == c) {
				printf("a=%d, b=%d, c=%.0f\n", a, b, c);
			}
		}
	}
	return 0;
}
