#include <GLUT/glut.h>
#include <string>

void renderBitmapString(float x, float y, void *font, const std::string& str) {
	glRasterPos2f(x, y);
	for (auto c : str) {
		glutBitmapCharacter(font, c);
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 1.0f, 1.0f);  // white text

	// Render 5 lines of "hello, world"
	for (int i = 0; i < 5; ++i) {
		float y = 0.9f - static_cast<float>(i) * 0.2f; // vertical spacing
		renderBitmapString(-0.9f, y, GLUT_BITMAP_HELVETICA_18, "hello, world");
	}

	glFlush();
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);  // black background
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // 2D coordinate system
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("GLUT Hello World x5");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
