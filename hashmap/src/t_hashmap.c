#include "../lib/t_hashmap.h"

HM* createHM()
{
    HM *map = NULL;
    map = malloc(sizeof(HM));
    if(map == NULL)
    {
        printf("ERROR:: createHM\n\n");
        printf("Memory allocation failed\n\n");
        return NULL;
    }
    map->size = 0;
    map->tree = NULL;
    return map;
}

void freeHM(HM *map)
{
	BST_treeFree(map->tree);
	free(map);
}

int sizeHM(HM *map)
{
	if(map == NULL) return -1;
	return map->size;
}

void displayHM(HM *map)
{
	printf("__________ HASH MAP __________\n");
	printf("size of map		%d\n\n", map->size);
	BST_treeDisplay(map->tree);
}

int addHM(HM *map, char *key, int value)
{
	if(map == NULL)
	{
		printf("error: map is missing\n");
		printf("in addHM\n\n");
		return 0;
	}
	if(key == NULL)
	{
		printf("error: key is missing\n");
		printf("in addHM\n\n");
		return 0;
	}
	if(strlen(key) < 1)
	{
		printf("error: key length is out of range\n");
		printf("minimum length for key: 1\n");
		printf("in addHM\n\n");
		return 0;
	}
	int p;
	BST *newTree = BST_pairAdd(map->tree, key, value, &p);
	if(p != 1 || newTree == NULL)
	{
		return 0;
	}
	map->size += 1;
	map->tree = newTree;
	return 1;
}

int modifyHM(HM *map, char *key, int value)
{
	if(map == NULL)
	{
		printf("error: map is missing\n");
		printf("in addHM\n\n");
		return 0;
	}
	if(key == NULL)
	{
		printf("error: key is missing\n");
		printf("in addHM\n\n");
		return 0;
	}
	if(strlen(key) < 1)
	{
		printf("error: key length is out of range\n");
		printf("minimum length for key: 1\n");
		printf("in addHM\n\n");
		return 0;
	}
	int p;
	BST *newTree = BST_pairUpdate(map->tree, key, value, &p);
	if(p != 1 || newTree == NULL)
	{
		return 0;
	}
	map->tree = newTree;
	return 1;
}

Q* getHM(HM *map, char *key)
{
	if(map == NULL)
	{
		printf("error: map is missing\n");
		printf("in getHM\n\n");
		return NULL;
	}
	if(key == NULL)
	{
		printf("error: key is missing\n");
		printf("in getHM\n\n");
		return NULL;
	}
	if(strlen(key) < 1)
	{
		printf("error: key length is out of range\n");
		printf("minimum length for key: 1\n");
		printf("in getHM\n\n");
		return NULL;
	}
	int hash = hashHM(key);
	if(hash < 0 || hash > 255)
	{
		printf("error: key length is out of range\n");
		printf("in getHM\n\n");
		return NULL;
	}
	BST *BSTnode = BST_getNode(map->tree, hash);
	if(BSTnode == NULL) return NULL;
	Q *Qnode = Q_nodeGet(BSTnode->data, key);
	return Qnode;
}

int removeHM(HM *map, char *key)
{
	if(map == NULL)
	{
		printf("error: map is missing\n");
		printf("in addHM\n\n");
		return 0;
	}
	if(key == NULL)
	{
		printf("error: key is missing\n");
		printf("in addHM\n\n");
		return 0;
	}
	if(strlen(key) < 1)
	{
		printf("error: key length is out of range\n");
		printf("minimum length for key: 1\n");
		printf("in addHM\n\n");
		return 0;
	}
	int p;
	BST *newTree = BST_pairRemove(map->tree, key, &p);
	if(p != 1 || newTree == NULL)
	{
		return 0;
	}
	map->size -= 1;
	map->tree = newTree;
	return 1;
}