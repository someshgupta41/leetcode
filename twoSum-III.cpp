class TwoSum {
public:
    /** Initialize your data structure here. */
    
    unordered_map<int,int> m;
    
    
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        m[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        
        for(auto it = m.begin(); it!= m.end();++it){
            int i = it->first;
            int j = value - i;
            
            if((i == j) && ( it->second > 1)  || (i !=j && m.find(j) != m.end()) ){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */