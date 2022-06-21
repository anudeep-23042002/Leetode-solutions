class RandomizedSet {
public:
    map<int,int>m;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(m[val]>0){
            return false;
        }
        m[val]=1;
        return true;
    }
    
    bool remove(int val) {
        if(m[val]!=1){
            return false;
        }
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        int k=rand()%(m.size());
        for(auto i=m.begin();i!=m.end() && k>=0;i++){
            if(k==0 && (*i).second>0){
                return (*i).first;
            }
            k-=1;
        }
        for(auto i=m.begin();i!=m.end();i++){
            if((*i).second>0){
                return (*i).first;
            }
        }
        return (*m.begin()).first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */