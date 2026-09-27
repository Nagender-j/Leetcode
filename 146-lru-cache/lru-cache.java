class LRUCache {
    LinkedHashMap<Integer, Integer> elements;
    int capacity;
    public LRUCache(int capacity) {
        this.capacity = capacity;
        elements = new LinkedHashMap<>();
    }
    
    public int get(int key) {
        if(elements.containsKey(key)) {
            int value = elements.get(key);
            elements.remove(key);
            elements.put(key, value);

            return value;
        }

        return -1;
    }
    
    public void put(int key, int value) {

         if(elements.containsKey(key)) {
            elements.remove(key);
             elements.put(key, value);
             return ;
         }

          if(elements.size() == capacity) {
            delete();
        }
        
          elements.put(key, value);
    }

void delete() {
    Iterator<Integer> iterator = elements.keySet().iterator();
    iterator.next();
    iterator.remove();
}
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */