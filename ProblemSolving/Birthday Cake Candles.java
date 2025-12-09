import java.util.*;

public class Solution {
    public static int birthdayCakeCandles(int[] candles) {
        if (candles == null || candles.length == 0) {
            return 0;
        }
        
        int maxHeight = Integer.MIN_VALUE;
        int count = 0;
        
        for (int height : candles) {
            if (height > maxHeight) {
                maxHeight = height;
                count = 1;
            } else if (height == maxHeight) {
                count++;
            }
        }
        
        return count;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read number of candles
        int n = scanner.nextInt();
        
        // Read candle heights
        int[] candles = new int[n];
        for (int i = 0; i < n; i++) {
            candles[i] = scanner.nextInt();
        }
        
        // Calculate and print result
        int result = birthdayCakeCandles(candles);
        System.out.println(result);
        
        scanner.close();
    }
}
