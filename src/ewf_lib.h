/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief Library of utility macros and low footprint functions.
 ****************************************************************************/

/************************************************************************//**
 * @defgroup group_lib EWF Library
 * @{
 ****************************************************************************/

#ifndef __ewf_lib__h__included__
#define __ewf_lib__h__included__

#include "ewf.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 *
 * @defgroup group_lib_string String utilities
 * Low footprint string functions to avoid bringing in libraries.
 * Some of these functions are similar to C library functions but are
 * available here to avoid including C standard libraries, this enables
 * some toolchains to further optimize footprint.
 * @{
 *
 ****************************************************************************/


#ifdef EWF_DEBUG // only in debug configurations!!!

/** This can be configured to match the application requirements  */
#define EWF_ESCAPE_STR_BUFFER_SIZE (2048)

/**
 * @brief Escapes non-printable and control characters in a string.
 *
 * This function is useful for printing or logging buffers sent and received
 * from an adapter, where non-printable and control characters would produce
 * confusing output. This function also escapes carriage return and line feed
 * characters, helping to keep output in a single line.
 *
 * @param[in] str a pointer to a NULL terminated string that will be
 * escaped. This parameters is const, it will not be modified by the function.
 * @param[in] len the length to use from the string. If 0, then the string
 * will be converted until its terminating NULL character
 * @return a pointer to a static buffer with an C like escaped version of the
  * passed string.
 */
const char * _escape_str_to_str_buffer(const char * str, unsigned len);

#endif


/**
 * @brief Converts an unsigned to a string.
 * @param[in] u an unsigned to be converted into a string.
 * @return a pointer to a static buffer with the string representation of
 * the passed unsigned.
 */
const char * _unsigned_to_str_buffer(unsigned u);


/**
 * @brief Converts an unsigned to a string.
 * @param[in] u and unsigned to be converted into a string.
 * @param[in,out] str a pointer to a buffer
 * @return a pointer to a static buffer with the string representation of the
 * passed unsigned.
 */
char * _unsigned_to_str(unsigned u, char * str, unsigned len);


/**
 * @brief Parse an unsigned from a string.
 * This function will attempt to parse an unsigned out of the passed string.
 * If the string is NULL, 0 is returned.
 * The string will be parsed until the first non digit character.
 * @param[in] str a pointer to a NULL terminated string to be parsed
 * @return an unsigned value parsed from the string
 */
unsigned _str_to_unsigned(const char * str);


/**
 * @brief Returns the length of the passed NULL terminated string.
 *
 * This function is functionaly equivalent to the C library strlen but it is
 * available here for completness. Not including C standard libraries that
 * define strlen will allow some toolchains to further optimize footprint.
 *
 * @param[in] a pointer to a NULL terminated string.
 * @return the unsigned length of the passed string.
 */
unsigned _str_length(const char * str);


/**
 * @brief Converts an unsigned to a string
 *
 * Note that the order of parameters in this function is not interchangeable.
 * The first parameter is the string that will be matched and the second one
 * the prefix that will be looked for in that string. Typically, the prefix
 * will be shorted than the string that is being matched, if it is longer
 * there will be no match, the function will return false.
 *
 * @param[in] str a pointer to a NULL terminated string that will be matched.
 * @param[in] prefix the prefix that will be looked for at the begining of the string.
 * @return true if the string starts with the prefix, false otherwise.
 */
bool _str_starts_with(const char * str, const char * prefix);


/**
 * @brief Checks if a buffer ends with a string
 * @return true if the buffer ends with the suffix, false otherwise.
 */
bool _buffer_ends_with(const char * buffer, unsigned buffer_length, const char * suffix, unsigned suffix_length);


/**
 * @brief Checks if a buffer ends with a string containing wildcards
 * The current version supports question marks '?'to match single characters.
 * @return true if the buffer ends with the suffix, false otherwise.
 */
bool _buffer_ends_with_wildcard_string(const char* buffer, unsigned buffer_length, const char* suffix, unsigned suffix_length);


/**
 * @brief Checks if two strings are equal.
 *
 * This function is similar to the C library function strcmp but it is
 * available here for completness. Not including C standard libraries that
 * define strcmp will allow some toolchains to further optimize footprint.
 * Note that the return of this function and strcmp are different, opposite.
 * strcmp will return zero if both strings are equal, this function will return
 * true if both strings are equal.
 *
 * @param[in] str1 a pointer to a NULL terminated string.
 * @param[in] str2 a pointer to a NULL terminated string.
 * @return true if both strings are equal, false if they are different.
 */
bool _str_equals_str(const char * str1, const char * str2);


/**
 * @brief Searches for a string in a substring
 *
 * This function is similar to the C library function strstr but it is
 * available here for completness. Not including C standard libraries that
 * define strstr will allow some toolchains to further optimize footprint.
 *
 * @param[in] str a pointer to a NULL terminated string that will be searched
 * @param[in] substr a sub-string pattern that will be looked for in str.
 * @return true if the substr is found in str, false otherwise.
 */
bool _str_contains_str(const char * str, const char * substr);

/**
 * @brief Copies source string to destination buffer and terminates it by NULL
 *
 * @param[in] dest a pointer to the destination buffer where the source
 *                 string will be copied
 * @param[in] src_str a pointer to a NULL terminated string that will be copied
 * @param[in] n number of bytes that will be copied
 * @return true if the substr is found in str, false otherwise.
 */
char * _str_n_cpy(char* dest, const char* src_str, uint32_t n);

/**
 * @brief Remove leading and trailing white space characters
 *
 * @param[in] str a pointer to the string that will be trimmed
 * @return pointer to the trimed string.
 */
char * _str_remove_white_spaces(char* str);

/**
 * @brief Remove suffix from string
 *
 * @param[in] str a pointer to the string from which suffix string
 *                will be removed
 * @param[in] suffix_str a pointer to substring to be removed
 * @return pointer to the trimmed string.
 */
char * _str_remove_suffix_str(char* str, const char * suffix_str);

/**
 * @brief Parse adapter response by trimming white space and "OK"
 *
 * @param[in] str a pointer to the string from which suffix string
 *                will be removed
 * @param[in] suffix_str a pointer to substring to be removed
 * @return pointer to the trimmed string.
 */
char* adapter_response_str_extract(char* str);


/************************************************************************//**
 * @}
 ****************************************************************************/


#ifdef __cplusplus
}
#endif

#endif /* __ewf_lib__h__included__ */

/************************************************************************//**
 * @}
 ****************************************************************************/
