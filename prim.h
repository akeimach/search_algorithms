// ########## CLIENT B / PRIM ######### //
#ifndef __DroneRouting__prim__
#define __DroneRouting__prim__
#include <cmath>
#include <sstream>
#include <iostream>
#include "structs.h"

double weightB(int x1, int y1, int x2, int y2) {
    double x_dist = (double)(x1) - (double)(x2);
    double y_dist = (double)(y1) - (double)(y2);
    double shit = (x_dist * x_dist) + (y_dist * y_dist);
    return sqrt(shit);
}

void Prim(std::vector<prim> &tree, double &final_sum) {
    std::ostringstream os;
    int current, min_prev = 0;
    int min_index = 0;
    double min_distance = 0;
    int trueCounter = 1;
    int size = (int)tree.size();
    while (trueCounter < size) {
        current = min_index;
        min_index = -1;
        min_distance = -1;
        tree[current].visited = true;
        for (std::vector<prim>::iterator next = tree.begin();
             next != tree.end(); ++next) {
            if (!tree[next->ID].visited) {
                double next_dist = weightB(tree[current].X_coord,
                                          tree[current].Y_coord,
                                          tree[next->ID].X_coord,
                                          tree[next->ID].Y_coord);
                if ((tree[next->ID].distance == -1) ||
                    (tree[next->ID].distance > next_dist)) {
                    tree[next->ID].distance = next_dist;
                    tree[next->ID].previous = current;
                }
                if ((min_index == -1) ||
                    (tree[next->ID].distance < min_distance)) {
                    min_index = next->ID;
                    min_prev = tree[next->ID].previous;
                    min_distance = tree[next->ID].distance;
                }
            }
        }
        final_sum += min_distance;
        ++trueCounter;
        if (min_prev > min_index) {
            os << min_index << ' ' << min_prev << '\n';
        }
        else { os << min_prev << ' ' << min_index << '\n'; }
    }
    std::cout << final_sum << std::endl;
    std::cout << os.str();
    return;
}


#endif
