// Purpose: 1-D integration (single-valued function of y versus x) 
// Goal: Program to MC-integrate (full area under the curve)



#include "stdio.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>
#include "math.h"
#include "string.h"
#include "float.h"

double rand_uniform ( );
double integrand ( double x ); 
using namespace std;

int main ( int argc, char** argv ) {

  long N = 1e6L; 
  double left, right, midpt, trap; // left hand rule, right etc
  double yL, yR, yM, a, b, h, xI, xF, xM; // a,b bounds upper and lower
  a = 0.; b = 1.; h = (b-a)/double(N); // h is step size
  
 xI = a; left = 0.; right = 0.; midpt = 0.; trap = 0.;

 ofstream myfile; 
 myfile.open("example_output.dat", ios::app); //must open and name it (myfile is var name)
 //myfile << "Left-hand" << "\t" << "Right-hand" << "\t" << "Midpoint" << "\t" << "Trapezoid" << "\t" << endl;
  cout << "Left-hand" << "\t" << "Right-hand" << "\t" << "Midpoint" << "\t" << "Trapezoid" << "\t" << endl;
  for ( long i = 0; i < N; i++ ) {
    
    xF = xI + h;
    yL = integrand(xI); // x initial
    yR = integrand(xF); // x final function trying to integrate
    xM = (xI+xF)/2.;
    yM = integrand(xM);
    
    left += yL*h;
    right += yR*h;
    midpt += yM*h;
    trap += (yL+yR)*(h/2.);
    
    //for loop goes to n-l. print results on the last step.
   if(i==N-1)
       //myfile << ("%e\t%e\t%e\t%e\t%e\n", left, right, midpt, trap)<< endl;
       printf("%e\t%e\t%e\t%e\t%e\n",left,right,midpt,trap); // %e means exponential. 
    xI = xF;
    
  } 
  // compare with wolfram alpha integral 0 10 1 (x+1)dx e^-x^2dx,x^x dx
  
  double x_min = 0., x_max=200,y_min=0,y_max=10e-4, area = 0., points = 2e9; //von neumann
  double total = (b-a)*(y_max-0.);
  for ( unsigned long i = 0; i <= points; i++ ) {
    
    double x_random = a + ( b - a ) * rand_uniform(); // rand number between a and b
    double y_random = 0 + ( y_max - 0 ) * rand_uniform(); // random min to max for y value. bounded. replace 1 with max. first find rectangle then mc integreate it for y min
    
    if(y_min < integrand(x_max)) area++; //von Neumann
    if ( !(i % 5000000) ) // don't need a billion points. every 50 hundreath thousand print to secreen
        	myfile << (stderr, "\t%llu\t\t\t%f\n", i, (area / points) * total)<< endl;
      fprintf(stderr,"\t%llu\t\t\t%f\n",i,(area/points)*total);
	// % llu long long unsigned, %f is the area of the points inside function / #number of points * total
    
  }
  
  return 0; //disclaimer not doing Simpson's 3/8 rule or adaptive-step or Taylor
  myfile.close();
}

double rand_uniform ( ) {
  
  return (double)rand() / (double)RAND_MAX;
  
}

double integrand ( double x ) { //fucntions not integrable
  
  //return exp(-pow(x,2.));
  //return pow(x,x);
  // return tgamma(x+1.);
   


  
}

// while loop necessary so von-nemann stops when it needs to: if (n-(n-1)) current iteration-previous iteration. is it getting smaller?