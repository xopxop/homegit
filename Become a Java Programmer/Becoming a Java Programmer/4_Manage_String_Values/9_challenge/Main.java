import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		var scanner = new Scanner(System.in);
		System.out.print("Enter a numeric value: ");
		var number1 = scanner.nextDouble();

		System.out.print("Enter a numeric value: ");
		var number2 = scanner.nextDouble();
		
		var answer = number1 / number2;
		System.out.println("The answer is :" + answer);
	}
}