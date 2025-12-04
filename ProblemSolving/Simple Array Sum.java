import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(bufferedReader.readLine().trim());
        
        String[] arTemp = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int arItem = Integer.parseInt(arTemp[i]);
            sum += arItem;
        }
        
        System.out.println(sum);
        
        bufferedReader.close();
    }
}
