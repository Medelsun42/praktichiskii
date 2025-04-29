#include <iostream>
#include <vector>
using namespace std;

class Media {
public:
    virtual void play() const = 0;
    virtual ~Media() {}
};

class Audio : public Media {
public:
    void play() const override { cout << "���������� ������..." << endl; }
};

class Video : public Media {
public:
    void play() const override { cout << "���������� �����..." << endl; }
};

void mediaDemo() {
    vector<Media*> media = {
        new Audio(),
        new Video()
    };

    for (auto m : media) {
        m->play();
        delete m;
    }
}