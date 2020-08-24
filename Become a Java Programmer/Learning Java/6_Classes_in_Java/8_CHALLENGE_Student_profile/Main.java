public class Main {
	public static void main (String[] args) {
		Student studentA = new Student("Lara", "Smith", 2021, 4.0, "Nursing");
		Student studentB = new Student("Kevin", "Lauren", 2022, 3.8, "Engineer");

		studentB.increamentExpectedGraduationYear();
		System.out.println(studentB.expectedGradutionYear);
	}
}