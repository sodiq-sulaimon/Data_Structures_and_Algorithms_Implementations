public class PowerRecursion {
    public static int power(int m, int n) {
        if (n == 0) {
            return 1;
        }
        return power(m, n - 1) * m;
    }

    public static void main(String[] args) {
        System.out.println(power(2, 9));
    }
}