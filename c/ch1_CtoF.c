#include <stdio.h>

#define LOWER -30 	/* lower limit of conversion table */
#define UPPER 100 	/* upper limit of conversion table */
#define STEP 10 	/* step size */

int main()
{
	int celsius;
	
	printf("Celsius\t Fahrenheit\n");
	for (celsius = UPPER; celsius > LOWER; celsius = celsius - STEP) {
		printf("%3d\t%6.1f\n", celsius, (9.0/5.0 * celsius + 32.0));
	}
	
	return 0;
}
