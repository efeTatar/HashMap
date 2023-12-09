#include "../lib/t_utilities.h"

int hashHM(char *key)
{
    if(key == NULL)
    {
        printf("ERROR:: hash\n");
        printf("Key is missing\n");
        return -1;
    }
    if(strlen(key) < 1)
    {
        printf("ERROR:: hash\n");
        printf("Key length is out of range: %ld\n", strlen(key));
		printf("Minimum length for key: 1\n");
        return -1;
    }
	// returns ascii value of key[0]
    return key[0];
}