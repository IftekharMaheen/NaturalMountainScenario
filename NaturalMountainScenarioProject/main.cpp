#include <cstdio>

#include <GL/gl.h>
#include <GL/glut.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <windows.h>
#include <MMSystem.h>

#define PI 3.1416

using namespace std;

float cloud1Position = 0.0f;
GLfloat cloud1Speed = 0.01f;

float cloud2Position = 0.0f;
GLfloat cloud2Speed = 0.014f;

float cloud3Position = 0.0f;
GLfloat cloud3Speed = 0.007f;

float rightWavePosition1 = 0.0f;
GLfloat rightWaveSpeed1 = 0.072f;

float rightWavePosition2 = 0.0f;
GLfloat rightWaveSpeed2 = 0.062f;

float boatPosition = 0.0f;
GLfloat boatSpeed = 0.02f;

float trainPosition = 0.0f;
GLfloat trainSpeed = 0.02f;

float planePosition = 0.0f;
GLfloat planeSpeed = 0.012f;

float birdPosition = 0.0f;
GLfloat birdSpeed = 0.016f;

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void DrawCircle(float cx, float cy, float r, int num_segments){
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++){
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();
}

// ============== Update Functions =================
void cloud1Update(int value) {
    if(cloud1Position > 1.6f)
        cloud1Position = -0.8f;

    cloud1Position += cloud1Speed;

	glutPostRedisplay();

	glutTimerFunc(100, cloud1Update, 0);
}

void cloud2Update(int value) {
    if(cloud2Position < -1.8)
        cloud2Position = +0.7f;

    cloud2Position -= cloud2Speed;

	glutPostRedisplay();

	glutTimerFunc(100, cloud2Update, 0);
}

void cloud3Update(int value) {
    if(cloud3Position < -0.4)
        cloud3Position = +1.9f;

    cloud3Position -= cloud3Speed;

	glutPostRedisplay();

	glutTimerFunc(100, cloud3Update, 0);
}

void rightWaveUpdate1(int value) {
    if(rightWavePosition1 > 1.0)
        rightWavePosition1 = -1.0f;

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

void trainUpdate(int value) {
    if(trainPosition < -2.0)
        trainPosition = 1.1f;

    trainPosition -= trainSpeed;

	glutPostRedisplay();

	glutTimerFunc(100, trainUpdate, 0);
}

void planeUpdate(int value) {

    if(planePosition < -1.9)
        planePosition = 0.6f;

    planePosition -= planeSpeed;

	glutPostRedisplay();

	glutTimerFunc(100, planeUpdate, 0);
}

void birdUpdate(int value) {

    if(birdPosition < -2.0)
        birdPosition = 0.4f;

    birdPosition -= birdSpeed;

	glutPostRedisplay();

	glutTimerFunc(100, birdUpdate, 0);
}

// ================================================================

// Audio section starts here

void boatHonkSound()
{
    PlaySound(TEXT("boatHonk.wav"), NULL, SND_ASYNC);
}

void bird()
{
    PlaySound(TEXT("birds.wav"), NULL, SND_ASYNC);
}

// Audio section ends here

// ================================================================

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

    // Sun drawing code starts here

    glColor3ub(253, 218, 113);
	DrawCircle(-0.7356168493546, 0.5864996734224, 0.1620605572764, 2000);

    // Sun drawing code ends here

    // =================================================

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
    glPushMatrix();
    glTranslatef(rightWavePosition1,0.0f, 0.0f);
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

    // Boat code starts from here

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
   glColor3ub(244, 244, 244);
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
   glColor3ub(82, 82, 82);
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
   glColor3ub(244, 244, 244);
   glVertex2f(0.52f, -0.23f);
   glVertex2f(0.56f, -0.23f);
   glVertex2f(0.56f, -0.18f);
   glVertex2f(0.52f, -0.18f);
   glEnd();

   //2nd flr right big block
   glBegin(GL_QUADS);
   glColor3ub(244, 244, 244);
   glVertex2f(0.56f, -0.23f);
   glVertex2f(0.71f, -0.23f);
   glVertex2f(0.71f, -0.16f);
   glVertex2f(0.56f, -0.16f);
   glEnd();

   // 2nd flr door
   glBegin(GL_QUADS);
   glColor3ub(82, 82, 82);
   glVertex2f(0.64f, -0.23f);
   glVertex2f(0.67f, -0.23f);
   glVertex2f(0.67f, -0.17f);
   glVertex2f(0.64f, -0.17f);
   glEnd();

   // 2nd flr door window
   glBegin(GL_QUADS);
   glColor3ub(100, 204, 204);
   glVertex2f(0.65f, -0.20f);
   glVertex2f(0.662f, -0.20f);
   glVertex2f(0.662f, -0.18f);
   glVertex2f(0.65f, -0.18f);
   glEnd();

   // 2nd flr big window
   glBegin(GL_QUADS);
   glColor3ub(100, 204, 204);
   glVertex2f(0.59f, -0.20f);
   glVertex2f(0.63f, -0.20f);
   glVertex2f(0.63f, -0.17f);
   glVertex2f(0.59f, -0.17f);
   glEnd();

   // 2nd flr small window
   glBegin(GL_QUADS);
   glColor3ub(100, 204, 204);
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
   glColor3ub(5, 166, 96);
   glVertex2f(0.38f, -0.33f);
   glVertex2f(0.41f, -0.33f);
   glVertex2f(0.41f, -0.32f);
   glVertex2f(0.38f, -0.32f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(5, 166, 96);
   glVertex2f(0.41f, -0.33f);
   glVertex2f(0.43f, -0.33f);
   glVertex2f(0.43f, -0.32f);
   glVertex2f(0.41f, -0.32f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(5, 166, 96);
   glVertex2f(0.43f, -0.33f);
   glVertex2f(0.45f, -0.33f);
   glVertex2f(0.45f, -0.32f);
   glVertex2f(0.43f, -0.32f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(5, 166, 96);
   glVertex2f(0.38f, -0.32f);
   glVertex2f(0.41f, -0.32f);
   glVertex2f(0.41f, -0.31f);
   glVertex2f(0.38f, -0.31f);
   glEnd();


   glBegin(GL_QUADS);
   glColor3ub(5, 166, 96);
   glVertex2f(0.43f, -0.32f);
   glVertex2f(0.45f, -0.32f);
   glVertex2f(0.45f, -0.31f);
   glVertex2f(0.43f, -0.31f);
   glEnd();

   glPopMatrix();

   // back fence code block ends here

   // Boat code ends here

   // ===========================================================

   // Back tree row common fill code starts here

   glBegin(GL_QUADS);
   glColor3ub(61, 124, 83);
   glVertex2f(1.0, -0.5756367057105); // Base +x down
   glVertex2f(-1.0, -0.5756367057105); // Base -x down
   glVertex2f(-1.0, -0.6869004722551);
   glVertex2f(1.0, -0.6869004722551);
   glEnd();

   // Back tree row common fill code ends here

   // Bush code starts here

   glColor3ub(61, 124, 83);
	DrawCircle(-0.9072372816471, -0.5468327234769, 0.0978210355299, 2000);//1
    DrawCircle(-0.7882306545015, -0.5235785549542, 0.0951840734353, 2000);//2
	DrawCircle(-0.6500735356314, -0.5372574776146, 0.096724589725, 2000);//3
	DrawCircle(-0.5283311239537, -0.4934849251013, 0.108227857386, 2000);//4
	DrawCircle(-0.3696556210929, -0.5317859085505, 0.1003328230094, 2000);//5
	DrawCircle(-0.2219232563605, -0.5673511074675, 0.1262189788627, 2000);//6
	DrawCircle(-0.0315276315684, -0.4951186711054, 0.1503734194491, 2000);//7
	DrawCircle(0.0896782091289, -0.4385559454467, 0.0983021794995, 2000);//8
	DrawCircle(0.1769464144309, -0.4838061259736, 0.1155580437535, 2000);//9
	DrawCircle(0.2512859967253, -0.5322884622525, 0.096126072669, 2000);//10
	DrawCircle(0.3821883046783, -0.4870382817256, 0.1047961396401, 2000);//11
	DrawCircle(0.5003317807708, -0.5258241507487, 0.0740050744839, 2000);//12
	DrawCircle(0.644505499274, -0.4974731103267, 0.1039797036134, 2000);//13
	DrawCircle(0.7710785506579, -0.4841496312337, 0.093338673811, 2000);//14
	DrawCircle(0.7910637692975, -0.5557633313588, 0.117575444767, 2000);//15
	DrawCircle(0.9292948648878, -0.4641644125941, 0.1348282433764, 2000);//16

	// Bush Code ends here

   // ============================================================

   // Pine Tree code starts here

   // Ground grass color code starts here

   glBegin(GL_QUADS);
   glColor3ub(78, 133, 21);
   glVertex2f(-1.0, -0.6869004722551);
   glVertex2f(1.0, -0.6869004722551);
   glVertex2f(1.0, -1);
   glVertex2f(-1.0, -1);
   glEnd();

   // Ground grass color code ends here

   // tree 1 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2938571399917, -0.4423232979151);
   glVertex2f(-0.2115496244678, -0.5423834148265);
   glVertex2f(-0.3793924012224, -0.5415764783998);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2978918221252, -0.5084920849049);
   glVertex2f(-0.1841137859599, -0.5811163633083);
   glVertex2f(-0.3898825747696, -0.5762747447481);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3, -0.55);
   glVertex2f(-0.1792721673996, -0.6408296588845);
   glVertex2f(-0.3955311297565, -0.6335672310441);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3, -0.6);
   glVertex2f(-0.1740006707345, -0.6905816498292);
   glVertex2f(-0.4187989794158, -0.6869004722551);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136, -0.6973304753819);
   glVertex2f(-0.2825954091721, -0.6961034161905);
   glVertex2f(-0.2801412907893, -0.74886696142);
   glVertex2f(-0.3187936553179, -0.7494804910157);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3, -0.65);
   glVertex2f(-0.1574353716508, -0.7286204847622);
   glVertex2f(-0.4286154529469, -0.7292340143579);
   glEnd();

   // Tree 1 code ends here

   // tree 2 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2938571399917 + 0.3, -0.4423232979151);
   glVertex2f(-0.2115496244678 + 0.3, -0.5423834148265);
   glVertex2f(-0.3793924012224 + 0.3, -0.5415764783998);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2978918221252 + 0.3, -0.5084920849049);
   glVertex2f(-0.1841137859599 + 0.3, -0.5811163633083);
   glVertex2f(-0.3898825747696 + 0.3, -0.5762747447481);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.3, -0.55);
   glVertex2f(-0.1792721673996 + 0.3, -0.6408296588845);
   glVertex2f(-0.3955311297565 + 0.3, -0.6335672310441);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.3, -0.6);
   glVertex2f(-0.1740006707345 + 0.3, -0.6905816498292);
   glVertex2f(-0.4187989794158 + 0.3, -0.6869004722551);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136 + 0.3 , -0.6973304753819);
   glVertex2f(-0.2825954091721 + 0.3, -0.6961034161905);
   glVertex2f(-0.2801412907893 + 0.3, -0.74886696142);
   glVertex2f(-0.3187936553179 + 0.3, -0.7494804910157);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.3, -0.65);
   glVertex2f(-0.1574353716508 + 0.3, -0.7286204847622);
   glVertex2f(-0.4286154529469 + 0.3, -0.7292340143579);
   glEnd();

   // Tree 2 code ends here

   // tree 3 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2938571399917 + 0.6, -0.4423232979151);
   glVertex2f(-0.2115496244678 + 0.6, -0.5423834148265);
   glVertex2f(-0.3793924012224 + 0.6, -0.5415764783998);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2978918221252 + 0.6, -0.5084920849049);
   glVertex2f(-0.1841137859599 + 0.6, -0.5811163633083);
   glVertex2f(-0.3898825747696 + 0.6, -0.5762747447481);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.6, -0.55);
   glVertex2f(-0.1792721673996 + 0.6, -0.6408296588845);
   glVertex2f(-0.3955311297565 + 0.6, -0.6335672310441);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.6, -0.6);
   glVertex2f(-0.1740006707345 + 0.6, -0.6905816498292);
   glVertex2f(-0.4187989794158 + 0.6, -0.6869004722551);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136 + 0.6 , -0.6973304753819);
   glVertex2f(-0.2825954091721 + 0.6, -0.6961034161905);
   glVertex2f(-0.2801412907893 + 0.6, -0.74886696142);
   glVertex2f(-0.3187936553179 + 0.6, -0.7494804910157);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.6, -0.65);
   glVertex2f(-0.1574353716508 + 0.6, -0.7286204847622);
   glVertex2f(-0.4286154529469 + 0.6, -0.7292340143579);
   glEnd();

   // Tree 3 code ends here

      // tree 2 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2938571399917 + 0.3, -0.4423232979151);
   glVertex2f(-0.2115496244678 + 0.3, -0.5423834148265);
   glVertex2f(-0.3793924012224 + 0.3, -0.5415764783998);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2978918221252 + 0.3, -0.5084920849049);
   glVertex2f(-0.1841137859599 + 0.3, -0.5811163633083);
   glVertex2f(-0.3898825747696 + 0.3, -0.5762747447481);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.3, -0.55);
   glVertex2f(-0.1792721673996 + 0.3, -0.6408296588845);
   glVertex2f(-0.3955311297565 + 0.3, -0.6335672310441);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.3, -0.6);
   glVertex2f(-0.1740006707345 + 0.3, -0.6905816498292);
   glVertex2f(-0.4187989794158 + 0.3, -0.6869004722551);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136 + 0.3 , -0.6973304753819);
   glVertex2f(-0.2825954091721 + 0.3, -0.6961034161905);
   glVertex2f(-0.2801412907893 + 0.3, -0.74886696142);
   glVertex2f(-0.3187936553179 + 0.3, -0.7494804910157);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.3, -0.65);
   glVertex2f(-0.1574353716508 + 0.3, -0.7286204847622);
   glVertex2f(-0.4286154529469 + 0.3, -0.7292340143579);
   glEnd();

   // Tree 2 code ends here

   // tree 4 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2938571399917 + 0.9, -0.4423232979151);
   glVertex2f(-0.2115496244678 + 0.9, -0.5423834148265);
   glVertex2f(-0.3793924012224 + 0.9, -0.5415764783998);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2978918221252 + 0.9, -0.5084920849049);
   glVertex2f(-0.1841137859599 + 0.9, -0.5811163633083);
   glVertex2f(-0.3898825747696 + 0.9, -0.5762747447481);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.9, -0.55);
   glVertex2f(-0.1792721673996 + 0.9, -0.6408296588845);
   glVertex2f(-0.3955311297565 + 0.9, -0.6335672310441);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.9, -0.6);
   glVertex2f(-0.1740006707345 + 0.9, -0.6905816498292);
   glVertex2f(-0.4187989794158 + 0.9, -0.6869004722551);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136 + 0.9 , -0.6973304753819);
   glVertex2f(-0.2825954091721 + 0.9, -0.6961034161905);
   glVertex2f(-0.2801412907893 + 0.9, -0.74886696142);
   glVertex2f(-0.3187936553179 + 0.9, -0.7494804910157);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.9, -0.65);
   glVertex2f(-0.1574353716508 + 0.9, -0.7286204847622);
   glVertex2f(-0.4286154529469 + 0.9, -0.7292340143579);
   glEnd();

   // Tree 4 code ends here

      // tree 5 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2938571399917 + 1.2, -0.4423232979151);
   glVertex2f(-0.2115496244678 + 1.2, -0.5423834148265);
   glVertex2f(-0.3793924012224 + 1.2, -0.5415764783998);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2978918221252 + 1.2, -0.5084920849049);
   glVertex2f(-0.1841137859599 + 1.2, -0.5811163633083);
   glVertex2f(-0.3898825747696 + 1.2, -0.5762747447481);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 1.2, -0.55);
   glVertex2f(-0.1792721673996 + 1.2, -0.6408296588845);
   glVertex2f(-0.3955311297565 + 1.2, -0.6335672310441);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 1.2, -0.6);
   glVertex2f(-0.1740006707345 + 1.2, -0.6905816498292);
   glVertex2f(-0.4187989794158 + 1.2, -0.6869004722551);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136 + 1.2 , -0.6973304753819);
   glVertex2f(-0.2825954091721 + 1.2, -0.6961034161905);
   glVertex2f(-0.2801412907893 + 1.2, -0.74886696142);
   glVertex2f(-0.3187936553179 + 1.2, -0.7494804910157);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 1.2, -0.65);
   glVertex2f(-0.1574353716508 + 1.2, -0.7286204847622);
   glVertex2f(-0.4286154529469 + 1.2, -0.7292340143579);
   glEnd();

   // Tree 5 code ends here

   // tree 6 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2938571399917 - 0.3, -0.4423232979151 + 0.03);
   glVertex2f(-0.2115496244678 - 0.3, -0.5423834148265 + 0.03);
   glVertex2f(-0.3793924012224 - 0.3, -0.5415764783998 + 0.03);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2978918221252 - 0.3, -0.5084920849049 + 0.03);
   glVertex2f(-0.1841137859599 - 0.3, -0.5811163633083 + 0.03);
   glVertex2f(-0.3898825747696 - 0.3, -0.5762747447481 + 0.03);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 - 0.3, -0.55 + 0.03);
   glVertex2f(-0.1792721673996 - 0.3, -0.6408296588845 + 0.03);
   glVertex2f(-0.3955311297565 - 0.3, -0.6335672310441 + 0.03);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 - 0.3, -0.6);
   glVertex2f(-0.1740006707345 - 0.3, -0.6905816498292 + 0.03);
   glVertex2f(-0.4187989794158 - 0.3, -0.6869004722551 + 0.03);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136 - 0.3 , -0.6973304753819 + 0.03);
   glVertex2f(-0.2825954091721 - 0.3, -0.6961034161905 + 0.03);
   glVertex2f(-0.2801412907893 - 0.3, -0.74886696142 + 0.03);
   glVertex2f(-0.3187936553179 - 0.3, -0.7494804910157 + 0.03);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 - 0.3, -0.65);
   glVertex2f(-0.1574353716508 - 0.3, -0.7286204847622 + 0.03);
   glVertex2f(-0.4286154529469 - 0.3, -0.7292340143579 + 0.03);
   glEnd();

   // Tree 6 code ends here

      // tree 7 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2938571399917 - 0.6, -0.4423232979151);
   glVertex2f(-0.2115496244678 - 0.6, -0.5423834148265);
   glVertex2f(-0.3793924012224 - 0.6, -0.5415764783998);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2978918221252 - 0.6, -0.5084920849049);
   glVertex2f(-0.1841137859599 - 0.6, -0.5811163633083);
   glVertex2f(-0.3898825747696 - 0.6, -0.5762747447481);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 - 0.6, -0.55);
   glVertex2f(-0.1792721673996 - 0.6, -0.6408296588845);
   glVertex2f(-0.3955311297565 - 0.6, -0.6335672310441);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 - 0.6, -0.6);
   glVertex2f(-0.1740006707345 - 0.6, -0.6905816498292);
   glVertex2f(-0.4187989794158 - 0.6, -0.6869004722551);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136 - 0.6 , -0.6973304753819);
   glVertex2f(-0.2825954091721 - 0.6, -0.6961034161905);
   glVertex2f(-0.2801412907893 - 0.6, -0.74886696142);
   glVertex2f(-0.3187936553179 - 0.6, -0.7494804910157);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 - 0.6, -0.65);
   glVertex2f(-0.1574353716508 - 0.6, -0.7286204847622);
   glVertex2f(-0.4286154529469 - 0.6, -0.7292340143579);
   glEnd();

   // Tree 7 code ends here

   // Pine Tree code ends here

   // ================================================

   // Fence code starts here

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-1.0f, -0.95f + 0.15f);
      glVertex2f(1.0f, -0.95f + 0.15f);
      glVertex2f(1.0f, -0.93f + 0.15f);
      glVertex2f(-1.0f, -0.93f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-1.0f, -0.87f + 0.15f);
      glVertex2f(1.0f, -0.87f + 0.15f);
      glVertex2f(1.0f, -0.85f + 0.15f);
      glVertex2f(-1.0f, -0.85f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.92f, -0.98f + 0.15f);
      glVertex2f(-0.88f, -0.98f + 0.15f);
      glVertex2f(-0.88f, -0.82f + 0.15f);
      glVertex2f(-0.92f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.82f, -0.98f + 0.15f);
      glVertex2f(-0.79f, -0.98f + 0.15f);
      glVertex2f(-0.79f, -0.82f + 0.15f);
      glVertex2f(-0.82f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.72f, -0.98f + 0.15f);
      glVertex2f(-0.69f, -0.98f + 0.15f);
      glVertex2f(-0.69f, -0.82f + 0.15f);
      glVertex2f(-0.72f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.62f, -0.98f + 0.15f);
      glVertex2f(-0.59f, -0.98f + 0.15f);
      glVertex2f(-0.59f, -0.82f + 0.15f);
      glVertex2f(-0.62f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.52f, -0.98f + 0.15f);
      glVertex2f(-0.49f, -0.98f + 0.15f);
      glVertex2f(-0.49f, -0.82f + 0.15f);
      glVertex2f(-0.52f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.42f, -0.98f + 0.15f);
      glVertex2f(-0.39f, -0.98f + 0.15f);
      glVertex2f(-0.39f, -0.82f + 0.15f);
      glVertex2f(-0.42f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.32f, -0.98f + 0.15f);
      glVertex2f(-0.29f, -0.98f + 0.15f);
      glVertex2f(-0.29f, -0.82f + 0.15f);
      glVertex2f(-0.32f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.22f, -0.98f + 0.15f);
      glVertex2f(-0.19f, -0.98f + 0.15f);
      glVertex2f(-0.19f, -0.82f + 0.15f);
      glVertex2f(-0.22f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.12f, -0.98f + 0.15f);
      glVertex2f(-0.09f, -0.98f + 0.15f);
      glVertex2f(-0.09f, -0.82f + 0.15f);
      glVertex2f(-0.12f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.02f, -0.98f + 0.15f);
      glVertex2f(0.0f, -0.98f + 0.15f);
      glVertex2f(0.0f, -0.82f + 0.15f);
      glVertex2f(-0.02f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.12f, -0.98f + 0.15f);
      glVertex2f(0.09f, -0.98f + 0.15f);
      glVertex2f(0.09f, -0.82f + 0.15f);
      glVertex2f(0.12f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.22f, -0.98f + 0.15f);
      glVertex2f(0.19f, -0.98f + 0.15f);
      glVertex2f(0.19f, -0.82f + 0.15f);
      glVertex2f(0.22f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.32f, -0.98f + 0.15f);
      glVertex2f(0.29f, -0.98f + 0.15f);
      glVertex2f(0.29f, -0.82f + 0.15f);
      glVertex2f(0.32f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.42f, -0.98f + 0.15f);
      glVertex2f(0.39f, -0.98f + 0.15f);
      glVertex2f(0.39f, -0.82f + 0.15f);
      glVertex2f(0.42f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.52f, -0.98f + 0.15f);
      glVertex2f(0.49f, -0.98f + 0.15f);
      glVertex2f(0.49f, -0.82f + 0.15f);
      glVertex2f(0.52f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.62f, -0.98f + 0.15f);
      glVertex2f(0.59f, -0.98f + 0.15f);
      glVertex2f(0.59f, -0.82f + 0.15f);
      glVertex2f(0.62f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.72f, -0.98f + 0.15f);
      glVertex2f(0.69f, -0.98f + 0.15f);
      glVertex2f(0.69f, -0.82f + 0.15f);
      glVertex2f(0.72f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.82f, -0.98f + 0.15f);
      glVertex2f(0.79f, -0.98f + 0.15f);
      glVertex2f(0.79f, -0.82f + 0.15f);
      glVertex2f(0.82f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.92f, -0.98f + 0.15f);
      glVertex2f(0.89f, -0.98f + 0.15f);
      glVertex2f(0.89f, -0.82f + 0.15f);
      glVertex2f(0.92f, -0.82f + 0.15f);
    glEnd();

   // Fence Code ends here

   // =============================================================

   // Close Train code starts here

   // Train track code starts here

   glBegin(GL_QUADS);
   glColor3ub(123, 123, 123);
   glVertex2f(-1.0, -0.9599998637683);
   glVertex2f(-1.0, -0.9443483025884);
   glVertex2f(1.0, -0.9443483025884);
   glVertex2f(1.0, -0.9599998637683);
   glEnd();

   // Train track code ends here

   // ==================================================================

   // updated train model code starts here

   glPushMatrix();
   glTranslatef(trainPosition,0.0f, 0.0f);

   // Connector code
   glBegin(GL_QUADS);
   glColor3ub(201, 201, 201);
   glVertex2f(0.4588413119369, -0.7467275099806); //G9
   glVertex2f(0.4798857278648, -0.7467275099806); //H9
   glVertex2f(0.4798857278648, -0.9117251206329); //I9
   glVertex2f(0.4588413119369, -0.9117251206329); //J9
   glEnd();

   // left engine wheel code goes here

   //y = -0.9137316052198 for wheel center
   glColor3ub(82, 82, 82);
   // Back pair
   DrawCircle(0.2979740488535, -0.9361512437916, 0.023803337574, 8000);//1 - far left
   DrawCircle(0.2979740488535 + 0.0679267614286, -0.9361512437916, 0.023803337574, 8000);//1 - far left

   // Front pair
   DrawCircle(0.1140783890, -0.9361512437916, 0.023803337574, 8000);//1 - far left
   DrawCircle(0.1140783890 + 0.0679267614286, -0.9361512437916, 0.023803337574, 8000);//1 - far left

   //  left engine body code goes here
   glBegin(GL_POLYGON);
   glColor3ub(255, 92, 92);
   glVertex2f(0.0902750519795, -0.9243514184048); //V
   glVertex2f(0.2638419609981, -0.9243514184048); //Z
   glVertex2f(0.2638419609981, -0.9243514184048); //Z
   glVertex2f(0.2673071512138, -0.9172990967291); //T1
   glVertex2f(0.268625571989, -0.9152051343215); //U1
   glVertex2f(0.2704868719069, -0.9137316052198); //V1
   glVertex2f(0.2730461592941, -0.9135764968933); //W1
   glVertex2f(0.3883143036753, -0.9139417200826); //T2
   glVertex2f(0.3897577491135, -0.9142537476641); //U2
   glVertex2f(0.3910351937303, -0.9149161263543); //V2
   glVertex2f(0.392, -0.916); //W2
   glVertex2f(0.3973751040505, -0.9239055514352); //E8
   glVertex2f(0.4495081231461, -0.9243514184048); //F8
   glVertex2f(0.4517892659953, -0.9237467603624); //G8
   glVertex2f(0.4539527958094, -0.9226913799653); //H8
   glVertex2f(0.455535866405, -0.9215832305484); //I8
   glVertex2f(0.456644015822, -0.9201584670122); //J8
   glVertex2f(0.4573827821, -0.9185753964166); //K8
   glVertex2f(0.4573827821, -0.7408630998829); //L8
   glVertex2f(0.4580127024621, -0.7385660853445); //M8
   glVertex2f(0.4568244590262, -0.7365460715036); //N8
   glVertex2f(0.455, -0.735); //o8
   glVertex2f(0.4533191408905, -0.7341101724601); //P8
   glVertex2f(0.4508832418471, -0.733872523773); //Q8 - MAX Y VALUE
   glVertex2f(0.1311461118639, -0.733872523773); //S8
   glVertex2f(0.1269818194044, -0.7332398273495); //T8
   glVertex2f(0.1233172420401, -0.7345724009365); //U8
   glVertex2f(0.1196526646757, -0.7367378330155); //V8
   glVertex2f(0.1164878024065, -0.7390698367928); //W8
   glVertex2f(0.1134895118357, -0.7425678424587); //Z8
   glVertex2f(0.04, -0.866); //A9
   glVertex2f(0.0387581733414, -0.8689573745512); //B9
   glVertex2f(0.0382721983081, -0.8707068846711); //C9
   glVertex2f(0.0380172743025, -0.8741027234919); //A
   glVertex2f(0.0380487737159, -0.8776008690587); //H
   glVertex2f(0.0387481261355, -0.8810976311566); //I
   glVertex2f(0.0397971547648, -0.8848275107277); //L
   glVertex2f(0.0413124183406, -0.888207714089); //M
   glVertex2f(0.0432939168627, -0.8913547999771); //N
   glVertex2f(0.0458582090679, -0.8952012382848); //O
   glVertex2f(0.0486556187462, -0.8981152066997); //P
   glVertex2f(0.0516980249696, -0.9007746742169); //Q
   glVertex2f(0.0566279964724, -0.9041024049814); //R
   glVertex2f(0.0689529252296, -0.9114973622357); //T
   glVertex2f(0.0902750519795, -0.9243514184048); //V
   glEnd();

   // left engine - engine master window code goes here
   glBegin(GL_POLYGON);
   glColor3ub(221, 255, 255);
   glVertex2f(0.1028258229583, -0.7605273722022); //G9
   glVertex2f(0.1045268049421, -0.7603038528659); //H9
   glVertex2f(0.1064892834981, -0.7600234987865); //I9
   glVertex2f(0.1076574254957, -0.7604907555856); //J9
   glVertex2f(0.1084517620541, -0.7616121719033); //K9
   glVertex2f(0.1088255674933, -0.7633877477396); //L9
   glVertex2f(0.0963670020494, -0.854308496056); //M9
   glVertex2f(0.0959840335848, -0.8561686285981); //N9
   glVertex2f(0.0952728064364, -0.857755212237); //O9
   glVertex2f(0.0940144814815, -0.8591229567532); //P9
   glVertex2f(0.0921543489394, -0.8600530230242); //Q9
   glVertex2f(0.081256053022, -0.8638552288953); //R9
   glVertex2f(0.0764584464475, -0.8650420401822); //S9
   glVertex2f(0.0707017648046, -0.8653097928167); //T9
   glVertex2f(0.0634724436716, -0.8650420401822); //U9
   glVertex2f(0.0578496383459, -0.8645065349131); //V9
   glVertex2f(0.0522268330203, -0.8633016480576); //W9
   glVertex2f(0.0434783774913, -0.8602687046815); //Z9
   glVertex2f(0.1028258229583, -0.7605273722022); //G9
   glEnd();

   // left engine - engine master door
   glBegin(GL_QUADS);
   glColor3ub(255, 255, 255);
   glVertex2f(0.1649363264379, -0.7736938476301); //G9
   glVertex2f(0.2210939998274, -0.7736938476301); //H9
   glVertex2f(0.2210939998274, -0.9108481653313); //I9
   glVertex2f(0.1649363264379, -0.9108481653313); //J9
   glEnd();

   // Left engine - main window
   glBegin(GL_QUADS);
   glColor3ub(255, 255, 255);
   glVertex2f(0.2329994395528, -0.7736938476301); //G9
   glVertex2f(0.4296313165988, -0.7736938476301); //H9
   glVertex2f(0.4296313165988, -0.8562788832022); //I9
   glVertex2f(0.2329994395528, -0.8562788832022); //J9
   glEnd();
   glBegin(GL_LINES);
   glColor3ub(0, 0, 0);
   glVertex2f(0.2329994395528, -0.8000048684736); //G9
   glVertex2f(0.4296313165988, -0.8000048684736); //H9
   glEnd();

   // Left Engine top Box code goes here
   glBegin(GL_QUADS);
   glColor3ub(246, 246, 246);
   glVertex2f(0.4341934243381, -0.733329040145); //G9
   glVertex2f(0.4341934243381, -0.7175755480725); //H9
   glVertex2f(0.1797273626565, -0.7175755480725); //I9
   glVertex2f(0.1797273626565, -0.733329040145); //J9
   glEnd();

   // Left engine code ends here

   // Middle carriage of train code goes here

   // Middle carriage wheel code
   glColor3ub(82, 82, 82);
   DrawCircle(0.6335635062646, -0.9361512437916, 0.023803337574, 8000);//1 - far left
   DrawCircle(0.6335635062646 + 0.0679267614286, -0.9361512437916, 0.023803337574, 8000);//1 - far left

   // Carriage body code
   glBegin(GL_POLYGON);
   glColor3ub(255, 92, 92);
   glVertex2f(0.4801758240852, -0.9191043740047); //I11
   glVertex2f(0.4809755595681, -0.9205862368113); //H11
   glVertex2f(0.482410379111, -0.9219975347223); //G11
   glVertex2f(0.4841257894728, -0.9232021159928); //J11
   glVertex2f(0.4855932943556, -0.9237627358357); //F11
   glVertex2f(0.4872381164666, -0.9240447934564); //E11
   glVertex2f(0.8489917039809, -0.9240447934564); //D11
   glVertex2f(0.8504746539721, -0.9242064673156); //C11
   glVertex2f(0.851715489679, -0.9234801244628); //B11
   glVertex2f(0.8527444753872, -0.9221787601848); //A11
   glVertex2f(0.8535010825255, -0.9205142244804); //Z10
   glVertex2f(0.8540128051614, -0.9188721651553); //W10
   glVertex2f(0.8541329302856, -0.9169501631667); //V10
   glVertex2f(0.8541329302856, -0.7405637387567); //U10
   glVertex2f(0.8529695509292, -0.7392606860364); //T10
   glVertex2f(0.8515268854173, -0.7376318701359); //S10
   glVertex2f(0.8501772950998, -0.736468430207); //R10
   glVertex2f(0.848455404005, -0.7353980654724); //Q10
   glVertex2f(0.8462043017123, -0.7345738841131); //P10
   glVertex2f(0.4873888670143, -0.7345738841131); //o10
   glVertex2f(0.485, -0.735); //N10
   glVertex2f(0.4831260743853, -0.7365778999664); //M10
   glVertex2f(0.4813790282259, -0.7385345916649); //L10
   glVertex2f(0.4801758240852, -0.7408406925953); //K19
   glVertex2f(0.4801758240852, -0.9191043740047); //I11
   glEnd();

   //top Box code goes here
   glBegin(GL_QUADS);
   glColor3ub(246, 246, 246);
   glVertex2f(0.5054866328459, -0.733329040145); //G9
   glVertex2f(0.5054866328459, -0.7175755480725); //H9
   glVertex2f(0.8286505622915, -0.7175755480725); //I9
   glVertex2f(0.8286505622915, -0.733329040145); //J9
   glEnd();

   // Left door
   glBegin(GL_QUADS);
   glColor3ub(255, 255, 255);
   glVertex2f(0.5003789366041, -0.7736938476301); //G9
   glVertex2f(0.600634048208, -0.7736938476301); //H9
   glVertex2f(0.600634048208, -0.9108481653313); //I9
   glVertex2f(0.5003789366041, -0.9108481653313); //J9
   glEnd();
   glBegin(GL_LINES);
   glColor3ub(0, 0, 0);
   glVertex2f(0.5505176318039, -0.7736938476301); //G9
   glVertex2f(0.5505176318039, -0.9108481653313); //H9
   glEnd();

   // Window
   glBegin(GL_QUADS);
   glColor3ub(255, 255, 255);
   glVertex2f(0.610621388717, -0.7736938476301); //G9
   glVertex2f(0.7222523746758, -0.7736938476301); //H9
   glVertex2f(0.7222523746758, -0.8562788832022); //I9
   glVertex2f(0.610621388717, -0.8562788832022); //J9
   glEnd();
   glBegin(GL_LINES);
   glColor3ub(0, 0, 0);
   glVertex2f(0.7222523746758, -0.8000048684736); //G9
   glVertex2f(0.610621388717, -0.8000048684736); //H9
   glEnd();

   // Right door
   glBegin(GL_QUADS);
   glColor3ub(255, 255, 255);
   glVertex2f(0.7323094782337, -0.7736938476301); //G9
   glVertex2f(0.8325645898376, -0.7736938476301); //H9
   glVertex2f(0.8325645898376, -0.9108481653313); //I9
   glVertex2f(0.7323094782337, -0.9108481653313); //J9
   glEnd();
   glBegin(GL_LINES);
   glColor3ub(0, 0, 0);
   glVertex2f(0.7824481734336, -0.7736938476301); //G9
   glVertex2f(0.7824481734336, -0.9108481653313); //H9
   glEnd();


   // Middle carriage code ends here

   glPopMatrix();

   // updated train model code ends here
/*
   // Train body code starts here
   glPushMatrix();
   glTranslatef(trainPosition,0.0f, 0.0f);

   // Train wheel - from left
   glColor3f(1.0, 1.0, 1.0);
   DrawCircle(0.5998821731765, -0.9361512437916, 0.0238494583195, 8000);//1 - far left
   DrawCircle(0.5998821731765+0.0817079239908, -0.9361512437916, 0.0238494583195, 8000);//2
   DrawCircle(0.5998821731765+0.0817079239908+0.0817079239908, -0.9361512437916, 0.0238494583195, 8000);//3
   DrawCircle(0.5998821731765+0.0817079239908+0.0817079239908+0.0817079239908, -0.9361512437916, 0.0238494583195, 8000);//4
   DrawCircle(0.5998821731765+0.0817079239908+0.0817079239908+0.0817079239908+0.0817079239908, -0.9361512437916, 0.0238494583195, 8000);//5

   // Train Body
   glBegin(GL_QUADS);
   glColor3ub(60, 160, 160);
   glVertex2f(0.541827936322, -0.9243514184048);
   glVertex2f(0.5877156024394, -0.6793877707164);
   glVertex2f(0.9772657599597, -0.6793877707164);
   glVertex2f(0.9775893048246, -0.9284275411587);
   glEnd();

   // Train nose
   glBegin(GL_TRIANGLES);
   glColor3ub(60, 160, 160);
   glVertex2f(0.541827936322, -0.9243514184048);
   glVertex2f(0.4812066770985 , -0.9243514184048);
   glVertex2f(0.541827936322+ 0.1, -0.8593877707164);
   glVertex2f(0.541827936322+ 0.1, -0.9284275411587);
   glEnd();

   //Train Front window
   glBegin(GL_QUADS);
   glColor3ub(0, 0, 0);
   glVertex2f(0.6332556280382, -0.7189713862838);
   glVertex2f(0.6328508059703, -0.8007454440108);
   glVertex2f(0.6328508059703 - 0.0674149961409, -0.8007454440108);
   glVertex2f(0.6332556280382 - 0.0527475137977, -0.7189713862838);
   glEnd();

   //Train Front door
   glBegin(GL_QUADS);
   glColor3ub(0, 0, 0);
   glVertex2f(0.6477341622669, -0.7189713862838);
   glVertex2f(0.7003276602857, -0.7189713862838);
   glVertex2f(0.7003276602857, -0.7189713862838 - 0.2067068723295);
   glVertex2f(0.6477341622669, -0.7189713862838 - 0.2067068723295);
   glEnd();

   // Train window 1
   glBegin(GL_QUADS);
   glColor3ub(0, 0, 0);
   glVertex2f(0.7184890224957, -0.7189713862838);
   glVertex2f(0.7829826061271, -0.7189713862838);
   glVertex2f(0.7829826061271, -0.7889713862838);
   glVertex2f(0.7184890224957, -0.7889713862838);
   glEnd();

   // Train window 2
   glBegin(GL_QUADS);
   glColor3ub(0, 0, 0);
   glVertex2f(0.7184890224957 + 0.0889386558788, -0.7189713862838);
   glVertex2f(0.7829826061271 + 0.0889386558788, -0.7189713862838);
   glVertex2f(0.7829826061271 + 0.0889386558788, -0.7889713862838);
   glVertex2f(0.7184890224957 + 0.0889386558788, -0.7889713862838);
   glEnd();

   // Train window 3
   glBegin(GL_QUADS);
   glColor3ub(0, 0, 0);
   glVertex2f(0.7184890224957 + 0.0889386558788 + 0.0889386558788, -0.7189713862838);
   glVertex2f(0.7829826061271 + 0.0889386558788 + 0.0889386558788, -0.7189713862838);
   glVertex2f(0.7829826061271 + 0.0889386558788 + 0.0889386558788, -0.7889713862838);
   glVertex2f(0.7184890224957 + 0.0889386558788 + 0.0889386558788, -0.7889713862838);
   glEnd();

   // Train body rest design will go here

   // Code

   glPopMatrix();

   // Train body rest code ends here
*/
   // Plane code will go here

   glPushMatrix();
   glTranslatef(planePosition,0.0f, 0.0f);

   //Plane tail
   glBegin(GL_POLYGON);
   glColor3ub(255, 92, 92);
   glVertex2f(0.8358019188841, 0.8504269629171); //S1
   glVertex2f(0.88381860356, 0.8404090218668); //P1
   glVertex2f(0.9185412349809, 0.8637735585556); //Q1
   glVertex2f(0.9316038656871, 0.8737627140618); //M4
   glVertex2f(0.9327815383071, 0.8753293221571); //N4
   glVertex2f(0.9326295291775, 0.876697404323); //O4
   glVertex2f(0.9317681441101, 0.8779134773593); //P4
   glVertex2f(0.9295893465868, 0.8786228532971); //Q4
   glVertex2f(0.9274612187732, 0.8788255321365); //R4
   glVertex2f(0.9032410974668, 0.8799402657531); //S4
   glVertex2f(0.9012649787828, 0.8798895960433); //T4
   glVertex2f(0.89888350242, 0.8792815595251); //U4
   glVertex2f(0.8972114019951, 0.8785215138774); //V4
   glVertex2f(0.8945864156456, 0.8772187040285); //W4
   glVertex2f(0.8358019188841, 0.8504269629171); //S1
   glEnd();

   // Plane main body
   glBegin(GL_POLYGON);
   glColor3ub(8, 104, 150);
   glVertex2f(0.4931696166869, 0.8256810958153); //C1
   glVertex2f(0.4947744567499, 0.820619677155); // E1
   glVertex2f(0.4977372384047, 0.8171630985578); // F1
   glVertex2f(0.5126745959143, 0.8092623474784); //G1
   glVertex2f(0.527858851895, 0.8038305811112); //H1
   glVertex2f(0.55, 0.8); //I1
   glVertex2f(0.5971435291571, 0.7983374458889); //J1
   glVertex2f(0.7644941758939, 0.8085828922877); //K1
   glVertex2f(0.8358819419587, 0.8170986991965); //L1
   glVertex2f(0.8591212368993, 0.8224616134136); //M1
   glVertex2f(0.8661934067416, 0.8259745934379); //N1
   glVertex2f(0.8833627795043, 0.8355468986065); //O1
   glVertex2f(0.88381860356, 0.8404090218668); //P1
   glVertex2f(0.9185412349809, 0.8637735585556); //Q1
   glVertex2f(0.8538685824715, 0.8475664078491); //R1
   glVertex2f(0.8358019188841, 0.8504269629171); //S1
   glVertex2f(0.8177623187589, 0.8536990486945); //Z1
   glVertex2f(0.797120476474, 0.8558949893631); //A2
   glVertex2f(0.7729651291195, 0.8576517418979); //B2
   glVertex2f(0.7349753555527, 0.8611652469677); //C2
   glVertex2f(0.6912761362476, 0.8651179401712); //D2
   glVertex2f(0.6794180566372, 0.8655571283049); //E2
   glVertex2f(0.6278982128812, 0.8688360012186); //F2
   glVertex2f(0.5944919131105, 0.8701291483064); //G2
   glVertex2f(0.580698344173, 0.8701291483064); //H2
   glVertex2f(0.5725084126163, 0.8696980992771); //I2
   glVertex2f(0.5658271526621, 0.8684049521893); //J2
   glVertex2f(0.5578527456201, 0.8660341825281); //K2
   glVertex2f(0.5459988973144, 0.8595684470886); //L2
   glVertex2f(0.536382263609, 0.8527512670952); //M2
   glVertex2f(0.5285262147454, 0.8486449317491); //N2
   glVertex2f(0.519198416877, 0.8452430289971); //O2
   glVertex2f(0.5109680069931, 0.8417313874466);//P2
   glVertex2f(0.5048226342798, 0.8383294846946); //Q2
   glVertex2f(0.5024083807139, 0.8364639251209); //R2
   glVertex2f(0.4995551719542, 0.8342691491519); //S2
   glVertex2f(0.4970311795898, 0.8321841119813); //Z2
   glVertex2f(0.4950558812176, 0.8300990748107); //A3
   glVertex2f(0.4931696166869, 0.8256810958153); //C3
   glEnd();

   // Plane pilot window
   glBegin(GL_POLYGON);
   glColor3f(1.0, 1.0, 1.0);
   glVertex2f(0.5459988973144, 0.8595684470886); //L2
   glVertex2f(0.5484435225582, 0.8581125963309); //B3
   glVertex2f(0.5508898829972, 0.8570181719239); //C3
   glVertex2f(0.5528212201859, 0.8565031486736); //D3
   glVertex2f(0.5552896323442, 0.8563174078103); //E3
   glVertex2f(0.5579070747829, 0.8564387707673); //F3
   glVertex2f(0.5613834817226, 0.8565675265799); //G3
   glVertex2f(0.5639585979742, 0.8565675265799); //H3
   glVertex2f(0.5653749119126, 0.8560525033296); //I3
   glVertex2f(0.5668556037572, 0.8550868347352); //J3
   glVertex2f(0.5677568944453, 0.853928032422); //K3
   glVertex2f(0.5678212723516, 0.8520610731396); //L3
   glVertex2f(0.5678212723516, 0.849936602232); //M3
   glVertex2f(0.5678212723516, 0.8484559103873); //N3
   glVertex2f(0.567241871195, 0.8470395964489); //O3
   glVertex2f(0.5658899351629, 0.8466533290112); //P3
   glVertex2f(0.5635723305364, 0.8465889511049); //Q3
   glVertex2f(0.5609107663931, 0.8466688996364); //R3
   glVertex2f(0.5575208073451, 0.8469108406363); //S3
   glVertex2f(0.5540189421813, 0.8474679729524); //T3
   glVertex2f(0.5505406472968, 0.8482241240142); //U3
   glVertex2f(0.5474782354964, 0.8489802750761); //V3
   glVertex2f(0.5445670539083, 0.8496986185848); //W3
   glVertex2f(0.542198865648, 0.8505160033886); //Z3
   glVertex2f(0.5399456389279, 0.8512885382641); //A4
   glVertex2f(0.5379499238329, 0.8521898289521); //B4
   glVertex2f(0.536382263609, 0.8527512670952); //M2
   glVertex2f(0.5459988973144, 0.8595684470886); //L2
   glEnd();

   //Place passenger window
   glColor3f(1.0, 1.0, 1.0);
   DrawCircle(0.6136134880138, 0.8411480005225, 0.0035804757714, 2000); //C4
   DrawCircle(0.6355357881342, 0.8414408556768, 0.0035804757714, 2000); //D4
   DrawCircle(0.6571667992868, 0.8414456205529, 0.0035804757714, 2000); //E4
   DrawCircle(0.679067501284, 0.8416361909346, 0.0035804757714, 2000); //F4
   DrawCircle(0.7009679284309, 0.8415294616745, 0.0035804757714, 2000); //G4
   DrawCircle(0.72265947389, 0.8415294616745, 0.0035804757714, 2000); //H4
   DrawCircle(0.7445384675596, 0.8417593880138, 0.0035804757714, 2000); //J4
   DrawCircle(0.7665457011564, 0.8416987620259, 0.0035804757714, 2000); //I4
   DrawCircle(0.788, 0.842, 0.0035804757714, 2000); //K4

   //Plane back small wing
   glBegin(GL_POLYGON);
   glColor3ub(217, 215, 13);
   glVertex2f(0.8429190184152, 0.8388715830182); //Z4
   glVertex2f(0.8428187584983, 0.8357635255951); //A5
   glVertex2f(0.8699891959712, 0.8237323355702); //B5
   glVertex2f(0.9002676908672, 0.823130776069); //C5
   glVertex2f(0.9014766912113, 0.8234275134586); //d5
   glVertex2f(0.9025034098246, 0.8241001911708); //e5
   glVertex2f(0.9028574507257, 0.8250915056939); //f5
   glVertex2f(0.9027512384554, 0.8259766079467); //g5
   glVertex2f(0.9022555811938, 0.8267554979292); //h5
   glVertex2f(0.9014016655598, 0.82762094261); //I5
   glVertex2f(0.9004809145604, 0.8284665302625); //J5
   glVertex2f(0.8996710826156, 0.8291275719667); //K5
   glVertex2f(0.8989024842758, 0.8297443071596); //L5
   glVertex2f(0.8980568966233, 0.8302704505878); //M5
   glVertex2f(0.8970572291451, 0.8307109601084); //N5
   glVertex2f(0.8955020011973, 0.8313589717533); //O5
   glVertex2f(0.8768693126856, 0.838674312793); //P5
   glVertex2f(0.8429190184152, 0.8388715830182); //Z4
   glEnd();

   //Plane big wing
   glBegin(GL_POLYGON);
   glColor3ub(217, 215, 13);
   glVertex2f(0.6124736329244, 0.8227595947783); //Q5
   glVertex2f(0.6110676761079, 0.8217051271659); //R5
   glVertex2f(0.61, 0.82); //S5
   glVertex2f(0.6098726128138, 0.8185417243287); //T5
   glVertex2f(0.6103646976996, 0.8170654696713); //U5
   glVertex2f(0.6117003566753, 0.815589215014); //V5
   glVertex2f(0.6131766113327, 0.8140426625158); //W5
   glVertex2f(0.6658787763452, 0.7722024281381); //Z5
   glVertex2f(0.6669672079811, 0.7714181657979); //A6
   glVertex2f(0.6681233765325, 0.770809656034); //B6
   glVertex2f(0.6694316725249, 0.7702924227346); //C6
   glVertex2f(0.6710137979111, 0.7698664658999); //D6
   glVertex2f(0.672078689998, 0.7697447639471); //E6
   glVertex2f(0.673630389896, 0.7695926365061); //F6
   glVertex2f(0.7135351189402, 0.7714776243854); //G6
   glVertex2f(0.7148593214257, 0.7717972594681); //H6
   glVertex2f(0.7161378617566, 0.7722995431695); //I6
   glVertex2f(0.7173707399328, 0.7729844754896); //J6
   glVertex2f(0.7184209694903, 0.7738977185831); //K6
   glVertex2f(0.7191843707172, 0.7750120793597); //L6
   glVertex2f(0.7352872015836, 0.8240134714226); //M6
   glVertex2f(0.6812536153452, 0.8255889907556); //S6
   glVertex2f(0.662131400258, 0.8259186841192); //R6
   glVertex2f(0.6524054460326, 0.826083530801); //Q6
   glVertex2f(0.647460045579, 0.826083530801); //P6
   glVertex2f(0.6433388785344, 0.8259186841192); //O6
   glVertex2f(0.6283378304918, 0.8245999106649); //N6
   glVertex2f(0.6124736329244, 0.8227595947783); //Q5
   glEnd();

   glPopMatrix();
   // Plane code ends here

   glFlush();
}

void sunset(){

    // All drawing related to summer will be performed in this block
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Sky Drawing will start from here
    // This block creates a gradient of the sky

    glBegin(GL_POLYGON);
    glColor3ub(248, 153, 107);
    glVertex2f(-1, 1);
    glVertex2f(-0.5, 1);
    glVertex2f(0, 1);
    glVertex2f(0.5, 1);
    glVertex2f(1, 1);
    glVertex2f(1, 0.75);
    glVertex2f(1, 0.5);
    glVertex2f(1, 0.25);

    glColor3ub(251,192,122);
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

    // Sun drawing code starts here

    glColor3ub(247, 128, 27);
	DrawCircle(-0.4356168493546, 0.3064996734224, 0.1620605572764, 2000);

    // Sun drawing code ends here

    // =================================================

    // Drawing clouds start from here

    // Cloud 1 starts from here


    glPushMatrix();
    glTranslatef(cloud1Position, 0.0f, 0.0f);
    glColor3ub(251, 251, 251);
	DrawCircle(-0.3799673933028, 0.5780739267177, 0.0653084338854, 2000);//1
    DrawCircle(-0.4599673933028, 0.5829705293098, 0.0995776305031, 2000);//2
	DrawCircle(-0.3099673933028, 0.5886832323339, 0.0783838868466, 2000);//3
    glPopMatrix();

    // Cloud 1 ends here

    // Cloud 2 Starts from here

    glPushMatrix();
    glTranslatef(cloud2Position, 0.0f, 0.0f);
    glColor3ub(251, 251, 251);
    DrawCircle(-0.3799673933028+1.0, 0.5780739267177+0.2, 0.0653084338854, 2000);//1
	DrawCircle(-0.4599673933028+1.0, 0.5829705293098+0.2, 0.0995776305031, 2000);//2
	DrawCircle(-0.3099673933028+1.0, 0.5886832323339+0.2, 0.0783838868466, 2000);//3
    glPopMatrix();

	// Cloud 2 ends here

	// Cloud 3 starts from here

    glPushMatrix();
    glTranslatef(cloud3Position, 0.0f, 0.0f);
	glColor3ub(253, 221, 207);
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

    // Fly small birds code start here

    glPushMatrix();
    glTranslatef(birdPosition,0.0f, 0.0f);

    //Bird 1
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(0.7470545861619, 0.3558209044761); //C12
    glVertex2f(0.7502479878184, 0.3566434473271); //D12
    glVertex2f(0.7531510802334, 0.3568369868214); //F12
    glVertex2f(0.7557154785333, 0.3561595985912); //H12
    glVertex2f(0.7577960280974, 0.3543693582686); //J12
    glVertex2f(0.7612797389954, 0.3498211801518); //L12
    glVertex2f(0.7628280549501, 0.34817609445); //M12
    glVertex2f(0.7655859927443, 0.3462890843802); //Q12
    glVertex2f(0.7681987759178, 0.3453213869085); //S12
    glVertex2f(0.770878119105, 0.3448582147674); //U12
    glVertex2f(0.7722501243973, 0.3448230351445); //V12
    glVertex2f(0.7758032663084, 0.3451044721276); //Z12
    glVertex2f(0.7788638934991, 0.3454210887335); //B13
    glVertex2f(0.7816079040839, 0.3450341128818); //D13
    glVertex2f(0.784, 0.344); //F13
    glVertex2f(0.7869148239889, 0.3420691133103); //H13
    glVertex2f(0.7907273477545, 0.3390354922495); //I13
    glVertex2f(0.7927770917145, 0.3380926100279); //K13
    glVertex2f(0.7936379841777, 0.3379286305111); //L13
    glVertex2f(0.7948678305537, 0.3381745997863); //M13
    glVertex2f(0.7964666308425, 0.3394044461623); //N13
    glVertex2f(0.8014787237258, 0.3442303002812); //R13
    glVertex2f(0.7967388888545, 0.3460256922779); //T13
    glVertex2f(0.7925017637422, 0.3476774529149); //U13
    glVertex2f(0.786816993239, 0.350651994052); //W13
    glVertex2f(0.7889277354771, 0.3512383113404); //Z13
    glVertex2f(0.7912730046305, 0.3520005238152); //A14
    glVertex2f(0.792856061309, 0.3527920521545); //B14
    glVertex2f(0.7939993800213, 0.3534663170361); //C14
    glVertex2f(0.7954358573777, 0.3543164771042); //D14
    glVertex2f(0.7966964395477, 0.3552252689012); //E14
    glVertex2f(0.8024713758203, 0.3625414341591); //K14
    glVertex2f(0.805, 0.366); //N14
    glVertex2f(0.8065684611937, 0.3685234304438); //o14
    glVertex2f(0.8078094936828, 0.3710381541718); //P14
    glVertex2f(0.8087565974245, 0.3733895841511); //Q14
    glVertex2f(0.8090831849216, 0.374761251639); //R14
    glVertex2f(0.8094097724187, 0.3763941891247); //S14
    glVertex2f(0.8094424311684, 0.3778311741121); //T14
    glVertex2f(0.8091811611707, 0.3786476428549); //U14
    glVertex2f(0.8083973511776, 0.3793008178492); //V14
    glVertex2f(0.8072542949377, 0.3793334765989); //W14
    glVertex2f(0.8056866749514, 0.3787782778538); //Z14
    glVertex2f(0.79673817753, 0.3738141478974); //E15
    glVertex2f(0.7681097501776, 0.360227100126); //I15
    glVertex2f(0.7667103520047, 0.35993555884); //J15
    glVertex2f(0.765, 0.36); //K15
    glVertex2f(0.7635617061157, 0.3608684909552); //L15
    glVertex2f(0.7635617061157, 0.3608684909552); //M15
    glVertex2f(0.7607046015127, 0.3637255955582); //N15
    glVertex2f(0.7607046015127, 0.3637255955582); //o15
    glVertex2f(0.7562268715868, 0.3625145872298); //P15
    glVertex2f(0.7540218785067, 0.3613314202112); //Q15
    glVertex2f(0.7470545861619, 0.3558209044761); //C12
    glEnd();

        //Bird 2
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(0.7470545861619 + 0.06, 0.3558209044761-0.03); //C12
    glVertex2f(0.7502479878184 + 0.06, 0.3566434473271-0.03); //D12
    glVertex2f(0.7531510802334 + 0.06, 0.3568369868214-0.03); //F12
    glVertex2f(0.7557154785333 + 0.06, 0.3561595985912-0.03); //H12
    glVertex2f(0.7577960280974 + 0.06, 0.3543693582686-0.03); //J12
    glVertex2f(0.7612797389954 + 0.06, 0.3498211801518-0.03); //L12
    glVertex2f(0.7628280549501 + 0.06, 0.34817609445-0.03); //M12
    glVertex2f(0.7655859927443 + 0.06, 0.3462890843802-0.03); //Q12
    glVertex2f(0.7681987759178 + 0.06, 0.3453213869085-0.03); //S12
    glVertex2f(0.770878119105 + 0.06, 0.3448582147674-0.03); //U12
    glVertex2f(0.7722501243973 + 0.06, 0.3448230351445-0.03); //V12
    glVertex2f(0.7758032663084 + 0.06, 0.3451044721276-0.03); //Z12
    glVertex2f(0.7788638934991 + 0.06, 0.3454210887335-0.03); //B13
    glVertex2f(0.7816079040839 + 0.06, 0.3450341128818-0.03); //D13
    glVertex2f(0.784+ 0.06, 0.344-0.03); //F13
    glVertex2f(0.7869148239889+ 0.06, 0.3420691133103-0.03); //H13
    glVertex2f(0.7907273477545+ 0.06, 0.3390354922495-0.03); //I13
    glVertex2f(0.7927770917145+ 0.06, 0.3380926100279-0.03); //K13
    glVertex2f(0.7936379841777+ 0.06, 0.3379286305111-0.03); //L13
    glVertex2f(0.7948678305537+ 0.06, 0.3381745997863-0.03); //M13
    glVertex2f(0.7964666308425+ 0.06, 0.3394044461623-0.03); //N13
    glVertex2f(0.8014787237258+ 0.06, 0.3442303002812-0.03); //R13
    glVertex2f(0.7967388888545+ 0.06, 0.3460256922779-0.03); //T13
    glVertex2f(0.7925017637422+ 0.06, 0.3476774529149-0.03); //U13
    glVertex2f(0.786816993239+ 0.06, 0.350651994052-0.03); //W13
    glVertex2f(0.7889277354771+ 0.06, 0.3512383113404-0.03); //Z13
    glVertex2f(0.7912730046305+ 0.06, 0.3520005238152-0.03); //A14
    glVertex2f(0.792856061309+ 0.06, 0.3527920521545-0.03); //B14
    glVertex2f(0.7939993800213+ 0.06, 0.3534663170361-0.03); //C14
    glVertex2f(0.7954358573777+ 0.06, 0.3543164771042-0.03); //D14
    glVertex2f(0.7966964395477+ 0.06, 0.3552252689012-0.03); //E14
    glVertex2f(0.8024713758203+ 0.06, 0.3625414341591-0.03); //K14
    glVertex2f(0.805+ 0.06, 0.366-0.03); //N14
    glVertex2f(0.8065684611937+ 0.06, 0.3685234304438-0.03); //o14
    glVertex2f(0.8078094936828+ 0.06, 0.3710381541718-0.03); //P14
    glVertex2f(0.8087565974245+ 0.06, 0.3733895841511-0.03); //Q14
    glVertex2f(0.8090831849216+ 0.06, 0.374761251639-0.03); //R14
    glVertex2f(0.8094097724187+ 0.06, 0.3763941891247-0.03); //S14
    glVertex2f(0.8094424311684+ 0.06, 0.3778311741121-0.03); //T14
    glVertex2f(0.8091811611707+ 0.06, 0.3786476428549-0.03); //U14
    glVertex2f(0.8083973511776+ 0.06, 0.3793008178492-0.03); //V14
    glVertex2f(0.8072542949377+ 0.06, 0.3793334765989-0.03); //W14
    glVertex2f(0.8056866749514+ 0.06, 0.3787782778538-0.03); //Z14
    glVertex2f(0.79673817753+ 0.06, 0.3738141478974-0.03); //E15
    glVertex2f(0.7681097501776+ 0.06, 0.360227100126-0.03); //I15
    glVertex2f(0.7667103520047+ 0.06, 0.35993555884-0.03); //J15
    glVertex2f(0.765+ 0.06, 0.36-0.03); //K15
    glVertex2f(0.7635617061157+ 0.06, 0.3608684909552-0.03); //L15
    glVertex2f(0.7635617061157+ 0.06, 0.3608684909552-0.03); //M15
    glVertex2f(0.7607046015127+ 0.06, 0.3637255955582-0.03); //N15
    glVertex2f(0.7607046015127+ 0.06, 0.3637255955582-0.03); //o15
    glVertex2f(0.7562268715868+ 0.06, 0.3625145872298-0.03); //P15
    glVertex2f(0.7540218785067+ 0.06, 0.3613314202112-0.03); //Q15
    glVertex2f(0.7470545861619+ 0.06, 0.3558209044761-0.03); //C12
    glEnd();

    glPopMatrix();

    // Fly small birds code end here

    // ===========================================================

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
    glPushMatrix();
    glTranslatef(rightWavePosition1,0.0f, 0.0f);
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

    // Boat code starts from here

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
   glColor3ub(244, 244, 244);
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
   glColor3ub(82, 82, 82);
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
   glColor3ub(244, 244, 244);
   glVertex2f(0.52f, -0.23f);
   glVertex2f(0.56f, -0.23f);
   glVertex2f(0.56f, -0.18f);
   glVertex2f(0.52f, -0.18f);
   glEnd();

   //2nd flr right big block
   glBegin(GL_QUADS);
   glColor3ub(244, 244, 244);
   glVertex2f(0.56f, -0.23f);
   glVertex2f(0.71f, -0.23f);
   glVertex2f(0.71f, -0.16f);
   glVertex2f(0.56f, -0.16f);
   glEnd();

   // 2nd flr door
   glBegin(GL_QUADS);
   glColor3ub(82, 82, 82);
   glVertex2f(0.64f, -0.23f);
   glVertex2f(0.67f, -0.23f);
   glVertex2f(0.67f, -0.17f);
   glVertex2f(0.64f, -0.17f);
   glEnd();

   // 2nd flr door window
   glBegin(GL_QUADS);
   glColor3ub(100, 204, 204);
   glVertex2f(0.65f, -0.20f);
   glVertex2f(0.662f, -0.20f);
   glVertex2f(0.662f, -0.18f);
   glVertex2f(0.65f, -0.18f);
   glEnd();

   // 2nd flr big window
   glBegin(GL_QUADS);
   glColor3ub(100, 204, 204);
   glVertex2f(0.59f, -0.20f);
   glVertex2f(0.63f, -0.20f);
   glVertex2f(0.63f, -0.17f);
   glVertex2f(0.59f, -0.17f);
   glEnd();

   // 2nd flr small window
   glBegin(GL_QUADS);
   glColor3ub(100, 204, 204);
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
   glColor3ub(5, 166, 96);
   glVertex2f(0.38f, -0.33f);
   glVertex2f(0.41f, -0.33f);
   glVertex2f(0.41f, -0.32f);
   glVertex2f(0.38f, -0.32f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(5, 166, 96);
   glVertex2f(0.41f, -0.33f);
   glVertex2f(0.43f, -0.33f);
   glVertex2f(0.43f, -0.32f);
   glVertex2f(0.41f, -0.32f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(5, 166, 96);
   glVertex2f(0.43f, -0.33f);
   glVertex2f(0.45f, -0.33f);
   glVertex2f(0.45f, -0.32f);
   glVertex2f(0.43f, -0.32f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(5, 166, 96);
   glVertex2f(0.38f, -0.32f);
   glVertex2f(0.41f, -0.32f);
   glVertex2f(0.41f, -0.31f);
   glVertex2f(0.38f, -0.31f);
   glEnd();


   glBegin(GL_QUADS);
   glColor3ub(5, 166, 96);
   glVertex2f(0.43f, -0.32f);
   glVertex2f(0.45f, -0.32f);
   glVertex2f(0.45f, -0.31f);
   glVertex2f(0.43f, -0.31f);
   glEnd();

   glPopMatrix();

   // back fence code block ends here

   // Boat code ends here

   // ===========================================================

   // Back tree row common fill code starts here

   glBegin(GL_QUADS);
   glColor3ub(61, 124, 83);
   glVertex2f(1.0, -0.5756367057105); // Base +x down
   glVertex2f(-1.0, -0.5756367057105); // Base -x down
   glVertex2f(-1.0, -0.6869004722551);
   glVertex2f(1.0, -0.6869004722551);
   glEnd();

   // Back tree row common fill code ends here

   // Bush code starts here

   glColor3ub(61, 124, 83);
	DrawCircle(-0.9072372816471, -0.5468327234769, 0.0978210355299, 2000);//1
    DrawCircle(-0.7882306545015, -0.5235785549542, 0.0951840734353, 2000);//2
	DrawCircle(-0.6500735356314, -0.5372574776146, 0.096724589725, 2000);//3
	DrawCircle(-0.5283311239537, -0.4934849251013, 0.108227857386, 2000);//4
	DrawCircle(-0.3696556210929, -0.5317859085505, 0.1003328230094, 2000);//5
	DrawCircle(-0.2219232563605, -0.5673511074675, 0.1262189788627, 2000);//6
	DrawCircle(-0.0315276315684, -0.4951186711054, 0.1503734194491, 2000);//7
	DrawCircle(0.0896782091289, -0.4385559454467, 0.0983021794995, 2000);//8
	DrawCircle(0.1769464144309, -0.4838061259736, 0.1155580437535, 2000);//9
	DrawCircle(0.2512859967253, -0.5322884622525, 0.096126072669, 2000);//10
	DrawCircle(0.3821883046783, -0.4870382817256, 0.1047961396401, 2000);//11
	DrawCircle(0.5003317807708, -0.5258241507487, 0.0740050744839, 2000);//12
	DrawCircle(0.644505499274, -0.4974731103267, 0.1039797036134, 2000);//13
	DrawCircle(0.7710785506579, -0.4841496312337, 0.093338673811, 2000);//14
	DrawCircle(0.7910637692975, -0.5557633313588, 0.117575444767, 2000);//15
	DrawCircle(0.9292948648878, -0.4641644125941, 0.1348282433764, 2000);//16

	// Bush Code ends here

   // ============================================================

   // Pine Tree code starts here

   // Ground grass color code starts here

   glBegin(GL_QUADS);
   glColor3ub(78, 133, 21);
   glVertex2f(-1.0, -0.6869004722551);
   glVertex2f(1.0, -0.6869004722551);
   glVertex2f(1.0, -1);
   glVertex2f(-1.0, -1);
   glEnd();

   // Ground grass color code ends here

   // tree 1 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2938571399917, -0.4423232979151);
   glVertex2f(-0.2115496244678, -0.5423834148265);
   glVertex2f(-0.3793924012224, -0.5415764783998);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2978918221252, -0.5084920849049);
   glVertex2f(-0.1841137859599, -0.5811163633083);
   glVertex2f(-0.3898825747696, -0.5762747447481);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3, -0.55);
   glVertex2f(-0.1792721673996, -0.6408296588845);
   glVertex2f(-0.3955311297565, -0.6335672310441);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3, -0.6);
   glVertex2f(-0.1740006707345, -0.6905816498292);
   glVertex2f(-0.4187989794158, -0.6869004722551);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136, -0.6973304753819);
   glVertex2f(-0.2825954091721, -0.6961034161905);
   glVertex2f(-0.2801412907893, -0.74886696142);
   glVertex2f(-0.3187936553179, -0.7494804910157);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3, -0.65);
   glVertex2f(-0.1574353716508, -0.7286204847622);
   glVertex2f(-0.4286154529469, -0.7292340143579);
   glEnd();

   // Tree 1 code ends here

   // tree 2 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2938571399917 + 0.3, -0.4423232979151);
   glVertex2f(-0.2115496244678 + 0.3, -0.5423834148265);
   glVertex2f(-0.3793924012224 + 0.3, -0.5415764783998);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2978918221252 + 0.3, -0.5084920849049);
   glVertex2f(-0.1841137859599 + 0.3, -0.5811163633083);
   glVertex2f(-0.3898825747696 + 0.3, -0.5762747447481);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.3, -0.55);
   glVertex2f(-0.1792721673996 + 0.3, -0.6408296588845);
   glVertex2f(-0.3955311297565 + 0.3, -0.6335672310441);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.3, -0.6);
   glVertex2f(-0.1740006707345 + 0.3, -0.6905816498292);
   glVertex2f(-0.4187989794158 + 0.3, -0.6869004722551);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136 + 0.3 , -0.6973304753819);
   glVertex2f(-0.2825954091721 + 0.3, -0.6961034161905);
   glVertex2f(-0.2801412907893 + 0.3, -0.74886696142);
   glVertex2f(-0.3187936553179 + 0.3, -0.7494804910157);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.3, -0.65);
   glVertex2f(-0.1574353716508 + 0.3, -0.7286204847622);
   glVertex2f(-0.4286154529469 + 0.3, -0.7292340143579);
   glEnd();

   // Tree 2 code ends here

   // tree 3 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2938571399917 + 0.6, -0.4423232979151);
   glVertex2f(-0.2115496244678 + 0.6, -0.5423834148265);
   glVertex2f(-0.3793924012224 + 0.6, -0.5415764783998);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2978918221252 + 0.6, -0.5084920849049);
   glVertex2f(-0.1841137859599 + 0.6, -0.5811163633083);
   glVertex2f(-0.3898825747696 + 0.6, -0.5762747447481);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.6, -0.55);
   glVertex2f(-0.1792721673996 + 0.6, -0.6408296588845);
   glVertex2f(-0.3955311297565 + 0.6, -0.6335672310441);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.6, -0.6);
   glVertex2f(-0.1740006707345 + 0.6, -0.6905816498292);
   glVertex2f(-0.4187989794158 + 0.6, -0.6869004722551);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136 + 0.6 , -0.6973304753819);
   glVertex2f(-0.2825954091721 + 0.6, -0.6961034161905);
   glVertex2f(-0.2801412907893 + 0.6, -0.74886696142);
   glVertex2f(-0.3187936553179 + 0.6, -0.7494804910157);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.6, -0.65);
   glVertex2f(-0.1574353716508 + 0.6, -0.7286204847622);
   glVertex2f(-0.4286154529469 + 0.6, -0.7292340143579);
   glEnd();

   // Tree 3 code ends here

      // tree 2 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2938571399917 + 0.3, -0.4423232979151);
   glVertex2f(-0.2115496244678 + 0.3, -0.5423834148265);
   glVertex2f(-0.3793924012224 + 0.3, -0.5415764783998);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2978918221252 + 0.3, -0.5084920849049);
   glVertex2f(-0.1841137859599 + 0.3, -0.5811163633083);
   glVertex2f(-0.3898825747696 + 0.3, -0.5762747447481);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.3, -0.55);
   glVertex2f(-0.1792721673996 + 0.3, -0.6408296588845);
   glVertex2f(-0.3955311297565 + 0.3, -0.6335672310441);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.3, -0.6);
   glVertex2f(-0.1740006707345 + 0.3, -0.6905816498292);
   glVertex2f(-0.4187989794158 + 0.3, -0.6869004722551);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136 + 0.3 , -0.6973304753819);
   glVertex2f(-0.2825954091721 + 0.3, -0.6961034161905);
   glVertex2f(-0.2801412907893 + 0.3, -0.74886696142);
   glVertex2f(-0.3187936553179 + 0.3, -0.7494804910157);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.3, -0.65);
   glVertex2f(-0.1574353716508 + 0.3, -0.7286204847622);
   glVertex2f(-0.4286154529469 + 0.3, -0.7292340143579);
   glEnd();

   // Tree 2 code ends here

   // tree 4 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2938571399917 + 0.9, -0.4423232979151);
   glVertex2f(-0.2115496244678 + 0.9, -0.5423834148265);
   glVertex2f(-0.3793924012224 + 0.9, -0.5415764783998);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2978918221252 + 0.9, -0.5084920849049);
   glVertex2f(-0.1841137859599 + 0.9, -0.5811163633083);
   glVertex2f(-0.3898825747696 + 0.9, -0.5762747447481);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.9, -0.55);
   glVertex2f(-0.1792721673996 + 0.9, -0.6408296588845);
   glVertex2f(-0.3955311297565 + 0.9, -0.6335672310441);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.9, -0.6);
   glVertex2f(-0.1740006707345 + 0.9, -0.6905816498292);
   glVertex2f(-0.4187989794158 + 0.9, -0.6869004722551);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136 + 0.9 , -0.6973304753819);
   glVertex2f(-0.2825954091721 + 0.9, -0.6961034161905);
   glVertex2f(-0.2801412907893 + 0.9, -0.74886696142);
   glVertex2f(-0.3187936553179 + 0.9, -0.7494804910157);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 0.9, -0.65);
   glVertex2f(-0.1574353716508 + 0.9, -0.7286204847622);
   glVertex2f(-0.4286154529469 + 0.9, -0.7292340143579);
   glEnd();

   // Tree 4 code ends here

      // tree 5 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2938571399917 + 1.2, -0.4423232979151);
   glVertex2f(-0.2115496244678 + 1.2, -0.5423834148265);
   glVertex2f(-0.3793924012224 + 1.2, -0.5415764783998);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2978918221252 + 1.2, -0.5084920849049);
   glVertex2f(-0.1841137859599 + 1.2, -0.5811163633083);
   glVertex2f(-0.3898825747696 + 1.2, -0.5762747447481);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 1.2, -0.55);
   glVertex2f(-0.1792721673996 + 1.2, -0.6408296588845);
   glVertex2f(-0.3955311297565 + 1.2, -0.6335672310441);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 1.2, -0.6);
   glVertex2f(-0.1740006707345 + 1.2, -0.6905816498292);
   glVertex2f(-0.4187989794158 + 1.2, -0.6869004722551);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136 + 1.2 , -0.6973304753819);
   glVertex2f(-0.2825954091721 + 1.2, -0.6961034161905);
   glVertex2f(-0.2801412907893 + 1.2, -0.74886696142);
   glVertex2f(-0.3187936553179 + 1.2, -0.7494804910157);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 + 1.2, -0.65);
   glVertex2f(-0.1574353716508 + 1.2, -0.7286204847622);
   glVertex2f(-0.4286154529469 + 1.2, -0.7292340143579);
   glEnd();

   // Tree 5 code ends here

   // tree 6 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2938571399917 - 0.3, -0.4423232979151 + 0.03);
   glVertex2f(-0.2115496244678 - 0.3, -0.5423834148265 + 0.03);
   glVertex2f(-0.3793924012224 - 0.3, -0.5415764783998 + 0.03);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2978918221252 - 0.3, -0.5084920849049 + 0.03);
   glVertex2f(-0.1841137859599 - 0.3, -0.5811163633083 + 0.03);
   glVertex2f(-0.3898825747696 - 0.3, -0.5762747447481 + 0.03);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 - 0.3, -0.55 + 0.03);
   glVertex2f(-0.1792721673996 - 0.3, -0.6408296588845 + 0.03);
   glVertex2f(-0.3955311297565 - 0.3, -0.6335672310441 + 0.03);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 - 0.3, -0.6);
   glVertex2f(-0.1740006707345 - 0.3, -0.6905816498292 + 0.03);
   glVertex2f(-0.4187989794158 - 0.3, -0.6869004722551 + 0.03);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136 - 0.3 , -0.6973304753819 + 0.03);
   glVertex2f(-0.2825954091721 - 0.3, -0.6961034161905 + 0.03);
   glVertex2f(-0.2801412907893 - 0.3, -0.74886696142 + 0.03);
   glVertex2f(-0.3187936553179 - 0.3, -0.7494804910157 + 0.03);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 - 0.3, -0.65);
   glVertex2f(-0.1574353716508 - 0.3, -0.7286204847622 + 0.03);
   glVertex2f(-0.4286154529469 - 0.3, -0.7292340143579 + 0.03);
   glEnd();

   // Tree 6 code ends here

      // tree 7 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2938571399917 - 0.6, -0.4423232979151);
   glVertex2f(-0.2115496244678 - 0.6, -0.5423834148265);
   glVertex2f(-0.3793924012224 - 0.6, -0.5415764783998);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.2978918221252 - 0.6, -0.5084920849049);
   glVertex2f(-0.1841137859599 - 0.6, -0.5811163633083);
   glVertex2f(-0.3898825747696 - 0.6, -0.5762747447481);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 - 0.6, -0.55);
   glVertex2f(-0.1792721673996 - 0.6, -0.6408296588845);
   glVertex2f(-0.3955311297565 - 0.6, -0.6335672310441);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 - 0.6, -0.6);
   glVertex2f(-0.1740006707345 - 0.6, -0.6905816498292);
   glVertex2f(-0.4187989794158 - 0.6, -0.6869004722551);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136 - 0.6 , -0.6973304753819);
   glVertex2f(-0.2825954091721 - 0.6, -0.6961034161905);
   glVertex2f(-0.2801412907893 - 0.6, -0.74886696142);
   glVertex2f(-0.3187936553179 - 0.6, -0.7494804910157);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(13, 91, 40);
   glVertex2f(-0.3 - 0.6, -0.65);
   glVertex2f(-0.1574353716508 - 0.6, -0.7286204847622);
   glVertex2f(-0.4286154529469 - 0.6, -0.7292340143579);
   glEnd();

   // Tree 7 code ends here

   // Pine Tree code ends here

   // ================================================

   // Fence code starts here

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-1.0f, -0.95f + 0.15f);
      glVertex2f(1.0f, -0.95f + 0.15f);
      glVertex2f(1.0f, -0.93f + 0.15f);
      glVertex2f(-1.0f, -0.93f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-1.0f, -0.87f + 0.15f);
      glVertex2f(1.0f, -0.87f + 0.15f);
      glVertex2f(1.0f, -0.85f + 0.15f);
      glVertex2f(-1.0f, -0.85f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.92f, -0.98f + 0.15f);
      glVertex2f(-0.88f, -0.98f + 0.15f);
      glVertex2f(-0.88f, -0.82f + 0.15f);
      glVertex2f(-0.92f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.82f, -0.98f + 0.15f);
      glVertex2f(-0.79f, -0.98f + 0.15f);
      glVertex2f(-0.79f, -0.82f + 0.15f);
      glVertex2f(-0.82f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.72f, -0.98f + 0.15f);
      glVertex2f(-0.69f, -0.98f + 0.15f);
      glVertex2f(-0.69f, -0.82f + 0.15f);
      glVertex2f(-0.72f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.62f, -0.98f + 0.15f);
      glVertex2f(-0.59f, -0.98f + 0.15f);
      glVertex2f(-0.59f, -0.82f + 0.15f);
      glVertex2f(-0.62f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.52f, -0.98f + 0.15f);
      glVertex2f(-0.49f, -0.98f + 0.15f);
      glVertex2f(-0.49f, -0.82f + 0.15f);
      glVertex2f(-0.52f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.42f, -0.98f + 0.15f);
      glVertex2f(-0.39f, -0.98f + 0.15f);
      glVertex2f(-0.39f, -0.82f + 0.15f);
      glVertex2f(-0.42f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.32f, -0.98f + 0.15f);
      glVertex2f(-0.29f, -0.98f + 0.15f);
      glVertex2f(-0.29f, -0.82f + 0.15f);
      glVertex2f(-0.32f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.22f, -0.98f + 0.15f);
      glVertex2f(-0.19f, -0.98f + 0.15f);
      glVertex2f(-0.19f, -0.82f + 0.15f);
      glVertex2f(-0.22f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.12f, -0.98f + 0.15f);
      glVertex2f(-0.09f, -0.98f + 0.15f);
      glVertex2f(-0.09f, -0.82f + 0.15f);
      glVertex2f(-0.12f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.02f, -0.98f + 0.15f);
      glVertex2f(0.0f, -0.98f + 0.15f);
      glVertex2f(0.0f, -0.82f + 0.15f);
      glVertex2f(-0.02f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.12f, -0.98f + 0.15f);
      glVertex2f(0.09f, -0.98f + 0.15f);
      glVertex2f(0.09f, -0.82f + 0.15f);
      glVertex2f(0.12f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.22f, -0.98f + 0.15f);
      glVertex2f(0.19f, -0.98f + 0.15f);
      glVertex2f(0.19f, -0.82f + 0.15f);
      glVertex2f(0.22f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.32f, -0.98f + 0.15f);
      glVertex2f(0.29f, -0.98f + 0.15f);
      glVertex2f(0.29f, -0.82f + 0.15f);
      glVertex2f(0.32f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.42f, -0.98f + 0.15f);
      glVertex2f(0.39f, -0.98f + 0.15f);
      glVertex2f(0.39f, -0.82f + 0.15f);
      glVertex2f(0.42f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.52f, -0.98f + 0.15f);
      glVertex2f(0.49f, -0.98f + 0.15f);
      glVertex2f(0.49f, -0.82f + 0.15f);
      glVertex2f(0.52f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.62f, -0.98f + 0.15f);
      glVertex2f(0.59f, -0.98f + 0.15f);
      glVertex2f(0.59f, -0.82f + 0.15f);
      glVertex2f(0.62f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.72f, -0.98f + 0.15f);
      glVertex2f(0.69f, -0.98f + 0.15f);
      glVertex2f(0.69f, -0.82f + 0.15f);
      glVertex2f(0.72f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.82f, -0.98f + 0.15f);
      glVertex2f(0.79f, -0.98f + 0.15f);
      glVertex2f(0.79f, -0.82f + 0.15f);
      glVertex2f(0.82f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.92f, -0.98f + 0.15f);
      glVertex2f(0.89f, -0.98f + 0.15f);
      glVertex2f(0.89f, -0.82f + 0.15f);
      glVertex2f(0.92f, -0.82f + 0.15f);
    glEnd();

   // Fence Code ends here

   // =============================================================

   // Close Train code starts here

   // Train track code starts here

   glBegin(GL_QUADS);
   glColor3ub(123, 123, 123);
   glVertex2f(-1.0, -0.9599998637683);
   glVertex2f(-1.0, -0.9443483025884);
   glVertex2f(1.0, -0.9443483025884);
   glVertex2f(1.0, -0.9599998637683);
   glEnd();

   // Train track code ends here

   // ==================================================================

   // updated train model code starts here

   glPushMatrix();
   glTranslatef(trainPosition,0.0f, 0.0f);

   // Connector code
   glBegin(GL_QUADS);
   glColor3ub(201, 201, 201);
   glVertex2f(0.4588413119369, -0.7467275099806); //G9
   glVertex2f(0.4798857278648, -0.7467275099806); //H9
   glVertex2f(0.4798857278648, -0.9117251206329); //I9
   glVertex2f(0.4588413119369, -0.9117251206329); //J9
   glEnd();

   // left engine wheel code goes here

   //y = -0.9137316052198 for wheel center
   glColor3ub(82, 82, 82);
   // Back pair
   DrawCircle(0.2979740488535, -0.9361512437916, 0.023803337574, 8000);//1 - far left
   DrawCircle(0.2979740488535 + 0.0679267614286, -0.9361512437916, 0.023803337574, 8000);//1 - far left

   // Front pair
   DrawCircle(0.1140783890, -0.9361512437916, 0.023803337574, 8000);//1 - far left
   DrawCircle(0.1140783890 + 0.0679267614286, -0.9361512437916, 0.023803337574, 8000);//1 - far left

   //  left engine body code goes here
   glBegin(GL_POLYGON);
   glColor3ub(255, 92, 92);
   glVertex2f(0.0902750519795, -0.9243514184048); //V
   glVertex2f(0.2638419609981, -0.9243514184048); //Z
   glVertex2f(0.2638419609981, -0.9243514184048); //Z
   glVertex2f(0.2673071512138, -0.9172990967291); //T1
   glVertex2f(0.268625571989, -0.9152051343215); //U1
   glVertex2f(0.2704868719069, -0.9137316052198); //V1
   glVertex2f(0.2730461592941, -0.9135764968933); //W1
   glVertex2f(0.3883143036753, -0.9139417200826); //T2
   glVertex2f(0.3897577491135, -0.9142537476641); //U2
   glVertex2f(0.3910351937303, -0.9149161263543); //V2
   glVertex2f(0.392, -0.916); //W2
   glVertex2f(0.3973751040505, -0.9239055514352); //E8
   glVertex2f(0.4495081231461, -0.9243514184048); //F8
   glVertex2f(0.4517892659953, -0.9237467603624); //G8
   glVertex2f(0.4539527958094, -0.9226913799653); //H8
   glVertex2f(0.455535866405, -0.9215832305484); //I8
   glVertex2f(0.456644015822, -0.9201584670122); //J8
   glVertex2f(0.4573827821, -0.9185753964166); //K8
   glVertex2f(0.4573827821, -0.7408630998829); //L8
   glVertex2f(0.4580127024621, -0.7385660853445); //M8
   glVertex2f(0.4568244590262, -0.7365460715036); //N8
   glVertex2f(0.455, -0.735); //o8
   glVertex2f(0.4533191408905, -0.7341101724601); //P8
   glVertex2f(0.4508832418471, -0.733872523773); //Q8 - MAX Y VALUE
   glVertex2f(0.1311461118639, -0.733872523773); //S8
   glVertex2f(0.1269818194044, -0.7332398273495); //T8
   glVertex2f(0.1233172420401, -0.7345724009365); //U8
   glVertex2f(0.1196526646757, -0.7367378330155); //V8
   glVertex2f(0.1164878024065, -0.7390698367928); //W8
   glVertex2f(0.1134895118357, -0.7425678424587); //Z8
   glVertex2f(0.04, -0.866); //A9
   glVertex2f(0.0387581733414, -0.8689573745512); //B9
   glVertex2f(0.0382721983081, -0.8707068846711); //C9
   glVertex2f(0.0380172743025, -0.8741027234919); //A
   glVertex2f(0.0380487737159, -0.8776008690587); //H
   glVertex2f(0.0387481261355, -0.8810976311566); //I
   glVertex2f(0.0397971547648, -0.8848275107277); //L
   glVertex2f(0.0413124183406, -0.888207714089); //M
   glVertex2f(0.0432939168627, -0.8913547999771); //N
   glVertex2f(0.0458582090679, -0.8952012382848); //O
   glVertex2f(0.0486556187462, -0.8981152066997); //P
   glVertex2f(0.0516980249696, -0.9007746742169); //Q
   glVertex2f(0.0566279964724, -0.9041024049814); //R
   glVertex2f(0.0689529252296, -0.9114973622357); //T
   glVertex2f(0.0902750519795, -0.9243514184048); //V
   glEnd();

   // left engine - engine master window code goes here
   glBegin(GL_POLYGON);
   glColor3ub(221, 255, 255);
   glVertex2f(0.1028258229583, -0.7605273722022); //G9
   glVertex2f(0.1045268049421, -0.7603038528659); //H9
   glVertex2f(0.1064892834981, -0.7600234987865); //I9
   glVertex2f(0.1076574254957, -0.7604907555856); //J9
   glVertex2f(0.1084517620541, -0.7616121719033); //K9
   glVertex2f(0.1088255674933, -0.7633877477396); //L9
   glVertex2f(0.0963670020494, -0.854308496056); //M9
   glVertex2f(0.0959840335848, -0.8561686285981); //N9
   glVertex2f(0.0952728064364, -0.857755212237); //O9
   glVertex2f(0.0940144814815, -0.8591229567532); //P9
   glVertex2f(0.0921543489394, -0.8600530230242); //Q9
   glVertex2f(0.081256053022, -0.8638552288953); //R9
   glVertex2f(0.0764584464475, -0.8650420401822); //S9
   glVertex2f(0.0707017648046, -0.8653097928167); //T9
   glVertex2f(0.0634724436716, -0.8650420401822); //U9
   glVertex2f(0.0578496383459, -0.8645065349131); //V9
   glVertex2f(0.0522268330203, -0.8633016480576); //W9
   glVertex2f(0.0434783774913, -0.8602687046815); //Z9
   glVertex2f(0.1028258229583, -0.7605273722022); //G9
   glEnd();

   // left engine - engine master door
   glBegin(GL_QUADS);
   glColor3ub(255, 255, 255);
   glVertex2f(0.1649363264379, -0.7736938476301); //G9
   glVertex2f(0.2210939998274, -0.7736938476301); //H9
   glVertex2f(0.2210939998274, -0.9108481653313); //I9
   glVertex2f(0.1649363264379, -0.9108481653313); //J9
   glEnd();

   // Left engine - main window
   glBegin(GL_QUADS);
   glColor3ub(255, 255, 255);
   glVertex2f(0.2329994395528, -0.7736938476301); //G9
   glVertex2f(0.4296313165988, -0.7736938476301); //H9
   glVertex2f(0.4296313165988, -0.8562788832022); //I9
   glVertex2f(0.2329994395528, -0.8562788832022); //J9
   glEnd();
   glBegin(GL_LINES);
   glColor3ub(0, 0, 0);
   glVertex2f(0.2329994395528, -0.8000048684736); //G9
   glVertex2f(0.4296313165988, -0.8000048684736); //H9
   glEnd();

   // Left Engine top Box code goes here
   glBegin(GL_QUADS);
   glColor3ub(246, 246, 246);
   glVertex2f(0.4341934243381, -0.733329040145); //G9
   glVertex2f(0.4341934243381, -0.7175755480725); //H9
   glVertex2f(0.1797273626565, -0.7175755480725); //I9
   glVertex2f(0.1797273626565, -0.733329040145); //J9
   glEnd();

   // Left engine code ends here

   // Middle carriage of train code goes here

   // Middle carriage wheel code
   glColor3ub(82, 82, 82);
   DrawCircle(0.6335635062646, -0.9361512437916, 0.023803337574, 8000);//1 - far left
   DrawCircle(0.6335635062646 + 0.0679267614286, -0.9361512437916, 0.023803337574, 8000);//1 - far left

   // Carriage body code
   glBegin(GL_POLYGON);
   glColor3ub(255, 92, 92);
   glVertex2f(0.4801758240852, -0.9191043740047); //I11
   glVertex2f(0.4809755595681, -0.9205862368113); //H11
   glVertex2f(0.482410379111, -0.9219975347223); //G11
   glVertex2f(0.4841257894728, -0.9232021159928); //J11
   glVertex2f(0.4855932943556, -0.9237627358357); //F11
   glVertex2f(0.4872381164666, -0.9240447934564); //E11
   glVertex2f(0.8489917039809, -0.9240447934564); //D11
   glVertex2f(0.8504746539721, -0.9242064673156); //C11
   glVertex2f(0.851715489679, -0.9234801244628); //B11
   glVertex2f(0.8527444753872, -0.9221787601848); //A11
   glVertex2f(0.8535010825255, -0.9205142244804); //Z10
   glVertex2f(0.8540128051614, -0.9188721651553); //W10
   glVertex2f(0.8541329302856, -0.9169501631667); //V10
   glVertex2f(0.8541329302856, -0.7405637387567); //U10
   glVertex2f(0.8529695509292, -0.7392606860364); //T10
   glVertex2f(0.8515268854173, -0.7376318701359); //S10
   glVertex2f(0.8501772950998, -0.736468430207); //R10
   glVertex2f(0.848455404005, -0.7353980654724); //Q10
   glVertex2f(0.8462043017123, -0.7345738841131); //P10
   glVertex2f(0.4873888670143, -0.7345738841131); //o10
   glVertex2f(0.485, -0.735); //N10
   glVertex2f(0.4831260743853, -0.7365778999664); //M10
   glVertex2f(0.4813790282259, -0.7385345916649); //L10
   glVertex2f(0.4801758240852, -0.7408406925953); //K19
   glVertex2f(0.4801758240852, -0.9191043740047); //I11
   glEnd();

   //top Box code goes here
   glBegin(GL_QUADS);
   glColor3ub(246, 246, 246);
   glVertex2f(0.5054866328459, -0.733329040145); //G9
   glVertex2f(0.5054866328459, -0.7175755480725); //H9
   glVertex2f(0.8286505622915, -0.7175755480725); //I9
   glVertex2f(0.8286505622915, -0.733329040145); //J9
   glEnd();

   // Left door
   glBegin(GL_QUADS);
   glColor3ub(255, 255, 255);
   glVertex2f(0.5003789366041, -0.7736938476301); //G9
   glVertex2f(0.600634048208, -0.7736938476301); //H9
   glVertex2f(0.600634048208, -0.9108481653313); //I9
   glVertex2f(0.5003789366041, -0.9108481653313); //J9
   glEnd();
   glBegin(GL_LINES);
   glColor3ub(0, 0, 0);
   glVertex2f(0.5505176318039, -0.7736938476301); //G9
   glVertex2f(0.5505176318039, -0.9108481653313); //H9
   glEnd();

   // Window
   glBegin(GL_QUADS);
   glColor3ub(255, 255, 255);
   glVertex2f(0.610621388717, -0.7736938476301); //G9
   glVertex2f(0.7222523746758, -0.7736938476301); //H9
   glVertex2f(0.7222523746758, -0.8562788832022); //I9
   glVertex2f(0.610621388717, -0.8562788832022); //J9
   glEnd();
   glBegin(GL_LINES);
   glColor3ub(0, 0, 0);
   glVertex2f(0.7222523746758, -0.8000048684736); //G9
   glVertex2f(0.610621388717, -0.8000048684736); //H9
   glEnd();

   // Right door
   glBegin(GL_QUADS);
   glColor3ub(255, 255, 255);
   glVertex2f(0.7323094782337, -0.7736938476301); //G9
   glVertex2f(0.8325645898376, -0.7736938476301); //H9
   glVertex2f(0.8325645898376, -0.9108481653313); //I9
   glVertex2f(0.7323094782337, -0.9108481653313); //J9
   glEnd();
   glBegin(GL_LINES);
   glColor3ub(0, 0, 0);
   glVertex2f(0.7824481734336, -0.7736938476301); //G9
   glVertex2f(0.7824481734336, -0.9108481653313); //H9
   glEnd();


   // Middle carriage code ends here

   glPopMatrix();

   // updated train model code ends here

   // Plane code will go here

   glPushMatrix();
   glTranslatef(planePosition,0.0f, 0.0f);

   //Plane tail
   glBegin(GL_POLYGON);
   glColor3ub(255, 92, 92);
   glVertex2f(0.8358019188841, 0.8504269629171); //S1
   glVertex2f(0.88381860356, 0.8404090218668); //P1
   glVertex2f(0.9185412349809, 0.8637735585556); //Q1
   glVertex2f(0.9316038656871, 0.8737627140618); //M4
   glVertex2f(0.9327815383071, 0.8753293221571); //N4
   glVertex2f(0.9326295291775, 0.876697404323); //O4
   glVertex2f(0.9317681441101, 0.8779134773593); //P4
   glVertex2f(0.9295893465868, 0.8786228532971); //Q4
   glVertex2f(0.9274612187732, 0.8788255321365); //R4
   glVertex2f(0.9032410974668, 0.8799402657531); //S4
   glVertex2f(0.9012649787828, 0.8798895960433); //T4
   glVertex2f(0.89888350242, 0.8792815595251); //U4
   glVertex2f(0.8972114019951, 0.8785215138774); //V4
   glVertex2f(0.8945864156456, 0.8772187040285); //W4
   glVertex2f(0.8358019188841, 0.8504269629171); //S1
   glEnd();

   // Plane main body
   glBegin(GL_POLYGON);
   glColor3ub(8, 104, 150);
   glVertex2f(0.4931696166869, 0.8256810958153); //C1
   glVertex2f(0.4947744567499, 0.820619677155); // E1
   glVertex2f(0.4977372384047, 0.8171630985578); // F1
   glVertex2f(0.5126745959143, 0.8092623474784); //G1
   glVertex2f(0.527858851895, 0.8038305811112); //H1
   glVertex2f(0.55, 0.8); //I1
   glVertex2f(0.5971435291571, 0.7983374458889); //J1
   glVertex2f(0.7644941758939, 0.8085828922877); //K1
   glVertex2f(0.8358819419587, 0.8170986991965); //L1
   glVertex2f(0.8591212368993, 0.8224616134136); //M1
   glVertex2f(0.8661934067416, 0.8259745934379); //N1
   glVertex2f(0.8833627795043, 0.8355468986065); //O1
   glVertex2f(0.88381860356, 0.8404090218668); //P1
   glVertex2f(0.9185412349809, 0.8637735585556); //Q1
   glVertex2f(0.8538685824715, 0.8475664078491); //R1
   glVertex2f(0.8358019188841, 0.8504269629171); //S1
   glVertex2f(0.8177623187589, 0.8536990486945); //Z1
   glVertex2f(0.797120476474, 0.8558949893631); //A2
   glVertex2f(0.7729651291195, 0.8576517418979); //B2
   glVertex2f(0.7349753555527, 0.8611652469677); //C2
   glVertex2f(0.6912761362476, 0.8651179401712); //D2
   glVertex2f(0.6794180566372, 0.8655571283049); //E2
   glVertex2f(0.6278982128812, 0.8688360012186); //F2
   glVertex2f(0.5944919131105, 0.8701291483064); //G2
   glVertex2f(0.580698344173, 0.8701291483064); //H2
   glVertex2f(0.5725084126163, 0.8696980992771); //I2
   glVertex2f(0.5658271526621, 0.8684049521893); //J2
   glVertex2f(0.5578527456201, 0.8660341825281); //K2
   glVertex2f(0.5459988973144, 0.8595684470886); //L2
   glVertex2f(0.536382263609, 0.8527512670952); //M2
   glVertex2f(0.5285262147454, 0.8486449317491); //N2
   glVertex2f(0.519198416877, 0.8452430289971); //O2
   glVertex2f(0.5109680069931, 0.8417313874466);//P2
   glVertex2f(0.5048226342798, 0.8383294846946); //Q2
   glVertex2f(0.5024083807139, 0.8364639251209); //R2
   glVertex2f(0.4995551719542, 0.8342691491519); //S2
   glVertex2f(0.4970311795898, 0.8321841119813); //Z2
   glVertex2f(0.4950558812176, 0.8300990748107); //A3
   glVertex2f(0.4931696166869, 0.8256810958153); //C3
   glEnd();

   // Plane pilot window
   glBegin(GL_POLYGON);
   glColor3f(1.0, 1.0, 1.0);
   glVertex2f(0.5459988973144, 0.8595684470886); //L2
   glVertex2f(0.5484435225582, 0.8581125963309); //B3
   glVertex2f(0.5508898829972, 0.8570181719239); //C3
   glVertex2f(0.5528212201859, 0.8565031486736); //D3
   glVertex2f(0.5552896323442, 0.8563174078103); //E3
   glVertex2f(0.5579070747829, 0.8564387707673); //F3
   glVertex2f(0.5613834817226, 0.8565675265799); //G3
   glVertex2f(0.5639585979742, 0.8565675265799); //H3
   glVertex2f(0.5653749119126, 0.8560525033296); //I3
   glVertex2f(0.5668556037572, 0.8550868347352); //J3
   glVertex2f(0.5677568944453, 0.853928032422); //K3
   glVertex2f(0.5678212723516, 0.8520610731396); //L3
   glVertex2f(0.5678212723516, 0.849936602232); //M3
   glVertex2f(0.5678212723516, 0.8484559103873); //N3
   glVertex2f(0.567241871195, 0.8470395964489); //O3
   glVertex2f(0.5658899351629, 0.8466533290112); //P3
   glVertex2f(0.5635723305364, 0.8465889511049); //Q3
   glVertex2f(0.5609107663931, 0.8466688996364); //R3
   glVertex2f(0.5575208073451, 0.8469108406363); //S3
   glVertex2f(0.5540189421813, 0.8474679729524); //T3
   glVertex2f(0.5505406472968, 0.8482241240142); //U3
   glVertex2f(0.5474782354964, 0.8489802750761); //V3
   glVertex2f(0.5445670539083, 0.8496986185848); //W3
   glVertex2f(0.542198865648, 0.8505160033886); //Z3
   glVertex2f(0.5399456389279, 0.8512885382641); //A4
   glVertex2f(0.5379499238329, 0.8521898289521); //B4
   glVertex2f(0.536382263609, 0.8527512670952); //M2
   glVertex2f(0.5459988973144, 0.8595684470886); //L2
   glEnd();

   //Place passenger window
   glColor3f(1.0, 1.0, 1.0);
   DrawCircle(0.6136134880138, 0.8411480005225, 0.0035804757714, 2000); //C4
   DrawCircle(0.6355357881342, 0.8414408556768, 0.0035804757714, 2000); //D4
   DrawCircle(0.6571667992868, 0.8414456205529, 0.0035804757714, 2000); //E4
   DrawCircle(0.679067501284, 0.8416361909346, 0.0035804757714, 2000); //F4
   DrawCircle(0.7009679284309, 0.8415294616745, 0.0035804757714, 2000); //G4
   DrawCircle(0.72265947389, 0.8415294616745, 0.0035804757714, 2000); //H4
   DrawCircle(0.7445384675596, 0.8417593880138, 0.0035804757714, 2000); //J4
   DrawCircle(0.7665457011564, 0.8416987620259, 0.0035804757714, 2000); //I4
   DrawCircle(0.788, 0.842, 0.0035804757714, 2000); //K4

   //Plane back small wing
   glBegin(GL_POLYGON);
   glColor3ub(217, 215, 13);
   glVertex2f(0.8429190184152, 0.8388715830182); //Z4
   glVertex2f(0.8428187584983, 0.8357635255951); //A5
   glVertex2f(0.8699891959712, 0.8237323355702); //B5
   glVertex2f(0.9002676908672, 0.823130776069); //C5
   glVertex2f(0.9014766912113, 0.8234275134586); //d5
   glVertex2f(0.9025034098246, 0.8241001911708); //e5
   glVertex2f(0.9028574507257, 0.8250915056939); //f5
   glVertex2f(0.9027512384554, 0.8259766079467); //g5
   glVertex2f(0.9022555811938, 0.8267554979292); //h5
   glVertex2f(0.9014016655598, 0.82762094261); //I5
   glVertex2f(0.9004809145604, 0.8284665302625); //J5
   glVertex2f(0.8996710826156, 0.8291275719667); //K5
   glVertex2f(0.8989024842758, 0.8297443071596); //L5
   glVertex2f(0.8980568966233, 0.8302704505878); //M5
   glVertex2f(0.8970572291451, 0.8307109601084); //N5
   glVertex2f(0.8955020011973, 0.8313589717533); //O5
   glVertex2f(0.8768693126856, 0.838674312793); //P5
   glVertex2f(0.8429190184152, 0.8388715830182); //Z4
   glEnd();

   //Plane big wing
   glBegin(GL_POLYGON);
   glColor3ub(217, 215, 13);
   glVertex2f(0.6124736329244, 0.8227595947783); //Q5
   glVertex2f(0.6110676761079, 0.8217051271659); //R5
   glVertex2f(0.61, 0.82); //S5
   glVertex2f(0.6098726128138, 0.8185417243287); //T5
   glVertex2f(0.6103646976996, 0.8170654696713); //U5
   glVertex2f(0.6117003566753, 0.815589215014); //V5
   glVertex2f(0.6131766113327, 0.8140426625158); //W5
   glVertex2f(0.6658787763452, 0.7722024281381); //Z5
   glVertex2f(0.6669672079811, 0.7714181657979); //A6
   glVertex2f(0.6681233765325, 0.770809656034); //B6
   glVertex2f(0.6694316725249, 0.7702924227346); //C6
   glVertex2f(0.6710137979111, 0.7698664658999); //D6
   glVertex2f(0.672078689998, 0.7697447639471); //E6
   glVertex2f(0.673630389896, 0.7695926365061); //F6
   glVertex2f(0.7135351189402, 0.7714776243854); //G6
   glVertex2f(0.7148593214257, 0.7717972594681); //H6
   glVertex2f(0.7161378617566, 0.7722995431695); //I6
   glVertex2f(0.7173707399328, 0.7729844754896); //J6
   glVertex2f(0.7184209694903, 0.7738977185831); //K6
   glVertex2f(0.7191843707172, 0.7750120793597); //L6
   glVertex2f(0.7352872015836, 0.8240134714226); //M6
   glVertex2f(0.6812536153452, 0.8255889907556); //S6
   glVertex2f(0.662131400258, 0.8259186841192); //R6
   glVertex2f(0.6524054460326, 0.826083530801); //Q6
   glVertex2f(0.647460045579, 0.826083530801); //P6
   glVertex2f(0.6433388785344, 0.8259186841192); //O6
   glVertex2f(0.6283378304918, 0.8245999106649); //N6
   glVertex2f(0.6124736329244, 0.8227595947783); //Q5
   glEnd();

   glPopMatrix();
   // Plane code ends here

   glFlush();
}

void night(){

// All drawing related to night will be performed in this block
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Sky Drawing will start from here
    // This block creates a gradient of the sky

    glBegin(GL_POLYGON);
    glColor3ub(4, 26, 64);
    //glColor3ub(23, 91, 191);
    glVertex2f(-1, 1);
    glVertex2f(-0.5, 1);
    glVertex2f(0, 1);
    glVertex2f(0.5, 1);
    glVertex2f(1, 1);
    glVertex2f(1, 0.75);
    glVertex2f(1, 0.5);
    glVertex2f(1, 0.25);

    glColor3ub(56, 40, 92);
    //glColor3ub(23, 91, 191);
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

    //Star drawing code starts here

    glPointSize(4.0);
    glBegin(GL_POINTS);
    glColor3ub(253, 254, 254);
    glVertex2f(-0.3645172959228,0.4309170099487);
    glVertex2f(-0.1821772156068,0.4481564358171);
    glVertex2f(-0.1225022802306,0.5191033038138);
    glVertex2f(0.3405137665184,0.4669291361126);
    glVertex2f(0.6715992413588,0.4674006182477);

    glVertex2f(0.133518308869,0.6199728400006);
    glVertex2f(0.5253637739596,0.7548184461239);
    glVertex2f(0.2,0.8);
    glVertex2f(0.8410338162627,0.7080052324405);
    glVertex2f(-0.2894974846897,0.7359195857011);
    glVertex2f(-0.0297675866571,0.907116918527);
    glVertex2f(0.388722593744,0.9116657248602);
    glVertex2f(0.7185110511253,0.8866472900273);
    glEnd();

    // Start drawing code ends here

    // ====================================================

    // Moon drawing code starts here

    glColor3ub(253, 254, 254);
	DrawCircle(0.7356168493546, 0.5864996734224, 0.1620605572764, 2000);
	glColor3ub(4, 26, 64);
	DrawCircle(0.7356168493546 + 0.05, 0.5864996734224 + 0.05, 0.1620605572764, 2000);

    // Moon drawing code ends here

    // =================================================

    // Drawing clouds start from here

    // Cloud 1 starts from here


    glPushMatrix();
    glTranslatef(cloud1Position, 0.0f, 0.0f);
    glColor3ub(60,105,161);
	DrawCircle(-0.3799673933028, 0.5780739267177, 0.0653084338854, 2000);//1
    DrawCircle(-0.4599673933028, 0.5829705293098, 0.0995776305031, 2000);//2
	DrawCircle(-0.3099673933028, 0.5886832323339, 0.0783838868466, 2000);//3
    glPopMatrix();

    // Cloud 1 ends here

    // Cloud 2 Starts from here

    glPushMatrix();
    glTranslatef(cloud2Position, 0.0f, 0.0f);
    glColor3ub(24,62,124);
    DrawCircle(-0.3799673933028+1.0, 0.5780739267177+0.2, 0.0653084338854, 2000);//1
	DrawCircle(-0.4599673933028+1.0, 0.5829705293098+0.2, 0.0995776305031, 2000);//2
	DrawCircle(-0.3099673933028+1.0, 0.5886832323339+0.2, 0.0783838868466, 2000);//3
    glPopMatrix();

	// Cloud 2 ends here

	// Cloud 3 starts from here

    glPushMatrix();
    glTranslatef(cloud3Position, 0.0f, 0.0f);
	glColor3ub(60,105,161);
	DrawCircle(-0.3799673933028-0.35, 0.5780739267177+0.3, 0.0653084338854, 2000);//1
	DrawCircle(-0.4599673933028-0.35, 0.5829705293098+0.3, 0.0995776305031, 2000);//2
    glPopMatrix();

    // Cloud 3 ends here

    // Drawing clouds ends here


    // =================================================

    // Drawing Mountains start here

    // Mountain 1 - Most back mountain starts from here

    glBegin(GL_POLYGON);
    glColor3ub(32, 41, 47);
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
    glColor3ub(38, 48, 55);
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
    glColor3ub(43, 55, 63);
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
    glColor3ub(50, 62, 71);
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
    glColor3ub(50, 62, 71);
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
    glColor3ub(10,46,82);
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
    glColor3ub(112,168,198);
    glVertex2f(-0.6, -0.3);
    glVertex2f(-0.4, -0.3);
    glVertex2f(-0.5, -0.275);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(32,93,140);
    glVertex2f(0.6, -0.3);
    glVertex2f(0.8, -0.3);
    glVertex2f(0.7, -0.275);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(32,93,140);
    glVertex2f(-0.9, -0.4);
    glVertex2f(-0.7, -0.4);
    glVertex2f(-0.8, -0.375);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(32,93,140);
    glVertex2f(0.3, -0.4);
    glVertex2f(0.5, -0.4);
    glVertex2f(0.4, -0.375);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(32,93,140);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.3, -0.5);
    glVertex2f(-0.4, -0.475);
    glEnd();
    glPushMatrix();

    glTranslatef(rightWavePosition1,0.0f, 0.0f);
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
    glColor3ub(111,170,202);
    glVertex2f(0.0, -0.3);
    glVertex2f(0.2, -0.3);
    glVertex2f(0.1, -0.275);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(111,170,202);
    glVertex2f(-0.3, -0.4);
    glVertex2f(-0.1, -0.4);
    glVertex2f(-0.2, -0.375);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(111,170,202);
    glVertex2f(0.1, -0.5);
    glVertex2f(0.3, -0.5);
    glVertex2f(0.2, -0.475);
    glEnd();

    glPopMatrix();

    // Wave set code ENDS here

    // River code ends here

    // ===============================================

    // Boat code starts from here

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
   glColor3ub(130, 130, 130);
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
   glColor3ub(82, 82, 82);
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
   glColor3ub(130, 130, 130);
   glVertex2f(0.52f, -0.23f);
   glVertex2f(0.56f, -0.23f);
   glVertex2f(0.56f, -0.18f);
   glVertex2f(0.52f, -0.18f);
   glEnd();

   //2nd flr right big block
   glBegin(GL_QUADS);
   glColor3ub(130, 130, 130);
   glVertex2f(0.56f, -0.23f);
   glVertex2f(0.71f, -0.23f);
   glVertex2f(0.71f, -0.16f);
   glVertex2f(0.56f, -0.16f);
   glEnd();

   // 2nd flr door
   glBegin(GL_QUADS);
   glColor3ub(82, 82, 82);
   glVertex2f(0.64f, -0.23f);
   glVertex2f(0.67f, -0.23f);
   glVertex2f(0.67f, -0.17f);
   glVertex2f(0.64f, -0.17f);
   glEnd();

   // 2nd flr door window
   glBegin(GL_QUADS);
   glColor3ub(100, 204, 204);
   glVertex2f(0.65f, -0.20f);
   glVertex2f(0.662f, -0.20f);
   glVertex2f(0.662f, -0.18f);
   glVertex2f(0.65f, -0.18f);
   glEnd();

   // 2nd flr big window
   glBegin(GL_QUADS);
   glColor3ub(100, 204, 204);
   glVertex2f(0.59f, -0.20f);
   glVertex2f(0.63f, -0.20f);
   glVertex2f(0.63f, -0.17f);
   glVertex2f(0.59f, -0.17f);
   glEnd();

   // 2nd flr small window
   glBegin(GL_QUADS);
   glColor3ub(100, 204, 204);
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
   glColor3ub(5, 166, 96);
   glVertex2f(0.38f, -0.33f);
   glVertex2f(0.41f, -0.33f);
   glVertex2f(0.41f, -0.32f);
   glVertex2f(0.38f, -0.32f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(5, 166, 96);
   glVertex2f(0.41f, -0.33f);
   glVertex2f(0.43f, -0.33f);
   glVertex2f(0.43f, -0.32f);
   glVertex2f(0.41f, -0.32f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(5, 166, 96);
   glVertex2f(0.43f, -0.33f);
   glVertex2f(0.45f, -0.33f);
   glVertex2f(0.45f, -0.32f);
   glVertex2f(0.43f, -0.32f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(5, 166, 96);
   glVertex2f(0.38f, -0.32f);
   glVertex2f(0.41f, -0.32f);
   glVertex2f(0.41f, -0.31f);
   glVertex2f(0.38f, -0.31f);
   glEnd();


   glBegin(GL_QUADS);
   glColor3ub(5, 166, 96);
   glVertex2f(0.43f, -0.32f);
   glVertex2f(0.45f, -0.32f);
   glVertex2f(0.45f, -0.31f);
   glVertex2f(0.43f, -0.31f);
   glEnd();

   glPopMatrix();

   // back fence code block ends here

   // Boat code ends here

   // ===========================================================

   // Back tree row common fill code starts here

   glBegin(GL_QUADS);
   glColor3ub(0, 82, 0);
   glVertex2f(1.0, -0.5756367057105); // Base +x down
   glVertex2f(-1.0, -0.5756367057105); // Base -x down
   glVertex2f(-1.0, -0.6869004722551);
   glVertex2f(1.0, -0.6869004722551);
   glEnd();

   // Back tree row common fill code ends here

   // Bush code starts here

   glColor3ub(0, 82, 0);
	DrawCircle(-0.9072372816471, -0.5468327234769, 0.0978210355299, 2000);//1
    DrawCircle(-0.7882306545015, -0.5235785549542, 0.0951840734353, 2000);//2
	DrawCircle(-0.6500735356314, -0.5372574776146, 0.096724589725, 2000);//3
	DrawCircle(-0.5283311239537, -0.4934849251013, 0.108227857386, 2000);//4
	DrawCircle(-0.3696556210929, -0.5317859085505, 0.1003328230094, 2000);//5
	DrawCircle(-0.2219232563605, -0.5673511074675, 0.1262189788627, 2000);//6
	DrawCircle(-0.0315276315684, -0.4951186711054, 0.1503734194491, 2000);//7
	DrawCircle(0.0896782091289, -0.4385559454467, 0.0983021794995, 2000);//8
	DrawCircle(0.1769464144309, -0.4838061259736, 0.1155580437535, 2000);//9
	DrawCircle(0.2512859967253, -0.5322884622525, 0.096126072669, 2000);//10
	DrawCircle(0.3821883046783, -0.4870382817256, 0.1047961396401, 2000);//11
	DrawCircle(0.5003317807708, -0.5258241507487, 0.0740050744839, 2000);//12
	DrawCircle(0.644505499274, -0.4974731103267, 0.1039797036134, 2000);//13
	DrawCircle(0.7710785506579, -0.4841496312337, 0.093338673811, 2000);//14
	DrawCircle(0.7910637692975, -0.5557633313588, 0.117575444767, 2000);//15
	DrawCircle(0.9292948648878, -0.4641644125941, 0.1348282433764, 2000);//16

	// Bush Code ends here

   // ============================================================

   // Pine Tree code starts here

   // Ground grass color code starts here

   glBegin(GL_QUADS);
   glColor3ub(3, 96, 3);
   glVertex2f(-1.0, -0.6869004722551);
   glVertex2f(1.0, -0.6869004722551);
   glVertex2f(1.0, -1);
   glVertex2f(-1.0, -1);
   glEnd();

   // Ground grass color code ends here

   // tree 1 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 40);
   glVertex2f(-0.2938571399917, -0.4423232979151);
   glVertex2f(-0.2115496244678, -0.5423834148265);
   glVertex2f(-0.3793924012224, -0.5415764783998);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.2978918221252, -0.5084920849049);
   glVertex2f(-0.1841137859599, -0.5811163633083);
   glVertex2f(-0.3898825747696, -0.5762747447481);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3, -0.55);
   glVertex2f(-0.1792721673996, -0.6408296588845);
   glVertex2f(-0.3955311297565, -0.6335672310441);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3, -0.6);
   glVertex2f(-0.1740006707345, -0.6905816498292);
   glVertex2f(-0.4187989794158, -0.6869004722551);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136, -0.6973304753819);
   glVertex2f(-0.2825954091721, -0.6961034161905);
   glVertex2f(-0.2801412907893, -0.74886696142);
   glVertex2f(-0.3187936553179, -0.7494804910157);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3, -0.65);
   glVertex2f(-0.1574353716508, -0.7286204847622);
   glVertex2f(-0.4286154529469, -0.7292340143579);
   glEnd();

   // Tree 1 code ends here

   // tree 2 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.2938571399917 + 0.3, -0.4423232979151);
   glVertex2f(-0.2115496244678 + 0.3, -0.5423834148265);
   glVertex2f(-0.3793924012224 + 0.3, -0.5415764783998);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.2978918221252 + 0.3, -0.5084920849049);
   glVertex2f(-0.1841137859599 + 0.3, -0.5811163633083);
   glVertex2f(-0.3898825747696 + 0.3, -0.5762747447481);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3 + 0.3, -0.55);
   glVertex2f(-0.1792721673996 + 0.3, -0.6408296588845);
   glVertex2f(-0.3955311297565 + 0.3, -0.6335672310441);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3 + 0.3, -0.6);
   glVertex2f(-0.1740006707345 + 0.3, -0.6905816498292);
   glVertex2f(-0.4187989794158 + 0.3, -0.6869004722551);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136 + 0.3 , -0.6973304753819);
   glVertex2f(-0.2825954091721 + 0.3, -0.6961034161905);
   glVertex2f(-0.2801412907893 + 0.3, -0.74886696142);
   glVertex2f(-0.3187936553179 + 0.3, -0.7494804910157);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3 + 0.3, -0.65);
   glVertex2f(-0.1574353716508 + 0.3, -0.7286204847622);
   glVertex2f(-0.4286154529469 + 0.3, -0.7292340143579);
   glEnd();

   // Tree 2 code ends here

   // tree 3 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.2938571399917 + 0.6, -0.4423232979151);
   glVertex2f(-0.2115496244678 + 0.6, -0.5423834148265);
   glVertex2f(-0.3793924012224 + 0.6, -0.5415764783998);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.2978918221252 + 0.6, -0.5084920849049);
   glVertex2f(-0.1841137859599 + 0.6, -0.5811163633083);
   glVertex2f(-0.3898825747696 + 0.6, -0.5762747447481);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3 + 0.6, -0.55);
   glVertex2f(-0.1792721673996 + 0.6, -0.6408296588845);
   glVertex2f(-0.3955311297565 + 0.6, -0.6335672310441);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3 + 0.6, -0.6);
   glVertex2f(-0.1740006707345 + 0.6, -0.6905816498292);
   glVertex2f(-0.4187989794158 + 0.6, -0.6869004722551);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136 + 0.6 , -0.6973304753819);
   glVertex2f(-0.2825954091721 + 0.6, -0.6961034161905);
   glVertex2f(-0.2801412907893 + 0.6, -0.74886696142);
   glVertex2f(-0.3187936553179 + 0.6, -0.7494804910157);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3 + 0.6, -0.65);
   glVertex2f(-0.1574353716508 + 0.6, -0.7286204847622);
   glVertex2f(-0.4286154529469 + 0.6, -0.7292340143579);
   glEnd();

   // Tree 3 code ends here

      // tree 2 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.2938571399917 + 0.3, -0.4423232979151);
   glVertex2f(-0.2115496244678 + 0.3, -0.5423834148265);
   glVertex2f(-0.3793924012224 + 0.3, -0.5415764783998);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.2978918221252 + 0.3, -0.5084920849049);
   glVertex2f(-0.1841137859599 + 0.3, -0.5811163633083);
   glVertex2f(-0.3898825747696 + 0.3, -0.5762747447481);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3 + 0.3, -0.55);
   glVertex2f(-0.1792721673996 + 0.3, -0.6408296588845);
   glVertex2f(-0.3955311297565 + 0.3, -0.6335672310441);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3 + 0.3, -0.6);
   glVertex2f(-0.1740006707345 + 0.3, -0.6905816498292);
   glVertex2f(-0.4187989794158 + 0.3, -0.6869004722551);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136 + 0.3 , -0.6973304753819);
   glVertex2f(-0.2825954091721 + 0.3, -0.6961034161905);
   glVertex2f(-0.2801412907893 + 0.3, -0.74886696142);
   glVertex2f(-0.3187936553179 + 0.3, -0.7494804910157);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3 + 0.3, -0.65);
   glVertex2f(-0.1574353716508 + 0.3, -0.7286204847622);
   glVertex2f(-0.4286154529469 + 0.3, -0.7292340143579);
   glEnd();

   // Tree 2 code ends here

   // tree 4 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.2938571399917 + 0.9, -0.4423232979151);
   glVertex2f(-0.2115496244678 + 0.9, -0.5423834148265);
   glVertex2f(-0.3793924012224 + 0.9, -0.5415764783998);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.2978918221252 + 0.9, -0.5084920849049);
   glVertex2f(-0.1841137859599 + 0.9, -0.5811163633083);
   glVertex2f(-0.3898825747696 + 0.9, -0.5762747447481);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3 + 0.9, -0.55);
   glVertex2f(-0.1792721673996 + 0.9, -0.6408296588845);
   glVertex2f(-0.3955311297565 + 0.9, -0.6335672310441);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3 + 0.9, -0.6);
   glVertex2f(-0.1740006707345 + 0.9, -0.6905816498292);
   glVertex2f(-0.4187989794158 + 0.9, -0.6869004722551);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136 + 0.9 , -0.6973304753819);
   glVertex2f(-0.2825954091721 + 0.9, -0.6961034161905);
   glVertex2f(-0.2801412907893 + 0.9, -0.74886696142);
   glVertex2f(-0.3187936553179 + 0.9, -0.7494804910157);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3 + 0.9, -0.65);
   glVertex2f(-0.1574353716508 + 0.9, -0.7286204847622);
   glVertex2f(-0.4286154529469 + 0.9, -0.7292340143579);
   glEnd();

   // Tree 4 code ends here

      // tree 5 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.2938571399917 + 1.2, -0.4423232979151);
   glVertex2f(-0.2115496244678 + 1.2, -0.5423834148265);
   glVertex2f(-0.3793924012224 + 1.2, -0.5415764783998);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.2978918221252 + 1.2, -0.5084920849049);
   glVertex2f(-0.1841137859599 + 1.2, -0.5811163633083);
   glVertex2f(-0.3898825747696 + 1.2, -0.5762747447481);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3 + 1.2, -0.55);
   glVertex2f(-0.1792721673996 + 1.2, -0.6408296588845);
   glVertex2f(-0.3955311297565 + 1.2, -0.6335672310441);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3 + 1.2, -0.6);
   glVertex2f(-0.1740006707345 + 1.2, -0.6905816498292);
   glVertex2f(-0.4187989794158 + 1.2, -0.6869004722551);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136 + 1.2 , -0.6973304753819);
   glVertex2f(-0.2825954091721 + 1.2, -0.6961034161905);
   glVertex2f(-0.2801412907893 + 1.2, -0.74886696142);
   glVertex2f(-0.3187936553179 + 1.2, -0.7494804910157);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3 + 1.2, -0.65);
   glVertex2f(-0.1574353716508 + 1.2, -0.7286204847622);
   glVertex2f(-0.4286154529469 + 1.2, -0.7292340143579);
   glEnd();

   // Tree 5 code ends here

   // tree 6 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.2938571399917 - 0.3, -0.4423232979151 + 0.03);
   glVertex2f(-0.2115496244678 - 0.3, -0.5423834148265 + 0.03);
   glVertex2f(-0.3793924012224 - 0.3, -0.5415764783998 + 0.03);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.2978918221252 - 0.3, -0.5084920849049 + 0.03);
   glVertex2f(-0.1841137859599 - 0.3, -0.5811163633083 + 0.03);
   glVertex2f(-0.3898825747696 - 0.3, -0.5762747447481 + 0.03);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3 - 0.3, -0.55 + 0.03);
   glVertex2f(-0.1792721673996 - 0.3, -0.6408296588845 + 0.03);
   glVertex2f(-0.3955311297565 - 0.3, -0.6335672310441 + 0.03);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3 - 0.3, -0.6);
   glVertex2f(-0.1740006707345 - 0.3, -0.6905816498292 + 0.03);
   glVertex2f(-0.4187989794158 - 0.3, -0.6869004722551 + 0.03);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136 - 0.3 , -0.6973304753819 + 0.03);
   glVertex2f(-0.2825954091721 - 0.3, -0.6961034161905 + 0.03);
   glVertex2f(-0.2801412907893 - 0.3, -0.74886696142 + 0.03);
   glVertex2f(-0.3187936553179 - 0.3, -0.7494804910157 + 0.03);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3 - 0.3, -0.65);
   glVertex2f(-0.1574353716508 - 0.3, -0.7286204847622 + 0.03);
   glVertex2f(-0.4286154529469 - 0.3, -0.7292340143579 + 0.03);
   glEnd();

   // Tree 6 code ends here

      // tree 7 code starts here

   // 1st triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.2938571399917 - 0.6, -0.4423232979151);
   glVertex2f(-0.2115496244678 - 0.6, -0.5423834148265);
   glVertex2f(-0.3793924012224 - 0.6, -0.5415764783998);
   glEnd();
   // 2nd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.2978918221252 - 0.6, -0.5084920849049);
   glVertex2f(-0.1841137859599 - 0.6, -0.5811163633083);
   glVertex2f(-0.3898825747696 - 0.6, -0.5762747447481);
   glEnd();
   //3rd triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3 - 0.6, -0.55);
   glVertex2f(-0.1792721673996 - 0.6, -0.6408296588845);
   glVertex2f(-0.3955311297565 - 0.6, -0.6335672310441);
   glEnd();
   //4th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3 - 0.6, -0.6);
   glVertex2f(-0.1740006707345 - 0.6, -0.6905816498292);
   glVertex2f(-0.4187989794158 - 0.6, -0.6869004722551);
   glEnd();
   // Tree stand
   glBegin(GL_QUADS);
   glColor3ub(118, 92, 72);
   glVertex2f(-0.3194071849136 - 0.6 , -0.6973304753819);
   glVertex2f(-0.2825954091721 - 0.6, -0.6961034161905);
   glVertex2f(-0.2801412907893 - 0.6, -0.74886696142);
   glVertex2f(-0.3187936553179 - 0.6, -0.7494804910157);
   glEnd();
   //5th triangle
   glBegin(GL_TRIANGLES);
   glColor3ub(0, 53, 0);
   glVertex2f(-0.3 - 0.6, -0.65);
   glVertex2f(-0.1574353716508 - 0.6, -0.7286204847622);
   glVertex2f(-0.4286154529469 - 0.6, -0.7292340143579);
   glEnd();

   // Tree 7 code ends here

   // Pine Tree code ends here

   // ================================================

   // Fence code starts here

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-1.0f, -0.95f + 0.15f);
      glVertex2f(1.0f, -0.95f + 0.15f);
      glVertex2f(1.0f, -0.93f + 0.15f);
      glVertex2f(-1.0f, -0.93f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-1.0f, -0.87f + 0.15f);
      glVertex2f(1.0f, -0.87f + 0.15f);
      glVertex2f(1.0f, -0.85f + 0.15f);
      glVertex2f(-1.0f, -0.85f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.92f, -0.98f + 0.15f);
      glVertex2f(-0.88f, -0.98f + 0.15f);
      glVertex2f(-0.88f, -0.82f + 0.15f);
      glVertex2f(-0.92f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.82f, -0.98f + 0.15f);
      glVertex2f(-0.79f, -0.98f + 0.15f);
      glVertex2f(-0.79f, -0.82f + 0.15f);
      glVertex2f(-0.82f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.72f, -0.98f + 0.15f);
      glVertex2f(-0.69f, -0.98f + 0.15f);
      glVertex2f(-0.69f, -0.82f + 0.15f);
      glVertex2f(-0.72f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.62f, -0.98f + 0.15f);
      glVertex2f(-0.59f, -0.98f + 0.15f);
      glVertex2f(-0.59f, -0.82f + 0.15f);
      glVertex2f(-0.62f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.52f, -0.98f + 0.15f);
      glVertex2f(-0.49f, -0.98f + 0.15f);
      glVertex2f(-0.49f, -0.82f + 0.15f);
      glVertex2f(-0.52f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.42f, -0.98f + 0.15f);
      glVertex2f(-0.39f, -0.98f + 0.15f);
      glVertex2f(-0.39f, -0.82f + 0.15f);
      glVertex2f(-0.42f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.32f, -0.98f + 0.15f);
      glVertex2f(-0.29f, -0.98f + 0.15f);
      glVertex2f(-0.29f, -0.82f + 0.15f);
      glVertex2f(-0.32f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.22f, -0.98f + 0.15f);
      glVertex2f(-0.19f, -0.98f + 0.15f);
      glVertex2f(-0.19f, -0.82f + 0.15f);
      glVertex2f(-0.22f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.12f, -0.98f + 0.15f);
      glVertex2f(-0.09f, -0.98f + 0.15f);
      glVertex2f(-0.09f, -0.82f + 0.15f);
      glVertex2f(-0.12f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(-0.02f, -0.98f + 0.15f);
      glVertex2f(0.0f, -0.98f + 0.15f);
      glVertex2f(0.0f, -0.82f + 0.15f);
      glVertex2f(-0.02f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.12f, -0.98f + 0.15f);
      glVertex2f(0.09f, -0.98f + 0.15f);
      glVertex2f(0.09f, -0.82f + 0.15f);
      glVertex2f(0.12f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.22f, -0.98f + 0.15f);
      glVertex2f(0.19f, -0.98f + 0.15f);
      glVertex2f(0.19f, -0.82f + 0.15f);
      glVertex2f(0.22f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.32f, -0.98f + 0.15f);
      glVertex2f(0.29f, -0.98f + 0.15f);
      glVertex2f(0.29f, -0.82f + 0.15f);
      glVertex2f(0.32f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.42f, -0.98f + 0.15f);
      glVertex2f(0.39f, -0.98f + 0.15f);
      glVertex2f(0.39f, -0.82f + 0.15f);
      glVertex2f(0.42f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.52f, -0.98f + 0.15f);
      glVertex2f(0.49f, -0.98f + 0.15f);
      glVertex2f(0.49f, -0.82f + 0.15f);
      glVertex2f(0.52f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.62f, -0.98f + 0.15f);
      glVertex2f(0.59f, -0.98f + 0.15f);
      glVertex2f(0.59f, -0.82f + 0.15f);
      glVertex2f(0.62f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.72f, -0.98f + 0.15f);
      glVertex2f(0.69f, -0.98f + 0.15f);
      glVertex2f(0.69f, -0.82f + 0.15f);
      glVertex2f(0.72f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.82f, -0.98f + 0.15f);
      glVertex2f(0.79f, -0.98f + 0.15f);
      glVertex2f(0.79f, -0.82f + 0.15f);
      glVertex2f(0.82f, -0.82f + 0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(78, 75, 75);
      glVertex2f(0.92f, -0.98f + 0.15f);
      glVertex2f(0.89f, -0.98f + 0.15f);
      glVertex2f(0.89f, -0.82f + 0.15f);
      glVertex2f(0.92f, -0.82f + 0.15f);
    glEnd();

   // Fence Code ends here

   // =============================================================

   // Close Train code starts here

   // Train track code starts here

   glBegin(GL_QUADS);
   glColor3ub(123, 123, 123);
   glVertex2f(-1.0, -0.9599998637683);
   glVertex2f(-1.0, -0.9443483025884);
   glVertex2f(1.0, -0.9443483025884);
   glVertex2f(1.0, -0.9599998637683);
   glEnd();

   // Train track code ends here

   // ==================================================================

   // updated train model code starts here

   glPushMatrix();
   glTranslatef(trainPosition,0.0f, 0.0f);

   // Connector code
   glBegin(GL_QUADS);
   glColor3ub(201, 201, 201);
   glVertex2f(0.4588413119369, -0.7467275099806); //G9
   glVertex2f(0.4798857278648, -0.7467275099806); //H9
   glVertex2f(0.4798857278648, -0.9117251206329); //I9
   glVertex2f(0.4588413119369, -0.9117251206329); //J9
   glEnd();

   // left engine wheel code goes here

   //y = -0.9137316052198 for wheel center
   glColor3ub(82, 82, 82);
   // Back pair
   DrawCircle(0.2979740488535, -0.9361512437916, 0.023803337574, 8000);//1 - far left
   DrawCircle(0.2979740488535 + 0.0679267614286, -0.9361512437916, 0.023803337574, 8000);//1 - far left

   // Front pair
   DrawCircle(0.1140783890, -0.9361512437916, 0.023803337574, 8000);//1 - far left
   DrawCircle(0.1140783890 + 0.0679267614286, -0.9361512437916, 0.023803337574, 8000);//1 - far left

   //  left engine body code goes here
   glBegin(GL_POLYGON);
   glColor3ub(0, 0, 104);
   glVertex2f(0.0902750519795, -0.9243514184048); //V
   glVertex2f(0.2638419609981, -0.9243514184048); //Z
   glVertex2f(0.2638419609981, -0.9243514184048); //Z
   glVertex2f(0.2673071512138, -0.9172990967291); //T1
   glVertex2f(0.268625571989, -0.9152051343215); //U1
   glVertex2f(0.2704868719069, -0.9137316052198); //V1
   glVertex2f(0.2730461592941, -0.9135764968933); //W1
   glVertex2f(0.3883143036753, -0.9139417200826); //T2
   glVertex2f(0.3897577491135, -0.9142537476641); //U2
   glVertex2f(0.3910351937303, -0.9149161263543); //V2
   glVertex2f(0.392, -0.916); //W2
   glVertex2f(0.3973751040505, -0.9239055514352); //E8
   glVertex2f(0.4495081231461, -0.9243514184048); //F8
   glVertex2f(0.4517892659953, -0.9237467603624); //G8
   glVertex2f(0.4539527958094, -0.9226913799653); //H8
   glVertex2f(0.455535866405, -0.9215832305484); //I8
   glVertex2f(0.456644015822, -0.9201584670122); //J8
   glVertex2f(0.4573827821, -0.9185753964166); //K8
   glVertex2f(0.4573827821, -0.7408630998829); //L8
   glVertex2f(0.4580127024621, -0.7385660853445); //M8
   glVertex2f(0.4568244590262, -0.7365460715036); //N8
   glVertex2f(0.455, -0.735); //o8
   glVertex2f(0.4533191408905, -0.7341101724601); //P8
   glVertex2f(0.4508832418471, -0.733872523773); //Q8 - MAX Y VALUE
   glVertex2f(0.1311461118639, -0.733872523773); //S8
   glVertex2f(0.1269818194044, -0.7332398273495); //T8
   glVertex2f(0.1233172420401, -0.7345724009365); //U8
   glVertex2f(0.1196526646757, -0.7367378330155); //V8
   glVertex2f(0.1164878024065, -0.7390698367928); //W8
   glVertex2f(0.1134895118357, -0.7425678424587); //Z8
   glVertex2f(0.04, -0.866); //A9
   glVertex2f(0.0387581733414, -0.8689573745512); //B9
   glVertex2f(0.0382721983081, -0.8707068846711); //C9
   glVertex2f(0.0380172743025, -0.8741027234919); //A
   glVertex2f(0.0380487737159, -0.8776008690587); //H
   glVertex2f(0.0387481261355, -0.8810976311566); //I
   glVertex2f(0.0397971547648, -0.8848275107277); //L
   glVertex2f(0.0413124183406, -0.888207714089); //M
   glVertex2f(0.0432939168627, -0.8913547999771); //N
   glVertex2f(0.0458582090679, -0.8952012382848); //O
   glVertex2f(0.0486556187462, -0.8981152066997); //P
   glVertex2f(0.0516980249696, -0.9007746742169); //Q
   glVertex2f(0.0566279964724, -0.9041024049814); //R
   glVertex2f(0.0689529252296, -0.9114973622357); //T
   glVertex2f(0.0902750519795, -0.9243514184048); //V
   glEnd();

   // left engine - engine master window code goes here
   glBegin(GL_POLYGON);
   glColor3ub(221, 255, 255);
   glVertex2f(0.1028258229583, -0.7605273722022); //G9
   glVertex2f(0.1045268049421, -0.7603038528659); //H9
   glVertex2f(0.1064892834981, -0.7600234987865); //I9
   glVertex2f(0.1076574254957, -0.7604907555856); //J9
   glVertex2f(0.1084517620541, -0.7616121719033); //K9
   glVertex2f(0.1088255674933, -0.7633877477396); //L9
   glVertex2f(0.0963670020494, -0.854308496056); //M9
   glVertex2f(0.0959840335848, -0.8561686285981); //N9
   glVertex2f(0.0952728064364, -0.857755212237); //O9
   glVertex2f(0.0940144814815, -0.8591229567532); //P9
   glVertex2f(0.0921543489394, -0.8600530230242); //Q9
   glVertex2f(0.081256053022, -0.8638552288953); //R9
   glVertex2f(0.0764584464475, -0.8650420401822); //S9
   glVertex2f(0.0707017648046, -0.8653097928167); //T9
   glVertex2f(0.0634724436716, -0.8650420401822); //U9
   glVertex2f(0.0578496383459, -0.8645065349131); //V9
   glVertex2f(0.0522268330203, -0.8633016480576); //W9
   glVertex2f(0.0434783774913, -0.8602687046815); //Z9
   glVertex2f(0.1028258229583, -0.7605273722022); //G9
   glEnd();

   // left engine - engine master door
   glBegin(GL_QUADS);
   glColor3ub(255, 255, 255);
   glVertex2f(0.1649363264379, -0.7736938476301); //G9
   glVertex2f(0.2210939998274, -0.7736938476301); //H9
   glVertex2f(0.2210939998274, -0.9108481653313); //I9
   glVertex2f(0.1649363264379, -0.9108481653313); //J9
   glEnd();

   // Left engine - main window
   glBegin(GL_QUADS);
   glColor3ub(255, 255, 255);
   glVertex2f(0.2329994395528, -0.7736938476301); //G9
   glVertex2f(0.4296313165988, -0.7736938476301); //H9
   glVertex2f(0.4296313165988, -0.8562788832022); //I9
   glVertex2f(0.2329994395528, -0.8562788832022); //J9
   glEnd();
   glBegin(GL_LINES);
   glColor3ub(0, 0, 0);
   glVertex2f(0.2329994395528, -0.8000048684736); //G9
   glVertex2f(0.4296313165988, -0.8000048684736); //H9
   glEnd();

   // Left Engine top Box code goes here
   glBegin(GL_QUADS);
   glColor3ub(0, 0, 34);
   glVertex2f(0.4341934243381, -0.733329040145); //G9
   glVertex2f(0.4341934243381, -0.7175755480725); //H9
   glVertex2f(0.1797273626565, -0.7175755480725); //I9
   glVertex2f(0.1797273626565, -0.733329040145); //J9
   glEnd();

   // Left engine code ends here

   // Middle carriage of train code goes here

   // Middle carriage wheel code
   glColor3ub(82, 82, 82);
   DrawCircle(0.6335635062646, -0.9361512437916, 0.023803337574, 8000);//1 - far left
   DrawCircle(0.6335635062646 + 0.0679267614286, -0.9361512437916, 0.023803337574, 8000);//1 - far left

   // Carriage body code
   glBegin(GL_POLYGON);
   glColor3ub(0, 0, 104);
   glVertex2f(0.4801758240852, -0.9191043740047); //I11
   glVertex2f(0.4809755595681, -0.9205862368113); //H11
   glVertex2f(0.482410379111, -0.9219975347223); //G11
   glVertex2f(0.4841257894728, -0.9232021159928); //J11
   glVertex2f(0.4855932943556, -0.9237627358357); //F11
   glVertex2f(0.4872381164666, -0.9240447934564); //E11
   glVertex2f(0.8489917039809, -0.9240447934564); //D11
   glVertex2f(0.8504746539721, -0.9242064673156); //C11
   glVertex2f(0.851715489679, -0.9234801244628); //B11
   glVertex2f(0.8527444753872, -0.9221787601848); //A11
   glVertex2f(0.8535010825255, -0.9205142244804); //Z10
   glVertex2f(0.8540128051614, -0.9188721651553); //W10
   glVertex2f(0.8541329302856, -0.9169501631667); //V10
   glVertex2f(0.8541329302856, -0.7405637387567); //U10
   glVertex2f(0.8529695509292, -0.7392606860364); //T10
   glVertex2f(0.8515268854173, -0.7376318701359); //S10
   glVertex2f(0.8501772950998, -0.736468430207); //R10
   glVertex2f(0.848455404005, -0.7353980654724); //Q10
   glVertex2f(0.8462043017123, -0.7345738841131); //P10
   glVertex2f(0.4873888670143, -0.7345738841131); //o10
   glVertex2f(0.485, -0.735); //N10
   glVertex2f(0.4831260743853, -0.7365778999664); //M10
   glVertex2f(0.4813790282259, -0.7385345916649); //L10
   glVertex2f(0.4801758240852, -0.7408406925953); //K19
   glVertex2f(0.4801758240852, -0.9191043740047); //I11
   glEnd();

   //top Box code goes here
   glBegin(GL_QUADS);
   glColor3ub(0, 0, 34);
   glVertex2f(0.5054866328459, -0.733329040145); //G9
   glVertex2f(0.5054866328459, -0.7175755480725); //H9
   glVertex2f(0.8286505622915, -0.7175755480725); //I9
   glVertex2f(0.8286505622915, -0.733329040145); //J9
   glEnd();

   // Left door
   glBegin(GL_QUADS);
   glColor3ub(255, 255, 255);
   glVertex2f(0.5003789366041, -0.7736938476301); //G9
   glVertex2f(0.600634048208, -0.7736938476301); //H9
   glVertex2f(0.600634048208, -0.9108481653313); //I9
   glVertex2f(0.5003789366041, -0.9108481653313); //J9
   glEnd();
   glBegin(GL_LINES);
   glColor3ub(0, 0, 0);
   glVertex2f(0.5505176318039, -0.7736938476301); //G9
   glVertex2f(0.5505176318039, -0.9108481653313); //H9
   glEnd();

   // Window
   glBegin(GL_QUADS);
   glColor3ub(255, 255, 255);
   glVertex2f(0.610621388717, -0.7736938476301); //G9
   glVertex2f(0.7222523746758, -0.7736938476301); //H9
   glVertex2f(0.7222523746758, -0.8562788832022); //I9
   glVertex2f(0.610621388717, -0.8562788832022); //J9
   glEnd();
   glBegin(GL_LINES);
   glColor3ub(0, 0, 0);
   glVertex2f(0.7222523746758, -0.8000048684736); //G9
   glVertex2f(0.610621388717, -0.8000048684736); //H9
   glEnd();

   // Right door
   glBegin(GL_QUADS);
   glColor3ub(255, 255, 255);
   glVertex2f(0.7323094782337, -0.7736938476301); //G9
   glVertex2f(0.8325645898376, -0.7736938476301); //H9
   glVertex2f(0.8325645898376, -0.9108481653313); //I9
   glVertex2f(0.7323094782337, -0.9108481653313); //J9
   glEnd();
   glBegin(GL_LINES);
   glColor3ub(0, 0, 0);
   glVertex2f(0.7824481734336, -0.7736938476301); //G9
   glVertex2f(0.7824481734336, -0.9108481653313); //H9
   glEnd();


   // Middle carriage code ends here

   glPopMatrix();

   // updated train model code ends here

   // Plane code will go here

   glPushMatrix();
   glTranslatef(planePosition,0.0f, 0.0f);

   //Plane tail
   glBegin(GL_POLYGON);
   glColor3ub(143,20,5);
   glVertex2f(0.8358019188841, 0.8504269629171); //S1
   glVertex2f(0.88381860356, 0.8404090218668); //P1
   glVertex2f(0.9185412349809, 0.8637735585556); //Q1
   glVertex2f(0.9316038656871, 0.8737627140618); //M4
   glVertex2f(0.9327815383071, 0.8753293221571); //N4
   glVertex2f(0.9326295291775, 0.876697404323); //O4
   glVertex2f(0.9317681441101, 0.8779134773593); //P4
   glVertex2f(0.9295893465868, 0.8786228532971); //Q4
   glVertex2f(0.9274612187732, 0.8788255321365); //R4
   glVertex2f(0.9032410974668, 0.8799402657531); //S4
   glVertex2f(0.9012649787828, 0.8798895960433); //T4
   glVertex2f(0.89888350242, 0.8792815595251); //U4
   glVertex2f(0.8972114019951, 0.8785215138774); //V4
   glVertex2f(0.8945864156456, 0.8772187040285); //W4
   glVertex2f(0.8358019188841, 0.8504269629171); //S1
   glEnd();

   // Plane main body
   glBegin(GL_POLYGON);
   glColor3ub(240, 236, 236);
   glVertex2f(0.4931696166869, 0.8256810958153); //C1
   glVertex2f(0.4947744567499, 0.820619677155); // E1
   glVertex2f(0.4977372384047, 0.8171630985578); // F1
   glVertex2f(0.5126745959143, 0.8092623474784); //G1
   glVertex2f(0.527858851895, 0.8038305811112); //H1
   glVertex2f(0.55, 0.8); //I1
   glVertex2f(0.5971435291571, 0.7983374458889); //J1
   glVertex2f(0.7644941758939, 0.8085828922877); //K1
   glVertex2f(0.8358819419587, 0.8170986991965); //L1
   glVertex2f(0.8591212368993, 0.8224616134136); //M1
   glVertex2f(0.8661934067416, 0.8259745934379); //N1
   glVertex2f(0.8833627795043, 0.8355468986065); //O1
   glVertex2f(0.88381860356, 0.8404090218668); //P1
   glVertex2f(0.9185412349809, 0.8637735585556); //Q1
   glVertex2f(0.8538685824715, 0.8475664078491); //R1
   glVertex2f(0.8358019188841, 0.8504269629171); //S1
   glVertex2f(0.8177623187589, 0.8536990486945); //Z1
   glVertex2f(0.797120476474, 0.8558949893631); //A2
   glVertex2f(0.7729651291195, 0.8576517418979); //B2
   glVertex2f(0.7349753555527, 0.8611652469677); //C2
   glVertex2f(0.6912761362476, 0.8651179401712); //D2
   glVertex2f(0.6794180566372, 0.8655571283049); //E2
   glVertex2f(0.6278982128812, 0.8688360012186); //F2
   glVertex2f(0.5944919131105, 0.8701291483064); //G2
   glVertex2f(0.580698344173, 0.8701291483064); //H2
   glVertex2f(0.5725084126163, 0.8696980992771); //I2
   glVertex2f(0.5658271526621, 0.8684049521893); //J2
   glVertex2f(0.5578527456201, 0.8660341825281); //K2
   glVertex2f(0.5459988973144, 0.8595684470886); //L2
   glVertex2f(0.536382263609, 0.8527512670952); //M2
   glVertex2f(0.5285262147454, 0.8486449317491); //N2
   glVertex2f(0.519198416877, 0.8452430289971); //O2
   glVertex2f(0.5109680069931, 0.8417313874466);//P2
   glVertex2f(0.5048226342798, 0.8383294846946); //Q2
   glVertex2f(0.5024083807139, 0.8364639251209); //R2
   glVertex2f(0.4995551719542, 0.8342691491519); //S2
   glVertex2f(0.4970311795898, 0.8321841119813); //Z2
   glVertex2f(0.4950558812176, 0.8300990748107); //A3
   glVertex2f(0.4931696166869, 0.8256810958153); //C3
   glEnd();

   // Plane pilot window
   glBegin(GL_POLYGON);
   glColor3ub(32, 32, 32);
   glVertex2f(0.5459988973144, 0.8595684470886); //L2
   glVertex2f(0.5484435225582, 0.8581125963309); //B3
   glVertex2f(0.5508898829972, 0.8570181719239); //C3
   glVertex2f(0.5528212201859, 0.8565031486736); //D3
   glVertex2f(0.5552896323442, 0.8563174078103); //E3
   glVertex2f(0.5579070747829, 0.8564387707673); //F3
   glVertex2f(0.5613834817226, 0.8565675265799); //G3
   glVertex2f(0.5639585979742, 0.8565675265799); //H3
   glVertex2f(0.5653749119126, 0.8560525033296); //I3
   glVertex2f(0.5668556037572, 0.8550868347352); //J3
   glVertex2f(0.5677568944453, 0.853928032422); //K3
   glVertex2f(0.5678212723516, 0.8520610731396); //L3
   glVertex2f(0.5678212723516, 0.849936602232); //M3
   glVertex2f(0.5678212723516, 0.8484559103873); //N3
   glVertex2f(0.567241871195, 0.8470395964489); //O3
   glVertex2f(0.5658899351629, 0.8466533290112); //P3
   glVertex2f(0.5635723305364, 0.8465889511049); //Q3
   glVertex2f(0.5609107663931, 0.8466688996364); //R3
   glVertex2f(0.5575208073451, 0.8469108406363); //S3
   glVertex2f(0.5540189421813, 0.8474679729524); //T3
   glVertex2f(0.5505406472968, 0.8482241240142); //U3
   glVertex2f(0.5474782354964, 0.8489802750761); //V3
   glVertex2f(0.5445670539083, 0.8496986185848); //W3
   glVertex2f(0.542198865648, 0.8505160033886); //Z3
   glVertex2f(0.5399456389279, 0.8512885382641); //A4
   glVertex2f(0.5379499238329, 0.8521898289521); //B4
   glVertex2f(0.536382263609, 0.8527512670952); //M2
   glVertex2f(0.5459988973144, 0.8595684470886); //L2
   glEnd();

   //Place passenger window
   glColor3ub(32, 32, 32);
   DrawCircle(0.6136134880138, 0.8411480005225, 0.0035804757714, 2000); //C4
   DrawCircle(0.6355357881342, 0.8414408556768, 0.0035804757714, 2000); //D4
   DrawCircle(0.6571667992868, 0.8414456205529, 0.0035804757714, 2000); //E4
   DrawCircle(0.679067501284, 0.8416361909346, 0.0035804757714, 2000); //F4
   DrawCircle(0.7009679284309, 0.8415294616745, 0.0035804757714, 2000); //G4
   DrawCircle(0.72265947389, 0.8415294616745, 0.0035804757714, 2000); //H4
   DrawCircle(0.7445384675596, 0.8417593880138, 0.0035804757714, 2000); //J4
   DrawCircle(0.7665457011564, 0.8416987620259, 0.0035804757714, 2000); //I4
   DrawCircle(0.788, 0.842, 0.0035804757714, 2000); //K4

   //Plane back small wing
   glBegin(GL_POLYGON);
   glColor3ub(163, 0, 0);
   glVertex2f(0.8429190184152, 0.8388715830182); //Z4
   glVertex2f(0.8428187584983, 0.8357635255951); //A5
   glVertex2f(0.8699891959712, 0.8237323355702); //B5
   glVertex2f(0.9002676908672, 0.823130776069); //C5
   glVertex2f(0.9014766912113, 0.8234275134586); //d5
   glVertex2f(0.9025034098246, 0.8241001911708); //e5
   glVertex2f(0.9028574507257, 0.8250915056939); //f5
   glVertex2f(0.9027512384554, 0.8259766079467); //g5
   glVertex2f(0.9022555811938, 0.8267554979292); //h5
   glVertex2f(0.9014016655598, 0.82762094261); //I5
   glVertex2f(0.9004809145604, 0.8284665302625); //J5
   glVertex2f(0.8996710826156, 0.8291275719667); //K5
   glVertex2f(0.8989024842758, 0.8297443071596); //L5
   glVertex2f(0.8980568966233, 0.8302704505878); //M5
   glVertex2f(0.8970572291451, 0.8307109601084); //N5
   glVertex2f(0.8955020011973, 0.8313589717533); //O5
   glVertex2f(0.8768693126856, 0.838674312793); //P5
   glVertex2f(0.8429190184152, 0.8388715830182); //Z4
   glEnd();

   //Plane big wing
   glBegin(GL_POLYGON);
   glColor3ub(163, 0, 0);
   glVertex2f(0.6124736329244, 0.8227595947783); //Q5
   glVertex2f(0.6110676761079, 0.8217051271659); //R5
   glVertex2f(0.61, 0.82); //S5
   glVertex2f(0.6098726128138, 0.8185417243287); //T5
   glVertex2f(0.6103646976996, 0.8170654696713); //U5
   glVertex2f(0.6117003566753, 0.815589215014); //V5
   glVertex2f(0.6131766113327, 0.8140426625158); //W5
   glVertex2f(0.6658787763452, 0.7722024281381); //Z5
   glVertex2f(0.6669672079811, 0.7714181657979); //A6
   glVertex2f(0.6681233765325, 0.770809656034); //B6
   glVertex2f(0.6694316725249, 0.7702924227346); //C6
   glVertex2f(0.6710137979111, 0.7698664658999); //D6
   glVertex2f(0.672078689998, 0.7697447639471); //E6
   glVertex2f(0.673630389896, 0.7695926365061); //F6
   glVertex2f(0.7135351189402, 0.7714776243854); //G6
   glVertex2f(0.7148593214257, 0.7717972594681); //H6
   glVertex2f(0.7161378617566, 0.7722995431695); //I6
   glVertex2f(0.7173707399328, 0.7729844754896); //J6
   glVertex2f(0.7184209694903, 0.7738977185831); //K6
   glVertex2f(0.7191843707172, 0.7750120793597); //L6
   glVertex2f(0.7352872015836, 0.8240134714226); //M6
   glVertex2f(0.6812536153452, 0.8255889907556); //S6
   glVertex2f(0.662131400258, 0.8259186841192); //R6
   glVertex2f(0.6524054460326, 0.826083530801); //Q6
   glVertex2f(0.647460045579, 0.826083530801); //P6
   glVertex2f(0.6433388785344, 0.8259186841192); //O6
   glVertex2f(0.6283378304918, 0.8245999106649); //N6
   glVertex2f(0.6124736329244, 0.8227595947783); //Q5
   glEnd();

   glPopMatrix();
   // Plane code ends here

   glFlush();
}
// ============= Handle Mouse Press Functions ================

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			boatSpeed += 0.04f;
			printf(">>> Notification: Boat speed increased (+0.04)!\n");
		}
	}
    if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			boatSpeed -= 0.04f;
			printf(">>> Notification: Boat speed decreased (-0.04)!\n");
		}
	}
	glutPostRedisplay();
}

// ============== Handle Keyboard Press Functions ==============

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {

	case 'w':
	    // Increase train speed
        trainSpeed = +0.1f;
        printf(">>> Notification: Train speed increased (+0.03)!\n");
        break;

    case 'a':
        trainSpeed = 0.0f;
        printf(">>> Notification: Train stopped!\n");
        break;

    case 'd':
        trainSpeed = 0.02f;
        printf(">>> Notification: Train started / speed reset!\n");
        break;

    case 'm':
        glLoadIdentity();
        glutDisplayFunc(sunset);
        glutPostRedisplay();
        printf(">>> Notification: Showing sunset view!\n");
        bird();
        break;

    case 'b':
        glLoadIdentity();
        glutDisplayFunc(summerSeason);
        glutPostRedisplay();
        printf(">>> Notification: Showing morning / summer view!\n");
        break;

    case 'n':
        glLoadIdentity();
        glutDisplayFunc(night);
        glutPostRedisplay();
        printf(">>> Notification: Showing night view!\n");
        break;

    case 'h':
        boatHonkSound();
        printf(">>> Notification: Playing boat honk sound!\n");
        break;

    case 27:
        exit(0);
        break;

    glutPostRedisplay();
	}
}


int main(int argc, char** argv) {
    printf("       ************* COMPUTER GRAPHICS PROJECT *************       ");
    printf("\n            *************INSTRUCTIONS*************             \n");
    printf("           ************* Train operations *************          \n");
    printf("Increase Speed: W \n");
    printf("Stop train: A \n");
    printf("Start train: D \n");
    printf("\n");
    printf("           ************** Boat operations *************          \n");
    printf("Increase Speed and For Going Forward: Mouse Left Button \n");
    printf("Decrease Speed and For Going Backward: Mouse Right Button \n");
    printf("After Stopping Train, Start Train Backward: Mouse Right Button \n");
    printf("Honk Boat: H \n");
    printf("\n");
    printf("           **************** Scene Change **************          \n");
    printf("Switch to Morning view: B \n");
    printf("Switch to Sunset view: M \n");
    printf("Switch to Night view: N \n");
    printf("\n");
    printf("Exit Program: Esc \n");
    printf("\n");
    printf("Github Link: https://github.com/IftekharMaheen/NaturalMountainScenario\n");
    printf("\n");

   glutInit(&argc, argv);
   glutInitWindowSize(980, 700);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Natural Scenario");
   glutDisplayFunc(night);
   init();
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutTimerFunc(25, cloud1Update, 0);
   glutTimerFunc(25, cloud2Update, 0);
   glutTimerFunc(25, cloud3Update, 0);
   glutTimerFunc(25, rightWaveUpdate1, 0);
   glutTimerFunc(25, rightWaveUpdate2, 0);
   glutTimerFunc(25, boatUpdate, 0);
   glutTimerFunc(25, trainUpdate, 0);
   glutTimerFunc(25, planeUpdate, 0);
   glutTimerFunc(25, birdUpdate, 0);
   glutMainLoop();
   return 0;
}
