#include "exr_13_34.h"

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
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

Message &operator=(const Message &msg)
{
    remove_from_Folders();
    contents = msg.contents;
    folders = msg.folders;
    add_to_Folders(msg);
    return *this;
}

Message::~Message()
{
    remove_from_Folders();
}

swap(Message &lhs, Message &rhs)
{
    using std::swap;
    lhs.remove_from_Folders();
    rhs.remove_from_Folders();
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);
    // lhs.remove_from_Folders();
    lhs.add_to_Folders(*this);
    // rhs.remove_from_Folders();
    rhs.add_to_Folders(*this);
}