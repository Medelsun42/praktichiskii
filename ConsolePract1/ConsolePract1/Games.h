#include <iostream>
#include <vector>
using namespace std;

class Game {
public:
    virtual void play() const = 0;
    virtual ~Game() {}
};

class BoardGame : public Game {
public:
    void play() const override { cout << "Настольная игра" << endl; }
};

class VideoGame : public Game {
public:
    void play() const override { cout << "Компьютерная игра" << endl; }
};

void gameDemo() {
    vector<Game*> games = {
        new BoardGame(),
        new VideoGame()
    };

    for (auto g : games) {
        g->play();
        delete g;
    }
}