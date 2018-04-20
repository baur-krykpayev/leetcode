/* 
 * Problem: 146. LRU Cache [hard]
 * Source : https://leetcode.com/problems/lru-cache/description/
 * Solver : Baur Krykpayev
 * Date   : 4/20/2018
 */

class LRUCache {
public:
    LRUCache(int capacity) 
    {
        this->capacity = capacity;  
    }
    
    int get(int key) 
    {
        auto it = cache.find(key);
        if (it == cache.end()){return -1;}
        touch(it);
        return it->second.first;        
    }
    
    void put(int key, int value) 
    {
        auto it = cache.find(key);
        if (it == cache.end())
        {
            if (cache.size() == capacity)
            {
                cache.erase(least.back());
                least.pop_back();
            }
            
            least.push_front(key);
        }
        else
        {
            touch(it);
        }
        
        cache[key] = make_pair(value, least.begin());        
    }

private:
    int capacity;
    list<int> least;
    unordered_map<int, pair<int, list<int> :: iterator>> cache;        
    
    void touch(unordered_map<int, pair<int, list<int> :: iterator>> :: iterator it)
    {
        least.erase(it->second.second);
        least.push_front(it->first);
        it->second.second = least.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */