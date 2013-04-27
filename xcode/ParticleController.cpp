#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/Vector.h"
#include "ParticleController.h"

using namespace ci;
using std::list;

ParticleController::ParticleController()
{
}

void ParticleController::update(Channel32f channel)
{
 	for( list<Particle>::iterator p = particles.begin(); p != particles.end();)
    {
		p->update(channel);
        if (p->alive)
        {
            p++;
        }
        else
        {
            p = particles.erase(p);
            this->addParticle().update(channel);
        }
	}
    
}

void ParticleController::draw()
{
	for( Particle &p : particles ){
		p.draw();
	}
}

void ParticleController::addParticles( int amt )
{
	for( int i=0; i<amt; i++ )
	{
        this->addParticle();
	}
}

Particle ParticleController::addParticle() {
    float x = Rand::randFloat( app::getWindowWidth() );
    float y = Rand::randFloat( app::getWindowHeight() );
    auto p = Particle( Vec2f( x, y ) );
    particles.push_back( p );
    return p;
}

void ParticleController::removeParticles( int amt )
{
	for( int i=0; i<amt; i++ )
	{
		particles.pop_back();
	}
}

