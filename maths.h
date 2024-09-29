#ifndef MATHS_H

#define MATHS_H

#include <SDL2/SDL.h>
#include <math.h>

typedef struct{
    // [-1,1]
    float x;
    float y;
}Proj;

typedef struct {
    float x, y, z;
} Vec3;

typedef struct {
    float m[4][4];
} Mat4;

SDL_Point convertVec3(SDL_Window* window, Vec3 cam, Vec3 pos, float fov);
Proj projection(Vec3 pos, float fov);
Vec3 vec3_add(Vec3 a, Vec3 b);
Vec3 vec3_sub(Vec3 a, Vec3 b);
float vec3_dot(Vec3 a, Vec3 b);
Vec3 vec3_cross(Vec3 a, Vec3 b);
Vec3 vec3_normalize(Vec3 v);

Mat4 mat4_identity();
Mat4 mat4_translate(float x, float y, float z);
Vec3 mat4_mul_vec3(Mat4 m, Vec3 v);
Mat4 mat4_mul(Mat4 a, Mat4 b);
Mat4 mat4_perspective(float fov, float aspect, float near, float far);

#endif