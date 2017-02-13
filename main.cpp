#include <GL/glut.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <map>

#include "consoleinterface.h"

enum
{
    EXIT
};

std::map <char, float> BottomLeftColor;
std::map <char, float> TopLeftColor;
std::map <char, float> TopRightColor;
std::map <char, float> BottomRightColor;

char* string;

void DrawString( GLfloat x, GLfloat y, char * string )
{
    glRasterPos2f( x, y );

    int len = strlen( string );
    for( int i = 0; i < len; i++ )
         glutBitmapCharacter( GLUT_BITMAP_9_BY_15, string[ i ] );

}

void Display()
{
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glClear( GL_COLOR_BUFFER_BIT );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glShadeModel( GL_SMOOTH );


    glBegin( GL_POLYGON );

    // Left Bottom Vertex
    glVertex3f(1, -1, 0);
    glColor3f( BottomLeftColor['r'], BottomLeftColor['g'], BottomLeftColor['b'] );

    // Left Top Vertex
    glVertex3f(-1, -1, 0);
    glColor3f( TopLeftColor['r'], TopLeftColor['g'], TopLeftColor['b'] );

    // Right Top Vertex
    glVertex3f(-1, 1, 0);
    glColor3f( TopRightColor['r'], TopRightColor['g'], TopRightColor['b'] );

    // Right Bottom Vertex
    glVertex3f(1, 1, 0);
    glColor3f( BottomRightColor['r'], BottomRightColor['g'], BottomRightColor['b'] );

    glEnd();

    DrawString( 0, 0.01, string );

    glFlush();
    glutSwapBuffers();
}

void Menu( int value )
{
    switch( value )
    {
    case EXIT:
        exit( 0 );
    }
}

int main( int argc, char * argv[] )
{
    int width = 500;
    int height = 500;

    ConsoleInterface interface;

    BottomLeftColor = interface.getBottomLeftColor();
    TopLeftColor = interface.getTopLeftColor();
    TopRightColor = interface.getTopRightColor();
    BottomRightColor = interface.getBottomRightColor();
    string = interface.getDisplayName();

    glutInit( & argc, argv );

    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );

    glutInitWindowSize( width, height );

    glutCreateWindow( "ColorDisplay" );
    glutFullScreen();

    glViewport( 0, 0, width, height );

    glutDisplayFunc( Display );

    glutCreateMenu( Menu );

    #ifdef WIN32

    glutAddMenuEntry( "EXIT", EXIT );
    #else

    glutAddMenuEntry( "EXIT", EXIT );
    #endif

    glutAttachMenu( GLUT_RIGHT_BUTTON );

    glutMainLoop();
    return 0;
}
