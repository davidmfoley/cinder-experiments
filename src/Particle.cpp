#include "Particle.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include <stdlib.h>

using namespace ci;

Particle::Particle( Vec2f loc_ )
{
	loc	= loc_;
	dir	= Rand::randVec2f();
	auto velRelative = Rand::randFloat( 1.0f );
    vel = velRelative * 7.0f;
    red = velRelative;
    green = 1.0f - velRelative;
    blue = 0.9f;
	radius	= 3.0f;
    age = 0;
    lifespan = 120 + Rand::randUint(240);
    alive = true;
}

void Particle::update(Channel32f channel)
{
    if (age > lifespan) {
        alive = false;
        return;
    }
	loc += dir * vel;
    auto lifePhase = ((float)age) / lifespan;
    blue = channel.getValue(loc);
    radius = 3.0f * (1 - (abs(lifePhase - 0.5f))) * channel.getValue(loc) + 1.0f;
    
    age++;
    vel*=0.97f;
}

void Particle::draw()
{
    glColor3f( red, green, blue);
	gl::drawSolidCircle( loc, radius );
    //gl::drawStringCentered(std::to_string(age) + " / " + std::to_string(lifespan) + " - " + std::to_string(radius), loc);
}
