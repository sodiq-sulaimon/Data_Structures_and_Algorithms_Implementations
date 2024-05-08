public class StaticGlobal {
    static int x = 0;

    public static int func1(int n) {
        if (n > 0) {
            return func1(n - 1) + n;
        }
        return 0;
    }

    public static int func2(int n) {
        if (n > 0) {
            x++;
            return func2(n - 1) + x;
        }
        return 0;
    }

    public static void main(String[] args) {
        int a=5;
        System.out.println("Function 1");
        System.out.println(func1(a));

        System.out.println("Function 2");
        System.out.println(func2(a));

        System.out.println("Function 2");
        System.out.println(func2(a)); // returns 50 because first call of func2() has changed the value of x to 5
    }
}