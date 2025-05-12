#include<stdio.h>

int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize)
{
    *returnSize=2;
    int n=gridSize*gridColSize[0];
    int * result=(int*)malloc(2*sizeof(int));int* freq=(int*)calloc(n+1,sizeof(int));
    //flattering gid and counting Freq of Each Element
    for(int i=0;i<gridSize;i++)
    {
        for(int j=0;j<gridColSize[i];j++)
        {
            int num=grid[i][j];
            freq[num]++;
        }
    }

    //Looking Missing and Repeating value
   int missing=-1,repeating=-1;
   for(int i=0;i<=n;i++)
   {
    if(freq[i]==2)
    {
        repeating=i;
    }else if(freq[i]==0)
    {
        missing=i;
    }
   }
   result[0]=repeating;
   result[1]=missing;
   free(freq);
   return result;
}

int main() {
    // Initialize the grid
    int row1[] = {9, 1, 7};
    int row2[] = {8, 9, 2};
    int row3[] = {3, 4, 6};
    int* grid[] = {row1, row2, row3};
    int gridSize = 3;
    int gridColSize[] = {3, 3, 3};
    int returnSize;

    int* result = findMissingAndRepeatedValues(grid, gridSize, gridColSize, &returnSize);

    printf("Repeated value: %d\n", result[0]);
    printf("Missing value: %d\n", result[1]);
    free(result);

    return 0;
}