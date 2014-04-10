//Corey Bradford, University of Bolton

#pragma once

static float lerp(float start, float end, float percent){
	if (percent > 1.0f){
		percent = 1.0f;
	}
	else if (percent < 0.0f){
		percent = 0.0f;
	}
	return (start + (percent * (end - start)));
}