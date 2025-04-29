#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>

using namespace std;

// 1. Класс Shape с функцией reflect()
class Shape {
public:
    virtual void reflect(double axisX, double axisY) = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double x, y, radius;
public:
    Circle(double x, double y, double r) : x(x), y(y), radius(r) {
        if (r <= 0) throw invalid_argument("Radius must be positive");
    }
    void reflect(double axisX, double axisY) override {
        if (isnan(axisX) || isnan(axisY))
            throw invalid_argument("Reflection axis cannot be NaN");
        x = 2 * axisX - x;
        y = 2 * axisY - y;
    }
};

class Rectangle : public Shape {
    double x1, y1, x2, y2;
public:
    Rectangle(double x1, double y1, double x2, double y2)
        : x1(x1), y1(y1), x2(x2), y2(y2) {
        if (x1 >= x2 || y1 >= y2)
            throw invalid_argument("Invalid rectangle coordinates");
    }
    void reflect(double axisX, double axisY) override {
        if (isinf(axisX) || isinf(axisY))
            throw invalid_argument("Reflection axis cannot be infinite");
        double temp;
        temp = 2 * axisX - x1; x1 = 2 * axisX - x2; x2 = temp;
        temp = 2 * axisY - y1; y1 = 2 * axisY - y2; y2 = temp;
    }
};

// 2. Класс FileReader с функцией read()
class FileReader {
public:
    virtual string read(const string& filename) = 0;
    virtual ~FileReader() = default;
};

class TextFileReader : public FileReader {
public:
    string read(const string& filename) override {
        ifstream file(filename);
        if (!file.is_open())
            throw runtime_error("Failed to open text file: " + filename);
        string content((istreambuf_iterator<char>(file)),
            istreambuf_iterator<char>());
        if (content.empty())
            throw runtime_error("Text file is empty: " + filename);
        return content;
    }
};

class BinaryFileReader : public FileReader {
public:
    string read(const string& filename) override {
        ifstream file(filename, ios::binary);
        if (!file.is_open())
            throw runtime_error("Failed to open binary file: " + filename);
        file.seekg(0, ios::end);
        size_t size = file.tellg();
        if (size == 0)
            throw runtime_error("Binary file is empty: " + filename);
        string content(size, '\0');
        file.seekg(0);
        file.read(&content[0], size);
        return content;
    }
};

// 3. Класс Shape с функцией getArea()
class AreaShape {
public:
    virtual double getArea() const = 0;
    virtual ~AreaShape() = default;
};

class Ellipse : public AreaShape {
    double a, b;
public:
    Ellipse(double a, double b) : a(a), b(b) {
        if (a <= 0 || b <= 0)
            throw invalid_argument("Semi-axes must be positive");
    }
    double getArea() const override { return 3.14159 * a * b; }
};

class Square : public AreaShape {
    double side;
public:
    Square(double s) : side(s) {
        if (s <= 0) throw invalid_argument("Side must be positive");
    }
    double getArea() const override { return side * side; }
};

// 4. Класс EmailService с функцией sendEmail()
class EmailService {
public:
    virtual void sendEmail(const string& to, const string& subject,
        const string& body) = 0;
    virtual ~EmailService() = default;
};

class SMTPService : public EmailService {
public:
    void sendEmail(const string& to, const string& subject,
        const string& body) override {
        if (to.empty() || to.find('@') == string::npos)
            throw invalid_argument("Invalid recipient email");
        if (subject.empty())
            throw invalid_argument("Email subject cannot be empty");
        bool smtpAvailable = false; // имитация
        if (!smtpAvailable)
            throw runtime_error("SMTP server unavailable");
        cout << "Email sent via SMTP to: " << to << endl;
    }
};

class APIService : public EmailService {
public:
    void sendEmail(const string& to, const string& subject,
        const string& body) override {
        if (body.empty())
            throw invalid_argument("Email body cannot be empty");
        bool apiAvailable = false; // имитация
        if (!apiAvailable)
            throw runtime_error("Email API unavailable");
        cout << "Email sent via API to: " << to << endl;
    }
};

// 5. Класс Game с функцией endGame()
class Game {
protected:
    bool isActive;
public:
    Game() : isActive(false) {}
    virtual void endGame() = 0;
    virtual ~Game() = default;
};

class ChessGame : public Game {
public:
    ChessGame() { isActive = true; }
    void endGame() override {
        if (!isActive) throw runtime_error("Chess game is not active");
        isActive = false;
        cout << "Chess game ended" << endl;
    }
};

class FootballGame : public Game {
public:
    FootballGame() { isActive = true; }
    void endGame() override {
        if (!isActive) throw runtime_error("Football game is not active");
        isActive = false;
        cout << "Football game ended" << endl;
    }
};

// 6. Класс Shape с функцией getVertices()
class VertexShape {
public:
    virtual vector<pair<double, double>> getVertices() const = 0;
    virtual ~VertexShape() = default;
};

class Triangle : public VertexShape {
    double x1, y1, x2, y2, x3, y3;
public:
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {
        double area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;
        if (area == 0) throw invalid_argument("Invalid triangle vertices");
    }
    vector<pair<double, double>> getVertices() const override {
        return { {x1, y1}, {x2, y2}, {x3, y3} };
    }
};

