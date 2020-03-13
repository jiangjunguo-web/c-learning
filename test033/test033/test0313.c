#include<stdio.h>
#include <stdlib.h>

int majorityElement(int* nums, int numsSize){
	int count = 1;
	int maj = nums[0];
	for (int i = 1; i<numsSize; i++) {
		if (maj == nums[i]) {
			count++;
		}
		else {
			count--;
			if (count == 0) {
				maj = nums[i + 1];
			}
		}
	}
	return maj;
}

int main()
{
	int nums[] = { 3,3,4};
	int numsSize = 3;
	printf("%d", majorityElement(nums, numsSize));
	system("pause");
	return 0;
}
