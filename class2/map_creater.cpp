#include <iostream>
#include <string>
#include <map>
#include <functional>


struct Context
{
    double GetEdge() { return 2.3; }
    double GetAngle() { return 36.6; }
    double GetRadius() { return 23.1; }
};

struct Shape
{
};

struct Circle : public Shape
{
    Circle(const Context& ctx) {}
};

struct Rectangle : public Shape
{
    Rectangle(const Context& ctx) {}
};

struct Triangle : public Shape
{
    Triangle(const Context& ctx) {}
};

bool IsValidName(const std::string& name)
{
    return true;
}

std::map<std::string, std::function<Shape*(const Context& ctx)>> Creater = {
    {"Circle", [](const Context& ctx) { return new Circle(ctx); } },
    {"Rectangle", [](const Context& ctx) { return new Rectangle(ctx); } },
    {"Triangle", [](const Context& ctx) { return new Triangle(ctx); } }
};

int main()
{
    Context context;
    std::string name = "Circle";
    if(IsValidName(name))
    {
        Shape *shape = Creater[name](context);
        //

        delete shape;
    }
 
}

