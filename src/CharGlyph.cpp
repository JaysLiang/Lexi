#include "CharGlyph.h"
#include <iostream>

CharGlyph::CharGlyph(char _ch) : ch(_ch), x(0), y(0)
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

void CharGlyph::Bounds(Rect & /*r*/)
{
    std::cerr << "!!!!Not implemented CharGlyph::Bounds" << '\n';
}

bool CharGlyph::Intersects(const Point & /*p*/)
{
    std::cerr << "!!!!Not implemented CharGlyph::Intersects" << '\n';
    return false;
}
