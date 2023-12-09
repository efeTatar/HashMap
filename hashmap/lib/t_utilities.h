/**
 * @file t_utilities.h
 * @author Efe Tatar
 * @brief utilities library for queue, bst and hash map libraries
 * @version 0.1
 * @date 2023-12-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * @brief compute hash value 
 * 
 * @param key	pointer on key
 * @return integer between 0 and 255
 */
int hashHM(char *key);
