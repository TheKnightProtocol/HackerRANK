#include <cstdio>

int main() {
    int intNum;
    long longNum;
    char character;
    float floatNum;
    double doubleNum;
    
    scanf("%d %ld %c %f %lf", &intNum, &longNum, &character, &floatNum, &doubleNum);
    
    printf("%d\n%ld\n%c\n%.3f\n%.9lf\n", intNum, longNum, character, floatNum, doubleNum);
    
    return 0;
}
