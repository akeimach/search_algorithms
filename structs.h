//#########ALL STRUCTS FOR INPUT#########//
#ifndef DroneRouting_structs_h
#define DroneRouting_structs_h
#include <queue>
#include <vector>
#include <cmath>

struct vertex {
    int X_coord, Y_coord, ID;
};

struct makeSet {
    int p;
    int rank;
};

struct clientA {
    int from_ID, to_ID;
    double distance;
    bool operator() (const struct clientA A,
                     const struct clientA B) const {
        return A.distance > B.distance;
    }
};

struct prim {
    bool visited = false;
    int ID = -1;
    int previous = -1;
    int X_coord, Y_coord;
    double distance = -1;
};





#endif