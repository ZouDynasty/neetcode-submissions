class LRUCache {
public:
    struct Node
    {
        // must store key so you can remove values based on key in the future
        int key;
        int val;

        // must store prev and next
        Node* next = nullptr;
        Node* prev = nullptr;
    };

    int size = 0;
    int capacity = 0;

    // use to get location of node
    unordered_map<int, Node*> track;

    Node* head = nullptr;
    Node* tail = nullptr;

    LRUCache(int capacity) 
    {
        this->capacity = capacity;
    }

    void removeNode(Node* node) 
    {
        // if only one node in the list, we reset head and tail
        if (head == node && tail == node)
        {
            head = nullptr;
            tail = nullptr;
        }
        // if the node to remove is the head, we increment and replace the head. 
        else if (head == node)
        {
            head = head->next;
            head->prev = nullptr;
        }
        // if the node to remove is the tail, we remove the tail. 
        else if (tail == node)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        // if the node is somewhere in the middle of the list, we use adjust the nodes prev and next. 
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
        // if we are adding to the tail, the next value of the node must be nullptr.
        node->next = nullptr;

        // if there is no head and tail, or there is nothing in cache, we set head and tail to the current node. 
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
        // if node is already tail, nothing to do
        if (node == tail)
        {
            return;
        }
        // otherwise, remove node and then add it to tail. 
        removeNode(node);
        addToTail(node);
    }

    void put(int key, int value) 
    {
        // if key exists in hash map already, size doesn't change. 
        // Just move the corresponding node to the end of the list and update its value. 
        if (track.contains(key))
        {
            Node* n = track[key];
            n->val = value;

            moveToTail(n);
        }
        // if the key doesn't exist, we create a new node for the key. 
        // if we hit the size, we must remove the head and add the new node to the end of the list.
        // if we have enough room, we just add the new node to the end of the list and increment size. 

        // use delete to remove the removed head node from memory. 
        // Create another pointer to the head to delete head after it is removed. 

        // no need to ever de increment size in a cache. 
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
