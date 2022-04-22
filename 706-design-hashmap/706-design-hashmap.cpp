class MyHashMap {
public:
    vector<list<pair<int,int>>>m;
    int size;
    
    MyHashMap() {
    int size=1e6+1;
    m.resize(size);        
    }
    int hash(int key){
        return key%size;
    }
    list<pair<int,int>>::iterator search(int key){
        int index=hash(key);
        list<pair<int,int>>::iterator it=m[index].begin();
        while(it!=m[index].end()){
            // accessing the doubly  linked list pair values
        if(it->first==key)
            return it;
            it++;
        }
       
            return it;
        }
    // value will always be non negative 
    void put(int key, int value) 
    {
        int index=hash(key);
        remove(key);
        m[index].push_back(make_pair(key,value));
    }
    
    int get(int key) {
        int index=hash(key);
        list<pair<int,int>>::iterator it=search(key);
        if(it==m[index].end()){
            return -1;
        }
        return it->second;
    }
    
    void remove(int key) {
      int index=hash(key);
      list<pair<int,int>>::iterator it=search(key);  
      if(it!=m[index].end())
          m[index].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */