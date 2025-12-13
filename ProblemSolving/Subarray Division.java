import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;

class Solution {
    
    public static int birthday(List<Integer> s, int d, int m) {
        int count = 0;
        int n = s.size();
        
        if (n < m) return 0;
        
        int windowSum = 0;
        
        // Calculate sum of first window
        for (int i = 0; i < m; i++) {
            windowSum += s.get(i);
        }
        
        // Check first window
        if (windowSum == d) {
            count++;
        }
        
        // Slide the window
        for (int i = m; i < n; i++) {
            windowSum = windowSum - s.get(i - m) + s.get(i);
            if (windowSum == d) {
                count++;
            }
        }
        
        return count;
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));
        
        int n = Integer.parseInt(bufferedReader.readLine().trim());
        
        List<Integer> s = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());
        
        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");
        int d = Integer.parseInt(firstMultipleInput[0]);
        int m = Integer.parseInt(firstMultipleInput[1]);
        
        int result = birthday(s, d, m);
        
        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();
        
        bufferedReader.close();
        bufferedWriter.close();
    }
}
