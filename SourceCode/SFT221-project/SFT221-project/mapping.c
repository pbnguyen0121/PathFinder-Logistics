#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "math.h"
#include "delivery.h"

struct Map populateMap()
{
	struct Map result = {
		//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
		//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
		{
		{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
		{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
		{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//2
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//3
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//4
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//5
		{1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},	//6
		{1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//7
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//8
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//9
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//10
		{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//11
		{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//12
		{1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//13
		{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//14
		{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//15
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//16
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//17
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//18
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//19
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//20
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},	//21
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},	//22
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},	//23
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}		//24
		},
		MAP_ROWS, MAP_COLS
	};
	return result;
}

int getNumRows(const struct Map* map)
{
	return map->numRows;
}

int getNumCols(const struct Map* map)
{
	return map->numCols;
}

void printMap(const struct Map* map, const int base1, const int alphaCols)
{
	//              01234567890123456
	//              1248F
	char sym[] = { " XB?G?.?Y?-?*?+?P" };
	int r, c, rowMax;

	rowMax = map->numRows + base1;

	printf("%4s", " ");
	for (c = 0; c < map->numCols; c++)
	{
		if (alphaCols) printf("%c", 'A' + c);
		else printf("%d", c % 10);
	}
	printf("\n");
	printf("%4s", " ");
	for (c = 0; c < map->numCols; c++)
	{
		printf("-");
	}
	printf("\n");

	for (r = base1; r < rowMax; r++)
	{
		printf("%3d|", r);
		for (c = 0; c < map->numCols; c++)
		{
			printf("%c", sym[map->squares[r - base1][c]]);
		}
		printf("\n");
	}
}

struct Route getBlueRoute()
{
	struct Route result = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8},{4, 9},
			{5, 9},
			{6, 9},
			{7, 9},
			{8, 9},
			{9, 9},
			{10, 9},{10, 10},
			{11, 10},
			{12, 10},
			{13, 10},
			{14, 10},
			{15, 10},
			{16, 10},
			{17, 10},{17, 11},{17, 12},{17, 13},{17, 14},{17, 15},{17, 16},{17, 17},{17, 18},{17, 19},{17, 20},
				{17, 21},{17, 22},{17, 23},{17, 24},
		},
			42, BLUE
	};
	return result;
}

struct Route getGreenRoute()
{
	struct Route result = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8},{4, 9},{4, 10},{4, 11},
			{3, 11},
			{2, 11},
			{1, 11},
			{0, 11},{0, 12},{0, 13},{0, 14},{0, 15},{0, 16},{0, 17},{0, 18},{0, 19},
			{1, 19},
			{2, 19},
			{3, 19},
			{4, 19},
			{5, 19},
			{6, 19},
			{7, 19},
			{8, 19},
			{9, 19},{9, 20},{9, 21},{9, 22},{9, 23},{9, 24}

		},
			42, GREEN
	};
	return result;
}

struct Route getYellowRoute()
{
	struct Route result = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}, {4, 1}, {4, 2}, {4, 3},
			{5, 3},
			{6, 3},
			{7, 3},
			{8, 3},
			{9, 3},{9, 2},{9, 1},
			{10, 1},
			{11, 1},
			{12, 1},
			{13, 1},
			{14, 1},
			{15, 1},
			{16, 1},
			{17, 1},
			{18, 1},
			{19, 1},{19, 2},{19, 3},{19, 4},{19, 5},{19, 6},{19, 7},{19, 8},{19, 9},{19, 10},{19, 11},{19, 12},
				{19, 13},{19, 14},{19, 15},{19, 16},{19, 17},{19, 18},{19, 19},{19, 20},{19, 21},{19, 22},{19, 23},{19, 24}
		},
			48, YELLOW
	};
	return result;
}

struct Map addRoute(const struct Map* map, const struct Route* route)
{
	int r, c;
	struct Map result = { {0}, 0 };

	for (r = 0; r < map->numRows; r++)
	{
		for (c = 0; c < map->numCols; c++)
		{
			result.squares[r][c] = map->squares[r][c];
		}
	}
	result.numRows = map->numRows;
	result.numCols = map->numCols;

	for (r = 0; r < route->numPoints; r++)
	{
		result.squares[route->points[r].row][route->points[r].col] += route->routeSymbol;
	}

