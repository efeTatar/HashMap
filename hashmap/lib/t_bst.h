/**
 * @file t_bst.h
 * @author Efe Tatar
 * @brief bst management library
 * @version 0.1
 * @date 2023-12-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "t_utilities.h"
#include "t_queue.h"

/**
 * @brief 
 * 
 */
typedef struct _bst{
    int hash;
    Q *data;
    struct _bst *left, *right;
}BST;

/**
 * @brief initialise node (BST)
 * 
 * @param hash	hash value
 * @return BST* 
 * 1. NULL if hash value out of range or malloc fails
 * 2. node (BST) if node initialised
 */
BST* 	BST_nodeInitialise	(int hash);

/**
 * @brief add pair to tree (bst)
 * 
 * @param tree	pointer on tree
 * @param key 	pointer on key
 * @param value value
 * @param h 	pointer on integer, is set to success state
 * @return BST* 
 * 1. tree if tree, key, h is NULL
 * 2. tree if pair addition fails
 * 3. updated tree if addition succeeds
 */
BST*	BST_pairAdd			(BST *tree, char *key, int value, int *h);

/**
 * @brief DO NOT CALL THIS FUNCTION, INTERNAL SUBFUNCTION OF BST_pairAdd
 * 
 * @param tree 	pointer on tree
 * @param key 	pointer on key
 * @param value value
 * @param hash 	hash value
 * @param h 	pointer on integer, is set to success state
 * @return BST* 
 * 1. NULL if insertion fails
 * 2. modified tree if insertion succeeds
 */
BST* 	BST_recursiveInsert	(BST *tree, char *key, int value, int hash , int *h);

/**
 * @brief remove pair from tree (BST)
 * 
 * @param tree 	pointer on tree
 * @param key 	pointer on key
 * @param h 	pointer on integer, is set to success state
 * @return BST* 
 * 1. tree if tree, key or h is NULL
 * 2. tree if hash value out of range
 * 3. modified tree if removal succeeds
 */
BST* 	BST_pairRemove		(BST *tree, char *key, int *h);

/**
 * @brief DO NOT CALL THIS FUNCTION, INTERNAL SUBFUNCTION OF BST_pairRemove
 * 
 * @param tree 	pointer on tree
 * @param key 	pointer on key
 * @param hash 	hash value
 * @param h 	pointer on integer, is set to success state
 * @return BST* 
 * 1. NULL if removal fails
 * 2. modified tree if removal succeeds 
 */
BST* 	BST_recursiveDelete	(BST *tree, char *key, int hash, int *h);

/**
 * @brief DO NOT CALL THIS FUNCTION, INTERNAL SUBFUNCTION OF BST_pairRemove, WILL CAUSE MEMORY LEAKS
 * removes node from BST
 * 
 * @param tree 	pointer on tree
 * @return BST* 
 * NULL if tree is NULL
 * modified tree if removal succeeds
 */
BST* 	BST_nodeRemove		(BST *tree);

/**
 * @brief DO NOT CALL THIS FUNCTION, INTERNAL SUBFUNCTION
 * 
 * @param tree 	pointer on tree
 * @param key 	pointer on key
 * @param value value
 * @param h 	pointer on integer, is set to success state
 * @return BST* 
 * 1. 
 */
BST* 	BST_pairUpdate		(BST *tree, char *key, int value, int *h);

/**
 * @brief DO NOT CALL THIS FUNCTION, INTERNAL SUBFUNCTION OF BST_pairUpdate
 * 
 * @param tree	pointer on tree
 * @param key 	pointer on key
 * @param value value
 * @param hash 	hash value
 * @param h 	pointer on integer, is set to success state
 * @return BST* 
 * 1. NULL if update fails
 * 2. modified tree if update succeeds
 */
BST* 	BST_nodeUpdate		(BST *tree, char *key, int value, int hash, int *h);

/**
 * @brief get node with matching hash value(BST)
 * 
 * @param tree	pointer on tree
 * @param hash	hash value
 * @return BST* 
 * 1. NULL if tree is NULL or if there is no match for hash value
 * 2. node (BST) if hash values match
 */
BST* 	BST_getNode			(BST *tree, int hash);

/**
 * @brief free all allocated memory related to tree (BST)
 * 
 * @param tree	pointer on tree (BST)
 */
void 	BST_treeFree		(BST *tree);

/**
 * @brief display tree (BST)
 * 
 * @param tree	pointer on tree (BST)
 */
void 	BST_treeDisplay		(BST *tree);

/**
 * @brief dispaly node (BST)
 * 
 * @param node	pointer on node (BST)
 */
void 	BST_nodeDisplay		(BST *node);