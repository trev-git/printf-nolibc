/**
 * Copyright (c) 2024 trev-git
 * This program is published under the MIT license.
 * Refer to the LICENSE file for more information.
 */

#include <stdarg.h>

#include "io.h"

#define MAXBUF (sizeof(long long) * 8)

/**
 * This function only supports the following format specifiers:
 * %d - decimal integer;
 * %x - hexadecimal representation;
 * %s - string;
 * %u - decimal unsigned integer;
 * %c - character;
 * %b - binary representation.
 */

void printf(char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    const char *digits = "0123456789abcdef";
    char c;
    while ((c = *fmt) != '\0')
    {
        if (c != '%')
        {
            putchar(c);
            fmt++;
            continue;
        }
        fmt++;
        c = *fmt;
        switch (c)
        {
        case 'c':
        {
            putchar(va_arg(ap, int));
            fmt++;
            break;
        }
        case 's':
        {
            const char *str = va_arg(ap, const char *);
            puts(str);
            fmt++;
            break;
        }
        case 'u':
        {
            unsigned int num = va_arg(ap, int);
            char buf[MAXBUF];
            int i = 0;
            do {
                buf[i] = digits[num % 10];
                num /= 10;
                i++;
            } while (num != 0);
            i--;
            for (; i >= 0; i--)
                putchar(buf[i]);
            fmt++;
            break;
        }
        case 'x':
        {
            int num = va_arg(ap, int);
            char buf[MAXBUF];
            int i = 0;
            do {
                buf[i] = digits[num % 16];
                num /= 16;
                i++;
            } while (num != 0);
            i--;
            puts("0x");
            for (; i >= 0; i--)
                putchar(buf[i]);
            fmt++;
            break;
        }
        case 'd':
        {
            int num = va_arg(ap, int);
            if (num < 0) {
                putchar('-');
                num = -num;
            }
            char buf[MAXBUF];
            int i = 0;
            do {
                buf[i] = digits[num % 10];
                num /= 10;
                i++;
            } while (num != 0);
            i--;
            for (; i >= 0; i--)
                putchar(buf[i]);
            fmt++;
            break;
        }
        case 'b':
        {
            int num = va_arg(ap, int);
            char buf[MAXBUF];

            int i = 0;
            do {
                buf[i] = digits[num % 2];
                num /= 2;
                i++;
            } while (num != 0);
            puts("0b");
            i--;
            for (; i >= 0; i--)
                putchar(buf[i]);
            fmt++;
            break;
        }
        default:
        {
            putchar(c);
            fmt++;
            break;
        }
        }
    }
    va_end(ap);
}

void puts(const char *str)
{
    int c;
    while ((c = *str++) != '\0')
    {
        putchar(c);
    }
}

void putchar(int c)
{
    write(stdout, (char*)&c, 1);
}

int write(int fd, const char *buf, unsigned int count)
{
    int ret;
    __asm__ volatile (
        "movq $1, %%rax \n"
        "movl %1, %%edi \n"
        "movq %2, %%rsi \n"
        "movl %3, %%edx \n"
        "syscall \n"
        "movl %%eax, %0 \n"
        : "=r" (ret)
        : "r" (fd), "r" (buf), "r" (count)
        : "%eax", "%edi", "%esi", "%edx", "memory"
    );
    return ret;
}
