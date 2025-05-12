#include<stdio.h>

int removeDuplicates(int* nums, int n) 
{
    int i=0;
    for(int j=0;i<n;j++)
    {
        if(nums[i]!=nums[j])
        {
            i++;
        }
        nums[i]=nums[j];
    }
    return i+1;
}
int main() {
    int nums2[] = {1, 1, 2, 2, 3, 4, 4, 5};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int newSize2 = removeDuplicates(nums2, size2);
    printf("Test Case 2: ");
    for (int i = 0; i < newSize2; i++) {
        printf("%d ", nums2[i]);
    }
    printf("\n");
    printf("\nNew size: %d\n", newSize2);
    return 0;
}