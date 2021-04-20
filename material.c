#include <GL/glut.h>

void red(void) {
	float diffuse[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	float specular[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	float ambient[] = { 0.25f, 0.0f, 0.0f, 1.0f };
	float shininess = 0.0f;

	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

void green(void) {
	float diffuse[] = { 0.0f, 1.0f, 0.0f, 1.0f };
	float specular[] = { 0.0f, 1.0f, 0.0f, 1.0f };
	float ambient[] = { 0.0f, 0.25f, 0.0f, 1.0f };
	float shininess = 0.0f;

	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

void blue(void) {
	float diffuse[] = { 0.0f, 0.0f, 1.0f, 1.0f };
	float specular[] = { 0.0f, 0.0f, 1.0f, 1.0f };
	float ambient[] = { 0.0f, 0.0f, 0.25f, 1.0f };
	float shininess = 0.0f;

	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

void yellow(void) {
	float diffuse[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	float specular[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	float ambient[] = { 0.25f, 0.25f, 0.0f, 1.0f };
	float shininess = 0.0f;

	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

void magenta(void) {
	float diffuse[] = { 1.0f, 0.0f, 1.0f, 1.0f };
	float specular[] = { 1.0f, 0.0f, 1.0f, 1.0f };
	float ambient[] = { 0.25f, 0.0f, 0.25f, 1.0f };
	float shininess = 0.0f;

	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

void cyan(void) {
	float diffuse[] = { 0.0f, 1.0f, 1.0f, 1.0f };
	float specular[] = { 0.0f, 1.0f, 1.0f, 1.0f };
	float ambient[] = { 0.0f, 0.25f, 0.25f, 1.0f };
	float shininess = 0.0f;

	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

void white(void) {
	float diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float ambient[] = { 0.25f, 0.25f, 0.25f, 1.0f };
	float shininess = 0.0f;

	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

void setParticlesMaterial(int value) {
	switch (value) {
	case 0:
		red();
		break;
	case 1:
		green();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
	default:
		break;
	}
}

void waterBlue(void) {
	float diffuse[] = { 0.1f, 0.3f, 0.9f, 1.0f };
	float specular[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	float ambient[] = { 0.7f, 0.8f, 0.9f, 1.0f };
	float shininess = 64.0f;

	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}