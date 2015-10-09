#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define N 1000

bool issorted(int *arr, size_t len)
{
	for (int i = 0; i < len - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}

void swap(int *arr, int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void partition(int *arr, size_t len, int mid)
{
	int a = 0;
	int b = 0;
	int c = len - 1;
	while (b <= c) {
		if (arr[b] < mid) {
			swap(arr, a , b);
			a++;
			b++;
		} else if (arr[b] > mid) {
			swap(arr, b, c);
			c--;
		} else {
			b++;
		}
	}
}

int main(int argc, char const *argv[])
{
	int arr[N];
	for (int i = 0; i < N; i++) { arr[i] = rand() % 3; }
	partition(arr, N, 1);
	printf("issorted=%s\n", issorted(arr, N)?"true":"false");
	return 0;
}
