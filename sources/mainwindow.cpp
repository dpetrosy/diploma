#include "mainwindow.hpp"
#include "headers/predefined_classes.hpp"
#include "mainmenu.hpp"
#include "helpers.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Set MainWindow size
    this->setFixedSize((int)MainWindowProps::windowSizeW, (int)MainWindowProps::windowSizeH);

    // Init class members
    init();

    //setBackgroundImage(BackgroundImages::StrongKnight);

    // Make StackedWidget
    makeStackedWidget();

    // Set MainMenu when program start
    setCentralWidget(this->_MenusStackedWidget);
    switchMenu(Menus::MainMenu);
}

MainWindow::~MainWindow() {}

// Singlton pattern realization
MainWindow *MainWindow::_mainWindow = nullptr;

MainWindow *MainWindow::GetInstance(QWidget *parent)
{
    if(_mainWindow == nullptr)
        _mainWindow = new MainWindow(parent);

    return _mainWindow;
}

// Init
void MainWindow::init()
{
    // Menus Widgets
    _MainMenuWidget = new MainMenu(this);

    // Menus StackedWidget
    _MenusStackedWidget = new QStackedWidget();
}

// Public slots
void MainWindow::switchMenu(Menus toMenu)
{
//    if (toMenu == Menus::PVPMenu)
//        _PVPMenuWidget->makeMenuBeforeSwitch();
//    else if (toMenu == Menus::SettingsMenu)
//        _SettingsMenuWidget->makeMenuBeforeSwitch();
//    else if (toMenu == Menus::MainMenu)
//        _MainMenuWidget->makeMenuBeforeSwitch(_SettingsMenuWidget, this);

    _MenusStackedWidget->setCurrentIndex((int)toMenu);
}

void MainWindow::showQuitWindow()
{
    if (QMessageBox::question(this, "Quit confirmation", "Are you sure you want to quit?", QMessageBox::Yes|QMessageBox::Cancel, QMessageBox::Cancel) == QMessageBox::Yes)
        exitFromProgram(0);
}

void MainWindow::exitFromProgram(int signal)
{
    QCoreApplication::exit(signal);
}

// Public util functions
void MainWindow::setBackgroundImage(const QString& image)
{
//    _backgroundImage.load(ImagesPaths::backgroundsPath + image + BackgroundImages::Extencion);
//    _backgroundImage = _backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio);
//    _palette.setBrush(QPalette::Window, _backgroundImage);
//    this->setPalette(_palette);
}

QStackedWidget* MainWindow::getStackedWidget()
{
    return _MenusStackedWidget;
}

// Private util functions
void MainWindow::makeStackedWidget()
{
    makeStackedWidget(_MenusStackedWidget, _MainMenuWidget);
}
