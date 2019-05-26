#include "ofApp.h"
#include <iostream>

time_t rawtime;
//--------------------------------------------------------------
void ofApp::setup(){
	m_serial.setup();
	if ( !m_serial.available() )
	{
		std::cout << "[*] error : no serial port available" << std::endl;
	}
	for ( int i = 0; i < 3; i++ )
	{
		Top[i].load("TOP" + std::to_string(i + 1) + ".png");
		Top[i].rotate90(3);
		Bottom[i].load("BOTTOM" + std::to_string(i + 1) + ".png");
		Bottom[i].rotate90(3);
	}
	Bottom[3].load("BOTTOM_TAG.png");
	Bottom[3].rotate90(3);

	topChange = 0;
	topCount = TOP_CHANGETIME;
	bottomChange = 0;
	bottomCount = BOTTOM_CHANGETIME;

	video = new ofVideoPlayer;
	video->load("video.mp4");
	video->setLoopState(OF_LOOP_NONE);


}

//--------------------------------------------------------------
void ofApp::update(){

	m_serial.update();
	//top change
	topCount--;
	if ( !topCount )
	{
		topChange++;
		topCount = TOP_CHANGETIME;
		if ( topChange >= 3 )
		{
			topChange = 0;
		}
	}
	//bottom change
	bottomCount--;
	if ( !bottomCount )
	{
		bottomChange++;
		bottomCount = BOTTOM_CHANGETIME;
		if ( bottomChange >= 3 )
		{
			bottomChange = 0;
		}
	}
	video->update();
	if ( video->getIsMovieDone() )
	{
		delete video;
		video = new ofVideoPlayer;
		video->load("video.mp4");
		video->setLoopState(OF_LOOP_NONE);
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofPushMatrix();
	ofTranslate(-1920, 0);

	Top[topChange].draw(0, 0, 1920, 1080);
	Bottom[bottomChange].draw(1920, 0, 1920, 1080);

	video->draw(-945, 1010, 880, 635);
	video->play();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	callback(1);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
