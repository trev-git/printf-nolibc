/**
 * Copyright (c) 2024 trev-git
 * This program is published under the MIT license.
 * Refer to the LICENSE file for more information.
 */

.text
.globl _start
.extern main
_start:
    # rdi
    movq (%rsp), %rdi
    # rsi
    leaq 8(%rsp), %rsi
    call main
    movq %rax, %rdi # our exit code from main
    movq $0x3c, %rax # code for syscall exit
    syscall
