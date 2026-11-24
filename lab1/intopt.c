#include <stdio.h>
#include <stdlib.h>


int main (void) {
    //printf("Hello, world\n");
    int n, m;
    scanf("%d %d", &m, &n);
   

    double *c = malloc(n*sizeof(double));
    double **A = malloc(m*sizeof(*A));
    double *b = malloc(m*sizeof(double));
    

    for (size_t i = 0; i < n; i++) {
        scanf("%lf", (c+i)); //not sure ab this 

    }

    for (size_t i = 0; i < m; i++) {
        *(A+i) = malloc(n*sizeof(double));
        for (size_t j = 0; j < n; j++) {
            scanf("%lf", *(A+i)+ j);

        }
        
    }

    for (size_t i = 0; i < m; i++) { 
        scanf("%lf", (b+i));
        
     }

    


    printf("max z = ");
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" + ");
        }
        printf("%.1f x%d", c[i], i);
    }
    printf("\n");

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) {
                printf(" + ");
            }
            printf("%.1f x%d", A[i][j], j);
        }
        printf(" \u2264 %.1f\n", b[i]);
    }


    free(c);
    free(b);
    for (size_t i = 0; i < m; i++) {
       free(A[i]);
        
        
    }
    free(A);
    





}
