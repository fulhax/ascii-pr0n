#include "zoomer.h"
#include <math.h>
#include <curses.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define hy screen_height/2
#define hx screen_width/2

#define delta(x, y, X, Y)(float)(y-x)/((int)Y-(int)X)

int screen_width, screen_height;

struct vec3
{
    vec3()
    {
        x = y = z = 0;
    }
    vec3(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    float x, y, z;

    void operator = (vec3 v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
    }

    void operator +=(vec3 v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
    }

    vec3 operator +(vec3 v)
    {
        return vec3(x + v.x, y + v.y, z + v.z);
    }

    void operator +=(float s)
    {
        x += s;
        y += s;
        z += s;
    }

    vec3 operator +(float s)
    {
        return vec3(x + s, y + s, z + s);
    }

    void operator -=(vec3 v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
    }

    vec3 operator -(vec3 v)
    {
        return vec3(x - v.x, y - v.y, z - v.z);
    }

    void operator -=(float s)
    {
        x -= s;
        y -= s;
        z -= s;
    }

    vec3 operator -(float s)
    {
        return vec3(x - s, y - s, z - s);
    }

    void operator *=(vec3 v)
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;
    }

    vec3 operator *(vec3 v)
    {
        return vec3(x * v.x, y * v.y, z * v.z);
    }

    void operator *=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
    }

    vec3 operator *(float s)
    {
        return vec3(x * s, y * s, z * s);
    }

    void operator /=(vec3 v)
    {
        x /= v.x;
        y /= v.y;
        z /= v.z;
    }

    vec3 operator /(vec3 v)
    {
        return vec3(x / v.x, y / v.y, z / v.z);
    }

    void operator /=(float s)
    {
        x /= s;
        y /= s;
        z /= s;
    }

    vec3 operator /(float s)
    {
        return vec3(x / s, y / s, z / s);
    }
};

class mat4
{
public:
    float mat[4][4];

