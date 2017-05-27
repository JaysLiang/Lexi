#include <iostream>     // std::cerr
#include <algorithm>    // std::find
#include <vector>       // std::vector

#include "CompositeGlyph.h"

CompositeGlyph::CompositeGlyph()
{
    //ctor
}

CompositeGlyph::~CompositeGlyph()
{
    //dtor
}

void CompositeGlyph::Draw(MainWindow * w)
{
    for(auto c : children) {
        c->Draw(w);
    }
}

void CompositeGlyph::Bounds(Rect & r)
{
    Glyph * firstChild = Child(0);
    firstChild->Bounds(r); //x, y от первого дочернего элемента

    int w = 0, h = 0;
    Rect cR;
    for(auto c : children) {
        c->Bounds(cR);
        w += cR.width; //суммарная ширина дочерних элементов
        if(cR.height > h) {
            h = cR.height; //максимальная высота
        }
    }
    r.width = w;
    r.height = h;
}

bool CompositeGlyph::Intersects(const Point & p)
{
    for(auto c : children) {
        if(c->Intersects(p)) {
            return true;
        }
    }

    return false;
}

void CompositeGlyph::Insert(Glyph * g, int index)
{
    g->SetParent(this);
    auto it = children.begin();
    children.insert(it + index, g);
}

void CompositeGlyph::Remove(Glyph * g)
{
    std::vector<Glyph *>::iterator it = std::find(children.begin(), children.end(), g);
    if(it != children.end()) {
        g->SetParent(nullptr);
        children.erase(it);
    }
    else {
        std::cerr << "CompositeGlyph::Remove() - glyph is not child of this CompositeGlyph" << '\n';
    }
}

Glyph * CompositeGlyph::Child(int index)
{
    return children[index];
}
