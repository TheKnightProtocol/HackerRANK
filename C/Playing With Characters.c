#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() 
{
    char ch;
    char s[100];
    char sen[100];
    
    // Read character
    scanf("%c", &ch);
    
    // Read string (first word)
    scanf("%s", s);
    
    // Clear the newline left in the buffer
    getchar();
    
    // Read the entire sentence with spaces
    fgets(sen, 100, stdin);
    
    // Print outputs
    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s", sen);
    
    return 0;
}
