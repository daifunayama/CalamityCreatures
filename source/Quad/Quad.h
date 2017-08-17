#pragma once

#include "Vertex.h"


class Quad{

public:
    Quad(){}
    Quad(Vertex, Vertex, Vertex, Vertex);
    Vertex& tl(){return mTl;}
    Vertex& tr(){return mTr;}
    Vertex& bl(){return mBl;}
    Vertex& br(){return mBr;}

// 主要な演算子のオーバーロード
public:
    Quad operator+(Quad);
    Quad operator-(Quad);
    Quad operator*(float);
    Quad operator*(Quad);
    Quad operator/(float);
    bool operator>(Vertex);
    bool operator<(Vertex);

private:
    Vertex mTl, mTr;
    Vertex mBl, mBr;

};
