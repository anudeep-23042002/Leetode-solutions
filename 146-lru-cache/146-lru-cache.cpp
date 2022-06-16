class LRUCache {
public:
    int cap=0;
    int count=0;
    unordered_map<int,pair<list<int>::iterator,int>>m;
    list<int>v;
    LRUCache(int capacity) {
        cap=capacity;
    }
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        else{
            put(key,m[key].second);
        }
        return m[key].second;
    }
    
    void put(int key, int value) {
        if(m.find(key)==m.end()){
            if(cap==count){
                int k=v.back();
                v.pop_back();
                m.erase(k);
            }
            else{
                count+=1;
            }
        }
        else{
            v.erase(m[key].first);
        }
        
        v.push_front(key);
        m[key]={v.begin(),value};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */