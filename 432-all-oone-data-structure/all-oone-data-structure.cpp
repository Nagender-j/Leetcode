struct DLLNode {
    DLLNode *next, *prev;
    int freq;
    unordered_set<string> keys;
    DLLNode(int f) {
        next = NULL;
        prev = NULL;
        freq = f; 
    }
};


class AllOne {
public:
    DLLNode *head, *tail;
    unordered_map<string, DLLNode*> location;
    AllOne() {
        head = NULL;
        tail = NULL;
    }
    
    void inc(string key) {
        if(location.count(key) == 0) {
            insertNewKeyAtHead(key);
            return;
        }

        moveToNextFreq(location[key], key);
    }
    
    void dec(string key) {
        moveToPrevFreq(location[key], key);
    }
    
    string getMaxKey() {
       if(tail == NULL) return "";
       string s = *(tail->keys.begin()); 
       return s;
    }
    
    string getMinKey() {
        if(head == NULL) return "";
       string s = *(head->keys.begin()); 
       return s;
    }

    void deleteNode(DLLNode *node) {
        if(node->next) {
            node->next->prev = node->prev;
        } 

        if(node->prev) {
            node->prev->next = node->next;
        }
        
        if(node == head) {
            head = node->next;
        }

        if(node == tail) {
            tail = node->prev;
        }

        node->next = NULL;
        node->prev = NULL;
    }

    void moveToNextFreq(DLLNode* node, string key) {
        // get the next Freq Node
        int nextFreq = node->freq + 1;
        if(node->next && node->next->freq == nextFreq) {
            node->next->keys.insert(key);
            location[key] = node->next;
        } else {
            // i.e there is no node with nextFreq
            // 1. create a node and adjust links and insert key
            DLLNode *nextFreqNode = new DLLNode(nextFreq);
            location[key] = nextFreqNode;
            
            nextFreqNode->next = node->next;
            nextFreqNode->prev = node;
            if(node->next) {
                node->next->prev = nextFreqNode;
            }
            node->next = nextFreqNode;

            // adjust tail if needed
            if(tail == node) {
                tail = nextFreqNode;
            }
            nextFreqNode->keys.insert(key);
        }

        // erase key from cur Freq node and move it to nextFreq node;
        node->keys.erase(key);
        if(node->keys.size() == 0) {
            deleteNode(node);
        }
    }
    
    void moveToPrevFreq(DLLNode* node, string key) {
         // get the next Freq Node
        int prevFreq = node->freq - 1;
        if(prevFreq == 0) {
            location.erase(location.find(key));
        } else if(node->prev && node->prev->freq == prevFreq) {
            node->prev->keys.insert(key);
            location[key] = node->prev;
        } else {
            // i.e there is no node with prevFreq
            // 1. create a node and adjust links and insert key
            DLLNode *prevFreqNode = new DLLNode(prevFreq);
            location[key] = prevFreqNode;
            
            prevFreqNode->next = node;
            prevFreqNode->prev = node->prev;
            if(node->prev) {
                node->prev->next = prevFreqNode;
            }
            
            node->prev = prevFreqNode;
            // adjust head if needed
            if(head == node) {
                head = prevFreqNode;
            }
            prevFreqNode->keys.insert(key);
        }

        // erase key from cur Freq node and move it to nextFreq node;
        node->keys.erase(key);
        if(node->keys.size() == 0) {
            deleteNode(node);
        }
        
    }

    void insertNewKeyAtHead(string key) {
        if(head == NULL) {
            DLLNode* node = new DLLNode(1);
            node->keys.insert(key);

            location[key] = node;
            head = node;
            tail = head;
            return;
        }

        if(head->freq == 1) {
            head->keys.insert(key);
            location[key] = head;
        } else {
            DLLNode* node = new DLLNode(1);
            node->keys.insert(key);
            location[key] = node;
            node->next = head;
            head->prev = node;
            head = node;
        }
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */