#ifndef Timer_h
#define Timer_h

#include "GlutApp.h"
#include "TexRect.h"

class Timer
{
	double x;						//x position of gauge
	double y;						//y position of gauge
	double w;						//width of gauge changes over time
	bool fullgauge = false;					//if gauge is full or not (currently using 0.2 for full)
	bool burnt;						//if pot/pan is burning
	int cooked;						//0 = undercooked; 1 = cooked; 2 = overcooked
	int cut;						//0 = uncut; 1 = cut
public:
	//constructor
	/*Timer()
	{
		x = 0.0;
		y = 0.0;
		w = 0.0;
		fullgauge = false;
		cooked = 0;
		cut = 0;
		burnt = false;
	}*/
	Timer(double xpos, double ypos)
	{
		x = xpos;
		y = ypos;
		w = 0.0;
		//fullgauge = false;
		cooked = 0;
		cut = 0;
		burnt = false;
	}

	void drawPotGauge();
	void drawBoardGauge();
	//double advanceGauge(double w);
	void advanceGauge();
	void complete();
	void burn();
	bool done();
	int cookingStatus();
	int cutStatus();
};

#endif
