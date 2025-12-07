import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        long[] arr = new long[5];
        
        for (int i = 0; i < 5; i++) {
            arr[i] = scanner.nextLong();
        }
        
        long sum = 0;
        long min = arr[0];
        long max = arr[0];
        
        for (int i = 0; i < 5; i++) {
            sum += arr[i];
            if (arr[i] < min) min = arr[i];
            if (arr[i] > max) max = arr[i];
        }
        
        long minSum = sum - max;
        long maxSum = sum - min;
        
        System.out.println(minSum + " " + maxSum);
    }
}
