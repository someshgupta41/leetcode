class LRUCache {
public:
    
    // we would need a DLL and a map to simulate a cache
    
    list<int> _lru;
    
    unordered_map<int,pair<int,list<int>::iterator>> _cache;
    
    // size of the cache
    int _capacity;
    
    LRUCache(int capacity) {
        //initialize the cache capacity with the given value
        _capacity = capacity;
    }
    
    void use(unordered_map<int,pair<int,list<int>::iterator>>::iterator &it){
        //erase the value from the list
        _lru.erase(it->second.second);
        // move the key to the front of the list
        _lru.push_front(it->first);
        // update the location of the key,value pair in the map
        it->second.second = _lru.begin();
        
    }
    
    int get(int key) {
        
        // try to find if they key exists
        auto item = _cache.find(key);
        
        //if the key doesn't exist, then return -1
        if(item == _cache.end()){
            return -1;
        }
        
        //if the key exists, then move it to the front of the list and update the map too
        use(item);
        
        // return the value associated with the key
        return item->second.first;
        
    }
    
    void put(int key, int value) {
        
        // try to find if they key exists
        auto item = _cache.find(key);
        
        //if the key exists, update it in the list and the map
        if(item != _cache.end()){
            use(item);
            _cache[key] = {value,_lru.begin()};
            return ;
        }
        
        // new key,value to be inserted
        // check if the cache is full or not
        
        if(_cache.size() == _capacity){
            
            // if the cache is full , then remove the value from the back of the list
            // first get the value at the back and remove it from the cache
            _cache.erase(_lru.back());
            // once done, remove the value from the list
            _lru.pop_back();
        }
        
        // insert the key,value pair in the DLL and the map
        _lru.push_front(key);
        _cache.insert({key,{value,_lru.begin()}});
        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */