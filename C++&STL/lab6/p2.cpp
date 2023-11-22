#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class Point {
public:
    double x;
    double y;
    int r;
    int g;
    int b;
    string name;

    Point(double x, double y, int r, int g, int b, string name)
        : x(x), y(y), r(r), g(g), b(b), name(std::move(name)) {}

    double getLuminance() const {
        return 0.3 * r + 0.59 * g + 0.11 * b;
    }
};

int main() {
    // Create list of color points
    list<Point> points = {
        {1, 2, 255, 1, 4, "p1"},
        {4, -6, 4, 1, 245, "p2"},
        {-5, 6, 5, 23, 255, "p3"},
        {-5, -52, 42, 12, 255, "p4"},
        {5, -2, 1, 2, 3, "p5"},
        {-6, -8, 12, 23, 255, "p6"},
        {1,1, 0, 4, 255, "p10000"},
    };

    cout << "del p10000\n";
    points.remove_if([](const Point& point) {
        return point.name.length() > 5;
    });
    
    for_each(points.begin(), points.end(),[](const Point &points){
        cout << ("name: ") << points.name << (" coords: (")<< points.x << "," << points.y<< ") \n";
    });

    size_t firstQuadrant = count_if(points.begin(), points.end(), [](const Point& point) {
        return point.x > 0 && point.y > 0;
    });
    size_t secondQuadrant = count_if(points.begin(), points.end(), [](const Point& point) {
        return point.x < 0 && point.y > 0;
    });
    size_t thirdQuadrant = count_if(points.begin(), points.end(), [](const Point& point) {
        return point.x < 0 && point.y < 0;
    });
    size_t fourthQuadrant = count_if(points.begin(), points.end(), [](const Point& point) {
        return point.x > 0 && point.y < 0;
    });

    cout << "\nPoints in each quadrant:\n";
    cout << "1st quadrants: " << firstQuadrant << " points\n";
    cout << "2nd quadrants: " << secondQuadrant << " points\n";
    cout << "3rd quadrants: " << thirdQuadrant << " points\n";
    cout << "4th quadrants: " << fourthQuadrant << " points\n";

    points.sort([](const Point& a, const Point& b) {
        return a.getLuminance() < b.getLuminance();
    });

    cout << "\nsort by luminance:\n";
    for_each(points.begin(), points.end(),[](const Point &points){
        cout << ("name: ") << points.name << (" luminance:")<< points.getLuminance() << "\n";
    });

    list<Point> darkPoints;
    copy_if(points.begin(), points.end(), back_inserter(darkPoints),[](const Point& point){
        return point.getLuminance() < 64;
    });
    
    cout << "\nDark points with luminance below 64:\n";
    for_each(darkPoints.begin(), darkPoints.end(),[](const Point &darkPoint){
        cout << ("name: ") << darkPoint.name << (" luminance:")<< darkPoint.getLuminance() << "\n";
    });
    return 0;
}