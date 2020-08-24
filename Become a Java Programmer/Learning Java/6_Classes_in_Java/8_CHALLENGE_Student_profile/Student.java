public class Student {
	String	firstName;
	String	lastName;
	int		expectedGradutionYear;
	double	GPA;
	String	declaredMajor;

	public Student(String firstName, String lastName, int expectedGradutionYear, double GPA, String declaredMajor) {
		this.firstName = firstName;
		this.lastName = lastName;
		this.expectedGradutionYear = expectedGradutionYear;
		this.GPA = GPA;
		this.declaredMajor = declaredMajor;
	}

	void increamentExpectedGraduationYear() {
		this.expectedGradutionYear++;
	}
}