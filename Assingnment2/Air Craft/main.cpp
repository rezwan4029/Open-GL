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

struct PP{
    double x , y , z ;
    PP(double _x , double _y , double _z){
        x = _x ;
        y = _y ;
        z = _z ;
    }
    PP rotate(PP p,double angle) { // angle must be in radian
        PP v(x - p.x , y-p.y ,z);
        double c = cos(angle) , s = sin(angle);
        return PP(p.x + v.x*c - v.y*s , p.y + v.x*s + v.y*c ,0);
    }

    PP(){}
};

PP P[15];

const double Shift = 0.015;

void InitPosition() {
    P[1] = PP( .30 , .20 , 0 );
    P[2] = PP( .70 , .20 , 0 );
    P[3] = PP( .55 , .25 , 0 );
    P[4] = PP( .55 , .30 , 0 );
    P[5] = PP( .80 , .30 , 0 );
    P[6] = PP( .55 , .50 , 0 );
    P[7] = PP( .55 , .55 , 0 );
    P[8] = PP( .50 , .60 , 0 );
    P[9] = PP( .45 , .55 , 0 );
    P[10] = PP( .45 , .50 , 0 );
    P[11] = PP( .20 , .30 , 0 );
    P[12] = PP( .45 , .30 , 0 );
    P[13] = PP( .45 , .25 , 0 );
}
PP getMid(){
    double MxX = 0 , MxY = 0 ;
    double MnX = 10000 , MnY = 10000 ;
    For(i,13){
        MxX = max(MxX,P[i].x);
        MxY = max(MxY,P[i].y);
        MnX = min(MnX,P[i].x);
        MnY = min(MnY,P[i].y);
    }
    return PP( (MxX + MnX) /2.00 , (MnY + MxY) / 2.00 , 0 );
}
void goLeft(){
    PP MID = getMid();
    //cout << MID.x << "  " << MID.y << endl;
    For(i,13) P[i] = P[i].rotate(MID,pi/2.00);
}
void goRight(){
    PP MID = getMid();
    cout << MID.x << "  " << MID.y << endl;
    For(i,13) P[i] = P[i].rotate(MID,-pi/2.00);
}
void moveRight(){
    For(i,13) P[i].x += Shift;
}
void moveLeft(){
    For(i,13) P[i].x -= Shift;
}
void moveUp(){
    For(i,13) P[i].y += Shift;
}
void moveDown(){
    For(i,13) P[i].y -= Shift;
}

void drawAirCraft()
{
  	glBegin(GL_POLYGON);
        glVertex3f(P[9].x,P[9].y,P[9].z);
        glVertex3f(P[8].x,P[8].y,P[8].z);
        glVertex3f(P[7].x,P[7].y,P[7].z);
        glVertex3f(P[6].x,P[6].y,P[6].z);
        glVertex3f(P[10].x,P[10].y,P[10].z);
	glEnd();


	glBegin(GL_POLYGON);
        glVertex3f(P[10].x,P[10].y,P[10].z);
        glVertex3f(P[11].x,P[11].y,P[11].z);
        glVertex3f(P[12].x,P[12].y,P[12].z);
        glVertex3f(P[4].x,P[4].y,P[4].z);
        glVertex3f(P[5].x,P[5].y,P[5].z);
        glVertex3f(P[6].x,P[6].y,P[6].z);
	glEnd();

    glBegin(GL_QUADS);

        glVertex3f(P[3].x,P[3].y,P[3].z);
        glVertex3f(P[4].x,P[4].y,P[4].z);
        glVertex3f(P[12].x,P[12].y,P[12].z);
        glVertex3f(P[13].x,P[13].y,P[13].z);

        glVertex3f(P[1].x,P[1].y,P[1].z);
        glVertex3f(P[2].x,P[2].y,P[2].z);
        glVertex3f(P[3].x,P[3].y,P[3].z);
        glVertex3f(P[13].x,P[13].y,P[13].z);

	glEnd();
}

void Draw() {
  glClear(GL_COLOR_BUFFER_BIT);
  getColor(RED);
  glPushMatrix();
      glTranslated(-0.5,-.8,0);
     drawAirCraft();
  glPopMatrix();
  glFlush();
}

bool flag = true ;
int l = 0 , r = 0 , u = 1 , d = 0 ;
void windowKey(unsigned char key,int x,int y) {
  if (key == 'd' ) { // right button
     if(flag) {
        goRight();
        r = 1 , l = u = d = 0 ;
        flag = false;
     }
     else {
       if(u == 1 ) {
        r = 1 ; u = d = l = 0 ;
        goRight();
       }
       else if( d == 1 ){
        r = 1 , u = d = l = 0 ;
        goLeft();
       }
       else if( r == 1 ){
            moveRight();
       }
       else if(l == 1 ){
         r = 1 , l = u = d = 0 ;
         goRight(); goRight();
       }
     }
  }
  else if (key == 'a') { // left button
    if(flag) {
        goLeft();
        l  = 1 , r = u = d = 0 ;
        flag = false;
     }
     else {
       if(u == 1 ){
         goLeft();
         l = 1 ; r = d = u = 0;
       }
       else if( d == 1 ){
          goRight();
          l = 1 ; r = d = u = 0 ;
       }
       else if( r == 1){
            goLeft() ; goLeft();
            l = 1 , r = u = d = 0 ;
       }
       else if( l == 1 ){
            moveLeft();
       }
     }
  }
  else if (key == 'w') { // up button
    if(flag) {
        moveUp();
        u = 1 , l = r = d = 0 ;
        flag = false;
    }
    else {
       if( u == 1 ){
            moveUp();
       }
       else if( d == 1 ){
          goLeft(); goLeft();
          u = 1 , d = l = r = 0 ;
       }
       else if(l == 1){
            goRight();
            u = 1 , l = r = d = 0 ;
       }
       else if(r == 1 ){
            goLeft();
            u = 1 , l = r = d = 0 ;
       }
    }
  }
  else if (key == 's') { // down button
    if(flag) {
        goLeft(); goLeft();
        u = 1 , r = d = l = 0 ;
        flag = false;
    }
    else {
        if( u == 1){
             goLeft(); goLeft();
             d = 1 , r = u = l = 0 ;
        }
        else if( d == 1 ){
            moveDown();
        }
        else if( l == 1 ){
            goLeft();
            d = 1 , l = r = u = 0 ;
        }
        else if( r == 1 ){
            goRight();
            d = 1 , l = r = u = 0 ;
        }
    }
  }
  glutPostRedisplay();
}


void Initialize() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}
int main(int argc,char* argv[]) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Air - Craft");
  InitPosition();
  Initialize();
  glutDisplayFunc(Draw);
  glutKeyboardFunc(windowKey);
  glutMainLoop();
  return 0;
}
