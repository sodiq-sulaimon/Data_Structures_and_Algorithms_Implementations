public class Fibonacci {
    // fibonacci with for loop
    public static int fib1(int n) {
        if (n <= 1) {
            return n;
        }
        int t0 = 0;
        int t1=1;
        int sum = 0;
        for (int i = 2; i <= n; i++) {
            sum = t0 + t1;
            t0 = t1;
            t1 = sum;
        }
        return sum;
    }

    // fibonacci with recursion
    public static int rFib(int n) {
        if (n <= 1) {
            return n;
        }
        return rFib(n-2) + rFib(n-1);
    }

    public static void main(String[] args) {
        System.out.println(fib1(10));
        System.out.println(rFib(10));
    }
}