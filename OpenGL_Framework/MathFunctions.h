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

static Vector NormToPlane(Vector p1, Vector p2, Vector p3){
	Vector v1, v2, n;
	v1 = p1 - p2;
	v2 = p3 - p2;
	n = v1.CrossProduct(v2);
	if (n.Length() > 0) n.Normalize();
	return n;
}