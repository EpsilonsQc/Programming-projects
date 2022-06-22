#ifndef Color_h
#define Color_h

struct Color
{
public:
    Color(){}
    Color(int r, int g, int b): r(r), g(g), b(b) {}
    int r;
    int g;
    int b;
    
    static Color Black;
    static Color Yellow;
    static Color Blue;
    static Color White;
    static Color Orange;
    static Color Gray;
    static Color Red;
};

#endif /* Color_h */
