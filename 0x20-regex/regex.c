#include "regex.h"

/**
 * rec_match - recursively checks for match
 * @str: string
 * @pattern: pattern
 * @s_str: index into str
 * @s_pat: index into pattern
 * Return: 1 on match. 0 on no match
 */
int rec_match(char const *str, char const *pattern, size_t s_str, size_t s_pat)
{
	if (pattern[s_pat] == '\0' && str[s_str] == '\0')
		return (1);
	if (pattern[s_pat] == '\0' && str[s_str] != '\0')
		return (0);
	if (pattern[s_pat + 1] != '*')
	{
		if (
			pattern[s_pat] == str[s_str] ||
			(pattern[s_pat] == '.' && str[s_str] != '\0')
		)
			return (rec_match(str, pattern, s_str + 1, s_pat + 1));
		else
			return (0);
	}
	else
	{
		if (
			pattern[s_pat] == str[s_str] ||
			(pattern[s_pat] == '.' && str[s_str] != '\0')
		)
		{
			if (rec_match(str, pattern, s_str + 1, s_pat))
				return (1);
			else
				return (rec_match(str, pattern, s_str, s_pat + 2));
		}
		else
			return (rec_match(str, pattern, s_str, s_pat + 2));
	}
}
/**
 * regex_match - Checks whether a given pattern matches a given string
 * @str: string to scan
 * @pattern: regular expression
 * Return: 1 on success 0 on failure
 */
int regex_match(char const *str, char const *pattern)
{
	return (rec_match(str, pattern, 0, 0));
}
