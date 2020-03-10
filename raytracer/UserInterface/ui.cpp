//
// Created by root on 9/3/20.
//

#include <World.h>
#include "ui.h"

void RenderThread::setPixel(int x, int y, int red, int green, int blue) {
    pixels.push_back(RenderPixel({x, y, red, green, blue}));
}

std::vector<unsigned char> RenderThread::pixel_data(bool flip_y) {
    std::vector<unsigned char> buffer;
    int stride = 3;
    buffer.resize(pixels.size() * stride);
    int width = world->vp.hres;
    int height = world->vp.vres;

    for (auto pixel : pixels) {
        auto &[x, y, r, g, b] = pixel;
        if (flip_y) y = height - y - 1;
        buffer[y * width * stride + x * stride + 0] = static_cast<unsigned char>(r);
        buffer[y * width * stride + x * stride + 1] = static_cast<unsigned char>(g);
        buffer[y * width * stride + x * stride + 2] = static_cast<unsigned char>(b);
    }
    return buffer;
}
