// Special Relativity 
// Mini Program asks user to enter a velocity, time, length, mass. 
// Output values related to the speed of light.

#include "stdio.h"
#include <iostream>
#include "math.h"

using namespace std;

int main() {

	double velocity; double time; double length; double mass;
	fprintf(stdout, "Enter input velocity in (m/s): ");
	cin >> velocity;
	fprintf(stdout, "Enter the time in (s): ");
	cin >> time;
	fprintf(stdout, "Enter the length in (m): ");
	cin >> length;
	fprintf(stdout, "Enter the mass at rest in (kg): ");
	cin >> mass;


	double beta; double speed_of_light; double gamma; double t_dilation; double l_contraction;
	speed_of_light = 2.99792458e8;
	beta = (velocity / (speed_of_light));
	gamma = (1 / (sqrt(1 - pow(beta, 2))));
	t_dilation = (gamma * time);
	l_contraction = (length / gamma);
	double k_energy; double total_energy; double new_larger_mass; double rest_mass_energy; double momentum;
	k_energy = (gamma - 1) * mass * pow(speed_of_light, 2);
	new_larger_mass = (gamma * mass);
	rest_mass_energy = (mass * pow(speed_of_light, 2));
	total_energy = (k_energy + rest_mass_energy);
	momentum = (gamma * mass * velocity);

	printf("%f \n  %f \n  %f \n  %f \n  %f \n %f \n %f \n  %f \n", beta, gamma, t_dilation, l_contraction, new_larger_mass , k_energy, total_energy, momentum);

		return 0;

}