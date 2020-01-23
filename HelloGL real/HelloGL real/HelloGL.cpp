//DO THE REST OF WEEK 2 14-2


#include "HelloGL.h"
#include "GLUTCallbacks.h"
HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutMainLoop();
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutSwapBuffers();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT); //this clears the scene
		DrawSqu(); //draw polygon
		DrawTri(); 
	glFlush(); //flushes the scene drawn to the graphics card
}

void HelloGL::DrawSqu()
{
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(0.0f, 2.0f, 5.0f, 0.0f);
		glVertex2f(0.75, 0.5);
		glVertex2f(-0.75, 0.5);
		glVertex2f(-0.75, -0.5);
		glVertex2f(0.75, -0.5);
		glEnd(); // defines the end of the draw
	}

	

	glPopMatrix();
}

void HelloGL::DrawTri() {

	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON); //starts to draw a polygon
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f); //sets colour
		glVertex2f(0.2, 0.6); //define the first point of the polygon, top left
		glVertex2f(0.1, 0.48); //next point, top righ
		glVertex2f(0.58, 0.28); //bottom right
		glEnd(); // defines the end of the draw
	}
	glPopMatrix();
}

void HelloGL::Update()
{
	glutPostRedisplay();
	rotation += 0.5f;
	if (rotation >= 360.0f)
		rotation = 0.0f;
}

HelloGL::~HelloGL(void)
{

}
