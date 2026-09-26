class DLLNode {
    DLLNode next;
    DLLNode prev;
    int freq;
    Set<String> keys;
    DLLNode(int f) {
        next = null;
        prev = null;
        freq = f; 
        keys = new HashSet<>();
    }
};

class AllOne {

    DLLNode head;
    DLLNode tail;
    Map<String, DLLNode> location;
    public AllOne() {
        head = null;
        tail = null;
        location = new HashMap<>();
    }
    
    public void inc(String key) {
         if(!location.containsKey(key)) {
            insertNewKeyAtHead(key);
            return;
        }

        moveToNextFreq(location.get(key), key);
    }
    
    public void dec(String key) {
         moveToPrevFreq(location.get(key), key);
    }
    
    public String getMaxKey() {
      if(tail == null) return "";
       String s = tail.keys.stream().findFirst().get();
       return s;
    }
    
    public String getMinKey() {
       if(head == null) return "";
       return head.keys.stream().findFirst().get();  
    }

    private void deleteNode(DLLNode node) {
        if(node.next != null) {
            node.next.prev = node.prev;
        } 

        if(node.prev != null) {
            node.prev.next = node.next;
        }
        
        if(node == head) {
            head = node.next;
        }

        if(node == tail) {
            tail = node.prev;
        }

        node.next = null;
        node.prev = null;
    }

    private  void moveToNextFreq(DLLNode node, String key) {
        // get the next Freq Node
        int nextFreq = node.freq + 1;
        if(node.next != null && node.next.freq == nextFreq) {
            node.next.keys.add(key);
            location.put(key, node.next);
        } else {
            // i.e there is no node with nextFreq
            // 1. create a node and adjust links and insert key
            DLLNode nextFreqNode = new DLLNode(nextFreq);
            location.put(key, nextFreqNode);
            
            nextFreqNode.next = node.next;
            nextFreqNode.prev = node;
            if(node.next != null) {
                node.next.prev = nextFreqNode;
            }
            node.next = nextFreqNode;

            // adjust tail if needed
            if(tail == node) {
                tail = nextFreqNode;
            }
            nextFreqNode.keys.add(key);
        }

        // erase key from cur Freq node and move it to nextFreq node;
        node.keys.remove(key);
        if(node.keys.size() == 0) {
            deleteNode(node);
        }
    }

    private   void moveToPrevFreq(DLLNode node, String key) {
         // get the next Freq Node
        int prevFreq = node.freq - 1;
        if(prevFreq == 0) {
            location.remove(key);
        } else if(node.prev != null && node.prev.freq == prevFreq) {
            node.prev.keys.add(key);
            location.put(key, node.prev);
        } else {
            // i.e there is no node with prevFreq
            // 1. create a node and adjust links and insert key
            DLLNode prevFreqNode = new DLLNode(prevFreq);
            location.put(key, prevFreqNode);
            
            prevFreqNode.next = node;
            prevFreqNode.prev = node.prev;
            if(node.prev != null) {
                node.prev.next = prevFreqNode;
            }
            
            node.prev = prevFreqNode;
            // adjust head if needed
            if(head == node) {
                head = prevFreqNode;
            }
            prevFreqNode.keys.add(key);
        }

        // erase key from cur Freq node and move it to nextFreq node;
        node.keys.remove(key);
        if(node.keys.size() == 0) {
            deleteNode(node);
        }
        
    }

     void insertNewKeyAtHead(String key) {
        if(head == null) {
            DLLNode node = new DLLNode(1);
            node.keys.add(key);

            location.put(key, node);
            head = node;
            tail = head;
            return;
        }

        if(head.freq == 1) {
            head.keys.add(key);
             location.put(key, head);
        } else {
            DLLNode node = new DLLNode(1);
            node.keys.add(key);
            location.put(key, node);
            node.next = head;
            head.prev = node;
            head = node;
        }
    }
}

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */