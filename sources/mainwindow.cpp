#include "mainwindow.hpp"
#include "mainmenu.hpp"
#include "helpers.hpp"
#include "algo_menu.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Set MainWindow size
    this->setFixedSize((int)MainWindowProps::windowSizeW, (int)MainWindowProps::windowSizeH);

    // Init class members
    init();

    setBackgroundImage(ImagesPaths::MainMenuBKGImage);

    // Make StackedWidget
    makeStackedWidget();

    // Set MainMenu when program start
    setCentralWidget(this->_MenusStackedWidget);
    switchMenu(Menus::MainMenu);
}

MainWindow::~MainWindow()
{
    delete _MainMenuWidget;
    delete _AlgoMenuWidget;
    delete _MenusStackedWidget;
}

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
    _AlgoMenuWidget = new AlgoMenu(this);

    // Menus StackedWidget
    _MenusStackedWidget = new QStackedWidget();
}

// Public slots
void MainWindow::switchMenu(Menus toMenu)
{
    _MenusStackedWidget->setCurrentIndex((int)toMenu);

    if (toMenu == Menus::MainMenu)
        setBackgroundImage(ImagesPaths::MainMenuBKGImage);
    else
        setBackgroundImage(ImagesPaths::MenusBKGImage);
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
    _backgroundImage.load(ImagesPaths::BackgroundsPath + image + ".jpg");
    _backgroundImage = _backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio);
    _palette.setBrush(QPalette::Window, _backgroundImage);
    this->setPalette(_palette);
}

// Getters
QStackedWidget* MainWindow::getStackedWidget()
{
    return _MenusStackedWidget;
}

// Private util functions
void MainWindow::makeStackedWidget()
{
    makeStackedWidget(_MenusStackedWidget, _MainMenuWidget, _AlgoMenuWidget);
}
