import java.util.Scanner;

class Solution {
    public static String dayOfProgrammer(int year) {
        if (year == 1918) {
            return "26.09.1918";
        }
        
        boolean isLeap = false;
        
        if (year < 1918) {
            // Julian calendar
            isLeap = (year % 4 == 0);
        } else {
            // Gregorian calendar
            isLeap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
        }
        
        if (isLeap) {
            return "12.09." + year;
        } else {
            return "13.09." + year;
        }
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int year = scanner.nextInt();
        System.out.println(dayOfProgrammer(year));
        scanner.close();
    }
}
