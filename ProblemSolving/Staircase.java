import java.io.*;

class Result {
    public static void staircase(int n) {
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n - i; j++) {
                sb.append(' ');
            }
            for (int j = 0; j < i; j++) {
                sb.append('#');
            }
            sb.append('\n');
        }
        System.out.print(sb);
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bufferedReader.readLine().trim());
        Result.staircase(n);
        bufferedReader.close();
    }
}
