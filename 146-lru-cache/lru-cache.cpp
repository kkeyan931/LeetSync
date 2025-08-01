struct ListNodee {
    ListNodee *prev, *next;
    int key, value;
    ListNodee(int key, int value) : key(key), value(value) {
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
public:
    int size;
    unordered_map<int, ListNodee*> map;
    ListNodee *head, *tail;
    LRUCache(int capacity) {
        size = capacity;
        head = new ListNodee(-1, -1);
        tail = new ListNodee(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void attachFront(ListNodee* node) {
        ListNodee* nextNode = head->next;
        node->prev = head;
        node->next = nextNode;
        head->next = node;
        nextNode->prev = node;
    }
    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        ListNodee* node = map[key];

        ListNodee* nextNode = node->next;
        ListNodee* prevNode = node->prev;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        attachFront(node);
        return node->value;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            ListNodee* node = map[key];
            node->value = value;

            ListNodee* prevNode = node->prev;
            ListNodee* nextNode = node->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            attachFront(node);
            return;
        }

        if (map.size() == size) {
            ListNodee* deleteNode = tail->prev;
            ListNodee* prevNode = deleteNode->prev;
            prevNode->next = tail;
            tail->prev = prevNode;
            map.erase(deleteNode->key);
            delete deleteNode;
        }

        ListNodee* newNode = new ListNodee(key, value);
        map[key] = newNode;
        attachFront(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */