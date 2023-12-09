/**
 * @file t_hashmap.h
 * @author Efe Tatar
 * @brief hash map management library
 * @version 0.1
 * @date 2023-12-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "t_utilities.h"
#include "t_bst.h"

/**
 * @brief 
 * 
 */
typedef struct _hm{
    BST *tree;
    int size;
}HM;

/**
 * @brief allocate memory for HM
 * 
 * @return HM* 
 * 1. NULL if memory allocation fails
 * 2. pointer on var of type HM
 */
HM* createHM(void);

/**
 * @brief add pair to tree (BST) in map (HM)
 * 
 * @param map 	pointer on map
 * @param key 	pointer on key
 * @param value pair value
 * @return int 
 * 1. 0 if addition fails
 * 2. 1 if addition succeeds
 */
int addHM(HM *map, char *key, int value);

/**
 * @brief modify pair in tree (BST) in map (HM)
 * 
 * @param map 	pointer on map
 * @param key 	pointer on key
 * @param value pair value
 * @return int 
 * 1. 0 if update fails
 * 2. 1 if update succeeds
 */
int modifyHM(HM *map, char *key, int value);

/**
 * @brief remove pair from tree (BST) in map (HM)
 * 
 * @param map 	pointer on map
 * @param key 	pointer on key
 * @return int 
 * 1. 0 if removal fails
 * 2. 1 if removal succeeds
 */
int removeHM(HM *map, char *key);

/**
 * @brief fetch size of Hash Map (HM)
 * 
 * @param map 	pointer on map
 * @return int 
 * 1. -1 if map is NULL
 * 2. size of HM
 */
int sizeHM(HM *map);

/**
 * @brief fetch pair (Q) from map (HM)
 * 
 * @param map 	pointer on map
 * @param key 	pointer on key
 * @return Q* 
 * 1. NULL if pair not found
 * 2. pair (Q)
 */
Q* getHM(HM *map, char *key);

/**
 * @brief display map (HM) tree (BST)
 * 
 * @param map 	pointer on map
 */
void displayHM(HM *map);

/**
 * @brief free all allocated memory related to map (HM)
 * 
 * @param map 	pointer on map
 */
void freeHM(HM *map);