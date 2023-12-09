#include "../lib/t_bst.h"

BST* BST_nodeInitialise(int hash)
{
	BST *node = NULL;
	node = malloc(sizeof(BST));
	if(node == NULL)
	{
		printf("error: memory allocation failed\n");
		printf("in BST_nodeInitialise");
		return NULL;
	}
	node->hash = hash;
	node->data = NULL;
	node->left = NULL;
	node->right= NULL;
	return node;
}

BST* BST_pairAdd(BST *tree, char *key, int value, int *h)
{
	if(h == NULL){
		printf("error: pointer to success state is missing\n");
		printf("in BST_pairAdd\n");
		return tree;
	}
	if(key == NULL){
		printf("error: key is missing\n");
		printf("in BST_pairAdd\n");
		*h = 0;
		return tree;
	}
	if(strlen(key) < 1){
		printf("error: key lenght is out of range\n");
		printf("in BST_pairAdd\n");
		*h = 0;
		return tree;
	}
	int hash = hashHM(key);
	if(hash < 0 || hash > 255)
	{
		printf("error: hash value is out of range\n");
		printf("in BST_pairAdd\n");
		*h = 0;
		return tree;
	}
	// calls BST_recursiveInsert to add pair
	int p;
	BST *updatedTree = BST_recursiveInsert(tree, key, value, hash, &p);
	// checks for errors
	if(updatedTree == NULL)
	{
		printf("warning: tree might be corrupted\n");
		printf("in BST_pairAdd\n");
		*h = 0;
		return tree;
	}
	if(p == 0)
	{
		*h = 0;
		return tree;
	}
	// returns updated tree
	*h = 1;
	tree = updatedTree;
	return tree;
}

BST* BST_recursiveInsert(BST *tree, char *key, int value, int hash, int *h)
{
	// initialises Q node
	// initialises BST node
	//inserts Q node in BST node
	// inserts BST node in tree
	if(tree == NULL)
	{
		BST *BSTnode = BST_nodeInitialise(hash);
		if(BSTnode == NULL)
		{
			printf("error: failed to initialise BST node\n");
			printf("in BST_pairInsert\n");
			*h = 0;
			return NULL;
		}
		Q *Qnode = Q_nodeInitialise(key, value);
		if(Qnode == NULL)
		{
			printf("error: failed to initialise Q node\n");
			printf("in BST_pairInsert\n");
			free(BSTnode);
			*h = 0;
			return NULL;
		}
		int p;
		BSTnode->data = Q_nodeEnqueue(BSTnode->data, Qnode, &p);
		if(p == 0)
		{
			printf("warning: failed to insert Q node\n");
			printf("in BST_pairInsert\n");
			*h = 0;
			Q_queueFree(Qnode);
			return NULL;
		}
		*h = 1;
		return BSTnode;
	}
	// initialises Q node
	// inserts Q node in BST node
	if(hash == tree->hash)
	{
		Q *Qnode = Q_nodeInitialise(key, value);
		if(Qnode == NULL)
		{
			printf("error: failed to initialise Q node\n");
			printf("in BST_pairInsert\n");
			*h = 0;
			return NULL;
		}
		int p;
		tree->data = Q_nodeEnqueue(tree->data, Qnode, &p);
		if(p == 0)
		{
			*h = 0;
			return tree;
		}
		*h = 1;
		return tree;
	}
	if(hash < tree->hash)
	{
		tree->left = BST_recursiveInsert(tree->left, key, value, hash, h);
		return tree;
	}
	if(hash > tree->hash)
	{
		tree->right = BST_recursiveInsert(tree->right, key, value, hash, h);
		return tree;
	}
	*h = 0;
	return NULL;
}

BST* BST_pairRemove(BST *tree, char *key, int *h)
{
	if(h == NULL)
	{
		printf("error: pointer to success state is missing\n");
		printf("in BST_pairRemove\n");
		return tree;
	}
	if(tree == NULL)
	{
		*h = 0;
		return NULL;
	}
	if(key == NULL)
	{
		printf("error: key is missing\n");
		printf("in BST_pairRemove\n");
		*h = 0;
		return tree;
	}
	int hash = hashHM(key);
	if(hash < 0 || hash > 255)
	{
		printf("error: hash value is out of range\n");
		printf("in BST_pairRemove\n");
		*h = 0;
		return tree;
	}
	int p;
	// calls BST_recursiveDelete to delete pair
	BST *modifiedNode = BST_recursiveDelete(tree, key, hash, &p);
	if(modifiedNode == NULL){
		*h = 0;
		return tree;
	}
	if(p != 1)
	{
		*h = 0;
		return tree;
	}
	*h = 1;
	return modifiedNode;
}

BST* BST_recursiveDelete(BST *tree, char *key, int hash, int *h)
{
	if(tree == NULL)
	{
		*h = 0;
		return NULL;
	}
	// remvoes Q node from BST node
	// deletes BST node if its Q pointer is NULL
	if(hash == tree->hash)
	{
		int p;
		tree->data = Q_nodeDequeue(tree->data, key, &p);
		*h = p;
		if(tree->data == NULL)
		{
			tree = BST_nodeRemove(tree);
		}
		return tree;
	}
	if(hash < tree->hash)
	{
		tree->left = BST_recursiveDelete(tree->left, key, hash, h);
		return tree;
	}
	if(hash > tree->hash)
	{
		tree->right = BST_recursiveDelete(tree->right, key, hash, h);
		return tree;
	}
	*h = 0;
	return NULL;
}

BST* BST_nodeRemove(BST *tree)
{
	if(tree == NULL) return NULL;
	// replaces node with left child
	// frees the node
	if(tree->right == NULL)
	{
		BST *temp = tree;
		tree = temp->left;
		free(temp);
		return tree;
	}
	// places left child in right branch (min)
	// replaces node with right child
	BST *p = tree->right;
	while(p->left != NULL)
	{
		p = p->left;
	}
	p->left = tree->left;
	BST *temp = tree;
	tree = tree->right;
	free(temp);
	return tree;
}

BST* BST_pairUpdate(BST *tree, char *key, int value, int *h)
{
	if(h == NULL)
	{
		printf("error: pointer to success state is missing\n");
		printf("in BST_pairUpdate\n");
		return tree;
	}
	if(tree == NULL)
	{
		*h = 0;
		return tree;
	}
	if(key == NULL)
	{
		printf("error: key is missing\n");
		printf("in BST_pairUpdate\n");
		*h = 0;
		return tree;
	}
	int hash = hashHM(key);
	if(hash < 0 || hash > 255)
	{
		printf("error: hash value is out of range\n");
		printf("in BST_pairAdd\n");
		*h = 0;
		return tree;
	}
	int p;
	// calls BST_nodeUpdate to update pair
	BST *updatedNode = BST_nodeUpdate(tree, key, value, hash, &p);
	if(updatedNode == NULL)
	{
		printf("warning: unable to obtain updated node\n");
		printf("in BST_pairUpdate\n");
		*h = 0;
		return tree;
	}
	if(p != 1)
	{
		*h = 0;
		return tree;
	}
	*h = 1;
	return updatedNode;
}

BST* BST_nodeUpdate(BST *tree, char *key, int value, int hash, int *h)
{
	if(tree == NULL)
	{
		*h = 0;
		return NULL;
	}
	// updates pair
	if(hash == tree->hash)
	{
		int p;
		tree->data = Q_nodeUpdate(tree->data, key, value, &p);
		if(p == 0)
		{
			*h = 0;
			return tree;
		}
		*h = 1;
		return tree;
	}
	if(hash < tree->hash)
	{
		tree->left = BST_nodeUpdate(tree->left, key, value, hash, h);
		return tree;
	}
	if(hash > tree->hash)
	{
		tree->right = BST_nodeUpdate(tree->right, key, value, hash, h);
		return tree;
	}
	*h = 0;
	return NULL;
}

BST* BST_getNode(BST *tree, int hash)
{
	// searches for BST node recursively
	if(tree == NULL) return NULL;
	if(hash == tree->hash) return tree;
	if(hash < tree->hash) return BST_getNode(tree->left, hash);
	if(hash > tree->hash) return BST_getNode(tree->right, hash);
	return NULL;
}

void BST_treeFree(BST *tree)
{
	if(tree == NULL) return;
	BST_treeFree(tree->left);
	BST_treeFree(tree->right);
	Q_queueFree(tree->data);
	free(tree);
}

void BST_treeDisplay(BST *tree)
{
	if(tree == NULL) return;
	BST_treeDisplay(tree->left);
	printf("__________HASH %d__________\n\n", tree->hash);
	Q_queueDisplay(tree->data);
	BST_treeDisplay(tree->right);
}

void BST_nodeDisplay(BST *node)
{
	if(node == NULL) return;
	printf("	NODE HASH:	%d\n\n", node->hash);
	Q_queueDisplay(node->data);
}