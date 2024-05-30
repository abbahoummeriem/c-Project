
#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct S2d{
    double x,y;
}S2d;
class segment{
protected:

    S2d  base,extr;
    double angle;
    double longueur;
    int indice;
    public:
    segment();
    segment(S2d ,double ,double,int );
    void extrimite();
    int get_indice();
    double get_base_x();
    double get_base_y();
    double  get_extr_x();
    double  get_extr_y();

    S2d get_base();

    S2d get_extr();
    double get_angle();
    double get_longueur();
    void set_indice(int);
    void set_base_x(double);
    void set_base_y(double);
    void  set_extr_x(double);
    void  set_extr_y(double);
    void set_angle(double);
    void set_longueur(double);

    
    
};

double ecart_angulaire(segment A, segment B);
void test_supr(int id, segment A, segment B);
double orientation(segment A, segment B);
bool onSegment(S2d, S2d, S2d);
bool doIntersect(S2d p1, S2d q1, S2d p2, S2d q2);
void test_intr(int, int, segment, segment);




#endif 