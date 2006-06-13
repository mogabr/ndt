/*
 * This file contains functions needed to handle numbers sanity checks.
 *
 * Jakub S�awi�ski 2006-06-12
 * jeremian@poczta.fm
 */

#include "../config.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

#include "utils.h"

/*
 * Function name: check_int
 * Description: Checks if the string is a valid int number.
 * Arguments: text - the string representing number
 *            number - the pointer where decoded number will be stored
 * Returns: 0 - success,
 *          1 - value from outside the int number range,
 *          2 - not the valid int number.
 */

int
check_int(char* text, int* number)
{
  char* znak;
  long tmp;

  assert(text != NULL);
  assert(info != NULL);
  
  if (((tmp = strtol(text, &znak, 10)) >= INT_MAX) || (tmp <= INT_MIN)) {
    return 1;
  }
  if ((*text != '\0') && (*znak == '\0')) {
    *number = tmp;
    return 0;
  }
  else {
    return 2;
  }
}

/*
 * Function name: check_rint
 * Description: Checks if the string is a valid int number from the specified
 *              range.
 * Arguments: text - the string representing number
 *            number - the pointer where decoded number will be stored
 *            minVal - the minimal value restriction (inclusive)
 *            maxVal - the maximum value restriction (inclusive)
 * Returns: 0 - success,
 *          1 - value from outside the specified range,
 *          2 - not the valid int number.
 */

int
check_rint(char* text, int* number, int minVal, int maxVal)
{
  int ret;

  assert(maxVal >= minVal);
  
  if ((ret = check_int(text, number))) {
    return ret;
  }
  if ((*number < minVal) || (*number > maxVal)) {
    return 1;
  }
  return 0;
}

/*
 * Function name: check_long
 * Description: Checks if the string is a valid long number.
 * Arguments: text - the string representing number
 *            number - the pointer where decoded number will be stored
 * Returns: 0 - success,
 *          1 - value from outside the long number range,
 *          2 - not the valid long number.
 */

int
check_long(char* text, long* number)
{
  char* tmp;
  
  assert(text != NULL);
  assert(info != NULL);
  
  if (((*number = strtol(text, &tmp, 10)) == LONG_MAX) || (*number == LONG_MIN)) {
    return 1;
  }
  if ((*text != '\0') && (*tmp == '\0')) {
    return 0;
  }
  else {
    return 2;
  }
}

