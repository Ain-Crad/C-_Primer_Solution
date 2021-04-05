#ifndef _EXR_13_44_H
#define _EXR_13_44_H

#include <iostream>
#include <memory>
#include <cstring>
#include <algorithm>

class String
{
    friend std::ostream &operator<<(std::ostream &, const String &);
    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const String &);
    friend bool operator<(const String &, const String &);
    friend bool operator>(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator>=(const String &, const String &);

public:
    String() : element(nullptr), first_free(nullptr), cap(nullptr) {}
    String(const char *s);
    String(const String &);
    String &operator=(const String &);
    String(String &&) noexcept;
    String &operator=(String &&) noexcept;
    ~String();

    size_t size() const { return first_free - element; }
    char *begin() const { return element; }
    char *end() const { return first_free; }
    void free();

private:
    static std::allocator<char> alloc;
    char *element;
    char *first_free;
    char *cap;

    std::pair<char *, char *> alloc_n_copy(const String &);
};

std::ostream &operator<<(std::ostream &, const String &);
bool operator==(const String &, const String &);
bool operator!=(const String &, const String &);
bool operator<(const String &, const String &);
bool operator>(const String &, const String &);
bool operator<=(const String &, const String &);
bool operator>=(const String &, const String &);

#endif