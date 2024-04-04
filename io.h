/**
 * Copyright (c) 2024 trev-git
 * This program is published under the MIT license.
 * Refer to the LICENSE file for more information.
 */

#ifndef IO_H
#define IO_H

#define stdin   0
#define stdout  1
#define stderr  2

void printf(char *fmt, ...);
void puts(const char *str);
void putchar(int c);
int write(int fd, const char *buf, unsigned int count);

#endif // IO_H
