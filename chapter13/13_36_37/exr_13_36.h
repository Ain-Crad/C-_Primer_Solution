#ifndef _EXR_13_36_H
#define _EXR_13_36_H

#include <iostream>
#include <string>
#include <set>

using std::cin;
using std::cout;
using std::endl;

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

    void addFolder(Folder *f) { folders.insert(f); }
    void remFolder(Folder *f) { folders.erase(f); }
};

class Folder
{
    friend class Message;
    friend void swap(Folder &, Folder &);

public:
    Folder() = default;
    Folder(const Folder &);
    Folder &operator=(const Folder &);
    ~Folder();

    void print() const;

private:
    std::set<Message *> msgs;

    void add_to_Messages(const Folder &);
    void remove_from_Messages();

    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
};

#endif