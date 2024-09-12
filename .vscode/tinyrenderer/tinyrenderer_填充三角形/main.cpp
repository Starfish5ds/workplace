#include <vector>
#include <cmath>
#include "tgaimage.h"
#include "geometry.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);
const TGAColor green = TGAColor(0,   255, 0,   255);
const int width  = 200;
const int height = 200;

void line(Vec2i p0, Vec2i p1, TGAImage &image, TGAColor color) 
{
    bool steep = false;
    if (std::abs(p0.x-p1.x)<std::abs(p0.y-p1.y)) {
        std::swap(p0.x, p0.y);
        std::swap(p1.x, p1.y);
        steep = true;
    }
    if (p0.x>p1.x) {
        std::swap(p0, p1);
    }

    for (int x=p0.x; x<=p1.x; x++) {
        float t = (x-p0.x)/(float)(p1.x-p0.x);
        int y = p0.y*(1.-t) + p1.y*t;
        if (steep) {
            image.set(y, x, color);
        } else {
            image.set(x, y, color);
        }
    }
}

void triangle(Vec2i t0, Vec2i t1, Vec2i t2, TGAImage &image, TGAColor color)
{
    //将三角形三个点根据y的大小排序
    //t0为最高点
    if(t0.y < t1.y) std::swap(t0, t1);
    if(t0.y < t2.y) std::swap(t0, t2);
    //t2为最低点
    if(t2.y > t1.y) std::swap(t2, t1);

    for(int i = t2.y; i < t0.y; ++i)
    {
        //根据t1将三角形分割成两部分
        //计算下半部分
        if(i < t1.y)
        {
            
        }


    }


}

int main(int argc, char** argv) 
{
    TGAImage image(width, height, TGAImage::RGB);

    image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
    image.write_tga_file("output.tga");
    return 0;
}

