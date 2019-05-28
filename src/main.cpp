#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1920 * 2, 1080, OF_FULLSCREEN);			// <-------- setup the GL context

	std::string port_name;
	std::cout << "[*] port name : ";
	std::cin >> port_name;

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp(port_name));

}
