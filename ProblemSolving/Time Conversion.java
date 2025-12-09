import java.util.*;

public class Solution {
    public static String timeConversion(String s) {
        // Extract AM/PM part
        String period = s.substring(s.length() - 2);
        
        // Extract time part (HH:MM:SS without AM/PM)
        String time = s.substring(0, s.length() - 2);
        
        // Split hours, minutes, seconds
        String[] parts = time.split(":");
        int hours = Integer.parseInt(parts[0]);
        String minutes = parts[1];
        String seconds = parts[2];
        
        // Convert based on AM/PM
        if (period.equals("AM")) {
            if (hours == 12) {
                hours = 0; // 12 AM becomes 00
            }
        } else { // PM case
            if (hours != 12) {
                hours += 12; // Add 12 to hours except for 12 PM
            }
        }
        
        // Format hours with leading zero if needed
        String hoursStr = String.format("%02d", hours);
        
        return hoursStr + ":" + minutes + ":" + seconds;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine().trim();
        System.out.println(timeConversion(input));
        scanner.close();
    }
}
