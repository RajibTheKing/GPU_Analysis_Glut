#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <string>
using namespace std;

class GlutProcessor
{
public:

	GlutProcessor(int &argc, string sWindowName, int iWidth, int iHeight);
	~GlutProcessor();
	static void resize(int width, int height);
	static void CustomizedMethod();
	static void key(unsigned char key, int x, int y);
	static void idle();

	static int m_iHeight;
	static int m_iWidth;
	static int m_iStacks;
	static int m_iSlices;

	long long displayCounter;
	long long prevTime;
	double a , b , c, d;

};
