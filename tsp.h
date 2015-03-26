// ######## CLIENT C / BRUTE-FORCE ######## //
#ifndef __DroneRouting__tsp__
#define __DroneRouting__tsp__
#include <cmath>
#include <sstream>
#include <iostream>
#include "structs.h"

double weight(int x1, int y1, int x2, int y2) {
    double x_dist = (double)(x1) - (double)(x2);
    double y_dist = (double)(y1) - (double)(y2);
    double shit = (x_dist * x_dist) + (y_dist * y_dist);
    return sqrt(shit);
}

void Brute(std::vector<vertex> &path, std::queue<vertex> &coords,
                       std::vector<int> &final_tsp, double &final_sum) {
    if (coords.empty()) {
        int path_size = (int)path.size();
        std::vector<int> curr;
        curr.resize(path_size);
        curr[0] = path[0].ID;
        double sum = weight(path[0].X_coord, path[0].Y_coord,
                            path[path_size-1].X_coord,
                            path[path_size-1].Y_coord);
        for (int i = 1; i < path_size; ++i) {
            sum += weight(path[i-1].X_coord, path[i-1].Y_coord,
                                path[i].X_coord,
                                path[i].Y_coord);
            curr[i] = path[i].ID;
        }
        if ((final_sum == 0) || (sum < final_sum)) {
            final_sum = sum;
            final_tsp = curr;
        }
    }
    for (int i = 0; i < (int)coords.size(); ++i) {
        path.push_back(coords.front());
        coords.pop();
        Brute(path, coords, final_tsp, final_sum);
        coords.push(path.back());
        path.pop_back();
    }
    return;
}


#endif