

#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    srand(time(NULL));

    RenderWindow window(VideoMode( 1500, 900 ), L"Titul", Style::Default);


    //Точка
    VertexArray mypoint(Points, 10000);
    for (int i = 0; i < 10000; i++)
        mypoint[i].position = Vector2f(rand() % 1500, rand() % 900);

    // Линия отрезками
    VertexArray myLines(Lines, 40);
    for (int i = 0, y = 0; i < 40; i += 2, y += 10) {
        myLines[i].position = Vector2f(100, 100 + y);
        myLines[i + 1].position = Vector2f(500, 100 + y);
    }

    // Ломаная линия
    VertexArray myLinesStrip(LineStrip, 20);
    for (int i = 0, y = 0; i < 20; i += 2, y += 50) {
        myLinesStrip[i].position = Vector2f(600, 100 + y);
        myLinesStrip[i + 1].position = Vector2f(1200, 100 + y);
    }

    // Треугольники
    VertexArray myTriangles(Triangles, 9);
    myTriangles[0].position = Vector2f(150, 350);
    myTriangles[1].position = Vector2f(250, 250);
    myTriangles[2].position = Vector2f(350, 350);
    myTriangles[0].color = Color(255, 0, 74);
    myTriangles[1].color = Color(255, 0, 74);
    myTriangles[2].color = Color(255, 0, 74);

    myTriangles[3].position = Vector2f(400, 200);
    myTriangles[4].position = Vector2f(600, 300);
    myTriangles[5].position = Vector2f(400, 400);
    myTriangles[3].color = Color(153, 255, 70);
    myTriangles[4].color = Color(153, 255, 70);
    myTriangles[5].color = Color(153, 255, 70);

    myTriangles[6].position = Vector2f(600, 400);
    myTriangles[7].position = Vector2f(800, 100);
    myTriangles[8].position = Vector2f(800, 400);
    myTriangles[6].color = Color(255, 255, 0);
    myTriangles[7].color = Color(255, 255, 0);
    myTriangles[8].color = Color(255, 255, 0);

    // Набор соединённых треугольников
    VertexArray myTriangleStrip(TriangleStrip, 10);
    myTriangleStrip[0].position = Vector2f(100, 200);
    myTriangleStrip[1].position = Vector2f(100, 400);
    myTriangleStrip[2].position = Vector2f(300, 200);
    myTriangleStrip[0].color = Color(0, 181, 99);
    myTriangleStrip[1].color = Color(0, 181, 99);
    myTriangleStrip[2].color = Color(102, 0, 99);

    myTriangleStrip[3].position = Vector2f(300, 400);
    myTriangleStrip[4].position = Vector2f(500, 300);
    myTriangleStrip[5].position = Vector2f(500, 500);
    myTriangleStrip[3].color = Color(102, 0, 99);
    myTriangleStrip[4].color = Color(255, 255, 0);
    myTriangleStrip[5].color = Color(255, 255, 0);

    myTriangleStrip[6].position = Vector2f(700, 300);
    myTriangleStrip[7].position = Vector2f(700, 500);
    myTriangleStrip[8].position = Vector2f(900, 400);
    myTriangleStrip[9].position = Vector2f(900, 600);
    myTriangleStrip[6].color = Color(126, 221, 54);
    myTriangleStrip[7].color = Color(126, 221, 54);
    myTriangleStrip[8].color = Color(0, 0, 205);
    myTriangleStrip[9].color = Color(0, 0, 205);

    // Набор треугольников соединённых с центральной точкой
    VertexArray myTriangleFan(TriangleFan, 12);
    myTriangleFan[0].position = Vector2f(250, 200);
    myTriangleFan[1].position = Vector2f(350, 250);
    myTriangleFan[2].position = Vector2f(300, 300);
    myTriangleFan[0].color = Color::Yellow;
    myTriangleFan[1].color = Color::White;
    myTriangleFan[2].color = Color::White;

    myTriangleFan[3].position = Vector2f(250, 315);
    myTriangleFan[4].position = Vector2f(200, 300);
    myTriangleFan[5].position = Vector2f(140, 250);
    myTriangleFan[3].color = Color::Red;
    myTriangleFan[4].color = Color::Red;
    myTriangleFan[5].color = Color::Magenta;

    myTriangleFan[6].position = Vector2f(130, 200);
    myTriangleFan[7].position = Vector2f(140, 150);
    myTriangleFan[8].position = Vector2f(200, 100);
    myTriangleFan[9].position = Vector2f(250, 80);
    myTriangleFan[10].position = Vector2f(300, 100);
    myTriangleFan[11].position = Vector2f(350, 150);
    myTriangleFan[6].color = Color::Magenta;
    myTriangleFan[7].color = Color::Green;
    myTriangleFan[8].color = Color::Green;
    myTriangleFan[9].color = Color::Cyan;
    myTriangleFan[10].color = Color::Cyan;
    myTriangleFan[11].color = Color::Yellow;

    // Набор неподключенных четырёхугольников.
    VertexArray myQuads(Quads, 12);
    myQuads[0].position = Vector2f(400, 300);
    myQuads[1].position = Vector2f(400, 200);
    myQuads[2].position = Vector2f(500, 200);
    myQuads[3].position = Vector2f(500, 300);
    myQuads[0].color = Color(255, 102, 255);
    myQuads[1].color = Color(255, 102, 255);
    myQuads[2].color = Color(255, 102, 255);
    myQuads[3].color = Color(255, 102, 255);

    myQuads[4].position = Vector2f(600, 300);
    myQuads[5].position = Vector2f(600, 200);
    myQuads[6].position = Vector2f(800, 200);
    myQuads[7].position = Vector2f(800, 300);
    myQuads[4].color = Color(102, 0, 99);
    myQuads[5].color = Color(102, 0, 99);
    myQuads[6].color = Color(102, 0, 99);
    myQuads[7].color = Color(102, 0, 99);

    myQuads[8].position = Vector2f(500, 500);
    myQuads[9].position = Vector2f(600, 400);
    myQuads[10].position = Vector2f(800, 400);
    myQuads[11].position = Vector2f(700, 500);
    myQuads[8].color = Color(255, 88, 0);
    myQuads[9].color = Color(255, 88, 0);
    myQuads[10].color = Color(255, 88, 0);
    myQuads[11].color = Color(255, 88, 0);

       while (window.isOpen())
    {
        
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) window.close();                
        }
        
        window.clear(Color::Blue);
       // window.draw(mypoint);
        //window.draw(myLines);
        //window.draw(myLinesStrip);
        window.draw(myTriangles);
        window.display();
    }
    return 0;
}




