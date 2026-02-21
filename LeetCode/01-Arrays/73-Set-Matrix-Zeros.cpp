/*
Problem Name : 73. Set Matrix Zeroes
Platform     : LeetCode
Topic        : 2D-Arrays,Matrix
Difficulty   : Medium
Link         : https://leetcode.com/problems/set-matrix-zeroes/description/

Time Complexity : O(m * n)
Space Complexity: O(1)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstColZero = false;
        bool firstRowZero = false;

        // checking 1st row
        for(int j=0; j<n; j++){
            if(matrix[0][j] == 0){
                firstRowZero = true;
                break;
            }
        }
        // checking 1st col
        for(int i=0; i<m; i++){
            if(matrix[i][0]==0){
                firstColZero = true;
                break;
            }
        }
        // mark row and col
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;

                }
            }
        }

        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstRowZero){
            for(int j = 0; j < n; j++) matrix[0][j] = 0;
        }
        if(firstColZero){
            for(int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    }
};