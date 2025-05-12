#include<stdio.h>
void swap(int* nums,int i,int j)
{
    int temp=nums[i];
    nums[i]=nums[j];
    nums[j]=temp;
}
void sortColors(int* nums, int numsSize)
{
    int high=numsSize-1;
    int low=0;
    int mid=0;
    while(low<high)
    {
        if(nums[mid]==0)
        {
            swap(nums,mid,low);
            low++;
            mid++;
        }else if(nums[mid]==1)
        {
            low++;
        }else{
            swap(nums,mid,high);
            high--;
        }
    }
}
int main() {
    int nums1[] = {2, 0, 2, 1, 1, 0};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    sortColors(nums1, size1);
    printf("Test case 1: ");
    for (int i = 0; i < size1; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");
    return 0;
}