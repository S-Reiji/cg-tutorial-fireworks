#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include <math.h>
#define SHOOTING_TIME 60
#define SPREADING_TIME 80
#define KEY_ESC 27
#define PI acos(-1)

GLfloat light[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLboolean isLaunching = GL_FALSE;
GLboolean isSpread = GL_FALSE;
float particles[500][4]; //Theta, Phi, r, v
float fwX, fwY, fwZ;
float shootV;
float g = 0.000005f;
float resist = 0.000001f;

void keyboardPressEvent(unsigned char key, int x, int y) {
	if (key == ' ' && isLaunching == GL_FALSE) {
		glEnable(GL_LIGHT0);
		srand((unsigned)time(NULL));
		float r = rand();
		shootV = 0.01f;
		srand(r);
		fwX = (rand()%10)-5;
		fwY = 0.0f;
		srand(r);
		fwZ = (rand()%10)-5;
		srand(r);
		isLaunching = GL_TRUE;
	}
	else if (key == KEY_ESC) exit(0);
}

void drawParticle(int i) {
	glPushMatrix();

	if (particles[i][3] > 0.0f) {
		setParticlesMaterial(rand() % 7);

		float x = particles[i][2] * sin(particles[i][0]) * cos(particles[i][1]);
		float y = (particles[i][2] * sin(particles[i][0]) * sin(particles[i][1])) + (shootV/10.0);
		float z = particles[i][2] * cos(particles[i][0]);

		glTranslated(x, y, z);
		glutSolidSphere(0.1, 4, 2);
	}

	glPopMatrix();
}

void drawFireworks(void) {
	glPushMatrix();

	if (isLaunching == GL_TRUE) {
		glTranslatef(fwX, fwY, fwZ);
		glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, shootV);
		glLightfv(GL_LIGHT0, GL_POSITION, light);

		if (isSpread == GL_FALSE) {
			white();
			glutSolidSphere(0.1, 4, 2);
		}
		else if (GL_TRUE && isSpread == GL_TRUE) {
			for (int i = 0; i < 500; i++) {
				drawParticle(i);
			}
		}
	}

	glPopMatrix();
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	glPushMatrix();
	glTranslatef(0.0f, 10.0f, 0.0f);
	glLightfv(GL_LIGHT1, GL_POSITION, light);
	glPopMatrix();

	drawFireworks();

	glTranslatef(0.0, -1.0, 0.0);
	waterBlue();
	glPushMatrix();
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	int i, j;
	float x0, y0;
	for (i = -50; i < 50; i++) {
		x0 = 0.8 * (float)i;
		glBegin(GL_QUAD_STRIP);
		glNormal3f(0.0, 0.0, 1.0);
		for (j = -50; j < 50; j++) {
			y0 = 0.8 * (float)j;
			glVertex3f(x0, y0, 0.0);
			glVertex3f(x0 + 0.8, y0, 0.0);
		}
		glEnd();
	}
	glPopMatrix();

	glPopMatrix();
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glFlush();
}

void initParticles(void) {
	srand((unsigned)time(NULL));
	float r = rand();

	for (int i = 0; i < 500; i++) {
		// Theta
		srand(r);
		r = rand();
		particles[i][0] = (rand()%360) * (PI/180);
		// Phi
		srand(r);
		r = rand();
		particles[i][1] = (rand()%360) * (PI/180);
		// r
		particles[i][2] = 0.0f;
		// v
		srand(r);
		r = rand();
		particles[i][3] = (rand()%2+1) * 0.002f;
	}
}

void calcFireworks(void) {
	if (isSpread == GL_FALSE) {
		fwY = fwY + shootV;
		shootV = shootV - g;

		if (shootV <= 0) {
			initParticles();
			shootV = 0.0f;
			isSpread = GL_TRUE;
		}
	}
	else if (isSpread == GL_TRUE) {
		for (int i = 0; i < 500; i++) {
			if (shootV <= 0) shootV = 0.0f;
			else shootV = shootV - g;			
			particles[i][2] = particles[i][2] + particles[i][3];
			if (particles[i][3] <= 0) particles[i][3] = 0.0f;
			else particles[i][3] = particles[i][3] - resist;
		}
	}	
}

void checkFireworksAlive(void) {
	int temp = 0;

	for (int i = 0; i < 500; i++) {
		if (particles[i][3] <= 0) temp = temp + 1;
	}

	if (temp > 0) {
		fwX = fwY = fwZ = 0.0f;
		isLaunching = GL_FALSE;
		isSpread = GL_FALSE;
		glDisable(GL_LIGHT0);
	}
}

void idle(void) {
	if (isLaunching == GL_TRUE) {
		calcFireworks();
		if(isSpread == GL_TRUE) checkFireworksAlive();
		glutPostRedisplay();
	}
}

void initLighting(void) {
	GLfloat diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat light1_spot_exp = 0.0f;

	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, light1_spot_exp);	
	glEnable(GL_LIGHT1);
}

void initialize(char *progname) {
	int width = 500, height = 500;

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(progname);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glutKeyboardFunc(keyboardPressEvent);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (double)width / (double)height, 0.1, 50.0);
	gluLookAt(
		0.0, 20.0, 20.0,
		0.0, 5.0, 0.0,
		0.0, 1.0, 0.0
	);
	glMatrixMode(GL_MODELVIEW);
	glShadeModel(GL_SMOOTH);
	initLighting();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	initialize(argv[0]);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutMainLoop();
}