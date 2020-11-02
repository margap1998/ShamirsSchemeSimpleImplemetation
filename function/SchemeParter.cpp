//
// Created by mg on 01.11.2020.
//

#include "SchemeParter.h"
#include "functions.h"
#include <sstream>
#include <random>
#include <functional>

std::vector<std::pair<int, long>> SchemeParter::part(int secret, ILog *wind) const{
    return part(secret,11,wind);
}

SchemeParter::SchemeParter() = default;

SchemeParter::SchemeParter(int c_n, int c_t) {
    n = c_n;
    t = c_t;
}

std::vector<std::pair<int, long>> SchemeParter::part(int secret, long in_p, ILog *wind) const {
    std::random_device rd;

    std::vector<std::pair<int, long>> r(n);
    if (secret>=in_p){wind->addToLog("//Secret bigger then prime number//"); throw std::exception();}
    else if(!is_prime(in_p)){wind->addToLog("//The number is not prime//"); throw std::exception();}
    std::vector<int> wsp;
    std::stringstream str;
    long tmp = 0;
    wsp.push_back(secret);
    for(int i=1; i<t; i++){
        tmp = rd()%999+2;
        str<<"Wylosowano stopień "<<i<<":"<<tmp;
        wsp.push_back(tmp);
        wind->addToLog(str.str().c_str());
        str.str("");
    }
    for (int x=1; x<=n;x++){
        tmp = 0;
        str<<"zaczynamy liczyć udział s("<<x<<"):"<<"\n";
        for (long a=0; a<t; a++){
            tmp += (long)(wsp.at(a)*(std::pow(x,a)));
        }
        str<<"Wyliczono udział s("<<x<<"):"<<tmp;
        r[x-1].first = x;
        r[x-1].second = tmp%in_p;
        wind->addToLog(str.str().c_str());
        str.str("");
    }
    return r;
}


