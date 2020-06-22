/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

Example 2:

Input:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

Follow up:

    A straight forward solution using O(mn) space is probably a bad idea.
    A simple improvement uses O(m + n) space, but still not the best solution.
    Could you devise a constant space solution?


*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*
        //O(m*n) time | O(m + n) space
        unordered_set<int> rows;
        unordered_set<int> cols;
            for(int i = 0; i < matrix.size(); i++){
                for(int j = 0; j < matrix[0].size(); j++){
                    if(matrix[i][j] == 0){
                        rows.insert(i);
                        cols.insert(j);
                    }
                }
            }

            for(int i = 0; i < matrix.size(); i++){
                for(int j = 0; j < matrix[0].size(); j++){
                    if(rows.find(i) != rows.end() || cols.find(j) != cols.end()){
                        matrix[i][j] = 0;
                    }
                }
            }
        */

        //optimised approach
        //O(m * n) time | O(1) space
        bool isZeroCol = false;
        bool isZeroRow = false;

            for(int i = 0; i < matrix[0].size(); i++){
                if(matrix[0][i] == 0){
                    isZeroRow = true;
                    break;
                }
            }

            for(int i = 0; i < matrix.size(); i++){
                if(matrix[i][0] == 0){
                    isZeroCol = true;
                    break;
                }
            }

            for(int i = 1; i < matrix.size(); i++){
                for(int j = 1; j < matrix[0].size(); j++){
                    if(matrix[i][j] == 0){
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }

            for(int i = 1; i < matrix.size(); i++){
                for(int j = 1; j < matrix[0].size(); j++){
                    if(matrix[i][0] == 0 || matrix[0][j] == 0){
                        matrix[i][j] = 0;
                    }
                }
            }

            if(isZeroCol){
                for(int i = 0; i < matrix.size(); i++){
                    matrix[i][0] = 0;
                }
            }

            if(isZeroRow){
                for(int i = 0; i < matrix[0].size(); i++){
                    matrix[0][i] = 0;
                }
            }
    }
};
