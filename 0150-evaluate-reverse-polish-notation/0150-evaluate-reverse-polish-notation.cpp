class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;

        for(string token:tokens){

            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.pop();

                if(token == "+")
                    st.push(top2+top1);
                else if(token == "-")
                    st.push(top2 - top1);
                else if(token == "*")
                    st.push(top2 * top1);
                else
                    st.push(top2 / top1);
            }else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};