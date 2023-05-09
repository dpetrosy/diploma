#include "mainmenu.hpp"
#include "mainwindow.hpp"
#include "helpers.hpp"
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
    delete _RBTreeButton;
    delete _AVLTreeButton;
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
    _RBTreeButton = new QPushButton();
    _AVLTreeButton = new QPushButton();
    _BFSButton = new QPushButton();
    _DFSButton = new QPushButton();
    _QuitButton = new QPushButton(this);
}

// Private util functions
void MainMenu::makeMainMenu(MainWindow* mainWindow)
{
    // Set buttons sizes
    setPushButtonSize(_RBTreeButton, (int)MainMenuProps::VerLayoutButtonsW, (int)MainMenuProps::VerLayoutButtonsH);
    setPushButtonSize(_AVLTreeButton, (int)MainMenuProps::VerLayoutButtonsW, (int)MainMenuProps::VerLayoutButtonsH);
    setPushButtonSize(_BFSButton, (int)MainMenuProps::HorLayoutButtonsW, (int)MainMenuProps::HorLayoutButtonsH);
    setPushButtonSize(_DFSButton, (int)MainMenuProps::HorLayoutButtonsW, (int)MainMenuProps::HorLayoutButtonsH);
    setPushButtonSize(_QuitButton, (int)MainMenuProps::VerLayoutButtonsW, (int)MainMenuProps::VerLayoutButtonsH);

    // Set buttons texts
    _RBTreeButton->setText("Red-Black Tree");
    _AVLTreeButton->setText("AVL Tree");
    _BFSButton->setText("BFS");
    _DFSButton->setText("DFS");
    _QuitButton->setText("Quit");

    // Set buttons fonts
    setPushButtonFont(_RBTreeButton, (int)MainMenuProps::VerLayoutButtonsFont);
    setPushButtonFont(_AVLTreeButton, (int)MainMenuProps::VerLayoutButtonsFont);
    setPushButtonFont(_BFSButton, (int)MainMenuProps::HorLayoutButtonsFont);
    setPushButtonFont(_DFSButton, (int)MainMenuProps::HorLayoutButtonsFont);
    setPushButtonFont(_QuitButton, (int)MainMenuProps::HorLayoutButtonsFont);

    // Set buttons style
    ::setStyleSheet(StylesPaths::MainMenuButtonStyle, _RBTreeButton);
    ::setStyleSheet(StylesPaths::MainMenuButtonStyle, _AVLTreeButton);
    ::setStyleSheet(StylesPaths::MainMenuButtonStyle, _BFSButton);
    ::setStyleSheet(StylesPaths::MainMenuButtonStyle, _DFSButton);
    ::setStyleSheet(StylesPaths::MainMenuButtonStyle, _QuitButton);

    // Add buttons to layouts
    _verLayout->addWidget(_RBTreeButton);
    _verLayout->addWidget(_AVLTreeButton);
    _horLayout->addWidget(_BFSButton);
    _horLayout->addWidget(_DFSButton);

    // Set geometry for layouts and buttons
    QRect rect((int)MainMenuProps::VerLayoutX, (int)MainMenuProps::VerLayoutY, (int)MainMenuProps::VerLayoutW, (int)MainMenuProps::VerLayoutH);
    _widgetForVerLayout->setGeometry(rect);
    rect.setRect((int)MainMenuProps::HorLayoutX, (int)MainMenuProps::HorLayoutY, (int)MainMenuProps::HorLayoutW, (int)MainMenuProps::HorLayoutH);
    _widgetForHorLayout->setGeometry(rect);
    _QuitButton->setGeometry((int)MainMenuProps::QuitButtonX, (int)MainMenuProps::QuitButtonY, (int)MainMenuProps::QuitButtonW, (int)MainMenuProps::QuitButtonH);

    // Make connects
    connect(_RBTreeButton, &QPushButton::clicked, mainWindow, std::bind(&MainWindow::switchMenu, mainWindow, Menus::RBTree));
    connect(_AVLTreeButton, &QPushButton::clicked, mainWindow, std::bind(&MainWindow::switchMenu, mainWindow, Menus::AVLTree));
    connect(_BFSButton, &QPushButton::clicked, mainWindow, std::bind(&MainWindow::switchMenu, mainWindow, Menus::BFS));
    connect(_DFSButton, &QPushButton::clicked, mainWindow, std::bind(&MainWindow::switchMenu, mainWindow, Menus::DFS));
    connect(_QuitButton, &QPushButton::clicked, mainWindow, std::bind(&MainWindow::showQuitWindow, mainWindow));
}
