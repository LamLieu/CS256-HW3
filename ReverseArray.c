#include <stdio.h>

int * ReverseArray(int *array, int *newArray, int arraySize);

int * ReverseArray(int *arrayptr, int *newArrayptr, int arraySize) {
	for (int oldIndex = 0; oldIndex < arraySize; oldIndex++) {
		int newIndex = arraySize - 1;
		int arrayContent = *(arrayptr + oldIndex);
		*(newArrayptr + newIndex) = arrayContent;
		newIndex--;
	}

	return newArrayptr;
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

	int *newArrayPTR = ReverseArray(&array[0], &newArray[0], arraySize);

	return 0;
}
