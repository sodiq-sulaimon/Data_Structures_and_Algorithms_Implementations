public class TowerOfHanoi {
    public static void TOH (int n, int tower1, int tower2, int tower3) {
        if (n > 0) {
            TOH(n-1, tower1, tower3, tower2);
            // print the steps required to move the discs from Tower 1 to Tower 3
            System.out.printf("(%d, %d)\n", tower1, tower3);
            TOH(n-1, tower2, tower1, tower3);
       }
    }

    public static void main(String[] args) {
        TOH(3, 1, 2, 3);
    }
}