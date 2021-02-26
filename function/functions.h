//
// Created by mg on 02.11.2020.
//

#ifndef UNTITLED1_FUNCTIONS_H
#define UNTITLED1_FUNCTIONS_H

#include <sstream>
/**
 *
 * @param num - number to check
 * @return Answer, if the number is prime
 */
inline bool is_prime(long num){
    long i;
    bool prime = false;
    if (num>1) prime = true;
    long lim = num/2;
    if(num>3)
        for (i=2;i<lim && prime;i++){
            prime = (num % i != 0);
            if (!prime) i = lim+1;
        }
    return prime;
}
/**
 * Computes interpolation polymon for x_0 = q and vector "points"
 * @param points - vector of points to
 * @param q - point
 * @param length - length of result polymon
 * @param divider
 * @return vector of factors
 */
inline std::vector<double> polynomialLagrange(std::vector<int> &points,int q, int length,int *divider){

    std::vector<double>factors(length);
    factors[0] = 1;
    int b = 1;//index of last cell
    *divider=1;
    //multiplying
    //partial_result_0 = 1
    //partial_result_n = partial_result_(n-1) * (x - x_(n-1))
    for(int x_0:points){
        if(x_0!=q){
            for (int i=b; i>0; i-- ){
                factors[i]+=factors[i-1]*(-x_0);
            }
            (*divider)*=(q-x_0);
            b++;
        }
    }
    for (int i=0;i<length;i++){
        factors[i]= factors[i] / *divider;
    }
    return factors;
}
//function that display polynomial
inline void polyString(std::vector<double> &po, char* _dest){
    int size = po.size();
    sprintf(_dest,"%lf x^%d",po[0],size-1);
    for (int i=size-1;i>1; i--){
        if (po[size - i]<0) {
            sprintf(_dest, "%s - %lf x^%d", _dest, std::abs(po[size - i]), i - 1);
        }else if (po[size - i]>0){
            sprintf(_dest,"%s + %lf x^%d",_dest,std::abs(po[size - i]), i - 1);
        }
    }
}

#endif //UNTITLED1_FUNCTIONS_H
