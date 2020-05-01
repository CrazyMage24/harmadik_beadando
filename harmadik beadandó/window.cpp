#include "window.hpp"

Window::Window(Application* wparent, int ww, int wh)
{
    this->wparent=wparent;
    this->ww=ww;
    this->wh=wh;
}

Menu::Menu(Application* wparent, int ww, int wh) :  Window(wparent,ww,wh)
{
    uj_jatek = new Ujjatek(this,500,300,200,50);
    kilepes = new Kilepes(this,500,600,200,50);
    widgets.push_back(uj_jatek);
    widgets.push_back(kilepes);
}
void Menu::show()
{
    for(Widget* wi : widgets)
    {
        wi->draw();
    }
}

void Menu::handleMouse(event ev)
{
    if(ev.button == btn_left)
    {
        for(Widget* wi : widgets)
        {
            if(wi->is_selected(ev.pos_x,ev.pos_y))
            {
                wi->action();
            }
        }
    }
}

Jatek::Jatek(Application* wparent, int ww, int wh) :  Window(wparent,ww,wh)
{

}
void Jatek::show()
{

}

void Jatek::handleMouse(event ev)
{

}
/*
Csata::Csata(Application* wparent, int ww, int wh) :  Window(wparent,ww,wh)
{

}
void Csata::show()
{

}*/
