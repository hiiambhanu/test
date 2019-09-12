#include<stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a=*b;
    *b= temp;
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

void multiply(int sparse[3][10], int sparse2[3][10], int count, int count2, int mul[3][10], int count3){
    
    int apos, tempa,sum, tempb, bpos, r, c;
    transpose(sparse2, count2);
    count3 = 0;
    for(apos=0;apos<count;){
        
        r = sparse[0][apos];

        for(bpos = 0 ; bpos < count2;){
            c = sparse2[0][bpos];

            tempa = apos;
            tempb = bpos;

            sum = 0;

            while(tempa < count && sparse[0][tempa] == r &&
             tempb < count2 && sparse2[0][tempb] == c){
                 if(sparse[1][tempa] < sparse2[1][tempb])
                    tempa++;

                else if(sparse[1][tempa] > sparse2[1][tempb])
                    tempb++;    
                
                else {
                    sum += sparse[2][tempa] * sparse2[2][tempb];
                    tempa++;
                    tempb++; 
                }
            }

            if (sum)
                {
                    mul[0][count3] = r;
                    mul[1][count3] = c;
                    mul[2][count3] = sum;
                    count3++;
                }

            while (bpos < count2 && sparse2[0][bpos] == c) 
					bpos++; 
        }
        while (apos < count && sparse[0][apos] == r) 
					apos++;
    }

    display_sparse(mul, count3);

}



int main(){
    int i, j, m, n, p, q, a[10][10], b[10][10], sparse[3][10], sparse2[3][10], mul[3][10], count, count2, count3;
    count = count2 = count3 = 0;
    printf("Enter m, n and then the matrix");
    scanf("%d%d", &m, &n);
    for(i = 0 ; i < m ; i ++)
        for(j = 0 ; j < n ; j++)
            scanf("%d", &a[i][j]);

    conv_sparse(a, m, n, sparse, &count);

    printf("Enter p, q and then the matrix");
    scanf("%d%d", &p, &q);
    for(i = 0 ; i < p ; i ++)
        for(j = 0 ; j < q ; j++)
            scanf("%d", &b[i][j]);

    conv_sparse(b, p, q, sparse2, &count2);

    multiply(sparse, sparse2, count, count2, mul, count3);
    return 0;
}