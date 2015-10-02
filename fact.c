#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <inttypes.h>

#define MAX_FACT_IN_INT32 16
#define MAX_FACT_IN_INT64 20

int32_t fact32(int32_t n)
{
	if (n < 1) return 1;
	return n * fact32(n - 1);
}

int64_t fact64(int64_t n)
{
	if (n < 1) return 1;
	return n * fact64(n - 1);
}

int64_t fact64_tail2(int64_t n, int64_t acc)
{
	if (n < 1) return acc;
	return fact64_tail2(n - 1, n * acc);
}

int64_t fact64_tail(int64_t n)
{
	return fact64_tail2(n, 1);
}

int64_t fact64_linear(int64_t n)
{
	int64_t ret = 1;
	for (size_t i = 2; i <= n; i++) {
		ret *= i;
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	assert(fact32(MAX_FACT_IN_INT32) > 0);
	assert(fact32(MAX_FACT_IN_INT32 + 1) < 0);
	assert(fact64(MAX_FACT_IN_INT64) > 0);
	assert(fact64(MAX_FACT_IN_INT64 + 1) < 0);

	for (int64_t i = 0; i <= MAX_FACT_IN_INT64; i++) {
		assert(fact64(i) == fact64_tail(i));
		assert(fact64(i) == fact64_linear(i));
	}

	printf("All Ok.\n");
	return 0;
}