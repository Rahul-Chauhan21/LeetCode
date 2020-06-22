/*Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    //O(n^2) time | O(1) space
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
            for(int i = 0; i < numRows; i++){
                result[i].resize(i + 1);
                    for(int j = 0; j <= i; j++){
                        if(j == 0 || j == i){
                            result[i][j] = 1;
                        }
                        else{
                            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
                        }
                    }
            }
        return result;
    }
};