class Pentagon : public VertexShape {
    vector<pair<double, double>> vertices;
public:
    Pentagon(const vector<pair<double, double>>& verts) : vertices(verts) {
        if (verts.size() != 5)
            throw invalid_argument("Pentagon must have 5 vertices");
        // Проверка на выпуклость
        bool sign = false;
        for (size_t i = 0; i < 5; i++) {
            double cross = (verts[(i + 1) % 5].first - verts[i].first) *
                (verts[(i + 2) % 5].second - verts[(i + 1) % 5].second) -
                (verts[(i + 1) % 5].second - verts[i].second) *
                (verts[(i + 2) % 5].first - verts[(i + 1) % 5].first);
            if (i == 0) sign = cross > 0;
            else if ((cross > 0) != sign)
                throw invalid_argument("Pentagon vertices must be convex");
        }
    }
    vector<pair<double, double>> getVertices() const override {
        return vertices;
    }
};

// 7. Класс Session с функцией startSession()
class Session {
protected:
    bool isActive;
public:
    Session() : isActive(false) {}
    virtual void startSession() = 0;
    virtual ~Session() = default;
};

class UserSession : public Session {
public:
    void startSession() override {
        if (isActive) throw runtime_error("User session already active");
        isActive = true;
        cout << "User session started" << endl;
    }
};

class AdminSession : public Session {
public:
    void startSession() override {
        if (isActive) throw runtime_error("Admin session already active");
        isActive = true;
        cout << "Admin session started" << endl;
    }
};

// 8. Класс Shape с функцией getColor()
class ColoredShape {
protected:
    string color;
public:
    ColoredShape(const string& col) : color(col) {
        if (col.empty()) throw invalid_argument("Color cannot be empty");
    }
    virtual string getColor() const = 0;
    virtual ~ColoredShape() = default;
};

class ColoredCircle : public ColoredShape {
    double radius;
public:
    ColoredCircle(const string& col, double r) : ColoredShape(col), radius(r) {
        if (r <= 0) throw invalid_argument("Radius must be positive");
    }
    string getColor() const override {
        if (color == "transparent")
            throw runtime_error("Cannot get color of transparent circle");
        return color;
    }
};

class ColoredSquare : public ColoredShape {
    double side;
public:
    ColoredSquare(const string& col, double s) : ColoredShape(col), side(s) {
        if (s <= 0) throw invalid_argument("Side must be positive");
    }
    string getColor() const override {
        return color;
    }
};

// 9. Класс Logger с функцией log()
class Logger {
public:
    virtual void log(const string& message) = 0;
    virtual ~Logger() = default;
};

class FileLogger : public Logger {
    string filename;
public:
    FileLogger(const string& fn) : filename(fn) {
        if (fn.empty()) throw invalid_argument("Filename cannot be empty");
    }
    void log(const string& message) override {
        ofstream file(filename, ios::app);
        if (!file.is_open())
            throw runtime_error("Failed to open log file: " + filename);
        file << message << endl;
        if (file.fail())
            throw runtime_error("Failed to write to log file");
    }
};

class ConsoleLogger : public Logger {
public:
    void log(const string& message) override {
        if (message.empty())
            throw invalid_argument("Log message cannot be empty");
        cout << "LOG: " << message << endl;
    }
};

// 10. Класс DataProcessor с функцией processData()
class DataProcessor {
public:
    virtual void processData(const string& data) = 0;
    virtual ~DataProcessor() = default;
};

class CSVProcessor : public DataProcessor {
public:
    void processData(const string& data) override {
        if (data.empty())
            throw invalid_argument("CSV data cannot be empty");
        if (data.find(',') == string::npos)
            throw runtime_error("Invalid CSV format - no commas found");
        cout << "Processing CSV data" << endl;
    }
};

class JSONProcessor : public DataProcessor {
public:
    void processData(const string& data) override {
        if (data.empty())
            throw invalid_argument("JSON data cannot be empty");
        if (data.front() != '{' || data.back() != '}')
            throw runtime_error("Invalid JSON format - missing braces");
        cout << "Processing JSON data" << endl;
    }
};

int main() {
    try {
        // Тестирование классов
        Circle circle(0, 0, 5);
        circle.reflect(1, 1);

        TextFileReader textReader;
        string content = textReader.read("example.txt");

        Ellipse ellipse(3, 4);
        cout << "Ellipse area: " << ellipse.getArea() << endl;

        SMTPService smtp;
        smtp.sendEmail("test@example.com", "Hello", "Test message");

        ChessGame chess;
        chess.endGame();

        Triangle triangle(0, 0, 1, 0, 0, 1);
        auto vertices = triangle.getVertices();

        UserSession userSession;
        userSession.startSession();

        ColoredSquare square("red", 5);
        cout << "Square color: " << square.getColor() << endl;

        ConsoleLogger consoleLog;
        consoleLog.log("Test log message");

        JSONProcessor jsonProc;
        jsonProc.processData("{\"key\":\"value\"}");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}