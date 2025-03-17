#include <iostream>

class Vector2 {
private:
    double x, y;  // 2차원 벡터의 x, y 좌표

public:
    // 생성자
    Vector2(double x = 0, double y = 0) : x(x), y(y) {}

    // 벡터 덧셈 (Vector + Vector)
    Vector2 operator+(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }

    // 스칼라 곱 (Vector * Scalar)
    Vector2 operator*(double scalar) const {
        return Vector2(x * scalar, y * scalar);
    }

    // 벡터 내적 (Dot Product: Vector * Vector -> double)
    double operator*(const Vector2& other) const {
        return (x * other.x) + (y * other.y);
    }

    // 출력 연산자 오버로딩
    friend std::ostream& operator<<(std::ostream& os, const Vector2& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
};