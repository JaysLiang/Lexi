#include "CharGlyph.h"
#include <iostream>

CharGlyph::CharGlyph(char _ch, int _w, int _h, int _x, int _y) : ch(_ch), width(_w), height(_h), x(_x), y(_y)
{
    //ctor
}

CharGlyph::~CharGlyph()
{
    //dtor
}

void CharGlyph::Draw(MainWindow *w)
{
    w->DrawChar(ch, x, y);
}

void CharGlyph::Bounds(Rect & r)
{
    r.x = x;
    r.y = y;
    r.width = width;
    r.height = height;
}

bool CharGlyph::Intersects(const Point & p)
{
    bool intersectsX = (x <= p.x) && (p.x <= (x + width - 1));
    bool intersectsY = (y <= p.y) && (p.y <= (y + height - 1));
    return intersectsX && intersectsY;
}
