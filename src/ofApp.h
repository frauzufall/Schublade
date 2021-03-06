#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	
	void exit();

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

private:

	void loadImageset(string name);
	void setActiveImageset(int& setid);
	void setShowCursor(bool& show);

	vector<vector<ofPtr<ofImage> > > images;
	ofParameter<int> distance;

	ofParameter<float> bottom, top, left, right;

	ofParameter<int> active_set;

	ofParameter<int> window_width, window_height;

	ofParameter<bool> draw_gui, show_cursor;

	ofxPanel gui;

};

