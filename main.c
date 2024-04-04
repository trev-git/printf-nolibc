/**
 * printf without libc
 * 
 * Copyright (c) 2024 trev-git
 * This program is published under the MIT license.
 * Refer to the LICENSE file for more information.
 */

#include "io.h"

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; i++)
        printf("%d %s\n", i, argv[i]);

    printf("%d\n", 69);
    printf("%x\n", 420);
    printf("%s\n", "Hello World");
    printf("%u\n", 1337);
    printf("%c\n", '@');
    printf("%b\n", 69420);
    return 0;
}
