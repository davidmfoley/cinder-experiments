//
//  Particle.h
//  HellCinder
//
//  Created by Dave on 4/26/13.
//
//

#ifndef __HellCinder__Particle__
#define __HellCinder__Particle__

#include <iostream>

#endif /* defined(__HellCinder__Particle__) */
class Particle {
public:
    Particle();
	Particle( ci::Vec2f );
	void update(cinder::Channel32f channel);
	void draw();
	
	ci::Vec2f	loc;
	ci::Vec2f	dir;
	float		vel;
	
	float		radius;

};