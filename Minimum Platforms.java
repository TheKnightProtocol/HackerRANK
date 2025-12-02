import java.util.*;

class Solution {
    // Method name is findPlatform, not minPlatform
    static int findPlatform(int arr[], int dep[]) {
        int n = arr.length;
        
        // Sort arrival and departure arrays
        Arrays.sort(arr);
        Arrays.sort(dep);
        
        int platformsNeeded = 0;
        int maxPlatforms = 0;
        int i = 0; // pointer for arrival
        int j = 0; // pointer for departure
        
        while (i < n && j < n) {
            // If a train arrives before or at the same time as another departs
            if (arr[i] <= dep[j]) {
                platformsNeeded++;
                i++;
            } else {
                // A train departs before next arrival
                platformsNeeded--;
                j++;
            }
            
            // Update maximum platforms needed
            maxPlatforms = Math.max(maxPlatforms, platformsNeeded);
        }
        
        return maxPlatforms;
    }
    
    // If the driver code expects minPlatform method, we can add an alias
    static int minPlatform(int arr[], int dep[]) {
        return findPlatform(arr, dep);
    }
}
