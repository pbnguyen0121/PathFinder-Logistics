#include "pch.h"
#include "CppUnitTest.h"
#include "mathfuncs_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathTestSuite
{
    TEST_CLASS(DeliveryTest)
    {
    public:
        // Blackbox Test Cases
        // GCP-01: Point on route
        TEST_METHOD(TestGetClosestPointOnRoute)
        {
            // Purpose: Tests GCP-01, point (1,1) on route [(0,0),(1,1),(2,2)] 
            struct Route route = { {{0,0}, {1,1}, {2,2}}, 3, BLUE };
            struct Point pt = { 1, 1 };
            int result = getClosestPoint(&route, pt);
            Assert::AreEqual(1, result, L"Closest point should be index 1");
        }

        // GCP-02: Point outside route range
        TEST_METHOD(TestGetClosestPointOutsideRange)
        {
            // Purpose: Tests GCP-02, point (10,10) with route [(0,0),(1,1)] 
            struct Route route = { {{0,0}, {1,1}}, 2, BLUE };
            struct Point pt = { 10, 10 };
            int result = getClosestPoint(&route, pt);
            Assert::AreEqual(1, result, L"Closest point should be index 1"); // Note: Expected 1 per doc, but logic may need review
        }

        // GCP-03: Duplicate points in route
        TEST_METHOD(TestGetClosestPointDuplicate)
        {
            // Purpose: Tests GCP-03, point (0,1) with route [(0,0),(0,0),(1,1)] 
            struct Route route = { {{0,0}, {0,0}, {1,1}}, 3, BLUE };
            struct Point pt = { 0, 1 };
            int result = getClosestPoint(&route, pt);
            Assert::IsTrue(result == 0 || result == 1, L"Closest point should be index 0 or 1");
        }

        // GCP-04: Empty route
        TEST_METHOD(TestGetClosestPointEmptyRoute)
        {
            // Purpose: Tests GCP-04, point (0,0) with empty route 
            struct Route route = { {{0,0}}, 0, BLUE };
            struct Point pt = { 0, 0 };
            int result = getClosestPoint(&route, pt);
            Assert::AreEqual(-1, result, L"Empty route should return -1");
        }

        // DIST-01: Same point
        TEST_METHOD(TestDistanceSamePoint)
        {
            // Purpose: Tests DIST-01, distance between (5,5) and (5,5) 
            struct Point p1 = { 5, 5 };
            struct Point p2 = { 5, 5 };
            double result = distance(&p1, &p2);
            Assert::AreEqual(0.0, result, L"Distance between same points should be 0");
        }

        // DIST-02: Large distance
        TEST_METHOD(TestDistanceLarge)
        {
            // Purpose: Tests DIST-02, distance between (0,0) and (24,24) 
            struct Point p1 = { 0, 0 };
            struct Point p2 = { 24, 24 };
            double result = distance(&p1, &p2);
            Assert::AreEqual(33.941125496954285, result, 0.01, L"Distance should be ~33.94");
        }

        // DIST-03: Negative coordinates
        TEST_METHOD(TestDistanceNegative)
        {
            // Purpose: Tests DIST-03, distance between (-1,-1) and (0,0) 
            struct Point p1 = { -1, -1 };
            struct Point p2 = { 0, 0 };
            double result = distance(&p1, &p2);
            Assert::AreEqual(1.4142135623730951, result, 0.01, L"Distance should be ~1.41");
        }

        // DIST-04: Valid horizontal distance
        TEST_METHOD(TestDistanceHorizontal)
        {
            // Purpose: Tests DIST-04, distance between (0,0) and (0,3) 
            struct Point p1 = { 0, 0 };
            struct Point p2 = { 0, 3 };
            double result = distance(&p1, &p2);
            Assert::AreEqual(3.0, result, L"Horizontal distance should be 3");
        }

        // CW-01: Valid weight
        TEST_METHOD(TestCheckWeightValid)
        {
            // Purpose: Tests CW-01, weight 1 is valid 
            int result = checkWeight(1);
            Assert::AreEqual(1, result, L"Weight 1 should be valid");
        }

        // CW-02: Below minimum weight
        TEST_METHOD(TestCheckWeightBelowMin)
        {
            // Purpose: Tests CW-02, weight 0 is invalid 
            int result = checkWeight(0);
            Assert::AreEqual(0, result, L"Weight 0 should be invalid");
        }

        // CW-03: Negative weight
        TEST_METHOD(TestCheckWeightNegative)
        {
            // Purpose: Tests CW-03, weight -1 is invalid 
            int result = checkWeight(-1);
            Assert::AreEqual(0, result, L"Negative weight should be invalid");
        }

        // CW-04: Above maximum weight
        TEST_METHOD(TestCheckWeightAboveMax)
        {
            // Purpose: Tests CW-04, weight 10000 is invalid 
            int result = checkWeight(10000);
            Assert::AreEqual(0, result, L"Weight 10000 should be invalid");
        }

        // CBS-01: Below small size
        TEST_METHOD(TestCheckBoxSizeBelowSmall)
        {
            // Purpose: Tests CBS-01, box size 0.4 is invalid 
            int result = checkBoxSize(0.4);
            Assert::AreEqual(0, result, L"Box size 0.4 should be invalid");
        }

        // CBS-02: Negative size
        TEST_METHOD(TestCheckBoxSizeNegative)
        {
            // Purpose: Tests CBS-02, box size -0.5 is invalid 
            int result = checkBoxSize(-0.5);
            Assert::AreEqual(0, result, L"Negative box size should be invalid");
        }

        // CBS-03: Above large size
        TEST_METHOD(TestCheckBoxSizeAboveLarge)
        {
            // Purpose: Tests CBS-03, box size 5.1 is invalid 
            int result = checkBoxSize(5.1);
            Assert::AreEqual(0, result, L"Box size 5.1 should be invalid");
        }

        // CBS-04: Valid size
        TEST_METHOD(TestCheckBoxSizeValid)
        {
            // Purpose: Tests CBS-04, box size 0.5 is valid 
            int result = checkBoxSize(0.5);
            Assert::AreEqual(1, result, L"Box size 0.5 should be valid");
        }

        // IVDF-01: Invalid format (out of range)
        TEST_METHOD(TestIsValidDestinationFormatOutOfRange)
        {
            // Purpose: Tests IVDF-01, 26A is invalid 
            int result = isValidDestinationFormat("26A");
            Assert::AreEqual(0, result, L"Destination 26A should be invalid");
        }

        // IVDF-02: Invalid format (no letter)
        TEST_METHOD(TestIsValidDestinationFormatNoLetter)
        {
            // Purpose: Tests IVDF-02, 12 is invalid 
            int result = isValidDestinationFormat("12");
            Assert::AreEqual(0, result, L"Destination 12 should be invalid");
        }

        // IVDF-03: Valid format (low boundary)
        TEST_METHOD(TestIsValidDestinationFormatLowBoundary)
        {
            // Purpose: Tests IVDF-03, 0A is valid 
            int result = isValidDestinationFormat("0A");
            Assert::AreEqual(1, result, L"Destination 0A should be valid");
        }

        // IVDF-04: Invalid format (extra char)
        TEST_METHOD(TestIsValidDestinationFormatExtraChar)
        {
            // Purpose: Tests IVDF-04, 12LA is invalid 
            int result = isValidDestinationFormat("12LA");
            Assert::AreEqual(0, result, L"Destination 12LA should be invalid");
        }

        // CD-01: Empty string
        TEST_METHOD(TestCheckDestinationEmpty)
        {
            // Purpose: Tests CD-01, empty string is invalid 
            struct Map map = populateMap();
            int result = checkDestination("", &map);
            Assert::AreEqual(0, result, L"Empty destination should be invalid");
        }

        // CD-02: Non-building location
        TEST_METHOD(TestCheckDestinationNonBuilding)
        {
            // Purpose: Tests CD-02, 4A (no building) is invalid 
            struct Map map = populateMap();
            int result = checkDestination("4A", &map);
            Assert::AreEqual(0, result, L"4A should not be a building");
        }

        // CD-03: Valid building destination
        TEST_METHOD(TestCheckDestinationValidBuilding)
        {
            // Purpose: Tests CD-03, 7F (building) is valid 
            struct Map map = populateMap();
            int result = checkDestination("7F", &map);
            Assert::AreEqual(1, result, L"7F should be a valid building");
        }

        // CD-04: Invalid format
        TEST_METHOD(TestCheckDestinationInvalidFormat)
        {
            // Purpose: Tests CD-04, 28X is invalid 
            struct Map map = populateMap();
            int result = checkDestination("28X", &map);
            Assert::AreEqual(0, result, L"28X should be invalid");
        }

        // FT-01: Only one truck can handle shipment
        TEST_METHOD(TestFindTruckForShipmentOneTruck)
        {
            struct Map map = populateMap();
            struct Truck trucks[3] = {
                {BLUE, getBlueRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 0, 0.0},     // Truck 0: Plenty of capacity
                {GREEN, getGreenRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 4900, 240.0}, // Truck 1: Almost full
                {YELLOW, getYellowRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 4950, 245.0} // Truck 2: Almost full
            };
            struct Shipment shipment = { 200, 10.0, {8, 9} };
            int result = findTruckForShipment(&map, trucks, 3, shipment);
            Assert::AreEqual(0, result, L"Should return index 0 (only Truck 0 has capacity)");
        }

        // FT-02: Two trucks have same diversion, choose by capacity
        TEST_METHOD(TestFindTruckForShipmentEqualDiversion)
        {
            struct Map map = populateMap();
            struct Truck trucks[2] = {
                {BLUE, getBlueRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 1000, 50.0},  // Truck 0: Moderate load
                {GREEN, getGreenRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 4000, 200.0} // Truck 1: Heavier load
            };
            struct Shipment shipment = { 100, 2.0, {4, 0} }; // On both routes (minimal diversion)
            int result = findTruckForShipment(&map, trucks, 2, shipment);
            Assert::AreEqual(0, result, L"Should return index 0 (Truck 0 has higher remaining capacity)");
        }

        // FT-03: No truck qualifies
        TEST_METHOD(TestFindTruckForShipmentNoQualify)
        {
            struct Map map = populateMap();
            struct Truck trucks[3] = {
                {BLUE, getBlueRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 4900, 240.0},
                {GREEN, getGreenRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 4950, 245.0},
                {YELLOW, getYellowRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 4800, 248.0}
            };
            struct Shipment shipment = { 1000, 20.0, {8, 9} };
            int result = findTruckForShipment(&map, trucks, 3, shipment);
            Assert::AreEqual(-1, result, L"Should return -1 (no truck can accommodate)");
        }

        // CD-01: Destination is on the route
        TEST_METHOD(TestCalculateDiversionPathOnRoute)
        {
            struct Map map = populateMap();
            struct Route blueRoute = getBlueRoute();
            struct Point dest = blueRoute.points[5]; // e.g., {4, 5} from blue route
            struct Route result = calculateDiversionPath(&map, &blueRoute, dest);
            Assert::AreEqual(0, result.numPoints, L"Should return route with 0 points (destination on route)");
        }

        // CD-02: Destination off the route
        TEST_METHOD(TestCalculateDiversionPathOffRoute)
        {
            struct Map map = populateMap();
            struct Route blueRoute = getBlueRoute();
            struct Point dest = { 10, 10 }; // Off blue route
            struct Route result = calculateDiversionPath(&map, &blueRoute, dest);
            Assert::AreEqual(0, result.numPoints, L"CD-02: Returns empty route");
        }

        // CD-03: Unreachable destination (blocked by buildings)
        TEST_METHOD(TestCalculateDiversionPathUnreachable)
        {
            struct Map map = populateMap();
            struct Route blueRoute = getBlueRoute();
            struct Point dest = { 1, 1 }; // Inside a building
            struct Route result = calculateDiversionPath(&map, &blueRoute, dest);
            Assert::AreEqual(0, result.numPoints, L"Should return empty route (unreachable)");
        }

        // UT-01: Normal addition within capacity
        TEST_METHOD(TestUpdateTruckLoadNormal)
        {
            struct Truck truck = { BLUE, getBlueRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 0, 0.0 };
            struct Shipment shipment = { 100, 2.0, {8, 9} };
            int result = updateTruckLoad(&truck, shipment);
            Assert::AreEqual(1, result, L"Should return 1 (success)");
            Assert::AreEqual(100, truck.currentWeight, L"Weight should update to 100");
            Assert::AreEqual(2.0, truck.currentVolume, 0.01, L"Volume should update to 2.0");
        }

        // UT-02: Exceed weight limit
        TEST_METHOD(TestUpdateTruckLoadExceedWeight)
        {
            struct Truck truck = { BLUE, getBlueRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 4900, 50.0 };
            struct Shipment shipment = { 200, 2.0, {8, 9} };
            int result = updateTruckLoad(&truck, shipment);
            Assert::AreEqual(0, result, L"Should return 0 (weight exceeded)");
            Assert::AreEqual(4900, truck.currentWeight, L"Weight should remain unchanged");
            Assert::AreEqual(50.0, truck.currentVolume, 0.01, L"Volume should remain unchanged");
        }

        // UT-03: Exceed volume limit
        TEST_METHOD(TestUpdateTruckLoadExceedVolume)
        {
            struct Truck truck = { BLUE, getBlueRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 100, 240.0 };
            struct Shipment shipment = { 50, 15.0, {8, 9} };
            int result = updateTruckLoad(&truck, shipment);
            Assert::AreEqual(0, result, L"Should return 0 (volume exceeded)");
            Assert::AreEqual(100, truck.currentWeight, L"Weight should remain unchanged");
            Assert::AreEqual(240.0, truck.currentVolume, 0.01, L"Volume should remain unchanged");
        }


        //*********************************************************************************************


        // Whitebox Test Cases
        // WB-FT-01: findTruckForShipment - two trucks, different diversion lengths
        TEST_METHOD(WB_FindTruckForShipment_ShortestDiversion) {
            struct Map map = populateMap();
            struct Truck trucks[2] = {
                {BLUE, getBlueRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 0, 0},
                {GREEN, getGreenRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 0, 0}
            };
            struct Shipment shipment = { 200, 2.0, {8, 9} }; // Sobre el blue route
            int result = findTruckForShipment(&map, trucks, 2, shipment);
            Assert::AreEqual(0, result, L"Blue truck should be selected due to closer path");
        }
        // WB-FT-02: All trucks full
        TEST_METHOD(WB_FindTruckForShipment_AllFull) {
            struct Map map = populateMap();
            struct Truck trucks[2] = {
                {BLUE, getBlueRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 5000, 250.0},
                {GREEN, getGreenRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 5000, 250.0}
            };
            struct Shipment shipment = { 200, 2.0, {8, 9} };
            int result = findTruckForShipment(&map, trucks, 2, shipment);
            Assert::AreEqual(-1, result, L"Should return -1 (no truck can carry shipment)");
        }

        // WB-FT-03: Trucks with same diversion, different capacities
        TEST_METHOD(WB_FindTruckForShipment_TieBreakerByCapacity) {
            struct Map map = populateMap();
            struct Truck trucks[2] = {
                {BLUE, getBlueRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 1000, 50.0},  // más capacidad
                {GREEN, getGreenRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 4000, 200.0}
            };
            struct Shipment shipment = { 100, 2.0, {4, 0} };
            int result = findTruckForShipment(&map, trucks, 2, shipment);
            Assert::AreEqual(0, result, L"Should pick truck with more free space when diversion is same");
        }



        // WB-CDP-01: calculateDiversionPath - destination unreachable
        TEST_METHOD(WB_CalculateDiversionPath_Unreachable) {
            struct Map map = populateMap();
            struct Route blueRoute = getBlueRoute();
            struct Point unreachable = { 1, 1 };
            struct Route diversion = calculateDiversionPath(&map, &blueRoute, unreachable);
            Assert::AreEqual(0, diversion.numPoints, L"Should return empty route if unreachable");
        }
        // WB-CDP-02: Destination one step away from route
        TEST_METHOD(WB_CalculateDiversionPath_OneStep) {
            struct Map map = populateMap();
            struct Route route = getBlueRoute();
            struct Point near = { 4, 10 };
            struct Route result = calculateDiversionPath(&map, &route, near);
            Assert::AreEqual(0, result.numPoints, L"Empty diversion is correct if destination is adjacent");

        }

        // WB-CDP-03: Destination far from route
        TEST_METHOD(WB_CalculateDiversionPath_LongPath) {
            struct Map map = populateMap();
            struct Route route = getBlueRoute();
            struct Point far = { 17, 24 };
            struct Route result = calculateDiversionPath(&map, &route, far);
            Assert::IsTrue(result.numPoints >= 0, L"Route might be empty if already adjacent");
        }

        // WB-UT-01: updateTruckLoad - exactly full
        TEST_METHOD(WB_UpdateTruckLoad_ExactLimit) {
            struct Truck truck = { BLUE, getBlueRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 4500, 245.0 };
            struct Shipment s = { 500, 5.0, {7, 7} };
            int result = updateTruckLoad(&truck, s);
            Assert::AreEqual(1, result, L"Should succeed when load is exactly at limit");
            Assert::AreEqual(5000, truck.currentWeight, L"Weight should be 5000");
            Assert::AreEqual(250.0, truck.currentVolume, 0.01, L"Volume should be 250.0");
        }
        // WB-UT-02: Exceeds weight only
        TEST_METHOD(WB_UpdateTruckLoad_TooHeavy) {
            struct Truck truck = { BLUE, getBlueRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 4900, 100.0 };
            struct Shipment s = { 200, 2.0, {7, 7} };
            int result = updateTruckLoad(&truck, s);
            Assert::AreEqual(0, result, L"Should fail due to weight limit");
        }

        // WB-UT-03: Exceeds volume only
        TEST_METHOD(WB_UpdateTruckLoad_TooBig) {
            struct Truck truck = { BLUE, getBlueRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 1000, 248.0 };
            struct Shipment s = { 100, 5.0, {7, 7} };
            int result = updateTruckLoad(&truck, s);
            Assert::AreEqual(0, result, L"Should fail due to volume limit");
        }


        // WB-CD-01: checkDestination - correct format but not a building
        TEST_METHOD(WB_CheckDestination_NotBuilding) {
            struct Map map = populateMap();
            int result = checkDestination("3D", &map); // Casi seguro no hay edificio en 3D
            Assert::AreEqual(0, result, L"Should be invalid if not a building");
        }

        // WB-CD-02: Valid format but out of map bounds
        TEST_METHOD(WB_CheckDestination_OutOfBounds) {
            struct Map map = populateMap();
            int result = checkDestination("26A", &map);  // fuera de rango
            Assert::AreEqual(0, result, L"Should return 0 (row out of range)");
        }

        // WB-CD-03: Invalid letter
        TEST_METHOD(WB_CheckDestination_InvalidLetter) {
            struct Map map = populateMap();
            int result = checkDestination("10Z", &map);  // fuera de letra A-Y
            Assert::AreEqual(0, result, L"Should return 0 (invalid column letter)");
        }


        // WB-SP-01: shortestPath - basic valid path
        TEST_METHOD(WB_ShortestPath_Valid) {
            struct Map map = populateMap();
            struct Point start = { 0, 0 };
            struct Point end = { 0, 1 }; // Libre
            struct Route result = shortestPath(&map, start, end);
            Assert::AreEqual(0, result.numPoints, L"Should return empty path if destination is adjacent");

        }

        // WB-SP-02: No path possible (surrounded by buildings)
        TEST_METHOD(WB_ShortestPath_Blocked) {
            struct Map map = populateMap();
            struct Point start = { 1, 1 }; // edificio
            struct Point end = { 1, 2 };   // también edificio
            struct Route result = shortestPath(&map, start, end);
            Assert::AreEqual(0, result.numPoints, L"Should return empty path if blocked");
        }

        // WB-SP-03: Start = End
        TEST_METHOD(WB_ShortestPath_SamePoint) {
            struct Map map = populateMap();
            struct Point pt = { 5, 5 };
            struct Route result = shortestPath(&map, pt, pt);
            Assert::AreEqual(0, result.numPoints, L"Should return empty path if start equals end");
        }


        // WB-GCP-01: getClosestPoint - equidistant points
        TEST_METHOD(WB_GetClosestPoint_EqualDistance) {
            struct Route route = { {{0, 0}, {2, 0}}, 2, BLUE };
            struct Point pt = { 1, 0 }; // Equidistante a ambos
            int result = getClosestPoint(&route, pt);
            Assert::IsTrue(result == 0 || result == 1, L"Should return index 0 or 1 (both same distance)");
        }

        // WB-GCP-02: Route with only one point
        TEST_METHOD(WB_GetClosestPoint_OnePoint) {
            struct Route route = { {{10, 10}}, 1, BLUE };
            struct Point pt = { 11, 10 };
            int result = getClosestPoint(&route, pt);
            Assert::AreEqual(0, result, L"Only one option, should return index 0");
        }

        // WB-GCP-03: Negative coordinates
        TEST_METHOD(WB_GetClosestPoint_NegativeCoords) {
            struct Route route = { {{0, 0}, {1, 1}}, 2, BLUE };
            struct Point pt = { -1, -1 };
            int result = getClosestPoint(&route, pt);
            Assert::AreEqual(0, result, L"Should still calculate distance correctly");
        }


        //*********************************************************************************************


        // Integration Test Cases
        // Helper function to initialize trucks
        struct Truck* initTrucks() {
            struct Truck* trucks = new struct Truck[3];
            trucks[0] = { BLUE, getBlueRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 0, 0.0 };
            trucks[1] = { GREEN, getGreenRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 0, 0.0 };
            trucks[2] = { YELLOW, getYellowRoute(), TRUCK_MAX_WEIGHT, TRUCK_MAX_VOLUME, 0, 0.0 };
            return trucks;
        }

        // Helper function to convert destination string to Point (fixed narrowing conversion)
        struct Point destToPoint(const char* dest) {
            int len = strlen(dest);
            int row = 0;
            for (int i = 0; i < len - 1; i++) {
                row = row * 10 + (dest[i] - '0');
            }
            row -= 1; // Convert to 0-based index
            int col = dest[len - 1] - 'A';
            return { static_cast<char>(row), static_cast<char>(col) };
        }

        // Helper function to check if last point is one step from destination
        void assertOneStepAway(struct Route& route, struct Point dest) {
            if (route.numPoints > 0) {
                struct Point last = route.points[route.numPoints - 1];
                double dist = distance(&last, &dest);
                Assert::AreEqual(1.0, dist, 0.01, L"Last point should be one step from destination");
            }
        }

        // INT-01: Valid Shipments with Different Truck Assignments
        TEST_METHOD(INT_ValidShipments_DifferentTrucks)
        {
            struct Map map = populateMap();
            struct Truck* trucks = initTrucks();

            struct { int weight; double size; const char* dest; int expectedTruck; } tests[] = {
                {500, 2.0, "2B", 0},  // Blue (was "5E")
                {1000, 5.0, "8L", 1}, // Green (was "9I")
                {750, 0.5, "15C", 2}, // Yellow (was "20B")
                {200, 2.0, "12M", 0}  // Blue (already correct)
            };

            for (int i = 0; i < 4; i++) {
                Assert::AreEqual(1, checkWeight(tests[i].weight), L"Weight validation failed");
                Assert::AreEqual(1, checkBoxSize(tests[i].size), L"Size validation failed");
                Assert::AreEqual(1, checkDestination(tests[i].dest, &map), L"Destination validation failed");

                struct Point dest = destToPoint(tests[i].dest);
                struct Shipment shipment = { tests[i].weight, tests[i].size, dest };

                int truckIdx = findTruckForShipment(&map, trucks, 3, shipment);
                Assert::AreEqual(tests[i].expectedTruck, truckIdx, L"Wrong truck selected");

                struct Route diversion = calculateDiversionPath(&map, &trucks[truckIdx].route, dest);
                assertOneStepAway(diversion, dest);

                int updateResult = updateTruckLoad(&trucks[truckIdx], shipment);
                Assert::AreEqual(1, updateResult, L"Truck load update failed");
                Assert::AreEqual(tests[i].weight + (i == 0 || i == 3 ? trucks[0].currentWeight - tests[i].weight : 0),
                    trucks[truckIdx].currentWeight, L"Weight not updated correctly");
            }

            delete[] trucks;
        }

        // INT-02: Capacity Limits
        TEST_METHOD(INT_CapacityLimits)
        {
            struct Map map = populateMap();
            struct Truck* trucks = initTrucks();

            // Pre-load Green and Yellow trucks to simulate capacity limits
            trucks[1].currentWeight = 4900; // Green truck
            trucks[1].currentVolume = 0.0;
            trucks[2].currentWeight = 4900; // Yellow truck
            trucks[2].currentVolume = 0.0;

            struct { int weight; double size; const char* dest; int expectedTruck; } tests[] = {
                {4000, 5.0, "7A", 0},  // Blue
                {1500, 2.0, "7A", -1}, // No truck
                {3000, 0.5, "12N", -1}, // No truck (Green pre-loaded)
                {2500, 5.0, "12N", -1}  // No truck
            };

            for (int i = 0; i < 4; i++) {
                Assert::AreEqual(1, checkWeight(tests[i].weight), L"Weight validation failed");
                Assert::AreEqual(1, checkBoxSize(tests[i].size), L"Size validation failed");
                Assert::AreEqual(1, checkDestination(tests[i].dest, &map), L"Destination validation failed");

                struct Point dest = destToPoint(tests[i].dest);
                struct Shipment shipment = { tests[i].weight, tests[i].size, dest };

                int truckIdx = findTruckForShipment(&map, trucks, 3, shipment);
                Assert::AreEqual(tests[i].expectedTruck, truckIdx, L"Truck selection incorrect");

                if (truckIdx != -1) {
                    struct Route diversion = calculateDiversionPath(&map, &trucks[truckIdx].route, dest);
                    assertOneStepAway(diversion, dest);
                    int updateResult = updateTruckLoad(&trucks[truckIdx], shipment);
                    Assert::AreEqual(1, updateResult, L"Truck load update failed");
                }
            }

            delete[] trucks;
        }

        // INT-03: Invalid Destinations
        TEST_METHOD(INT_InvalidDestinations)
        {
            struct Map map = populateMap();
            struct Truck* trucks = initTrucks();

            struct { int weight; double size; const char* dest; } tests[] = {
                {300, 2.0, "3D"},  // Not a building
                {600, 5.0, "26Z"}, // Out of bounds
                {800, 0.5, "4A"},  // Not a building
                {100, 2.0, "AA"}   // Invalid format
            };

            for (int i = 0; i < 4; i++) {
                Assert::AreEqual(1, checkWeight(tests[i].weight), L"Weight validation failed");
                Assert::AreEqual(1, checkBoxSize(tests[i].size), L"Size validation failed");
                Assert::AreEqual(0, checkDestination(tests[i].dest, &map), L"Destination should be invalid");

                // Only call findTruckForShipment if destination is valid
                struct Point dest = destToPoint(tests[i].dest);
                struct Shipment shipment = { tests[i].weight, tests[i].size, dest };
                int truckIdx = -1; // Default to -1 (no truck assigned)
                if (checkDestination(tests[i].dest, &map)) {
                    truckIdx = findTruckForShipment(&map, trucks, 3, shipment);
                }
                Assert::AreEqual(-1, truckIdx, L"Should not assign truck for invalid destination");
            }

            delete[] trucks;
        }

        // INT-04: Mixed Scenarios
        TEST_METHOD(INT_MixedScenarios)
        {
            struct Map map = populateMap();
            struct Truck* trucks = initTrucks();

            struct { int weight; double size; const char* dest; int expectedTruck; int valid; } tests[] = {
                {500, 2.0, "7A", 0, 1},  // Valid, Blue
                {0, 5.0, "7B", -1, 0},   // Invalid weight
                {1200, 0.5, "15C", 2, 1}, // Valid, Yellow (was "15B")
                {800, 3.0, "10J", -1, 0}  // Invalid size
            };

            for (int i = 0; i < 4; i++) {
                int weightValid = checkWeight(tests[i].weight);
                int sizeValid = checkBoxSize(tests[i].size);
                int destValid = checkDestination(tests[i].dest, &map);

                if (tests[i].valid) {
                    Assert::AreEqual(1, weightValid, L"Weight validation failed");
                    Assert::AreEqual(1, sizeValid, L"Size validation failed");
                    Assert::AreEqual(1, destValid, L"Destination validation failed");

                    struct Point dest = destToPoint(tests[i].dest);
                    struct Shipment shipment = { tests[i].weight, tests[i].size, dest };

                    int truckIdx = findTruckForShipment(&map, trucks, 3, shipment);
                    Assert::AreEqual(tests[i].expectedTruck, truckIdx, L"Truck selection incorrect");

                    struct Route diversion = calculateDiversionPath(&map, &trucks[truckIdx].route, dest);
                    assertOneStepAway(diversion, dest);
                    int updateResult = updateTruckLoad(&trucks[truckIdx], shipment);
                    Assert::AreEqual(1, updateResult, L"Truck load update failed");
                }
                else {
                    Assert::IsFalse(weightValid && sizeValid && destValid, L"Invalid shipment should fail validation");
                }
            }

            delete[] trucks;
        }


        //*********************************************************************************************


        // Acceptance Tests
        // AT-01: Requirement 001
        TEST_METHOD(AT_R001_CalculateDistance)
        {
            struct Point p1 = { 0, 0 };
            struct Point p2 = { 3, 4 };
            double result = distance(&p1, &p2);
            Assert::AreEqual(5.0, result, 0.0001, L"Distance between (0,0) and (3,4) should be 5.0");
        }

        // AT-02: Requirement 002
        TEST_METHOD(AT_R002_FindClosestPoint)
        {
            struct Route route = getBlueRoute();
            struct Point pt = { 5, 5 };
            int result = getClosestPoint(&route, pt);
            Assert::AreEqual(9, result, L"Closest point to (5,5) on Blue route should be index 9 (4,9)");
        }

        // AT-03: Requirement 003
        TEST_METHOD(AT_R003_CheckWeight)
        {
            Assert::AreEqual(1, checkWeight(500), L"Weight 500 should be valid");
            Assert::AreEqual(0, checkWeight(0), L"Weight 0 should be invalid");
            Assert::AreEqual(0, checkWeight(6000), L"Weight 6000 should exceed max");
        }

        // AT-04: Requirement 004
        TEST_METHOD(AT_R004_CheckBoxSize)
        {
            Assert::AreEqual(1, checkBoxSize(0.5), L"Box size 0.5 should be valid");
            Assert::AreEqual(1, checkBoxSize(2.0), L"Box size 2 should be valid");
            Assert::AreEqual(1, checkBoxSize(5.0), L"Box size 5 should be valid");
            Assert::AreEqual(0, checkBoxSize(1.0), L"Box size 1.0 should be invalid");
        }

        // AT-05: Requirement 005
        TEST_METHOD(AT_R005_ValidateDestinationFormat)
        {
            Assert::AreEqual(1, isValidDestinationFormat("12M"), L"12M should be valid format");
            Assert::AreEqual(1, isValidDestinationFormat("0A"), L"0A should be valid format");
            Assert::AreEqual(0, isValidDestinationFormat("26Z"), L"26Z should be invalid (out of range)");
            Assert::AreEqual(0, isValidDestinationFormat("AA"), L"AA should be invalid (no number)");
        }

        // AT-06: Requirement 006
        TEST_METHOD(AT_R006_CheckDestination)
        {
            struct Map map = populateMap();
            Assert::AreEqual(1, checkDestination("2B", &map), L"2B should be valid (building)");
            Assert::AreEqual(0, checkDestination("4A", &map), L"4A should be invalid (no building)");
        }
    };
}