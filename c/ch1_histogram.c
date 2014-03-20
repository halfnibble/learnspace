#include <stdio.h>

int main()
{
	/* numVowel represents the following vowels:
	 * a = 0
	 * e = 1
	 * i = 2
	 * o = 3
	 * u = 4
	 */
	 
	int i, c, numVowel[5];
	
	for (i = 0; i < 5; ++i) {
		numVowel[i] = 0;
	}
	
	while ((c = getchar()) != EOF) {
		if (c == 'a' || c == 'A') {
			++numVowel[0];
		}
		else if (c == 'e' || c == 'E') {
			++numVowel[1];
		}
		else if (c == 'i' || c == 'I') {
			++numVowel[2];
		}
		else if (c == 'o' || c == 'O') {
			++numVowel[3];
		}
		else if (c == 'u' || c == 'U') {
			++numVowel[4];
		}
	}
	
	printf("\nVowel occurance histogram\n-------------------------\n");
	// a
	printf("a: ");
	for (i = 0; i < numVowel[0]; i++)
		printf("|");
	printf("\n");
	// e
	printf("e: ");
	for (i = 0; i < numVowel[1]; i++)
		printf("|");
	printf("\n");
	// i
	printf("i: ");
	for (i = 0; i < numVowel[2]; i++)
		printf("|");
	printf("\n");
	// o
	printf("o: ");
	for (i = 0; i < numVowel[3]; i++)
		printf("|");
	printf("\n");
	// u
	printf("u: ");
	for (i = 0; i < numVowel[4]; i++)
		printf("|");
	printf("\n");
	
	return 0;
}
