//
// Created by mg on 01.11.2020.
//

#ifndef UNTITLED1_SCHEMEPARTER_H
#define UNTITLED1_SCHEMEPARTER_H


#include <vector>
#include "ILog.h"

class SchemeParter {

private:
    int n{5};
    int t{3};
    long p{23};
public:
    SchemeParter();
    SchemeParter(int c_n, int c_t);
    std::vector<std::pair<int,long>> part(int secret,ILog *wind) const;
    std::vector<std::pair<int,long>> part(int secret, long in_p, ILog *wind) const;
};

#endif //UNTITLED1_SCHEMEPARTER_H
