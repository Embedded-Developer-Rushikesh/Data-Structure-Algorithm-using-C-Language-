#include<stdio.h>
#include <stdlib.h>
long merge(int* arr, int start,int mid, int end) 
{
    int i=start,j=mid+1,k=0;
    int inversionCount = 0;
    int* temp = (int*)malloc((end - start + 1) * sizeof(int));
    while(i<=mid && j<=end)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
            inversionCount+=mid-i+1;
        }
    }
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<=end)
    {
        temp[k++]=arr[j++];
    }
    for (i = start, k = 0; i <= end; i++, k++) {
        arr[i] = temp[k];
    }
    
    free(temp);
    return inversionCount;
}
long mergesort(int* arr, int start, int end) 
{
   
    long inversionCount = 0;
    while(start<end)
    {
        int mid=start+((end-start)/2);
        inversionCount+=mergesort(arr,start,mid);
        inversionCount+=mergesort(arr,mid+1,end);
        inversionCount+=merge(arr,start,mid,end);
        return inversionCount;
    }
    return 0;
}
long countInversions(int arr_count, int* arr) {
    return mergesort(arr, 0, arr_count - 1);
}
int main() {
    int arr[] = {6, 3, 5, 2, 7};
    int arr_count = sizeof(arr) / sizeof(arr[0]);
    long inversions = countInversions(arr_count, arr);   
    printf("Number of inversions: %ld\n", inversions);
    
    return 0;
}