class LRUCache {
public:
    struct Node
    {
        int key;
        int val;
        Node* next = nullptr;
        Node* prev = nullptr;
    };

    int size = 0;
    int capacity = 0;

    unordered_map<int, Node*> track;

    Node* head = nullptr;
    Node* tail = nullptr;

    LRUCache(int capacity) 
    {
        this->capacity = capacity;
    }

    void removeNode(Node* node) 
    {
        if (head == node && tail == node)
        {
            head = nullptr;
            tail = nullptr;
        }
        else if (head == node)
        {
            head = head->next;
            head->prev = nullptr;
        }
        else if (tail == node)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
        {
            Node* prev = node->prev;
            Node* next = node->next;

            prev->next = next;
            next->prev = prev;
        }
        return;
    }

    void addToTail(Node* node) 
    {
        node->next = nullptr;

        if (head == nullptr)
        {
            node->prev = nullptr;
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            
            tail = tail->next;
            tail->next = nullptr;
        }
        return;
    }

    void moveToTail(Node* node) 
    {
        if (node == tail)
        {
            return;
        }
        removeNode(node);
        addToTail(node);
    }

    void put(int key, int value) 
    {
        if (track.contains(key))
        {
            Node* n = track[key];
            n->val = value;

            moveToTail(n);
        }
        else
        {
            Node* n = new Node{key, value, nullptr, nullptr};
            track[key] = n;

            if (size == capacity)
            {
                Node* oldHead = head;

                track.erase(oldHead->key);

                removeNode(head);
                addToTail(n);

                delete oldHead;
            }
            else
            {
                addToTail(n);
                size++;
            }
        }
        return;
    }
    
    int get(int key) 
    {
        if (track.contains(key))
        {
            Node* n = track[key];
            moveToTail(n);

            return n->val;
        }
        return -1;
    }
};
