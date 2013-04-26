#include "Particle.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"

using namespace ci;

Particle::Particle()
{
}

Particle::Particle( Vec2f loc_ )
{
	loc	= loc_;
	dir	= Rand::randVec2f();
	vel	= Rand::randFloat( 5.0f );
	radius	= 3.0f;
}

void Particle::update(Channel32f channel)
{
	loc += dir * vel;
    radius = 3.0f * channel.getValue(loc);
}

void Particle::draw()
{
	gl::drawSolidCircle( loc, radius );
}
