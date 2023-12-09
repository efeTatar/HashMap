#include "../lib/t_queue.h"

void Q_queueFree(Q *queue)
{
	// recursively frees all allocated memory related to the given queue
	if(queue == NULL) return;
	Q_queueFree(queue->next);
	free(queue->key);
	free(queue);
}

void Q_queueDisplay(Q *node)
{
	while(node!=NULL)
	{
		Q_nodeDisplay(node);
		node = node->next;
	}
}

void Q_nodeDisplay(Q *node)
{
	if(node == NULL)
	{
		printf("node (Q) is NULL\n\n");
		return;
	}
	printf("1.key		%s\n", node->key);
	printf("2.value 	%d\n\n", node->value);
}

Q* Q_nodeGet(Q *queue, char *key)
{
	if(key==NULL)
	{
		printf("error: key is missing\n");
		printf("in Q_nodeGet\n\n");
		return queue;
	}
	Q *p = NULL;
	p = queue;
	// iterates until matching key is found
	while(p != NULL)
	{
		if(strcmp(p->key, key) == 0) return p;
		p = p->next;
	}
	// returns NULL if matching key not found
	return NULL;
}

Q* Q_nodeUpdate(Q *queue, char *key, int value, int *h)
{
	if(h==NULL)
	{
		printf("error: feedback pointer is missing\n");
		printf("in Q_nodeUpdate\n\n");
		return queue;
	}
	if(queue==NULL)
	{
		*h = 0;
		return NULL;
	}
	if(key==NULL)
	{
		printf("error: key is missing\n");
		printf("in Q_nodeUpdate\n\n");
		*h = 0;
		return queue;
	}
	// iterates until a matching key is found
	// updates value and returns queue
	Q *p = queue;
	while(p!=NULL)
	{
		if(strcmp(key, p->key) == 0)
		{
			p->value = value;
			*h = 1;
			return queue;
		}
		p = p->next;
	}
	// returns queue if no matching key is found
	*h = 0;
	return queue;
}

Q* Q_nodeEnqueue(Q *queue, Q *node, int *h)
{
	if(h==NULL)
	{
		printf("error: feedback pointer is missing\n");
		printf("in Q_nodeEnqueue\n\n");
		return queue;
	}
	if(node==NULL)
	{
		*h = 0;
		printf("error: node is missing\n");
		printf("in Q_nodeEnqueue\n\n");
		return NULL;
	}
	if(queue==NULL)
	{
		queue = node;
		*h = 1;
		return queue;
	}
	Q *p = queue;
	// iterates until end of queue is reached
	// compares each key to new one
	// does not proceed in case of a match
	while(p->next != NULL)
	{
		if(strcmp(node->key, p->key)==0)
		{
			*h = 0;
			free(node->key);
			free(node);
			return queue;
		}
		p = p->next;
	}
	// previous iteration stops at last node
	// compares last key with given one
	if(strcmp(node->key, p->key)==0)
	{
		*h = 0;
		free(node->key);
		free(node);
		return queue;
	}
	// enqueues new node if keys do not match
	p->next = node;
	*h = 1;
	return queue;
}

Q* Q_nodeDequeue(Q *queue, char *key, int *h)
{
	if(h==NULL)
	{
		printf("error: feedback pointer is missing\n");
		printf("in Q_nodeEnqueue\n\n");
		return NULL;
	}
	if(queue==NULL)
	{
		*h = 0;
		return NULL;
	}
	if(key==NULL)
	{
		printf("error: key is missing\n");
		printf("in Q_nodeDequeue\n\n");
		*h = 0;
		return queue;
	}
	// ultimate iteration does not work in case of queue with first node
	// penultimate iteration removes first node from queue if keys match
	if(strcmp(queue->key, key) == 0)
	{
		Q *temp = queue;
		queue = queue->next;
		free(temp->key);
		free(temp);
		*h = 1;
		return queue;
	}
	// iterates seeking matching keys
	// removes node in case of mtach
	Q *p = queue;
	while(p->next!=NULL)
	{
		if(strcmp(key, p->next->key)==0)
		{
			Q *temp = p->next;
			p->next = temp->next;
			free(temp->key);
			free(temp);
			*h = 1;
			return queue;
		}
		p = p->next;
	}
	*h = 0;
	return queue;
}

Q* Q_nodeInitialise(char *key, int value)
{
	if(key==NULL)
	{
		printf("error: key is missing\n");
		printf("in Q_nodeInitialise\n\n");
		return NULL;
	}
	if(strlen(key) < 1)
	{
		printf("error: key length is out of range\n");
		printf("in Q_nodeInitialise\n\n");
		return NULL;
	}
	Q *node = NULL;
	node = malloc(sizeof(Q));
	if(node==NULL)
	{
		printf("error: memory allocation failed\n");
		printf("in Q_nodeInitialise\n\n");
		return NULL;
	}
	node->key = malloc(strlen(key)+1);
	if(node->key == NULL)
	{
		printf("error: memory allocation failed\n");
		printf("in Q_nodeInitialise\n\n");
		free(node);
		return NULL;
	}
	strcpy(node->key, key);
	node->value = value;
	node->next = NULL;
	return node;
}