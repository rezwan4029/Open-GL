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
void __getColor(int s)  {
    if( s == BLACK )        glColor3f(0,0,0);
    else if( s == BLUE )    glColor3f(0,0,1);
    else if( s == GREEN )   glColor3f(0,1,0);
    else if( s == CYAN )    glColor3f(0,1,1);
    else if( s == RED )     glColor3f(1,0,0);
    else if( s == PURPLE )  glColor3f(1,0,1);
    else if( s == YELLOW )  glColor3f(1,1,0);
    else if( s == WHITE )   glColor3f(1,1,1);
}
struct point{
    double x , y ;
    point(double _x , double _y){
        x = _x , y = _y ;
    }
    point(){}
};
point a , b , c , d , Mid = point(0.5,0.5);

void update(double scale) {
    a.x = Mid.x + scale , a.y = Mid.y + scale ;
    b.x = Mid.x - scale , b.y = Mid.y + scale ;
    c.x = Mid.x - scale , c.y = Mid.y - scale ;
    d.x = Mid.x + scale , d.y = Mid.y - scale ;
}
void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    update(.3);

    __getColor(GREEN);
    glBegin(GL_QUADS);

    glVertex3f(a.x,a.y, 0.0);
    glVertex3f(b.x,b.y, 0.0);
    glVertex3f(c.x,c.y, 0.0);
    glVertex3f(d.x,d.y, 0.0);

    glEnd();
    glFlush();

    update(.1);

    __getColor(CYAN);
    glBegin(GL_QUADS);

    glVertex3f(a.x,a.y, 0.0);
    glVertex3f(b.x,b.y, 0.0);
    glVertex3f(c.x,c.y, 0.0);
    glVertex3f(d.x,d.y, 0.0);

    glEnd();
    glFlush();

    __getColor(RED);
    glPointSize(7);
    glBegin(GL_POINTS);
    glVertex3f(Mid.x,Mid.y,0.0);
    glEnd();
    glFlush();
}

void Initialize() {
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv) {
    glutInit(&iArgc, cppArgv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 350);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Assignment #2");
    Initialize();
    glutDisplayFunc(Draw);
    glutMainLoop();
}
