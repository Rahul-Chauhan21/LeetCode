// Day 23
/*
Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)



Example 1:

Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.



Note:

    0 <= A.length < 1000
    0 <= B.length < 1000
    0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9

*/
class Solution {
public:
    // O(N) time
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int i = 0, j = 0;
        vector<vector<int>> result;
        vector<int> temp(2); // to push to resultant vector
        while(i < A.size() && j < B.size()){
            // ending time of A >= starting time of B and starting time of A is <= ending time of B
            if(B[j][0] <= A[i][1] && A[i][0] <= B[j][1]){
                temp[0] = max(A[i][0],B[j][0]);
                temp[1] = min(A[i][1],B[j][1]);
                result.push_back(temp);
            }
            //check which interval has more span
            if(A[i][1] > B[j][1]){
                j++;
            }
            else{
                i++;
            }
        }
        return result;
    }
};
