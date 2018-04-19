#include <stdio.h>

int * ReverseArray(int *array, int *newArray, int arraySize);

int * ReverseArray(int *array, int *newArray, int arraySize) {
	for (int oldIndex = 0; oldIndex < arraySize; oldIndex++) {
		int newIndex = arraySize - 1;
		*(newArray + newIndex) = *(array + oldIndex);
	}

	return newArray;
}

int main() {
	int arraySize = 0;

	printf("Please enter the array size: ");
	fflush(stdout);
	scanf("%d", &arraySize);

	int array[arraySize];
	int newArray[arraySize];

	for (int i = 0; i < arraySize; i++) {
		printf("Please enter element %d: ", i);
		fflush(stdout);
		scanf("%d", &array[i]);
	}

	int *newArrayPTR = ReverseArray(&array, &newArray, arraySize);
	printf("%d, %d, %d, %d, %d", newArray[0], newArray[1], newArray[2], newArray[3], newArray[4]);
	return 0;
}