    void operator = (mat4 m)
    {
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                mat[i][j] = m.mat[i][j];
            }
    }

    mat4 operator + (mat4 m)
    {
        mat4 tmp;

        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                tmp.mat[i][j] = mat[i][j] + m.mat[i][j];
            }

        return tmp;
    }

    void operator += (mat4 m)
    {
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                mat[i][j] += m.mat[i][j];
            }
    }

    void operator += (float s)
    {
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                mat[i][j] += s;
            }
    }

    mat4 operator - (mat4 m)
    {
        mat4 tmp;

        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                tmp.mat[i][j] = mat[i][j] - m.mat[i][j];
            }

        return tmp;
    }

    void operator -= (mat4 m)
    {
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                mat[i][j] -= m.mat[i][j];
            }
    }

    void operator -= (float s)
    {
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                mat[i][j] -= s;
            }
    }

    mat4 operator * (mat4 m)
    {
        mat4 tmp;

        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                tmp.mat[i][j] = 0.0f;
            }

        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                float tmpf = 0;

                for(int g = 0; g < 4; g++)
                {
                    tmpf += mat[i][g] * m.mat[g][j];
                }

                tmp.mat[i][j] = tmpf;
            }

        return tmp;
    }

    void operator *= (float s)
    {
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                mat[i][j] *= s;
            }
    }

    vec3 transform(vec3 v)
    {
        vec3 tmp;
        float vec4[4];

        vec4[0] = (mat[0][0] * v.x) + (mat[0][1] * v.y) +
                  (mat[0][2] * v.z) + mat[0][3];
        vec4[1] = (mat[1][0] * v.x) + (mat[1][1] * v.y) +
                  (mat[1][2] * v.z) + mat[1][3];
        vec4[2] = (mat[2][0] * v.x) + (mat[2][1] * v.y) +
                  (mat[2][2] * v.z) + mat[2][3];
        vec4[3] = (mat[3][0] * v.x) + (mat[3][1] * v.y) +
                  (mat[3][2] * v.z) + mat[3][3];

        tmp.x = vec4[0] / vec4[3];
        tmp.y = vec4[1] / vec4[3];
        tmp.z = vec4[2] / vec4[3];

        return tmp;
    }

    void rotZ(float a)
    {
        mat4 tmp;
        tmp.loadIdentity();
        tmp.mat[0][0] = (float)cos(a);
        tmp.mat[0][1] = (float) - sin(a);
        tmp.mat[1][0] = (float)sin(a);
        tmp.mat[1][1] = (float)cos(a);

        (*this) = tmp  * (*this);
    }

    void rotX(float a)
    {
        mat4 tmp;
        tmp.loadIdentity();
        tmp.mat[1][1] = (float)cos(a);
        tmp.mat[1][2] = (float) - sin(a);
        tmp.mat[2][1] = (float)sin(a);
        tmp.mat[2][2] = (float)cos(a);

        (*this) = tmp  * (*this);
    }

    void rotY(float a)
    {
        mat4 tmp;
        tmp.loadIdentity();
        tmp.mat[2][2] = (float)cos(a);
        tmp.mat[2][0] = (float) - sin(a);
        tmp.mat[0][2] = (float)sin(a);
        tmp.mat[0][0] = (float)cos(a);

        (*this) = tmp  * (*this);
    }

    void scale(float size)
    {
        scale(size, size, size);
    }

    void scale(float x, float y, float z)
    {
        mat4 tmp;
        tmp.loadIdentity();

        tmp.mat[0][0] *= x;
        tmp.mat[1][1] *= y;
        tmp.mat[2][2] *= z;

        (*this) = tmp  * (*this);
    }

    void translate(float x, float y, float z)
    {
        mat4 tmp;
        tmp.loadIdentity();

        tmp.mat[0][3] += x;
        tmp.mat[1][3] += y;
        tmp.mat[2][3] += z;

        (*this) = tmp  * (*this);
    }

    void projection()
    {
        mat4 tmp;
        tmp.loadIdentity();
        tmp.mat[3][3] = 0.0f;
        tmp.mat[2][3] = -1.0f;
        tmp.mat[3][2] = 1.0f;

        (*this) = tmp * (*this);
    }

    void loadIdentity()
    {
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                mat[i][j] = 0.0f;
            }

        mat[0][0] = 1.0f;
        mat[1][1] = 1.0f;
        mat[2][2] = 1.0f;
        mat[3][3] = 1.0f;
    }
};

vec3 cross(vec3 v1, vec3 v2)
{
    return vec3(v1.y * v2.z - v1.z * v2.y,
                v1.z * v2.x - v1.x * v2.z,
                v1.x * v2.y - v1.y * v2.x);
}

void drawline(vec3 v1, vec3 v2)
{
    int s;
    float v[2];

    v[0] = (float)v2.x - v1.x;
    v[1] = (float)v2.y - v1.y;

    if(abs((int)v[0]) < abs((int)v[1]))
    {
        s = abs((int)v[1]);
        v[0] /= v[1];

        if(v[1] > 0)
        {
            v[1] = 1;
        }
        else
        {
            v[0] = -v[0];
            v[1] = -1;
        }
    }
    else
    {
        s = abs((int)v[0]);
        v[1] /= v[0];

        if(v[0] > 0)
        {
            v[0] = 1;
        }
        else
        {
            v[1] = -v[1];
            v[0] = -1;
        }
    }

    float w[2] = {v1.x, v1.y};

    while(s--)
    {
        if(!(
                    w[0] >= screen_width
                    || 0 >= w[0]
                    || w[1] >= screen_height
                    || 0 >= w[1]
                ))
        {
            mvprintw(w[1], w[0], "x");
        }

        w[0] += v[0];
        w[1] += v[1];
    }
}

void flat_shade(int x1, int x2, int y, int color)
{
    for(int i = x1; i < x2; i++)
    {
        attron(COLOR_PAIR(color));
        mvprintw(y, i, "x");
    }
}

void swap(vec3 *v1, vec3 *v2)
{
    vec3 tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}

