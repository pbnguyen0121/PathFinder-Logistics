#ifndef DELIVERY_H
#define DELIVERY_H

#include "mapping.h"
#include "mapping.h"
#include <ctype.h>
#include <stdio.h>
#include <math.h>

#define TRUCK_MAX_WEIGHT 5000
#define TRUCK_MAX_VOLUME 250.0

struct Truck {
    int type;
    struct Route route;
    int maxWeight;
    double maxVolume;
    int currentWeight;
    double currentVolume;
};

struct Shipment {
    int weight;
    double boxVolume;
    struct Point destination;
};


/**
 * Checks if the shipment weight is within acceptable limits (1 to TRUCK_MAX_WEIGHT).
 * @param weight The shipment weight in kilograms.
 * @return 1 if the weight is valid; otherwise, 0.
 */
int checkWeight(int weight);

/**
 * Checks if the box size is valid.
 * Allowed box sizes are 0.5, 2, and 5 cubic meters.
 * @param boxSize The size of the box in cubic meters.
 * @return 1 if the box size is valid; otherwise, 0.
 */
int checkBoxSize(double boxSize);

/**
 * Validates the format of the destination string.
 *
 * The destination should consist of a numeric part (0-25) followed by an uppercase letter (A-Y).
 * For example: "12L" is valid, while "28x" or "3Z" are invalid.
 *
 * @param dest The destination string provided by the user.
 * @return 1 if the format is valid; otherwise, 0.
 */
int isValidDestinationFormat(const char* dest);

/**
 * Checks if the destination input is valid.
 *
 * First, it validates the format (using isValidDestinationFormat). Then, it converts the
 * destination into map coordinates and checks whether the destination corresponds to a valid
 * building location on the map.
 *
 * @param dest The destination string provided by the user.
 * @param map A pointer to the current map.
 * @return 1 if the destination is valid; otherwise, 0.
 */
int checkDestination(const char* dest, const struct Map* map);

///* Initializes a truck with zero load.
//   The truck type is specified by one of the macros (TRUCK_BLUE, TRUCK_GREEN, TRUCK_YELLOW) */
//void initTruck(struct Truck* truck, int type);
//
///* Attempts to add a shipment to a truck.
//   Returns 1 if successful, or 0 if the truck cannot accommodate the shipment.
//   It will use TRUCK_MAX_WEIGHT and TRUCK_MAX_VOLUME to check available capacity.
//*/
//int addShipmentToTruck(struct Truck* truck, struct Shipment shipment);


//adding functions

/// <summary>
/// Scans the available trucks and selects the best truck for a given shipment
/// </summary>
/// <param name="map">Pointer to the city map</param>
/// <param name="trucks">Array of available Truck structures</param>
/// <param name="numTrucks">Number of trucks available</param>
/// <param name="shipment">The shipment details (weight, box volume, destination)</param>
/// <returns>The index of the best truck in the trucks array. Returns -1 if no truck qualifies.</returns>
int findTruckForShipment(const struct Map* map, struct Truck trucks[], int numTrucks, const struct Shipment shipment);


/// <summary>
/// Determines the shortest diversion path from the truck’s route to the shipment destination.
/// </summary>
/// <param name="map">Pointer to the Map structure</param>
/// <param name="truckRoute">Pointer to the truck’s default route</param>
/// <param name="destination">The destination point for the shipment</param>
/// <returns>struct Route: The diversion path. If no path is found, the Route's numPoints will be zero.</returns>
struct Route calculateDiversionPath(const struct Map* map, const struct Route* truckRoute, const struct Point destination);


/// <summary>
/// Adds the shipment’s weight and volume to the truck’s current load.
/// The update is performed only if neither the maximum weight nor maximum volume is exceeded.
/// </summary>
/// <param name="truck">Pointer to the Truck structure to update </param>
/// <param name="shipment">The shipment to be loaded</param>
/// <returns>1 if the truck load was updated successfully, 0 otherwise.</returns>
int updateTruckLoad(struct Truck* truck, const struct Shipment shipment);

/*Phuong Bac comments*/
//That's because we need at least 4 functions to complete this milestone. 
// Feel free to add any functions you want for your convenience. 
// I'm going to leave the above 2 functions and will find a way to add them where they are needed


//Test execution : Run the code for user input data
void runSenecaDeliveries();


#endif
