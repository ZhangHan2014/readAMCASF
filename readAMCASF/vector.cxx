#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include "transform.h"
#include "types.h"
#include "vector.h"

//===============友元函数的实现====================
vector operator-( vector const& a, vector const& b )
{
    vector c;

    c.p[0] = a.p[0] - b.p[0];
    c.p[1] = a.p[1] - b.p[1];
    c.p[2] = a.p[2] - b.p[2];

    return c;
}
vector operator+( vector const& a, vector const& b )
{
    vector c;

    c.p[0] = a.p[0] + b.p[0];
    c.p[1] = a.p[1] + b.p[1];
    c.p[2] = a.p[2] + b.p[2];

    return c;
}
vector operator/( vector const& a, float b )
{
    vector c;

    c.p[0] = a.p[0] / b;
    c.p[1] = a.p[1] / b;
    c.p[2] = a.p[2] / b;

    return c;
}

vector operator*( vector const& a, float b )
{
    vector c;

    c.p[0] = a.p[0] * b;
    c.p[1] = a.p[1] * b;
    c.p[2] = a.p[2] * b;

    return c;
}


//叉乘实现
vector operator*( vector const& a, vector const& b )
{
    vector c;

    c.p[0] = a.p[1]*b.p[2] - a.p[2]*b.p[1];
    c.p[1] = a.p[2]*b.p[0] - a.p[0]*b.p[2];
    c.p[2] = a.p[0]*b.p[1] - a.p[1]*b.p[0];

    return c;
}

//点积实现
float operator%( vector const& a, vector const& b )
{
    return ( a.p[0]*b.p[0] + a.p[1]*b.p[1] + a.p[2]*b.p[2] );
}
vector operator%(vector const& a,float b){
	vector c;
	c.p[0] = a.p[0]-((int)(a.p[0]/b))*b;
	c.p[1] = a.p[1]-((int)(a.p[1]/b))*b;
	c.p[2] = a.p[2]-((int)(a.p[2]/b))*b;
	return c;
}
vector operator+=(vector &a,vector const& b){
	a = a+b;
	return a;
}
//线性插值实现
vector interpolate( float t, vector const& a, vector const& b )
{
	return a*(1.0-t) + b*t;
}

float len( vector const& v )
{
    return sqrt( v.p[0]*v.p[0] + v.p[1]*v.p[1] + v.p[2]*v.p[2] );
}

float
vector::length() const
{
    return sqrt( p[0]*p[0] + p[1]*p[1] + p[2]*p[2] );
}


float angle( vector const& a, vector const& b )
{
    return acos( (a%b)/(len(a)*len(b)) );
}


