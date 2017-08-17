#include "Quad.h"

#define _USE_MATH_DEFINES
#include <cmath>


Quad::Quad(Vertex tl, Vertex tr, Vertex bl, Vertex br)
:mTl(tl), mTr(tr), mBl(bl), mBr(br){}


Quad Quad::operator+(Quad other){
    return Quad( this->tl() + other.tl(), 
                            this->tr() + other.tr(),
                            this->bl() + other.bl(),
                            this->br() + other.br());
}


Quad Quad::operator-(Quad other){
    return Quad( this->tl() - other.tl(), 
                            this->tr() - other.tr(),
                            this->bl() - other.bl(),
                            this->br() - other.br());
}


Quad Quad::operator*(float coef){
    return Quad( this->tl() * coef, 
                            this->tr() * coef,
                            this->bl() * coef,
                            this->br() * coef);
}


Quad Quad::operator*(Quad other){
    return Quad( this->tl() * other.tl(), 
                            this->tr() * other.tr(),
                            this->bl() * other.bl(),
                            this->br() * other.br());
}


Quad Quad::operator/(float coef){
    return Quad( this->tl() / coef, 
                            this->tr() / coef,
                            this->bl() / coef,
                            this->br() / coef);
}


// Quadの中にVertexが入っているかどうか
bool Quad::operator>(Vertex ver){

    // 左上座標を中心とし、右上座標への角度を割り出す
    double rad = std::atan2(this->tr().x() - this->tl().x(), this->tr().y() - this->tl().y());
    rad -= M_PI_2;

    // tlからtrへの直線がx軸に平行になるように、座標を回転させる
    Quad tmpQ;
    tmpQ.tl() = Vertex( this->tl().x() * std::cos(rad) -  this->tl().y() * std::sin(rad),
                                    this->tl().x() * std::sin(rad) + this->tl().y() * std::cos(rad));
    tmpQ.tr() = Vertex( this->tr().x() * std::cos(rad) -  this->tr().y() * std::sin(rad),
                                        this->tr().x() * std::sin(rad) + this->tr().y() * std::cos(rad));
    tmpQ.bl() = Vertex( this->bl().x() * std::cos(rad) -  this->bl().y() * std::sin(rad),
                                        this->bl().x() * std::sin(rad) + this->bl().y() * std::cos(rad));
    tmpQ.br() = Vertex( this->br().x() * std::cos(rad) -  this->br().y() * std::sin(rad),
                                        this->br().x() * std::sin(rad) + this->br().y() * std::cos(rad));

    Vertex tmpV;
    tmpV.x() = ver.x() * std::cos(rad) -  ver.y() * std::sin(rad);
    tmpV.y() =  ver.x() * std::sin(rad) + ver.y() * std::cos(rad);

    return (tmpQ.tl().x() <= tmpV.x()) && (tmpV.x() <= tmpQ.tr().x()) &&
                (tmpQ.tl().y() <= tmpV.y()) && (tmpV.y() <= tmpQ.bl().y());
}



// Quadの中にVertexが入っていないかどうか
bool Quad::operator<(Vertex ver){
    return !(*this > ver);
}
