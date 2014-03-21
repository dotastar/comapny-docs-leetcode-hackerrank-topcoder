#include <list>
#include <unordered_map>

using namespace std;

class LRUCache{
public:
    LRUCache(int capacity):capa(capacity) {

    }

    int get(int key) {
        unordered_map<int, __Val>::iterator wh = cache.find(key);
        if(wh != cache.end()){
            lru.splice(lru.begin(), lru, wh->second);
            return wh->second->second;
        }
        return -1;
    }

    void set(int key, int value) {
        unordered_map<int, __Val>::iterator wh = cache.find(key);
        if(wh != cache.end()){
            wh->second->second = value;
            lru.splice(lru.begin(), lru, wh->second);
        }else{
            lru.push_front(make_pair(key, value));
            cache.insert(make_pair(key, lru.begin()));
            while(cache.size() > capa){
                cache.erase(lru.back().first);
                lru.pop_back();
            }
        }
    }
private:
    list<pair<int, int> > lru;  //key + value
    typedef list<pair<int, int> >::iterator __Val;
    unordered_map<int, __Val> cache;
    int capa;
};

int main()
{
}
