#ifndef TREE_MENU_HPP
#define TREE_MENU_HPP

#include <QDebug>
#include <QWidget>
#include <QRadioButton>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QSlider>
#include <QTextEdit>
#include <QMenuBar>
#include <QMediaPlayer>
#include <QVideoWidget>

#include "helpers.hpp"
#include "predefined_classes.hpp"

class TreeMenu : public QWidget
{
    Q_OBJECT

public:
    TreeMenu(bool isRBTree, MainWindow* mainWindow, QWidget* parent = nullptr);
    virtual ~TreeMenu();

    // public util functions
    void prepareMenuBeforeSwitch(bool isRBTree);

private slots:
//    void showCompareWith(CompareWithTrees tree);
    void showPerfAnalaysis();
    void showAboutProject();
    void showContact();
    void speedSliderValueChanged(int x);
    void playButtonClicked();
    void stopButtonClicked();
    void operationsButtonGroupPressed(int id);
    void sizeButtonGroupPressed(int id);

private:
    // Init
    void init();

    // Private util functions
    void makeTreeMenu(MainWindow* mainWindow);
    double getSliderValueByPos(int x);
    int getSliderPosByValue(double x);
    int getVertexByIndex(int index);

private:
    bool _isRBTree;

    // Graph settings
    QWidget*        _settingsWidget;
    QLabel*         _treeSettingsText;
    QLabel*         _operationsText;

    // Operations Radio Buttons
    QWidget*        _widgetForOperationsLayout;
    QVBoxLayout*    _operationsVerLayout;
    QButtonGroup*   _operationsButtonGroup;
    QRadioButton*   _findRadioButton;
    QRadioButton*   _insertRadioButton;
    QRadioButton*   _deleteRadioButton;

    // Size Radio Buttons
    QWidget*        _widgetForSizeLayout;
    QVBoxLayout*    _sizeVerLayout;
    QButtonGroup*   _sizeButtonGroup;
    QRadioButton*   _smallRadioButton;
    QRadioButton*   _largeRadioButton;
    QLabel*         _treePicture;

    // Animation speed contrlos
    QLabel*         _sliderText;
    QLabel*         _sliderNumberText;
    QSlider*        _speedSlider;
    double          _animationSpeed;

    // About tree
    QLabel*         _aboutTitleText;
    QLabel*         _aboutText;

    // Similar trees
    QLabel*         _similarTitleText;
    QTextEdit*      _similarText;

    // MenuBar
    QMenuBar*       _menuBar;
    QMenu*          _analyzeMenu;
    QMenu*          _compareWithMenu;
    QMenu*          _helpMenu;
    QMenu*          _exitMenu;
////    QAction*        _compareWithBFS;
////    QAction*        _compareWithDFS;
////    QAction*        _compareWithBeam;
////    QAction*        _compareWithDijkstra;
////    QAction*        _compareWithBidirectional;
////    QAction*        _compareWithAll;
    QAction*        _perfAnalaysis;
    QAction*        _aboutProject;
    QAction*        _contact;
    QAction*        _returnToMainMenu;
    QAction*        _exitFromProgram;

//    // Compare with
//    QWidget*        _compareWithWidget;
//    QLabel*         _compareWithImage;

    // Performance analysis
    QWidget*        _perfAnalysisWidget;
    QLabel*         _perfAnalysisImage;

    // Complexities
    QLabel*         _compTitleText;
    QLabel*         _compText;

    // Animation control buttons
    ClickableLabel* _playButton;
    ClickableLabel* _stopButton;
    bool            _isAnimationPaused;

    // Animation player
    QMediaPlayer*   _videoPlayer;
    QVideoWidget*   _videoWidget;
};

#endif // TREE_MENU_HPP
