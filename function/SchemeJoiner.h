//
// Created by mg on 02.11.2020.
//

#ifndef UNTITLED1_SCHEMEJOINER_H
#define UNTITLED1_SCHEMEJOINER_H
#include <vector>
#include "ILog.h"

class SchemeJoiner {
    int t{3};
    long p{23};
public:
    SchemeJoiner();
    SchemeJoiner(int c_t,long c_p):t(c_t),p(c_p){};
    long joinShares(std::vector<std::pair<int, long>> &points, ILog *wind) const;
};


#endif //UNTITLED1_SCHEMEJOINER_H
