#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <MainWindow.h>
#include <iostream>

//-------TEST-------
//#include <Glyph.h>
//#include <CompositeGlyph.h>
//#include <CharGlyph.h>
//#include <iostream>
//void test();
//-------TEST-------



/*  Declare Windows procedure  */
//LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
//TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

int WINAPI WinMain (HINSTANCE /*hThisInstance*/,
                     HINSTANCE /*hPrevInstance*/,
                     LPSTR /*lpszArgument*/,
                     int nCmdShow)
{
//    HWND hwnd;               /* This is the handle for our window */
//    MSG messages;            /* Here messages to the application are saved */
//    WNDCLASSEX wincl;        /* Data structure for the windowclass */
//
//    /* The Window structure */
//    wincl.hInstance = hThisInstance;
//    wincl.lpszClassName = szClassName;
//    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
//    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
//    wincl.cbSize = sizeof (WNDCLASSEX);
//
//    /* Use default icon and mouse-pointer */
//    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
//    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
//    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
//    wincl.lpszMenuName = NULL;                 /* No menu */
//    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
//    wincl.cbWndExtra = 0;                      /* structure or the window instance */
//    /* Use Windows's default colour as the background of the window */
//    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
//
//    /* Register the window class, and if it fails quit the program */
//    if (!RegisterClassEx (&wincl))
//        return 0;
//
//    /* The class is registered, let's create the program*/
//    hwnd = CreateWindowEx (
//           0,                   /* Extended possibilites for variation */
//           szClassName,         /* Classname */
//           _T("Code::Blocks Template Windows App"),       /* Title Text */
//           WS_OVERLAPPEDWINDOW, /* default window */
//           CW_USEDEFAULT,       /* Windows decides the position */
//           CW_USEDEFAULT,       /* where the window ends up on the screen */
//           544,                 /* The programs width */
//           375,                 /* and height in pixels */
//           HWND_DESKTOP,        /* The window is a child-window to desktop */
//           NULL,                /* No menu */
//           hThisInstance,       /* Program Instance handler */
//           NULL                 /* No Window Creation data */
//           );
//
//    /* Make the window visible on the screen */
//    ShowWindow (hwnd, nCmdShow);




//-------TEST-------
//test(hwnd);
//-------TEST-------

    MainWindow win;

    if (!win.Create("Lexi", WS_OVERLAPPEDWINDOW))
    {
        std::cerr << "Can't create window" << '\n';
        return 0;
    }

    ShowWindow(win.Window(), nCmdShow);

    MSG messages;
    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

//LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    switch (message)                  /* handle the messages */
//    {
//        case WM_PAINT:
//            {
//                PAINTSTRUCT ps;
//                HDC hdc;
//                hdc = BeginPaint(hwnd, &ps);  //ask windows for the Context - use this method when dealing with WM_PAINT messages
//                TextOut(hdc, 0,0, _T("Hello World"),11); //put some text on the window client area.
//                TextOut(hdc, 0,30, TEXT("Hello World"),11); //put some text on the window client area.
//
//                //FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW + 1));
//
//                Window * w = new Window(hdc);
//                Glyph * c = new CharGlyph('A');
//                c->Draw(w);
//                delete c;
//                delete w;
//                std::cerr << "error";
//
//                EndPaint(hwnd, &ps); //Always end a response to WM_PAINT like this
//            }
//            //MessageBox(hwnd, "text", "title", MB_OK);
//            break;
//        case WM_SIZE:
//            {
//                //int width = LOWORD(lParam);  // Macro to get the low-order word.
//                //int height = HIWORD(lParam); // Macro to get the high-order word.
//                // Respond to the message:
//                //OnSize(hwnd, (UINT)wParam, width, height); // Handle resizing void OnSize(HWND hwnd, UINT flag, int width, int height);
//            }
//            break;
//        case WM_DESTROY:
//            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
//            break;
//        default:                      /* for messages that we don't deal with */
//            return DefWindowProc (hwnd, message, wParam, lParam);
//    }
//
//    return 0;
//}

//void test()
//{
//    Glyph * g1 = new Glyph();
//    Glyph * g2 = new Glyph();
//    Glyph * g3 = new Glyph();
//    CompositeGlyph * row1 = new CompositeGlyph();
//    row1->Insert(g1, 0);
//    row1->Insert(g2, 1);
//    CompositeGlyph * row2 = new CompositeGlyph();
//    row2->Insert(g3, 0);
//    CompositeGlyph * page = new CompositeGlyph();
//    page->Insert(row1, 0);
//    page->Insert(row2, 1);
//    page->Remove(row1);
//    MessageBox(0, "text", "title", MB_OK);
//}