#ifndef GLYPH_H
#define GLYPH_H

#include <Point.h>
#include <Rect.h>
#include <MainWindow.h>

class Glyph
{
    public:
        Glyph();
        virtual ~Glyph();
        virtual void Draw(MainWindow *);
        virtual void Bounds(Rect&);
        virtual bool Intersects(const Point&);
        virtual void Insert(Glyph *, int);
        virtual void Remove(Glyph *);
        virtual Glyph * Child(int);
        virtual Glyph * Parent();
        void SetParent(Glyph *);
    protected:
    private:
        Glyph * parent;
};

#endif // GLYPH_H
