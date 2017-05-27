#include "DocumentCreator.h"
#include <tuple>
#include <CompositeGlyph.h>
#include <CharGlyph.h>

DocumentCreator::DocumentCreator(MainWindow * _w) : window(_w)
{
    //ctor
}
Glyph * DocumentCreator::CreateDocument(const char * str)
{
    Glyph * character;
    Glyph * row = CreateCompositeGlyph();
    for(int i = 0; str[i] != 0; i++) {
        character = CreateCharGlyph(str[i]);
        row->Insert(character, i);
    }
    return row;
}

Glyph * DocumentCreator::CreateCharGlyph(const char & ch)
{
    int width, height;
    std::tie(width, height) = window->CharSizes(ch);
    return new CharGlyph(ch, width, height);
}

Glyph * DocumentCreator::CreateCompositeGlyph()
{
    return new CompositeGlyph();
}
