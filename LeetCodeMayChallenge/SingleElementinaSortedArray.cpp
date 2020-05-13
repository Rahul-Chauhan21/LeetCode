//Day 12
/*
You are given a sorted array consisting of only integers where every element
appears exactly twice, except for one element which appears exactly once.
Find this single element that appears only once.



Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10



Note: Your solution should run in O(log n) time and O(1) space.

*/

class Solution {
// array:   1 1 2 2 3 4 4
// indices: 0 1 2 3 4 5 6
// pair index property says if a pair exists it has a starting index always even
// 2 2 in example array have indices 2 3.
public:
    int singleNonDuplicate(vector<int>& nums) {
        //using pair index property we can partition the array for searching the unique element
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int high = nums.size() - 1;
        int low = 0;
        int mid;

        //boundary checks
        if(high == 0)
            return nums[0];
        else if(nums[0]!=nums[1])
            return nums[0];
        else if(nums[high]!=nums[high -1])
            return nums[high];

        //O(Log (N)) O(1)
        while(low <= high){
            mid = low + (high - low)/2;

            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
                return nums[mid];
            //partion property
            if((mid%2 == 0 && nums[mid] == nums[mid+1])
              || (mid%2==1 && nums[mid] == nums[mid-1])) //no disturbance in the order
            {
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};
