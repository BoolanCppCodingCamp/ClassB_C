#include <iostream>


class A
{
public:
    A(): a1(2),a2(3) {}
    virtual void Func() { std::cout << "A::Func() Invoked!" << std::endl;}

    int a1;
    int a2;
};

class B : virtual public A
{
public:
    B() : A(), b1(5), b2(6) {}
    virtual void Func() { std::cout << "B::Func() Invoked!" << std::endl;}

    int b1;
    int b2;
};

class C : virtual public A
{
public:
    C() : A(), c1(7), c2(8) {}
    virtual void Func() { std::cout << "C::Func() Invoked!" << std::endl;}

    int c1;
    int c2;
};	

class D : public B, public C
{
public:
    D() : B(), C(), d1(9), d2(10) {}
    virtual void Func() { std::cout << "D:Func() Invoked!" << std::endl;}
    
    int d1;
    int d2;    
};

int main()
{
    std::cout << "sizeof(A) = " << sizeof(A) << ", sizeof(B) = " << sizeof(B)
              << ", sizeof(C) = " << sizeof(C) << ", sizeof(A) = " << sizeof(D) << std::endl;
    
    A a;
    B b;
    C c;    
    D d;

    a.Func();  
  
    A* pA1 = &b;
    B* pB1 = &b;
    std::cout << "pA1 = " << pA1 << "   pB1 = " << pB1 << "   pB = " << &b << std::endl;
    b.Func();
    pA1->Func();
    pB1->Func();
    b.A::Func();
    pA1->A::Func();

    A* pA2 = &c;
    C* pC1 = &c;
    std::cout << "pA2 = " << pA2 << "   pC1 = " << pC1 << "   pC = " << &c << std::endl;
    c.Func();
    pA2->Func();
    pC1->Func();
    c.A::Func();

    B* pB2 = &d;
    C* pC2 = &d;
    A* pA3 = &d;
    std::cout << "pB2 = " << pB2 << "   pC2 = " << pC2 << "   pA3 = " << pA3 << "   pD = " << &d << std::endl;
    d.Func();
    pB2->Func();
    pC2->Func();
    pA3->Func();
}
