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

class LFUCache {
    
private: 
    std::unordered_map<int, int> keyToVal;
    std::unordered_map<int, int> keyToFreq;
    std::unordered_map<int, Node*> keyToNode;
    std::unordered_map<int, DoubleList> freqToKeys;
    int minFreq;
    int cap;
    
public:
    LFUCache(int capacity) {
        this->cap = capacity;
        this->minFreq = 0;
    }
    
    int get(int key) {
        if (keyToVal.find(key) == keyToVal.end()) {
            return -1;
        }
        increaseFreq(key);
        return keyToVal[key];
    }
    
    void put(int key, int value) {
        if (this->cap <= 0) return;        

        if (keyToVal.find(key) != keyToVal.end()) {
            keyToVal[key] = value;
            increaseFreq(key);
            return;
        }
        
        if (this->cap<=keyToVal.size()) {
            removeMinFreqKey();
        }
        
        keyToVal[key] = value;
        keyToFreq[key] = 1;
        Node* x = new Node(key, value);
        keyToNode[key] = x;
        if (freqToKeys[1].getSize() == 0) {
            freqToKeys[1] = DoubleList();      
        }
        freqToKeys[1].addLast(x);
        this->minFreq = 1; // if new key is added, then the minFreq must be 1
    }
    
private: 
    void removeMinFreqKey() {
        auto& keyList = freqToKeys[this->minFreq];
        Node* deletedNode = keyList.removeFirst();
        if (keyList.getSize() == 0) {
            freqToKeys.erase(this->minFreq);
            // doesnt need to update minFreq because it will be updated in put() function
        }
        int deletedKey = deletedNode->key;
        keyToVal.erase(deletedKey);
        keyToFreq.erase(deletedKey);
    }
    
    void increaseFreq(int key) {
        int freq = keyToFreq[key];
        keyToFreq[key] = freq + 1;
        int valueOfTheKey = keyToVal[key];
        Node* x = keyToNode[key];
        freqToKeys[freq].remove(x);
        if (freqToKeys[freq+1].getSize() == 0) {
            freqToKeys[freq+1] = DoubleList();      
        }
        freqToKeys[freq+1].addLast(x);
        if (freqToKeys[freq].getSize() == 0) {
            freqToKeys.erase(freq);
            if (freq == this->minFreq) {
                this->minFreq++;
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */