#ifndef _EXR_13_34_H
#define _EXR_13_34_H

#include <string>
#include <set>

class Folder;
class Message
{
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);

public:
    Message(const std::string &s = "") : contents(s) {}
    Message(const Message &msg);
    Message &operator=(const Message &msg);
    ~Message();

    void save(Folder &);
    void remove(Folder &);

private:
    std::string contents;
    std::set<Folder *> folders;

    void add_to_Folders(const Message &);
    void remove_from_Folders();
};

#endif