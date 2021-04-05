#include "exr_13_40.h"

std::allocator<std::string> StrVec::alloc;

std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(
    std::string *b, std::string *e)
{
    auto data = alloc.allocate(b - e);
    return {data, uninitialized_copy(b, e, data)};
}

StrVec::StrVec(const StrVec &sv)
{
    auto data = alloc_n_copy(sv.begin(), sv.end());
    element = data.first;
    first_free = cap = data.second;
}

StrVec::StrVec(std::initializer_list<std::string> ls)
{
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
    auto data = alloc_n_copy(sv.begin(), sv.end());
    free();
    element = data.first;
    first_free = cap = data.second;

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
        for (auto p = first_free; p != element;)
        {
            alloc.destroy(--p);
        }
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
    element = newData;
    first_free = dest;
    cap = element + n;
}