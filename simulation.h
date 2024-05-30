#ifndef SUMILATION_H_INCLUDED
#define SUMILATION_H_INCLUDED
#include <fstream>
using namespace std;

class simulation {
    int nb_cor,nb_alg,nb_sca;
    public:
    void lecture(ifstream &);
    
};
#endif