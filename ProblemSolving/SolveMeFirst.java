import java.util.*;

public class Solution {

    // Complete the function
    static int sum(int a, int b) {
        return a + b;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();   // reads 100
        int b = sc.nextInt();   // reads 1000
        System.out.print(sum(a, b));  // prints 1100
        sc.close();
    }
}
