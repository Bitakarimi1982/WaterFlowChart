
#include "waterFlowDown.h"
#include"waterFlow4.h"
#include <iostream>

int main()
{
	WaterFlowDown waterflow;        //Objekts der Klasse WaterFlowDown
	waterflow.printHeightmap();		//Aufruf der printHeightmap
	waterflow.printAfterRain();		//Aufruf der printAfterRain

	WaterFlow4 waterflow4;			//Objekts der Klasse WaterFlow4
	waterflow4.printAfterRain();
	return 0;
}

