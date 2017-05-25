#include "MainWindow.h"
#include <string>

MainWindow::MainWindow() : m_hdc(NULL)
{
    //ctor
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

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
            {
                PAINTSTRUCT ps;
                m_hdc = BeginPaint(m_hwnd, &ps);

                //FillRect(m_hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

                EndPaint(m_hwnd, &ps);
            }
            return 0;

        default:
            return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
    }
    return TRUE;
}
