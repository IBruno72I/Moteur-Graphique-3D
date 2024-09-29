#include "maths.h"
#include "events.h"
#include "window.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


SDL_Point convertVec3(SDL_Window* window, Vec3 cam, Vec3 pos, float fov) {
    SDL_Point point;
    Proj projPos;
    pos.x -= cam.x;
    pos.y -= cam.y;
    pos.z -= cam.z;
    int width = 0;
    int height = 0;
    SDL_GetWindowSize(window, &width, &height);
    float near = 0.1f;  // Plan proche
    float far = 100.0f;  // Plan lointain
    float aspect_ratio = width / height;
    Mat4 perspective_matrix = mat4_perspective(fov, aspect_ratio, near, far);
    
    // Appliquer la projection sur le point 3D
    Vec3 projected_point = mat4_mul_vec3(perspective_matrix, pos);

    // Division perspective (w est la 4ème composante calculée implicitement)
    float w = projected_point.z;  // w correspond souvent à z' après projection
    projected_point.x /= w;
    projected_point.y /= w;
    point = convertToScreen(projected_point, width, height);

    return point;
}

SDL_Point convertToScreen(Vec3 point, int width, int height) {
    SDL_Point sdl;
    sdl.x = (int)((point.x+1)/2.0f*width);
    sdl.y = (int)((1-point.y)/2.0f*height);
    return sdl;
}

//////////////////////////////////////////////////////////////////////////////////

Vec3 vec3_add(Vec3 a, Vec3 b) {
    return (Vec3){a.x + b.x, a.y + b.y, a.z + b.z};
}

Vec3 vec3_sub(Vec3 a, Vec3 b) {
    return (Vec3){a.x - b.x, a.y - b.y, a.z - b.z};
}

float vec3_dot(Vec3 a, Vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vec3 vec3_cross(Vec3 a, Vec3 b) {
    return (Vec3){
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

Vec3 vec3_normalize(Vec3 v) {
    float length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    return (Vec3){v.x / length, v.y / length, v.z / length};
}

//////////////////////////////////////////////////////////////////////////////////

Mat4 mat4_identity() {
    Mat4 result = {{{0}}};
    result.m[0][0] = result.m[1][1] = result.m[2][2] = result.m[3][3] = 1.0f;
    return result;
}

Mat4 mat4_translate(float x, float y, float z) {
    Mat4 result = mat4_identity();
    result.m[0][3] = x;
    result.m[1][3] = y;
    result.m[2][3] = z;
    return result;
}

Vec3 mat4_mul_vec3(Mat4 m, Vec3 v) {
    return (Vec3){
        m.m[0][0] * v.x + m.m[0][1] * v.y + m.m[0][2] * v.z + m.m[0][3],
        m.m[1][0] * v.x + m.m[1][1] * v.y + m.m[1][2] * v.z + m.m[1][3],
        m.m[2][0] * v.x + m.m[2][1] * v.y + m.m[2][2] * v.z + m.m[2][3]
    };
}

Mat4 mat4_mul(Mat4 a, Mat4 b) {
    Mat4 result = {{{0}}};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.m[i][j] = a.m[i][0] * b.m[0][j] + a.m[i][1] * b.m[1][j] +
                             a.m[i][2] * b.m[2][j] + a.m[i][3] * b.m[3][j];
        }
    }
    return result;
}

Mat4 mat4_perspective(float fov, float aspect, float near, float far) {
    Mat4 result = {{{0}}};
    float tan_half_fov = tan(fov / 2);

    result.m[0][0] = 1 / (aspect * tan_half_fov);
    result.m[1][1] = 1 / tan_half_fov;
    result.m[2][2] = -(far + near) / (far - near);
    result.m[2][3] = -(2 * far * near) / (far - near);
    result.m[3][2] = -1;
    return result;
}