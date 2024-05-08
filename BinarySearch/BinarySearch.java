public class BinarySearch {
    public static void main(String[] args) {
        int[] myarr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    }

    // returns the index of the target element in a sorted array or -1 if not found.
    public static int BisectionSearch(int[] arr, int target) {
        int lowIndex = 0;
        int highIndex = arr.length -1;

        while (lowIndex <= highIndex) {
            System.out.println("low: " + lowIndex);
            System.out.println("high: " + highIndex);
            int midIndex = (int) ((lowIndex + highIndex) / 2);
            System.out.println("mid: " + midIndex);
            if (target == arr[midIndex]) {
                return midIndex;
            }
            else if (target > arr[midIndex]) {
                lowIndex = midIndex + 1;
            }
            else
                highIndex = midIndex - 1;
        }
        return -1;
    }
}