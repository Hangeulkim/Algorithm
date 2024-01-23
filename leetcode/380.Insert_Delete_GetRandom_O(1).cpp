class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int, int> umap;
    RandomizedSet() {
    }

    bool search(int val) {
        if(umap.find(val) == umap.end()){
            return false;
        }
        return true;
    }
    
    bool insert(int val) {
        if(search(val))
            return false;

        v.push_back(val);
        umap[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!search(val))
            return false;

        auto it = umap.find(val);
        v[it->second] = v.back();
        v.pop_back();
        umap[v[it->second]] = it->second;
        umap.erase(val);

        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */