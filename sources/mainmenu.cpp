#include "mainmenu.hpp"
#include "mainwindow.hpp"
#include "main_menu_helpers.hpp"
#include "utils.hpp"

MainMenu::MainMenu(MainWindow* mainWindow, QWidget* parent) :
    QWidget(parent)
{
    // Init class members
    init();

    // Make MainMenu
    makeMainMenu(mainWindow);
}

MainMenu::~MainMenu()
{
    delete _Tree1Button;
    delete _Tree2Button;
    delete _Tree3Button;
    delete _BFSButton;
    delete _DFSButton;
    delete _QuitButton;
    delete _verLayout;
    delete _horLayout;
    delete _widgetForVerLayout;
    delete _widgetForHorLayout;
}

// Init
void MainMenu::init()
{
    // Widgets
    _widgetForVerLayout = new QWidget(this);
    _widgetForHorLayout = new QWidget(this);

    // Layouts
    _verLayout = new QVBoxLayout(_widgetForVerLayout);
    _horLayout = new QHBoxLayout(_widgetForHorLayout);

    // Push Buttons
    _Tree1Button = new QPushButton();
    _Tree2Button = new QPushButton();
    _Tree3Button = new QPushButton();
    _BFSButton = new QPushButton();
    _DFSButton = new QPushButton();
    _QuitButton = new QPushButton(this);
}

// Public util functions
//void MainMenu::makeMenuBeforeSwitch(SettingsMenu* settingMenuWidget, MainWindow* mainWindow)
//{
//    // set bkg image
//    mainWindow->setBackgroundImage(settingMenuWidget->getData().bkgImageStr);

//    if (gLanguage == Languages::Armenian)
//    {
//        _PVPButton->setText("Խաղալ ընկերոջ հետ");
//        _PVCButton->setText("Խաղալ համակարգչի հետ");
//        _InstrButton->setText("Կանոններ");
//        _SettingsButton->setText("Կարգավորումներ");
//        _QuitButton->setText("Լքել");
//        _versionTextLabel->setText("Տարբերակ: 1.2.4");
//        _versionTextLabel->move((int)MainMenuProps::VersionTextLabelX - 20, (int)MainMenuProps::VersionTextLabelY);
//    }
//    else if (gLanguage == Languages::Russian)
//    {
//        _PVPButton->setText("Сыграть с Другом");
//        _PVCButton->setText("Сыграть с Компьютером");
//        _InstrButton->setText("Правила");
//        _SettingsButton->setText("Настройки");
//        _QuitButton->setText("Выйти");
//        _versionTextLabel->setText("Версия: 1.2.4");
//        _versionTextLabel->move((int)MainMenuProps::VersionTextLabelX, (int)MainMenuProps::VersionTextLabelY);
//    }
//    else // English US
//    {
//        _PVPButton->setText("Player vs Player");
//        _PVCButton->setText("Player vs Computer");
//        _InstrButton->setText("Instructions");
//        _SettingsButton->setText("Settings");
//        _QuitButton->setText("Quit");
//        _versionTextLabel->setText("Version: 1.2.4");
//        _versionTextLabel->move((int)MainMenuProps::VersionTextLabelX, (int)MainMenuProps::VersionTextLabelY);
//    }
//}

