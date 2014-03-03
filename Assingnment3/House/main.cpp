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

#ifndef IMAGE_LOADER_H_INCLUDED
#define IMAGE_LOADER_H_INCLUDED

//Represents an image
class Image {
	public:
		Image(char* ps, int w, int h);
		~Image();

		/* An array of the form (R1, G1, B1, R2, G2, B2, ...) indicating the
		 * color of each pixel in image.  Color components range from 0 to 255.
		 * The array starts the bottom-left pixel, then moves right to the end
		 * of the row, then moves up to the next column, and so on.  This is the
		 * format in which OpenGL likes images.
		 */
		char* pixels;
		int width;
		int height;
};

//Reads a bitmap image from file.
Image* loadBMP(const char* filename);

#endif


Image::Image(char* ps, int w, int h) : pixels(ps), width(w), height(h) {

}

Image::~Image() {
	delete[] pixels;
}

namespace {
	//Converts a four-character array to an integer, using little-endian form
	int toInt(const char* bytes) {
		return (int)(((unsigned char)bytes[3] << 24) |
					 ((unsigned char)bytes[2] << 16) |
					 ((unsigned char)bytes[1] << 8) |
					 (unsigned char)bytes[0]);
	}

	//Converts a two-character array to a short, using little-endian form
	short toShort(const char* bytes) {
		return (short)(((unsigned char)bytes[1] << 8) |
					   (unsigned char)bytes[0]);
	}

	//Reads the next four bytes as an integer, using little-endian form
	int readInt(ifstream &input) {
		char buffer[4];
		input.read(buffer, 4);
		return toInt(buffer);
	}

	//Reads the next two bytes as a short, using little-endian form
	short readShort(ifstream &input) {
		char buffer[2];
		input.read(buffer, 2);
		return toShort(buffer);
	}

	//Just like auto_ptr, but for arrays
	template<class T>
	class auto_array {
		private:
			T* array;
			mutable bool isReleased;
		public:
			explicit auto_array(T* array_ = NULL) :
				array(array_), isReleased(false) {
			}

			auto_array(const auto_array<T> &aarray) {
				array = aarray.array;
				isReleased = aarray.isReleased;
				aarray.isReleased = true;
			}

			~auto_array() {
				if (!isReleased && array != NULL) {
					delete[] array;
				}
			}

			T* get() const {
				return array;
			}

			T &operator*() const {
				return *array;
			}

			void operator=(const auto_array<T> &aarray) {
				if (!isReleased && array != NULL) {
					delete[] array;
				}
				array = aarray.array;
				isReleased = aarray.isReleased;
				aarray.isReleased = true;
			}

			T* operator->() const {
				return array;
			}

			T* release() {
				isReleased = true;
				return array;
			}

			void reset(T* array_ = NULL) {
				if (!isReleased && array != NULL) {
					delete[] array;
				}
				array = array_;
			}

			T* operator+(int i) {
				return array + i;
			}

			T &operator[](int i) {
				return array[i];
			}
	};
}

Image* loadBMP(const char* filename) {
	ifstream input;
	input.open(filename, ifstream::binary);
	assert(!input.fail() || !"Could not find file");
	char buffer[2];
	input.read(buffer, 2);
	assert( (buffer[0] == 'B' ) && (buffer[1] == 'M') || (!"Not a bitmap file" ) );
	input.ignore(8);
	int dataOffset = readInt(input);

	//Read the header
	int headerSize = readInt(input);
	int width;
	int height;
	switch(headerSize) {
		case 40:
			//V3
			width = readInt(input);
			height = readInt(input);
			input.ignore(2);
			assert(readShort(input) == 24 || !"Image is not 24 bits per pixel");
			assert(readShort(input) == 0 || !"Image is compressed");
			break;
		case 12:
			//OS/2 V1
			width = readShort(input);
			height = readShort(input);
			input.ignore(2);
			assert(readShort(input) == 24 || !"Image is not 24 bits per pixel");
			break;
		case 64:
			//OS/2 V2
			assert(!"Can't load OS/2 V2 bitmaps");
			break;
		case 108:
			//Windows V4
			assert(!"Can't load Windows V4 bitmaps");
			break;
		case 124:
			//Windows V5
			assert(!"Can't load Windows V5 bitmaps");
			break;
		default:
			assert(!"Unknown bitmap format");
	}

	//Read the data
	int bytesPerRow = ((width * 3 + 3) / 4) * 4 - (width * 3 % 4);
	int size = bytesPerRow * height;
	auto_array<char> pixels(new char[size]);
	input.seekg(dataOffset, ios_base::beg);
	input.read(pixels.get(), size);

	//Get the data into the right format
	auto_array<char> pixels2(new char[width * height * 3]);
	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			for(int c = 0; c < 3; c++) {
				pixels2[3 * (width * y + x) + c] =
					pixels[bytesPerRow * y + 3 * x + (2 - c)];
			}
		}
	}

	input.close();
	return new Image(pixels2.release(), width, height);
}

GLuint _textureId;
GLuint _textureId1;
GLuint _textureId2;
GLuint _textureId3;
GLuint _textureId4;


void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();//Grass

	glTranslatef(0,0,-5);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glColor3f(1,1,1);
	glBegin(GL_QUADS);

	glTexCoord2f(0,0);
	glVertex2f(-2.5,-2);

	glTexCoord2f(0,5);
	glVertex2f(-2.5, 0.0);

	glTexCoord2f(5,5);
	glVertex2f(2.5,0);

	glTexCoord2f(5,0);
	glVertex2f(2.5, -2);

	glEnd();

	glPopMatrix();

	glPushMatrix();// Front Side of House behind dooor

	glBindTexture(GL_TEXTURE_2D, _textureId1);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTranslatef(0,0,-4.9);

	glBegin(GL_QUADS);

	glTexCoord2f(0,0);
	glVertex2f(-.1,-.7);

	glTexCoord2f(0,2);
	glVertex2f(-.1,.5);

	glTexCoord2f(2,2);
	glVertex2f(.9,.5);

	glTexCoord2f(2,0);
	glVertex2f(.8,-.6);

	glEnd();


	glPopMatrix();

	glPushMatrix();// Left Side House Shade

	glBindTexture(GL_TEXTURE_2D, _textureId1);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTranslatef(0,0,-4.9);

	glBegin(GL_QUADS);

	glTexCoord2f(0,0);
	glVertex2f(-0.1, -0.7);

	glTexCoord2f(0,2);
	glVertex2f(-0.1, 0.5);

	glTexCoord2f(2,2);
	glVertex2f(-1.9, 0.7);

	glTexCoord2f(2,0);
	glVertex2f(-1.9, -0.4);

	glEnd();


	glPopMatrix();

	glPushMatrix();//  Front side roof

	glBindTexture(GL_TEXTURE_2D, _textureId1);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTranslatef(0,0,-4.9);

	glBegin(GL_TRIANGLES);


	glTexCoord2f(0,0);
	glVertex2f(-0.1,0.5);

	glTexCoord2f(0,2);
	glVertex2f(0.9, 0.5);

	glTexCoord2f(2,2);
	glVertex2f(0.4,1.0);



	glEnd();


	glPopMatrix();

	glPushMatrix();//Upper Left Side Roof

	glBindTexture(GL_TEXTURE_2D, _textureId2);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTranslatef(0,0,-4.8);

	glBegin(GL_QUADS);

	glTexCoord2f(0,0);
	glVertex2f(-2.0,0.4);

	glTexCoord2f(0,2);
	glVertex2f(-1.7, 1.2);

	glTexCoord2f(2,2);
	glVertex2f(0.5, 1.2);

	glTexCoord2f(2,0);
	glVertex2f(0.1,0.3);

	glEnd();


	glPopMatrix();

	glPushMatrix();// Upper Back Side of Roof

	glBindTexture(GL_TEXTURE_2D, _textureId2);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTranslatef(0,0,-4.9);

	glBegin(GL_QUADS);

	glTexCoord2f(0,0);
	glVertex2f(-1.6,0.2);

	glTexCoord2f(0,2);
	glVertex2f(-1.7,1.2);

	glTexCoord2f(2,2);
	glVertex2f(0.5, 1.2);

	glTexCoord2f(2,0);
	glVertex2f(1.2,0.4);

	glEnd();


	glPopMatrix();





	glPushMatrix();//Right Window

	glBindTexture(GL_TEXTURE_2D, _textureId3);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTranslatef(0,0,-4.8);

	glBegin(GL_QUADS);

	glTexCoord2f(0,0);
	glVertex2f(-1.2, -0.3);

	glTexCoord2f(0,1);
	glVertex2f(-1.2, 0.2);

	glTexCoord2f(1,1);
	glVertex2f(-0.7,0.2);

	glTexCoord2f(1.0,0);
	glVertex2f(-0.7, -0.3);

	glEnd();


	glPopMatrix();


	glPushMatrix();//Door

	glBindTexture(GL_TEXTURE_2D, _textureId4);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTranslatef(0,0,-4.8);

	glBegin(GL_QUADS);

    glTexCoord2f(0,0);
	glVertex2f(0.2,-0.57);

	glTexCoord2f(0,1);
	glVertex2f(0.2, 0.4);

	glTexCoord2f(1, 1);
	glVertex2f(0.7, 0.4);

	glTexCoord2f(1,0);
	glVertex2f(0.7, -0.57);

	glEnd();


	glPopMatrix();


	glutSwapBuffers();
}

GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
		0,                            //0 for now
		GL_RGB,                       //Format OpenGL uses for image
		image->width, image->height,  //Width and height
		0,                            //The border of the image
		GL_RGB, //GL_RGB, because pixels are stored in RGB format
		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
		//as unsigned numbers
		image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

void initialize() {

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0, 1.00, 1.0, 200.0);
       // E:\\Prev Desk\\Desktop\\Point\\A2\\prac\\grass.bmp
	Image* image = loadBMP("E:\\Prev Desk\\Desktop\\Point\\A2\\prac\\grass.bmp");
	Image* image1 = loadBMP("E:\\Prev Desk\\Desktop\\Point\\A2\\prac\\bricks.bmp");
	Image* image2 = loadBMP("E:\\Prev Desk\\Desktop\\Point\\A2\\prac\\roof.bmp");
	Image* image3 = loadBMP("E:\\Prev Desk\\Desktop\\Point\\A2\\prac\\window.bmp");
	Image* image4 = loadBMP("E:\\Prev Desk\\Desktop\\Point\\A2\\prac\\door.bmp");

	_textureId = loadTexture(image);
	_textureId1 = loadTexture(image1);
	_textureId2 = loadTexture(image2);
	_textureId3 = loadTexture(image3);
	_textureId4 = loadTexture(image4);
	delete image;
}

void lightSetting()
{

	GLfloat ambientIntensity[4] = { 0.6, 0.6, 0.6, 1.0 };

	GLfloat position[4] = { 0.0, 1.0, 0.0, 0.0 };

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);


	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientIntensity);

	glLightfv(GL_LIGHT0, GL_POSITION, position);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);

	glutCreateWindow("House");
	initialize();
	lightSetting();
	glutDisplayFunc(drawScene);

	glutMainLoop();
	return 0;
}
