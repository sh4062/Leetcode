class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>>ls;
    priority_queue<int,vector<int>,less<int>>gt;
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        gt.push(num);
        int most = gt.top();
        gt.pop();
        ls.push(most);
        if(gt.size()<ls.size()){
            int least = ls.top();
            ls.pop();
            gt.push(least);
        }
        

    }
    
    double findMedian() {
        if(ls.size()==gt.size()){
            return (ls.top()+gt.top())*0.5;
        }
        return gt.top();

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
