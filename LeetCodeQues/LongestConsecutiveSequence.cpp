class Solution {
public:
    //O(n) time | O(n) space
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <=1){
            return nums.size();
        }
        unordered_set<int> values;
            for(int i = 0; i < nums.size(); i++){
                if(values.find(nums[i]) == values.end()){
                    values.insert(nums[i]);
                }
            }
        int maxRes = 0;
            for(int i = 0; i < nums.size(); i++){
                if(values.find(nums[i] - 1) == values.end()){
                    int j = nums[i];
                    while(values.find(j) != values.end()){
                        j++;
                        maxRes = max(maxRes, j - nums[i]);
                    }
                }
            }
        return maxRes;
    }
};
