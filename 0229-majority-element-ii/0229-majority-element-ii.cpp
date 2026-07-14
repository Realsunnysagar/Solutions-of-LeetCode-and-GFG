class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1, el2;
        int cnt1 = 0, cnt2 =0;

        for(int x : nums){
            if(x == el1){
                cnt1++;
            }else if(x == el2){
                cnt2++;
            }else if(cnt1 == 0){
                el1 = x;
                cnt1 = 1;
            }else if(cnt2 == 0){
                el2 = x;
                cnt2 = 1;
            }else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for(int x : nums){
            if (x == el1) cnt1++;
            else if(x == el2) cnt2++;
        }

        vector<int> ans;
        if(cnt1 > (nums.size() / 3))
            ans.push_back(el1);
        if(cnt2 > (nums.size() / 3))
            ans.push_back(el2);
    return ans;
    }
};