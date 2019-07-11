#include <string>
#include <vector>
#include <memory>

#include <unistd.h>
#include <curses.h>

class Entity
{
    void update(int ch) = 0;
    void draw(int ch) = 0;
};

class Scene
{
public:
    Scene(size_t cols, size_t rows) : cols_(cols), rows_(rows)
    {
        initscr();
        cbreak();
    }

    Scene(Scene &&o){}

    ~Scene()
    {
        endwin();
    }

    void run()
    {
        int c{};
        while( c = getch() != 'q' )
        {
            update();
            drawBG();
            drawSnake();
            usleep(200000);
        }
    }
private:
    size_t cols_;
    size_t rows_;
};

int main()
{
    Scene s(200,200);
    Scene r(s);
    r.run();
}

