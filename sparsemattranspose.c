#include<stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a=*b;
    *b= temp;
}

void sort(int sparse[3][10], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if(sparse[0][j] > sparse[0][j+1])
                {
                    swap(&sparse[0][j], & sparse[0][j+1]);
                    swap(&sparse[1][j], & sparse[1][j+1]);
                    swap(&sparse[2][j], & sparse[2][j+1]);
                }
            else if (sparse[0][j] == sparse[0][j+1]){
                if(sparse[1][j] > sparse[1][j+1]){
                    swap(&sparse[0][j], & sparse[0][j+1]);
                    swap(&sparse[1][j], & sparse[1][j+1]);
                    swap(&sparse[2][j], & sparse[2][j+1]);
                }
            }
        }
    }
}



void transpose(int sparse[3][10], int count){
    
    int i;    

    
    for( i = 0 ; i < count ; i++ ){
        swap(&sparse[0][i], &sparse[1][i]);
    }

    sort(sparse, count);

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

int main(){
    int i, j, m, n, a[10][10], count=0, sparse[3][10];
    printf("Enter the number of rows and coloumns. \n");
    scanf("%d%d", &m, &n);

    printf("Enter the matrix \n");

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    conv_sparse(a, m, n, sparse, &count);
    display_sparse(sparse, count);

    transpose(sparse, count);
    display_sparse(sparse, count);

    return 0;
}