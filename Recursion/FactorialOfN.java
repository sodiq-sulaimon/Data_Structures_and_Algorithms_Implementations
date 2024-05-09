public class FactorialOfN {
    public static int factN(int n) {
        if (n < 0) {
            throw new IllegalArgumentException("Factorial is not defined for negative numbers");
        }
        else if (n == 0) {
            return 1;
        }
        return factN(n - 1) * n;
    }

    public static void main(String[] args) {
        System.out.println(factN(5));
    }
}