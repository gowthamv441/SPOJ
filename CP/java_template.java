import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read number of test cases or inputs, if needed
        int t = scanner.nextInt();  // Example for reading the number of test cases

        // Example loop to process multiple test cases
        for (int i = 0; i < t; i++) {
            // Read input for each test case
            int input = scanner.nextInt();

            // Call your method to process input
            int result = yourMethod(input);

            // Print the result
            System.out.println(result);
        }

        // Close the scanner
        scanner.close();
    }

    // Example method to process the input and return result
    public static int yourMethod(int input) {
        // Implement your logic here
        return input * 2;  // Example logic (you can change this)
    }
}
