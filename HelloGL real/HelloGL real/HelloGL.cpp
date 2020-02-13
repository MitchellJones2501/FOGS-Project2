//DO THE REST OF WEEK 2 14-2

#include "HelloGL.h"
#include "GLUTCallbacks.h"
HelloGL::HelloGL(int argc, char* argv[])
{
	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	rotation = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(1920, 1080);
	glutCreateWindow("Simple OpenGL Program");
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Set the viewport to be the entire window
	//Set the correct perspective 
	glViewport(0, 0, 1920, 1080);

	gluPerspective(45, 1, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	/*glutInitWindowPosition(100, 100);*/
	

	glutMainLoop();

}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT); //this clears the scene
		DrawSqu(); //draw polygon
		DrawTri(); 
	glFlush(); //flushes the scene drawn to the graphics card

	glutSwapBuffers();

}

void HelloGL::DrawSqu()
{
	glPushMatrix();
	glRotatef(rotation, 1.0f, 0.0f, 0.0f);
	glutWireTeapot(0.01);
	//glTranslatef(0.0f, 0.0f, 10.0f);
	//glRotatef(rotation, 0.0f, 0.0f, 1.0f);
	//glBegin(GL_POLYGON);
	//{
	//	//glColor4f(0.0f, 2.0f, 5.0f, 0.0f);
	//	//glVertex2f(0.75, 0.5);
	//	//glVertex2f(-0.75, 0.5);
	//	//glVertex2f(-0.75, -0.5);
	//	//glVertex2f(0.75, -0.5);
	//	//glEnd(); // defines the end of the draw
	//	
	//}
	
	
	

	glPopMatrix();
}

void HelloGL::DrawTri() {

	glPushMatrix();

	glRotatef(rotation, -1.0f, 0.0f, 0.0f);
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
	/*glLoadIdentity();
	glutPostRedisplay();
	if (rotation >= 360.0f)
		rotation = 0.0f;*/
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);

	glutPostRedisplay();
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
		rotation += 0.5f;

	if (key == 'a')
		rotation += -0.5f;
}

HelloGL::~HelloGL(void)
{

}
