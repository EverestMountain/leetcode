#include <utility>

#include "header/common.h"

struct Node {
    int num;
    unordered_set<string> keys;

    Node(int num, unordered_set<string> keys) : num(num), keys(std::move(keys)) {}
};

class AllOne {
public:
    list<Node> lst;
    unordered_map<string, list<Node>::iterator> mp;
public:
    AllOne() {
        lst.clear();
        mp.clear();
    }

    void inc(string key) {
        if (mp.find(key) == mp.end()) {
            if (lst.empty() or lst.begin()->num != 1) {
                lst.push_front(Node(1, {key}));
            } else {
                lst.begin()->keys.insert(key);
            }
            mp[key] = lst.begin();
        } else {
            auto it = mp[key];
            if ((next(it) == lst.end()) or (next(it)->num != it->num + 1)) {
                lst.insert(next(it), Node{it->num + 1, {key}});
            } else {
                next(it)->keys.insert(key);
            }
            it->keys.erase(key);
            mp[key] = next(it);
            if (it->keys.empty()) {
                lst.erase(it);
            }
        }
    }

    void dec(string key) {
        if (mp.find(key) == mp.end()) {
            return;
        }
        if (mp[key]->num == 1) {
            mp[key]->keys.erase(key);
            if (mp[key]->keys.empty())lst.erase(lst.begin());
            mp.erase(key);
        } else {
            auto it = mp[key];
            if (it == lst.begin() or prev(it)->num != it->num - 1) {
                lst.insert(it, Node(it->num - 1, {key}));
            } else {
                prev(it)->keys.insert(key);
            }
            it->keys.erase(key);
            mp[key] = prev(it);
            if (it->keys.empty())
                lst.erase(it);
        }
    }

    string getMaxKey() {
        if(lst.empty()) return "";
        return *lst.rbegin()->keys.begin();
    }

    string getMinKey() {
        if(lst.empty()) return "";
        return *lst.begin()->keys.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
int test_lc() {
    AllOne allOne;
    allOne.inc("c");
    allOne.inc("b");
    allOne.inc("a");
    allOne.inc("a");
    allOne.inc("d");
    allOne.inc("d");
    allOne.inc("d");
    allOne.dec("a");
    allOne.dec("a");
    for (auto &x: allOne.lst) {
        cout << x.num << ":";
        for (auto &y: x.keys)
            cout << y << " ";
        cout << endl;
    }
    cout<<allOne.getMaxKey()<<endl;
    cout<<allOne.getMinKey()<<endl;
    return 0;
}

int main() {
    test_lc();
    return 0;
}