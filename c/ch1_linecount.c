#include <stdio.h>

/* Count lines in input */
int main()
{
	int c, blank;
	
	blank = 0; /* number of white space chars back to back */
	while((c = getchar()) != EOF) {
		if (c == '\n' || c == ' ' || c == '\t') {
			if (blank == 1)
				;
			else {
				blank = 1; /* Start counting white space */
				putchar(' ');
			}
		} else {
			blank = 0; /* Reset white space count */
			putchar(c);
		}
	}
	return 0;
}
