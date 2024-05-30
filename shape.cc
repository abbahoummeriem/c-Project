
#include "shape.h"
#include "constantes.h"
#include <iostream>
#include <cmath>
#include "message.h"
using namespace std;

segment::segment(S2d p, double a, double l, int i)
{
    base = p;
    angle = a;

    longueur = l;
  
    indice = i;
 
    this->extrimite();
};
double segment::get_base_x()
{
    return base.x;
}
int segment::get_indice(){return indice;}
segment::segment(){};

double segment::get_base_y()
{
    return base.y;
}

double segment::get_extr_x()
{
    return extr.x;
}
double segment::get_extr_y()
{
    return extr.y;
}
double segment::get_angle()
{
    return angle;
}
double segment::get_longueur()
{
    return longueur;
}
void segment::set_indice(int i){
    indice = i;
}
void segment::set_base_x(double x){
    base.x = x;
}
void segment::set_base_y(double y){
    base.y = y;
}

void segment::set_angle(double a){
    angle = a;
}
void segment::set_longueur(double l){
    longueur = l;
}
S2d segment::get_base() { return base; };
S2d segment::get_extr() { return extr; };



void segment::extrimite()
{
    extr.x = base.x + longueur * cos(this->angle);
    extr.y = base.y + longueur * cos(this->angle);
}


double ecart_angulaire(segment A, segment B) {

    S2d sg_a = {A.get_extr_x() - A.get_base_x(), A.get_extr_y() - A.get_base_y()};
    S2d sg_b = {B.get_extr_x() - B.get_base_x(), B.get_extr_y() - B.get_base_y()};

    double scalaire = sg_a.x * sg_b.x + sg_a.y * sg_b.y;
    double norm_a = sqrt(sg_a.x * sg_a.x + sg_a.y * sg_a.y);
    double norm_b = sqrt(sg_b.x * sg_b.x + sg_b.y * sg_b.y);

    double result = scalaire / (norm_a * norm_b);
    
    double angle = acos(result);
    
    return angle;
}

void test_supr(int id, segment A, segment B)
{    
	if  (ecart_angulaire(A, B) < epsil_zero)
	{
		cout << message::segment_superposition(id, A.get_indice(), B.get_indice()) << endl;
		exit(EXIT_FAILURE);

	}
}


bool OnSegment(const S2d p1, const S2d p2, const S2d q) {
    S2d pr = {p2.x - p1.x, p2.y - p1.y};
    S2d pq = {q.x - p1.x, q.y - p1.y};
    double p_s = pr.x * pr.x + pr.y * pr.y;
    double pq_nor = pq.x * pr.x + pq.y * pr.y;
    double x = pq_nor / p_s;

    return (x >= -epsil_zero && x <= pq_nor + epsil_zero);
}


int orientation(S2d p, S2d q, S2d r) 
{ 
	// S2d pr = {p.x - q.x, p.y - q.y};
    // S2d pq = {q.x - q.x, q.y - q.y};
    // double val = ((q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y)) / (pq.x * pq.x + pq.y * pq.y);
       double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val <= epsil_zero )
        return 0;
    
    return 1;
}



bool doIntersect(S2d p1, S2d q1, S2d p2, S2d q2) 
{ 
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
    if (o1 != o2 && o3 != o4) return true; 
  
    if (o1 == 0  && OnSegment(p1, p2, q1)) return true; 
  
    if (o2 == 0  && OnSegment(p1, q2, q1)) return true; 
  
    if (o3 == 0  && OnSegment(p2, p1, q2)) return true; 
  
    if (o4 == 0  && OnSegment(p2, q1, q2)) return true; 
  
    return false;  
} 



void test_intr(int id1, int id2, segment A, segment B)
{
	if (doIntersect(A.get_base(), A.get_extr(), B.get_base(), B.get_extr()) == true)
	{
		cout << message::segment_collision(id1, A.get_indice(), id2, B.get_indice()) << endl;
		exit(EXIT_FAILURE);
	}
}