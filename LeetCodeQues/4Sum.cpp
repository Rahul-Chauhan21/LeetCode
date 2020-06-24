/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]


*/
class Solution {
public:
    //O(n^3) time || O(1) space
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() < 4){
            return res;
        }

        sort(nums.begin(), nums.end());
            for(int i = 0; i < nums.size() - 3; i++){
                int target_3 = target - nums[i];
                    //three sum problem
                    for(int j = i + 1; j < nums.size() - 2; j++){
                        int target_2 = target_3 - nums[j];
                        //two sum problem
                        int leftIdx = j + 1;
                        int rightIdx = nums.size() - 1;

                        while(leftIdx < rightIdx){
                            int twoSum = nums[leftIdx] + nums[rightIdx];
                            if(twoSum < target_2) leftIdx++;

                            else if(twoSum > target_2) rightIdx--;

                            else{
                                vector<int>quadruplet(4,0);
                                quadruplet[0] = nums[i];
                                quadruplet[1] = nums[j];
                                quadruplet[2] = nums[leftIdx];
                                quadruplet[3] = nums[rightIdx];
                                res.push_back(quadruplet);

                                while(leftIdx < rightIdx && nums[leftIdx] == quadruplet[2]) leftIdx++;
                                while(leftIdx < rightIdx && nums[rightIdx] == quadruplet[3]) rightIdx--;
                            }
                        }
                        while(j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;
                    }
                while(i + 1 < nums.size() &&  nums[i] == nums[i + 1]) i++;
            }
        return res;
    }
};
