class Node {
public:
    int key, val, cnt;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        val = v;
        cnt = 1;
        prev = next = NULL;
    }
};

class List {
public:
    int size;
    Node* head;
    Node* tail;

    List() {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node* node) {
        Node* temp = head->next;

        node->next = temp;
        node->prev = head;

        head->next = node;
        temp->prev = node;

        size++;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        size--;
    }
};

class LFUCache {
public:
    unordered_map<int, Node*> mp;        // key -> node
    unordered_map<int, List*> freq;  // freq -> list

    int capacity;
    int minFreq;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void update(Node* node) {
        int f = node->cnt;
        freq[f]->removeNode(node);

        if(f == minFreq && freq[f]->size == 0) {
            minFreq++;
        }

        node->cnt++;

        if(freq.find(node->cnt) == freq.end()) {
            freq[node->cnt] = new List();
        }

        freq[node->cnt]->addFront(node);
    }

    int get(int key) {
        if(capacity == 0) return -1;

        if(mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];
        update(node);

        return node->val;
    }

    void put(int key, int value) {
        if(capacity == 0) return;

        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            update(node);
        } 
        else {
            if(mp.size() == capacity) {
                List* list = freq[minFreq];
                Node* nodeToDelete = list->tail->prev;

                list->removeNode(nodeToDelete);
                mp.erase(nodeToDelete->key);
                delete nodeToDelete;
            }

            Node* newNode = new Node(key, value);
            minFreq = 1;

            if(freq.find(1) == freq.end()) {
                freq[1] = new List();
            }

            freq[1]->addFront(newNode);
            mp[key] = newNode;
        }
    }
};