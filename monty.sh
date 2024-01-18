#!/bin/bash
gcc -Wall -Werror -Wextra -pedantic -std=c89 -D_POSIX_C_SOURCE=200809 *.c -o monty
