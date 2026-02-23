/*
Problem Name : 54. Spiral Matrix
Platform     : LeetCode
Topic        : 2D-Arrays,Matrix
Difficulty   : Medium
Link         : https://leetcode.com/problems/spiral-matrix/description/

Time Complexity : O(m * n)
Space Complexity: O(m * n)
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int srow = 0, scol = 0 ;
        int erow = m - 1, ecol = n - 1;

        vector<int> ans;

        while(srow <= erow && scol <= ecol){        //scol->left ans srow = top
            // top
            for(int j = scol; j<= ecol; j++){
                ans.push_back(matrix[srow][j]);
            }

            // right
            for(int i = srow+1; i<=erow ; i++ ){
                ans.push_back(matrix[i][ecol]);
            }
            
            // bottom
            for(int j = ecol-1; j>=scol; j--){ //scol->left ans srow = top
                if(srow == erow){
                    break;
                }
                ans.push_back(matrix[erow][j]);
            }
            // left
            for(int i = erow - 1; i>srow; i--){
                if(scol == ecol){
                    break;
                }
                ans.push_back(matrix[i][scol]);
            }

            srow++, scol++;
            erow--, ecol--;
        }
        return ans;
    }
};