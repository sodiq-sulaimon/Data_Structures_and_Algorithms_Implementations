public class tailHead {
    public static void func1(int n) {
        if (n > 0) {
            System.out.println(n);
            func1(n - 1);
        }
    }

    public static void func2(int n) {
        if (n > 0) {
            func2(n - 1);
            System.out.println(n);
        }
    }

    public static void main(String[] args) {
        int x = 3;
        System.out.println("Function 1");
        func1(x);

        System.out.println("Function 2");
        func2(x);
    }
}