//Day 8
/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the
coordinate of a point. Check if these points make a straight line in the XY plane.

Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Constraints:

    2 <= coordinates.length <= 1000
    coordinates[i].length == 2
    -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
    coordinates contains no duplicate point.

*/

class Solution {
public:
    //O(N)
    //slope of a straight line between any two points is same.
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int points = coordinates.size();
        if(points == 2)
            return true;
        int xDiff = abs(coordinates[1][0] - coordinates[0][0]);
        int yDiff = abs(coordinates[1][1] - coordinates[0][1]);
        int curr_xDiff, curr_yDiff;
            for(int i = 2; i < points; i++){
                curr_xDiff = abs(coordinates[i][0] - coordinates[i-1][0]);
                curr_yDiff = abs(coordinates[i][1] - coordinates[i-1][1]);
                if(yDiff*curr_xDiff != xDiff*curr_yDiff){ //to avoid division by 0
                    return false;
                }
            }
        return true;
    }
};
