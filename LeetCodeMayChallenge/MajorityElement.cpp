//Day 6
/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3

Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

*/
//O(N) O(1)
//Boyer-Moore Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majorityElement = nums[0];
        int count = 1;

            for(int i = 1; i < n; i++){
                if(nums[i] == majorityElement){
                    count++; //if the major element occurs N/2 times it'll become the candidate element by the end of the traversal
                }
                else{
                    count--;
                        if(count == 0){
                            majorityElement = nums[i];
                            count = 1;
                        }
                }
            }
        return majorityElement; //since major element always exists
    }
};
