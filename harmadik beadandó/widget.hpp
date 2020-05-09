#include "graphics.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <sstream>
#include <string>
#include <math.h>
#include <Windows.h>

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

    virtual void handleTimer() = 0;
    virtual void handleMouse(event ev,bool gep_ellen) = 0;
    virtual void handleKeys(event ev) = 0;
    virtual string getSelect() = 0;

    virtual void gepValaszt() = 0;

    virtual void action(bool gep_ellen) = 0;

    virtual void reset() = 0;
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
    void handleTimer() override;
    void handleMouse(event ev,bool gep_ellen) override;
    void handleKeys(event ev) override;
    string getSelect() override;
    void gepValaszt() override;
    void show();
    void action(bool gep_ellen) override;
    void reset() override;
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
    void handleTimer() override;
    void handleMouse(event ev,bool gep_ellen) override;
    void handleKeys(event ev) override;
    string getSelect() override;
    void gepValaszt() override;

    void show();
    void action(bool gep_ellen) override;

    void reset() override;
};
#endif // CUBE_HPP_INCLUDED


#ifndef MESSAGE_HPP_INCLUDED
#define MESSAGE_HPP_INCLUDED

class Message : public Widget
{
private:
    string m;
public:
    Message(Application* wiparent, int wix, int wiy, int wiw, int wih, string message);
    void handleTimer() override;
    void handleMouse(event ev,bool gep_ellen) override;
    void handleKeys(event ev) override;
    string getSelect() override;

    void gepValaszt() override;

    void action(bool gep_ellen) override;

    void reset() override;
    void show();
};

#endif // MESSAGE_HPP_INCLUDED
