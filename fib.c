#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

int32_t fib_recursive(int n)
{
	if (n < 2) return 1;
	int32_t ret = fib_recursive(n-1) + fib_recursive(n-2);
	assert(ret > 1);
	// assert(ret > 0); // does not work because of -O2
	return ret;
}

int64_t fib_memoization2(int n, int64_t *cache)
{
	if (n < 2) return 1;
	if (!cache[n-1]) {
		cache[n-1] = fib_memoization2(n-1, cache);
	}
	if (!cache[n-2]) {
		cache[n-2] = fib_memoization2(n-2, cache);
	}
	int64_t ret = cache[n-1] + cache[n-2];
	assert(ret > 0);
	return ret;
}

int64_t fib_memoization(int n)
{
	static int64_t *cache;
	if (!cache) {
		cache = calloc(100, sizeof(*cache));
	}
	int64_t ret = fib_memoization2(n, cache);
	return ret;
}

int64_t fib_dynamic(int n)
{
	if (n < 2) return 1;
	int64_t a = 1;
	int64_t b = 1;
	for (size_t i = 2; i <= n; i++) {
		int64_t s = a + b;
		a = b;
		b = s;
	}
	return b;
}

#define MAX_FIB_IN_INT32 45
#define MAX_FIB_IN_INT64 93

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 10; i++) {
		assert(fib_recursive(i) == fib_memoization(i));
		assert(fib_recursive(i) == fib_dynamic(i));
	}
	printf("fib_recursive(45)=%" PRIi32 "\n", fib_recursive(MAX_FIB_IN_INT32));
	printf("fib_memoization(93)=%" PRIi64 "\n", fib_memoization(MAX_FIB_IN_INT64));
	printf("fib_dynamic(93)    =%" PRIi64 "\n", fib_dynamic(MAX_FIB_IN_INT64));
	return 0;
}