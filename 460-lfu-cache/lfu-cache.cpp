struct Node {
    Node *next, *prev;
    int key, value, freq;

    Node(int key, int value) : key(key), value(value) {
        next = nullptr;
        prev = nullptr;
        freq = 1;
    }
};

struct List {
    Node *head, *tail;
    int size;
    List() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node* node) {
        Node* nextNode = head->next;
        node->next = nextNode;
        head->next = node;
        nextNode->prev = node;
        node->prev = head;
        size++;
    }
    Node* removeTail() {
        Node* deleteNode = tail->prev;
        Node* prevNode = deleteNode->prev;
        prevNode->next = tail;
        tail->prev = prevNode;
        size--;
        return deleteNode;
    }
    void removeNode(Node* node) {
        Node* nextNode = node->next;
        Node* prevNode = node->prev;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
        size--;
    }
    ~List() {
        // clean dummy nodes; real nodes are managed by cache
        delete head;
        delete tail;
    }
};
class LFUCache {
public:
    LFUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        if (nodeMap.find(key) == nodeMap.end()) {
            return -1;
        }
        Node* node = nodeMap[key];
        upgradeNode(node);

        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;
        if (nodeMap.find(key) != nodeMap.end()) {
            Node* node = nodeMap[key];
            node->value = value;
            upgradeNode(node);
            return;
        }

        if (this->capacity == nodeMap.size()) {
            List* list = freqMap[minFreq];
            Node* node = list->removeTail();
            nodeMap.erase(node->key);
            delete node;
            if (list->size == 0) {
                freqMap.erase(minFreq);
                delete list;
            }
        }

        Node* newNode = new Node(key, value);
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
    unordered_map<int, Node*> nodeMap;
    void upgradeNode(Node* node) {
        int oldFreq = node->freq;
        List* oldList = freqMap[oldFreq];

        oldList->removeNode(node);

        if (oldList->size == 0) {
            freqMap.erase(oldFreq);
            if (minFreq == oldFreq) {
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