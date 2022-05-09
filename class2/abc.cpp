struct A
{
    A() : m_a(1) { cout << "A constructor invoked!" << endl; }
    virtual void Func() { cout << "A::Func() invoked!" << endl; }
    int m_a;
};

struct B
{
    B() : m_b(2) { cout << "B constructor invoked!" << endl; }
    virtual void Func() { cout << "B::Func() invoked!" << endl; }
    int m_b;
};

//组合
struct C
{
    C() : m_c(3) { cout << "C constructor invoked!" << endl; }
    //virtual void Func() { cout << "C::Func() invoked!" << endl; }
    A a;
    B b;
    int m_c;
};

//继承
struct C : public A, public B
{
    C() : m_c(3) { cout << "C constructor invoked!" << endl; }
    int m_c;
};


但是继承的时候，指针强制转换时编译器会做偏移计算：
    A* pA1 = &c;
    B* pB1 = &c;
    cout << "pA1 = " << pA1 << ", pB1 = " << pB1 << ", c= " << &c << endl;
    pA1->Func();
    pB1->Func();
    //c.Func(); 错误，从 A 和 B 都继承了一个 Func，编译器不知道调用哪个 Func？
