#include "MainWindow.h"
#include <string>
#include <sstream>
#include <DocumentCreator.h>


MainWindow::MainWindow() : m_hdc(NULL)
{
    //ctor
    DocumentCreator * dc = new DocumentCreator(this);
    Glyph * doc = dc->CreateDocument("test");
}

MainWindow::~MainWindow()
{
    //dtor
}

LPCSTR MainWindow::ClassName() const
{
    return "Lexi";
}

void MainWindow::DrawChar(char & ch, int & x, int & y)
{
    //char buf[ 1 ];
    //TextOut( hdc, x, y, buf, wsprintf( buf, "%c", ch ));

    //OR
    //std::string str;
    //str.push_back(ch);
    //TextOut(hdc, x, y, str.c_str(), str.size());

    //OR
    std::string str(1, ch);
    TextOut(m_hdc, x, y, str.c_str(), str.size());
}

LRESULT MainWindow::HandleMessage(UINT & uMsg, WPARAM & wParam, LPARAM & lParam)
{
    switch (uMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
            HandlePaint(wParam, lParam);
            return 0;

        default:
            return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
    }
    return TRUE;
}

void MainWindow::HandlePaint(WPARAM & /*wParam*/, LPARAM & /*lParam*/)
{
    PAINTSTRUCT ps;
    m_hdc = BeginPaint(m_hwnd, &ps);

    SIZE sz;
    char ch = 'i';
    GetTextExtentPoint32(m_hdc, &ch, 1, &sz);
    std::stringstream sx, sy;
    sx << sz.cx; sy << sz.cy;
    std::string str = std::string(1, ch) + " CharWidth = " + sx.str() + " CharHeight = " + sy.str();
    TextOut(m_hdc, 0, 0, str.c_str(), str.size());
    TextOut(m_hdc, 4, 16, str.c_str(), str.size());

    //FillRect(m_hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

    EndPaint(m_hwnd, &ps);
}

std::tuple<int, int> MainWindow::CharSizes(const char & ch)
{
    HDC hdc = GetDC(m_hwnd);
    SIZE sz;
    GetTextExtentPoint32(hdc, &ch, 1, &sz);
    //widht = sz.cx;
    //height = sz.cy;
    ReleaseDC(m_hwnd, hdc);
    return std::make_tuple(sz.cx, sz.cy);
}
