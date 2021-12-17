#ifndef EVENTWINDOW_H
#define EVENTWINDOW_H
#include <FL/Fl_Window.H>
#include <FL/Fl.H>
#include <stdio.h>
class EventWindow: public Fl_Window
{
private:
    int handle_mouse(int event, int button, int x, int y);
    int handle_key(int event,int key);
public:
    EventWindow(int width, int height);
    int handle(int e);
};



#endif // EVENTWINDOW_H
