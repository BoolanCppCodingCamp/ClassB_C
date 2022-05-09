override 关键字的意义：

struct Base
{
    virtual void Func(int a, double b) { cout << "Base::Func() invoked!" << endl; }
};

struct Sub : public Base
{
    virtual void Func(int a, int b) { cout << "Sub::Func() invoked!" << endl; }
};

int main()
{
    Sub c;

    Base* pBase = &c;
    pBase->Func(5, 7);
}