// Private util functions
void MainMenu::makeMainMenu(MainWindow* mainWindow)
{
    // Set buttons sizes
    setPushButtonSize(_Tree1Button, (int)MainMenuProps::VerLayoutButtonsW, (int)MainMenuProps::VerLayoutButtonsH);
    setPushButtonSize(_Tree2Button, (int)MainMenuProps::VerLayoutButtonsW, (int)MainMenuProps::VerLayoutButtonsH);
    setPushButtonSize(_Tree3Button, (int)MainMenuProps::VerLayoutButtonsW, (int)MainMenuProps::VerLayoutButtonsH);
    setPushButtonSize(_BFSButton, (int)MainMenuProps::HorLayoutButtonsW, (int)MainMenuProps::HorLayoutButtonsH);
    setPushButtonSize(_DFSButton, (int)MainMenuProps::HorLayoutButtonsW, (int)MainMenuProps::HorLayoutButtonsH);
    setPushButtonSize(_QuitButton, (int)MainMenuProps::VerLayoutButtonsW, (int)MainMenuProps::VerLayoutButtonsH);

    // Set buttons texts
    _Tree1Button->setText("Tree1");
    _Tree2Button->setText("Tree2");
    _Tree3Button->setText("Tree3");
    _BFSButton->setText("BFS");
    _DFSButton->setText("DFS");
    _QuitButton->setText("Quit");

    // Set buttons fonts
    setPushButtonFont(_Tree1Button, (int)MainMenuProps::VerLayoutButtonsFont);
    setPushButtonFont(_Tree2Button, (int)MainMenuProps::VerLayoutButtonsFont);
    setPushButtonFont(_Tree3Button, (int)MainMenuProps::VerLayoutButtonsFont);
    setPushButtonFont(_BFSButton, (int)MainMenuProps::HorLayoutButtonsFont);
    setPushButtonFont(_DFSButton, (int)MainMenuProps::HorLayoutButtonsFont);
    setPushButtonFont(_QuitButton, (int)MainMenuProps::HorLayoutButtonsFont);

    // Set buttons style
    ::setStyleSheet(StylesPaths::MainMenuButtonStyle, _Tree1Button);
    ::setStyleSheet(StylesPaths::MainMenuButtonStyle, _Tree2Button);
    ::setStyleSheet(StylesPaths::MainMenuButtonStyle, _Tree3Button);
    ::setStyleSheet(StylesPaths::MainMenuButtonStyle, _BFSButton);
    ::setStyleSheet(StylesPaths::MainMenuButtonStyle, _DFSButton);
    ::setStyleSheet(StylesPaths::MainMenuButtonStyle, _QuitButton);

    // Add buttons to layouts
    _verLayout->addWidget(_Tree1Button);
    _verLayout->addWidget(_Tree2Button);
    _verLayout->addWidget(_Tree3Button);
    _horLayout->addWidget(_BFSButton);
    _horLayout->addWidget(_DFSButton);

    // Set geometry for layouts and buttons
    QRect rect((int)MainMenuProps::VerLayoutX, (int)MainMenuProps::VerLayoutY, (int)MainMenuProps::VerLayoutW, (int)MainMenuProps::VerLayoutH);
    _widgetForVerLayout->setGeometry(rect);
    rect.setRect((int)MainMenuProps::HorLayoutX, (int)MainMenuProps::HorLayoutY, (int)MainMenuProps::HorLayoutW, (int)MainMenuProps::HorLayoutH);
    _widgetForHorLayout->setGeometry(rect);
    _QuitButton->setGeometry((int)MainMenuProps::QuitButtonX, (int)MainMenuProps::QuitButtonY, (int)MainMenuProps::QuitButtonW, (int)MainMenuProps::QuitButtonH);

    // Make connects
    connect(_Tree1Button, &QPushButton::clicked, mainWindow, std::bind(&MainWindow::switchMenu, mainWindow, Menus::Tree1));
    connect(_Tree2Button, &QPushButton::clicked, mainWindow, std::bind(&MainWindow::switchMenu, mainWindow, Menus::Tree2));
    connect(_Tree3Button, &QPushButton::clicked, mainWindow, std::bind(&MainWindow::switchMenu, mainWindow, Menus::Tree3));
    connect(_BFSButton, &QPushButton::clicked, mainWindow, std::bind(&MainWindow::switchMenu, mainWindow, Menus::BFS));
    connect(_DFSButton, &QPushButton::clicked, mainWindow, std::bind(&MainWindow::switchMenu, mainWindow, Menus::DFS));
    connect(_QuitButton, &QPushButton::clicked, mainWindow, std::bind(&MainWindow::showQuitWindow, mainWindow));
}
