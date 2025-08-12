/* Copyright (c) 2002, 2005, 2007 Joerg Wunsch
   All rights reserved.

   Portions of documentation Copyright (c) 1990, 1991, 1993
   The Regents of the University of California.

   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.

  $Id: stdio.h 2527 2016-10-27 20:41:22Z joerg_wunsch $
*/

#ifndef _STDIO_H_
#define	_STDIO_H_ 1

#include <sys/cdefs.h>
#define __need_NULL
#define __need_size_t
#include <stddef.h>
#define __need___va_list
#include <stdarg.h>
#include <sys/lock.h>
#include <sys/_types.h>

_BEGIN_STD_C

#if !((defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L) || \
     (defined(__cplusplus) && __cplusplus >= 201402L))
     //Provide this function for applications which use an earlier C standard before C11 and C++14
     #define _PICOLIBC_USE_DEPRECATED_GETS
#endif

/*
 * This is an internal structure of the library that is subject to be
 * changed without warnings at any time.  Please do *never* reference
 * elements of it beyond by using the official interfaces provided.
 */

#ifdef __ATOMIC_UNGETC
#if defined(__riscv) || defined(__MICROBLAZE__) || (__loongarch__)
/*
 * Use 32-bit ungetc storage when doing atomic ungetc on RISC-V and
 * MicroBlaze, which have 4-byte swap intrinsics but not 2-byte swap
 * intrinsics. This increases the size of the __file struct by four
 * bytes.
 */
#define __PICOLIBC_UNGETC_SIZE	4
#endif
#endif

#ifndef __PICOLIBC_UNGETC_SIZE
#define __PICOLIBC_UNGETC_SIZE	2
#endif

#if __PICOLIBC_UNGETC_SIZE == 4
typedef __uint32_t __ungetc_t;
#endif

#if __PICOLIBC_UNGETC_SIZE == 2
typedef __uint16_t __ungetc_t;
#endif

struct __file {
	__ungetc_t unget;	/* ungetc() buffer */
	__uint8_t  flags;	/* flags, see below */
#define __SRD	0x0001		/* OK to read */
#define __SWR	0x0002		/* OK to write */
#define __SERR	0x0004		/* found error */
#define __SEOF	0x0008		/* found EOF */
#define __SCLOSE 0x0010		/* struct is __file_close */
#define __SEXT  0x0020          /* struct is __file_ext */
#define __SBUF  0x0040          /* struct is __file_bufio */
#define __SWIDE 0x0080          /* wchar output mode */
	int	(*put)(char, struct __file *);	/* function to write one char to device */
	int	(*get)(struct __file *);	/* function to read one char from device */
	int	(*flush)(struct __file *);	/* function to flush output to device */
#ifdef __STDIO_LOCKING
	_LOCK_RECURSIVE_T lock;
#endif
};

#ifdef __STDIO_LOCKING
#define __STDIO_UNLOCKED(_fn) _fn##_unlocked
#else
#define __STDIO_UNLOCKED(_fn) _fn
#endif

/*
 * This variant includes a 'close' function which is
 * invoked from fclose when the __SCLOSE bit is set
 */
struct __file_close {
	struct __file file;			/* main file struct */
	int	(*close)(struct __file *);	/* function to close file */
};

#define FDEV_SETUP_CLOSE(__put, __get, __flush, __close, __flags) \
        {                                                               \
                .file = FDEV_SETUP_STREAM(__put, __get, __flush, (__flags) | __SCLOSE),   \
                .close = (__close),                                      \
        }

struct __file_ext {
        struct __file_close cfile;              /* close file struct */
        __off_t (*seek)(struct __file *, __off_t offset, int whence);
        int     (*setvbuf)(struct __file *, char *buf, int mode, size_t size);
};

#define FDEV_SETUP_EXT(__put, __get, __flush, __close, __seek, __setvbuf, __flags) \
        {                                                               \
                .cfile = FDEV_SETUP_CLOSE(__put, __get, __flush, __close, (__flags) | __SEXT), \
                .seek = (__seek),                                        \
                .setvbuf = (__setvbuf),                                  \
        }

/*@{*/
/**
   \c FILE is the opaque structure that is passed around between the
   various standard IO functions.
*/
#ifndef ___FILE_DECLARED
typedef struct __file __FILE;
# define ___FILE_DECLARED
#endif

#ifndef _FILE_DECLARED
typedef __FILE FILE;
#define _FILE_DECLARED
#endif

/**
   This symbol is defined when stdin/stdout/stderr are global
   variables. When undefined, the old __iob array is used which
   contains the pointers instead
*/
#define __PICOLIBC_STDIO_GLOBALS

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;

