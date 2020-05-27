// Day 26
/*
    Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:

Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:

Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Note: The length of the given binary array will not exceed 50,000.
*/

/*
    Approach: if we encounter a sum value that has been seen, the values in b/w didn't contribute
    to the sum & the equivalent sum of these values is 0 and so the count of 0's & 1's in this range is
    equal
*/
class Solution {
public:
    // O(n) time | O(n) space
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> map;
        int maxLen = 0, sum = 0;
            for(int i = 0; i < nums.size(); i++){
                sum += nums[i] == 1 ? 1 : -1;
                if(sum == 0){
                    maxLen = max(maxLen, i + 1);
                }
                else if(map.find(sum) != map.end()){ //equivalent sum of that range of values is 0
                    maxLen = max(maxLen, i - map[sum]);
                }
                else{// first occurence of that sum
                    map[sum] = i;
                }
            }
        return maxLen;
    }
};
