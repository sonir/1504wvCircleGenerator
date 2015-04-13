#pragma once
#include <iostream>

class Interpolation {

	public:
	Interpolation();
	void init(float got_st, float got_ed, int got_step);
	float update();	

	float st;
	float ed;
	float now;
	int step;
	int step_count;
    
};