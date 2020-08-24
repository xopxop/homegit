public class Main {
	public static double calculateEmployeeSalary(double hoursPerWeek, double moneyPerHour, double vacationday) {
		if(hoursPerWeek < 0 || moneyPerHour < 0) {
			return -1;
		}

		double result = (52 * hoursPerWeek * moneyPerHour) - (vacationday * 8 * moneyPerHour);
		return result;
	}

	public static void main(String[] args) {
		double grossYearlySalary = calculateEmployeeSalary(40, 15, 8);
		System.out.println(grossYearlySalary);
	}
}
