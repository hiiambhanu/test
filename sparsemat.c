#include <stdio.h>
void main()
{

    int a[10][10], m, k = 0, n,mat3, i, j, mat1=0, mat2=0, count = 0, sparse[3][10], sparse2[3][10], b[10][10], p, q, count2 = 0, bback[10][10], sumsparse[3][10];
    printf("Enter the number of rows and coloumns. \n");
    scanf("%d%d", &m, &n);

    printf("Enter the matrix \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j])
            {
                count++;
                sparse[0][k] = i;
                sparse[1][k] = j;
                sparse[2][k] = a[i][j];
                k++;
            }
        }
    }

    printf("The entered matrix is\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("No of non zero elements are %d\nThe sparse matrix is\n", count);

    for (i = 0; i < 3; i++)
    {
        if (i == 0)
            printf("row: ");
        else if (i == 1)
            printf("col: ");
        else
            printf("val: ");
        for (j = 0; j < k; j++)
        {
            printf("%d ", sparse[i][j]);
        }
        printf("\n");
    }

    printf("Enter the number of rows and coloumns. \n");
    scanf("%d%d", &p, &q);

    printf("Enter the matrix 2 \n");
    k = 0;
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < q; j++)
        {
            scanf("%d", &b[i][j]);
            if (b[i][j])
            {
                count2++;
                sparse2[0][k] = i;
                sparse2[1][k] = j;
                sparse2[2][k] = b[i][j];
                k++;
            }
        }
    }

    printf("No of non zero elements are %d\nThe sparse matrix2 is\n", count2);

    for (i = 0; i < 3; i++)
    {
        if (i == 0)
            printf("row: ");
        else if (i == 1)
            printf("col: ");
        else
            printf("val: ");
        for (j = 0; j < count2; j++)
        {
            printf("%d ", sparse2[i][j]);
        }
        printf("\n");
    }

    k = 0;

    for (i = 0; i < p; i++)
    {
        for (j = 0; j < q; j++)
        {
            if (sparse2[0][k] == i)
            {
                if (sparse2[1][k] == j)
                {
                    bback[i][j] = sparse2[2][k];
                    k++;
                }
            }
            else
                bback[i][j] = 0;
        }
    }

    // printf("The converted  matrix is\n");

    // for (i = 0; i < p; i++)
    // {
    //     for (j = 0; j < q; j++)
    //     {
    //         printf("%d ", bback[i][j]);
    //     }
    //     printf("\n");
    // }
    mat3=0;
    while(mat1<count && mat2<count2){

        if(sparse[0][mat1]==sparse2[0][mat2] && sparse[1][mat1] == sparse2[1][mat2]){
            sumsparse[0][mat3] = sparse[0][mat1];
            sumsparse[1][mat3] = sparse[1][mat1];
            sumsparse[2][mat3] = sparse[2][mat1] + sparse2[2][mat2];
            mat3++;
            mat2++;
            mat1++;
        }

        else{
            if(sparse[0][mat1] < sparse2[0][mat2]){
                sumsparse[0][mat3]  = sparse[0][mat1];
                sumsparse[1][mat3]  = sparse[1][mat1];
                sumsparse[2][mat3]  = sparse[2][mat1];
                mat3++;
                mat1++;
            }
            else{
                sumsparse[1][mat3]  = sparse2[1][mat2];
                sumsparse[0][mat3]  = sparse2[0][mat2];
                sumsparse[2][mat3]  = sparse2[2][mat2];
                mat2++;
                mat3++;
            }
        }
    }

    for (i = 0; i < 3; i++)
    {
        if (i == 0)
            printf("row: ");
        else if (i == 1)
            printf("col: ");
        else
            printf("val: ");
        for (j = 0; j < count2; j++)
        {
            printf("%d ", sumsparse[i][j]);
        }
        printf("\n");
    }

    
}