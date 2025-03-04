#include<stdio.h>
#include<stdlib.h>
int* getConcatenation(int* nums, int numsSize, int* returnSize) {

    *returnSize = 2 * numsSize;

    int *ans = (int*)malloc((*returnSize) * sizeof(int));

 
    for (int i = 0; i < numsSize; i++) {
        ans[i] = nums[i];               
        ans[i + numsSize] = nums[i];  
    }

    return ans;
}
int main(){
    int nums [] = {1,2,1};
    int numsSize = 3;
    int returnSize;
    int *answer = getConcatenation(nums,numsSize,&returnSize);
    for(int i = 0 ;i<2*numsSize;i++){
        printf("%d ",answer[i]);
    }
    free(answer);
    return 0;
}