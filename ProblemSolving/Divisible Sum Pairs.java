import java.util.*;

class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        List<Integer> ar = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            ar.add(sc.nextInt());
        }
        System.out.println(divisibleSumPairs(n, k, ar));
        sc.close();
    }
    
    public static int divisibleSumPairs(int n, int k, List<Integer> ar) {
        int[] freq = new int[k];
        int count = 0;
        
        for (int num : ar) {
            int rem = num % k;
            int complement = (k - rem) % k;
            count += freq[complement];
            freq[rem]++;
        }
        
        return count;
    }
}
