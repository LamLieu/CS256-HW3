#include <stdio.h>

int main() {
	double newPopulation, oldPopulation = 0, birthRate = -1, deathRate = -1, numOfYears = 0;

	while(oldPopulation < 2) {
		printf("Enter the starting population size: ");
		fflush(stdout);
		scanf("%lf", &oldPopulation);
	}

	while (birthRate < 0) {
		printf("Enter the annual birth rate: ");
		fflush(stdout);
		scanf("%lf", &birthRate);
	}

	while (deathRate < 0) {
		printf("Enter the annual death rate: ");
		fflush(stdout);
		scanf("%lf", &deathRate);
	}

	while (numOfYears < 1) {
		printf("Enter the number of years to display: ");
		fflush(stdout);
		scanf("%lf", &numOfYears);
	}

	newPopulation = oldPopulation + (birthRate * oldPopulation) - (deathRate * oldPopulation);
	printf("The new population is: %.0lf", newPopulation);
	return 0;
}
