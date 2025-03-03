#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

thread_local int x = 0;

// mutex for synchronisation
mutex mtx;

int main()
{
    thread T1([]()
              {
        x+=1;
        lock_guard<mutex> lock(mtx);
        cout<<"Thread value in T1 is "<<x<<endl; });
    thread T2([]()
              {
        x+=2;
        lock_guard<mutex> lock(mtx);
        cout<<"Thread value in T2 is "<<x<<endl; });
    thread T3([]()
              {
        x+=3;
        lock_guard<mutex> lock(mtx);
        cout<<"Thread value in T3 is "<<x<<endl; });

    T1.join();
    T2.join();
    T3.join();
    cout << "Thread value in x is " << x << endl;
}