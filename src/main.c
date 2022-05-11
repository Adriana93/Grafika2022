/* main.c file */

#include "app.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <SOIL/SOIL.h>
//#include <GL/glut.h>


/* Main function */
int main(int argc, char* argv[])
{
   App app;

    init_app(&app, 800, 600);
    while (app.is_running) {
        handle_app_events(&app);
        update_app(&app);
        render_app(&app);
    }
    destroy_app(&app);

    return 0;

    return 0;
}