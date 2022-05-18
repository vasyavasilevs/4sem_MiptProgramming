#include <iostream>
#include <future>
#include <math.h>
#include <time.h>

#define R 6
#define NUM_OF_DOTS 2000000

struct Dot {
	float x = 0;
	float y = 0;
	float z = 0;
};

float get_rand()
{
	return (float)rand() / RAND_MAX;
}

int main() 
{
	double probability = 0, volume = 0, hit_dots = 0, i = 0, square_d = 0;
	struct Dot dot;
	std::vector <Dot> dots;
	srand(time(NULL));
	while (i < NUM_OF_DOTS) {
		dot.x = -R + get_rand() * 2 * R;
		dot.y = -R + get_rand() * 2 * R;
		dot.z = -R + get_rand() * 2 * R;
		dots.push_back(dot);
		i++;
	}
	for (i = 0; i < dots.size(); i++) {
		square_d = pow(dots[i].x, 2) + pow(dots[i].y, 2) + pow(dots[i].z, 2);
		if (square_d <= pow(R, 2))
			hit_dots++;
	}
	std::cout << hit_dots << std::endl;
	probability = hit_dots / NUM_OF_DOTS;
	std::cout << probability << " " << std::endl;
	volume = probability * pow(2 * R, 3);
	std::cout << volume << std::endl;
	return 0;
}
