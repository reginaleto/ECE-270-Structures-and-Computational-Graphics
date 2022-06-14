#include "ofApp.h"
#define pi 3.14159
#define N_MAX 10000

void ofApp::setLine(Line *l, int x_1, int y_1, int x_2, int y_2)
{
	l->x1 = x_1;
	l->y1 = y_1;
	l->x2 = x_2;
	l->y2 = y_2;
}

void ofApp::setCircle(Circle *c, int c_x, int c_y, int c_r)
{
	c->x = c_x;
	c->y = c_y;
	c->r = c_r;
}
void ofApp::setRectangle(Rectang *r, int r_x, int r_y, int r_w, int r_h)
{
	r->x = r_x;
	r->y = r_y;
	r->w = r_h;
	r->h = r_h;
}

void ofApp::setStroke(Stroke *s)
{
	s->red = rand() % 256;
	s->green = rand() % 256;
	s->blue = rand() % 256;
}

void ofApp::setFill(Fill *f)
{
	f->red = rand() % 256;
	f->green = rand() % 256;
	f->blue = rand() % 256;
}

void ofApp::setPath(Path *p, int offsetX, int offsetY)
{
	p->n = 1000;
	for (int i = 0; i < 1001; i++)
	{
		p->x[i] = 10 * exp((log((1 + sqrt(5)) / 2)) / (pi / 2) *(i)) * cos(i) + offsetX;
		p->y[i] = 10 * exp((log((1 + sqrt(5)) / 2)) / (pi / 2)*(i)) * sin(i) + offsetY;
	}
}

//--------------------------------------------------------------
void ofApp::drawLine(Line line)
{
	ofSetColor(0, 0, 0);
	ofDrawLine(line.x1, line.y1, line.x2, line.y2);
}

//--------------------------------------------------------------
void ofApp::drawCircle(Circle circle, Fill fill, Stroke stroke)
{
	ofSetColor(fill.red, fill.green, fill.blue);
	ofFill();
	ofDrawCircle(circle.x, circle.y, circle.r);

	ofNoFill();
	ofSetColor(stroke.red, stroke.green, stroke.blue);
	ofDrawCircle(circle.x, circle.y, circle.r);
}

//--------------------------------------------------------------
void ofApp::drawRectangle(Rectang rect, Fill fill, Stroke stroke)
{
	ofSetColor(fill.red, fill.green, fill.blue);
	ofFill();
	ofDrawRectangle(rect.x, rect.y, rect.w, rect.h);

	ofNoFill();
	ofSetColor(stroke.red, stroke.green, stroke.blue);
	ofDrawRectangle(rect.x, rect.y, rect.w, rect.h);
}
//--------------------------------------------------------------
void ofApp::drawPath(Line line, Circle circle, Path path, Fill fill, Stroke stroke)
{
	setPath(&path, offsetX, offsetY);
	setFill(&fill);
	setStroke(&stroke);

	for (int i = 0; i < path.n; i++)
	{
		setLine(&line, path.x[i], path.y[i], path.x[i + 1], path.y[i + 1]);
		drawLine(line);

		setCircle(&circle, path.x[i], path.y[i], 20);
		drawCircle(circle, fill, stroke);
	}
}

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(3);

	ofSetBackgroundAuto(false);
	ofSetBackgroundColor(255, 255, 255);
	
	ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::update(){
	drawPath(line, circle, path, fill, stroke);
}

//--------------------------------------------------------------
void ofApp::draw(){
	
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
	ofSetBackgroundAuto(true);
	offsetX = rand() % 1001;
	offsetY = rand() % 1001;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
