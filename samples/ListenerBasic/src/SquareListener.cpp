#include "SquareListener.h"
#include "cinder/gl/gl.h"
#include "cinder/Rect.h"

using namespace ci;
using namespace ci::app;

SquareListener::SquareListener( App *app )
	: App::Listener()
{
	mRect = Rectf( Vec2f( -40, -40 ), Vec2f( 40, 40 ) );
	mRect.offset( app->getWindowCenter() );
	mSelected = false;
	app->addListener( this );
}
 
bool SquareListener::mouseDown( MouseEvent event )
{
	mSelected = mRect.isInside( event.getPos() );

	// if we got selected then we handled the event, otherwise let it pass through
	return mSelected;
}

bool SquareListener::mouseDrag( MouseEvent event )
{
	if( mSelected )
		mRect.offsetCenterTo( event.getPos() );

	// if we are selected then we handled the event, otherwise let it pass through
	return mSelected;
}

void SquareListener::draw()
{
	gl::color( ( mSelected ) ? Color::white() : Color::black() );
	gl::drawSolidRect( mRect );
}