/* The stdin, stdout, and stderr symbols are described as macros in the C
 * standard. */
#define stdin stdin
#define stdout stdout
#define stderr stderr

#define EOF	(-1)

#define	_IOFBF	0		/* setvbuf should set fully buffered */
#define	_IOLBF	1		/* setvbuf should set line buffered */
#define	_IONBF	2		/* setvbuf should set unbuffered */

#define _FDEV_SETUP_READ  __SRD	/**< fdev_setup_stream() with read intent */
#define _FDEV_SETUP_WRITE __SWR	/**< fdev_setup_stream() with write intent */
#define _FDEV_SETUP_RW    (__SRD|__SWR)	/**< fdev_setup_stream() with read/write intent */

/**
 * Return code for an error condition during device read.
 *
 * To be used in the get function of fdevopen().
 */
#define _FDEV_ERR (-1)

/**
 * Return code for an end-of-file condition during device read.
 *
 * To be used in the get function of fdevopen().
 */
#define _FDEV_EOF (-2)

#define FDEV_SETUP_STREAM(__put, __get, __flush, __flags)        \
	{                                           \
                .flags = (__flags),                 \
                .put = (__put),                     \
                .get = (__get),                     \
                .flush = (__flush),                 \
	}

FILE *why_fdevopen(int (*__put)(char, FILE*), int (*__get)(FILE*), int(*__flush)(FILE *));
int	why_fclose(FILE *__stream);
int	why_fflush(FILE *stream);

# define fdev_close(f) (why_fflush(f))

/* Check for old-style printf selection symbols */

#define __IO_VARIANT_DOUBLE       'd'
#define __IO_VARIANT_FLOAT        'f'
#define __IO_VARIANT_LLONG        'l'
#define __IO_VARIANT_INTEGER      'i'
#define __IO_VARIANT_MINIMAL      'm'

#ifndef _PICOLIBC_PRINTF
# if defined(PICOLIBC_DOUBLE_PRINTF_SCANF)
#  define _PICOLIBC_PRINTF __IO_VARIANT_DOUBLE
# elif defined(PICOLIBC_FLOAT_PRINTF_SCANF)
#  define _PICOLIBC_PRINTF __IO_VARIANT_FLOAT
# elif defined(PICOLIBC_LONG_LONG_PRINTF_SCANF)
#  define _PICOLIBC_PRINTF __IO_VARIANT_LLONG
# elif defined(PICOLIBC_INTEGER_PRINTF_SCANF)
#  define _PICOLIBC_PRINTF __IO_VARIANT_INTEGER
# elif defined(PICOLIBC_MINIMAL_PRINTF_SCANF)
#  define _PICOLIBC_PRINTF __IO_VARIANT_MINIMAL
# else
#  define _PICOLIBC_PRINTF __IO_DEFAULT
# endif
#endif

/* Check for old-style scanf selection symbols */

#ifndef _PICOLIBC_SCANF
# if defined(PICOLIBC_DOUBLE_PRINTF_SCANF)
#  define _PICOLIBC_SCANF __IO_VARIANT_DOUBLE
# elif defined(PICOLIBC_FLOAT_PRINTF_SCANF)
#  define _PICOLIBC_SCANF __IO_VARIANT_FLOAT
# elif defined(PICOLIBC_LONG_LONG_PRINTF_SCANF)
#  define _PICOLIBC_SCANF __IO_VARIANT_LLONG
# elif defined(PICOLIBC_INTEGER_PRINTF_SCANF)
#  define _PICOLIBC_SCANF __IO_VARIANT_INTEGER
# elif defined(PICOLIBC_MINIMAL_PRINTF_SCANF)
#  define _PICOLIBC_SCANF __IO_VARIANT_MINIMAL
# else
#  define _PICOLIBC_SCANF __IO_DEFAULT
# endif
#endif

#if _PICOLIBC_PRINTF == __IO_VARIANT_FLOAT
#ifdef __GNUCLIKE_PRAGMA_DIAGNOSTIC
#pragma GCC diagnostic ignored "-Wformat"
#endif
#define __FORMAT_ATTRIBUTE__(__a, __s, __f) __picolibc_format(__a, __s, 0)
#else
#define __FORMAT_ATTRIBUTE__(__a, __s, __f) __picolibc_format(__a, __s, __f)
#endif

#define __PRINTF_ATTRIBUTE__(__s, __f) __FORMAT_ATTRIBUTE__(printf, __s, __f)
#define __SCANF_ATTRIBUTE__(__s, _f) __FORMAT_ATTRIBUTE__(scanf, __s, __f)

