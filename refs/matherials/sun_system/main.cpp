

#include <SFML/Graphics.hpp>
#include<math.h>

using namespace sf;
using namespace std;

class Planets 
{
    int x0 = 0, y0 = 0, rad = 0, x = 0, y = 0, vector = 1;
    double a = 0;
    const double PI = acos(-1.0);
public:
    Planets(int startx,int starty, int r, int v);
    Planets(int r,int v);
    int getx();
    int gety();
    void move(double s);
    void setposition(int startx,int starty);
};

int main()
{
    srand(time(NULL));
    
    RenderWindow window(VideoMode(1500, 900), L"Солнечная система", Style::Default);
    
    // Устанавливаем иконку в главное окно приложения
    Image icon;
    if (!icon.loadFromFile("sys.png"))
    {
        return 32;
    }
    window.setIcon(48, 48, icon.getPixelsPtr());
    
    window.setVerticalSyncEnabled(true);

    VertexArray stars(Points,500);
    for (int i = 0; i < 490; i++) 
    {
        stars[i].color = Color::White;
        stars[i].position = Vector2f(rand()%1500,rand()%900);
    
    }
    CircleShape sun(100.f), merk(1.f), vener(6.f), earth(10), mars(4), moon(4);

    sun.setPosition(750,450);
    sun.setOrigin(100,100);
    Texture texsun;
    texsun.loadFromFile("sun.png");
    sun.setTexture(&texsun);

    Texture texearth;
    texearth.loadFromFile("erd.png");
    earth.setTexture(&texearth);
    earth.setOrigin(5,5);
    vener.setFillColor(Color::Yellow);
    mars.setFillColor(Color::Red);
    merk.setFillColor(Color::Red);

    Texture texmoon;
    texmoon.loadFromFile("luna.png");
    moon.setTexture(&texmoon);

    Planets merkxy(750,450,150,-1), venerxy(750,450,200,-1), marsxy(750,450,300,-1), earthxy(750,450,250,-1);

    Planets moonxy(30,-1);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event)) if (event.type == Event::Closed)window.close();
               
        merkxy.move(1);
        merk.setPosition(merkxy.getx(), merkxy.gety());
        venerxy.move(0.5);
        vener.setPosition(venerxy.getx(), venerxy.gety());
        marsxy.move(1.5);
        mars.setPosition(marsxy.getx(), marsxy.gety());
        earthxy.move(0.8);
        earth.setPosition(earthxy.getx(), earthxy.gety());
        moonxy.setposition(earth.getPosition().x, earth.getPosition().y);
        moonxy.move(2);
        moon.setPosition(moonxy.getx(), moonxy.gety());
        sun.rotate(-1);
               
        window.clear();
        window.draw(stars);
        window.draw(sun);
        window.draw(merk);
        window.draw(vener);
        window.draw(earth);
        window.draw(mars);
        window.draw(moon);

        window.display();
    }
    return 0;
}

Planets::Planets(int startx, int starty, int r, int v)
{
    if (v > 1) v = 1;
    if (v < -1 || v == 0) v = -1;
    vector = v;
    x0 = startx;
    y0 = starty;
    rad = r;

}

Planets::Planets(int r, int v)
{
    if (v > 1) v = 1;
    if (v < -1 || v == 0) v = -1;
    vector = v;
    rad = r;
}

int Planets::getx()
{
    return x;
}

int Planets::gety()
{
    return y;
}

void Planets::move(double s)
{
    a += s;
    if (a > 360) a = 0;
    x = x0 + round(rad*cos(a*PI/180));
    y = y0 + round(rad * sin(a * PI / 180))*vector;
}

void Planets::setposition(int startx, int starty)
{
    x0 = startx;
    y0 = starty;
}
