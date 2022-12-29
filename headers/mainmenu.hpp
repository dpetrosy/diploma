#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <QDebug>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include "predefined_classes.hpp"

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(MainWindow* mainWindow, QWidget* parent = nullptr);
    virtual ~MainMenu();

private:
    // Init
    void init();

    // Private util functions
    void makeMainMenu(MainWindow* mainWindow);

private:
    // Widgets
    QWidget*     _widgetForVerLayout;
    QWidget*     _widgetForHorLayout;

    // Layouts
    QVBoxLayout* _verLayout;
    QHBoxLayout* _horLayout;

    // PushButtons
    QPushButton* _Tree1Button;
    QPushButton* _Tree2Button;
    QPushButton* _Tree3Button;
    QPushButton* _BFSButton;
    QPushButton* _DFSButton;
    QPushButton* _QuitButton;
};

#endif // MAINMENU_HPP
