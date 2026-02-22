/*
Problem Name : 59. Spiral Matrix II
Platform     : LeetCode
Topic        : 2D-Arrays,Matrix
Difficulty   : Medium
Link         : https://leetcode.com/problems/spiral-matrix-ii/description/

Time Complexity : O(n^2)
Space Complexity: O(n^2)
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top = 0, left = 0, bottom = n-1, right = n-1;
        int val = 1;
        vector<vector<int>>matrix(n, vector<int>(n));

        while(left <= right && top<=bottom){
            for(int i = left; i<=right; i++){   //left to right
                matrix[top][i] = val++;
            }
            top++;
            for(int j = top; j<=bottom; j++){   //top to bottom
                matrix[j][right] = val++;
            }
            right--;
            if(top<=bottom){        //right to left
                for(int i = right; i>=left; i--){
                    matrix[bottom][i] = val++;
                }
                bottom --;
            }
            if(left<=right){        //bottom to top
                for(int i = bottom; i>=top; i--){
                     matrix[i][left] = val++;
                 }
                left++;
            }
        }
        return matrix; 
    }
};