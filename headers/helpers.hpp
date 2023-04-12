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
    BFS,
    DFS,
    Tree1,
    Tree2,
    Tree3,
};

namespace StylesPaths
{
    extern QString StylesPath;
    extern QString MainMenuButtonStyle;
    extern QString OneLineTextStyle;
    extern QString ComboBoxStyle;
    extern QString DimTextStyle;
    extern QString BoldDimTextStyle;
    extern QString SliderStyle;
    extern QString PseudocodeStyle;
    extern QString AboutTextStyle;
    extern QString AboutTitleStyle;
    extern QString SimilarTitleStyle;
    extern QString SimilarTextStyle;
    extern QString MenuStyle;
    extern QString CompTextStyle;
}

namespace TextsPaths
{
    extern QString TextsPath;
    extern QString BFSPseudocodePath;
    extern QString DFSPseudocodePath;
    extern QString AboutBFSPath;
    extern QString AboutDFSPath;
    extern QString SimilarAlgosPath;
    extern QString CompBFSPath;
    extern QString CompDFSPath;
}

namespace ImagesPaths
{
    extern QString ImagesPath;
    extern QString BackgroundsPath;
    extern QString MainMenuBKGImage;
    extern QString MenusBKGImage;
}

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

enum class AlgoMenuProps
{
    // Graph settings props
    settingsWidgetW = 240,
    settingsWidgetH = 284,
    settingsWidgetX = 22,
    settingsWidgetY = (int)MainWindowProps::windowSizeH - settingsWidgetH - 22,

    settingsTextX = 41,
    settingsTextY = 10,

    vertexTextX = 17,
    vertexTextY = settingsTextY + 40,

    VerticesComboBoxX = vertexTextX,
    VerticesComboBoxY = vertexTextY + 22,
    VerticesComboBoxW = 120,
    VerticesComboBoxH = 25,

    SizeWidgetX = VerticesComboBoxX - 9,
    SizeWidgetY = VerticesComboBoxY + 40,
    SizeWidgetW = 200,
    SizeWidgetH = 95,

    DirectWidgetX = SizeWidgetX,
    DirectWidgetY = SizeWidgetY + SizeWidgetH + 7,
    DirectWidgetW = SizeWidgetW,
    DirectWidgetH = 67,

    // Animation settings props
    SliderTextX = 500,
    SliderTextY = (int)MainWindowProps::windowSizeH - 75,

    SliderTextNumberX = SliderTextX + 139,
    SliderTextNumberY = SliderTextY + 2,

    SliderX = SliderTextX - 55,
    SliderY = SliderTextY + 28,
    SliderW = 270,
    SliderH = 25,

    // About text props
    AboutTextX = settingsWidgetX,
    AboutTextY = 126,
    AboutTextW = settingsWidgetW,
    AboutTextH = 248,
    AboutTitleTextX = AboutTextX + 83,
    AboutTitleTextY = AboutTextY + 6,

    // Similar text props
    SimilarTextW = 288,
    SimilarTextH = 296,
    SimilarTextX = (int)MainWindowProps::windowSizeW - SimilarTextW - 22,
    SimilarTextY = (int)MainWindowProps::windowSizeH - SimilarTextH - 22,
    SimilarTitleTextX = SimilarTextX + 60,
    SimilarTitleTextY = SimilarTextY + 10,

    // Complexities text props
    CompTextW = SimilarTextW,
    CompTextH = 108,
    CompTextX = (int)MainWindowProps::windowSizeW - CompTextW - 22,
    CompTextY = (int)MainWindowProps::windowSizeH - SimilarTextH - CompTextH - 42,
    CompTitleTextX = CompTextX + 79,
    CompTitleTextY = CompTextY + 8,

    // Pseudocode props
    CodeTitleTextX = (int)MainWindowProps::windowSizeW - 221,
    CodeTitleTextY = (int)MainWindowProps::windowSizeH - SimilarTextH - CompTextH - 250,
    CodeTextX = CodeTitleTextX - 89,
    CodeTextY = CodeTitleTextY + 30,
    CodeTextW = SimilarTextW,
    CodeTextH = 156,
};

enum class SizeRadioButtons
{
    SmallButton,
    MediumButton,
    LargeButton,
};

enum class DirectRadioButtons
{
    UndirectedButton,
    DirectedButton,
};


#endif // HELPERS_HPP
