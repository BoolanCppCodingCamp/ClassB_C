// policy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <mutex>
#include <thread>


template<class T> struct NoChecking
{
    static void Check(T*) {}
};
template<class T> struct EnforceNotNull
{
    class NullPtrException : public std::exception {};
    static void Check(T* ptr) 
    {
        if (!ptr) throw NullPtrException();
    }
};

template<typename T>
T* GetDefaultPtr()
{
    return new T();
}

template<class T> struct EnsureNotNull
{
    static void Check(T*& ptr)
    {
        if (!ptr) ptr = GetDefaultPtr<T>();
    }
};

template<class T> struct SingleThread
{
    struct Lock
    {
        Lock() {}
        explicit Lock(const SingleThread&) {}
    };
};

template<class T> struct MultiThread
{
    class Lock
    {
    public:
        explicit Lock(const MultiThread& host)
        {
            m_mutex.lock();
        }
        ~Lock()
        {
            m_mutex.unlock();
        }

    private:
        std::mutex m_mutex;

        Lock(const Lock&) = delete;
        Lock(Lock&&) = delete;
        Lock& operator=(const Lock&) = delete;
        Lock& operator=(Lock&&) = delete;
    };
};

template< class T,
          template<class> class CheckingPolicy, 
          template<class> class ThreadPolicy>
class SmartPtr : public CheckingPolicy<T>,
                 public ThreadPolicy<T>
{
public:
    SmartPtr() {  }
    ~SmartPtr() {  }
    T* operator->()
    {
        typename ThreadPolicy<T>::Lock lock(*this);
        CheckingPolicy<T>::Check(pointee_);

        return pointee_;
    }
private:
    T* pointee_;
};

using EnsureSingleThreadInt = SmartPtr<int, EnsureNotNull, SingleThread>;
using NoCheckMultiThreadDouble = SmartPtr<double, NoChecking, MultiThread>;

int main()
{
    EnsureSingleThreadInt p1;
    NoCheckMultiThreadDouble p2;

    std::cout << "Hello World!\n";
}
