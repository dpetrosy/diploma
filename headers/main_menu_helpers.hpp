#ifndef MAIN_MENU_HELPERS_HPP
#define MAIN_MENU_HELPERS_HPP

#include "helpers.hpp"

enum class MainMenuProps
{
    // Layouts Properties
    VerLayoutW = ((int)MainWindowProps::windowSizeW / 10) * 4 - 115,
    VerLayoutH = (int)MainWindowProps::windowSizeH / 4,
    VerLayoutX = ((int)MainWindowProps::windowSizeW - 326) / 2 - 13,
    HorLayoutX = VerLayoutX,
    HorLayoutW = VerLayoutW,
    HorLayoutH = VerLayoutH / 3,
    VerLayoutY = ((int)MainWindowProps::windowSizeH - 260) / 2 - 25,
    HorLayoutY = VerLayoutY + VerLayoutH - 8,
    QuitButtonX = VerLayoutX + 10,
    QuitButtonY = HorLayoutY + HorLayoutH + 3,
    QuitButtonW = VerLayoutW - 20,
    QuitButtonH = HorLayoutH - 20,

    // PushButtons Properties
    VerLayoutButtonsW = 0,
    VerLayoutButtonsH = 44,
    VerLayoutButtonsFont = 16,
    HorLayoutButtonsW = VerLayoutButtonsW,
    HorLayoutButtonsH = VerLayoutButtonsH,
    HorLayoutButtonsFont = VerLayoutButtonsFont,
};

#endif // MAIN_MENU_HELPERS_HPP
