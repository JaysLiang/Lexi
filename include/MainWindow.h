#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <BaseWindow.h>
#include <tuple>


class MainWindow : public BaseWindow<MainWindow>
{
    public:
        MainWindow();
        virtual ~MainWindow();
        LPCSTR  ClassName() const;
        LRESULT HandleMessage(UINT &, WPARAM &, LPARAM &);
        void DrawChar(char &, int &, int &);
        void HandlePaint(WPARAM &, LPARAM &);
        std::tuple<int, int> CharSizes(const char &);
    protected:
    private:
        HDC m_hdc;
};

#endif // MAINWINDOW_H
