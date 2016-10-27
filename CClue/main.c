#include <stdlib.h>
#include <stdio.h>
#include "location.h"
#include "boardGraph.h"

int main(int argc, char *argv[])
{
    char buffer[256];
    locationToString(&Library, buffer, sizeof(buffer));
    printf("%s\n", buffer);
    return 0;
}
