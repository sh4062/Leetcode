class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        data.resize(k);
        head = 0;
        cur_size=0;

    }
    
    bool enQueue(int value) {
        if(isFull())return false;

        data[(head+cur_size)%data.size()]=value;
        cur_size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())return false;
        if(head==data.size()-1)head=0;
        else head++;
        cur_size--;
        return true;

    }
    
    int Front() {
        if(!isEmpty()){
          return data[head];

        }
        return -1;

    }
    
    int Rear() {
        if(!isEmpty()){
            
        return data[(head+cur_size-1)%data.size()];
        }
        return -1;

    }
    
    bool isEmpty() {
        return cur_size==0;

    }
    
    bool isFull() {
        return cur_size==data.size();
    }
    vector<int>data;
    int cur_size;
    int head;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
