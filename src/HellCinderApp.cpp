#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "ParticleController.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HellCinderApp : public AppNative {
  public:
	void setup();
	void update();
	void draw();
    void prepareSettings(Settings *settings);
    Channel32f channel;
    gl::Texture texture;
    ParticleController particleController;
    int particleCount, particleIncrement, maxParticles;
};

void HellCinderApp::prepareSettings(Settings *settings)
{
    settings->setWindowSize(800, 600);
    settings->setFrameRate(60);
}

void HellCinderApp::setup()
{
    //string loc = "http://lorempixel.com/800/600/nightlife/";
    //Url url(loc);
    
    auto image = loadImage( loadAsset( "Lucy.png" ) );
    texture = gl::Texture(image);
    channel = Channel32f( image );
    particleCount = 0;
    particleIncrement = 100;
    maxParticles = 15000;
    
}

void HellCinderApp::update()
{
    if (particleCount < maxParticles) {
        particleController.addParticles( particleIncrement );
        particleCount += particleIncrement;
    }
    
    particleController.update(channel);
}

void HellCinderApp::draw()
{
    
    gl::clear( Color( 0, 0, 0 ), true );
	
	glDisable( GL_TEXTURE_2D );
	//gl::draw( texture, getWindowBounds() );

	particleController.draw();
}

CINDER_APP_NATIVE( HellCinderApp, RendererGl )
