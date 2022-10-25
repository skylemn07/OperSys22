#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Input N, size of array:\n");
	int n; scanf("%d", &n);
	
	if (n < 0)
		printf("N must be non-negative\n");
	
	int* arr = (int*)(malloc(sizeof(int) * n));
	
	for (int i = 0; i < n; ++i)
		arr[i] = i;
	
	printf("The array: ");
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	
	free(arr);
	
	return 0;
}

