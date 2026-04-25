#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
     
    char str[1000];
    int freq[10] = {0};  // Array to store frequency of digits 0-9
    
    // Read the input string
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    str[strcspn(str, "\n")] = 0;
    
    // Count frequency of each digit
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            freq[str[i] - '0']++;
        }
    }
    
    // Print the frequencies
    for(int i = 0; i < 10; i++) {
        printf("%d ", freq[i]);
    }
    
    
      
    return 0;
}
