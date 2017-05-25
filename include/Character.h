#ifndef CHARACTER_H
#define CHARACTER_H

#include <Glyph.h>


class Character : public Glyph
{
    public:
        Character(char&);
        virtual ~Character();
        char Getch() { return ch; }
    protected:
    private:
        char ch;
};

#endif // CHARACTER_H