int	why_fputc(int __c, FILE *__stream);
int	why_putc(int __c, FILE *__stream);
int	why_putchar(int __c);
#define why_putc(__c, __stream) why_fputc(__c, __stream)
#define why_putchar(__c) why_fputc(__c, stdout)

int	why_printf(const char *__fmt, ...) __PRINTF_ATTRIBUTE__(1, 2);
int	why_fprintf(FILE *__stream, const char *__fmt, ...) __PRINTF_ATTRIBUTE__(2, 3);
int	why_vprintf(const char *__fmt, __gnuc_va_list __ap) __PRINTF_ATTRIBUTE__(1, 0);
int	why_vfprintf(FILE *__stream, const char *__fmt, __gnuc_va_list __ap) __PRINTF_ATTRIBUTE__(2, 0);
int	why_sprintf(char *__s, const char *__fmt, ...) __PRINTF_ATTRIBUTE__(2, 3);
int	why_snprintf(char *__s, size_t __n, const char *__fmt, ...) __PRINTF_ATTRIBUTE__(3, 4);
int	why_vsprintf(char *__s, const char *__fmt, __gnuc_va_list ap) __PRINTF_ATTRIBUTE__(2, 0);
int	why_vsnprintf(char *__s, size_t __n, const char *__fmt, __gnuc_va_list ap) __PRINTF_ATTRIBUTE__(3, 0);
int     why_asprintf(char **strp, const char *fmt, ...) __PRINTF_ATTRIBUTE__(2,3);
char    *why_asnprintf(char *str, size_t *lenp, const char *fmt, ...) __PRINTF_ATTRIBUTE__(3,4);
int     why_vasprintf(char **strp, const char *fmt, __gnuc_va_list ap) __PRINTF_ATTRIBUTE__(2,0);
char    *why_vasnprintf(char *str, size_t *lenp, const char *fmt, __gnuc_va_list ap) __PRINTF_ATTRIBUTE__(3,0);

int	why_fputs(const char *__str, FILE *__stream);
int	why_puts(const char *__str);
size_t	why_fwrite(const void *__ptr, size_t __size, size_t __nmemb,
		       FILE *__stream);

int	why_fgetc(FILE *__stream);
int	why_getc(FILE *__stream);
int	why_getchar(void);
#define why_getchar() getc(stdin)
int	why_ungetc(int __c, FILE *__stream);

int	why_scanf(const char *__fmt, ...) __FORMAT_ATTRIBUTE__(scanf, 1, 2);
int	why_fscanf(FILE *__stream, const char *__fmt, ...) __FORMAT_ATTRIBUTE__(scanf, 2, 3);
int	why_vscanf(const char *__fmt, __gnuc_va_list __ap) __FORMAT_ATTRIBUTE__(scanf, 1, 0);
int	why_vfscanf(FILE *__stream, const char *__fmt, __gnuc_va_list __ap) __FORMAT_ATTRIBUTE__(scanf, 2, 0);
int	why_sscanf(const char *__buf, const char *__fmt, ...) __FORMAT_ATTRIBUTE__(scanf, 2, 3);
int	why_vsscanf(const char *__buf, const char *__fmt, __gnuc_va_list ap) __FORMAT_ATTRIBUTE__(scanf, 2, 0);

char	*why_fgets(char *__str, int __size, FILE *__stream);
#ifdef _PICOLIBC_USE_DEPRECATED_GETS
char *why_gets(char *str);
#endif
size_t	why_fread(void *__ptr, size_t __size, size_t __nmemb,
		      FILE *__stream);

void	why_clearerr(FILE *__stream);
int     why_ferror(FILE *__stream);
int     why_feof(FILE *__stream);

/* fast inlined versions */
#define __why_clearerr_unlocked(s) ((s)->flags &= ~(__SERR | __SEOF))
#define __why_ferror_unlocked(s) ((s)->flags & __SERR)
#define __why_feof_unlocked(s) ((s)->flags & __SEOF)

/* When locking is disabled, use the unlocked macros */
#ifndef __STDIO_LOCKING
#define why_clearerr(s) __why_clearerr_unlocked(s)
#define why_ferror(s) __why_ferror_unlocked(s)
#define why_feof(s) __why_feof_unlocked(s)
#endif

/* Expose the unlocked symbols when requested */
#ifdef __MISC_VISIBLE
void    why_clearerr_unlocked(FILE *__stream);
int     why_ferror_unlocked(FILE *__stream);
int     why_feof_unlocked(FILE *__stream);
#define why_clearerr_unlocked(s) __why_clearerr_unlocked(s)
#define why_ferror_unlocked(s) __why_ferror_unlocked(s)
#define why_feof_unlocked(s) __why_feof_unlocked(s)
#endif

#ifndef SEEK_SET
#define	SEEK_SET	0	/* set file offset to offset */
#endif
#ifndef SEEK_CUR
#define	SEEK_CUR	1	/* set file offset to current plus offset */
#endif
#ifndef SEEK_END
#define	SEEK_END	2	/* set file offset to EOF plus offset */
#endif

/* only mentioned for libstdc++ support, not implemented in library */
#ifndef BUFSIZ
#define BUFSIZ 512
#endif

/*
 * We don't have any way of knowing any underlying POSIX limits,
 * so just use a reasonably small values here
 */
#ifndef FOPEN_MAX
#define FOPEN_MAX 32
#endif
#ifndef FILENAME_MAX
#define FILENAME_MAX 1024
#endif

/*
 * Declare required C types
 *
 * size_t comes from stddef.h (included from cdefs.h)
 */
typedef _fpos_t fpos_t;

#if __POSIX_VISIBLE
/*
 * Declare required additional POSIX types.
 */

# ifndef _OFF_T_DECLARED
typedef	__off_t		off_t;		/* file offset */
#  define _OFF_T_DECLARED
# endif

#ifndef _OFF64_T_DECLARED
typedef __off64_t       off64_t;        /* 64-bit file offset */
#define	_OFF64_T_DECLARED
#endif

# ifndef _SSIZE_T_DECLARED
typedef _ssize_t ssize_t;
#  define _SSIZE_T_DECLARED
# endif

/* This needs to agree with <stdarg.h> */
# ifdef __GNUC__
#  ifndef _VA_LIST_DEFINED
typedef __gnuc_va_list va_list;
#   define _VA_LIST_DEFINED
#  endif
# else
#  include <stdarg.h>
# endif

#endif

int why_fgetpos(FILE * __restrict stream, fpos_t * __restrict pos);
FILE *why_fopen(const char *path, const char *mode) __malloc_like_with_free(why_fclose, 1);
FILE *why_freopen(const char *path, const char *mode, FILE *stream);
FILE *why_fdopen(int, const char *) __malloc_like_with_free(why_fclose, 1);
FILE *why_fmemopen(void *buf, size_t size, const char *mode) __malloc_like_with_free(why_fclose, 1);
int why_fseek(FILE *stream, long offset, int whence);
int why_fseeko(FILE *stream, __off_t offset, int whence);
int why_fsetpos(FILE *stream, const fpos_t *pos);
long why_ftell(FILE *stream);
__off_t why_ftello(FILE *stream);
int why_fileno(FILE *);
void why_perror(const char *s);
int why_remove(const char *pathname);
int why_rename(const char *oldpath, const char *newpath);
void why_rewind(FILE *stream);
void why_setbuf(FILE *stream, char *buf);
void why_setbuffer(FILE *stream, char *buf, size_t size);
void why_setlinebuf(FILE *stream);
int why_setvbuf(FILE *stream, char *buf, int mode, size_t size);
FILE *why_tmpfile(void);
char *why_tmpnam (char *s);
_ssize_t why_getline(char **__restrict lineptr, size_t *__restrict n, FILE *__restrict stream);
_ssize_t why_getdelim(char **__restrict lineptr, size_t *__restrict  n, int delim, FILE *__restrict stream);

#if __BSD_VISIBLE
FILE	*funopen (const void *cookie,
		_ssize_t (*readfn)(void *cookie, void *buf,
				size_t n),
		_ssize_t (*writefn)(void *cookie, const void *buf,
				 size_t n),
		__off_t (*seekfn)(void *cookie, __off_t off, int whence),
		int (*closefn)(void *cookie));
# define	fropen(__cookie, __fn) funopen(__cookie, __fn, NULL, NULL, NULL)
# define	fwopen(__cookie, __fn) funopen(__cookie, NULL, __fn, NULL, NULL)
#endif /*__BSD_VISIBLE */

#if __POSIX_VISIBLE >= 199309L
int	why_getc_unlocked (FILE *);
int	why_getchar_unlocked (void);
void	why_flockfile (FILE *);
int	why_ftrylockfile (FILE *);
void	why_funlockfile (FILE *);
int	why_putc_unlocked (int, FILE *);
int	why_putchar_unlocked (int);
#ifndef __STDIO_LOCKING
#define why_getc_unlocked(f) why_getc(f)
#define why_getchar_unlocked(f) why_getc(stdin)
#define why_putc_unlocked(c, f) why_putc(c, f)
#define why_putchar_unlocked(c, f) why_putc(c, stdout)
#endif
#endif

#if __STDC_WANT_LIB_EXT1__ == 1
#include <sys/_types.h>
#include <stdarg.h>

#ifndef _ERRNO_T_DEFINED
typedef __errno_t errno_t;
#define _ERRNO_T_DEFINED
#endif

#ifndef _RSIZE_T_DEFINED
typedef __rsize_t rsize_t;
#define _RSIZE_T_DEFINED
#endif

int why_sprintf_s(char *__restrict __s, rsize_t __bufsize,
              const char *__restrict __format, ...);
int why_vsnprintf_s(char *__restrict s, rsize_t n, const char *__restrict fmt,
                va_list arg);
int why_vfprintf_s(FILE *__restrict stream, const char *__restrict fmt,
               va_list ap_orig);
#endif

/*
 * The format of tmpnam names is TXXXXXX, which works with mktemp
 */
#define L_tmpnam        8

/*
 * tmpnam files are created in the current directory
 */
#define P_tmpdir        ""

/*
 * We don't have any way of knowing any underlying POSIX limits,
 * so just use a reasonably small value here
 */
#ifndef TMP_MAX
#define TMP_MAX         32
#endif

/*@}*/

static __inline __uint32_t
__why_printf_float(float f)
{
	union {
		float		f;
		__uint32_t	u;
	} u = { .f = f };
	return u.u;
}

/* Express printf capabilities to applications in the form of _HAS_IO values */

#if _PICOLIBC_PRINTF == __IO_VARIANT_MINIMAL
# define printf_float(x) ((double) (x))
# if defined(__IO_MINIMAL_LONG_LONG) || __SIZEOF_LONG_LONG__ == __SIZEOF_LONG__
#  define _HAS_IO_LONG_LONG
# endif
# ifdef __IO_C99_FORMATS
#  define _HAS_IO_C99_FORMATS
# endif
#elif _PICOLIBC_PRINTF == __IO_VARIANT_INTEGER
# define printf_float(x) ((double) (x))
# if defined(__IO_LONG_LONG) || __SIZEOF_LONG_LONG__ == __SIZEOF_LONG__
#  define _HAS_IO_LONG_LONG
# endif
# ifdef __IO_POS_ARGS
#  define _HAS_IO_POS_ARGS
# endif
# ifdef __IO_C99_FORMATS
#  define _HAS_IO_C99_FORMATS
# endif
# ifdef __IO_PERCENT_B
#  define _HAS_IO_PERCENT_B
# endif
#elif _PICOLIBC_PRINTF == __IO_VARIANT_LLONG
# define printf_float(x) ((double) (x))
# define _HAS_IO_LONG_LONG
# ifdef __IO_POS_ARGS
#  define _HAS_IO_POS_ARGS
# endif
# ifdef __IO_C99_FORMATS
#  define _HAS_IO_C99_FORMATS
# endif
# ifdef __IO_PERCENT_B
#  define _HAS_IO_PERCENT_B
# endif
#elif _PICOLIBC_PRINTF == __IO_VARIANT_FLOAT
# define why_printf_float(x) __why_printf_float(x)
# define _HAS_IO_LONG_LONG
# define _HAS_IO_POS_ARGS
# define _HAS_IO_C99_FORMATS
# ifdef __IO_PERCENT_B
#  define _HAS_IO_PERCENT_B
# endif
# define _HAS_IO_FLOAT
#else /* _PICOLIBC_PRINTF == __IO_VARIANT_DOUBLE */
# define printf_float(x) ((double) (x))
# define _HAS_IO_LONG_LONG
# define _HAS_IO_POS_ARGS
# define _HAS_IO_C99_FORMATS
# define _HAS_IO_DOUBLE
# if defined(__MB_CAPABLE) || defined(__IO_WCHAR)
#  define _HAS_IO_WCHAR
# endif
# ifdef __MB_CAPABLE
#  define _HAS_IO_MBCHAR
# endif
# ifdef __IO_PERCENT_B
#  define _HAS_IO_PERCENT_B
# endif
# ifdef __IO_LONG_DOUBLE
#  define _HAS_IO_LONG_DOUBLE
# endif
#endif

_END_STD_C

#if __SSP_FORTIFY_LEVEL > 0
#include <ssp/stdio.h>
#endif

#endif /* _STDIO_H_ */
