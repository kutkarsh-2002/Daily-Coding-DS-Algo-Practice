class Node{
   public:
    int key, val;
    Node* left, *right;
    
    Node(int key, int val){
        this->key=key;
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

class LRUCache {
public:
    
    Node* head, *tail;
    int cap, size;
    unordered_map<int, Node*>mp;
    

    LRUCache(int cap) {
        this->cap=cap;
        this->size=0;
        this->head=NULL;
        this->tail=NULL;
        
    }
    
    void insert(Node* p){
        if(head==NULL){
            head=p;
            tail=p;
        }else{
            tail->right=p;
            p->left=tail;
            tail=tail->right;
        }
    }
    
    void deletenode(Node* p){
        if(p->left!=NULL){
            p->left->right=p->right;
        }
        else{
            head=p->right;
        }
        
        if(p->right!=NULL){
            p->right->left=p->left;
        }
        else{
            tail=p->left;
        }
        
        p->left=NULL;
        p->right=NULL;
    }
    
    int get(int key) {
        
        if(mp.find(key)==mp.end())
            return -1;
        deletenode(mp[key]);
        insert(mp[key]);
        
        return mp[key]->val;
            
    }
    
    void put(int key, int value) {
        Node* temp=new Node(key, value);
        if(mp.find(key)!=mp.end()){
            mp[key]->val=value;
            deletenode(mp[key]);
            insert(mp[key]);
        }
        else{
            mp[key]=temp;
            if(cap==size){
                mp.erase(head->key);
                deletenode(head);
                insert(temp);
            }else{
                insert(temp);
                size++;
                
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */