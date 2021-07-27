class ZeroEvenOdd {
private:
    int n;
    int nn;
    bool terminate;
    std::mutex mutex;
    std::condition_variable cv0,cv1;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        terminate=false;
        nn=1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(nn<=n){
        unique_lock<std::mutex> l(mutex);
        printNumber(0);
        cv1.notify_all();
        cv0.wait(l);
        }
        terminate = true;
        cv1.notify_all();
        
    }

    void even(function<void(int)> printNumber) {
         while(nn<=n){
        unique_lock<std::mutex> l(mutex);
        cv1.wait(l, [ this ] { return nn % 2 == 0; });
        if(terminate!=true)
        printNumber(nn);
        nn++;
        cv0.notify_one();
        }
    }

    void odd(function<void(int)> printNumber) {
       while(nn<=n){
        unique_lock<std::mutex> l(mutex);
        cv1.wait(l, [ this ] { return nn % 2 != 0; });
        if(terminate!=true)
        printNumber(nn);
        nn++;
        cv0.notify_one();
        }

        
    }
};
