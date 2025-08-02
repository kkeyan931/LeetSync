struct ListNodee {
    ListNodee *next, *prev;
    int key, value, freq;

    ListNodee(int key, int value) : key(key), value(value) {
        next = nullptr;
        prev = nullptr;
        freq = 1;
    }
};

struct List {
    ListNodee *head, *tail;
    int size;
    List() {
        head = new ListNodee(-1, -1);
        tail = new ListNodee(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(ListNodee* node) {
        ListNodee* nextNode = head->next;
        node->next = nextNode;
        head->next = node;
        nextNode->prev = node;
        node->prev = head;
        size++;
    }
    ListNodee* removeTail() {
        ListNodee* deleteNode = tail->prev;
        ListNodee* prevNode = deleteNode->prev;
        prevNode->next = tail;
        tail->prev = prevNode;
        size--;
        return deleteNode;
    }
    void removeNode(ListNodee* node) {
        ListNodee* nextNode = node->next;
        ListNodee* prevNode = node->prev;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
        size--;
    }
    ~List() {
        // clean dummy nodes; real nodes are managed by cache
        delete head; delete tail;
    }
};
class LFUCache {
public:
    LFUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        if (nodeMap.find(key) == nodeMap.end()) {
            return -1;
        }
        ListNodee* node = nodeMap[key];
        upgradeNode(node);

        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        if (nodeMap.find(key) != nodeMap.end()) {
            ListNodee* node = nodeMap[key];
            node->value = value;
            upgradeNode(node);
            return;
        }

        if (this->capacity == nodeMap.size()) {
            List* list = freqMap[minFreq];
            ListNodee *node = list->removeTail();
            nodeMap.erase(node->key);
            delete node;
            if(list->size == 0) {
                freqMap.erase(minFreq);
                delete list;
            }
        }

        ListNodee* newNode = new ListNodee(key, value);
        minFreq = 1;
        if (freqMap.find(1) == freqMap.end()) {
            freqMap[1] = new List();
        }
        freqMap[1]->addFront(newNode);
        nodeMap[key] = newNode;
    }

private:
    int capacity;
    int minFreq = 1;
    unordered_map<int, List*> freqMap;
    unordered_map<int, ListNodee*> nodeMap;
    void upgradeNode(ListNodee* node) {
        int oldFreq = node->freq;
        List* oldList = freqMap[oldFreq];

        oldList->removeNode(node);

        if (oldList->size == 0) {
            freqMap.erase(oldFreq);
            if(minFreq == oldFreq) {
                minFreq = minFreq + 1;
            }
        }
        int newFreq = oldFreq + 1;
        List* newList;

        if (freqMap.find(newFreq) == freqMap.end()) {
            newList = new List();
            freqMap[newFreq] = newList;
        }
        newList = freqMap[newFreq];
        node->freq = newFreq;
        newList->addFront(node);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */