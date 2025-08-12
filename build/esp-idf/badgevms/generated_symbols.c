
#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif
#include <string.h>
#include <stdint.h>

#include <complex.h>
#include <ctype.h>
#include <fenv.h>
#include <float.h>
#include <fnmatch.h>
#include <getopt.h>
#include <iconv.h>
#include <ieeefp.h>
#include <inttypes.h>
#include <langinfo.h>
#include <locale.h>
#include <math.h>
#include <regex.h>
#include <sdkconfig.h>
#include <search.h>
#include <setjmp.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <wchar.h>
#include <wctype.h>
#include <badgevms/application.h>
#include <badgevms/compositor.h>
#include <badgevms/device.h>
#include <badgevms/event.h>
#include <badgevms/misc_funcs.h>
#include <badgevms/ota.h>
#include <badgevms/process.h>
#include <badgevms/wifi.h>
#include <curl/curl.h>
#include <wrapped_funcs.h>
#include <netdb.h>

struct esp_elfsym {
    const char  *name;
    const void  *sym;
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbuiltin-declaration-mismatch"
extern void __adddf3();
extern void __assert_func();
extern void __clzsi2();
extern void __divdf3();
extern void __divdi3();
extern void __eqdf2();
extern void __extendhfsf2();
extern void __extendsfdf2();
extern void __fixdfdi();
extern void __fixdfsi();
extern void __fixunsdfsi();
extern void __floatdisf();
extern void __floatsidf();
extern void __floatunsidf();
extern void __gedf2();
extern void __gtdf2();
extern void __issignalingf();
extern void __ledf2();
extern void __ltdf2();
extern void __muldf3();
extern void __popcountsi2();
extern void __riscv_restore_0();
extern void __riscv_restore_1();
extern void __riscv_restore_10();
extern void __riscv_restore_11();
extern void __riscv_restore_12();
extern void __riscv_restore_2();
extern void __riscv_restore_3();
extern void __riscv_restore_4();
extern void __riscv_restore_5();
extern void __riscv_restore_6();
extern void __riscv_restore_7();
extern void __riscv_restore_8();
extern void __riscv_restore_9();
extern void __riscv_save_0();
extern void __riscv_save_1();
extern void __riscv_save_10();
extern void __riscv_save_11();
extern void __riscv_save_12();
extern void __riscv_save_2();
extern void __riscv_save_3();
extern void __riscv_save_4();
extern void __riscv_save_5();
extern void __riscv_save_6();
extern void __riscv_save_7();
extern void __riscv_save_8();
extern void __riscv_save_9();
extern void __subdf3();
extern void __truncdfsf2();
extern void __truncsfhf2();
extern void __udivdi3();
extern void __umoddi3();
extern int _ctype_b;
extern void why__Exit();
extern void why_abort();
extern void why_accept();
extern void why_asctime();
extern void why_asnprintf();
extern void why_asprintf();
extern void why_atexit();
extern void why_bind();
extern void why_calloc();
extern void why_clearerr();
extern void why_clearerr_unlocked();
extern void why_close();
extern void why_closedir();
extern void why_connect();
extern void why_ctime();
extern void why_die();
extern void why_exit();
extern void why_fclose();
extern void why_fdopen();
extern void why_feof();
extern void why_ferror();
extern void why_fflush();
extern void why_fgetc();
extern void why_fgetpos();
extern void why_fgets();
extern void why_fileno();
extern void why_fmemopen();
extern void why_fopen();
extern void why_fprintf();
extern void why_fputc();
extern void why_fputs();
extern void why_fread();
extern void why_free();
extern void why_freopen();
extern void why_fscanf();
extern void why_fseek();
extern void why_fseeko();
extern void why_fstat();
extern void why_ftell();
extern void why_ftello();
extern void why_funopen();
extern void why_fwrite();
extern void why_gcvt();
extern void why_gcvtf();
extern void why_gcvtl();
extern void why_getc();
extern void why_getchar();
extern void why_getchar_unlocked();
extern void why_getdelim();
extern void why_getenv();
extern void why_getline();
extern void why_getpid();
extern void why_gets();
extern void why_gmtime();
extern void why_iconv_close();
extern void why_iconv_open();
extern void why_isatty();
extern void why_listen();
extern void why_localtime();
extern void why_lseek();
extern void why_malloc();
extern void why_mkdir();
extern void why_open();
extern void why_opendir();
extern void why_printf();
extern void why_putchar();
extern void why_puts();
extern void why_rand();
extern void why_random();
extern void why_read();
extern void why_readdir();
extern void why_realloc();
extern void why_reallocarray();
extern void why_regcomp();
extern void why_regfree();
extern void why_remove();
extern void why_rename();
extern void why_rewind();
extern void why_rewinddir();
extern void why_rmdir();
extern void why_scanf();
extern void why_setbuf();
extern void why_setbuffer();
extern void why_setlinebuf();
extern void why_setvbuf();
extern void why_snprintf();
extern void why_socket();
extern void why_sprintf();
extern void why_srand();
extern void why_srandom();
extern void why_sscanf();
extern void why_stat();
extern void why_strdup();
extern void why_strerror();
extern void why_strndup();
extern void why_strtok();
extern void why_system();
extern void why_tcgetattr();
extern void why_tcsetattr();
extern void why_ungetc();
extern void why_unlink();
extern void why_vasprintf();
extern void why_vfprintf();
extern void why_vfscanf();
extern void why_vprintf();
extern void why_vscanf();
extern void why_vsnprintf();
extern void why_vsprintf();
extern void why_vsscanf();
extern void why_wcsdup();
extern void why_write();
extern int why_stdin;
extern int why_stdout;
extern int why_stderr;
extern int why___errno;
extern int why_environ;
#pragma GCC diagnostic pop

struct esp_elfsym why2025_elfsyms[] = {
{"_Exit", &why__Exit},
{"__adddf3", &__adddf3},
{"__assert_func", &__assert_func},
{"__clzsi2", &__clzsi2},
{"__divdf3", &__divdf3},
{"__divdi3", &__divdi3},
{"__eqdf2", &__eqdf2},
{"__errno", &why___errno},
{"__extendhfsf2", &__extendhfsf2},
{"__extendsfdf2", &__extendsfdf2},
{"__fixdfdi", &__fixdfdi},
{"__fixdfsi", &__fixdfsi},
{"__fixunsdfsi", &__fixunsdfsi},
{"__floatdisf", &__floatdisf},
{"__floatsidf", &__floatsidf},
{"__floatunsidf", &__floatunsidf},
{"__gedf2", &__gedf2},
{"__gtdf2", &__gtdf2},
{"__issignalingf", &__issignalingf},
{"__ledf2", &__ledf2},
{"__ltdf2", &__ltdf2},
{"__muldf3", &__muldf3},
{"__popcountsi2", &__popcountsi2},
{"__riscv_restore_0", &__riscv_restore_0},
{"__riscv_restore_1", &__riscv_restore_1},
{"__riscv_restore_10", &__riscv_restore_10},
{"__riscv_restore_11", &__riscv_restore_11},
{"__riscv_restore_12", &__riscv_restore_12},
{"__riscv_restore_2", &__riscv_restore_2},
{"__riscv_restore_3", &__riscv_restore_3},
{"__riscv_restore_4", &__riscv_restore_4},
{"__riscv_restore_5", &__riscv_restore_5},
{"__riscv_restore_6", &__riscv_restore_6},
{"__riscv_restore_7", &__riscv_restore_7},
{"__riscv_restore_8", &__riscv_restore_8},
{"__riscv_restore_9", &__riscv_restore_9},
{"__riscv_save_0", &__riscv_save_0},
{"__riscv_save_1", &__riscv_save_1},
{"__riscv_save_10", &__riscv_save_10},
{"__riscv_save_11", &__riscv_save_11},
{"__riscv_save_12", &__riscv_save_12},
{"__riscv_save_2", &__riscv_save_2},
{"__riscv_save_3", &__riscv_save_3},
{"__riscv_save_4", &__riscv_save_4},
{"__riscv_save_5", &__riscv_save_5},
{"__riscv_save_6", &__riscv_save_6},
{"__riscv_save_7", &__riscv_save_7},
{"__riscv_save_8", &__riscv_save_8},
{"__riscv_save_9", &__riscv_save_9},
{"__subdf3", &__subdf3},
{"__truncdfsf2", &__truncdfsf2},
{"__truncsfhf2", &__truncsfhf2},
{"__udivdi3", &__udivdi3},
{"__umoddi3", &__umoddi3},
{"_ctype_", &_ctype_},
{"_ctype_b", &_ctype_b},
{"a64l", &a64l},
{"abort", &why_abort},
{"abs", &abs},
{"accept", &why_accept},
{"acos", &acos},
{"acosf", &acosf},
{"acosh", &acosh},
{"acoshf", &acoshf},
{"acoshl", &acoshl},
{"acosl", &acosl},
{"application_create", &application_create},
{"application_create_file", &application_create_file},
{"application_create_file_string", &application_create_file_string},
{"application_destroy", &application_destroy},
{"application_free", &application_free},
{"application_get", &application_get},
{"application_launch", &application_launch},
{"application_list", &application_list},
{"application_list_close", &application_list_close},
{"application_list_get_next", &application_list_get_next},
{"application_set_author", &application_set_author},
{"application_set_binary_path", &application_set_binary_path},
{"application_set_interpreter", &application_set_interpreter},
{"application_set_metadata", &application_set_metadata},
{"application_set_name", &application_set_name},
{"application_set_version", &application_set_version},
{"asctime", &why_asctime},
{"asctime_r", &asctime_r},
{"asin", &asin},
{"asinf", &asinf},
{"asinh", &asinh},
{"asinhf", &asinhf},
{"asinhl", &asinhl},
{"asinl", &asinl},
{"asnprintf", &why_asnprintf},
{"asprintf", &why_asprintf},
{"atan", &atan},
{"atan2", &atan2},
{"atan2f", &atan2f},
{"atan2l", &atan2l},
{"atanf", &atanf},
{"atanh", &atanh},
{"atanhf", &atanhf},
{"atanhl", &atanhl},
{"atanl", &atanl},
{"atexit", &why_atexit},
{"atof", &atof},
{"atoff", &atoff},
{"atoi", &atoi},
{"atol", &atol},
{"atoll", &atoll},
{"bcmp", &bcmp},
{"bcopy", &bcopy},
{"bind", &why_bind},
{"bsearch", &bsearch},
{"btowc", &btowc},
{"bzero", &bzero},
{"cabs", &cabs},
{"cabsf", &cabsf},
{"cabsl", &cabsl},
{"cacos", &cacos},
{"cacosf", &cacosf},
{"cacosh", &cacosh},
{"cacoshf", &cacoshf},
{"cacoshl", &cacoshl},
{"cacosl", &cacosl},
{"calloc", &why_calloc},
{"carg", &carg},
{"cargf", &cargf},
{"cargl", &cargl},
{"casin", &casin},
{"casinf", &casinf},
{"casinh", &casinh},
{"casinhf", &casinhf},
{"casinhl", &casinhl},
{"casinl", &casinl},
{"catan", &catan},
{"catanf", &catanf},
{"catanh", &catanh},
{"catanhf", &catanhf},
{"catanhl", &catanhl},
{"catanl", &catanl},
{"cbrt", &cbrt},
{"cbrtf", &cbrtf},
{"cbrtl", &cbrtl},
{"ccos", &ccos},
{"ccosf", &ccosf},
{"ccosh", &ccosh},
{"ccoshf", &ccoshf},
{"ccoshl", &ccoshl},
{"ccosl", &ccosl},
{"ceil", &ceil},
{"ceilf", &ceilf},
{"ceill", &ceill},
{"cexp", &cexp},
{"cexpf", &cexpf},
{"cexpl", &cexpl},
{"cimag", &cimag},
{"cimagf", &cimagf},
{"cimagl", &cimagl},
{"clearerr", &why_clearerr},
{"clearerr_unlocked", &why_clearerr_unlocked},
{"clock", &clock},
{"clock_gettime", &clock_gettime},
{"clog", &clog},
{"clog10", &clog10},
{"clog10f", &clog10f},
{"clogf", &clogf},
{"clogl", &clogl},
{"close", &why_close},
{"closedir", &why_closedir},
{"conj", &conj},
{"conjf", &conjf},
{"conjl", &conjl},
{"connect", &why_connect},
{"copysign", &copysign},
{"copysignf", &copysignf},
{"copysignl", &copysignl},
{"cos", &cos},
{"cosf", &cosf},
{"cosh", &cosh},
{"coshf", &coshf},
{"coshl", &coshl},
{"cosl", &cosl},
{"cpow", &cpow},
{"cpowf", &cpowf},
{"cpowl", &cpowl},
{"cproj", &cproj},
{"cprojf", &cprojf},
{"cprojl", &cprojl},
{"creal", &creal},
{"crealf", &crealf},
{"creall", &creall},
{"csin", &csin},
{"csinf", &csinf},
{"csinh", &csinh},
{"csinhf", &csinhf},
{"csinhl", &csinhl},
{"csinl", &csinl},
{"csqrt", &csqrt},
{"csqrtf", &csqrtf},
{"csqrtl", &csqrtl},
{"ctan", &ctan},
{"ctanf", &ctanf},
{"ctanh", &ctanh},
{"ctanhf", &ctanhf},
{"ctanhl", &ctanhl},
{"ctanl", &ctanl},
{"ctime", &why_ctime},
{"ctime_r", &ctime_r},
{"curl_easy_cleanup", &curl_easy_cleanup},
{"curl_easy_getinfo", &curl_easy_getinfo},
{"curl_easy_init", &curl_easy_init},
{"curl_easy_perform", &curl_easy_perform},
{"curl_easy_setopt", &curl_easy_setopt},
{"curl_easy_strerror", &curl_easy_strerror},
{"curl_global_cleanup", &curl_global_cleanup},
{"curl_global_init", &curl_global_init},
{"curl_slist_append", &curl_slist_append},
{"curl_slist_free_all", &curl_slist_free_all},
{"device_get", &device_get},
{"die", &why_die},
{"difftime", &difftime},
{"diprintf", &diprintf},
{"div", &div},
{"drem", &drem},
{"dremf", &dremf},
{"environ", &why_environ},
{"erf", &erf},
{"erfc", &erfc},
{"erfcf", &erfcf},
{"erfcl", &erfcl},
{"erff", &erff},
{"erfl", &erfl},
{"exit", &why_exit},
{"exp", &exp},
{"exp10", &exp10},
{"exp10f", &exp10f},
{"exp2", &exp2},
{"exp2f", &exp2f},
{"exp2l", &exp2l},
{"expf", &expf},
{"expl", &expl},
{"explicit_bzero", &explicit_bzero},
{"expm1", &expm1},
{"expm1f", &expm1f},
{"expm1l", &expm1l},
{"fabs", &fabs},
{"fabsf", &fabsf},
{"fabsl", &fabsl},
{"fclose", &why_fclose},
{"fdim", &fdim},
{"fdimf", &fdimf},
{"fdiml", &fdiml},
{"fdopen", &why_fdopen},
{"feclearexcept", &feclearexcept},
{"fegetenv", &fegetenv},
{"fegetexceptflag", &fegetexceptflag},
{"fegetround", &fegetround},
{"feholdexcept", &feholdexcept},
{"feof", &why_feof},
{"feraiseexcept", &feraiseexcept},
{"ferror", &why_ferror},
{"fesetenv", &fesetenv},
{"fesetexceptflag", &fesetexceptflag},
{"fesetround", &fesetround},
{"fetestexcept", &fetestexcept},
{"feupdateenv", &feupdateenv},
{"fflush", &why_fflush},
{"ffs", &ffs},
{"ffsl", &ffsl},
{"ffsll", &ffsll},
{"fgetc", &why_fgetc},
{"fgetpos", &why_fgetpos},
{"fgets", &why_fgets},
{"fileno", &why_fileno},
{"finite", &finite},
{"finitef", &finitef},
{"finitel", &finitel},
{"floor", &floor},
{"floorf", &floorf},
{"floorl", &floorl},
{"fls", &fls},
{"flsl", &flsl},
{"flsll", &flsll},
{"fma", &fma},
{"fmaf", &fmaf},
{"fmal", &fmal},
{"fmax", &fmax},
{"fmaxf", &fmaxf},
{"fmaxl", &fmaxl},
{"fmemopen", &why_fmemopen},
{"fmin", &fmin},
{"fminf", &fminf},
{"fminl", &fminl},
{"fmod", &fmod},
{"fmodf", &fmodf},
{"fmodl", &fmodl},
{"fnmatch", &fnmatch},
{"fopen", &why_fopen},
{"fpgetmask", &fpgetmask},
{"fpgetround", &fpgetround},
{"fpgetsticky", &fpgetsticky},
{"fprintf", &why_fprintf},
{"fpsetmask", &fpsetmask},
{"fpsetround", &fpsetround},
{"fpsetsticky", &fpsetsticky},
{"fputc", &why_fputc},
{"fputs", &why_fputs},
{"fread", &why_fread},
{"free", &why_free},
{"freeaddrinfo", &freeaddrinfo},
{"freopen", &why_freopen},
{"frexp", &frexp},
{"frexpf", &frexpf},
{"frexpl", &frexpl},
{"fscanf", &why_fscanf},
{"fseek", &why_fseek},
{"fseeko", &why_fseeko},
{"fstat", &why_fstat},
{"ftell", &why_ftell},
{"ftello", &why_ftello},
{"funopen", &why_funopen},
{"fwide", &fwide},
{"fwrite", &why_fwrite},
{"gamma", &gamma},
{"gamma_r", &gamma_r},
{"gammaf", &gammaf},
{"gammaf_r", &gammaf_r},
{"gcvt", &why_gcvt},
{"gcvtf", &why_gcvtf},
{"gcvtl", &why_gcvtl},
{"get_mac_address", &get_mac_address},
{"get_num_tasks", &get_num_tasks},
{"get_screen_info", &get_screen_info},
{"getaddrinfo", &getaddrinfo},
{"getc", &why_getc},
{"getchar", &why_getchar},
{"getchar_unlocked", &why_getchar_unlocked},
{"getdelim", &why_getdelim},
{"getentropy", &getentropy},
{"getenv", &why_getenv},
{"getline", &why_getline},
{"getopt", &getopt},
{"getopt_long", &getopt_long},
{"getopt_long_only", &getopt_long_only},
{"getpid", &why_getpid},
{"gets", &why_gets},
{"getsubopt", &getsubopt},
{"gettimeofday", &gettimeofday},
{"gmtime", &why_gmtime},
{"gmtime_r", &gmtime_r},
{"hypot", &hypot},
{"hypotf", &hypotf},
{"hypotl", &hypotl},
{"iconv", &iconv},
{"iconv_close", &why_iconv_close},
{"iconv_open", &why_iconv_open},
{"ilogb", &ilogb},
{"ilogbf", &ilogbf},
{"ilogbl", &ilogbl},
{"imaxabs", &imaxabs},
{"imaxdiv", &imaxdiv},
{"index", &index},
{"inet_aton", &inet_aton},
{"inet_ntoa", &inet_ntoa},
{"infinity", &infinity},
{"infinityf", &infinityf},
{"isalnum", &isalnum},
{"isalnum_l", &isalnum_l},
{"isalpha", &isalpha},
{"isalpha_l", &isalpha_l},
{"isascii", &isascii},
{"isascii_l", &isascii_l},
{"isatty", &why_isatty},
{"isblank", &isblank},
{"isblank_l", &isblank_l},
{"iscntrl", &iscntrl},
{"iscntrl_l", &iscntrl_l},
{"isdigit", &isdigit},
{"isdigit_l", &isdigit_l},
{"isgraph", &isgraph},
{"isgraph_l", &isgraph_l},
{"isinf", &isinf},
{"isinff", &isinff},
{"islower", &islower},
{"islower_l", &islower_l},
{"isnan", &isnan},
{"isnanf", &isnanf},
{"isprint", &isprint},
{"isprint_l", &isprint_l},
{"ispunct", &ispunct},
{"ispunct_l", &ispunct_l},
{"isspace", &isspace},
{"isspace_l", &isspace_l},
{"isupper", &isupper},
{"isupper_l", &isupper_l},
{"iswalnum", &iswalnum},
{"iswalnum_l", &iswalnum_l},
{"iswalpha", &iswalpha},
{"iswalpha_l", &iswalpha_l},
{"iswblank", &iswblank},
{"iswblank_l", &iswblank_l},
{"iswcntrl", &iswcntrl},
{"iswcntrl_l", &iswcntrl_l},
{"iswctype", &iswctype},
{"iswctype_l", &iswctype_l},
{"iswdigit", &iswdigit},
{"iswdigit_l", &iswdigit_l},
{"iswgraph", &iswgraph},
{"iswgraph_l", &iswgraph_l},
{"iswlower", &iswlower},
{"iswlower_l", &iswlower_l},
{"iswprint", &iswprint},
{"iswprint_l", &iswprint_l},
{"iswpunct", &iswpunct},
{"iswpunct_l", &iswpunct_l},
{"iswspace", &iswspace},
{"iswspace_l", &iswspace_l},
{"iswupper", &iswupper},
{"iswupper_l", &iswupper_l},
{"iswxdigit", &iswxdigit},
{"iswxdigit_l", &iswxdigit_l},
{"isxdigit", &isxdigit},
{"isxdigit_l", &isxdigit_l},
{"itoa", &itoa},
{"j0", &j0},
{"j0f", &j0f},
{"j1", &j1},
{"j1f", &j1f},
{"jn", &jn},
{"jnf", &jnf},
{"l64a", &l64a},
{"labs", &labs},
{"ldexp", &ldexp},
{"ldexpf", &ldexpf},
{"ldexpl", &ldexpl},
{"ldiv", &ldiv},
{"lgamma", &lgamma},
{"lgamma_r", &lgamma_r},
{"lgammaf", &lgammaf},
{"lgammaf_r", &lgammaf_r},
{"lgammal", &lgammal},
{"link", &link},
{"listen", &why_listen},
{"llabs", &llabs},
{"lldiv", &lldiv},
{"llrint", &llrint},
{"llrintf", &llrintf},
{"llrintl", &llrintl},
{"llround", &llround},
{"llroundf", &llroundf},
{"llroundl", &llroundl},
{"localeconv", &localeconv},
{"localtime", &why_localtime},
{"localtime_r", &localtime_r},
{"log", &log},
{"log10", &log10},
{"log10f", &log10f},
{"log10l", &log10l},
{"log1p", &log1p},
{"log1pf", &log1pf},
{"log1pl", &log1pl},
{"log2", &log2},
{"log2f", &log2f},
{"log2l", &log2l},
{"logb", &logb},
{"logbf", &logbf},
{"logbl", &logbl},
{"logf", &logf},
{"logl", &logl},
{"longjmp", &longjmp},
{"lrint", &lrint},
{"lrintf", &lrintf},
{"lrintl", &lrintl},
{"lround", &lround},
{"lroundf", &lroundf},
{"lroundl", &lroundl},
{"lseek", &why_lseek},
{"malloc", &why_malloc},
{"mblen", &mblen},
{"mbrlen", &mbrlen},
{"mbrtowc", &mbrtowc},
{"mbsinit", &mbsinit},
{"mbsnrtowcs", &mbsnrtowcs},
{"mbsrtowcs", &mbsrtowcs},
{"mbstowcs", &mbstowcs},
{"mbtowc", &mbtowc},
{"memccpy", &memccpy},
{"memchr", &memchr},
{"memcmp", &memcmp},
{"memcpy", &memcpy},
{"memmem", &memmem},
{"memmove", &memmove},
{"mempcpy", &mempcpy},
{"memrchr", &memrchr},
{"memset", &memset},
{"mkdir", &why_mkdir},
{"mkdir_p", &mkdir_p},
{"mktime", &mktime},
{"modf", &modf},
{"modff", &modff},
{"nan", &nan},
{"nanf", &nanf},
{"nearbyint", &nearbyint},
{"nearbyintf", &nearbyintf},
{"nearbyintl", &nearbyintl},
{"nextafter", &nextafter},
{"nextafterf", &nextafterf},
{"nextafterl", &nextafterl},
{"nexttoward", &nexttoward},
{"nexttowardf", &nexttowardf},
{"nexttowardl", &nexttowardl},
{"nl_langinfo", &nl_langinfo},
{"nl_langinfo_l", &nl_langinfo_l},
{"open", &why_open},
{"opendir", &why_opendir},
{"ota_get_invalid_version", &ota_get_invalid_version},
{"ota_get_running_version", &ota_get_running_version},
{"ota_session_abort", &ota_session_abort},
{"ota_session_commit", &ota_session_commit},
{"ota_session_open", &ota_session_open},
{"ota_write", &ota_write},
{"parse_path", &parse_path},
{"path_basename", &path_basename},
{"path_concat", &path_concat},
{"path_devname", &path_devname},
{"path_dirconcat", &path_dirconcat},
{"path_dirname", &path_dirname},
{"path_fileconcat", &path_fileconcat},
{"path_free", &path_free},
{"pow", &pow},
{"pow10", &pow10},
{"pow10f", &pow10f},
{"powf", &powf},
{"powl", &powl},
{"printf", &why_printf},
{"process_create", &process_create},
{"putchar", &why_putchar},
{"puts", &why_puts},
{"qsort", &qsort},
{"qsort_r", &qsort_r},
{"rand", &why_rand},
{"rand_r", &rand_r},
{"random", &why_random},
{"rawmemchr", &rawmemchr},
{"read", &why_read},
{"readdir", &why_readdir},
{"realloc", &why_realloc},
{"reallocarray", &why_reallocarray},
{"regcomp", &why_regcomp},
{"regerror", &regerror},
{"regexec", &regexec},
{"regfree", &why_regfree},
{"remainder", &remainder},
{"remainderf", &remainderf},
{"remainderl", &remainderl},
{"remove", &why_remove},
{"remquo", &remquo},
{"remquof", &remquof},
{"remquol", &remquol},
{"rename", &why_rename},
{"rewind", &why_rewind},
{"rewinddir", &why_rewinddir},
{"rindex", &rindex},
{"rint", &rint},
{"rintf", &rintf},
{"rintl", &rintl},
{"rm_rf", &rm_rf},
{"rmdir", &why_rmdir},
{"round", &round},
{"roundf", &roundf},
{"roundl", &roundl},
{"rpmatch", &rpmatch},
{"scalbln", &scalbln},
{"scalblnf", &scalblnf},
{"scalblnl", &scalblnl},
{"scalbn", &scalbn},
{"scalbnf", &scalbnf},
{"scalbnl", &scalbnl},
{"scanf", &why_scanf},
{"select", &select},
{"setbuf", &why_setbuf},
{"setbuffer", &why_setbuffer},
{"setjmp", &setjmp},
{"setlinebuf", &why_setlinebuf},
{"setvbuf", &why_setvbuf},
{"sig2str", &sig2str},
{"sin", &sin},
{"sincos", &sincos},
{"sincosf", &sincosf},
{"sinf", &sinf},
{"sinh", &sinh},
{"sinhf", &sinhf},
{"sinhl", &sinhl},
{"sinl", &sinl},
{"sleep", &sleep},
{"snprintf", &why_snprintf},
{"socket", &why_socket},
{"sprintf", &why_sprintf},
{"sqrt", &sqrt},
{"sqrtf", &sqrtf},
{"sqrtl", &sqrtl},
{"srand", &why_srand},
{"srandom", &why_srandom},
{"sscanf", &why_sscanf},
{"stat", &why_stat},
{"stderr", &why_stderr},
{"stdin", &why_stdin},
{"stdout", &why_stdout},
{"stpcpy", &stpcpy},
{"stpncpy", &stpncpy},
{"str2sig", &str2sig},
{"strcasecmp", &strcasecmp},
{"strcasecmp_l", &strcasecmp_l},
{"strcasestr", &strcasestr},
{"strcat", &strcat},
{"strchr", &strchr},
{"strchrnul", &strchrnul},
{"strcmp", &strcmp},
{"strcoll", &strcoll},
{"strcoll_l", &strcoll_l},
{"strcpy", &strcpy},
{"strcspn", &strcspn},
{"strdup", &why_strdup},
{"strerror", &why_strerror},
{"strerror_r", &strerror_r},
{"strftime", &strftime},
{"strftime_l", &strftime_l},
{"strlcat", &strlcat},
{"strlcpy", &strlcpy},
{"strlen", &strlen},
{"strlwr", &strlwr},
{"strncasecmp", &strncasecmp},
{"strncasecmp_l", &strncasecmp_l},
{"strncat", &strncat},
{"strncmp", &strncmp},
{"strncpy", &strncpy},
{"strndup", &why_strndup},
{"strnlen", &strnlen},
{"strnstr", &strnstr},
{"strpbrk", &strpbrk},
{"strptime", &strptime},
{"strptime_l", &strptime_l},
{"strrchr", &strrchr},
{"strsep", &strsep},
{"strspn", &strspn},
{"strstr", &strstr},
{"strtod", &strtod},
{"strtod_l", &strtod_l},
{"strtof", &strtof},
{"strtof_l", &strtof_l},
{"strtoimax", &strtoimax},
{"strtoimax_l", &strtoimax_l},
{"strtok", &why_strtok},
{"strtok_r", &strtok_r},
{"strtol", &strtol},
{"strtol_l", &strtol_l},
{"strtold", &strtold},
{"strtold_l", &strtold_l},
{"strtoll", &strtoll},
{"strtoll_l", &strtoll_l},
{"strtoul", &strtoul},
{"strtoul_l", &strtoul_l},
{"strtoull", &strtoull},
{"strtoull_l", &strtoull_l},
{"strtoumax", &strtoumax},
{"strtoumax_l", &strtoumax_l},
{"strupr", &strupr},
{"strverscmp", &strverscmp},
{"strxfrm", &strxfrm},
{"strxfrm_l", &strxfrm_l},
{"swab", &swab},
{"system", &why_system},
{"tan", &tan},
{"tanf", &tanf},
{"tanh", &tanh},
{"tanhf", &tanhf},
{"tanhl", &tanhl},
{"tanl", &tanl},
{"task_priority_lower", &task_priority_lower},
{"task_priority_restore", &task_priority_restore},
{"tcgetattr", &why_tcgetattr},
{"tcsetattr", &why_tcsetattr},
{"tdelete", &tdelete},
{"tdestroy", &tdestroy},
{"tfind", &tfind},
{"tgamma", &tgamma},
{"tgammaf", &tgammaf},
{"tgammal", &tgammal},
{"thread_create", &thread_create},
{"time", &time},
{"times", &times},
{"timingsafe_bcmp", &timingsafe_bcmp},
{"timingsafe_memcmp", &timingsafe_memcmp},
{"toascii", &toascii},
{"toascii_l", &toascii_l},
{"tolower", &tolower},
{"tolower_l", &tolower_l},
{"toupper", &toupper},
{"toupper_l", &toupper_l},
{"towlower", &towlower},
{"towlower_l", &towlower_l},
{"towupper", &towupper},
{"towupper_l", &towupper_l},
{"trunc", &trunc},
{"truncf", &truncf},
{"truncl", &truncl},
{"tsearch", &tsearch},
{"twalk", &twalk},
{"ungetc", &why_ungetc},
{"unlink", &why_unlink},
{"uselocale", &uselocale},
{"usleep", &usleep},
{"utoa", &utoa},
{"vaddr_to_paddr", &vaddr_to_paddr},
{"vasprintf", &why_vasprintf},
{"vfprintf", &why_vfprintf},
{"vfscanf", &why_vfscanf},
{"vprintf", &why_vprintf},
{"vscanf", &why_vscanf},
{"vsnprintf", &why_vsnprintf},
{"vsprintf", &why_vsprintf},
{"vsscanf", &why_vsscanf},
{"wait", &wait},
{"wcpcpy", &wcpcpy},
{"wcpncpy", &wcpncpy},
{"wcrtomb", &wcrtomb},
{"wcscasecmp", &wcscasecmp},
{"wcscasecmp_l", &wcscasecmp_l},
{"wcscat", &wcscat},
{"wcschr", &wcschr},
{"wcscmp", &wcscmp},
{"wcscoll", &wcscoll},
{"wcscoll_l", &wcscoll_l},
{"wcscpy", &wcscpy},
{"wcscspn", &wcscspn},
{"wcsdup", &why_wcsdup},
{"wcsftime", &wcsftime},
{"wcsftime_l", &wcsftime_l},
{"wcslcat", &wcslcat},
{"wcslcpy", &wcslcpy},
{"wcslen", &wcslen},
{"wcsncasecmp", &wcsncasecmp},
{"wcsncasecmp_l", &wcsncasecmp_l},
{"wcsncat", &wcsncat},
{"wcsncmp", &wcsncmp},
{"wcsncpy", &wcsncpy},
{"wcsnlen", &wcsnlen},
{"wcsnrtombs", &wcsnrtombs},
{"wcspbrk", &wcspbrk},
{"wcsrchr", &wcsrchr},
{"wcsrtombs", &wcsrtombs},
{"wcsspn", &wcsspn},
{"wcsstr", &wcsstr},
{"wcstod", &wcstod},
{"wcstod_l", &wcstod_l},
{"wcstof", &wcstof},
{"wcstof_l", &wcstof_l},
{"wcstoimax", &wcstoimax},
{"wcstoimax_l", &wcstoimax_l},
{"wcstok", &wcstok},
{"wcstol", &wcstol},
{"wcstol_l", &wcstol_l},
{"wcstold", &wcstold},
{"wcstold_l", &wcstold_l},
{"wcstoll", &wcstoll},
{"wcstoll_l", &wcstoll_l},
{"wcstombs", &wcstombs},
{"wcstoul", &wcstoul},
{"wcstoul_l", &wcstoul_l},
{"wcstoull", &wcstoull},
{"wcstoull_l", &wcstoull_l},
{"wcstoumax", &wcstoumax},
{"wcstoumax_l", &wcstoumax_l},
{"wcswidth", &wcswidth},
{"wcsxfrm", &wcsxfrm},
{"wcsxfrm_l", &wcsxfrm_l},
{"wctob", &wctob},
{"wctomb", &wctomb},
{"wctrans", &wctrans},
{"wctrans_l", &wctrans_l},
{"wctype", &wctype},
{"wctype_l", &wctype_l},
{"wcwidth", &wcwidth},
{"wifi_connect", &wifi_connect},
{"wifi_connect_to", &wifi_connect_to},
{"wifi_disconnect", &wifi_disconnect},
{"wifi_get_connection_station", &wifi_get_connection_station},
{"wifi_get_connection_status", &wifi_get_connection_status},
{"wifi_get_status", &wifi_get_status},
{"wifi_scan_free_station", &wifi_scan_free_station},
{"wifi_scan_get_num_results", &wifi_scan_get_num_results},
{"wifi_scan_get_result", &wifi_scan_get_result},
{"wifi_station_get_authmode", &wifi_station_get_authmode},
{"wifi_station_get_bssid", &wifi_station_get_bssid},
{"wifi_station_get_mode", &wifi_station_get_mode},
{"wifi_station_get_primary_channel", &wifi_station_get_primary_channel},
{"wifi_station_get_rssi", &wifi_station_get_rssi},
{"wifi_station_get_secondary_channel", &wifi_station_get_secondary_channel},
{"wifi_station_get_ssid", &wifi_station_get_ssid},
{"wifi_station_wps", &wifi_station_wps},
{"window_create", &window_create},
{"window_destroy", &window_destroy},
{"window_event_poll", &window_event_poll},
{"window_flags_get", &window_flags_get},
{"window_flags_set", &window_flags_set},
{"window_framebuffer_create", &window_framebuffer_create},
{"window_framebuffer_format_get", &window_framebuffer_format_get},
{"window_framebuffer_get", &window_framebuffer_get},
{"window_framebuffer_size_get", &window_framebuffer_size_get},
{"window_framebuffer_size_set", &window_framebuffer_size_set},
{"window_position_get", &window_position_get},
{"window_position_set", &window_position_set},
{"window_present", &window_present},
{"window_size_get", &window_size_get},
{"window_size_set", &window_size_set},
{"window_title_get", &window_title_get},
{"window_title_set", &window_title_set},
{"wmemchr", &wmemchr},
{"wmemcmp", &wmemcmp},
{"wmemcpy", &wmemcpy},
{"wmemmove", &wmemmove},
{"wmempcpy", &wmempcpy},
{"wmemset", &wmemset},
{"write", &why_write},
{"y0", &y0},
{"y0f", &y0f},
{"y1", &y1},
{"y1f", &y1f},
{"yn", &yn},
{"ynf", &ynf}
};

#define NUM_SYMBOLS 828

int symbol_compare(const void *a, const void *b) {
    const struct esp_elfsym *sym_a = (const struct esp_elfsym *)a;
    const struct esp_elfsym *sym_b = (const struct esp_elfsym *)b;
    return strcmp(sym_a->name, sym_b->name);
}

__attribute__((used))
uintptr_t elf_find_sym(const char *sym_name) {
    struct esp_elfsym key = { .name = sym_name };
    const struct esp_elfsym *res;

    res = (const struct esp_elfsym *)bsearch(
        &key,
        why2025_elfsyms,
        NUM_SYMBOLS,
        sizeof(struct esp_elfsym),
        symbol_compare
    );

    if (res) {
        return (uintptr_t)res->sym;
    }

    return (uintptr_t)NULL;
}
