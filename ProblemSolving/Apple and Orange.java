import java.util.*;

class Solution {
    public static void countApplesAndOranges(int s, int t, int a, int b, List<Integer> apples, List<Integer> oranges) {
        int appleCount = 0;
        int orangeCount = 0;
        
        for (int apple : apples) {
            int position = a + apple;
            if (position >= s && position <= t) {
                appleCount++;
            }
        }
        
        for (int orange : oranges) {
            int position = b + orange;
            if (position >= s && position <= t) {
                orangeCount++;
            }
        }
        
        System.out.println(appleCount);
        System.out.println(orangeCount);
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int s = scanner.nextInt();
        int t = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        
        List<Integer> apples = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            apples.add(scanner.nextInt());
        }
        
        List<Integer> oranges = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            oranges.add(scanner.nextInt());
        }
        
        countApplesAndOranges(s, t, a, b, apples, oranges);
        
        scanner.close();
    }
}
