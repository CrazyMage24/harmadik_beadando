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

class Application;

#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

class Widget
{
protected:
    int wix;
    int wiy;
    int wiw;
    int wih;
    Application* wiparent;
    bool folotte;
public:
    Widget(Application* wiparent, int wix, int wiy, int wiw, int wih);
    bool is_selected(int pos_x, int pos_y);

    virtual void handleTimer(event ev) = 0;
    virtual void handleMouse(event ev) = 0;
    virtual void handleKeys(event ev) = 0;
    virtual string getSelect() = 0;
};
#endif // WIDGET_HPP_INCLUDED

#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

class Button : public Widget
{
protected:
    string szoveg;
public:
    Button(Application* wiparent, int wix, int wiy, int wiw, int wih, string szoveg);
    void handleTimer(event ev) override;
    void handleMouse(event ev) override;
    void handleKeys(event ev) override;
    string getSelect() override;

    void show();
    void action();
};
#endif // BUTTON_HPP_INCLUDED

#ifndef CUBE_HPP_INCLUDED
#define CUBE_HPP_INCLUDED

class Cube : public Widget
{
private:
    /// i oszlop, j sor
    int i;
    int j;
    static int Count;
    bool marked;
    string select;
public:
    Cube(Application* wiparent, int wix, int wiy, int wiw, int wih,int i, int j);
    void handleTimer(event ev) override;
    void handleMouse(event ev) override;
    void handleKeys(event ev) override;
    string getSelect() override;

    void show();
    void action();

};
#endif // CUBE_HPP_INCLUDED



