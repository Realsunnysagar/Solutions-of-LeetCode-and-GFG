class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        // longer prefix match
        int ind = -1;
        for(int i = n-2 ; i>= 0 ; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }

        // Edge case 5,4,3,2,1
        if(ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }    
        // find > ind , but smallest one so that you stay close.
        for(int i = n-1; i>= ind ; i--){
            if(nums[i] > nums[ind]){
                swap(nums[i], nums[ind]);
                break;
            }
        }
        // Try to place remaining in minimum sorted order
        reverse(nums.begin() + ind + 1, nums.end());
    }
};