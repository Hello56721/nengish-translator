#include <string_view>
#include <string>
#include <sstream>
//#include <iostream>

#include "TextToNengish.hpp"

static std::string byteToBinaryImpl(uint8_t pByte)
{
    std::string result;
    uint8_t byte = pByte;
    
    for (uint8_t i = 0; i < 8; i++)
    {
        uint8_t thisBitInt = byte % 2;
        char thisBit = ' ';
        
        if (thisBitInt == 1)
        {
            thisBit = '1';
        }
        else if (thisBitInt == 0)
        {
            thisBit = '0';
        }
        
        byte = byte / 2;
        result = thisBit + result;
    }
    
    return result;
}

static std::string byteToNengishBight(uint8_t byte)
{
    std::string binaryString = byteToBinaryImpl(byte);
    std::stringstream result;
    
    for (char character: binaryString)
    {
        if (character == '1')
        {
            result << "UwU. ";
        } else if (character == '0')
        {
            result << "OwO. ";
        }
    }
    
    return result.str();
}

std::string textToNengish(std::string_view text)
{
    std::stringstream result;
    
    for (char character: text)
    {
        uint8_t byte = character;
        result << byteToNengishBight(byte) << "\n";
    }
    
    return result.str();
}

// Uncomment to use this main function instead of the primary one for testing purposes
//#define USE_THIS_MAIN

#ifdef USE_THIS_MAIN

int main()
{
    std::cout << "\"Hello\" in Nengish: \n" << textToNengish("Hello") << "\n";
}
#endif