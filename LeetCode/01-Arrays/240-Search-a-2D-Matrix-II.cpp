/*
Problem Name : 240. Search a 2D Matrix II
Platform     : LeetCode
Topic        : 2D-Arrays,Matrix
Difficulty   : Medium
Link         : https://leetcode.com/problems/search-a-2d-matrix-ii/description/

Time Complexity : O(m + n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();  //no. of rows
        int n = matrix[0].size();   //no. of colms
        
        int row = 0;
        int col = n-1;

        while(row < m && col >= 0){
            if(matrix[row][col] == target) return true;   
            else if(matrix[row][col] > target) col--;
            else row++;
        }
        return false;
    }
};