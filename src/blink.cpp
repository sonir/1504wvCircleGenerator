#include "blink.h"

using namespace std;
Blink::Blink(){

	step = 0;
	step_count=0;
	base_value = BASE_VAL;
	dacay_time = DECAY_TIME;


}

void Blink::init(float got_st, float got_ed, int got_step) {

	st = got_st;
	ed = got_ed;
	step = got_step;
    step_count = 0;

	intp.init(got_st, got_ed, got_step);

}


float Blink::update(){

	if(step_count>=step){

		if(now<MINIMAM_VAL){
			now=0.0; //Finish easing , to avoid turtol and akiless
			intp.now=0.0;
		}

		intp.init(now, base_value, dacay_time);
		step_count=0;

	}

	step_count++;
	now = intp.update();
	return now;

}
