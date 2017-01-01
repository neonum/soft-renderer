#ifndef __VERTEX2_H
#define __VERTEX2_H
#include "Vector4.h"
#include "Matrix4.h"

class Vertex
{
public:
    Vertex(float _x, float _y, float _z)
    {
        pos.x = _x;
        pos.y = _y; 
        pos.z = _z; 
        pos.w = 1;
    }
    Vertex(const Vector4& _pos, const Vector4& _texCoords)
        : pos(_pos), texCoords(_texCoords)
    {
    }
    Vertex Transform(const Matrix4& transform) const
    {
        return Vertex(transform.Transform(pos), texCoords);
    }
    Vertex PerspectiveDivide()
    {
        return Vertex(Vector4(pos.x / pos.w, pos.y / pos.w,
            pos.z / pos.w, pos.w), texCoords);
    }
    float TriangleAreaTimesTwo(const Vertex& b, const Vertex& c)
    {
        float x1 = b.pos.x - pos.x;
        float y1 = b.pos.y - pos.y;

        float x2 = c.pos.x - pos.x;
        float y2 = c.pos.y - pos.y;

        return (x1 * y2 - x2 * y1);
    }
    float GetX() const { return pos.x; } 
    float GetY() const { return pos.y; }
    float GetZ() const { return pos.z; }
    //Vector4 GetColor() const { return color; };
    Vector4 GetTexCoords() const { return texCoords; }
public:
    Vector4 pos; 
    //Vector4 color;
    Vector4 texCoords;
};

#endif