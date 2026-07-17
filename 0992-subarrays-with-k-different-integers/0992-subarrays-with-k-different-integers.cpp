class Solution {
public:
    int func(vector<int> &nums, int k){
        // func -> no. of subarrays where different integer <= k

        int left = 0, right = 0, cnt = 0;
        map<int,int> mpp;
        while(right<nums.size()){
            mpp[nums[right]]++;
            while(mpp.size() > k){
                mpp[nums[left]]--;
                if(mpp[nums[left]] == 0)
                    mpp.erase(nums[left]);
                left = left + 1;
            }
            cnt = cnt + (right - left + 1);
            right ++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int result = func(nums, k) - func(nums, k - 1);
        return result;
    }
};