#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

#include "../include/errors.h"

int my_puts ( const char * string );

const char* my_strchr ( const char* str, int ch );

size_t my_strlen ( const char* str );

char* my_strcpy  ( char* dest, const char* src );
char* my_strncpy ( char* s1, char* s2, size_t n );

char* my_strcat  ( char* dest, const char* src );
char* my_strncat (char* dest, const char* src, int n);

int my_atoi ( const char* str );

char* my_fgets ( char* str, int numChars, FILE* stream );

char* my_strdup ( const char* src );

ssize_t my_getline( char** lineptr, size_t* n, FILE* stream );

// TODO assert

int main() {
    // char str[] = "abcdef";
    // const char * dest = "ABCDEF";
    // const char ch = 'd';

    // my_puts( str );

    // printf( "%ld\n", my_strchr(str, ch) );

    // printf( "%ld\n", strchr(str, ch) );

    // printf( "%ld\n", my_strlen(str));

    // printf( "%s\n", my_strcpy(str, dest) );

    // char s1[] = "abcdef";
    // char s2[] = "xyzwf";

    // printf("%s\n", my_strncpy(s1, s2, 4));

    // char s1[10] = "abcd";
    // char s2[] = "xyz";

    // printf("%s\n", my_strncat(s1, s2, 2));
    // printf("%s\n", s1);

    // printf("%d\n", atoi("2147483648"));
    // printf("%d\n", my_atoi(" -123junk"));

    // char str[80];
    // FILE* ptr;

    // ptr = fopen("txt_for_tests.txt", "r");

    // if(my_fgets(str, 80, ptr) != NULL)
    // {
    //     puts(str);
    // }
    // fclose(ptr);

    // return 0;

    const char * str1 = "ABCDEF";
    char * str2 = my_strdup(str1);
    char * str3 = strdup(str1);

    printf("%s\n", str2);
    printf("%s\n", str3);

    return 0;

    // FILE* file = fopen("txt_for_tests.txt", "r");

    // if ( file == nullptr ) {
    //     printf("NullPTR\n");
    //     return 1;
    // }

    // char * str = NULL;
    // size_t size = 10;

    // my_getline(&str, &size, file);

    // printf("%s\n", str);
    // printf("%d\n", str[128]);

    // return 0;
}

int my_puts ( const char * string ) {
    assert ( string != nullptr );

    while ( *string != '\0' ) {
        putchar ( *string++ );
    }
    printf ( "\n" );
    return 0;
}

const char* my_strchr ( const char* str, int ch ) {
    assert ( str != nullptr  );
    assert ( isfinite ( ch ) );

    while ( *str != ch && *str != '\0' ) {
        str++;
    }

    if ( *str == ch ) {
        return str;
    }
    else {
        return NULL;
    }
}

size_t my_strlen ( const char* str ) {
    assert ( str != nullptr );

    size_t cnt = 0;

    while ( *str != '\0' ) {
        cnt++;
        str++;
    }

    return cnt;
}

char* my_strcpy( char* dest, const char* src ) {
    assert ( dest != NULL );
    assert ( src  != NULL );

    // fprintf(stderr, "%s\n", src);

    char * const old_dest = dest;

    while ( *src != '\0' ) {
        *dest++ = *src++;
    }

    *dest = '\0';

    return old_dest;
}

char* my_strncpy ( char* s1, char* s2, size_t n ) {
    assert ( s1 != nullptr  );
    assert ( s2 != nullptr  );
    assert ( isfinite ( n ) );

    char * const old_s1 = s1;

    while ( n != 0 && *s2 != '\0' ) {
        *s1 = *s2;

        n--;
        s1++;
        s2++;
    }

    while ( n != 0) {
        *s1 = '\0';

        s1++;
        n--;
    }

    return old_s1;
}

char* my_strcat ( char* dest, const char* src ) {
    assert ( dest != nullptr );
    assert ( src  != nullptr );

    char * const old_dest = dest;

    while ( *dest != '\0' ) {
        dest++;
    }

    while ( *src != '\0' ) {
        *dest = *src;

        dest++;
        src++;
    }

    return old_dest;
}

char* my_strncat ( char* dest, const char* src, int n ) {
    assert ( dest != nullptr );
    assert ( src  != nullptr );
    assert ( isfinite ( n )  );

    char * const old_dest = dest;

    while ( *dest != '\0' ) {
        dest++;
    }

    while ( *src != '\0' && n != 0 ) {
        *dest = *src;

        dest++;
        src++;
        n--;
    }

    return old_dest;
}

int my_atoi ( const char* str ) {
    assert ( str != nullptr );

    while ( *str == ' ' ) {
        str++;
    }

    int sign = 1;
    if ( *str == '-' ) {
        sign = -1;
        str++;
    }

    int number = 0;
    while ( isdigit ( *str ) ) {
        number *= 10;
        number += *str - 48;

        str++;
    }

    return (int)(sign * number);
}

char* my_fgets ( char* str, int numChars, FILE* stream ) {
    assert ( str    != nullptr     );
    assert ( stream != nullptr     );
    assert ( isfinite ( numChars ) );

    char * const old_str = str;

    if ( str == nullptr || numChars <= 0 || stream == nullptr ) {
        return NULL;
    }

    char ch = '\0';

    while ( (ch = fgetc( stream )) != '\n', EOF && numChars > 0 ) {
        *str = ch;
        str++;
        numChars--;
    }

    if ( ch == EOF && numChars != 0 ) {
        return NULL;
    }

    return old_str;
}

char* my_strdup ( const char* src ) {
    assert ( src != nullptr );

    char* str_for_copy = ( char * ) calloc ( strlen( src ) + 1, sizeof ( char ) );

    if ( str_for_copy == NULL ) {
        return NULL;
    }
    else {
        // str_for_copy = my_strcpy(str_for_copy, src);
        // return str_for_copy;
        return my_strcpy(str_for_copy, src);
    }
}

ssize_t my_getline( char** lineptr, size_t* size, FILE* stream ) {
    assert ( lineptr != nullptr );
    assert ( size    != nullptr );
    assert ( stream  != nullptr );

    printf ( "start my_getline\n" );
    *lineptr = ( char * ) calloc ( *size + 2, 8 );
    printf ( "done calloc\n" );

    int cnt_ch = 0;
    char ch;

    printf ( "start while\n" );
    while ( (ch = fgetc ( stream )) != '\n' && ch != EOF ) {
        ( *lineptr ) [ cnt_ch ] = ch;
        cnt_ch++;
        printf ( "%d char - %c\n", cnt_ch, ch );

        printf ( "check for size\n" );
        if ( cnt_ch + 1 == *size ) {
            printf ( "criticial size\n" );
            *size = *size * 2;
            *lineptr = ( char * ) realloc ( *lineptr, *size + 2 );
        }
    }

    if ( ch == EOF ) {
        return -1;
    }

    return cnt_ch + 1;
}
