#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <QString>

enum class MainWindowProps
{
    windowSizeW = 1150,
    windowSizeH = 700,
};

enum class Menus : int
{
    MainMenu,
    Tree1,
    Tree2,
    Tree3,
    DFS,
    BFS,
};

namespace StylesPaths
{
    extern QString StylesPath;
    extern QString MainMenuButtonStyle;
}

#endif // HELPERS_HPP
