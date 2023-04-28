#include <cstdio>

#include <GL/gl.h>
#include <GL/glut.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

#define PI 3.1416

using namespace std;

float cloud1Position = 0.0f;
GLfloat cloud1Speed = 0.01f;

float cloud2Position = 0.0f;
GLfloat cloud2Speed = 0.07f;

float cloud3Position = 0.0f;
GLfloat cloud3Speed = 0.03f;

float rightWavePosition1 = 0.0f;
GLfloat rightWaveSpeed1 = 0.072f;

float rightWavePosition2 = 0.0f;
GLfloat rightWaveSpeed2 = 0.062f;

float boatPosition = 0.0f;
GLfloat boatSpeed = 0.02f;

/*
void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed += 0.1f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}

	glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

case 'a':
    speed = 0.0f;
    break;
case 'w':
    speed += 0.1f;
    break;


glutPostRedisplay();

	}
}*/

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}


void DrawCircle(float cx, float cy, float r, int num_segments){
    num_segments = 200;
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++){
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();
}


void cloud1Update(int value) {
    if(cloud1Position > 1.8f)
        cloud1Position = -0.5f;

    cloud1Position += cloud1Speed;

	glutPostRedisplay();

	glutTimerFunc(100, cloud1Update, 0);
}

void cloud2Update(int value) {
    if(cloud2Position < -1.8)
        cloud2Position = +0.5f;

    cloud2Position -= cloud2Speed;

	glutPostRedisplay();

	glutTimerFunc(100, cloud2Update, 0);
}

void cloud3Update(int value) {
    if(cloud3Position < -0.4)//
        cloud3Position = +1.9f;

    cloud3Position -= cloud3Speed;

	glutPostRedisplay();

	glutTimerFunc(100, cloud3Update, 0);
}

void rightWaveUpdate1(int value) {
    if(rightWavePosition1 > 1.0)//1.7
        rightWavePosition1 = -1.0f; // -1.6

    rightWavePosition1 += rightWaveSpeed1;

	glutPostRedisplay();

	glutTimerFunc(100, rightWaveUpdate1, 0);
}

void rightWaveUpdate2(int value) {
    if(rightWavePosition2 > 1.0)
        rightWavePosition2 = -1.0f;

    rightWavePosition2 += rightWaveSpeed2;

	glutPostRedisplay();

	glutTimerFunc(100, rightWaveUpdate2, 0);
}

void boatUpdate(int value) {
    if(boatPosition > 0.7)
        boatPosition = -1.8f;

    boatPosition += boatSpeed;

	glutPostRedisplay();

	glutTimerFunc(100, boatUpdate, 0);
}

void summerSeason() {

    // All drawing related to summer will be performed in this block
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Sky Drawing will start from here
    // This block creates a gradient of the sky

    glBegin(GL_POLYGON);
    glColor3ub(146, 194, 213);
    glVertex2f(-1, 1);
    glVertex2f(-0.5, 1);
    glVertex2f(0, 1);
    glVertex2f(0.5, 1);
    glVertex2f(1, 1);
    glVertex2f(1, 0.75);
    glVertex2f(1, 0.5);
    glVertex2f(1, 0.25);

    glColor3ub(213, 237, 247);
    glVertex2f(1, 0);
    glVertex2f(0.5, 0);
    glVertex2f(0, 0);
    glVertex2f(-0.5, 0);
    glVertex2f(-1, 0);
    glVertex2f(-1, 0.25);
    glVertex2f(-1, 0.5);
    glVertex2f(-1, 0.75);
    glEnd();

    // Sky Drawing ends here

    // ======================================================

    // Drawing clouds start from here

    // Cloud 1 starts from here


    glPushMatrix();
    glTranslatef(cloud1Position, 0.0f, 0.0f);
    glColor3f(1.0, 1.0, 1.0);
	DrawCircle(-0.3799673933028, 0.5780739267177, 0.0653084338854, 2000);//1
    DrawCircle(-0.4599673933028, 0.5829705293098, 0.0995776305031, 2000);//2
	DrawCircle(-0.3099673933028, 0.5886832323339, 0.0783838868466, 2000);//3
    glPopMatrix();

    // Cloud 1 ends here

    // Cloud 2 Starts from here

    glPushMatrix();
    glTranslatef(cloud2Position, 0.0f, 0.0f);
    glColor3f(1.0, 1.0, 1.0);
    DrawCircle(-0.3799673933028+1.0, 0.5780739267177+0.2, 0.0653084338854, 2000);//1
	DrawCircle(-0.4599673933028+1.0, 0.5829705293098+0.2, 0.0995776305031, 2000);//2
	DrawCircle(-0.3099673933028+1.0, 0.5886832323339+0.2, 0.0783838868466, 2000);//3
    glPopMatrix();

	// Cloud 2 ends here

	// Cloud 3 starts from here

    glPushMatrix();
    glTranslatef(cloud3Position, 0.0f, 0.0f);
	glColor3f(1.0, 1.0, 1.0);
	DrawCircle(-0.3799673933028-0.35, 0.5780739267177+0.3, 0.0653084338854, 2000);//1
	DrawCircle(-0.4599673933028-0.35, 0.5829705293098+0.3, 0.0995776305031, 2000);//2
    glPopMatrix();

    // Cloud 3 ends here

    // Drawing clouds ends here

    // =================================================

    // Drawing Mountains start here

    // Mountain 1 - Most back mountain starts from here

    glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
    glVertex2f(0.3929401421717, 0.4485380502278); //W
    glVertex2f(0.5526843286014, 0.3768483130035+0.04); //J
    glVertex2f(0.670801460241, 0.2971879218977-0.03); //K
    glVertex2f(0.9372517339395, 0.1928053404488+0.04); //L
    glVertex2f(1, 0.1680831501056); //M
    glVertex2f(1.0, -0.1533053243555); //H
    glVertex2f(0.3929401421717, -0.1533053243555); //N
    glVertex2f(0.3929401421717, 0.4485380502278); //W
    glEnd();

    // Mountain 1 ends here

    // Mountain 2 - Middle mountain above most back starts from here

    glBegin(GL_POLYGON);
    glColor3ub(145, 145, 145);
    glVertex2f(-0.6786421718519, 0.2908236747635); //R
    glVertex2f(-0.5147937620031, 0.2355724667912); //S
    glVertex2f(-0.2385377221418, 0.3174966717156); //T
    glVertex2f(-0.0175328902527, 0.4470512283403); //U
    glVertex2f(0.0508032420971, 0.4149952168872); //V
    glVertex2f(0.3929401421717, 0.4485380502278); //W
    glVertex2f(0.5271114755343, 0.2942410168609); //Z
    glVertex2f(0.5371743255365, 0.2103839335092); //A
    glVertex2f(0.6814085089013, 0.1869039501708); //B
    glVertex2f(1.0, -0.1533053243555); // Base +x
    glVertex2f(-1.0, -0.1533053243555); // Base -x
    glVertex2f(-1.0, 0.2367559010589);
    glVertex2f(-0.6786421718519, 0.2908236747635);
    glEnd();

    // Mountain 2 ends here

    // Mountain 3 - small mountain all over the canvas starts from here

    glBegin(GL_POLYGON);
    glColor3ub(129, 129, 129);
    glVertex2f(-1, 0.1181319694005); //O
    glVertex2f(-0.5522115367946, 0.1827085088733); //P
    glVertex2f(-0.3539971566934, 0.1461150848547); //Q
    glVertex2f(-0.1379810070822, 0.0186226010721); //Z
    glVertex2f(-0.0401914318869, 0.0622849666483); //A1
    glVertex2f(0.1486818628493, 0.1780904904282); //B1
    glVertex2f(0.2915301969001, 0.1508367214239); //C1
    glVertex2f(0.3888177958833, 0.0993671672354); //D1
    glVertex2f(0.596384185652, 0.1262366028041); //E1
    glVertex2f(0.7699372091346, 0.0995241984756); //F1
    glVertex2f(1.0, 0.0986099427594); // G1
    glVertex2f(1.0, -0.1533053243555); // Base +x
    glVertex2f(-1.0, -0.1533053243555); // Base -x
    glVertex2f(-1, 0.1181319694005); //O
    glEnd();

    // Mountain 3 code ends here

    // Mountain 4 - most front mountain pt1 code starts from here

    glBegin(GL_POLYGON);
    glColor3ub(114, 114, 114);
    glVertex2f(-0.8012095319951, -0.1533053243555); //O
    glVertex2f(-0.6569896481988, -0.0378583357216); //P
    glVertex2f(-0.5769625910181, -0.0378583357216); //Q
    glVertex2f(-0.4688891067114, 0.063441322636); //Z
    glVertex2f(-0.4129803119442, 0.0170298865176); //A1
    glVertex2f(-0.15, -0.05); //B1
    glVertex2f(0.002145333951, -0.0238972141692); //C1
    glVertex2f(0.2405601730378, -0.0843732618176); //D1
    glVertex2f(0.3658944460086, -0.1533053243555); //E1
    glVertex2f(-0.8012095319951, -0.1533053243555); //F1
    glEnd();

    // Mountain 4 - pt 1 code ends here

    // Mountain 4 - pt 2 code starts from here

    glBegin(GL_POLYGON);
    glColor3ub(114, 114, 114);
    glVertex2f(0.4960794220775, -0.1533053243555); //O
    glVertex2f(0.5660816401225, -0.0919204959119); //P
    glVertex2f(0.7615044988316, -0.0598361459746); //Q
    glVertex2f(1, 0.011624451613); //Z
    glVertex2f(1, -0.1533053243555); //A1
    glVertex2f(0.4960794220775, -0.1533053243555); //B1
    glEnd();

    // Mountain 4 - pt 2 code ends here

    // Mountain code ends here

    //====================================================================

    // River code starts from here

    // River water code starts here

    glBegin(GL_POLYGON);
    glColor3ub(110, 164, 221);
    glVertex2f(-1.0, -0.1533053243555); // Base -x up
    glVertex2f(1.0, -0.1533053243555); // Base +x up
    glVertex2f(1.0, -0.5756367057105); // Base +x down
    glVertex2f(-1.0, -0.5756367057105); // Base -x down
    glVertex2f(-1.0, -0.1533053243555); // ending at beginning
    glEnd();

    // River water code ends here

    // Wave set code starts here


    glPushMatrix();
    glTranslatef(rightWavePosition1,0.0f, 0.0f);

    glBegin(GL_TRIANGLES);
    glColor3ub(190, 220, 220);
    glVertex2f(-0.6, -0.3);
    glVertex2f(-0.4, -0.3);
    glVertex2f(-0.5, -0.275);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(190, 220, 220);
    glVertex2f(0.6, -0.3);
    glVertex2f(0.8, -0.3);
    glVertex2f(0.7, -0.275);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(190, 220, 220);
    glVertex2f(-0.9, -0.4);
    glVertex2f(-0.7, -0.4);
    glVertex2f(-0.8, -0.375);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(190, 220, 220);
    glVertex2f(0.3, -0.4);
    glVertex2f(0.5, -0.4);
    glVertex2f(0.4, -0.375);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(190, 220, 220);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.3, -0.5);
    glVertex2f(-0.4, -0.475);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(190, 220, 220);
    glVertex2f(0.7, -0.5);
    glVertex2f(0.9, -0.5);
    glVertex2f(0.8, -0.475);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(rightWavePosition2,0.0f, 0.0f);

    glBegin(GL_TRIANGLES);
    glColor3ub(190, 220, 220);
    glVertex2f(0.0, -0.3);
    glVertex2f(0.2, -0.3);
    glVertex2f(0.1, -0.275);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(190, 220, 220);
    glVertex2f(-0.3, -0.4);
    glVertex2f(-0.1, -0.4);
    glVertex2f(-0.2, -0.375);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(190, 220, 220);
    glVertex2f(0.1, -0.5);
    glVertex2f(0.3, -0.5);
    glVertex2f(0.2, -0.475);
    glEnd();

    glPopMatrix();

    // Wave set code ENDS here

    // River code ends here

    // ===============================================

    // Boar code starts from here

    glPushMatrix();
    glTranslatef(boatPosition,0.0f, 0.0f);

    // Bottom haul of the boat //501
    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
    glVertex2f(0.36f, -0.37f);
    glVertex2f(0.77f, -0.37f);
    glVertex2f(0.77f, -0.35f);
    glVertex2f(0.36f, -0.35f);
    glEnd();

    // Middle haul of the boat
   glBegin(GL_QUADS);
   glColor3ub(138, 3, 42);
   glVertex2f(0.36f, -0.35f);
   glVertex2f(0.77f, -0.35f);
   glVertex2f(0.77f, -0.33f);
   glVertex2f(0.36f, -0.33f);
   glEnd();

    // 1st flr of boat
   glBegin(GL_QUADS);
   glColor3ub(250, 250, 150);
   glVertex2f(0.45f, -0.33f);
   glVertex2f(0.72f, -0.33f);
   glVertex2f(0.72f, -0.25f);
   glVertex2f(0.45f, -0.25f);
   glEnd();

   // body design stripe on 1st flr of boat
   glBegin(GL_QUADS);
   glColor3ub(200, 40, 90);
   glVertex2f(0.45f, -0.3f);
   glVertex2f(0.72f, -0.3f);
   glVertex2f(0.72f, -0.29f);
   glVertex2f(0.45f, -0.29f);
   glEnd();

   // 1st flr door
   glBegin(GL_QUADS);
   glColor3ub(60, 70, 180);
   glVertex2f(0.51f, -0.33f);
   glVertex2f(0.54f, -0.33f);
   glVertex2f(0.54f, -0.27f);
   glVertex2f(0.51f, -0.27f);
   glEnd();

   // front haul of boat
   glBegin(GL_QUADS);
   glColor3ub(138, 3, 42);
   glVertex2f(0.58f, -0.33f);
   glVertex2f(0.77f, -0.33f);
   glVertex2f(0.82f, -0.29f);
   glVertex2f(0.63f, -0.29f);
   glEnd();

   // Roof of first flr
   glBegin(GL_QUADS);
   glColor3ub(181, 57, 57);
   glVertex2f(0.43f, -0.25f);
   glVertex2f(0.74f, -0.25f);
   glVertex2f(0.74f, -0.23f);
   glVertex2f(0.43f, -0.23f);
   glEnd();

   // 2nd flr left small block
   glBegin(GL_QUADS);
   glColor3ub(250, 250, 150);
   glVertex2f(0.52f, -0.23f);
   glVertex2f(0.56f, -0.23f);
   glVertex2f(0.56f, -0.18f);
   glVertex2f(0.52f, -0.18f);
   glEnd();

   //2nd flr right big block
   glBegin(GL_QUADS);
   glColor3ub(250, 250, 150);
   glVertex2f(0.56f, -0.23f);
   glVertex2f(0.71f, -0.23f);
   glVertex2f(0.71f, -0.16f);
   glVertex2f(0.56f, -0.16f);
   glEnd();

   // 2nd flr door
   glBegin(GL_QUADS);
   glColor3ub(60, 70, 180);
   glVertex2f(0.64f, -0.23f);
   glVertex2f(0.67f, -0.23f);
   glVertex2f(0.67f, -0.17f);
   glVertex2f(0.64f, -0.17f);
   glEnd();

   // 2nd flr door window
   glBegin(GL_QUADS);
   glColor3ub(200, 40, 90);
   glVertex2f(0.65f, -0.20f);
   glVertex2f(0.662f, -0.20f);
   glVertex2f(0.662f, -0.18f);
   glVertex2f(0.65f, -0.18f);
   glEnd();

   // 2nd flr big window
   glBegin(GL_QUADS);
   glColor3ub(200, 40, 90);
   glVertex2f(0.59f, -0.20f);
   glVertex2f(0.63f, -0.20f);
   glVertex2f(0.63f, -0.17f);
   glVertex2f(0.59f, -0.17f);
   glEnd();

   // 2nd flr small window
   glBegin(GL_QUADS);
   glColor3ub(200, 40, 90);
   glVertex2f(0.68f, -0.20f);
   glVertex2f(0.70f, -0.20f);
   glVertex2f(0.70f, -0.17f);
   glVertex2f(0.68f, -0.17f);
   glEnd();

   //2nd flr big block roof
   glBegin(GL_QUADS);
   glColor3ub(181, 57, 57);
   glVertex2f(0.55f, -0.16f);
   glVertex2f(0.72f, -0.16f);
   glVertex2f(0.72f, -0.15f);
   glVertex2f(0.55f, -0.15f);
   glEnd();

   //Top roof above 2nd flr big block roof
   glBegin(GL_QUADS);
   glColor3ub(138, 3, 42);
   glVertex2f(0.55f, -0.15f);
   glVertex2f(0.73f, -0.15f);
   glVertex2f(0.74f, -0.14f);
   glVertex2f(0.55f, -0.14f);
   glEnd();

   //2nd flr small block roof
   glBegin(GL_QUADS);
   glColor3ub(181, 57, 57);
   glVertex2f(0.50f, -0.18f);
   glVertex2f(0.58f, -0.18f);
   glVertex2f(0.58f, -0.17f);
   glVertex2f(0.50f, -0.17f);
   glEnd();

   // Back fence code section starts here
   glBegin(GL_QUADS);
   glColor3ub(60, 160, 160);
   glVertex2f(0.38f, -0.33f);
   glVertex2f(0.41f, -0.33f);
   glVertex2f(0.41f, -0.32f);
   glVertex2f(0.38f, -0.32f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(60, 160, 160);
   glVertex2f(0.41f, -0.33f);
   glVertex2f(0.43f, -0.33f);
   glVertex2f(0.43f, -0.32f);
   glVertex2f(0.41f, -0.32f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(60, 160, 160);
   glVertex2f(0.43f, -0.33f);
   glVertex2f(0.45f, -0.33f);
   glVertex2f(0.45f, -0.32f);
   glVertex2f(0.43f, -0.32f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(60, 160, 160);
   glVertex2f(0.38f, -0.32f);
   glVertex2f(0.41f, -0.32f);
   glVertex2f(0.41f, -0.31f);
   glVertex2f(0.38f, -0.31f);
   glEnd();


   glBegin(GL_QUADS);
   glColor3ub(60, 160, 160);
   glVertex2f(0.43f, -0.32f);
   glVertex2f(0.45f, -0.32f);
   glVertex2f(0.45f, -0.31f);
   glVertex2f(0.43f, -0.31f);
   glEnd();

   glPopMatrix();

   // back fence code block ends here

   // Boat code ends here

   // ===========================================================

   glFlush();
}



int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(980, 700);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Natural Scenario");
   glutDisplayFunc(summerSeason);
   init();
   //glutKeyboardFunc(handleKeypress);
   //glutMouseFunc(handleMouse);
   glutTimerFunc(25, cloud1Update, 0);
   glutTimerFunc(25, cloud2Update, 0);
   glutTimerFunc(25, cloud3Update, 0);
   glutTimerFunc(25, rightWaveUpdate1, 0);
   glutTimerFunc(25, rightWaveUpdate2, 0);
   glutTimerFunc(25, boatUpdate, 0);
   glutMainLoop();
   return 0;
}
