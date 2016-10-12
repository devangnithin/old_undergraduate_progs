#include <stdio.h>

/* Applies the mask to a set like {1, 2, ..., n} and prints it */
void printv(int mask[], int n) {
	int i;
	for (i = 0; i < n; ++i)
		if (mask[i])
			printf("%c", i + 65); /*i+1 is part of the subset*/
	printf("\n");

}

/* Generates the next mask*/
int next(int mask[], int n) {
	int i;
	for (i = 0; (i < n) && mask[i]; ++i)
		mask[i] = 0;

	if (i < n) {
		mask[i] = 1;
		return 1;
	}
	return 0;
}

int main() {

	int n = 3;
	int mask[16]; /* Guess what this is */
	int i;
	clrscr();
	for (i = 0; i < n; ++i)
		mask[i] = 0;

	/* Print the first set */
	printv(mask, n);

	/* Print all the others */
	while (next(mask, n))
		printv(mask, n);
		getch();
		return 0;
}