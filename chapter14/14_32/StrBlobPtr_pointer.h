#ifndef _STRBLOBPTR_POINTER_H
#define _STRBLOBPTR_POINTER_H

class StrBlobPtr;
class StrBlobPtr_pointer
{
public:
    StrBlobPtr_pointer() : sbp(nullptr) {}
    StrBlobPtr_pointer(StrBlobPtr *p) : sbp(p) {}
    StrBlobPtr &operator*() const;
    StrBlobPtr *operator->() const;

private:
    StrBlobPtr *sbp;
};

#endif