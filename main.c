#include <stddef.h>
#include <stdio.h>
#include <string.h>

// make re
// make compil
// LD_LIBRARY_PATH=/home/jiachen/B4-Epitech/asm LD_PRELOAD=/home/jiachen/B4-Epitech/asm/libasm.so ./test

extern char *strchr(const char *s, int c);
extern size_t strlen(const char *s);
extern void *memset(void *s, int c, size_t n);
extern void *memcpy(void *dest, const void *src, size_t n);
extern void *memmove(void *dest, const void *src, size_t n);
extern int strcasecmp(const char *s1, const char *s2);
extern char *strstr(const char *haystack, const char *needle);
extern char *strpbrk(const char *s, const char *accept);
extern size_t strcspn(const char *s, const char *reject);
extern void *memfrob(void *s, size_t n);
// extern int my_ffs(int i);

void testing_strcspn()
{
    printf("STRCSPN:\n");
    printf("No rejected chars in 'Hello': %i\n", strcspn("Hello", "xyz"));
    printf("first char is rejected in 'Hello': %i\n", strcspn("Hello", "el"));
    printf("rejected char in 'abcdef' (should be 3): %i\n", strcspn("abcdef", "de"));
    printf("Empty input string: %i\n", strcspn("", "xyz"));
    printf("Empty reject string: %i\n", strcspn("Hello", ""));
}

int main()
{
    // char *test = strdup("CHOCLOL");
    // char *src = strdup("XDDDDDD");
    
    // printf("%s\n", memcpy(test, src, 3));
    // printf("%s", strchr(str, '\0'));
    // printf("%s\n", strchr(str, 'e'));


    // char str[] = "Hello world!";
    // char *test = "HellO";
    // char *test1 = "hello";

    // printf("Before memmove: %s\n", str);
    // memmove(str, str + 3, 6);
    // printf("After memmove: %s\n", str);
    // printf("%d\n", strcasecmp(test, test1));

    // char *str = "Hello";
    // char *str1 = strchr(str, '\0');

    // if ((str + 5) == str1)
    //     write(1, "Je suis pas un neuille", 22);
    // const char *test_cases[][2] = {
    //     {"hello world", "world"},
    //     {"hello world", "hello"},
    //     {"hello world", "o w"},
    //     {"hello world", "orld"},
    //     {"hello world", "hello world"},
    //     {"hello world", ""},
    //     {"hello world", "xyz"},
    //     {"hello world", "hello!"},
    //     {"hello world", "world!"},
    //     {"", "world"},
    //     {"", ""},
    //     {"hello hello", "hello"},
    //     {"hello world", "lo wo"},
    //     {"hello world", "hello world!"}, 
    //     {"hello world", "HELLO"},
    //     {"hello world", "o"},
    //     {"hello world", " "},
    //     {"hello world", "hello world hello"},
    //     {"", "lkl"}
    // };
    // for (size_t i = 0; i < 19; i++) {
    //     printf("%s \n", strstr(test_cases[i][0], test_cases[i][1]));
    // }

    // char *test = "saperlipopette";

    // printf("%s\n", strpbrk(test, ""));

    // char *test = "check_all";

    // printf("%i\n", strcspn(test, "al"));

    // testing_strcspn();
    // char test[] = "hello world";

    // memfrob(test, 4);
    // printf("1 time = %s\n", test);
    // memfrob(test, 4);
    // printf("2 times = %s\n", test);

    // printf("ffs = %d\n", ffs(5));
    // printf("my_ffs = %d\n", my_ffs(5));
    return 0;
}
