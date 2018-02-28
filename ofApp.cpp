#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	ofNoFill();
	ofSetColor(0, 200, 0);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	float radius = 300;
	int deg_span = 1;
	int z = 0;
	
	for (int i = 0; i < 360; i += 10) {
		ofRotateX(10);

		ofBeginShape();
		for (int deg = 0; deg < 360; deg += deg_span) {

			float x = radius * cos(deg * DEG_TO_RAD);
			float y = radius * sin(deg * DEG_TO_RAD);
			float tmp_radius = ofMap(ofNoise(x * 0.005, y * 0.005, i * 0.005 + ofGetFrameNum() * 0.005), 0, 1, 200, 300);

			x = tmp_radius * cos(deg * DEG_TO_RAD);
			y = tmp_radius * sin(deg * DEG_TO_RAD);
			ofPoint point = ofPoint(x, y, 0);
			ofVertex(point);
		}
		ofEndShape(true);
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}