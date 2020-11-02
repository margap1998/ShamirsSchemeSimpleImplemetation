//
// Created by mg on 02.11.2020.
//

#include "SchemeJoiner.h"
#include "functions.h"
#include <cstring>
#include <cstdio>

SchemeJoiner::SchemeJoiner() = default;

long SchemeJoiner::joinShares(std::vector<std::pair<int, long>> &points,ILog *wind = nullptr) const {
    long res = 0;
    char buf[255];
    std::vector<int> xCoords(points.size());
    int sizePoints = points.size();
    for (int i=0;i<sizePoints;i++){
        xCoords[i] = points[i].first;
    }
    if (!is_prime(p)) {wind->addToLog("Not prime\n"); throw std::exception(); }
    sprintf(buf,"Only %d points\n",t);
    if(sizePoints!=t) {wind->addToLog(buf); throw std::exception(); }
    int tmp;
    for (auto pair:points){
        sprintf(buf,"Computing factors for (%d, %ld)",pair.first,pair.second);
        wind->addToLog(buf);
        auto fact = polymonLagrange(xCoords,pair.first,sizePoints,&tmp);
        res += (long)(pair.second * fact[sizePoints-1]);
    }
    res = res%p;
    if (res<0) res = p+res;
    return res;
}
