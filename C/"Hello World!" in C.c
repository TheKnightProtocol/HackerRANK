#include <stdio.h>
#include <string.h>


int main() 
{
	
    char s[100];
    fgets(s, sizeof(s), stdin);
    
    s[strcspn(s, "\n")] =0;
    
    printf("Hello, World!\n");
    printf("%s\n", s);
  	
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
