#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
   // Array to store areas
    double areas[n];
    
    // Calculate area for each triangle using Heron's formula
    for (int i = 0; i < n; i++) {
        double s = (tr[i].a + tr[i].b + tr[i].c) / 2.0;
        areas[i] = sqrt(s * (s - tr[i].a) * (s - tr[i].b) * (s - tr[i].c));
    }
    
    // Bubble sort - sort triangles by area (smallest to largest)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (areas[j] > areas[j + 1]) {
                // Swap triangles
                triangle temp = tr[j];
                tr[j] = tr[j + 1];
                tr[j + 1] = temp;
                
                // Swap areas to keep them matched
                double temp_area = areas[j];
                areas[j] = areas[j + 1];
                areas[j + 1] = temp_area;
            }
        }
    }
}



int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
