import java.util.*;

class Solution {
    public static List<Integer> breakingRecords(List<Integer> scores) {
        List<Integer> result = new ArrayList<>();
        
        if (scores.size() == 0) {
            result.add(0);
            result.add(0);
            return result;
        }
        
        int minScore = scores.get(0);
        int maxScore = scores.get(0);
        int minBreaks = 0;
        int maxBreaks = 0;
        
        for (int i = 1; i < scores.size(); i++) {
            int currentScore = scores.get(i);
            
            if (currentScore > maxScore) {
                maxScore = currentScore;
                maxBreaks++;
            } else if (currentScore < minScore) {
                minScore = currentScore;
                minBreaks++;
            }
        }
        
        result.add(maxBreaks);
        result.add(minBreaks);
        return result;
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        List<Integer> scores = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            scores.add(scanner.nextInt());
        }
        
        List<Integer> result = breakingRecords(scores);
        System.out.println(result.get(0) + " " + result.get(1));
        
        scanner.close();
    }
}
