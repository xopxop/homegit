import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		String question = "How old are you?";
		String choiceOne = "20";
		String choiceTwo = "30";
		String choiceThree = "40";
		String correctAnswer = choiceTwo;
		
		System.out.println(question);
		System.out.println("Are you " + choiceOne + " or " + choiceTwo + " or " + choiceThree + " ?");

		Scanner input = new Scanner(System.in);
		String userInput = input.next();

		if (correctAnswer.equals(userInput.toLowerCase()))
			System.out.println("Congrat! you are correct");
		else
			System.out.println("You are incorrect, better luck next time");
	}
}