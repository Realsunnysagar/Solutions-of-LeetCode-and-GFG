/*
We have to solve this in two steps
1. we will take transpose of the matrix
2. then we will reverse each row 
-finally it will be a rotated image of previous 
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0; i<n ; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i = 0; i<n ; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};