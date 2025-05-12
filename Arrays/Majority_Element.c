#include<stdio.h>
#include <stdlib.h>
int compare(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}

/*
    optimized Aproach TC-o(nlogn);
*/
int MajorityElement(int* nums,int numsSize)
{
    //sort
    qsort(nums,numsSize,sizeof(nums[0]),compare);

    //Count Frequency 
    int freq=1,ans=nums[0];
    for(int i=1;i<numsSize;i++)
    {
        if(nums[i]==nums[i-1])
        {
            freq++;
        }else{
            freq=1;
            ans=nums[i];
        }
        if(ans>numsSize/2)
        {
            return ans;
        }
    }
    return ans;
}

/*
More Algorithm TC-o(n)
*/
int Moor_MajorityElement(int* nums,int numsSize)
{
    int freq=0,ans=0;
    for(int i=0;i<numsSize;i++)
    {
        if(freq==0)
        {
            ans=nums[i];
        }
        if(ans=nums[i])
        {
            freq++;
        }else{
            freq--;
        }
    }
    return ans;
}
int main()
{
    int nums[]={3,2,3} ; //test case 1
    //int nums[] = {2,2,1,1,1,1,2};//test case 2
    int ans=Moor_MajorityElement(nums,3);
    printf("Majority Element %d",ans);
}