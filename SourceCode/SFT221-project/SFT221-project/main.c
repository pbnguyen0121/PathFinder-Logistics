#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "delivery.h"

int main(void)
{
	struct Map baseMap = populateMap();
	struct Route blueRoute = getBlueRoute();

	struct Route yelloRoute = getYellowRoute();

	struct Route greenRoute = getGreenRoute();

	struct Map routeMap = addRoute(&baseMap, &blueRoute);

	routeMap = addRoute(&baseMap, &yelloRoute);

	routeMap = addRoute(&baseMap, &greenRoute);

	printMap(&routeMap, 1, 1);
	//testingsgwghw


	/*isValidDestinationFormat("9M");*/
	runSenecaDeliveries();

	return 0;
}