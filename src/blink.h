#include <iostream>
#include "interpolation.h"
#define BASE_VAL 0.0
#define DECAY_TIME 5
#define MINIMAM_VAL 0.05

 
class Blink {

	public:
	Blink();
	Interpolation intp;
	void init(float got_st, float got_ed, int got_step);
	float update();

	float st;
	float ed;
	float now;
	int step;
	int step_count;

	//Statics
	float base_value;
	int dacay_time;

};
