#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HellCinderApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    void prepareSettings(Settings *settings);
    gl::Texture imageTexture;
    
};

void HellCinderApp::prepareSettings(Settings *settings)
{
    settings->setWindowSize(800, 600);
    settings->setFrameRate(60);
}

void HellCinderApp::setup()
{
    string loc = "http://lorempixel.com/800/600/technics/";
    Url url(loc);
    imageTexture = gl::Texture( loadImage( loadUrl( url ) ) );
}

void HellCinderApp::mouseDown( MouseEvent event )
{
}

void HellCinderApp::update()
{
}

void HellCinderApp::draw()
{
    gl::clear();
    gl::draw( imageTexture, getWindowBounds() );
}

CINDER_APP_NATIVE( HellCinderApp, RendererGl )
