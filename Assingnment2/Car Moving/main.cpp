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

double angle1 , angle2 ;
int Iter = 50 ;
const double roadWidth = 1.5;

void drawQuad(int i){
    double theta = i * 2. * pi / Iter ;
    double x =  (roadWidth * cos(theta) );
    double y =  (roadWidth * sin(theta));
    if ( i & 1) {
        glVertex3f(x,y,0);
        glVertex3f(x,y,-.75);
    }
    else{
        glVertex3f(x,y,-.75);
        glVertex3f(x,y,0);
    }
}
void drawRoad(){
    glPushMatrix();
        glTranslatef(0.5,-0.5,-3);
        glRotatef(angle1, 1, 0, 0);
        glPushMatrix();
            glRotatef(90, 0, 1,0 );
            glPushMatrix();
                getColor(RED);
                glBegin(GL_QUADS);
                For(i,Iter) drawQuad(i);
                glEnd();
                getColor(WHITE);
                glBegin(GL_QUADS);
                forab(i,2,Iter+1) drawQuad(i);
                glEnd();
                glPopMatrix();
        glPopMatrix();
	glPopMatrix();
}
/**
    innerRadius :: Inner radius of the torus.
    outerRadius :: Outer radius of the torus.
    nsides      :: Number of sides for each radial section.
    rings       :: Number of radial divisions for the torus.
**/

struct Translate{
    double x , y , z ;
    Translate(double _x , double _y , double _z){
        x = _x , y =_y , z =_z ;
    }
    Translate(){}
};
void  drawTire(Translate p){
    glPushMatrix();
        getColor(WHITE);
        glPushMatrix();
        glTranslatef(p.x,p.y,p.z);
            glPushMatrix();
                glRotatef(angle2, 1.0, 0.0, 0.0);
                glPushMatrix();
                    glRotatef(90,0,1,0);
                    glPushMatrix();
                        glutSolidTorus(0.03,.1,10,8);
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
	glPopMatrix();
}
void drawBase(){
    glPushMatrix();
        glTranslatef(.7, 0, -1.2);
        glPushMatrix();
            getColor(YELLOW);
            glBegin(GL_QUADS);
            glVertex3f(-.53, .4,0); // b
            glVertex3f(-.72, .4,0); // a
            glVertex3f(-.69, -.18,0); // d
            glVertex3f(-.47, -.18,0); // c
        glEnd();
        glPopMatrix();
	glPopMatrix();
}
void drawUpBaseLine(){
	glPushMatrix();
        glTranslatef(.43, .07, -1.5);
        glPushMatrix();
            getColor(CYAN);
            glBegin(GL_QUADS);
            glVertex3f(-0.62, .32, 0);
            glVertex3f(-0.04, .32, 0);
            glVertex3f(-0.04, .34, 0);
            glVertex3f(-0.62, .34, 0);
            glEnd();
        glPopMatrix();
	glPopMatrix();
}
void drawDownBaseLine(){
    glPushMatrix();
        glTranslatef(.4, -.28, -1.2);
        glPushMatrix();
            getColor(CYAN);
            glBegin(GL_QUADS);
            glVertex3f(-0.58, .2, 0);
            glVertex3f(-0.022, .2, 0);
            glVertex3f(-0.022, .22, 0);
            glVertex3f(-0.58, .22, 0);
            glEnd();
        glPopMatrix();
	glPopMatrix();
}
void Draw(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawRoad();
    drawBase();
    drawDownBaseLine();
    drawUpBaseLine();
    drawTire( Translate(0.3, 0.4, -1.5) );
    drawTire( Translate(-.1, 0.4, -1.5) );
    drawTire( Translate(-.1, -0.08, -1.2) );
    drawTire( Translate(0.3, -0.08, -1.2) );
    glFlush();
}
void update(int val = 0) {
	angle1 += 0.08;
	if (angle1 > 360 ) angle1 = 0 ;
	angle2 -= 0.4;
	if (angle2 < 0 ) angle2 = 360;
	glutPostRedisplay();
	glutTimerFunc(1, update, 0);
}

void lightSetting() {
	double zpos = 0;
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
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(150, 150);
	glutCreateWindow("Thelagari Moving");
	Initialize();
	lightSetting();
	glutDisplayFunc(Draw);
	update();
	glutMainLoop();
	return 0;
}
