#include <iostream>
using namespace std;

float input_radius ();
float area_of_circle (float r);

int main() {
    
    float r, areac;
    
    r = input_radius();
    
    areac = area_of_circle(r);
    
    cout<<"Area of circle = "<<areac;
    
    return 0;
}

float input_radius () {
    
    float radius;
    
    cout<<"Enter radius of circle: ";
    cin>>radius;
    
    return radius;
}


float area_of_circle (float r) {
    
    float area, pi = 3.142;
    
    area = pi*r*r;
    
    return area;
}

