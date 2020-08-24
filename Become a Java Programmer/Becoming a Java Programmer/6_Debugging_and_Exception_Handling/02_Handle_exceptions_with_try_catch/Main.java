public class Main {
	public static void main(String[] args) {
		
		String s = null;

		// var sub = s.substring(1);
		try {
			var sub = s.substring(1);
		} catch (Exception e) {
			e.printStackTrace();
		}
		System.out.println("I'm not dead yet!");
	}
}