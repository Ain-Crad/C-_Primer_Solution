#include "StrBlobPtr_pointer.h"
#include "StrBlob.h"

StrBlobPtr &StrBlobPtr_pointer::operator*() const
{
    return *sbp;
}

StrBlobPtr *StrBlobPtr_pointer::operator->() const
{
    return sbp;
}