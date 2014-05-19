#include "Vector2D.h"

#include <cmath>

#include <iostream>
using std::cout;
using std::endl;

Vector2D::Vector2D(float X, float Y)
: x(X), y(Y)
{
    cout << " 8 C Vector2D" << endl;
}

Vector2D::~Vector2D()
{
    cout << " 8 D Vector2D" << endl;
}

float Vector2D::vecLength()
{
    return sqrt(x * x + y * y);
}

Vector2D Vector2D::operator+ (const Vector2D& v2) const
{
    return Vector2D(x + v2.getX(), y + v2.getY());
}

Vector2D& Vector2D::operator+= (const Vector2D& v2)
{
    x = x + v2.getX();
    y = y + v2.getY();

    return *this;
}

Vector2D Vector2D::operator* (const float scalar) const
{
    return Vector2D(x * scalar, y * scalar);
}

Vector2D& Vector2D::operator*= (const float scalar)
{
    x = x * scalar;
    y = y * scalar;

    return *this;
}

Vector2D Vector2D::operator- (const Vector2D& v2) const
{
    return Vector2D(x - v2.getX(), y - v2.getY());
}

Vector2D& Vector2D::operator-= (const Vector2D& v2)
{
    x = x - v2.getX();
    y = y - v2.getY();

    return *this;
}

Vector2D Vector2D::operator/ (const float scalar) const
{
    return Vector2D(x / scalar, y / scalar);
}

Vector2D& Vector2D::operator/= (const float scalar)
{
    x = x / scalar;
    y = y / scalar;

    return *this;
}

void Vector2D::normalise()
{
    float length = vecLength();

    if (length > 0)//check division by 0
    {
        x = x / length;
        y = y / length;
    }
}
