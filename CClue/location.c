#include "location.h"

void locationToString( location *loc, char *buffer, unsigned int buffLen )
{
    if (loc->rm != NULL) {
        snprintf(buffer, buffLen, "(%d, %d)", loc->col, loc->row);
    } else {
        snprintf(buffer, buffLen, "%s", loc->rm->name);
    }
}
