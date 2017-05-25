#ifndef COMPOSITEGLYPH_H
#define COMPOSITEGLYPH_H

#include <vector>
#include <Glyph.h>


class CompositeGlyph : public Glyph
{
    public:
        CompositeGlyph();
        ~CompositeGlyph();
        virtual void Draw(MainWindow *);
        virtual void Bounds(Rect &);
        virtual bool Intersects(const Point &);
        virtual void Insert(Glyph *, int);
        virtual void Remove(Glyph *);
        virtual Glyph * Child(int);
    protected:
    private:
        std::vector<Glyph *> children;
};

#endif // COMPOSITEGLYPH_H
