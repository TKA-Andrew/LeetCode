#include <stddef.h> // for NULL
#include <unordered_map>

class Node{
    public:
        int key;
        int val; 
        Node* prev;
        Node* next;
        Node(int key, int val){
            this->key = key;
            this->val = val;
    }
};

class DoubleList {
    private:
        Node* head;
        Node* tail;
        int size;
    
    public:
        DoubleList() {
            this->head = new Node(0,0);
            this->tail = new Node(0,0);
            head->next = tail;
            tail->prev = head;
            this->size = 0;
        }

    public: void addLast(Node* x) {
        x->prev = tail->prev;
        x->next = tail;
        tail->prev->next = x;
        tail->prev = x;
        size++;
    }
    
    public: void remove(Node* x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
        size--;
    }
    
    public: Node* removeFirst() {
        if (head->next == tail) {
            return NULL;
        }
        Node* first = head->next;
        remove(first);
        return first;
    }
    
    public: int getSize() {
        return size;
    }
    
};

class LRUCache {
private: std::unordered_map<int, Node*> map;
private: DoubleList cache;
private: int cap;
    
public:
    LRUCache(int capacity) {
        this->cap = capacity;
        this->cache = DoubleList();
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;        
        }
        makeRecently(key);
        return map[key]->val;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            deleteKey(key);
            addRecently(key, value);
            return;
        }
        if (cap==cache.getSize()) {
            removeLeastRecently();
        }
        addRecently(key, value);
    }

private: 
    void makeRecently(int key) {
        Node* x = map[key];
        cache.remove(x);
        cache.addLast(x);
    }
    
    void addRecently(int key, int val) {
        Node* x = new Node(key,val);
        cache.addLast(x);
        map[key] = x;
    }
    
    void deleteKey(int key) {
        Node* x = map[key];
        cache.remove(x);
        map.erase(key);
    }
    
    void removeLeastRecently() {
        Node* deletedNode = cache.removeFirst();
        int deletedKey = deletedNode->key;
        map.erase(deletedKey);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */