#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
    public:
        Vector2D(float X = 0, float Y = 0);
        ~Vector2D();

        float getX() const {return x; }
        float getY() const {return y; }

        void setX(const float X) {x = X; }
        void setY(const float Y) {y = Y; }

        //distance between two points
        float vecLength() const;

        //add two vectors
        Vector2D operator+ (const Vector2D& v2) const;
        Vector2D& operator+= (const Vector2D& v2);

        //multiply by a scalar
        Vector2D operator* (const float scalar) const;
        Vector2D& operator*= (const float scalar);

        //subtract vectors
        Vector2D operator- (const Vector2D& v2) const;
        Vector2D& operator-= (const Vector2D& v2);

        //divide by a scalar
        Vector2D operator/ (const float scalar) const;
        Vector2D& operator/= (const float scalar);

        //scale down the current vector to a unit vector
        void normalise();

    private:
        float x;
        float y;
};

#endif // VECTOR2D_H
