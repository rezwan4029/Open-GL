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


GLfloat A[3] = { 0.75, 0.75, 0.75};
GLfloat B[3] = {-0.75, 0.75, 0.75};
GLfloat C[3] = {-0.75,-0.75, 0.75};
GLfloat D[3] = { 0.75,-0.75, 0.75};
GLfloat E[3] = { 0.75, 0.75,-0.75};
GLfloat F[3] = {-0.75, 0.75,-0.75};
GLfloat G[3] = {-0.75,-0.75,-0.75};
GLfloat H[3] = { 0.75,-0.75,-0.75};

void drawCube()
{
  glBegin(GL_QUADS);
  /* front => ABCD */
  getColor(RED);

  glVertex3fv(A);
  glVertex3fv(B);
  glVertex3fv(C);
  glVertex3fv(D);

  /* back => FEHG */
  getColor(GREEN);

  glVertex3fv(F);
  glVertex3fv(E);
  glVertex3fv(H);
  glVertex3fv(G);

  /* right => EADH green */
  getColor(PURPLE);

  glVertex3fv(E);
  glVertex3fv(A);
  glVertex3fv(D);
  glVertex3fv(H);

  /* left => BFGC */
  getColor(BLUE);

  glVertex3fv(B);
  glVertex3fv(F);
  glVertex3fv(G);
  glVertex3fv(C);

  /* top => EFBA */
  getColor(YELLOW);

  glVertex3fv(E);
  glVertex3fv(F);
  glVertex3fv(B);
  glVertex3fv(A);

  /* bottom => DCGH */
  getColor(CYAN);

  glVertex3fv(D);
  glVertex3fv(C);
  glVertex3fv(G);
  glVertex3fv(H);
  glEnd();
}

int ang1 , ang2 ;

void Draw() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glEnable(GL_DEPTH_TEST);
  getColor(RED);
  glPushMatrix();
     glTranslated(0,0.2,-4);
     glRotatef(ang2,1,0,0);
    glRotatef(ang1,0,1,0);
    drawCube();
  glPopMatrix();
  glFlush();
  glutSwapBuffers(); // just keep
}


void windowKey(unsigned char key,int x,int y) {
  if (key == 'd' ) ang1 += 10; // right
  else if (key == 'a') ang1 -= 10; // left
  else if (key == 'w') ang2 += 10; // up
  else if (key == 's') ang2 -= 10; // down
  ang1 = ( ang1 + 360 ) % 360 ;
  ang2 = ( ang2 + 360 ) % 360 ;
  glutPostRedisplay();
}

void resize(int width, int height)
{
    const double ar = (double) width / (double) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

void Initialize() {
	glClearColor(1, 1, 1, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, 0.0, 1.0);
}
int main(int argc,char* argv[]) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(30, 30);
  glutCreateWindow("3-D Cube");
  Initialize();
  glutReshapeFunc(resize);
  glutDisplayFunc(Draw);
  glutKeyboardFunc(windowKey);
  glutMainLoop();
  return 0;
}
