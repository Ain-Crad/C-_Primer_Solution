#include "Message.h"

using std::cin;
using std::cout;
using std::endl;

void Message::save(Folder &f)
{
    addFolder(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    remFolder(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &msg)
{
    for (auto f : msg.folders)
    {
        f->addMsg(this);
    }
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
    {
        f->remMsg(this);
    }
}

Message::Message(const Message &msg)
    : contents(msg.contents), folders(msg.folders)
{
    add_to_Folders(msg);
}

Message &Message::operator=(const Message &msg)
{
    remove_from_Folders();
    contents = msg.contents;
    folders = msg.folders;
    add_to_Folders(msg);

    return *this;
}

void Message::move_Folders(Message *m)
{
    folders = std::move(m->folders);
    for (auto f : folders)
    {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

Message::Message(Message &&m) : contents(std::move(m.contents))
{
    move_Folders(&m);
}

Message &Message::operator=(Message &&m)
{
    if (this != &m)
    {
        remove_from_Folders();
        contents = std::move(m.contents);
        move_Folders(&m);
    }

    return *this;
}

Message::~Message()
{
    remove_from_Folders();
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    lhs.remove_from_Folders();
    rhs.remove_from_Folders();

    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);

    lhs.add_to_Folders(lhs);
    rhs.add_to_Folders(rhs);
}

void Folder::add_to_Messages(const Folder &f)
{
    for (auto m : f.msgs)
    {
        m->addFolder(this);
    }
}

void Folder::remove_from_Messages()
{
    for (auto m : msgs)
    {
        m->remFolder(this);
    }
}

Folder::Folder(const Folder &f) : msgs(f.msgs)
{
    add_to_Messages(f);
}

Folder &Folder::operator=(const Folder &f)
{
    remove_from_Messages();
    msgs = f.msgs;
    add_to_Messages(f);

    return *this;
}

void Folder::move_Messages(Folder *f)
{
    for (auto m : msgs)
    {
        m->remFolder(f);
        m->add_to_Folders(this);
    }
    f->msgs.clear();
}

Folder::Folder(Folder &&f) : msgs(std::move(f.msgs))
{
    move_Messages(&f);
}

Folder &Folder::operator=(Folder &&f)
{
    if (this != &f)
    {
        remove_from_Messages();
        msgs = std::move(f.msgs);
        move_Messages(&f);
    }

    return *this;
}

Folder::~Folder()
{
    remove_from_Messages();
}

void Folder::print() const
{
    for (auto m : msgs)
    {
        cout << m->contents << endl;
    }
}

void swap(Folder &lhs, Folder &rhs)
{
    lhs.remove_from_Messages();
    rhs.remove_from_Messages();

    swap(lhs.msgs, rhs.msgs);

    lhs.add_to_Messages(lhs);
    rhs.add_to_Messages(rhs);
}