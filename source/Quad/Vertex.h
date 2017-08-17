#pragma once


class Vertex{

public:
    Vertex(){}                         // コンストラクタに引数を指定しないと座標は0で初期化される
    Vertex(float, float);
    float& x(){return mX;}
    float& y(){return mY;}

// 主要な演算子のオーバーロード
public:
    Vertex operator+(Vertex);
    Vertex operator-(Vertex);
    Vertex operator*(float);
    Vertex operator*(Vertex);
    Vertex operator/(float);

private:
    float mX = 0;
    float mY = 0;

};
