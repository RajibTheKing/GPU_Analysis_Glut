// GPU_Analysis_Glut.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include "GlutProcessor.h"
#include <vector>
#include "Utils.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	printf("TheKing--> Starting Application\n");
	
	/*
	long long startTime = Utils::CurrentTimeStamp();
	double a=3.1416, b=2.15, c=45.65, d=56.78, e, sum;
	double results[352*288];
	
	for (int i = 0; i < 352; i++)
	{
		a = a + i;
		for (int j = 0; j < 288; j++)
		{
			sum = 0;
			for (int m = 0; m < 100; m++)
			{
				for (int n = 0; n < 100; n++)
				{
					sum+=(a*b + c)/d;
				}
			}
			//results.push_back(sum);
			results[i * 288 + j] = sum;
		}
	}
	printf("TheKing--> ProcessingTime = %lld\n", Utils::CurrentTimeStamp() - startTime);
	*/

	/*int counter = 0;
	while (counter < 50)
	{
		int indx = rand() % (352 * 288);
		printf("%d. Value = %lf\n", counter, results[indx]);
		counter++;
	}*/
	


	GlutProcessor *pGlutProcessor;
	pGlutProcessor = new GlutProcessor(argc, "TheKing Window", 1400, 900);

	getchar();

	return 0;
}

