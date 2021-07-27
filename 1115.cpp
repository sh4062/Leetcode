class FooBar {
private:
    int n;
    mutex _mu;
    mutex _mu2;
    // condition_variable cv;
public:
    FooBar(int n) {
        this->n = n;
        _mu2.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            _mu.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            _mu2.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            _mu2.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            _mu.unlock();
        }
    }
};
