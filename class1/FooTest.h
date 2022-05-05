#pragma once

#define SUPPORT_MOVE  1

class FooTest  {
public:
    FooTest(int a = 0) {
        std::cout << "Normal constructor invoked!" << std::endl;
        m_a = a;
    }
    FooTest(const FooTest& t) {
        std::cout << "Copy constructor invoked!" << std::endl;
        m_a = t.m_a;
    }
#ifdef SUPPORT_MOVE    
    FooTest(FooTest&& t) {
        std::cout << "Move constructor invoked!" << std::endl;
        m_a = t.m_a;  t.m_a = 0;
    }
#endif    
    ~FooTest() {
        if (m_a != 0)  {
            std::cout << "Do destructor invoked!" << std::endl;
        }
        else  {
            std::cout << "Trivial destructor invoked!" << std::endl;
        }
    }
    FooTest& operator = (const FooTest& t) {
        std::cout << "Assignment operator invoked!" << std::endl;
        if (this != &t)  {
            m_a = t.m_a;
        }

        return *this;
    }
#ifdef SUPPORT_MOVE    
    FooTest& operator = (FooTest&& t) {
        std::cout << "Move assignment operator invoked!" << std::endl;
        if (this != &t)  {
            m_a = t.m_a;  t.m_a = 0;
        }

        return *this;
    }
#endif    
protected:
    int m_a;
};


