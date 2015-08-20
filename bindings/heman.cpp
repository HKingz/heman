#include "heman.h"
#include "heman.hpp"

using namespace heman;

Image* Image::create(int width, int height, int nbands) { return nullptr; }

Image::~Image() {}

int Image::width() const { return 0; }

int Image::height() const { return 0; }

int Image::nbands() const { return 0; }

HEMAN_FLOAT* Image::data() { return 0; }

HEMAN_FLOAT* Image::texel(int x, int y) { return 0; }

void Image::sample(float u, float v, HEMAN_FLOAT* result) const {}

Image::Image(int width, int height, int nbands) {}

Image* Color::createGradient(int width, int num_colors, const int* cp_locations,
    const heman_color* cp_colors)
{}

void Color::setGamma(float) {}

void Color::applyGradient(
    Image*, HEMAN_FLOAT minh, HEMAN_FLOAT maxh, Image* gradient)
{}
