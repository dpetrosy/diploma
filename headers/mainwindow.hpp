#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QDebug>
#include <QMainWindow>
#include <QStackedWidget>
#include <QMessageBox>
#include <QCoreApplication>

#include "helpers.hpp"
#include "predefined_classes.hpp"

// Singleton pattern used
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Singleton pattern realization
    MainWindow(MainWindow &other) = delete;
    MainWindow& operator=(const MainWindow&) = delete;
    static MainWindow *GetInstance(QWidget *parent = nullptr);
    virtual ~MainWindow();

public:
    // Public util functions
    void             setBackgroundImage(const QString& image);
    QStackedWidget*  getStackedWidget();

public slots:
    void switchMenu(Menus toMenu);
    void showQuitWindow();
    void exitFromProgram(int signal);

private:
    explicit MainWindow(QWidget *parent = nullptr);

    // Init
    void init();

    // Private util functions
    void makeStackedWidget();

    // StackedWidget maker
    template <typename T, typename... Types>
    void makeStackedWidget(QStackedWidget *stackedWidget, T widget, Types... arg2)
    {
        stackedWidget->addWidget(widget);
        return makeStackedWidget(stackedWidget, arg2...);
    }

    // Template Specialization
    void makeStackedWidget(QStackedWidget *stackedWidget)
    {
        Q_UNUSED(stackedWidget)
        return;
    }

private:
    // Singleton pattern realization
    static MainWindow* _mainWindow;

    // Images
    QPixmap         _backgroundImage;
    QPalette        _palette;

    // Menus Widgets
    MainMenu*       _MainMenuWidget;

    // Menus StackedWidget
    QStackedWidget* _MenusStackedWidget;
};

#endif // MAINWINDOW_HPP
