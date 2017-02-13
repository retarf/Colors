#include <string.h>

#include "consoleinterface.h"

ConsoleInterface::ConsoleInterface()
{
    float TopLeftColor16bit = 0;
    float TopRightColor16bit = 0;
    float BottomLeftColor16bit = 0;
    float BottomRightColor16bit = 0;

    std::string name;

    std::cout << "Set Display Name: ";
    std::cin >> name;
    std::cout << std::endl;
    std::cout << "Set Top Left Color: ";
    std::cin >> TopLeftColor16bit;
    std::cout << "Set Top Right Color: ";
    std::cin >> TopRightColor16bit;
    std::cout << "Set Bottom Left Color: ";
    std::cin >> BottomLeftColor16bit;
    std::cout << "Set Bottom Right Color: ";
    std::cin >> BottomRightColor16bit;

    strcpy( string, name.c_str() );
    TopLeftColorRGB565 = Convert( TopLeftColor16bit );
    TopRightColorRGB565 = Convert( TopRightColor16bit );
    BottomLeftColorRGB565 = Convert( BottomLeftColor16bit );
    BottomRightColorRGB565 = Convert( BottomRightColor16bit );
}

std::map <char, float> ConsoleInterface::Convert(float color)
{
    std::map<char, float> rgb;

    rgb['r'] = 0;
    rgb['g'] = 0;
    rgb['b'] = 0;

    if ( color != 0 )
    {
        if ( color < 5 )
            rgb['b'] = ( color / 4 );
        if ( color >= 5 ) rgb['b'] = 1;
        if ( ( color >= 5 ) && ( color <= 10 ) )
        {
            rgb['g'] = ( ( color - 4 ) / 6 );
        }
        if ( color >= 11 )
        {
            rgb['g'] = 1;
            rgb['r'] = ( ( color - 10 ) / 5 );
        }
    }

    return rgb;
}

char* ConsoleInterface::getDisplayName()
{
    return string;
}

std::map <char, float> ConsoleInterface::getTopLeftColor()
{
    return TopLeftColorRGB565;
}

std::map <char, float> ConsoleInterface::getTopRightColor()
{
    return TopRightColorRGB565;
}

std::map <char, float> ConsoleInterface::getBottomLeftColor()
{
    return BottomLeftColorRGB565;
}

std::map <char, float> ConsoleInterface::getBottomRightColor()
{
    return BottomRightColorRGB565;
}
