// Draft-Program to compute age of the universe & various 4 cases
// Goal: Fix this as it the output age is off by a magnitude of 5.

#include "stdio.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include "string.h"
#include "float.h"

double pi = 3.14159265359;
using namespace std;

double  rk4(double H0, double omegam0, double omegar0, double omegalamda0, double omegak0, double p, double a)
{
	double da0dt = (H0 * sqrt(omegam0 / a + omegar0 / a + omegalamda0 * pow(a, 2 + p + omegak0)));
	return da0dt; //returns scalefactor of a (first deriv).
}

int main() {

	// VAR DECL.
	double omegalamda0 = 0.6892;
	double omegar0 = 0.0000924;
	double omegam0 = 0.3089;
	double omegak0 = (1. - (omegam0 + omegalamda0 + omegar0));
	double H0 = 67.7 * 3.240779270005395e-20 * 3.154e7; //conv. of units 67.7 * (1 / 10e6) * (1 / 3.26) * (10e3) * (1 / 9.461e+15) * (1 / (3.1557 * 10e7)); // in years (km/Mpc)
	double s = 1e7; // time step 
	double t = 1.7095e-51;
	double x0 = 0;
	double w = -1.006;
	double p = -3. * (1. + w);
	double k1, k2, k3, k4;
	double da0dtinitial = 1e-3;
	double da0dtf;
	double H = 0.001;
	double spacetimemetric;
	double z;
	
	for (int i = 1; i <= s; i++)
	{
		k1 = H * rk4(H0, omegam0, omegar0, omegalamda0, omegak0, p, da0dtinitial);
		k2 = H * rk4(H0, omegam0, omegar0, omegalamda0, omegak0, p, da0dtinitial + (k1 * (s / 2.)));
		k3 = H * rk4(H0, omegam0, omegar0, omegalamda0, omegak0, p, da0dtinitial + (k2 * (s / 2.)));
		k4 = H * rk4(H0, omegam0, omegar0, omegalamda0, omegak0, p, da0dtinitial + k3 * (s));
		da0dtf = da0dtinitial + (s / 6.0) * (k1 + 2. * k2 + 2. * k3 + k4);

		if (da0dtf >= 1.0 +0.001) {
			break;
			
		}
		
		
		t = t + s; // reinit t and s
		s = s * 1.001;
		
		
		printf("%e\t%.20f\n", t, da0dtf);
		// ON MY CODE  THE AGE OF THE UNI output: 3.517278e+15 in years (km/Mpc)  1.00092758524938951759

		spacetimemetric = (omegam0 / k3 + omegar0 / k4 + omegalamda0 * pow(k1, p) + omegak0 / pow(k1, 2));
		z = 1 / (k1 - 1);
		//printf("%e\t%.20f\n", spacetimemetric,da0dtf);
		//printf("%e\t%.20f\n",t,z);

	}


// RK 4th order. Four Possible Cases.

//CASE 1: (cold, slow) matter
	double w1 = 0;
	double p1 = -3. * (1. + w1);
	for (int i = 1; i <= s; i++)
	{
		k1 = H0 * rk4(H0, omegam0, omegar0, omegalamda0, omegak0, p1, da0dtinitial);
		k2 = H0 * rk4(H0, omegam0, omegar0, omegalamda0, omegak0, p1, da0dtinitial + (k1 * (s / 2.)));
		k3 = H0 * rk4(H0, omegam0, omegar0, omegalamda0, omegak0, p1, da0dtinitial + (k2 * (s / 2.)));
		k4 = H0 * rk4(H0, omegam0, omegar0, omegalamda0, omegak0, p1, da0dtinitial + k3 * (s));
		da0dtf = da0dtinitial + (s / 6.0) * (k1 + 2. * k2 + 2. * k3 + k4);

		if (da0dtf >= 1.0 + 0.001) {
			break;

		}
		t = t + s;
		s = s * 1.001;

		//printf("%e\t%.20f\n", t, da0dtf);

			spacetimemetric = (omegam0 / k3 + omegar0 / k4 + omegalamda0 * pow(k1, p1) + omegak0 / pow(k1, 2));
			z = 1 / (k1 - 1);
		//printf("%e\t%.20f\n", spacetimemetric, da0dtf);
		printf("%e\t%.20f\n",t,z);
	}

//  CASE 2: Relativistic Matter (radiation)
	double w2 = 1/3;
	double p2 = -3 * (1 + w2);
	for (int i = 1; i <= s; i++)
	{
		k1 = H0 * rk4(H0, omegam0, omegar0, omegalamda0, omegak0, p2, da0dtinitial);
		k2 = H0 * rk4(H0, omegam0, omegar0, omegalamda0, omegak0, p2, da0dtinitial + (k1 * (s / 2.)));
		k3 = H0 * rk4(H0, omegam0, omegar0, omegalamda0, omegak0, p2, da0dtinitial + (k2 * (s / 2.)));
		k4 = H0 * rk4(H0, omegam0, omegar0, omegalamda0, omegak0, p2, da0dtinitial + k3 * (s));
		da0dtf = da0dtinitial + (s / 6.0) * (k1 + 2. * k2 + 2. * k3 + k4);

		if (da0dtf >= 1.0 + 0.001) {
			break;

		}
		t = t + s;
		s = s * 1.001;

			spacetimemetric = (omegam0 / k3 + omegar0 / k4 + omegalamda0 * pow(k1, p2) + omegak0 / pow(k1, 2));
			z = 1 / (k1 - 1);
		//cout << spacetimemetric << "\t" << da0dtf << endl;
		printf("%e\t%.20f\n",t,z);
	}
	
// CASE 3: Intrinsic curvature of space-time
	double w3 = -1 / 3;
	double p3 = -3 * (1 + w3);
	for (int i = 1; i <= s; i++)
	{
		k1 = H0 * rk4(H0, omegam0, omegar0, omegalamda0, omegak0, p3, da0dtinitial);
		k2 = H0 * rk4(H0, omegam0, omegar0, omegalamda0, omegak0, p3, da0dtinitial + (k1 * (s / 2.)));
		k3 = H0 * rk4(H0, omegam0, omegar0, omegalamda0, omegak0, p3, da0dtinitial + (k2 * (s / 2.)));
		k4 = H0 * rk4(H0, omegam0, omegar0, omegalamda0, omegak0, p3, da0dtinitial + k3 * (s));
		da0dtf = da0dtinitial + (s / 6.0) * (k1 + 2. * k2 + 2. * k3 + k4);

		if (da0dtf >= 1.0 + 0.001) {
			break;

		}
		t = t + s;
		s = s * 1.001;


		 spacetimemetric = (omegam0 / k3 + omegar0 / k4 + omegalamda0 * pow(k1, p3) + omegak0 / pow(k1, 2));
		z = 1 / (k1 - 1);
		cout << spacetimemetric << "\t" << da0dtf << endl; 
		printf("%e\t%.20f\n",t,z);
	} 
	

// Case 4: Dark Energy
	double w4 = -1;
	double p4 = -3 * (1 + w4);
	for (int i = 1; i <= s; i++)
	{
		k1 = H0 * rk4(H0, omegam0, omegar0, omegalamda0, omegak0, p4, da0dtinitial);
		k2 = H0 * rk4(H0, omegam0, omegar0, omegalamda0, omegak0, p4, da0dtinitial + (k1 * (s / 2.)));
		k3 = H0 * rk4(H0, omegam0, omegar0, omegalamda0, omegak0, p4, da0dtinitial + (k2 * (s / 2.)));
		k4 = H0 * rk4(H0, omegam0, omegar0, omegalamda0, omegak0, p4, da0dtinitial + k3 * (s));
		da0dtf = da0dtinitial + (s / 6.0) * (k1 + 2. * k2 + 2. * k3 + k4);


		if (da0dtf >= 1.0 + 0.001) {
			break;

		}
		t = t + s;
		s = s * 1.001;


			spacetimemetric = (omegam0 / k3 + omegar0 / k4 + omegalamda0 * pow(k1, p4) + omegak0 / pow(k1, 2));
			 z = 1 / (k1 - 1);
		//cout << spacetimemetric << "\t" << da0dtf << endl;
		printf("%e\t%.20f\n",t,z);

	} 


	// VAR DECL. for EULER comparison
	double theta = (15 * pi / 180); double thetap = 0; double dtheta;
	double thetaf; double thetapf;
	double G=9.8;  double L=1.;
	double t0 = 0; double tmax = 20. // we don't know the max time of the uni if we don't look at rk4??  
	double t1;  double y0 = (2 * pi);
	double F0 = (t0 + y0 + t0 * y0); //double F(t0, y0) = (t0 + y0 + t0 * y0);
	double dt = 0.01; // Define step size
	double n = 10; double h = dt / n;


	for (t0 = 0; t0 < tmax; t0 += h)
	{

		double m = F0;
		double y1 = y0 + h * F0;
		t1 = t0 + h;
		y0 = y1;
		cout << y1 << t1;

		theta = (-G / L) * sin(theta);
		thetapf = theta + dt * (dtheta);
		thetaf= theta + dt * (thetap);
		theta = thetaf;
		thetap = thetapf;
		cout << t1 << "\t" << thetaf * (180 / pi) << endl;
		
return 0;
}



