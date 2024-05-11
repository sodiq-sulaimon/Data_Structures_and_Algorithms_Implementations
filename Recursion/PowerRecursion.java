public class PowerRecursion {
    public static int power(int m, int n) {
        if (n == 0) {
            return 1;
        }
        return power(m, n - 1) * m;
    }

    public static int power2(int m, int n) {
        if (n == 0) {
            return 1;
        }
        if (n % 2 == 0 ) {
            return power2(m * m, n/2);
        }
        return m * power2(m * m, (n - 1)/2);
    }

    public static void main(String[] args) {
        System.out.println(power(3, 4));
        System.out.println(power2(3, 4));
    }
}