#include "StrVec.h"

using std::cin;
using std::cout;
using std::endl;

std::allocator<std::string> StrVec::alloc;

std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(
    const std::string *b, const std::string *e)
{
    cout << "alloc_n_copy()" << endl;
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

StrVec::StrVec(const StrVec &sv)
{
    cout << "StrVec(const StrVec &sv)" << endl;
    auto data = alloc_n_copy(sv.begin(), sv.end());
    element = data.first;
    first_free = cap = data.second;
}

StrVec::StrVec(std::initializer_list<std::string> ls)
{
    cout << "StrVec(std::initializer_list<std::string>)" << endl;
    auto data = alloc.allocate(ls.size());
    auto dest = data;
    for (auto it = ls.begin(); it != ls.end(); ++it)
    {
        alloc.construct(dest++, *it);
    }
    element = data;
    first_free = cap = dest;
}

StrVec &StrVec::operator=(const StrVec &sv)
{
    cout << "StrVec &operator=(const StrVec &sv)" << endl;
    auto data = alloc_n_copy(sv.begin(), sv.end());
    free();
    element = data.first;
    first_free = cap = data.second;

    return *this;
}

StrVec &StrVec::operator=(std::initializer_list<std::string> il)
{
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    element = data.first;
    first_free = cap = data.second;

    return *this;
}

StrVec::StrVec(StrVec &&sv) noexcept
    : element(sv.element), first_free(sv.first_free), cap(sv.cap)
{
    sv.element = sv.first_free = sv.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&sv) noexcept
{
    if (this != &sv)
    {
        free();
        element = sv.element;
        first_free = sv.element;
        cap = sv.cap;
        sv.element = sv.first_free = sv.cap = nullptr;
    }

    return *this;
}

StrVec::~StrVec()
{
    free();
}

void StrVec::free()
{
    if (element)
    {
        // for (auto p = first_free; p != element;)
        // {
        //     alloc.destroy(--p);
        // }
        for_each(element, first_free,
                 [](const std::string &s) { alloc.destroy(&s); });
        alloc.deallocate(element, cap - element);
    }
}

void StrVec::push_back(const std::string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::chk_n_alloc()
{
    if (size() == capacity())
    {
        reallocate();
    }
}

void StrVec::reallocate()
{
    size_t newCapacity = size() ? 2 * size() : 1;
    alloc_n_move(newCapacity);
}

void StrVec::reserve(size_t n)
{
    if (n <= capacity())
    {
        return;
    }
    alloc_n_move(n);
}

void StrVec::resize(size_t n)
{
    resize(n, std::string());
}

void StrVec::resize(size_t n, const std::string &s)
{
    if (n < size())
    {
        while (first_free != element + n)
        {
            alloc.destroy(--first_free);
        }
    }
    else
    {
        if (n > capacity())
        {
            reserve(2 * n);
        }
        for (size_t i = size(); i < n; ++i)
        {
            alloc.construct(first_free++, s);
        }
    }
}

void StrVec::alloc_n_move(size_t n)
{
    auto newData = alloc.allocate(n);
    auto dest = newData;
    for (auto p = element; p != first_free; ++p)
    {
        alloc.construct(dest++, std::move(*p));
    }
    free();
    element = newData;
    first_free = dest;
    cap = element + n;
}

std::string &StrVec::at(size_t i) const
{
    if (i >= size())
    {
        throw std::out_of_range("StrVec indice out of range");
    }
    return *(element + i);
}