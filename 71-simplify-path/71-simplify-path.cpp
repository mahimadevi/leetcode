class Solution {
public:
    string simplifyPath(string path) {
        vector<string>v;
        string ans;
        
        for(int i=0;i<path.length();i++){
            string temp;
            
            while(i<path.length() && path[i]!='/'){
                temp += path[i];
                i++;
            }
            if(temp == "." || temp == "") continue;
            
            else if(temp == "..")
            {
                if(v.size()>0)
                    v.pop_back();
            }
            else
                v.push_back(temp);
        }
        
        if(v.size()==0)
            return "/";
        
        for(int i=0;i<v.size();i++)
            ans += "/" + v[i];
        
        return ans;
    }
};