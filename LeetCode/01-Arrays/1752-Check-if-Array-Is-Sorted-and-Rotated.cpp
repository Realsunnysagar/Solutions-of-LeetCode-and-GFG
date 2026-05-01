class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return true;

        // step 01 skip 1st non decreasing curve 
        int pos = 1;
        while(pos < n && nums[pos] >= nums[pos-1])
            pos++;
        
        if(pos == n) return true; //if entire array is still non decreasing 
        if(nums[pos] > nums[0]) return false; // checking if start of new curve is not smaller then the 1st of last 
        if(pos == n-1) return true;

        // step 2 check 2nd non decreasing curve with adj and start of first curve
        pos += 1;
        while(pos<n && nums[pos] <= nums[0] && nums[pos] >= nums[pos-1])
            pos++;
        return pos == n;
    }
};