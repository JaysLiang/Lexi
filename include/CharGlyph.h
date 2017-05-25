#ifndef CHARGLYPH_H
#define CHARGLYPH_H

#include <Glyph.h>


class CharGlyph : public Glyph
{
    public:
        CharGlyph(char);
        virtual ~CharGlyph();
        virtual void Draw(MainWindow *);
        virtual void Bounds(Rect &);
        virtual bool Intersects(const Point &);
    protected:
    private:
        char ch;
        int x, y;
};

#endif // CHARGLYPH_H
