
#include "lifeform.h"
#include "message.h"
#include <iostream>
#include <cmath>
using namespace std;
lifeform ::lifeform(double x, double y,int a ){
         point.x=x;
        point.y=y;
        age=a;
    }

lifeform::lifeform(){}
 void lifeform::test_age() {
    if( age <=0){
        cout << message::lifeform_age(age)<<endl;
        exit(EXIT_FAILURE);
    }
}
void lifeform::test_position() {
    if (point.x < 1 || point.y < 1 || point.x > dmax-1 || point.y > dmax-1) {
        cout << message::lifeform_center_outside(point.x,point.y)<<endl;
        exit(EXIT_FAILURE);
    }
}

 int* Corail:: all_ids = new int[7];
 int Corail::incre_id=0;


Corail::Corail(){}
Algue::Algue(){};


Corail::Corail(double x, double y, int a, int d, int s1, int s2, int s3, int nb_s) : lifeform(x, y, a)
{
    id = d;
    all_ids[incre_id] = id;
    incre_id++;
    if (s1 == 0)
        status_cr = Status_cor::DEAD;
    else
        status_cr = Status_cor::ALIVE;
    if (s2 == 0)
        dir_cor = Dir_rot_cor::TRIGO;
    else
        dir_cor = Dir_rot_cor::INVTRIGO;
    if (s3 == 0)
        satut_dv = Status_dev::EXTEND;
    else
        satut_dv = Status_dev::REPRO;
    nb_segment = nb_s;
    segment_list = new segment[nb_segment];
}
 int Corail::get_cr_id(){
    return id;
 }
 int Corail::get_nb_segment(){
    return nb_segment;
 }

void Corail::test_position() {
    if (!(point.x > 0 && point.y > 0 && point.x < dmax && point.y < dmax)) {
        cout << message::lifeform_computed_outside(id,point.x,point.y)<<endl;
        exit(EXIT_FAILURE);
    }
}

void Corail::create_seg(double* AL,double* LO){
    segment a;

    for(int i=0;i<nb_segment;i++){
        if(i == 0){
            segment_list[i].set_angle(AL[i]);
            segment_list[i].set_longueur(LO[i]);
            segment_list[i].set_indice(i);
            segment_list[i].set_base_x(point.x);
            segment_list[i].set_base_y(point.y);

        }

        else {
            segment_list[i].set_angle(AL[i]);
            segment_list[i].set_longueur(LO[i]);
            segment_list[i].set_indice(i);
            segment_list[i].set_base_x(segment_list[i-1].get_base_x());
            segment_list[i].set_base_y(segment_list[i-1].get_base_y());

        }

}}
segment* Corail::getSegment(){
        return segment_list;
        
}



void Corail::test_long(){
   for(int i=0;i<nb_segment;i++){
       if(segment_list[i].get_longueur()<l_repro - l_seg_interne || segment_list[i].get_longueur()>=l_repro){
           cout << message::segment_length_outside(id,segment_list[i].get_longueur())<<endl;
           exit(EXIT_FAILURE);
       }
   }

};
void Corail::test_angl() {
    for (int i = 0; i < nb_segment; i++) {
        if (segment_list[i].get_angle() <= -M_PI || segment_list[i].get_angle() >= M_PI) {
            cout << message::segment_angle_outside(id, segment_list[i].get_angle()) << endl;
            exit(EXIT_FAILURE);
        }
    }
}


int Corail::get_incre_id(){
    return incre_id;
}
int* Corail::get_all_ids(){
    return all_ids;
}


void Corail::duplicated_id( ){
    int k=0;
    for(int i=0;i<incre_id;i++){
        if(all_ids[i]==id){
            k++;
        }
    if(k!=0 && k!=1){
        cout << message::lifeform_duplicated_id(id)<<endl;
        exit(EXIT_FAILURE);
    }
}}

 Algue::Algue(double x, double y,int a ):lifeform(x,y,a){}
Scavenger::Scavenger(){}
Scavenger::Scavenger(double x,double y,int a,double r,int stat,int id):lifeform(x,y,a){
if (stat == 0)
        status = Status_sca::LIBRE;
    else
        status = Status_sca::MANGE; 
        id_mem=id;
        rayon=r;
           } 
void  Scavenger::test_rayon(){
    if (!(rayon>=r_sca  && rayon<r_sca_repro)){
    cout << message::scavenger_radius_outside(rayon)<<endl;
    exit(EXIT_FAILURE);}
}


void Scavenger::invalid_id(){
    int k=0;
    Corail a;
    int* T=a.get_all_ids();

    for(int i=0;i<a.get_incre_id();i++){
        if(T[i]==id_mem){
            k++;
        }
    if(k==0){
        cout << message::lifeform_invalid_id(id_mem)<<endl;
        exit(EXIT_FAILURE);
    }
}

}


    


