/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1){
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> mergedIntervals;
        mergedIntervals.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++) {
            if(mergedIntervals.back()[1] >= intervals[i][0]) mergedIntervals.back()[1] = max(mergedIntervals.back()[1] , intervals[i][1]);
            else mergedIntervals.push_back(intervals[i]);
        }
        return mergedIntervals;
    }
};