	return result;
}

void addPtToRoute(struct Route* route, struct Point pt)
{
	route->points[route->numPoints++] = pt;
}

void addPointToRoute(struct Route* route, const int row, const int col)
{
	struct Point pt = { row, col };
	addPtToRoute(route, pt);
}

void addPointToRouteIfNot(struct Route* route, const int row, const int col, const struct Point notThis)
{
	struct Point pt = { row, col };
	if (notThis.row != row || notThis.col != col) addPtToRoute(route, pt);
}

double distance(const struct Point* p1, const struct Point* p2)
{
	int deltaRow = p2->row - p1->row;
	int deltaCol = p2->col - p1->col;

	return sqrt((double)(deltaRow * deltaRow + deltaCol * deltaCol));
}

struct Route shortestPath(const struct Map* map, const struct Point start, const struct Point dest)
{
	struct Route result = { {0,0}, 0, DIVERSION };
	struct Point last = { -1, -1 };
	struct Point current = start;
	struct Route possible = { {0,0},0,0 };
	int close = 0;

	// If start and dest are the same, return empty route
	if (eqPt(start, dest)) {
		return result;
	}

	//while (distance(&current, &dest) != 1 && close >= 0) // changing from !eqPt(current, dest)
	while (distance(&current, &dest) != 1 && close >= 0 && result.numPoints < MAX_ROUTE) //changing from (distance(&current, &dest) != 1 && close >= 0)
	{
		possible = getPossibleMoves(map, current, last);
		close = getClosestPoint(&possible, dest);
		if (close >= 0)
		{
			last = current;
			current = possible.points[close];
			addPtToRoute(&result, current);
		}
	}

	return result;
}

struct Route getPossibleMoves(const struct Map* map, const struct Point p1, const struct Point backpath)
{
	struct Route result = { {0,0}, 0, DIVERSION };

	if (p1.row > 0)
	{
		if (map->squares[p1.row - 1][p1.col] != 1) addPointToRouteIfNot(&result, p1.row - 1, p1.col, backpath);	// square above
		if (p1.col > 0 && map->squares[p1.row - 1][p1.col - 1] != 1) addPointToRouteIfNot(&result, p1.row - 1, p1.col - 1, backpath);	// top left
		if (p1.col < (map->numCols - 1) && map->squares[p1.row - 1][p1.col + 1] != 1) addPointToRouteIfNot(&result, p1.row - 1, p1.col + 1, backpath);	// top right
	}
	if (p1.col > 0 && map->squares[p1.row][p1.col - 1] != 1)addPointToRouteIfNot(&result, p1.row, p1.col - 1, backpath);	// left
	if (p1.col < (map->numCols - 1) && map->squares[p1.row][p1.col + 1] != 1)addPointToRouteIfNot(&result, p1.row, p1.col + 1, backpath);	// right
	if (p1.row < (map->numRows - 1))
	{
		if (map->squares[p1.row + 1][p1.col] != 1) addPointToRouteIfNot(&result, p1.row + 1, p1.col, backpath);	// square below
		if (p1.col > 0 && map->squares[p1.row + 1][p1.col - 1] != 1) addPointToRouteIfNot(&result, p1.row + 1, p1.col - 1, backpath);	// bot left
		if (p1.col < (map->numCols - 1) && map->squares[p1.row + 1][p1.col + 1] != 1) addPointToRouteIfNot(&result, p1.row + 1, p1.col + 1, backpath);	// top right
	}

	return result;
}

int eqPt(const struct Point p1, const struct Point p2)
{
	return p1.row == p2.row && p1.col == p2.col;
}

int getClosestPoint(const struct Route* route, const struct Point pt)
{
	int i, closestIdx = -1;
	double closestDist = 999999.99, dist;

	for (i = 0; i < route->numPoints; i++)
	{
		dist = distance(&pt, &route->points[i]);
		if (dist < closestDist)
		{
			closestDist = dist;
			closestIdx = i;
		}
	}
	return closestIdx;
}

int checkWeight(int weight) {
	if (weight >= 1 && weight <= TRUCK_MAX_WEIGHT) {
		return 1;
	}
	return 0;
}

int checkBoxSize(double boxSize) {
	const double epsilon = 0.0001;
	if (fabs(boxSize - 0.5) < epsilon ||
		fabs(boxSize - 2.0) < epsilon ||
		fabs(boxSize - 5.0) < epsilon) {
		return 1;
	}
	return 0;
}

