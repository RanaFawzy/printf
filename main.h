#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
/* SIZES */
#define S_LONG 2
#define S_SHORT 1
/**
 * typedef struct fmt fmt_t - Struct oopp ..
 *
 * @fmt: A formattt…
 * @fm_t: A function was associateddd...
 */
typedef struct fmtt  fmtt_ttt;
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
