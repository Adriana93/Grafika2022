/* scene.c file */

#include "scene.h"
//#include <GL/glut.h>
#include <time.h>

double sun_y_rotation=0;
double sun_z_rotation=0;
double sun_rotate=0;

double brightness=10; // világosság
double flash_light=10; //fényerő


void init_scene(Scene* scene)
{
    load_model(&(scene->ground), "assets/models/ground.obj");
    load_model(&(scene->water), "assets/models/water.obj");
    load_model(&(scene->sun), "assets/models/sun.obj");
       load_model(&(scene->turtle), "assets/models/turtle.obj");

    scene->texture_ground = load_texture("assets/textures/ground.jpg"); 
    scene->texture_water = load_texture("assets/textures/water.jpg");	
	 scene->texture_sun = load_texture("assets/textures/sun.png"); 
	scene->texture_turtle = load_texture("assets/textures/turtle.jpg"); 	
	scene->information = load_texture("assets/textures/information.PNG"); 

    scene->material.ambient.red = 5.0;
    scene->material.ambient.green = 5.0;
    scene->material.ambient.blue = 5.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;
	
    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 10.0;
}

void set_lighting()
{
    float ambient_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light[] = { 1.0f+brightness, 1.0f+brightness, 1.0f+brightness, 1.0f+brightness };
    float specular_light[] = { 1.0f+flash_light, 1.0f+flash_light, 1.0f+flash_light, 1.0f+flash_light };
    float position[] = { 40.0f, 20.0f, 0.0f, 2.0f };
 
		
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}



void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_scene(Scene* scene)
{
}

void render_scene(const Scene* scene)
{

    set_material(&(scene->material));
    set_lighting();
	draw_origin();	
    draw_model(&(scene->ground));
	
	glBindTexture(GL_TEXTURE_2D, scene->texture_water);	
	glPushMatrix();	
	draw_model(&(scene->water));
	glPopMatrix();
	
    glBindTexture(GL_TEXTURE_2D, scene->texture_sun);	
	glPushMatrix();
	glRotatef(0, 0, 0+sun_rotate, 0);
	glTranslatef(1.0, 1.0+sun_y_rotation, 1.0+sun_z_rotation);
	glScalef(0.1, 0.1, 0.1);
	draw_model(&(scene->sun));
	glPopMatrix();

   
	glBindTexture(GL_TEXTURE_2D, scene->texture_turtle);
    glPushMatrix();
	glTranslatef(0.5,0.5,0.1);
	glScalef(0.1, 0.1, 0.1);
    draw_model(&(scene->turtle));
	glPopMatrix();
		
	glBindTexture(GL_TEXTURE_2D, scene->information);
}

void sun_movement(double time)
{
	sun_y_rotation=sun_y_rotation-time/500;
	sun_z_rotation=sun_z_rotation+time/500;
	sun_rotate=sun_rotate+time*5;	
}		

void invisible() // To invisible.
{
	glBlendFunc(1, 1);
}

void invisible2() // To black.
{
	glBlendFunc(0, 0);
}
void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}
