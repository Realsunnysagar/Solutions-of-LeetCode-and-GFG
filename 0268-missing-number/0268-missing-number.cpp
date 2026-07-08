class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int x : nums){
            total += x;
        }
        int nsum = 0;
        for(int i = 0; i<= n; i++){
            nsum += i;
        }

        return (nsum-total);
    }
};