class Node{
    public:
    Node* next;
    Node* prev;
    string val;
    Node(string x): val(x),next(nullptr),prev(nullptr){}
    };
    class BrowserHistory {
    Node* curr;
    
public:
    BrowserHistory(string homepage) {
        curr=new Node(homepage);
    }
    
    void visit(string url) {
        Node* newnode=new Node(url);
        curr->next=newnode;
        newnode->prev=curr;
        curr=newnode;
    }
    
    string back(int steps) {
        while(steps--) curr=(curr->prev)?curr->prev:curr;
        return curr->val;
    }
    
    string forward(int steps) {
        while(steps--) curr=(curr->next)?curr->next:curr;
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */