#include "widget.hpp"

class Application;

#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

class Window
{
protected:
    int ww;
    int wh;
    Application* wparent;
    vector<Widget*> widgets;
public:
    Window(Application* wparent, int ww, int wh);
    virtual void show() = 0;
    virtual void handleMouse(event ev) = 0;
};

#endif // WINDOW_HPP_INCLUDED

#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

class Menu : public Window
{
private:
    Button* uj_jatek;
    Button* kilepes;
public:
    Menu(Application* wparent, int ww, int wh);
    void show() override;
    void handleMouse(event ev) override;
};
#endif // MENU_HPP_INCLUDED

/*
#ifndef JATEK_HPP_INCLUDED
#define JATEK_HPP_INCLUDED

class Jatek : public Window
{
private:
public:
    Jatek(Application* wparent, int ww, int wh);
    void show() override;
};
#endif // JATEK_HPP_INCLUDED

#ifndef CSATA_HPP_INCLUDED
#define CSATA_HPP_INCLUDED

class Csata : public Window
{
private:
public:
    Csata(Application* wparent, int ww, int wh);
    void show() override;
};
#endif // CSATA_HPP_INCLUDED*/
