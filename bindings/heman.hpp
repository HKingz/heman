#pragma once

struct heman_image_s;
typedef struct heman_image_s heman_image;
typedef unsigned char heman_byte;
typedef unsigned int heman_color;

#ifndef HEMAN_FLOAT
#define HEMAN_FLOAT float
#endif

namespace heman
{
    struct ImageImpl;

    class Image
    {
    public:
        static Image* create(int width, int height, int nbands);
        ~Image();
        int width() const;
        int height() const;
        int nbands() const;
        HEMAN_FLOAT* data();
        HEMAN_FLOAT* texel(int x, int y);
        void sample(float u, float v, HEMAN_FLOAT* result) const;

    private:
        Image(int width, int height, int nbands);
        heman_image* img;
    };

    class Color
    {
    public:
        static Image* createGradient(int width, int num_colors,
            const int* cp_locations, const heman_color* cp_colors);
        static void setGamma(float);
        static void applyGradient(
            Image*, HEMAN_FLOAT minh, HEMAN_FLOAT maxh, Image* gradient);
    }
}
