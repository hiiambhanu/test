#include <stdio.h>
int max(int a, int b){
    return a>b?a:b;
}
void conv_sparse(int a[10][10], int m, int n, int sparse[3][10], int* count){
    int i, j,k = 0;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {   
            if (a[i][j])
            {
                (*count)++;
                sparse[0][k] = i;
                sparse[1][k] = j;
                sparse[2][k] = a[i][j];
                k++;
            }
        }
    }
}

void display_sparse(int sparse[3][10], int count){

    int i, j, k = count;
    printf("\nNo of non zero elements are %d\nThe sparse matrix is\n", count);

    for (i = 0; i < 3; i++)
    {
        if (i == 0)
            printf("row: ");
        else if (i == 1)
            printf("col: ");
        else
            printf("val: ");
        for (j = 0 ; j < k ; j++)
        {
            printf("%d ", sparse[i][j]);
        }
        printf("\n");
    }
}

void sum(int sparse[3][10], int sparse2[3][10], int sumsparse[3][10], int m, int n, int p, int q, int count, int count2){

    if(m!=p || n!=q)
        {
            printf("\nThe sum is not possible.\n ");
            return;
        }
    int mat1 = 0;
    int mat2 = 0;
    int mat3 = 0;

    while (mat1 < count && mat2 < count2)
    {
        if (sparse[0][mat1] == sparse2[0][mat2] && sparse[1][mat1] == sparse2[1][mat2])
        {
            sumsparse[0][mat3] = sparse[0][mat1];
            sumsparse[1][mat3] = sparse[1][mat1];
            sumsparse[2][mat3] = sparse[2][mat1] + sparse2[2][mat2];
            mat3++;
            mat2++;
            mat1++;
        }

        else
        {
            if (sparse[0][mat1] < sparse2[0][mat2])
            {
                sumsparse[0][mat3] = sparse[0][mat1];
                sumsparse[1][mat3] = sparse[1][mat1];
                sumsparse[2][mat3] = sparse[2][mat1];
                mat3++;
                mat1++;
            }

            else if(sparse[0][mat1] == sparse2[0][mat2]){
                if(sparse[1][mat1] < sparse2[1][mat2]){
                    sumsparse[0][mat3] = sparse[0][mat1];
                    sumsparse[1][mat3] = sparse[1][mat1];
                    sumsparse[2][mat3] = sparse[2][mat1];
                    mat3++;
                    mat1++;
                }
                else{
                    sumsparse[0][mat3] = sparse2[0][mat2];
                    sumsparse[1][mat3] = sparse2[1][mat2];
                    sumsparse[2][mat3] = sparse2[2][mat2];
                    mat2++;
                    mat3++;
                }
            }
            else
            {
                sumsparse[0][mat3] = sparse2[0][mat2];
                sumsparse[1][mat3] = sparse2[1][mat2];
                sumsparse[2][mat3] = sparse2[2][mat2];
                mat2++;
                mat3++;
            }
        }
    }

    while (mat1 < count)
    {
        sumsparse[0][mat3] = sparse[0][mat1];
        sumsparse[1][mat3] = sparse[1][mat1];
        sumsparse[2][mat3] = sparse[2][mat1];
        mat3++;
        mat1++;
    }
    while (mat2 < count)
    {
        sumsparse[0][mat3] = sparse2[0][mat2];
        sumsparse[1][mat3] = sparse2[1][mat2];
        sumsparse[2][mat3] = sparse2[2][mat2];
        mat3++;
        mat2++;
    }

    display_sparse(sumsparse, max(count2, count));
    
}

void display_mat(int a[10][10], int m, int n){

    int i, j;
    printf("The entered matrix is\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

}

void main()
{

    int count3=0,  a[10][10], m, k = 0, n, mat3, i, j, mat1 = 0, mat2 = 0, count = 0, sparse[3][10], sparse2[3][10], b[10][10], p, q, count2 = 0, sumsparse[3][10];
    printf("Enter the number of rows and coloumns. \n");
    scanf("%d%d", &m, &n);

    printf("Enter the matrix \n");

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    conv_sparse(a, m, n, sparse, &count);
    display_sparse(sparse, count);

    printf("Enter the number of rows and coloumns. \n");
    scanf("%d%d", &p, &q);

    printf("Enter the matrix 2 \n");
    k = 0;

    for (i = 0; i < p; i++)
        for (j = 0; j < q; j++)
            scanf("%d", &b[i][j]);
        
    conv_sparse(b, p, q, sparse2, &count2);
    
    display_mat(a, m, n);
    display_mat(b, p, q);

    display_sparse(sparse2, count2);

    sum(sparse, sparse2, sumsparse, m, n, p, q, count, count2);
    count3 = max(count2, count);
    

}