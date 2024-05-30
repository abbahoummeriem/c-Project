#ifndef LIFEFORM_H_INCLUDED
#define LIFEFORM_H_INCLUDED

#include "shape.h"
#include "constantes.h"

class lifeform {
protected:
    S2d point ; // Position de l'entité
    int age; // Âge de l'entité
public:
lifeform(double x, double y,int a );  
lifeform();
void test_age();
void test_position();
};
class Algue: public lifeform {
public : 
     Algue();
     Algue(double x, double y,int a );
};
class Corail:public lifeform{
enum Dir_rot_cor dir_cor;
enum Status_dev satut_dv;
enum Status_cor  status_cr;
int id;
static int* all_ids;
static int incre_id;
int nb_segment;
segment *segment_list;
public:
Corail();
Corail(double x, double y,int a,int d,int s1,int s2,int s3,int nb_s);
void create_seg(double*,double*);
int get_nb_segment();
int get_cr_id();
void test_long();
void test_angl();
segment* getSegment();
void test_position();
int get_incre_id();
int* get_all_ids();
void duplicated_id();

};
class Scavenger:public lifeform{
    private:
    int id_mem;
    Status_sca status;
    double rayon;
    public:
    Scavenger();
    Scavenger(double,double,int,double,int,int);
    void test_rayon();
    void invalid_id();
};

#endif 
