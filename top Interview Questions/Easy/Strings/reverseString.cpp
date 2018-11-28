class Solution {
public:
    
    void reverse(string &s, int start, int end){
        while(start <= end){
            char t = s[start];
            s[start] = s[end];
            s[end] = t;
            start++;
            end--;
        }
    }
    
    string reverseString(string s) {
        
         reverse(s,0, s.size() - 1);
        return s;
    }
};