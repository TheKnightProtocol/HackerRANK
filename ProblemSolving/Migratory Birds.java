import java.util.*;

public class Solution {
    public static int migratoryBirds(List<Integer> arr) {
        int[] freq = new int[6]; // indices 0-5
        
        for (int bird : arr) {
            freq[bird]++;
        }
        
        int maxId = 1;
        for (int i = 2; i <= 5; i++) {
            if (freq[i] > freq[maxId]) {
                maxId = i;
            }
        }
        
        return maxId;
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> arr = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            arr.add(scanner.nextInt());
        }
        
        System.out.println(migratoryBirds(arr));
    }
}
