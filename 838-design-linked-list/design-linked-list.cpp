class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int val) : val(val) {}
    };
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int size = 0;
    MyLinkedList() {}

    int get(int index) {
        if (index >= size) {
            return -1;
        }
        ListNode* ptr = head;
        while (index-- && ptr) {
            ptr = ptr->next;
        }
        return ptr->val;
    }

    void addAtHead(int val) {
        if (size == 0) {
            head = new ListNode(val);
            tail = head;
            size = 1;
            return;
        }
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);

        if (tail == nullptr) {
            tail = newNode;
            head = newNode;
            size = 1;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        if(index == 0) {
            addAtHead(val);
            return;
        }
        size++;
        ListNode* ptr = head;

        while (--index && ptr) {
            ptr = ptr->next;
        }
        ListNode* newNode = new ListNode(val);

        ListNode* next = ptr->next;
        ptr->next = newNode;
        newNode->next = next;
    }

    void deleteAtIndex(int index) {
        if (index >= size) {
            return;
        }
        if (index == 0) {
            ListNode* deleteNode = head;
            head = head->next;
            delete deleteNode;
            size--;
            return;
        }
        ListNode* ptr = head;
        ListNode* prev = nullptr;
        while (index-- && ptr) {
            prev = ptr;
            ptr = ptr->next;
        }
        ListNode* deleteNode = ptr;
        if(deleteNode == tail) {
            tail = prev;
        }
        prev->next = ptr->next;
        delete deleteNode;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */