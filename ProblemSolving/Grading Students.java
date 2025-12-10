import java.util.*;

class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> grades = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            grades.add(scanner.nextInt());
        }
        
        List<Integer> result = gradingStudents(grades);
        
        for (int grade : result) {
            System.out.println(grade);
        }
        
        scanner.close();
    }
    
    public static List<Integer> gradingStudents(List<Integer> grades) {
        List<Integer> result = new ArrayList<>();
        
        for (int grade : grades) {
            if (grade < 38) {
                result.add(grade);
            } else {
                int nextMultiple = ((grade + 4) / 5) * 5;
                if (nextMultiple - grade < 3) {
                    result.add(nextMultiple);
                } else {
                    result.add(grade);
                }
            }
        }
        
        return result;
    }
}
