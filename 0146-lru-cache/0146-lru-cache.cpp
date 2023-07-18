

class LRUCache {
public:
    
    //class to repersent DLL with each nodes has <key,value>
    class Node
    {
        public:
              int key;
              int value;
              Node* prev;
              Node* next;

        Node(int x, int y)
        {
            key = x;
            value = y;
            prev = NULL;
            next = NULL;
        }
    };

     //we need to add nodes at the head and remove the least recently used nodes from end , create two dummy nodes
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    
  
    //the actual DS:  key : key of node , value: pointer to the node in DLL   
    unordered_map<int,Node*> mp;
    
    //capacity of the cache
    int cap;
    
    //create initial configurations : 
    //1.define the capacity of the the cache
    //2. connect head and tail
    
    LRUCache(int capacity) {
        
       cap = capacity;
       head->next = tail;
       tail->prev = head;
    }
    
    //we need to add the newNode after head
    void addNode(Node* newNode)
    {
        //head points to the head node
        //we need a pointer to the node just after head
        Node* nextHead = head->next;
        
        //make prev and next of newNode
        newNode->prev = head;
        newNode->next = nextHead;
        
        //next of head is pointing to node after it , make it points to the new node
        head->next = newNode;
        
        //prev of nextHead is pointing to head , make it point to the new node
        nextHead->prev = newNode;
        
           
    }
    
    
    void deleteNode(Node* delNode)
    {
        //store the pointers of delNode
        Node* delNodePrev = delNode->prev;
        Node* delNodeNext = delNode->next;
        
        delNodePrev->next = delNodeNext;
        delNodeNext->prev = delNodePrev;
    
    }
    
    //if the key exists in the cache , it return the value otherwise -1
    int get(int key) {
        
        //check in map for the key
        if(mp.find(key) != mp.end())  //found the key
        {
            //find out the pointer of the node from map
            Node* ptr = mp[key];
            
            //use this pointer and get the val from the DLL
            int val = ptr->value;
            
            //node is used recently , need to delete from the current pos and insert after the head node
            deleteNode(ptr);
            addNode(ptr);
            
            //after re-insertion , nodes address will get changed , but we have inserted after head node
            mp[key] = head->next;
            
            //return the value
            return val;
            
        }
       
            return -1;
        
               
    }
    
    //we have to insert the <key,value> pair in to the cache
    void put(int key, int value) {
        
      
        //if the particular key already exists in the cache , we need to delete it 
        
        if(mp.find(key) != mp.end())
        {
            Node* ptr = mp[key];
            
            //erase it from the map
            mp.erase(key);
            
            //delete node from DLL
            deleteNode(ptr);
        }
        
        //we perform insertion after checking the capacity : cache current cap = map's size
        
        //if we reach the capacity , delete the node just before tail
        if(mp.size() == cap)
        { 
            
            Node* ptr = tail->prev; //node to be deleted
            mp.erase(ptr->key);
            deleteNode(ptr);
           
        }
        
        Node* newNode = new Node(key,value);
        
        addNode(newNode);
        
        mp[key] = head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */