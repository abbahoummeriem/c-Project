#include <iostream>
#include <fstream>
#include <string>
#include "message.h"
#include "lifeform.h"
#include "simulation.h"
#include "shape.h"
#include "message.cc"
#include "lifeform.cc"
#include "simulation.cc"
#include "shape.cc"
using namespace std;
int main()
{
    ifstream file("t11.txt");
    simulation a;
    a.lecture(file);
    return 0;
}