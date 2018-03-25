#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;

double rumusAI (double x1, double x2){
    double a = pow(x1,2);
    double b = pow(x1,4);
    double c = pow(x2,2);
    double temp1 = ((4 - (2.1*a)+(b/3))*a);
    double temp2 = ((-4 + (4*c))*c);
    return (temp1 + temp2 + (x1*x2));
}

int main()
{
    double random;
    srand(time(0));
    cout << endl << endl << "       ===============================================================================" << endl;
    cout<< "                                    TUGAS PROGRAM AI " << endl;
    cout << "       ===============================================================================" << endl <<endl;
    double finalx1 = (rand() / (double)RAND_MAX)* ( 10 - (-10)) + (-10);
    double finalx2 = (rand() / (double)RAND_MAX)* ( 10 - (-10)) + (-10);
    double templastlama = rumusAI(finalx1,finalx2);
    double TitikDidih = 10000000000;
    double TitikBeku = 1;
    double TitikDown = 0.999987776678889;
    int i = 1;
    while (TitikDidih > TitikBeku) {

        double x1 = (rand() / (double)RAND_MAX)* ( 10 - (-10)) + (-10);
        double x2 = (rand() / (double)RAND_MAX)* ( 10 - (-10)) + (-10);


        double templastbaru = rumusAI(x1,x2);

        if (templastbaru <= templastlama) {
            finalx1 = x1;
            finalx2 = x2;
            templastlama = templastbaru;
        }
        else {
            random = (rand() / (double)RAND_MAX)* ( 1 - 0) + (0);

            double deltaE = templastbaru - templastlama;
            double xx = (-(deltaE) / TitikDidih);
            double prob = pow((2.71828183),xx);
            if (prob>random) {
                finalx1 = x1;
                finalx2 = x2;
            }
        }
        TitikDidih = TitikDidih*TitikDown;
        i = i+1;
    }

    cout << "           Hasil : " << templastlama << endl;
   // cout << random << endl;
    cout << "           Nilai x1 : " << finalx1 << endl;
    cout << "           Nilai x2 : " << finalx2 << endl;
    cout << "           Banyak perulangan : " << i << endl;
    }
