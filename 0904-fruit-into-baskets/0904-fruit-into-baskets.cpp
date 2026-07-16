class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int k = 2;
        int left = 0, right = 0, maxLen = 0;
        map<int,int> mpp;
        while(right < fruits.size()){
            mpp[fruits[right]]++;
            if(mpp.size() > k){
                mpp[fruits[left]]--;
                if(mpp[fruits[left]] == 0) mpp.erase(fruits[left]);
                left++;
            }
            if(mpp.size() <= k){
                maxLen = max(maxLen, right - left + 1);
            }
            right ++;
        }
        return maxLen;
    }
};