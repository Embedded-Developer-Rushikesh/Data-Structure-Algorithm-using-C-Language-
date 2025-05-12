#include<stdio.h>
#include <stdlib.h>
int* majorityElement(int* nums, int numsSize, int* returnSize)
{
    if(numsSize==0)
    {
        *returnSize=0;
        return NULL;
    }
    int candidate1=0,candidate2=0,count1=0,count2=0;

    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==candidate1)
        {
            count1++;
        }else if(nums[i]==candidate2)
        {
            count2++;
        }else if(count1==0)
        {
            candidate1=nums[i];
            count1=1;
        }else if(count2==0)
        {
            candidate2=nums[i];
            count2=1;
        }else{
            count1--;
            count2--;
        }
    }
    count1=0,count2=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==candidate1)
        {
            count1++;
        }else if(nums[i]==candidate2)
        {
            count2++;
        }else{
            ;
        }
    }

    int* ans=NULL;
    *returnSize=0;

    if(count1>numsSize/3)
    {
        ans=(int*)malloc(sizeof(int));
        ans[0]=candidate1;
        *returnSize=1;
    }
    if(count2>numsSize/3)
    {
        if(*returnSize==0)
        {
            ans=(int*)malloc(sizeof(int));
            ans[0]=candidate2;
            *returnSize=1;

        }else{
            ans=(int*)realloc(ans,2*sizeof(int));
            ans[1]=candidate2;
            *returnSize=2;
        }

    }
    return ans;
}
int main() {
    int nums1[] = {1,2};
    int size1;
    int* res1 = majorityElement(nums1, 2, &size1);
    printf("Output: [");
    for (int i = 0; i < size1; i++) {
        if (i > 0) printf(", ");
        printf("%d", res1[i]);
    }
    printf("]\n");
    free(res1);

    return 0;
}