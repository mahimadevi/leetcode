class Solution {
public:
    string reverseVowels(string s) {
        vector<int> vec;
        int si = s.size();
        for(int i=0; i<si; i++){
            char cc = tolower(s[i]);
            if(cc == 'a' || cc == 'e' || cc == 'i' || cc == 'o' || cc == 'u'){
                vec.push_back(i);
            }
        }
        int total = vec.size();

        for(int i= 0; i<total/2; i++){
            swap(s[vec[i]], s[vec[total-i-1]]);
        }
        return s;
    }
};