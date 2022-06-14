#pragma once
#define N_MAX 10000
#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:

		typedef struct Line 
		{
			int x1;
			int y1;
			int x2;
			int y2;
		}Line;
		Line line;

		typedef struct Circle
		{
			int x; 
			int y;
			int r;
		}Circle;
		Circle circle;

		typedef struct Rectang
		{
			int x;
			int y;
			int w;
			int h;
		}Rectang;
		Rectang rect;

		typedef struct Fill
		{
			int red;
			int green;
			int blue;
		}Fill;
		Fill fill;

		typedef struct Stroke
		{
			int red;
			int green;
			int blue;
		}Stroke;
		Stroke stroke;

		typedef struct Path
		{
			int n;
			int x[N_MAX];
			float y[N_MAX];
		}Path;
		Path path;


		int offsetX = 500; 
		int offsetY = 500;

		void setLine(Line*, int, int, int, int);
		void setCircle(Circle*, int, int, int);
		void setRectangle(Rectang*, int, int r_y, int r_w, int r_h);
		void setFill(Fill *f);
		void setStroke(Stroke *s);
		void setPath(Path *p, int offsetX, int offsetY);

		void drawLine(Line line);
		void drawPath(Line line, Circle circle, Path path, Fill fill, Stroke stroke);
		void drawCircle(Circle circle, Fill fill, Stroke stroke);
		void drawRectangle(Rectang rect, Fill fill, Stroke stroke);

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
};
