#include "function/MainProgram.h"

int main(int argc, char **argv) {
    MainProgram mp;
    mp.run(argc,argv);
    return Fl::run();
}