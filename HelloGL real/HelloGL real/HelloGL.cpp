#include "HelloGL.h"
#include "GLUTCallbacks.h"
HelloGL::HelloGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutMainLoop();
	glutInitWindowSize(800, 800);
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT); //this clears the scene
	glBegin(GL_POLYGON); //starts to draw a polygon
		DrawHS(); //draw polygon
	glFlush(); //flushes the scene drawn to the graphics card
}

void HelloGL::DrawHS()
{
	glBegin(GL_POLYGON); //starts to draw a polygon
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f); //sets colour
		glVertex2f(0.2, 0.6); //define the first point of the polygon, top left
		glVertex2f(0.1, 0.48); //next point, top right
		glVertex2f(0.55, 0.3);//last point of the polygon, bottom left
		glVertex2f(0.58, 0.28); //bottom right
		glEnd(); // defines the end of the draw
	}

	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		
		glEnd(); // defines the end of the draw
	}

}

void HelloGL::Update()
{
	glutPostRedisplay();

}

HelloGL::~HelloGL(void)
{

}
