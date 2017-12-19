#include <stdio.h>

void counting_sort(int *input, int k, int n)
{
	int inc, output[99], count[100];
	
	for (inc = 0; inc <= k; inc++)
		count[inc] = 0;
	for (inc = 1; inc <= n; inc++)
		count[input[inc]] = count[input[inc]] + 1;
	for (inc = 1; inc <= k; inc++)
		count[inc] = count[inc] + count[inc - 1];
	for (inc = n; inc >= 1; inc--)
	{
		output[count[input[inc]]] = input[inc];
		count[input[inc]] = count[input[inc]] - 1;
	}

	printf("The sorted array: \n");
	for (inc = 1; inc <= n; inc++)
		printf("%d ", output[inc]);
}

int main()
{
	int n, k = 0, inc, input[99];
	printf("Enter the number of inputs: ");
	scanf_s("%d", &n);
	printf("\nEnter the numbers: \n");
	for (inc = 1; inc <= n; inc++)
	{
		scanf_s("%d", &input[inc]);
		if (input[inc] > k) 
		{
			k = input[inc];
		}
	}
	counting_sort(input, k, n);
	printf("\n");
	return 0;
}