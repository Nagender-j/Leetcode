class RandomizedCollection {
public:
    vector<int>a;
    unordered_map<int,unordered_set<int>>m;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
       
       bool res ;
       if(m.find(val)!=m.end()) {
            res = 0;
        } else {
            res = 1;
        }
        m[val].insert((int)a.size());
        a.push_back(val);
    
    
        return res;
    }
    
    void print(string t) {
        cout<<t<<endl;
        for(auto [num, positions] : m) {
            cout<<"THIS IS NUM :" << num<<endl;
            cout<<"These are positions"<<endl;
            for(int i : positions) {
                cout<< i<< " ";
            }
        }

        cout<<endl;
    }
    bool remove(int val) {
        if(m.find(val) == m.end())
            return 0;
        
        int last=a.back();
        // print("Before removal");
        if(last == val) {
           
            m[val].erase((int)a.size()-1);
            a.pop_back();
            if(m[val].size() == 0) {
                m.erase(m.find(val));
            }
            // print("after removal");
            return 1;

        }
       
        unordered_set<int>s=m[val];
        int idx=*(m[val].begin());
        m[val].erase(m[val].find(idx));
        if(m[val].size()==0)
            m.erase(m.find(val));
      
        m[last].erase(m[last].find((int)a.size()-1));
        m[last].insert(idx);
        
        if(m[last].size()==0)
            m.erase(m.find(last));
        
        a[idx]=last;
        
        a.pop_back();
        
        return 1;
        
        
    }
    
    int getRandom() {
        int r=rand()%a.size();
        
        return a[r];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */