public class TreeRecursion {

    public static void func1(int n) {
        if (n > 0) {
            System.out.println(n);
            func1(n - 1);
            func1(n - 1);
        }
    }


    public static void main(String[] args) {
        func1(3);
    }
}