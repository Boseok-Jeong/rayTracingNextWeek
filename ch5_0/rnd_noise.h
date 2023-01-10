#pragma once

#ifndef RANDOM_NOISE_H
#define RANDOM_NOISE_H

#include "rtweekend.h"

class rnd_noise {
public:
	rnd_noise() {
		ranfloat = new double[point_count];
		for (int i = 0; i < point_count; ++i) {
			ranfloat[i] = random_double();
		}
	}

	~rnd_noise() {
		delete[] ranfloat;
	}

	double noise(const point3& p) const {
		auto i = static_cast<int>(4 * p.x()) & 3;
		auto j = static_cast<int>(4 * p.y()) & 15;
		auto k = static_cast<int>(16 * p.z()) & 12;

		return ranfloat[i ^ j ^ k];
	}

private:
	static const int point_count = 16;
	double* ranfloat;
};


#endif // !RANDOM_NOISE_H
