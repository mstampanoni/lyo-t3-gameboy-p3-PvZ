#include "pch.h"
#include "TextManager.h"
#include <iostream>

namespace {
    static TextManager* instance = nullptr;
}

TextManager::TextManager()
{
}

TextManager* TextManager::instantiate()
{
    if (!instance)
    {
        instance = new TextManager();
        return instance;
    }
    return nullptr;
}

TextManager* TextManager::getInstance()
{
    return instance;
}

void TextManager::initText()
{
    if (!font.loadFromFile("../../../font/Hack-Regular.ttf"))
    {
        std::cerr << "Failed to load font" << std::endl;
    }

    text.setFont(font);

    text.setFillColor(sf::Color::White);

    text.setCharacterSize(20);

}
