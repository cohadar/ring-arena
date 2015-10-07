/*
 * Problem: given n
 * find the number of different ways to write n
 * as the sum of 1, 3, 4
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <assert.h>

int diffrec(int n)
{
	static int base[] = {0, 1, 1, 2, 4};
	if (n <= 4) {
		return base[n];
	}
	return diffrec(n - 1) + diffrec(n - 3) + diffrec(n - 4);
}

int diffdp(int n) {
	static int base[] = {0, 1, 1, 2, 4};
	int *arr = malloc((n + 1) * sizeof(*arr));
	for (size_t i = 0; i < 5; i++) {
		arr[i] = base[i];
	}
	for (int i = 5; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 3] + arr[i - 4];
	}
	int ret = arr[n];
	free(arr);
	return ret;
}

int imod5(i) {
	return i % 5;
}

int diffdpc(int n) {
	int arr[] = {0, 1, 1, 2, 4};
	for (int i = 5; i <= n; i++) {
		arr[imod5(i)] = arr[imod5(i - 1)] + arr[imod5(i - 3)] + arr[imod5(i - 4)];
	}
	return arr[imod5(n)];
}

 int main(int argc, char const *argv[])
 {
 	for (size_t i = 0; i < 30; i++) {
 		int d = diffrec(i);
 		printf("%d\n", d);
 		assert(d == diffdp(i));
 		assert(d == diffdpc(i));
 	}
 	return 0;
 }