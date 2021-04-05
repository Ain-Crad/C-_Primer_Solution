#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

class Employee
{
public:
    Employee() = default;
    Employee(std::string &s)
    {
        name = s;
        id = unique++;
    }

    int getId() const
    {
        return id;
    }

private:
    std::string name;
    int id;
    static int unique;
};

int Employee::unique = 0;

int main()
{

    return 0;
}