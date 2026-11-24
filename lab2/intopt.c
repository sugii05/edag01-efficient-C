#include <stdio.h>
#include <stdlib.h>

#define EPS 1e-6

struct  simplex_t
{
    int n, m;
    double** a;
    double* b;
    double* c;
    double* x;
    double y;
    int * var;

    /* data */
};

int init (struct simplex_t *s, int m, int n, double **a, double *b, double *c, double *x, double y, int * var) {
    (*s).m = m;
    (*s).n = n;
    (*s).a = a;
    (*s).b = b;
    (*s).c = c;
    (*s).x = x;
    (*s).y = y;
    (*s).var = var;


    if ((*s).var == NULL) {
        (*s).var = malloc((m+n+1) * sizeof(int));
        for (size_t i = 0; i < n+m+1; i++) {
            (*s).var [i] = i;

        }
        
    }
    int k = 0;
    
    for (size_t i = 1; i < m; i++) {
        if (b[i] < b[k]) {
            k = i;
        }
            
    }
    
    return k;

    
}

int initial(struct simplex_t *s, int m, int n,
            double **a, double *b, double *c,
            double *x, double y, int *var)
{
    init(s, m, n, a, b, c, x, y, var);

    // Lab 2 assumes every b[i] >= 0, so the origin is feasible.
    return 1;
}

int select_nonbasic(struct simplex_t *s) {
    for (size_t i = 0; i < (*s).n; i++) {
        if ((*s).c[i] > EPS) {
            return i;
        }
    }
    
    return -1;

}

void pivot(struct simplex_t* s, int row, int col) {
    auto a = (*s).a;
    auto b = (*s).b;
    auto c = (*s).c;
    int m = (*s).m;
    int n = (*s).n;
    int i, j, t;

    t = s->var[col];
    s->var[col] = s->var[n+row];
    s->var[n+row] = t;
    s->y = s->y + c[col] * b[row] / a[row][col];
    for (size_t i = 0; i < n; i++) {
        if (i != col) {
            c[i] = c[i] - c[col]*a[row][i]/a[row][col];
        }
    }
    c[col] = -c[col] /a[row][col];
    for (size_t i = 0; i < m; i++) {
        if (i != row) {
            for (size_t j = 0; j < n; j++) {
                if (j != col) {
                    a[i][j] = a[i][j] - a[i][col]*a[row][j] / a[row][col];
                }
            }
        }
    }

    for (size_t i = 0; i < m; i++)
    {
        if (i != row) {
            a[i][col] = -a[i][col] / a[row][col];
        }

    }
    for (size_t i = 0; i < n; i++) {

        if (i != col) {
            a[row][i] = a[row][i]/a[row][col];

        }
    }
    b[row] = b[row]/a[row][col];
    a[row][col] = 1 /a[row][col];
    
}


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
