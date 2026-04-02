class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = next = NULL;
    }
};
class LRUCache {
public:
unordered_map<int,Node*> mp;
Node* head;
Node* tail;
int capacity;
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
void deletenode(Node* node)   
{
    Node* prev=node->prev;
    Node* next=node->next;
    if(prev) prev->next=next;
    if(next) next->prev=prev;
} 
void insertafterhead(Node* node)
{
    Node* temp=head->next;
    node->next=temp;
    node->prev=head;
    head->next=node;
    temp->prev=node;
}
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        Node* node=mp[key];
        deletenode(node);
        insertafterhead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()) 
        {
            Node* node=mp[key];
            node->val=value;
            deletenode(node);
            insertafterhead(node);
        }
        else 
        {
            if(mp.size()==capacity)
            {
                Node* node=tail->prev;
                mp.erase(node->key);
                deletenode(node);
            }
            Node* newnode=new Node(key,value);
            mp[key]=newnode;
            insertafterhead(newnode);

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */