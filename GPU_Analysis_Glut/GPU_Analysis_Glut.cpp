// GPU_Analysis_Glut.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include "GlutProcessor.h"


int _tmain(int argc, _TCHAR* argv[])
{

	printf("TheKing--> Starting Application\n");

	GlutProcessor *pGlutProcessor;
	pGlutProcessor = new GlutProcessor(argc, "TheKing Window", 600, 400);

	getchar();

	return 0;
}

