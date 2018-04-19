#include <stdio.h>

double areaCircle(int radius);
int areaRectangle(int length, int width);
double areaTriangle(int base, int height);

double areaCircle(int radius) {
	return 3.14159 * radius * radius;
}

int areaRectangle(int length, int width) {
	return length * width;
}

double areaTriangle(int base, int height) {
	return .5 * base * height;
}

int main() {
	int areaInt, length, width;
	double areaDouble, radius, base, height;
	int choice;

	printf("Geometry Calculator\n");
	printf("\n\t1. Calculate the Area of a Circle\n");
	printf("\t2. Calculate the Area of a Rectangle\n");
	printf("\t3. Calculate the Area of a Triangle\n");
	printf("\t4. Quit\n");
	printf("\nEnter your choice (1-4): ");
	fflush(stdout);
	scanf("%d", &choice);

	switch(choice) {
	case 1:
		printf("Please enter the radius: ");
		fflush(stdout);
		scanf("%lf", &radius);
		areaDouble = areaCircle(radius);
		printf("\nThe area is %.2f", areaDouble);
		break;
	case 2:
		printf("Please enter the length: ");
		fflush(stdout);
		scanf("%d", &length);
		printf("\nPlease enter the width: ");
		fflush(stdout);
		scanf("%d", &width);
		areaInt = areaRectangle(length, width);
		printf("\nThe area is %d", areaInt);
		break;
	case 3:
		printf("Please enter the base: ");
		fflush(stdout);
		scanf("%lf", &base);
		printf("\nPlease enter the height: ");
		fflush(stdout);
		scanf("%lf", &height);
		areaDouble = areaTriangle(base, height);
		printf("\nThe area is %.2f", areaDouble);
		break;
	default:
		break;
	}

	return 0;
}
