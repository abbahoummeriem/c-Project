
#include "lifeform.h"
#include "message.h"
#include "simulation.h"
#include <fstream>

using namespace std;
void simulation::lecture(ifstream &f)
{
    double x, y, r;
    int ag, d, s1, s2, s3, nb_s;

    f >> nb_alg;
    Algue *alg = new Algue[nb_alg];
    for (int i = 0; i < nb_alg; i++)
    {
        f >> x;
        f >> y;
        f >> ag;
        Algue a(x, y, ag);
        alg[i] = a;
    }

    f >> nb_cor;
    Corail *cor = new Corail[nb_cor];
    for (int i = 0; i < nb_cor; i++)
    {
        f >> x;
        f >> y;
        f >> ag;
        f >> d;
        f >> s1;
        f >> s2;
        f >> s3;
        f >> nb_s;
        Corail a(x, y, ag, d, s1, s2, s3, nb_s);
        cor[i] = a;
        double *an = new double[nb_s];
        double *lo = new double[nb_s];
        for (int i = 0; i < nb_s; i++)
        {
            f >> an[i];
            f >> lo[i];
        }
        a.create_seg(an, lo);
    }

    f >> nb_sca;
    Scavenger *sca = new Scavenger[nb_sca];
    for (int i = 0; i < nb_sca; i++)
    {
        f >> x;
        f >> y;
        f >> ag;
        f >> r;
        f >> s1;
        f >> d;
        Scavenger a(x, y, ag, r, s1, d);
        sca[i] = a;
    }
    for (int i = 0; i < nb_alg; i++)
    {

        alg[i].test_age();

        alg[i].test_position();
    }
    for (int i = 0; i < nb_cor; i++)
    {

        cor[i].test_age();
        cor[i].test_position();

        cor[i].test_angl();
        cor[i].test_long();
        cor[i].duplicated_id();

        segment *s = cor[i].getSegment();
        for (int o = 0; o < nb_s - 1; o++)
        {
           test_supr(cor[i].get_cr_id(), s[o], s[o + 1]);
        }

        
       
        for (int j = 0; j < cor[i].get_nb_segment(); j++)
        {
            for (int k = 0; k < nb_cor; k++)
            {
                segment *se = cor[k].getSegment();
                for (int n = 0; n < cor[k].get_nb_segment(); n++)
                {
                    if (cor[k].get_cr_id() != cor[i].get_cr_id() || s[j].get_indice() != se[n].get_indice())
                        test_intr(cor[i].get_cr_id(), cor[k].get_cr_id(), s[j], s[n]);
                }
            }
        }
    }
    

    for (int i = 0; i < nb_sca; i++)
    {

        sca[i].test_age();
        sca[i].test_position();
        sca[i].invalid_id();
        sca[i].test_rayon();
    }

    cout << message::success() << endl;
}