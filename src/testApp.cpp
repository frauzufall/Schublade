#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(0);

    ofDirectory dir("imagesets");
    dir.listDir();
    dir.sort();
    for(uint i = 0; i < dir.size(); i++) {
        if (dir.getFile(i).isDirectory()==1){
            loadImageset(dir.getFile(i).getAbsolutePath());
        }
    }

    active_set.addListener(this, &testApp::setActiveImageset);
    show_cursor.addListener(this, &testApp::setShowCursor);

    gui.setup();
    if(images.size() > 1) {
        gui.add(active_set.set("active imageset", 0, 0, images.size()-1));
    }else {
        active_set.set(0);
    }
    gui.add(distance.set("distance", 0));
    gui.add(top.set("top", 0, 0, 1));
    gui.add(bottom.set("bottom", 1, 0, 1));
    gui.add(left.set("left", 0, 0, 1));
    gui.add(right.set("right", 1, 0, 1));
    gui.add(draw_gui.set("show gui", true));
    gui.add(show_cursor.set("show cursor", true));
    gui.add(window_width.set("window width", 1920, 0, 1920));
    gui.add(window_height.set("window height", 1200, 0, 1200));

    gui.loadFromFile("settings.xml");

    ofSetWindowShape(window_width, window_height);
    ofSetFullscreen(true);

}

void testApp::loadImageset(string name){
    images.push_back(vector<ofPtr<ofImage> >());
    int index = images.size()-1;

    ofDirectory dir(name);
    dir.allowExt("jpg");
    dir.allowExt("jpeg");
    dir.allowExt("png");
    dir.allowExt("gif");
    dir.listDir();
    dir.sort();
    vector<ofFile> files = dir.getFiles();
    for(uint i = 0; i < files.size(); i++) {
        ofPtr<ofImage> img = ofPtr<ofImage>(new ofImage());
        img->load(files.at(i));

        images.at(index).push_back(img);
    }

    distance.setMax(files.size()-1);
}

void testApp::setActiveImageset(int& setid){

    if(active_set >= images.size()){
        active_set = images.size()-1;
    }

    distance.setMax(images.at(active_set).size()-1);
    distance.set(0);
}

//--------------------------------------------------------------
void testApp::update(){
    left.setMax(right.get());
    right.setMin(left.get());
    top.setMax(bottom.get());
    bottom.setMin(top.get());
}

//--------------------------------------------------------------
void testApp::draw(){

    ofRectangle out_shape;
    out_shape.x = left*window_width;
    out_shape.y = top*window_height;
    out_shape.width = window_width*right-out_shape.x;
    out_shape.height = window_height*bottom-out_shape.y;

    ofSetColor(255);

    if(images.size() > 0){

        if(images.at(active_set).size() > 0){

            ofPtr<ofImage> image = images.at(active_set).at(distance);
            ofRectangle in_shape(0,0,image->getWidth(), image->getHeight());

            float img_ratio = image->getWidth() / image->getHeight();
            float output_ratio = out_shape.getWidth() / out_shape.getHeight();
            if(img_ratio > output_ratio){
                //source is wider
                in_shape.width = image->getHeight() * out_shape.getWidth() / out_shape.getHeight();
                in_shape.x = (image->getWidth() - in_shape.width)/2;
            }
            if(img_ratio < output_ratio){
                //source is taller
                in_shape.height = image->getWidth() * out_shape.getHeight() / out_shape.getWidth();
                in_shape.y = (image->getHeight() - in_shape.height)/2;
            }

            image->draw(out_shape.x, out_shape.y, image->getWidth(), image->getHeight());

//            glBegin(GL_QUADS);

//            glTexCoord2f(in_shape.getLeft(), in_shape.getTop());		glVertex3f(out_shape.getLeft(), out_shape.getTop(), 0);
//            glTexCoord2f(in_shape.getRight(), in_shape.getTop());		glVertex3f(out_shape.getRight(), out_shape.getTop(), 0);
//            glTexCoord2f(in_shape.getRight(), in_shape.getBottom());	glVertex3f(out_shape.getRight(), out_shape.getBottom(), 0);
//            glTexCoord2f(in_shape.getLeft(), in_shape.getBottom());		glVertex3f(out_shape.getLeft(), out_shape.getBottom(), 0);

//            glEnd();
//            image->unbind();

        }

    }

    if(draw_gui) {
        gui.draw();
    }

}

void testApp::setShowCursor(bool &show){
    if(show) {
        ofShowCursor();
    }else {
        ofHideCursor();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    switch(key) {
    case 'f': {
        ofToggleFullscreen();
        break;
    }
    case 'g': {
        draw_gui = !draw_gui;
        break;
    }
    case 'm': {
        show_cursor = !show_cursor;
        break;
    }
    default:break;
    }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
