import java.util.*;

class Solution {
    public static String kangaroo(int x1, int v1, int x2, int v2) {
        if (v1 == v2) {
            return x1 == x2 ? "YES" : "NO";
        }
        
        if ((x2 - x1) % (v1 - v2) == 0 && (x2 - x1) / (v1 - v2) >= 0) {
            return "YES";
        }
        
        return "NO";
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int x1 = scanner.nextInt();
        int v1 = scanner.nextInt();
        int x2 = scanner.nextInt();
        int v2 = scanner.nextInt();
        
        System.out.println(kangaroo(x1, v1, x2, v2));
        
        scanner.close();
    }
}
