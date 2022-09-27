/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief Library of utility macros and low footprint functions.
 ****************************************************************************/

#ifndef __ewf_lib__h__included__
#define __ewf_lib__h__included__

#include "ewf.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_lib The EWF Library
 * @brief The EWF library
 * @{
 ****************************************************************************/

/************************************************************************//**
 * @defgroup group_lib_string The EWF string utilities
 * @brief The EWF string utilities
 * @details
 * Low footprint string functions to avoid bringing in libraries.
 * Some of these functions are similar to C library functions but are
 * available here to avoid including C standard libraries, this enables
 * some toolchains to further optimize footprint.
 * @{
 ****************************************************************************/

#ifdef EWF_DEBUG // only in debug configurations!!!

/**
 * @brief Escapes non-printable and control characters in a string.
 * @details
 * This function is useful for printing or logging buffers sent and received
 * from an adapter, where non-printable and control characters would produce
 * confusing output. This function also escapes carriage return and line feed
 * characters, helping to keep output in a single line.
 * @param[in] str a pointer to a NULL terminated string that will be
 * escaped. This parameters is const, it will not be modified by the function.
 * @param[in] len the length to use from the string. If 0, then the string
 * will be converted until its terminating NULL character
 * @return a pointer to a static buffer with an C like escaped version of the
  * passed string.
 */
const char * ewfl_escape_str_to_str_buffer(const char * str, uint32_t len);

#endif

/**
 * @brief Converts an uint32_t to a string.
 * @param[in] u and uint32_t to be converted into a string.
 * @param[in,out] str a pointer to a buffer
 * @return a pointer to a static buffer with the string representation of the
 * passed uint32_t.
 */
char * ewfl_unsigned_to_str(uint32_t u, char * str, uint32_t len);

/**
 * @brief Parse an uint32_t from a string.
 * 
 * This function will attempt to parse an uint32_t out of the passed string.
 * If the string is NULL, 0 is returned.
 * The string will be parsed until the first non digit character.
 * 
 * @param[in] str a pointer to a NULL terminated string to be parsed
 * @return an uint32_t value parsed from the string
 */
uint32_t ewfl_str_to_unsigned(const char * str);

/**
 * @brief Returns the length of the passed NULL terminated string.
 * 
 * This function is equivalent to the C library strlen but it is available here for completness. 
 * Not including C standard libraries that define strlen will allow some toolchains to further optimize footprint.
 *
 * @param[in] a pointer to a NULL terminated string.
 * @return the uint32_t length of the passed string.
 */
uint32_t ewfl_str_length(const char * str);

/**
 * @brief Tests for a string start match
 *
 * Note that the order of parameters in this function is not interchangeable.
 * The first parameter is the string that will be matched and the second one
 * the prefix that will be looked for in that string. Typically, the prefix
 * will be shorted than the string that is being matched, if it is longer
 * there will be no match, the function will return false.
 *
 * @param[in] str a pointer to a NULL terminated string that will be matched.
 * @param[in] prefix_str the prefix that will be looked for at the begining of the string.
 * @return true if the string starts with the prefix, false otherwise.
 */
bool ewfl_str_starts_with(const char * str, const char * prefix_str);

/**
 * @brief Tests for a string end match
 *
 * Note that the order of parameters in this function is not interchangeable.
 * The first parameter is the string that will be matched and the second one
 * the suffix that will be looked for in that string. Typically, the terminator
 * will be shorted than the string that is being matched, if it is longer
 * there will be no match, the function will return false.
 *
 * @param[in] str a pointer to a NULL terminated string that will be matched.
 * @param[in] suffix_str the prefix that will be looked for at the end of the string.
 * @return true if the string ends with the terminator string, false otherwise.
 */
bool ewfl_str_ends_with(const char* str, const char* suffix_str);

/**
 * @brief Checks if a buffer starts with a string
 * @return true if the buffer starts with the prefix, false otherwise.
 */
bool ewfl_buffer_starts_with(const char* buffer, uint32_t buffer_length, const char* prefix_str, uint32_t prefix_length);

/**
 * @brief Checks if a buffer ends with a string
 * @return true if the buffer ends with the suffix, false otherwise.
 */
bool ewfl_buffer_ends_with(const char * buffer, uint32_t buffer_length, const char * suffix_str, uint32_t suffix_length);

/**
 * @brief Checks if a buffer ends with a string containing wildcards
 * The current version supports question marks '?'to match single characters.
 * @return true if the buffer ends with the suffix, false otherwise.
 */
bool ewfl_buffer_ends_with_wildcard_string(const char* buffer, uint32_t buffer_length, const char* suffix_str, uint32_t suffix_length);

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
bool ewfl_str_equals_str(const char * str1, const char * str2);

/**
 * @brief Checks if two buffers are equal.
 *
 * This function is similar to the C library function memcmp but it is
 * available here for completness. Not including C standard libraries that
 * define memcmp will allow some toolchains to further optimize footprint.
 * Note that the return of this function and memcmp are different, opposite.
 * memcmp will return zero if both strings are equal, this function will return
 * true if both strings are equal.
 *
 * @param[in] buffer1 a pointer to a buffer.
 * @param[in] buffer2 a pointer to a buffer.
 * @param[in] length the length to compare.
 * @return true if both strings are equal, false if they are different.
 */
bool ewfl_buffer_equals_buffer(const char* buffer1, const char* buffer2, uint32_t length);

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
bool ewfl_str_contains_str(const char * str, const char * substr);

/**
 * @brief Copies source string to destination buffer and terminates it by NULL
 *
 * @param[in] dest a pointer to the destination buffer where the source string will be copied
 * @param[in] src_str a pointer to a NULL terminated string that will be copied
 * @param[in] n number of bytes that will be copied
 * @return true if the substr is found in str, false otherwise.
 */
char * ewfl_str_n_cpy(char* dest, const char* src_str, uint32_t n);

/**
 * @brief Remove leading and trailing white space characters
 *
 * @param[in] str a pointer to the string that will be trimmed
 * @return pointer to the trimed string.
 */
char * ewfl_str_remove_white_spaces(char* str);

/**
 * @brief Remove suffix from string
 *
 * @param[in] str a pointer to the string from which suffix string will be removed
 * @param[in] suffix_str a pointer to substring to be removed
 * @return pointer to the trimmed string.
 */
char * ewfl_str_remove_suffix_str(char* str, const char * suffix_str);

/**
 * @brief Parse adapter response by trimming white space and "OK"
 *
 * @param[in] str a pointer to the string from which suffix string will be removed
 * @param[in] suffix_str a pointer to substring to be removed
 * @return pointer to the trimmed string.
 */
char* ewfl_adapter_response_str_extract(char* str);

/************************************************************************//**
 * @} *** group_lib_string
 ****************************************************************************/

/************************************************************************//**
 * @} *** group_lib
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_lib__h__included__ */
