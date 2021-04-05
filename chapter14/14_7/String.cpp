#include "String.h"

using std::cin;
using std::cout;
using std::endl;

std::allocator<char> String::alloc;

std::ostream &operator<<(std::ostream &os, const String &s)
{
    for (auto it = s.element; it != s.first_free; ++it)
    {
        os << *it;
    }

    return os;
}

std::pair<char *, char *> String::alloc_n_copy(const String &s)
{
    auto data = alloc.allocate(s.size());
    auto dest = data;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        alloc.construct(dest++, *it);
    }
    return {data, dest};
}

String::String(const char *s)
{
    cout << "String(const char *s)" << endl;
    auto data = alloc.allocate(strlen(s));
    auto dest = data;
    for (size_t i = 0; i < strlen(s); ++i)
    {
        alloc.construct(dest++, *(s + i));
    }
    element = data;
    first_free = cap = dest;
}

String::String(const String &s)
{
    cout << "String(const String &s)" << endl;
    auto p = alloc_n_copy(s);
    element = p.first;
    first_free = cap = p.second;
}

String &String::operator=(const String &s)
{
    cout << "String &operator=(const String &s)" << endl;
    auto p = alloc_n_copy(s);
    free();
    element = p.first;
    first_free = cap = p.second;
}

String::String(String &&s) noexcept
    : element(s.element), first_free(s.first_free), cap(s.cap)
{
    cout << "String(String &&s) noexcept" << endl;
    s.element = s.first_free = s.cap = nullptr;
}

String &String::operator=(String &&s) noexcept
{
    cout << "String &operator=(String &&s) noexcept" << endl;
    if (this != &s)
    {
        free();
        element = s.element;
        first_free = s.first_free;
        cap = s.cap;
        s.element = s.first_free = s.cap = nullptr;
    }

    return *this;
}

String::~String()
{
    free();
}

void String::free()
{
    if (element)
    {
        std::for_each(element, first_free,
                      [](const char &c) { alloc.destroy(&c); });
        alloc.deallocate(element, cap - element);
    }
}