#include <iostream>
#include <Glyph.h>

Glyph::Glyph() : parent(nullptr)
{
    //ctor
}

Glyph::~Glyph()
{
    //dtor
}

void Glyph::Draw(MainWindow *)
{
    std::cerr << "Glyph::Draw()" << '\n';
}

void Glyph::Bounds(Rect &)
{
    std::cerr << "Glyph::Bounds()" << '\n';
}

bool Glyph::Intersects(const Point &)
{
    std::cerr << "Glyph::Intersects()" << '\n';
    return false;
}

void Glyph::Insert(Glyph *, int)
{
    std::cerr << "Glyph::Insert()" << '\n';
}

void Glyph::Remove(Glyph *)
{
    std::cerr << "Glyph::Remove()" << '\n';
}

Glyph * Glyph::Child(int)
{
    std::cerr << "Glyph::Child()" << '\n';
    return nullptr;
}

Glyph * Glyph::Parent()
{
    return parent;
}

void Glyph::SetParent(Glyph * _parent)
{
    parent = _parent;
}
