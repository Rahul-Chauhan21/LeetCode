// Day 21
/*
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation:
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

Example 2:

Input: matrix =
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation:
There are 6 squares of side 1.
There is 1 square of side 2.
Total number of squares = 6 + 1 = 7.



Constraints:

    1 <= arr.length <= 300
    1 <= arr[0].length <= 300
    0 <= arr[i][j] <= 1

*/
/*
    A particular bottom right corner of a sub matrices determines the max size of sub square matrices
    ending at that corner position it can be extended by a value 1 if all the positions adjacent to it
    have the same value or else we take the minimum of those three values.

    The count of unique sub square matrices is the sum of count of squares ending at cell (i,j) since
    every sub square matrix ending at this cell is a different matrix. draw an example to visualize.
*/
class Solution {
public:
    //O(N*M) time | O(N*M) space
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp((n),vector<int> (m));
        int count = 0; // number of square matrices with all 1's

        // fill 1st row
        for(int i = 0; i < m; i++){
            dp[0][i] = matrix[0][i];
            count += dp[0][i];
        }

        // fill 1st col
        for(int i = 1; i < n; i++){
            dp[i][0] = matrix[i][0];
            count += dp[i][0];
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j] == 1){
                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1], dp[i-1][j-1])); // extending the size of sub square matrices ending at the current position
                }
                count += dp[i][j];
            }
        }
        return count;
    }
};
