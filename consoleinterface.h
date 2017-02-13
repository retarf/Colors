#ifndef CONSOLEINTERFACE_H
#define CONSOLEINTERFACE_H

#include <map>
#include <iostream>

class ConsoleInterface
{
public:
    ConsoleInterface();

    char* getDisplayName();
    std::map <char, float> getTopLeftColor();
    std::map <char, float> getTopRightColor();
    std::map <char, float> getBottomLeftColor();
    std::map <char, float> getBottomRightColor();


private:
    char string[100];

    std::map <char, float> TopLeftColorRGB565;
    std::map <char, float> TopRightColorRGB565;
    std::map <char, float> BottomLeftColorRGB565;
    std::map <char, float> BottomRightColorRGB565;

    std::map <char, float> Convert(float);
};

#endif // CONSOLEINTERFACE_H
