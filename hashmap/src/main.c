#include "../lib/t_hashmap.h"

void test()
{
	int count;
	char *string;
	string = malloc(100 * sizeof(char));

	HM *map = NULL;
	map = createHM();
	if(map == NULL)
	{
		printf("Failed to initialise HM\n");
		exit(1);
	}

	FILE *ptr = NULL;
	ptr = fopen("msc/data", "r");
	if(ptr == NULL)
	{
		printf("Failed to open data file\n");
		exit(1);
	}
	while(fscanf(ptr, "%s %d", string, &count) != EOF){
		addHM(map, string, count);
	}
	fclose(ptr);
	free(string);

	printf("\n__________ CREATE, ADD, DISPLAY, SIZE _______________________________________________________________\n");
	printf("_____________________________________________________________________________________________________\n\n");
	
	displayHM(map);

	printf("__________ MODIFY, REMOVE, SIZE _____________________________________________________________________\n");
	printf("_____________________________________________________________________________________________________\n\n");

	removeHM(map, "Eogeum");
	removeHM(map, "Romuald");
	removeHM(map, "Namgung");
	modifyHM(map, "Dae", 0);
	modifyHM(map, "Eo", 1);
	modifyHM(map, "Gyeong", 2);
	modifyHM(map, "Myeong", 3);
	modifyHM(map, "Ryeo", 4);
	modifyHM(map, "Seung", 5);
	modifyHM(map, "Efe", 99);
	displayHM(map);

	printf("__________ GET, FREE ________________________________________________________________________________\n");
	printf("_____________________________________________________________________________________________________\n\n");

	Q *node1 = getHM(map, "Efe");
	if(node1 == NULL)
	{
		printf("Key not found: %s\n\n", "Efe");
	}

	Q *node2 = getHM(map, "Ryu");
	if(node2 == NULL)
	{
		printf("Key not found: %s\n", "Ryu");
	}
	else{
		Q_nodeDisplay(node2);
	}


	freeHM(map);
}

int main()
{
	test();
	
	return 0;
}
