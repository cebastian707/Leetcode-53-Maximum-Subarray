/*By::Cebastian Santiago
* Leetcode 53
*/
#include<iostream>
#include<vector>
/*
	[-2, 1, -3, 4, -1, 2, 1, -5, 4]
	[ 0, 1,  0, 4, 3, 5, 6,  1, ,5]
	[-2,-1]
	[-2,1]
*/

int maxSubArray(std::vector<int>& nums) {
	//if only one element in the vector just return that
	if (nums.size()-1 ==0){
		return nums[0];
	}
	
	
	//varaibles and set the idx  to the first element in the vector
	int idx = 0;
	int max = INT_MIN;
	int count = 0;
	int neg = nums[0];
	
	//loop through the vector 
	for (size_t i = 0; i < nums.size(); i++) {
		//add the current index 
		idx += nums[i];
		//check if the idx is less then zero we 
		//only care about positive numbers
		if (idx <= 0) {
			//if max less then zero reset it to zero
			idx = 0;
			count++;
		}

		//else check the current biggest element at the current idx
		else {
			max = std::max(max, idx);
		}
	}


	
	
	//check if entire vector if filled with negative numbers
	if (count == nums.size()){
		for (size_t i = 1; i < nums.size(); i++) {
			if (neg < nums[i]) {
				neg = nums[i];
			}
		}
		max = neg;
	}
	return max;
}

int main(int argv, char* argc[]) {
	std::vector<int> nums = { -2, -1};

	std::cout << maxSubArray(nums) << std::endl;

}