#ifndef DOCUMENTCREATOR_H
#define DOCUMENTCREATOR_H

#include <Glyph.h>
#include <MainWindow.h>


class DocumentCreator
{
    public:
        DocumentCreator(MainWindow *);
        Glyph * CreateDocument(const char *);
        Glyph * CreateCharGlyph(const char &);
        Glyph * CreateCompositeGlyph();
    protected:
    private:
        MainWindow * window;
};

#endif // DOCUMENTCREATOR_H