void raster(vec3 v[3], int color)
{
    if(v[0].y < v[1].y)
    {
        swap(&v[0], &v[1]);
    }

    if(v[1].y < v[2].y)
    {
        swap(&v[1], &v[2]);

        if(v[0].y < v[1].y)
        {
            swap(&v[0], &v[1]);
        }
    }

    int dy = (int)v[0].y;

    float d1 = delta(v[1].x, v[0].x, v[1].y, dy);
    float d2 = delta(v[2].x, v[0].x, v[2].y, dy);

    float from = v[0].x;
    float to = v[0].x;

    while(dy > (int)v[1].y)
    {
        if(to < from)
        {
            flat_shade(to, from, dy, color);
        }
        else
        {
            flat_shade(from, to, dy, color);
        }

        dy--;
        from -= d1;
        to -= d2;
    }

    dy = (int)v[1].y;
    from = v[1].x;

    d1 = delta(v[2].x, v[1].x, v[2].y, dy);

    while(dy > (int)v[2].y)
    {
        if(to < from)
        {
            flat_shade(to, from, dy, color);
        }
        else
        {
            flat_shade(from, to, dy, color);
        }

        dy--;
        from -= d1;
        to -= d2;
    }
}

void drawCubes(bool wireframe)
{

    static vec3 cube[8] =
    {
        vec3(1, -1, -1),
        vec3(1, -1, 1),
        vec3(-1, -1, 1),
        vec3(-1, -1, -1),
        vec3(1, 1, -1),
        vec3(1, 1, 1),
        vec3(-1, 1, 1),
        vec3(-1, 1, -1)
    };

    static int colors[12] =
    {
        1, 1,
        2, 2,
        3, 3,
        4, 4,
        5, 5,
        6, 6,
    };

    static int indices[12][3] =
    {
        {5, 1, 4},
        {5, 4, 8},
        {3, 7, 8},
        {3, 8, 4},
        {2, 6, 3},
        {6, 7, 3},
        {1, 5, 2},
        {5, 6, 2},
        {5, 8, 6},
        {8, 7, 6},
        {1, 2, 3},
        {1, 3, 4}
    };



    mat4 m;
    mat4 em;
    mat4 mm;

    em.loadIdentity();

    static float r1 = 0.0f;


    {
        getmaxyx(stdscr, screen_height, screen_width);

        m.loadIdentity();

        m.scale(0.5f);
        m.translate(0.0f, 0.0f, -2.0f);

        m.projection();

        m.scale(hx, hy, 1.0f);
        m.translate(hx, hy, 0.0f);


        erase();

        // em.rotY(0.0001f);
        // em.rotX(0.0001f);

        vec3 v[3];

        for(int i = 0; i < 12; i++)
        {
            mm.loadIdentity();
            em.loadIdentity();

            mm.translate(-1.5f, 1, 0);

            em.rotX(r1);
            em.rotY(r1);

            for(int j = 0; j < 3; j++)
            {
                v[j] = em.transform(cube[indices[i][j] - 1]);
                v[j] = mm.transform(v[j]);
                v[j] = m.transform(v[j]);
            }

            if(cross(v[1] - v[0], v[2] - v[0]).z > 0)
            {
                raster(v, colors[i]);

                if(wireframe)
                {
                    attron(COLOR_PAIR(colors[i] + 7));
                    drawline(v[0], v[1]);
                    drawline(v[1], v[2]);
                    drawline(v[2], v[0]);
                }
            }
        }

        for(int i = 0; i < 12; i++)
        {
            mm.loadIdentity();
            em.loadIdentity();

            mm.translate(1.5f, -1, 0);

            em.rotX(-r1);
            em.rotY(-r1);

            for(int j = 0; j < 3; j++)
            {
                v[j] = em.transform(cube[indices[i][j] - 1]);
                v[j] = mm.transform(v[j]);
                v[j] = m.transform(v[j]);
            }

            if(cross(v[1] - v[0], v[2] - v[0]).z > 0)
            {
                raster(v, colors[i]);

                if(wireframe)
                {
                    attron(COLOR_PAIR(colors[i] + 7));
                    drawline(v[0], v[1]);
                    drawline(v[1], v[2]);
                    drawline(v[2], v[0]);
                }
            }
        }

        r1 += 0.0001f;

        refresh();
    }
}
