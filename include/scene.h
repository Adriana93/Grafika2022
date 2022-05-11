/* scene.h file */

#ifndef SCENE_H_
#define SCENE_H_

#include "camera.h"
#include "texture.h"
#include <obj/model.h>

typedef struct Scene
{
    Camera camera;
	Model ground;
    Model water;
    Model sun;
	Model turtle;
    Material material;
    GLuint texture_ground;
    GLuint texture_water;
    GLuint texture_sun;
    GLuint texture_turtle;
    GLuint information;
} Scene;

/* Initialize the scene by loading models. */
void init_scene(Scene* scene);

/* Set the lighting of the scene. */
void set_lighting();

/* Set the current material. */
void set_material(const Material* material);

/* Draw the scene objects. */
void draw_scene(const Scene* scene);

/* Update the light of the scene. */
void update_lighting(Scene* scene, double value);

/* Set the sun move of the scene. */
void sun_movement();

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

#endif /* SCENE_H_ */