
/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


class RandomizedCollection {
    List<Integer> a;
    Map<Integer, Set<Integer>> m;

    public RandomizedCollection() {
        a = new ArrayList<>();
        m = new HashMap<>();
    }
    
    public boolean insert(int val) {
        boolean res ;
       if(m.containsKey(val)) {
            res = false;
        } else {
            res = true;
        }
        // m[val].insert((int)a.size());
        Set<Integer> positions =  m.getOrDefault(val, new HashSet<>());
        positions.add(a.size());
        m.put(val, positions);
    
        a.add(val);
    
    
        return res;
    }
    
    public boolean remove(int val) {
        if(!m.containsKey(val))
            return false;
        
        int last=a.getLast();
        if(last == val) {
           
            m.get(val).remove((int)a.size()-1);
            a.removeLast();
            if(m.get(val).isEmpty()) {
                m.remove(val);
            }

            return true;

        }
       
        
        int idx= m.get(val).stream().toList().get(0);
        m.get(val).remove(idx);
     
        if(m.get(val).isEmpty())
            m.remove(val);
      
        m.get(last).remove(a.size() - 1);
        m.get(last).add(idx);
        
        if(m.get(last).size()==0)
            m.remove(last);
        
        a.set(idx, last);
      
        a.removeLast();
        
        return true;
        
    }
    
    public int getRandom() {
         int mul = 100000000;
         int r= (int)(Math.random() * mul) %a.size();
        
        return a.get(r);
    }
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */