/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <windows.h>
#include <glut.h>
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef vector<ll>vl;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;

#define forab(i, a, b)        for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)                forab (i, 0, (n) - 1)
#define For(i, n)                forab (i, 1, n)
#define rofba(i, a, b)        for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)                rofba (i, 0, (n) - 1)
#define rof(i, n)                rofba (i, 1, n)
#define forstl(i, s)        for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)


enum {BLACK=0,RED,GREEN,BLUE,YELLOW,PURPLE,CYAN,WHITE};
void getColor(int s)  {
    if( s == BLACK )        glColor3f(0,0,0);
    else if( s == BLUE )    glColor3f(0,0,1);
    else if( s == GREEN )   glColor3f(0,1,0);
    else if( s == CYAN )    glColor3f(0,1,1);
    else if( s == RED )     glColor3f(1,0,0);
    else if( s == PURPLE )  glColor3f(1,0,1);
    else if( s == YELLOW )  glColor3f(1,1,0);
    else if( s == WHITE )   glColor3f(1,1,1);
}

int ang = 0;

void ROTATE(){
    glRotatef(ang, 1.0, 0.0, 0.0);
}

/**
    innerRadius :: Inner radius of the torus.
    outerRadius :: Outer radius of the torus.
    nsides      :: Number of sides for each radial section.
    rings       :: Number of radial divisions for the torus.
**/

void UpperTorus(){
    glutSolidTorus(0.04, 0.25, 7, 45);
}
void LowerTorus(){
    glutSolidTorus(0.04, 0.2, 7, 45);
}

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // just keep
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    getColor(BLUE);
	glPushMatrix();
        glTranslatef(-.5,0.2,-5);
        glPushMatrix();
            ROTATE();
            UpperTorus();;
        glPopMatrix();
	glPopMatrix();


    getColor(BLACK);
    glPushMatrix();
        glTranslatef(.15,0.2,-5);
        ROTATE();
        UpperTorus();;
	glPopMatrix();

	getColor(RED);
	glPushMatrix();
        glTranslatef(.80,0.2,-5);
		ROTATE();
        UpperTorus();;
    glPopMatrix();

// Down Begins

	glPushMatrix();
        glTranslatef(-.15,0,-4);
        getColor(YELLOW);
        glPushMatrix();
            ROTATE();
            LowerTorus();
		glPopMatrix();
	glPopMatrix();


	getColor(GREEN);
	glPushMatrix();
        glTranslatef(0.38,0,-4);
        ROTATE();
        LowerTorus();
    glPopMatrix();

	glFlush();
	glutSwapBuffers(); // just keep
}


void update(int val = 0 ) {
	ang = ( ang + 10 )% 360 ;
	glutPostRedisplay();
	glutTimerFunc(100,update,0);
}

void lightSetting()
{
	double zpos = 0.0;
	GLfloat ambientIntensity[4] = {0.2, 0.1, 0.2, 1.0}; // 6. ambient property
	GLfloat diffuseIntensity[4] = {0.3, 0.9, 0.0, 1.0}; // 8. ambient property
	GLfloat position[4] = {0.0, 1.0, zpos, 0.0}; // 10. position property

	glEnable(GL_DEPTH_TEST); // 4. just keep
	glEnable(GL_COLOR_MATERIAL); // 3. Materals' color

	glEnable(GL_LIGHTING); // 1. enable lighting
	glEnable(GL_LIGHT0); // 2. enable light 0
	glEnable(GL_NORMALIZE);

	// set up light 0 properties
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientIntensity); // 7. ambient property adding to Light0
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseIntensity); // 9. ambient property adding to Light0
	glLightfv(GL_LIGHT0, GL_POSITION, position); // 11. position property adding to Light0
}

void Initialize() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0, 1.00, 1.0, 200.0);
}

int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 300);
	glutCreateWindow("Olimpic Ring");
	Initialize();
	lightSetting();
	glutDisplayFunc(Draw);
	update();
	glutMainLoop();
	return 0;
}
