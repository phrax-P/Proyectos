#include "EventWindow.h"
char * foo;

EventWindow::EventWindow(int width, int height):Fl_Window(width, height, "")
{
    label("Demo Window for CS 559");
    show();
}

int EventWindow::handle(int event)
{
    switch (event)
    {
        case FL_PUSH:
        case FL_RELEASE:
        case FL_DRAG:
        case FL_MOVE:
            return handle_mouse(event,Fl::event_button(), Fl::event_x(),Fl::event_y());

        case FL_FOCUS:
            label ("Gained focus");
            damage(1);
            return 1;
        case FL_UNFOCUS:
            label ("Lost focus");
            damage(1);
            return 1;
        case FL_KEYBOARD:
            return handle_key(event,Fl::event_key());
        default:
            return Fl_Window::handle(event);
        };
}
int EventWindow::handle_mouse(int event, int button, int x, int y)
{
    if (foo)
        delete[] foo;
        foo = new char[100];
    int ret = 0;
    switch ( button )
    {
        case 1: // LMB
        ret = 1;
        // Based on the action, print the action and
        // coordinates where it occurred.
        if ( event == FL_PUSH )
        {
            sprintf(foo,"LMB PUSH ( %d , %d )",x,y);
            label(foo);
            damage(1);
        }

        else if (event == FL_DRAG )
        {
            sprintf(foo,"LMB Drag ( %d , %d )",x,y);
            label(foo);
            damage(1);
        }

        else if ( event == FL_RELEASE )
        {
            sprintf(foo,"LMB Release ( %d , %d )",x,y);
            label(foo);
            damage(1);
        }
        break;
    case 2: // MMB
        ret = 1;
        // Based on the action, print the action and
        // coordinates where it occurred.
        if ( event == FL_PUSH )
            {
            sprintf(foo,"MMB Push ( %d , %d )",x,y);
            label(foo);
            damage(1);
            }

        else if (event == FL_DRAG )
        {
            sprintf(foo,"MMB Drag ( %d , %d )",x,y);
            label(foo);
            damage(1);

        }

        else if ( event == FL_RELEASE )
        {

            sprintf(foo,"MMB Release ( %d , %d )",x,y);
            label(foo);
            damage(1);
        }
        break;

    case 3: // RMB
        ret = 1;

        // Based on the action, print the action and

        // coordinates where it occurred.

        if ( event == FL_PUSH )
        {
            sprintf(foo,"RMB Push ( %d , %d )",x,y);
            label(foo);
            damage(1);
        }

        else if (event == FL_DRAG )
        {
            sprintf(foo,"RMB Drag ( %d , %d )",x,y);
            label(foo);
            damage(1);
        }

        else if ( event == FL_RELEASE )
        {
            sprintf(foo,"RMB Release ( %d , %d )",x,y);
            label(foo);
            damage(1);
        }
        break;

    }
    return ret;
}
int EventWindow::handle_key(int event, int key)
{
    switch(key)
    {
    case 'c':
        label("Letra c fue presionada");
        damage(1);
        return 1;
    default:
        label("NOthing to do!");
        damage(1);
        printf("nothing to do\n");
        return 1;
    }
}
