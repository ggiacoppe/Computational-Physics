// MC SIM for electrons
//Program runs a MC sim for individual high energy electrons traversing matter of Xe,Ar, and Water.

#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <random>



using namespace std;



   
double PI = 3.14159265359;

        double xeestar(double logE) {
            return 0.078004 + 0.0352622 * logE + 0.29705 * pow(logE, 2.) - 0.0038031 * pow(logE, 3.) - 0.012446 * pow(logE, 4.) + 0.001775 * pow(logE, 5.);
        }


        double arestar(double logE) {
            return 0.14782 - 0.068224 * logE + 0.24424 * pow(logE, 2.) - 0.01486 * pow(logE, 3.) - 0.0069073 * pow(logE, 4.) + 0.0023259 * pow(logE, 5.);
        }


        double waterestar(double logE) {
            return 0.27047 -0.12384 * logE + 0.200242 * pow(logE, 2.) - 0.0024512 * pow(logE, 3.) - 0.0033129* pow(logE, 4.) + 0.0029193* pow(logE, 5.);
        }

        double rand_uniform(long rand_int) {
            return double(rand_int) / (double)RAND_MAX;
        }

        double rand_Gaussian(double u, double v) { // variation in the mean dE / dx curve
            return sqrt(-2 * log(u)) * cos(2*PI*v);
        }

        double rand_exp(double mfp) { // how far an electron of a given energy travels
            return -mfp * log(rand_uniform(rand()));
        }



        int main()

        {
            string substance;
            double keV, rho, xedEOdxR, xeenergy, mfp, xedistance, ardistance, waterdistance, xedE0dx, ardEOdx, waterdEOdx, xemfp, armfp, watermfp, ar_dEOdxR, water_dEOdxR, waterenergy,arenergy;
            cout << "Enter a substance: ";
            cin >> substance;
            cout << "Enter an energy (keV): ";
            cin >> keV;
            cout << "Enter a density: "; 
            cin >> rho;



            
        if (rho == 2.90)
        {
           // srand(time(NULL));
            for (long i = 0; i < 1e4L; i++) {

                xeenergy = keV;
                xedistance = 0.0; // cm
                while (xeenergy > 1.) {
                    xedEOdxR = pow(10., xeestar(log10(xeenergy))) * rho; //keV*cm^2/g times density = keV/cm
                    xedEOdxR = xedEOdxR * (1. + 0.20 * rand_Gaussian(rand_uniform(rand()), rand_uniform(rand())));
                    xemfp = 0.1 * (xeenergy / xedEOdxR);
                    xemfp = rand_exp(xemfp);
                    xedistance += xemfp;
                    xeenergy -= xedEOdxR * xemfp;
                }
                cout << xedistance << endl; // total track length

            }
        }
        else if (rho == 1.40) {
            //srand(time(NULL));
            for (long i = 0; i < 1e4L; i++) {

                arenergy = keV;
                ardistance = 0.0; // cm
                while (arenergy > 1.) {
                    ardEOdx = pow(10., arestar(log10(arenergy))) * rho; //keV*cm^2/g times density = keV/cm
                    ar_dEOdxR = ardEOdx * (1. + 0.20 * rand_Gaussian(rand_uniform(rand()), rand_uniform(rand())));
                    armfp = 0.1 * (arenergy / ar_dEOdxR);
                    armfp = rand_exp(armfp);
                    ardistance += armfp;
                    arenergy -= ar_dEOdxR * armfp;
                }
                cout << ardistance << endl; // total track length

            }
        }
           

        else if (rho == 1.00) {
            //srand(time(NULL));
            for (long i = 0; i < 1e4L; i++) {

                waterenergy = keV;
                waterdistance = 0.0; // cm
                while (waterenergy > 1.) {
                    waterdEOdx = pow(10., waterestar(log10(waterenergy))) * rho; //keV*cm^2/g times density = keV/cm
                    water_dEOdxR = waterdEOdx * (1. + 0.20 * rand_Gaussian(rand_uniform(rand()), rand_uniform(rand())));
                    watermfp = 0.1 * (waterenergy / water_dEOdxR);
                    watermfp = rand_exp(watermfp);
                    waterdistance += watermfp;
                    waterenergy -= water_dEOdxR * watermfp;
                }
                cout << waterdistance << endl; // total track length

            }
        }

 else if (rho != 2.90 || rho != 1.40 || rho !=1.00) {
               cout << "error" << endl;
           }

     return 0;

        }


