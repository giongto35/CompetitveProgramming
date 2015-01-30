#include <iostream>

using namespace std;

class Polygon{
protected:
    int width, height;
public:
    Polygon(int w,int h):width(w),height(h){}
    virtual int area(void) = 0;
};

class rectangle: public Polygon{
    public:
    rectangle(int w, int h):Polygon(w,h){}
    int area(){
        return width * height ;
    }
};

class triangle: public Polygon{
    public:
    triangle(int w, int h):Polygon(w,h){}
    int area(){
        return width * height / 2;
    }
};

int main(){
    rectangle rect1(4,5);
    triangle tri1(4,5);
    Polygon *p1 = &rect1;
    Polygon *p2 = &tri1;
    cout<<p1->area()<<endl;
    cout<<p2->area()<<endl;
}
