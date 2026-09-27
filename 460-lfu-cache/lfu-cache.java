import java.util.HashMap;
import java.util.Map;

class Node {
    Node next, prev;
    int key, value;
    Node(int key, int value) {
        this.key = key;
        this.value = value;
    }

    public int getKey() {
        return key;
    }

    public int getValue() {
        return value;
    }
}

class LRUManager {
    Node head, tail;
    Map<Integer, Node> location;
    LRUManager() {
        head = null;
        tail = null;
        location = new HashMap<>();
    }

//    void print() {
//        System.out.print("THIS IS LRU\n");
//        Node node = head;
//        while(node != null) {
//            System.out.print( node.key +" ");
//            node = node.next;
//        }
//    }

    public boolean isLruEmpty() {
        return head==null && tail==null;
    }

    public Node getKey(int key) {
        return location.get(key);
    }

    public void removeKey(int key) {
        Node node = location.get(key);
        deleteNode(node);
    }

    public void addToLru(int key, int value) {
        Node node = location.get(key);
        if(node == null) {
            node = new Node(key, value);
            insertNodeAtHead(node);
            location.put(key, node);
            return;
        }

        node.value = value;
        moveNodeToHead(node);

    }

    private void insertNodeAtHead(Node node) {

        node.next = head;
        if(head != null) {
            head.prev = node;
            // System.out.println("inserting at head: " + head.value + ": value" + node.value);
        } else {
            tail = node;
        }

        head = node;
    }
    private void  moveNodeToHead(Node node) {
        if(node.next != null) {
            node.next.prev = node.prev;
        }

        if(node.prev != null) {
            node.prev.next = node.next;
        }

        node.next = null;
        node.prev = null;

        insertNodeAtHead(node);
    }
    public int evict() {
        int key = tail.key;
        deleteNode(tail);

        return key;
    }

    private void deleteNode(Node node) {

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

        location.remove(node.key);
    }
    // implement LRU methods
}

class LFUNode {
    int freq;
    LFUNode next, prev;
    LRUManager manager;
    LFUNode(int freq) {
        this.freq = freq;
        this.next = null;
        this.prev = null;
        this.manager = new LRUManager();
    }

}

class LFUCache {
    int capacity;
    LFUNode head, tail;
    Map<Integer, LFUNode> location;
    Map<Integer, Integer> freqMap;
    public LFUCache(int capacity) {
        this.capacity = capacity;
        this.head = null;
        this.tail = null;
        this.location = new HashMap<>();
        this.freqMap = new HashMap<>();
    }

//    void print() {
////        System.out.print("THIS IS LFU : \n");
//        LFUNode node = head;
//        while(node != null) {
////            System.out.println("LFUNode : freq : " +node.freq);
////            System.out.println("Corresponding LRU: ");
////            node.manager.print();
////            System.out.println("\n_______________");
//            node = node.next;
//        }
////
////        System.out.println("  *************      ");
//    }
    public int get(int key) {
//        print();
        if(!freqMap.containsKey(key)) {
            return -1;
        }

        LFUNode node = location.get(freqMap.get(key));
        // remove node from LRU

        Node temp = node.manager.getKey(key);


        int value = temp.getValue();
        removeKey(key, node);
        // moveToNextFreqNode
        moveToNextFreqNode(key, node.freq, value);

        return value;

    }

    private void removeKey(int key, LFUNode node) {
        node.manager.removeKey(key);
      
    }

//    void printFreqMap() {
//        System.out.println("THIS IS FM");
//        for(Map.Entry<Integer, LFUNode> e : location.entrySet()) {
//            System.out.println(e.getKey() + " :" + e.getValue() + " : " + e.getValue().freq);
//        }
//    }
    public void put(int key, int value) {

        if(freqMap.containsKey(key)) {
            LFUNode node = location.get(freqMap.get(key));
            removeKey(key, node);
            moveToNextFreqNode(key, node.freq, value);
            return ;
        }

        if(this.capacity == freqMap.size()) {
            deleteEntryFromLFUCache();
        }

        insertFirstElement(key, value);
//        printFreqMap();
//        print();
    }

    private void createHead(int key, int freq, int value) {
        System.out.println(String.format("Creating LFU head for key : %d , value : %d , freq: %d", key, value, freq));
        LFUNode node = new LFUNode(freq);
        node.manager.addToLru(key, value);
        location.put(freq, node);
        head = node;
        tail = head;
    }

    private void insertFirstElement(int key, int value) {
        // inserting new element 
        // get freq node 1
        LFUNode node = location.get(1);
        freqMap.put(key, 1);
        if(node != null) {
            node.manager.addToLru(key, value);
        } else {
            node = new LFUNode(1);
            node.manager.addToLru(key, value);
            insertNodeAtHead(node);
            location.put(1, node);
        }
    }

    private void insertNodeAtHead(LFUNode node) {
        node.next = head;
        if(head != null) {
            head.prev = node;
        }

        head = node;
    }

    private void moveToNextFreqNode(int key, int freq, int value) {

        int nextFreq = freq+1;
        freqMap.put(key, nextFreq);
        LFUNode curNode = location.get(freq);

        if(curNode.next != null ) {
            if(curNode.next.freq == nextFreq)
                curNode.next.manager.addToLru(key, value);
            else {
                LFUNode newNode = new LFUNode(nextFreq);
                newNode.manager.addToLru(key, value);
                location.put(nextFreq, newNode);
                insertNodeAfter(curNode, newNode);
            }
        } else {
            LFUNode newNode = new LFUNode(nextFreq);
            location.put(nextFreq, newNode);
               newNode.manager.addToLru(key, value);
            insertNodeAfter(curNode, newNode);
        }

          if(curNode.manager.isLruEmpty()) {
            deleteNode(curNode);
        }
    }

    private void insertNodeAfter(LFUNode node, LFUNode newNode) {
        newNode.next = node.next;
        newNode.prev = node;
        if(node.next != null) {
            node.next.prev = newNode;
        }
        node.next = newNode;
    }

    private void deleteNode(LFUNode node) {
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

        location.remove(node.freq);
    }

    private void deleteEntryFromLFUCache() {
        int freq = head.freq;
        LFUNode node = location.get(freq);
        int evictedKey = node.manager.evict();

        freqMap.remove(evictedKey);
        System.out.println("evicted : "+ evictedKey);
        if(node.manager.isLruEmpty()) {
            deleteNode(node);
        }
    }


}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */