/*
* RETRIEVED: 2015-09-08 09:24
*
* FROM: http://pastebin.com/k3dbDKdn
*
* VIA: http://barkeshli.org/pcc/node/783
*
*/

#include <windows.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>

using namespace std;

float transX =0.0f;
float transY =0.0f;

//Initializes 3D rendering
void initializeRendering(){
    if (!glfwInit())exit(EXIT_FAILURE);
}

//Called when a key is pressed
void handleKeypress(GLFWwindow* window, int key, int scancode, int action, int mode) { //The key that was pressed
    if (action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_UP:
                transY += 0.1f;
                break;
            case GLFW_KEY_DOWN:
                transY -= 0.1f;
                break;
            case GLFW_KEY_RIGHT:
                transX += 0.1f;
                break;
            case GLFW_KEY_LEFT:
                transX -= 0.1f;
                break;
            case GLFW_KEY_ESCAPE:
                exit(0);
        }
    }
}

//Called when the window is resized
void handleResize( GLFWwindow* window, int width,int height) {
    int fbwidth, fbheight;
    glfwGetFramebufferSize( window, &fbwidth, &fbheight );
    //Tell OpenGL how to convert from coordinates to pixel values
    glViewport( 0, 0, fbwidth, fbheight );

    glMatrixMode( GL_PROJECTION ); //Switch to setting the camera perspective
    //Set the camera perspective
    glLoadIdentity(); //reset the camera
    gluPerspective( 45.0f,                      //camera angle
                    (GLfloat)width/(GLfloat)height, //The width to height ratio
                    1.0f,                          //The near z clipping coordinate
                    100.0f );                       //The far z clipping coordinate
}

void display(GLFWwindow* window) {
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f ); //clear background screen to black

    //Clear information from last draw
    glClear( GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
    glLoadIdentity(); //Reset the drawing perspective

    glPushMatrix();
    glTranslatef(transX,transY,0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.1f, 0.6f);
    //square
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glEnd();

    glPopMatrix();
    glfwSwapBuffers(window);

}

int main() {
    // int     width, height;
    //int     frame = 0;
    bool running = true;

    initializeRendering();

    GLFWwindow* window = glfwCreateWindow( 512, 512, "name", NULL, NULL );
    if ( !window )
    {
        glfwTerminate(); //terminating glfw window
        return 0;
    }

    glfwSetWindowTitle(window, "codeincodeblock.blogspot.com - basic shape");
    glfwSetWindowSizeCallback(window, handleResize); //callback function of GLFW to handle window resize
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, handleKeypress); //callback function to handle keypress
    bool Up= false;
    bool Right=false;

    while(running) // infinite loop to draw object again and again
    {              // because once object is draw then window is terminated
        Sleep(10);
        display(window);
        if(Up){
            if (transY<=0.0f)
                transY+=0.01f;
            else
                Up=false;}
        else{
            if (transY>=-1.0f)
                transY-=0.01f;
            else
                Up=true;}
        if(Right){
            if (transX<=0.0f)
                transX+=0.03f;
            else
                Right=false;}
        else{
            if (transX>=-1.0f)
                transX-=0.03f;
            else
                Right=true;}
        glfwPollEvents();
        running = !glfwWindowShouldClose(window);
        //if should-be-closed then return false
    }
    return 0;
}
