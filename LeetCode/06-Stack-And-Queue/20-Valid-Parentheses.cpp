/*
Problem Name : 20. Valid Parentheses
Platform     : LeetCode
Topic        : Stacks, String
Difficulty   : Easy
Link         : https://leetcode.com/problems/valid-parentheses/description/

Time Complexity : O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> str;
        for(int i = 0; i<n; i++){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '['){
                str.push(ch);
            }else{
                if(str.empty()) return false;
            
        

        char top = str.top();
        if((top == '(' && ch == ')') || 
            (top == '{' && ch == '}') ||
            (top == '[' && ch == ']')){
                str.pop();
            }else{ 
                return false;
            }
        }   
        }
        return str.empty();
    }
};