int isValidDestinationFormat(const char* dest) {
	if (dest == 0) {
		printf("please input");
		return 0;
	}

	// Compute string length manually
	int len = 0;
	while (dest[len] != '\0') {
		len++;
	}

	// The destination string should be 2 or 3 characters long
	if (len < 2 || len > 3) {
		printf("should be 2 or 3 characters long");
		return 0;
	}

	// The last character must be an uppercase letter between 'A' and 'Y'
	char letter = dest[len - 1];
	if (letter < 'A' || letter > 'Y') {
		printf("uppercase please");
		return 0;
	}

	// Process the numeric part
	int row = 0;
	for (int i = 0; i < len - 1; i++) {
		char c = dest[i];
		// Check if character is a digit
		if (c < '0' || c > '9') {
			return 0;
		}
		// Convert the character to its numeric value and accumulate
		row = row * 10 + (c - '0');
	}

	// Check if the row number is within the acceptable range (0 to 25)
	if (row < 0 || row > 25) {
		printf("only from 0 to 25");
		return 0;
	}

	return 1;
}

int findTruckForShipment(const struct Map* map, struct Truck trucks[], int numTrucks, const struct Shipment shipment) {
	int bestTruckIndex = -1;
	double bestDiversion = 1e9;  // Arbitrarily large number
	double bestCapacityPct = -1.0; // To compare available capacity when diversions are equal

	// Iterate through each truck
	for (int i = 0; i < numTrucks; i++) {
		// Check capacity: weight and volume must not be exceeded
		if (trucks[i].currentWeight + shipment.weight > TRUCK_MAX_WEIGHT ||
			trucks[i].currentVolume + shipment.boxVolume > TRUCK_MAX_VOLUME) {
			continue;
		}

		// Find the closest point on the truck's route to the shipment destination.
		int idx = getClosestPoint(&trucks[i].route, shipment.destination);
		if (idx < 0) {
			continue;  // No valid point found
		}
		struct Point closestPoint = trucks[i].route.points[idx];

		// Calculate the diversion route from that point to the shipment destination.
		struct Route diversionRoute = shortestPath(map, closestPoint, shipment.destination);
		double diversionDistance = diversionRoute.numPoints;

		// Compute available capacity percentage (based on the limiting factor).
		double weightPct = (TRUCK_MAX_WEIGHT - trucks[i].currentWeight) / (double)TRUCK_MAX_WEIGHT;
		double volumePct = (TRUCK_MAX_VOLUME - trucks[i].currentVolume) / TRUCK_MAX_VOLUME;
		double availablePct = (weightPct < volumePct) ? weightPct : volumePct;

		// Choose the truck with the smallest diversion distance.
		// In case of a tie, choose the one with the highest available capacity percentage.
		if (diversionDistance < bestDiversion ||
			(fabs(diversionDistance - bestDiversion) < 0.0001 && availablePct > bestCapacityPct)) {
			bestDiversion = diversionDistance;
			bestCapacityPct = availablePct;
			bestTruckIndex = i;
		}
	}

	return bestTruckIndex;
}

struct Route calculateDiversionPath(const struct Map* map, const struct Route* truckRoute, const struct Point destination) {
	struct Route diversionPath = { {0}, 0, DIVERSION };

	int idx = getClosestPoint(truckRoute, destination);
	if (idx < 0) {
		return diversionPath;  // Return an empty diversion path if no valid point is found.
	}
	struct Point startPoint = truckRoute->points[idx];

	// Use the provided shortestPath function (from mapping.c) to calculate the diversion.
	diversionPath = shortestPath(map, startPoint, destination);
	return diversionPath;
}

int updateTruckLoad(struct Truck* truck, const struct Shipment shipment) {
	if (truck->currentWeight + shipment.weight > TRUCK_MAX_WEIGHT ||
		truck->currentVolume + shipment.boxVolume > TRUCK_MAX_VOLUME) {
		return 0;  // Cannot update: shipment exceeds capacity.
	}
	truck->currentWeight += shipment.weight;
	truck->currentVolume += shipment.boxVolume;
	return 1;
}

