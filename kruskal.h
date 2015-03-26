// ######## CLIENT A / KRUSKAL ######## //
#ifndef __DroneRouting__kruskal__
#define __DroneRouting__kruskal__
#include <cmath>
#include <sstream>
#include <iostream>
#include "structs.h"


int findSet(std::vector<makeSet> &links, int x) {
    if (x != links[x].p) {
        links[x].p = findSet(links, links[x].p);
    }
    return links[x].p;
}

void unions(std::vector<makeSet> &links, int x, int y) {
    int x_id = findSet(links, x);
    int y_id = findSet(links, y);
    links[y_id].p = x_id;
}

void Kruskal(std::priority_queue<clientA, std::vector<clientA>,
             clientA> &forest, std::vector<makeSet> &links,
             double &final_sum) {
    std::ostringstream os;
    int counter = 0;
    int size = (int)links.size();
    while (counter < size) {
        clientA shortest = forest.top();
        forest.pop();
        int x = findSet(links, shortest.from_ID);
        int y = findSet(links, shortest.to_ID);
        if (x != y) {
            
            final_sum += shortest.distance;
            unions(links, x, y);
            os << shortest.from_ID << ' ' << shortest.to_ID << '\n';
        }
        ++counter;
    }

    std::cout << final_sum << std::endl;
    std::cout << os.str();
    return;
}


#endif