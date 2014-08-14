// Fig 2.7: Addition.java
// Addition rogram that displays the sum of two numbers.
import java.util.Scanner; // uses class Scanner

public class Addition
{
	// main method begins execution of Java application
	public static void main( String[] args )
	{
		// create a Scanner to obtain input from command window
		Scanner input = new Scanner( System.in );

		int number1; // first number
		int number2; // second number
		int sum;	 // sum of numbers

		System.out.print( "Enter first integer: " ); // prompt
		number1 = input.nextInt();	// read 1st number from user

		System.out.print( "Enter second integer: " ); // prompt
		number2 = input.nextInt();	// read 2nd number

		sum = number1 + number2;

		System.out.printf( "Sum is %d\n", sum ); // display sum
	} // end main
} // end class Addition