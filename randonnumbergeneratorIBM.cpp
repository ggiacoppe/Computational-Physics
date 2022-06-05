
// Random Number Generator 
// Program compares number generator versus IBMs.

#include <iostream>
#include "stdio.h"
#include "stdlib.h" 
#include "math.h"
#include "string.h" 
#include <fstream>

using namespace std;
double rand_uniform(long rand_r); 
double randU();
int iseed = 6;

int main(int argc, char** argv) {

    ofstream myfile; //much easier than in C
    myfile.open("example_output.dat", ios::app); //must open and name it (myfile is var name)
   
        for (int i = 0; i < 10000; i++) {
            double randuni1 = rand_uniform(rand());
            double randIBM2 = randU();
            // myfile << randuni1 << "\t";
              myfile << randIBM2 << "\t";
            

            
            char digitfreq[9];
            
            //sprintf(digitfreq, "%.6f", randuni1);
            //myfile<< digitfreq[2] << "\t" << digitfreq[3] << "\t" << digitfreq[4] << "\t" << digitfreq[5] << "\t " << digitfreq[5] << "\t " << digitfreq[6] << "\t" << digitfreq[7] << endl;
             //sprintf(digitfreq, "%.6f", randIBM2);
              myfile << digitfreq[2] << "\t" << digitfreq[3] << "\t" << digitfreq[4] << "\t" << digitfreq[5] << "\t" << digitfreq[5] << "\t" << digitfreq[6] << "\t" << digitfreq[7] << endl;
             
        }
        myfile.close();
        int count[10] = { 0,0,0,0,0,0,0,0,0,0 };
        for (int i = 0; i < 10000; i++) {

            double randIBM2interval = fabs(randU());//distribution(generator);
            
            if (randIBM2interval >= 0.0 && randIBM2interval < 0.1) count[0]++;
            else if (randIBM2interval >= 0.1 && randIBM2interval < 0.2) count[1]++;
            else if (randIBM2interval >= 0.2 && randIBM2interval < 0.3) count[2]++;
            else if (randIBM2interval >= 0.3 && randIBM2interval < 0.4) count[3]++;
            else if (randIBM2interval >= 0.4 && randIBM2interval < 0.5) count[4]++;
            else if (randIBM2interval >= 0.5 && randIBM2interval < 0.6) count[5]++;
            else if (randIBM2interval >= 0.6 && randIBM2interval < 0.7) count[6]++;
            else if (randIBM2interval >= 0.7 && randIBM2interval < 0.8) count[7]++;
            else if (randIBM2interval >= 0.8 && randIBM2interval < 0.9) count[8]++;
            else
                count[9]++;
           // cout << randIBM2interval << endl;
        }
    
        int count1[10] = { 0,0,0,0,0,0,0,0,0,0 };
        for (int i = 0; i < 10000; i++) {

            double randuniInterval1 = rand_uniform(rand()); //distribution(generator);
            // cout << randuniInterval1<< endl;
            if (randuniInterval1 >= 0.0 && randuniInterval1 < 0.1) count[0]++;
            else if (randuniInterval1 >= 0.1 && randuniInterval1 < 0.2) count[1]++;
            else if (randuniInterval1 >= 0.2 && randuniInterval1 < 0.3) count[2]++;
            else if (randuniInterval1 >= 0.3 && randuniInterval1 < 0.4) count[3]++;
            else if (randuniInterval1 >= 0.4 && randuniInterval1 < 0.5) count[4]++;
            else if (randuniInterval1 >= 0.5 && randuniInterval1 < 0.6) count[5]++;
            else if (randuniInterval1 >= 0.6 && randuniInterval1 < 0.7) count[6]++;
            else if (randuniInterval1 >= 0.7 && randuniInterval1 < 0.8) count[7]++;
            else if (randuniInterval1 >= 0.8 && randuniInterval1 < 0.9) count[8]++;
            else
                count[9]++;
            // cout << randuniInterval1<< endl;
        }





   
    return 0;
}
    


    double rand_uniform(long rand_int) {

        return double(rand_int) / (double)RAND_MAX;

    }

    double randU() {

        long imax = 2147483647;
        double xmax_inv = 1. / double(imax);
        iseed *= 65539;
        if (iseed < 0)
            iseed += imax + 1;
        double x = double(iseed) * xmax_inv;
        return x;

    }
    