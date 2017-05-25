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

void CompositeGlyph::Bounds(Rect &)
{
//    for(auto c : children) {
//        c->Bounds();
//    }
    std::cerr << "CompositeGlyph::Bounds" << '\n';
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
        std::cerr << "CompositeGlyph::Remove()" << '\n';
    }
}

Glyph * CompositeGlyph::Child(int index)
{
    return children[index];
}
