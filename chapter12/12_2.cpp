#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob() : data(std::make_shared<std::vector<std::string>>()){};
    StrBlob(std::initializer_list<std::string> il)
        : data(std::make_shared<std::vector<std::string>>(il)){};

    std::string &front();
    std::string &back();
    const std::string &front() const;
    const std::string &back() const;
    void push_back(const std::string &s);
    void pop_back();

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

std::string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

const std::string &StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

const std::string &StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::push_back(const std::string &s) { data->push_back(s); }

void StrBlob::pop_back() { data->pop_back(); }

void StrBlob::check(size_type i, const std::string &msg) const {
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
}

int main() {
    StrBlob b1;
    {
        StrBlob b2({"a", "an", "the"});
        b1 = b2;
    }
    cout << b1.front() << endl;
    b1.push_back("hi");
    cout << b1.back() << endl;

    const StrBlob blb({"hello"});
    cout << blb.front() << endl;

    std::initializer_list<std::string> ilst = {"ha", "hi", "hey"};
    std::vector<std::string> vec = {"a", "b", "c"};
    for (auto x : vec) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}