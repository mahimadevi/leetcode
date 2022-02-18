class Solution {
public:
    string makeGood(string s) {
            stack<char> st;
	
	st.push(s[s.size()-1]);               
	/*pushing the last element to stack; LeEeetcode="e"*/
	
    for(int i=s.size()-2;i>=0;i--){     
	/*traversal from second last element of string as we need to make it a string at last and to preserve the order*/
        if(st.size()){
		
		/*checking if current element is lower case('a'=='A'+32) of element present on top of stack or if current element is uppercase('A'=='a'-32) of element present on top of stack*/
	   if(s[i]==st.top()+32 || s[i]==st.top()-32) 
            st.pop();  
			/*if yes, remove the element since it is making it bad string*/
        
        else
            st.push(s[i]);              
			/* else push the element */
        }
		
        else
            st.push(s[i]);
    }
    string ans="";
	
    while(st.size()){
	//pushing the elements of stack as a string
        ans+=st.top();
        st.pop();
    }
    return ans;
}

};