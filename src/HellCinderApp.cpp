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
    ParticleController particleController;
};

void HellCinderApp::prepareSettings(Settings *settings)
{
    settings->setWindowSize(800, 600);
    settings->setFrameRate(60);
}

void HellCinderApp::setup()
{
    string loc = "http://lorempixel.com/800/600/abstract/";
    Url url(loc);

    channel = Channel32f( loadImage( loadUrl( url ) ) );
    particleController.addParticles( 15000 );
}

void HellCinderApp::update()
{
    particleController.update(channel);
}

void HellCinderApp::draw()
{
    
    gl::clear( Color( 0, 0, 0 ), true );
	
	glDisable( GL_TEXTURE_2D );
	glColor3f( 1, 1, 1 );
	particleController.draw();
}

CINDER_APP_NATIVE( HellCinderApp, RendererGl )
