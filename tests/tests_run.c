/*
** EPITECH PROJECT, 2025
** minilibC
** File description:
** unit test
*/
#define ELEMENT_COUNT 10

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>

Test(strlen_test, check_len)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    int (*func_len)(const char *) = dlsym(handle, "strlen");

    cr_assert(strlen("minilibc") == func_len("minilibc"));
    cr_assert_eq(strlen("a"), func_len("a"));
    cr_assert_eq(strlen(""), func_len(""));
    dlclose(handle);
}

Test(strlen_test, check_len_void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    int (*func_len)(const char *) = dlsym(handle, "strlen");

    cr_assert(strlen("") == func_len(""));
    dlclose(handle);
}

Test(strchr_test, check_strchar)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*func_chr)(const char *, int) = dlsym(handle, "strchr");

    cr_assert_str_eq(strchr("minilibc", 98), func_chr("minilibc", 98));
    dlclose(handle);
}

Test(strchr_test, check_strchar_ok)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*func_chr)(const char *, int) = dlsym(handle, "strchr");

    cr_assert(strchr("asm", 8) == func_chr("asm", 8));
    dlclose(handle);
}

Test(strrchr_test, check_strrchar)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*func_chrr)(const char *, int) = dlsym(handle, "strrchr");

    cr_assert_str_eq(strrchr("asm", '\0'), func_chrr("asm", '\0'));
    cr_assert_str_eq(strrchr("asm", 'm'), func_chrr("asm", 'm'));
    dlclose(handle);
}

Test(memcpy_test, check_memcpy)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    void *(*func_chrr)(void *, const void *, size_t) = dlsym(handle, "memcpy");
    char test[] = "CHOCLOL";
    char src[] = "XDDDDDD";
    char test1[] = "CHOCLOL";
    char src1[] = "XDDDDDD";
    char test2[] = "";
    
    cr_assert_str_eq(memcpy(test, src, 3), func_chrr(test1, src1, 3));
    cr_assert_str_eq(memcpy(test, src, 0), func_chrr(test1, src1, 0));
    cr_assert_str_eq(memcpy(test2, test, 1), func_chrr(test2, test, 1));
    dlclose(handle);
}

Test(memmove_test, check_memmove)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    void *(*func_chrr)(void *, const void *, size_t) = dlsym(handle, "memmove");
    char str[] = "Hello, world!";
    char str1[] = "Hello, world!";
    char test[] = "Hola";
    char test1[] = "";

    cr_assert_str_eq(memmove(str + 3, str, 6), func_chrr(str1 + 3, str1, 6));
    cr_assert_str_eq(memmove(str + 3, str, 0), func_chrr(str1 + 3, str1, 0));
    cr_assert_str_eq(memmove(test + 3, test1, 0), func_chrr(test + 3, test1, 0));
    dlclose(handle);
}

Test(memset_test, check_memset)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    void *(*func_chrr)(void *, int, size_t) = dlsym(handle, "memset");
    char str[] = "Hello, world!";
    char str1[] = "Hello, world!";

    cr_assert_str_eq(memset(str, 'A', 6), func_chrr(str1, 'A', 6));
    cr_assert_str_eq(memset(str1, '\0', 4), func_chrr(str1, '\0', 4));
    dlclose(handle);
}

Test(memfrob_test, check_memfrob)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    void *(*func_chrr)(void *, size_t) = dlsym(handle, "memfrob");
    char test[] = "hello world";

    cr_assert_str_eq(func_chrr(test, 4), "BOFFo world");
    cr_assert_str_eq(func_chrr(test, 4), "hello world");
    dlclose(handle);
}

Test(strcasecmp_test, check_strcasecmp)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    int (*func_chrr)(const char *, const char *) = dlsym(handle, "strcasecmp");
    char *str = "hElLOo";
    char *str1 = "HeLloO";
    char *test = "kqjdskqlj";
    char *test1 = "";
    char *test2 = "";

    cr_assert_eq(strcasecmp(str, str1), func_chrr(str, str1));
    cr_assert_eq(strcasecmp(str, test), func_chrr(str, test));
    cr_assert_eq(strcasecmp(test1, test2), func_chrr(test1, test2));
    dlclose(handle);
}

Test(strcmp_test, check_strcmp)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    int (*func_chrr)(const char *, const char *) = dlsym(handle, "strcmp");
    char *str = "hElLOo";
    char *str1 = "HeLloO";
    char *test = "kqjdskqlj";
    char *test1 = "";
    char *test2 = "";

    cr_assert_eq(strcmp(str, str1), func_chrr(str, str1));
    cr_assert_eq(strcmp(str, test), func_chrr(str, test));
    cr_assert_eq(strcmp(test1, test2), func_chrr(test1, test2));
    dlclose(handle);
}

Test(strncmp_test, check_strncmp)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    int (*func_chrr)(const char *, const char *, size_t) = dlsym(handle, "strncmp");
    char *str = "hElLOo";
    char *str1 = "HeLloO";
    char *test = "kqjdskqlj";
    char *test1 = "";
    char *test2 = "";

    cr_assert_eq(strncmp(str, str1, 4), func_chrr(str, str1, 4));
    cr_assert_eq(strncmp(str, test, 0), func_chrr(str, test, 0));
    cr_assert_eq(strncmp(test1, test2, 0), func_chrr(test1, test2, 0));
    dlclose(handle);
}

Test(strcspn_test, check_strcspn)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    size_t (*func_chrr)(const char *, const char *) = dlsym(handle, "strcspn");
    char *str = "saperlipopette";
    char *str1 = "po";
    char *test = "";
    char *test1 = "";
    char *test2 = "";

    cr_assert_eq(strcspn(str, str1), func_chrr(str, str1));
    cr_assert_eq(strcspn(str, test), func_chrr(str, test));
    cr_assert_eq(strcspn(test1, test2), func_chrr(test1, test2));
    dlclose(handle);
}

Test(strpbrk_test, check_strpbrk)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*func_chrr)(const char *, const char *) = dlsym(handle, "strpbrk");
    char *str = "saperlipopette";
    char *str1 = "op";
    char *test = "";
    char *test1 = "";
    char *test2 = "";

    cr_assert_str_eq(strpbrk(str, str1), func_chrr(str, str1));
    cr_assert_eq(strpbrk(str, test), func_chrr(str, test));
    cr_assert_eq(strpbrk(test1, test2), func_chrr(test1, test2));
    dlclose(handle);
}

Test(strstr_test, check_strstr)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*func_chrr)(const char *, const char *) = dlsym(handle, "strstr");
    char *str = "saperlipopette";
    char *str1 = "op";
    char *test = "";
    char *test1 = "";
    char *test2 = "";

    cr_assert_str_eq(strstr(str, str1), func_chrr(str, str1));
    cr_assert_eq(strstr(str, test), func_chrr(str, test));
    cr_assert_eq(strstr(test1, test2), func_chrr(test1, test2));
    dlclose(handle);
}

Test(index_test, check_strchar)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*func_chr)(const char *, int) = dlsym(handle, "index");

    cr_assert_str_eq(index("minilibc", 98), func_chr("minilibc", 98));
    dlclose(handle);
}

Test(index_test, check_strchar_ok)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*func_chr)(const char *, int) = dlsym(handle, "index");

    cr_assert(index("asm", 8) == func_chr("asm", 8));
    dlclose(handle);
}

Test(rindex_test, check_strrchar)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*func_chrr)(const char *, int) = dlsym(handle, "rindex");

    cr_assert_str_eq(rindex("asm", '\0'), func_chrr("asm", '\0'));
    cr_assert_str_eq(rindex("asm", 'm'), func_chrr("asm", 'm'));
    dlclose(handle);
}

Test(ffs_test, check_strrchar)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    int (*func_chrr)(int) = dlsym(handle, "ffs");

    cr_assert_eq(ffs(100), func_chrr(100));
    cr_assert_eq(ffs(0), func_chrr(0));
    dlclose(handle);
}
