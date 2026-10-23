class MedianFinder {
   priority_queue<int> mxHeap;
   priority_queue<int,vector<int>, greater<int>> mnHeap;
public:

    MedianFinder() {
        
    }
    
    void addNum(int num) {
       if(mxHeap.size() == 0) {
        mxHeap.push(num);
        return;
       }
       
       if(mxHeap.top() >= num) {
        mxHeap.push(num);
        if(mxHeap.size() - mnHeap.size() >= 2) {
            mnHeap.push(mxHeap.top());
            mxHeap.pop();
        }

       } else {
            mnHeap.push(num);
            while(mnHeap.size() >0 && mnHeap.size() > mxHeap.size()) {
                mxHeap.push(mnHeap.top());
                mnHeap.pop();
            }
       }
    }
    
    double findMedian() {
        int sz1 = mxHeap.size();
        int sz2 = mnHeap.size();
        if(sz1 == 0) return 0;
        if(sz2 == 0) return mxHeap.top();
        int t1 = mxHeap.top();
        int t2 = mnHeap.top();


        // cout<<t1<<" "<<t2<<endl;
        if( (sz1+sz2)%2 == 0) {
            double res = (t1+t2) * 0.5;
            return res;
        } 
        
        return t1;


    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */