/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework library API
 ****************************************************************************/

#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "ewf_lib.h"

#ifdef EWF_DEBUG

/** This can be configured to match the application requirements  */
#ifndef EWF_ESCAPE_STR_BUFFER_SIZE
#define EWF_ESCAPE_STR_BUFFER_SIZE (2048)
#endif

char const * ewfl_escape_str_to_str_buffer(const char * str, uint32_t len)
{
    static char buffer_ptr[EWF_ESCAPE_STR_BUFFER_SIZE];
    char * guard = buffer_ptr + sizeof(buffer_ptr) - 5; /* one character may be escaped to four by using \xhh */
    char * out = buffer_ptr;
    const char * in = str;
    for ( ; *in && (out < guard) && ((len == 0) ? (true) : ((uint32_t)(in - str) < len)); in++)
    {
    switch(*in)
    {
    case '\\':
        *out++ = '\\';
        *out++ = '\\';
        break;
    case '\n':
        *out++ = '\\';
        *out++ = 'n';
        break;
    case '\r':
        *out++ = '\\';
        *out++ = 'r';
        break;
    case '\t':
        *out++ = '\\';
        *out++ = 't';
        break;
    case '\v':
        *out++ = '\\';
        *out++ = 'v';
        break;
    case '\f':
        *out++ = '\\';
        *out++ = 'f';
        break;
    case '\a':
        *out++ = '\\';
        *out++ = 'a';
        break;
    case '\b':
        *out++ = '\\';
        *out++ = 'b';
        break;
    default:
        if (*in < 32) {
        *out++ = '\\';
        *out++ = 'x';
        *out++ = '0' + ((*in & 0xF0) >> 4);
        *out++ = '0' + (*in & 0xF);
        } else  {
        *out++ = *in;
        }
        break;
    }
    }
    *out = 0;
    return buffer_ptr;
}

#endif

char * ewfl_unsigned_to_str(uint32_t u, char * str, uint32_t len)
{
    if (!str) return NULL;
    if (len < 1) return NULL;
    char * rev = str + len - 1;
    *rev = 0;
    do {
        div_t r = div(u, 10);
        u = r.quot;
        *--rev = (char)('0' + r.rem);
        if (rev < str) return NULL;
    } while (u);
    return rev;
}

uint32_t ewfl_str_to_unsigned(const char * str)
{
    if (!str) return 0;
    uint32_t u = 0;
    for (const char * p = str; *p && isdigit((int)*p); p++)
        u = (u * 10) + (*p - '0');
    return u;
}

uint32_t ewfl_str_length(const char * str)
{
    uint32_t len = 0;
    if (!str) return 0;
    while (*str++) len++;
    return len;
}

bool ewfl_str_starts_with(const char * str, const char * prefix_str)
{
    if (!str || !prefix_str) return false;
    while (*prefix_str) if (*prefix_str++ != *str++) return false;
    return true;
}

bool ewfl_str_ends_with(const char* str, const char* suffix_str)
{
    if (!str || !suffix_str) return false;
    const char *iter_str = str;
    while (*iter_str) iter_str++;
    const char *iter_terminator_str = suffix_str;
    while (*iter_terminator_str) iter_terminator_str++;
    while ((str-1 < iter_str) && (suffix_str-1 < iter_terminator_str)) if (*iter_str-- != *iter_terminator_str--) return false;
    if (iter_str == str && iter_terminator_str != suffix_str) return false;
    return true;
}

bool ewfl_buffer_starts_with(const uint8_t* buffer_ptr, uint32_t buffer_length, const uint8_t* prefix_ptr, uint32_t prefix_length)
{
    if (!buffer_ptr) return false;
    if (!buffer_length) return false;
    if (!prefix_ptr) return false;
    if (!prefix_length) return false;
    if (prefix_length > buffer_length) return false;
    const uint8_t* buffer_iter = buffer_ptr;
    const uint8_t* prefix_iter = prefix_ptr;
    for (; (buffer_iter < (buffer_ptr + buffer_length)) && (prefix_iter < (prefix_ptr + prefix_length)); buffer_iter--, prefix_iter--)
        if (*buffer_iter != *prefix_iter) 
            return false;
    return true;
}

bool ewfl_buffer_ends_with(const uint8_t* buffer_ptr, uint32_t buffer_length, const uint8_t* suffix_ptr, uint32_t suffix_length)
{
    if (!buffer_ptr) return false;
    if (!buffer_length) return false;
    if (!suffix_ptr) return false;
    if (!suffix_length) return false;
    if (suffix_length > buffer_length) return false;
    const uint8_t* buffer_tail = &(buffer_ptr[buffer_length-1]);
    const uint8_t* suffix_tail = &(suffix_ptr[suffix_length-1]);
    for (; (buffer_tail != buffer_ptr) && (suffix_tail != suffix_ptr); buffer_tail--, suffix_tail--)
    {
        if (*buffer_tail != *suffix_tail) return false;
    }
    return true;
}

bool ewfl_buffer_ends_with_wildcard_string(const uint8_t* buffer_ptr, uint32_t buffer_length, const uint8_t* suffix_ptr, uint32_t suffix_length)
{
    if (!buffer_ptr) return false;
    if (!buffer_length) return false;
    if (!suffix_ptr) return false;
    if (!suffix_length) return false;
    if (suffix_length > buffer_length) return false;
    const uint8_t* buffer_tail = &(buffer_ptr[buffer_length - 1]);
    const uint8_t* suffix_tail = &(suffix_ptr[suffix_length - 1]);
    for (; (buffer_tail != buffer_ptr) && (suffix_tail != suffix_ptr); buffer_tail--, suffix_tail--)
    {
        if (*suffix_tail == '?')
        {
            // A question mark matches any character
            continue;
        }

        if (*buffer_tail != *suffix_tail) return false;
    }
    return true;
}

bool ewfl_str_equals_str(const char * str1, const char * str2)
{
    if (ewfl_str_length(str1)!= ewfl_str_length(str2)) return false;
    if (!str1 || !str2) return false;
    for (; *str1 == *str2; str1++, str2++) if (!*str1 && !*str2) return true;
    return false;
}

bool ewfl_buffer_equals_buffer(const char* buffer1, const char* buffer2, uint32_t length)
{
    if (!buffer1 && !buffer2) return true;
    if (!buffer1 || !buffer2) return false;
    for (uint32_t i = 0; i < length; i++)
        if (buffer1[i] != buffer2[i])
            return false;
    return true;
}

bool ewfl_str_contains_str(const char * str, const char * substr)
{
    while(*str)
    {
        const char *start = str;
        /* Check if starting characters match, if true check for complete match of substring */
        while((*str == *substr) && (*str && *substr) )
        {
            str++;
            substr++;
        }
        /* If substring is present, return true */
        if(!*substr)
        {
            return true;
        }
        /* Increatemt the string */
        str = start+1;
    }
    return false;
}

char * ewfl_str_n_cpy(char* dest, const char* src_str, uint32_t n)
{
    *((char*)memcpy(dest, src_str, n) + n)  = '\0';
    return dest;
}

char * ewfl_str_remove_white_spaces(char* str)
{
    while ((*str != '\0') && (isspace((int)*str)) != 0)
    {
        str++;
    }

    char* str_end = str + ewfl_str_length(str) - 1;
    while (isspace((int)*str_end))
    {
        --str_end;
    };
    *(str_end + 1) = '\0';

    return str;
}

char * ewfl_str_remove_suffix_str(char* str, const char* suffix_str)
{
    char* str_end = str + ewfl_str_length(str);
    const char* suffix_str_end = suffix_str + ewfl_str_length(suffix_str);

    while (*str_end == *suffix_str_end)
    {
        str_end--;
        suffix_str_end--;
    };
    *(str_end + 1) = '\0';

    return str;
}

char * ewfl_adapter_response_str_extract(char * str)
{
    char* response_str = ewfl_str_remove_suffix_str(str, "OK\r\n");

    response_str = ewfl_str_remove_white_spaces(response_str);

    return response_str;
}

char * ewfl_find_chars_with_terms(char* str, char* chars_str, char* terms_str)
{
    if (!str) return NULL;
    if (!chars_str) return NULL;
    if (!chars_str[0]) return NULL; /* at least one valid character is necessary */
    
    char* p = str;
    for (; *p; p++)
    {
        for (char* char_ptr = chars_str; *char_ptr; char_ptr++)
        {
            if (*p == *char_ptr)
            {
                return p;
            }
        }

        if (terms_str)
        {
            for (char* term_ptr = terms_str; *term_ptr; term_ptr++)
            {
                if (*p == *term_ptr)
                {
                    return NULL;
                }
            }
        }
    }

    return NULL;
}
