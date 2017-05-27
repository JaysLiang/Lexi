#ifndef CHARGLYPH_H
#define CHARGLYPH_H

#include <Glyph.h>


class CharGlyph : public Glyph
{
    public:
        CharGlyph(char, int width = 0, int height = 0, int x = 0, int y = 0);
        virtual ~CharGlyph();
        virtual void Draw(MainWindow *);
        virtual void Bounds(Rect &);
        virtual bool Intersects(const Point &);
    protected:
    private:
        char ch;
        int width, height, x, y;
};

#endif // CHARGLYPH_H
