#include "Timer.h"

using namespace std;

void Timer::drawPotGauge()
{
	glColor3d(252.0, 0.0, 0.0);
	glRectd(x, y, x + w, y - 0.1);
	//cout << x << " " << y << endl;
	//redraw();
}

void Timer::drawBoardGauge()
{
	glColor3d(0.0, 252.0, 0.0);
	glRectd(x, y, x + w, y - 0.1);
	//redraw();
}

//double Timer::advanceGauge(double w)
void Timer::advanceGauge()
{
	//glutPostRedisplay();
	//glutTimerFunc(500, advanceGauge, 0);
	//cout << "w after advance: " << w << endl;				//testing
	if (w >= 0.2)
		fullgauge = true;
	else
		w += .0002;
	//return w;
}

void Timer::complete()
{
	fullgauge = true;
}

void Timer::burn()
{
	glColor3d(0.0, 0.0, 0.0);
	glRectd(x, y, x + 0.2, y - 0.1);
	burnt = true;
	//cout << "burnt after burn: " << burnt << endl;				//testing
}

bool Timer::done()
{
	if (w >= 0.2)
		return true;
	else
		return false;
	//cout <<"fullgauge after done: "<< fullgauge << endl;				//testing
	//return fullgauge;
}

int Timer::cookingStatus()
{
	if (!burnt)
	{
		if (!fullgauge)
			return 0;
		else
			return 1;
	}
	else
		return 2;
}

int Timer::cutStatus()
{
	if (!fullgauge)
		return 0;
	else
		return 1;
}