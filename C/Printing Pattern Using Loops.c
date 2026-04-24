#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.

  
    int size = 2 * n - 1;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int min_dist = i;
            if (j < min_dist) min_dist = j;
            if ((size - 1 - i) < min_dist) min_dist = size - 1 - i;
            if ((size - 1 - j) < min_dist) min_dist = size - 1 - j;
            
            printf("%d", n - min_dist);
            if (j < size - 1) printf(" ");
        }
        printf("\n");
    }
    
    
    
    
    return 0;
}
