#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <QString>

enum class MainWindowProps
{
    windowSizeW = 1250,
    windowSizeH = 700,
};

enum class Menus : int
{
    MainMenu = 0,
    BFS = 1,
    DFS = 2,
    Tree1 = 3,
    Tree2 = 4,
    AlgoMenu = 1,
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
    extern QString ImagesDirPath;
    extern QString BackgroundsDirPath;
    extern QString MainMenuBKGImage;
    extern QString MenusBKGImage;
    extern QString ButtonsDirPath;
    extern QString PauseButtonImage;
    extern QString PlayButtonImage;
    extern QString StopButtonImage;
    extern QString GraphsDirPath;
    extern QString SmallGraphImage;
    extern QString LargeGraphImage;
    extern QString AnalysisDirPath;
    extern QString PerfBFSImage1;
    extern QString PerfBFSImage2;
    extern QString PerfDFSImage1;
    extern QString PerfDFSImage2;
}

namespace VideosPaths
{
    extern QString VideosPath;
    extern QString BFSVideosPath;
}

enum class MainMenuProps
{
    // Layouts Properties
    VerLayoutW = ((int)MainWindowProps::windowSizeW / 10) * 4 - 130,
    VerLayoutH = (int)MainWindowProps::windowSizeH / 5 - 22,
    VerLayoutX = ((int)MainWindowProps::windowSizeW - 326) / 2 - 13,
    HorLayoutX = VerLayoutX,
    HorLayoutW = VerLayoutW,
    HorLayoutH = VerLayoutH / 2 - 2,
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
    settingsWidgetH = 255,
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
    SizeWidgetW = 125,
    SizeWidgetH = 67,

    DirectWidgetX = SizeWidgetX,
    DirectWidgetY = SizeWidgetY + SizeWidgetH + 7,
    DirectWidgetW = 162,
    DirectWidgetH = SizeWidgetH,

    // About text props
    AboutTextW = settingsWidgetW,
    AboutTextH = 248,
    AboutTextX = settingsWidgetX,
    AboutTextY = (int)MainWindowProps::windowSizeH - settingsWidgetH - AboutTextH - 44,
    AboutTitleTextX = AboutTextX + 83,
    AboutTitleTextY = AboutTextY + 4,

    // Similar text props
    SimilarTextW = 288,
    SimilarTextH = 296,
    SimilarTextX = (int)MainWindowProps::windowSizeW - SimilarTextW - 22,
    SimilarTextY = (int)MainWindowProps::windowSizeH - SimilarTextH - 22,
    SimilarTitleTextX = SimilarTextX + 60,
    SimilarTitleTextY = SimilarTextY + 10,

    // Animation speed props
    SliderTextX = 22 + settingsWidgetW + 222,
    SliderTextY = (int)MainWindowProps::windowSizeH - 75,
    SliderTextNumberX = SliderTextX + 139,
    SliderTextNumberY = SliderTextY + 2,
    SliderX = SliderTextX - 55,
    SliderY = SliderTextY + 28,
    SliderW = 270,
    SliderH = 25,

    // Animation controls props
    PlayButtonX = SliderX + SliderW + 15,
    PlayButtonY = SliderY,
    StopButtonX = PlayButtonX + 33,
    StopButtonY = PlayButtonY,

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

    // Performance analysis
    PerfWidgetW = 980,
    PerfWidgetH = 434,
    PerfImage1X = 18,
    PerfImage1Y = 18,
    PerfImage2X = PerfImage1X + 482 + 27,
    PerfImage2Y = PerfImage1Y,
};

enum class SizeRadioButtons
{
    SmallButton,
    LargeButton,
};

enum class DirectRadioButtons
{
    UndirectedButton,
    DirectedButton,
};

enum class BFSVertices
{
    A = 1,
    B = 2,
    C = 3,
    D = 4,
    E = 5,
};

enum class DFSVertices
{
    A = 1,
    B = 2,
    C = 3,
    D = 4,
    E = 5,
};

#endif // HELPERS_HPP
