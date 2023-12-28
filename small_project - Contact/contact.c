#include "contact.h"

void InitContact(struct Contact* ps)
{
    memset(ps->data, 0, sizeof(ps->data));
    ps->size = 0;
}