import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		try {
			double number1 = getInput(sc);
			sc.nextLine();
			double number2 = getInput(sc);
			sc.nextLine();
			var op = getOp(sc);
			calculate(number1, number2, op);
		} catch (InputMismatchException e) {
			System.out.println("Couldn't format as a number");
		}
	}

	public static double getInput(Scanner sc) {
		System.out.print("Enter a numeric value: ");
		return sc.nextDouble();
	}

	public static String getOp(Scanner sc) {
		System.out.print("Select an operation (+ - * /): ");
		return sc.nextLine();
	}

	public static void calculate(double n1, double n2, String op) {
		double answer;

		answer = 0;
		if (op.equals("+") || op.equals("-") || op.equals("*") || op.equals("/"))
		{
			if (op.equals("+"))
				answer = n1 + n2;
			else if (op.equals("-"))
				answer = n1 - n2;
			else if (op.equals("*"))
				answer = n1 * n2;
			else if (op.equals("/"))
				answer = n1 / n2;
			System.out.println("The answer is : " + answer);
		}
		else
			System.out.println("You didn't choose a valid operation");
	}
}