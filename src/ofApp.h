#pragma once

#include "ofMain.h"
#include "Serial.hpp"

class ofApp : public ofBaseApp{

private:
	LibDaetris::SerialApp m_serial;

	void callback(int byte)
	{
		bottomChange = 3;
		bottomCount = BOTTOM_CHANGETIME * 2;
		// Log the check-time in the ~/bin/data/log.txt
		time(&rawtime);
		myTextFile.open("log.txt", ofFile::Append);
		myTextFile << ctime(&rawtime);
		myTextFile.close();
	}
	public:
		ofApp() : m_serial("COM5", 9600)
		{
			m_serial.set_callback([this](int byte) { callback(byte); });
		}
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		std::time_t rawtime;

		ofFile myTextFile;
		int completeCounter = -1;

		bool word_writing = false;
		int c_endIndex = -1;
		int c_index = 0;
		bool test = false;

		ofImage Top[3];
		ofImage Bottom[4];
		
		int topCount;
		int topChange;
		const int TOP_CHANGETIME = 600;

		int bottomCount;
		int bottomChange;
		const int BOTTOM_CHANGETIME = 100;

		ofVideoPlayer* video;

};
