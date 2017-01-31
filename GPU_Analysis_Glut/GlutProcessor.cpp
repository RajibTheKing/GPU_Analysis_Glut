#include "GlutProcessor.h"
#include "Utils.h"

const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int GlutProcessor::m_iHeight;
int GlutProcessor::m_iWidth;
int GlutProcessor::m_iSlices;
int GlutProcessor::m_iStacks;
long long GlutProcessor::displayCounter;
long long GlutProcessor::prevTime;

GlutProcessor::GlutProcessor(int &argc, string sWindowName, int iWidth, int iHeight)
{
	m_iHeight = iHeight;
	m_iWidth = iWidth;
	m_iStacks = 50;
	m_iSlices = 50;

	displayCounter = 0;
	prevTime = -1;


	glutInit(&argc, NULL);
	glutInitWindowSize(m_iWidth, m_iHeight);
	glutInitWindowPosition(100, 50);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("TheKing--> GLUT Window");

	glutReshapeFunc(resize);
	glutDisplayFunc(CustomizedMethod);
	glutKeyboardFunc(key);
	glutIdleFunc(idle);

	glClearColor(1, 1, 1, 1);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

	const char *gpuVersion = (char *)glGetString(GL_RENDERER);
	printf("TheKing--> %s\n", gpuVersion);
	glutMainLoop();

	glutCreateWindow("GLUT Shapes 2");
	glutMainLoop();
}

GlutProcessor::~GlutProcessor()
{

}


void GlutProcessor::resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void GlutProcessor::CustomizedMethod(void)
{
	if (prevTime == -1)
	{
		prevTime = Utils::CurrentTimeStamp();
	}
	else
	{
		printf("TheKing--> TimeGap = %lld\n", Utils::CurrentTimeStamp() - prevTime);
		prevTime = Utils::CurrentTimeStamp();

		long long startTime = Utils::CurrentTimeStamp();
		double a = 3.1416, b = 2.15, c = 45.65, d = 56.78, e, sum;
		double results[352 * 288];

		for (int i = 0; i < 352; i++)
		{
			a = a + i;
			for (int j = 0; j < 288; j++)
			{
				sum = 0;
				for (int m = 0; m < 10; m++)
				{
					for (int n = 0; n < 10; n++)
					{
						sum += (a*b + c) / d;
					}
				}
				//results.push_back(sum);
				results[i * 288 + j] = sum;
			}
		}
		printf("TheKing--> ProcessingTime = %lld\n", Utils::CurrentTimeStamp() - startTime);


	}
	const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
	const double a = t*90.0;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3d(1, 0, 0);

	glPushMatrix();
	glTranslated(-2.4, -1.2, -6);
	glRotated(60, 1, 0, 0);
	glRotated(a, 0, 0, 1);
	glutWireSphere(1, m_iSlices, m_iStacks);
	glPopMatrix();

	glutSwapBuffers();
}

void GlutProcessor::key(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
	case 'q':
		exit(0);
		break;

	case '+':
		if (m_iSlices < 100 && m_iStacks < 100)
		{
			m_iSlices++;
			m_iStacks++;
		}
		break;

	case '-':
		if (m_iSlices>3 && m_iStacks>3)
		{
			m_iSlices--;
			m_iStacks--;
		}
		break;
	}

	glutPostRedisplay();
}

void GlutProcessor::idle(void)
{
	glutPostRedisplay();
}