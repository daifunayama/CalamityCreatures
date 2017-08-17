#include "Vertex.h"


Vertex::Vertex(float x, float y):mX(x), mY(y){}


Vertex Vertex::operator+(Vertex other){
    return Vertex(this->x() + other.x(), this->y() + other.y());
}


Vertex Vertex::operator-(Vertex other){
    return Vertex(this->x() - other.x(), this->y() - other.y());
}


Vertex Vertex::operator*(float coef){
    return Vertex(this->x() * coef, this->y() * coef);
}


Vertex Vertex::operator*(Vertex other){
    return Vertex(this->x() * other.x(), this->y() * other.y());
}


Vertex Vertex::operator/(float coef){
    return Vertex(this->x() / coef, this->y() / coef);
}
