import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < n; i++) {
            String pattern = sc.nextLine();
            try {
                java.util.regex.Pattern.compile(pattern);
                System.out.println("Valid");
            } catch (java.util.regex.PatternSyntaxException e) {
                System.out.println("Invalid");
            }
        }
        sc.close();
    }
}
