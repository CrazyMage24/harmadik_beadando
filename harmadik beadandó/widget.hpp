#include "graphics.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;
using namespace genv;

class Window;

#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

class Widget
{
protected:
    int wix;
    int wiy;
    int wiw;
    int wih;
    Window* wiparent;
public:
    Widget(Window* wiparent, int wix, int wiy, int wiw, int wih);
    virtual void draw() = 0;
};
#endif // WIDGET_HPP_INCLUDED

#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

class Button : public Widget
{
protected:
    string szoveg;
public:
    Button(Window* wiparent, int wix, int wiy, int wiw, int wih);
    void draw() override;
    virtual void action() = 0;
};
#endif // BUTTON_HPP_INCLUDED

#ifndef UJJATEK_HPP_INCLUDED
#define UJJATEK_HPP_INCLUDED

class Ujjatek : public Button
{
public:
    Ujjatek(Window* wiparent, int wix, int wiy, int wiw, int wih) : Button(wiparent,wix,wiy,wiw,wih)
    {
        szoveg = "Új jatek";
    }

    void action()
    {
        //wiparent->focus
    }
};
#endif // UJJATEK_HPP_INCLUDED



