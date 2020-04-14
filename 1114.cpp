class Foo {
public:
    // 定义互斥锁(条件变量需要和互斥锁一起使用)
std::mutex mtx;
// 定义条件变量(用来做线程间的同步通信)
std::condition_variable cv;
    int c = 1;
    Foo() {
        // 定义互斥锁(条件变量需要和互斥锁一起使用)
std::mutex mtx;
// 定义条件变量(用来做线程间的同步通信)
std::condition_variable cv;
        int c = 1;
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        c++;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        while(c!=2){
            std::unique_lock<std::mutex> lock(mtx);
            
            cv.wait(lock);
            
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        c++;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        
        while(c!=3){
            std::unique_lock<std::mutex> lock(mtx);
             
            cv.wait(lock);
        }
            
           
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
       // cv.notify_all();
         
    }
};