#include "widget.hpp"

Widget::Widget(Window* wiparent, int wix, int wiy, int wiw, int wih)
{
    this->wiparent=wiparent;
    this->wix=wix;
    this->wiy=wiy;
    this->wiw=wiw;
    this->wih=wih;
}

Button::Button(Window* wiparent, int wix, int wiy, int wiw, int wih) : Widget(wiparent,wix,wiy,wiw,wih)
{
}
void Button::draw()
{
    gout << color(120,120,120) << move_to(wix-5,wiy-5) << box(wiw+10,wih+10);
    gout << color(200,200,200) << move_to(wix,wiy) << box(wiw,wih);

    int sz_offset = gout.twidth(szoveg) / 2;
    gout << color(0,0,0) << move_to(wix+wiw/2-sz_offset,wiy+wih/2+5) << text(szoveg);
}

