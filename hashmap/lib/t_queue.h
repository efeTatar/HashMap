/**
 * @file t_queue.h
 * @author Efe Tatar
 * @brief queue management library
 * @version 0.1
 * @date 2023-12-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "t_utilities.h"

/**
 * @brief queue structure
 * 1. key
 * 2. value
 * 
 */
typedef struct _queue{
    char *key;
    int value;
    struct _queue *next;
}Q;

/**
 * @brief initialise node (Q)
 * 
 * @param key		pointer on key
 * @param value 	value
 * @return Q*
 * 1. NULL if memory allocation fails
 * 2. pointer on node (Q)
 */
Q* 		Q_nodeInitialise	(char *key, int value);

/**
 * @brief enqueue pair (Q) to queue (Q)
 * 
 * @param queue		pointer on queue (Q)
 * @param node 		pointer on node (Q)
 * @param h 		pointer on integer to fetch state of success
 * @return Q* 
 * 1. NULL if queue is NULL
 * 2. queue (Q) if node or h is NULL or if insertion fails
 * 3. updated queue (Q) if insertion succeeds
 */
Q* 		Q_nodeEnqueue		(Q *queue, Q *node, int *h);

/**
 * @brief remove pair (Q) with matching key from given queue (Q)
 * 
 * @param queue		pointer on queue (Q)
 * @param key 		pointer on key
 * @param h 		pointer on integer to fetch state of success
 * @return Q* 
 * 1. NULL if queue is NULL
 * 2. queue (Q) if key or h is NULL or if removal fails
 * 3. updated queue (Q) if removal succeeds
 */
Q* 		Q_nodeDequeue		(Q *queue, char *key, int *h);

/**
 * @brief update value of pair (Q) with matching key in queue (Q)
 * 
 * @param queue 	pointer on queue (Q)
 * @param key 		pointer on key
 * @param value 	new value
 * @param h 		pointer on integer to fetch state of success
 * @return Q* 
 * 1. NULL if key or queue is NULL
 * 2. queue (Q) if h is NULL or if pair not found
 * 3. updated queue (Q) if pair is updated
 */
Q* 		Q_nodeUpdate		(Q *queue, char *key, int value, int *h);

/**
 * @brief fetch pair node (Q) with matching key in queue (Q)
 * 
 * @param queue 	pointer on queue (Q)
 * @param key 		pointer on key
 * @return Q* 
 * 1. NULL if key is NULL
 * 2. NULL if pair not found in given queue
 * 3. pair (Q) with matching key 
 */
Q* 		Q_nodeGet			(Q *queue, char *key);

/**
 * @brief display given queue (Q) 
 * 
 * @param node 		pointer on queue
 */
void 	Q_queueDisplay		(Q *node);

/**
 * @brief display given node (Q)
 * 
 * @param node 		pointer on node
 */
void 	Q_nodeDisplay		(Q *node);

/**
 * @brief free allocated memory related to given queue (Q)
 * 
 * @param queue 	pointer on queue
 */
void 	Q_queueFree			(Q *queue);