class Solution {
public:
    void generate(int open , int close, int n, string curr, vector<string> &ans){

        // base case
        if(curr.length() == 2*n){
            ans.push_back(curr);
            return;
        }
        // add open
        if(open < n){
            generate(open + 1, close, n, curr + "(" , ans);
        }
        // add close
        if(close < open){
            generate(open, close + 1, n, curr + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        generate(0, 0, n,"", ans);
        return ans;
    }
};