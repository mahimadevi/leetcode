class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        //stack mein tb tk puch kro jb tk last paranthesis na aa jaye
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ']') {
                st.push(s[i]);
            }
            else
            {
        //1 naya substring bana kr usme tb tk char puch kro jb tak opening "[" na aa jaye
                string substr = "";
                
                while(st.top() != '['){
                    substr = st.top() + substr ;
                    st.pop();
                }  
                st.pop();   // '[' pop krne ke liye taki hme '[' pehle wala number mile
                // number pta krna ke liye use ek nayi string mein daal dia for ex: 345
                string number = "";
                while(!st.empty() && isdigit(st.top())){
                    number = st.top() + number;
                    st.pop();
                }
                int k_time = stoi(number);    // convert string to number
                //abhi apne stack mein hm substring(ab) put kr rhe k(number) times
                while(k_time--){
                    for(int p = 0; p < substr.size() ; p++)
                        st.push(substr[p]);
                }
            }
        }
        //ek nayi string bana rhe aur usme finally sare stack element store kr rhe
        s = "";
        while(!st.empty()){
            s = st.top() + s;
            st.pop();
        }
        return s;
    }
};