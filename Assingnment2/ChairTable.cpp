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

void drawTable() {
    glPushMatrix();
    glTranslatef(0, 0, 0);
    getColor(RED);
    glBegin(GL_QUADS);
    glVertex3f(-8.0, 0, 0);
    glVertex3f(-4.0, 0, 0);
    glVertex3f(-3.0, 2.0, 0);
    glVertex3f(-7.0, 2.0, 0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-8.0, 0, 0);
    glVertex3f(-4.0, 0, 0);
    glVertex3f(-4.0, -0.3, 0);
    glVertex3f(-8.0, -0.3, 0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-4.0, 0, 0);
    glVertex3f(-3.0, 2.0, 0);
    glVertex3f(-3.0, 1.7, 0);
    glVertex3f(-4.0, -0.3, 0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-7.8, 0, 0);
    glVertex3f(-7.6, 0, 0);
    glVertex3f(-7.6, -3.0, 0);
    glVertex3f(-7.8, -3.0, 0);
    glEnd();

    glTranslatef(3.4, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(-7.8, 0, 0);
    glVertex3f(-7.6, 0, 0);
    glVertex3f(-7.6, -3.0, 0);
    glVertex3f(-7.8, -3.0, 0);
    glEnd();

    glTranslatef(1.1, 2.0, 0);
    glBegin(GL_QUADS);
    glVertex3f(-7.8, 0, 0);
    glVertex3f(-7.6, 0, 0);
    glVertex3f(-7.6, -3.0, 0);
    glVertex3f(-7.8, -3.0, 0);
    glEnd();

    glTranslatef(-3.5, -0.8, 0);
    glBegin(GL_QUADS);
    glVertex3f(-7.8, 0, 0);
    glVertex3f(-7.6, 0, 0);
    glVertex3f(-7.6, -3.0, 0);
    glVertex3f(-7.8, -3.0, 0);
    glEnd();

    glPopMatrix();
}
int angle = 0;
void drawChair() {
    glPushMatrix();
    glRotatef(angle, 0, 1.0, 0);
    getColor(YELLOW);
    glBegin(GL_QUADS);
    glNormal3f(0, 0, 1.0);
    glVertex3f(-1.0, -0.15, 1.2);
    glVertex3f(1.0, -0.15, 1.2);
    glVertex3f(1.0, 0.15, 1.2);
    glVertex3f(-1.0, 0.15, 1.2);

    glNormal3f(1.0, 0, 0);
    glVertex3f(1.0, -0.15, 1.2);
    glVertex3f(1.0, -0.15, -1.16);
    glVertex3f(1.0, 0.15, -1.16);
    glVertex3f(1.0, 0.15, 1.2);

    glNormal3f(0, 0, -1.0);
    glVertex3f(-1.0, -0.15, -1.16);
    glVertex3f(1.0, -0.15, -1.16);
    glVertex3f(1.0, 0.15, -1.16);
    glVertex3f(-1.0, 0.15, -1.16);

    glNormal3f(-1.0, 0, 0);
    glVertex3f(-1.0, -0.15, 1.2);
    glVertex3f(-1.0, -0.15, -1.16);
    glVertex3f(-1.0, 0.15, -1.16);
    glVertex3f(-1.0, 0.15, 1.2);

    glNormal3f(0, 1.0, 0);
    glVertex3f(-1.0, 0.15, 1.2);
    glVertex3f(1.0, 0.15, 1.2);
    glVertex3f(1.0, 0.15, -1.16);
    glVertex3f(-1.0, 0.15, -1.16);

    //base
    glNormal3f(0, 0, 1.0);
    glVertex3f(-1.0, .15, -1.0);
    glVertex3f(1.0, .15,  -1.0);
    glVertex3f(1.0, 2.0,  -1.0);
    glVertex3f(-1.0, 2.0, -1.0);

    glNormal3f(1.0, 0, 0);
    glVertex3f(1.0, 0.15, -1.0);
    glVertex3f(1.0, 0.15, -1.16);
    glVertex3f(1.0, 2.0, -1.16);
    glVertex3f(1.0, 2.0, -1.0);

    glNormal3f(0, 0, -1.0);
    glVertex3f(-1.0, 0.15, -1.16);
    glVertex3f(1.0, 0.15, -1.16);
    glVertex3f(1.0, 2.0, -1.16);
    glVertex3f(-1.0, 2.0, -1.16);

    glNormal3f(-1.0, 0, 0);
    glVertex3f(-1.0, 0.15, -1.0);
    glVertex3f(-1.0, 0.15, -1.16);
    glVertex3f(-1.0, 2.0, -1.16);
    glVertex3f(-1.0, 2.0, -1.0);

    //front-left leg
    glNormal3f(0, 0, 1.0);
    glVertex3f(-1.0, -2.0, 1.2);
    glVertex3f(-0.8, -2.0, 1.2);
    glVertex3f(-0.8, -0.15, 1.2);
    glVertex3f(-1.0, -0.15, 1.2);

    glNormal3f(1.0, 0, 0);
    glVertex3f(-0.8, -2.0, 1.2);
    glVertex3f(-0.8, -2.0, 1.0);
    glVertex3f(-0.8, -0.15, 1.0);
    glVertex3f(-0.8, -0.15, 1.2);

    glNormal3f(0, 0, -1.0);
    glVertex3f(-1.0, -2.0, 1.0);
    glVertex3f(-0.8, -2.0, 1.0);
    glVertex3f(-0.8, -0.15, 1.0);
    glVertex3f(-1.0, -0.15, 1.0);

    glNormal3f(-1.0, 0, 0);
    glVertex3f(-1.0, -2.0, 1.2);
    glVertex3f(-1.0, -2.0, 1.0);
    glVertex3f(-1.0, -0.15, 1.0);
    glVertex3f(-1.0, -0.15, 1.2);

    //front-right leg
    glNormal3f(0, 0, 1.0);
    glVertex3f(0.8, -2.0, 1.2);
    glVertex3f(1.0, -2.0, 1.2);
    glVertex3f(1.0, -0.15, 1.2);
    glVertex3f(0.8, -0.15, 1.2);

    glNormal3f(1.0, 0, 0);
    glVertex3f(1.0, -2.0, 1.2);
    glVertex3f(1.0, -2.0, 1.0);
    glVertex3f(1.0, -0.15, 1.0);
    glVertex3f(1.0, -0.15, 1.2);

    glNormal3f(0, 0, -1.0);
    glVertex3f(0.8, -2.0, 1.0);
    glVertex3f(1.0, -2.0, 1.0);
    glVertex3f(1.0, -0.15, 1.0);
    glVertex3f(0.8, -0.15, 1.0);

    glNormal3f(-1.0, 0, 0);
    glVertex3f(0.8, -2.0, 1.2);
    glVertex3f(0.8, -2.0, 1.0);
    glVertex3f(0.8, -0.15, 1.0);
    glVertex3f(0.8, -0.15, 1.2);

    //back-left leg
    glNormal3f(0, 0, 1.0);
    glVertex3f(-1.0, -2.0, -1.0);
    glVertex3f(-0.8, -2.0, -1.0);
    glVertex3f(-0.8, -0.15, -1.0);
    glVertex3f(-1.0, -0.15, -1.0);

    glNormal3f(1.0, 0, 0);
    glVertex3f(-0.8, -2.0, -1.0);
    glVertex3f(-0.8, -2.0, -1.16);
    glVertex3f(-0.8, -0.15, -1.16);
    glVertex3f(-0.8, -0.15, -1.0);

    glNormal3f(0, 0, -1.0);
    glVertex3f(-1.0, -2.0, -1.16);
    glVertex3f(-0.8, -2.0, -1.16);
    glVertex3f(-0.8, -0.15, -1.16);
    glVertex3f(-1.0, -0.15, -1.16);

    glNormal3f(-1.0, 0, 0);
    glVertex3f(-1.0, -2.0, -1.0);
    glVertex3f(-1.0, -2.0, -1.16);
    glVertex3f(-1.0, -0.15, -1.16);
    glVertex3f(-1.0, -0.15, -1.0);

    //back-right leg
    glNormal3f(0, 0, 1.0);
    glVertex3f(0.8, -2.0, -1.0);
    glVertex3f(1.0, -2.0, -1.0);
    glVertex3f(1.0, -0.15, -1.0);
    glVertex3f(0.8, -0.15, -1.0);

    glNormal3f(1.0, 0, 0);
    glVertex3f(1.0, -2.0, -1.0);
    glVertex3f(1.0, -2.0, -1.16);
    glVertex3f(1.0, -0.15, -1.16);
    glVertex3f(1.0, -0.15, -1.0);

    glNormal3f(0, 0, -1.0);
    glVertex3f(0.8, -2.0, -1.16);
    glVertex3f(1.0, -2.0, -1.16);
    glVertex3f(1.0, -0.15, -1.16);
    glVertex3f(0.8, -0.15, -1.16);

    glNormal3f(-1.0, 0, 0);
    glVertex3f(0.8, -2.0, -1.0);
    glVertex3f(0.8, -2.0, -1.16);
    glVertex3f(0.8, -0.15, -1.16);
    glVertex3f(0.8, -0.15, -1.0);

    glEnd();
    glPopMatrix();
}
void draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(3.3, 0, -13);
    drawChair();
    drawTable();
    glutSwapBuffers();
}
void update(int v = 0) {
    angle += 2;
    angle %= 360 ;
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}
void lightSetting() {
    double zpos = 0;
    GLfloat ambientIntensity[4] = {0.2, 0.1, 0.2, 1.0}; // 6. ambient property
    GLfloat diffuseIntensity[4] = {0.3, 0.9, 0, 1.0}; // 8. ambient property
    GLfloat position[4] = {0, 1.0, zpos, 0}; // 10. position property

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
    gluPerspective(45.0, 1.00, 1.0, 200);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Chair - Table");
    Initialize();
    lightSetting();
    glutDisplayFunc(draw);
    update();
    glutMainLoop();
    return 0;
}