int checkDestination(const char* dest, const struct Map* map) {
	// Check if input is null or empty
	if (dest == NULL || dest[0] == '\0') {
		return 0;
	}

	// Validate format first
	if (!isValidDestinationFormat(dest)) {
		return 0;
	}

	// Extract row and column from destination string
	int len = strlen(dest);
	int row = 0;
	for (int i = 0; i < len - 1; i++) {
		row = row * 10 + (dest[i] - '0');
	}
	row = row - 1; //Subtract 1 to convert visual row to array index
	char colChar = dest[len - 1];
	int col = colChar - 'A'; // Convert 'A' to 0, 'B' to 1, etc.

	// Check if coordinates are within map bounds
	if (row < 0 || row >= map->numRows || col < 0 || col >= map->numCols) {
		return 0;
	}

	// Check if the location is a building (value 1 in map)
	if (map->squares[row][col] == 1) {
		return 1;
	}

	return 0; // Not a building
}

void runSenecaDeliveries() {
	struct Map baseMap = populateMap();

	struct Truck trucks[3] = {
		{ BLUE, getBlueRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 0, 0.0 },
		{ GREEN, getGreenRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 0, 0.0 },
		{ YELLOW, getYellowRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 0, 0.0 }
	};

	int weight = -1;
	double boxSize = -1;
	char destStr[10];

	printf("=================\n");
	printf("Seneca Polytechnic Deliveries:\n");
	printf("=================\n");

	int running = 1;

	while (running) {
		// Prompt user
		printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
		int readCount = scanf("%d %lf %s", &weight, &boxSize, destStr);

		if (readCount != 3) {
			printf("Invalid input.Please enter weight, box size and destination.\n");

			// Clear remaining invalid input in buffer
			int ch;
			while ((ch = getchar()) != '\n' && ch != EOF);

			continue;
		}

		// Exit condition
		if (weight == 0 && boxSize == 0 && (destStr[0] == 'x' || destStr[0] == 'X')) {
			running = 0;
			continue;
		}

		// Check weight first
		if (!checkWeight(weight)) {
			printf("Invalid weight (must be 1-5000 Kg.)\n");
			continue;
		}

		// Next, check box size
		if (!checkBoxSize(boxSize)) {
			printf("Invalid size\n");
			continue;
		}

		// Validate destination format
		if (!isValidDestinationFormat(destStr)) {
			printf("Invalid destination\n");
			continue;
		}

		// Convert destination to Point (FIX: subtract 1 for visual-to-index match)
		int row = 0;
		int len = strlen(destStr);
		for (int i = 0; i < len - 1; i++) {
			row = row * 10 + (destStr[i] - '0');
		}
		row = row - 1; //Subtract 1 to convert visual row to array index

		int col = destStr[len - 1] - 'A';

		// Boundary check (optional)
		if (row < 0 || row >= baseMap.numRows || col < 0 || col >= baseMap.numCols) {
			printf("Invalid destination\n");
			continue;
		}

		struct Point destination = { row, col };

		// Validate destination square
		if (baseMap.squares[row][col] != 1) {
			printf("Invalid destination\n");
			continue;
		}

		struct Shipment shipment = { weight, boxSize, destination };

		// Find the best truck
		int bestTruck = findTruckForShipment(&baseMap, trucks, 3, shipment);

		if (bestTruck == -1) {
			printf("Ships tomorrow\n");
		}
		else {
			struct Route diversion = calculateDiversionPath(&baseMap, &trucks[bestTruck].route, destination);

			// Print truck line
			printf("Ship on ");
			if (trucks[bestTruck].type == BLUE) printf("BLUE LINE");
			else if (trucks[bestTruck].type == GREEN) printf("GREEN LINE");
			else if (trucks[bestTruck].type == YELLOW) printf("YELLOW LINE");

			// Print diversion route
			if (diversion.numPoints == 0) {
				printf(", no diversion\n");
			}
			else {
				printf(", divert:");
				for (int i = 0; i < diversion.numPoints; i++) {
					printf(" %d%c",
						diversion.points[i].row + 1, // ✅ Convert index back to display row (1–25)
						'A' + diversion.points[i].col);
					if (i != diversion.numPoints - 1) printf(",");
				}
				printf("\n");
			}

			// Update truck load
			updateTruckLoad(&trucks[bestTruck], shipment);
		}
	}
}
