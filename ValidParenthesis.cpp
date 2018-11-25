class Solution {
public:
    bool isValid(string s) {
        
        if(s.size() == 0){
            return true;
        }
        
        // basic intuition is to use a stack
        // if an opening brace is found,  push in the stack 
        // if a closing brace is found. pop from the stack
        // put other sanity check to not pop from an empty stack
        
        // for a string to be valid, it should equal number of opening and closing braces
        
        // in the end , stack size should be 0 or stack should be empty!
        
        stack<char> st;
        
        for(char c : s){
            switch(c){
                case '(':
                case '[':
                case '{': st.push(c); break;
                case '}': if(st.empty() || st.top() != '{') return false; st.pop(); break;
                case ']': if(st.empty() || st.top() != '[') return false; st.pop(); break;
                case ')': if(st.empty() || st.top() != '(') return false; st.pop(); break;
                    
            }
        }
        return st.empty();
        
    }
};