#ifndef ALGO_MENU_HPP
#define ALGO_MENU_HPP

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

#include "predefined_classes.hpp"

class AlgoMenu : public QWidget
{
    Q_OBJECT

public:
    AlgoMenu(bool isBFS, MainWindow* mainWindow, QWidget* parent = nullptr);
    virtual ~AlgoMenu();

    // public util functions
    void prepareMenuBeforeSwitch(bool isBFS);

private slots:
    void showPerfAnalaysis();
    void showAboutProject();
    void showContact();
    void speedSliderValueChanged(int x);
    void playButtonClicked();
    void stopButtonClicked();
    void verticesComboBoxIndexChanged(int index);
    void sizeButtonGroupPressed(int id);

private:
    // Init
    void init();

    // Private util functions
    void makeBFSMenu(MainWindow* mainWindow);
    double getSliderValueByPos(int x);
    int getSliderPosByValue(double x);
    int getVertexByIndex(int index);

////////////////////////////////////// TESTING
public:
    bool _isBFS;

    // Graph settings
    QWidget*        _settingsWidget;

    // Start vertex combobox
    QLabel*         _graphSettingsText;
    QLabel*         _vertexText;
    QComboBox*      _verticesComboBox;
    int             _startVertex;

    // Size Radio Buttons
    QWidget*        _widgetForSizeLayout;
    QVBoxLayout*    _sizeVerLayout;
    QButtonGroup*   _sizeButtonGroup;
    QRadioButton*   _smallRadioButton;
    QRadioButton*   _largeRadioButton;
    QLabel*         _graphPicture;

    // Direct Radio Buttons
    QWidget*       _widgetForDirectLayout;
    QVBoxLayout*    _directVerLayout;
    QButtonGroup*   _directButtonGroup;
    QRadioButton*   _directedRadioButton;
    QRadioButton*   _undirectedRadioButton;

    // Animation speed contrlos
    QLabel*         _sliderText;
    QLabel*         _sliderNumberText;
    QSlider*        _speedSlider;
    double          _animationSpeed;

    // Pseudocode
    QLabel*         _codeTitleText;
    QLabel*         _codeText;

    // About algo
    QLabel*         _aboutTitleText;
    QLabel*         _aboutText;

    // Similar algos
    QLabel*         _similarTitleText;
    QTextEdit*      _similarText;

    // MenuBar
    QMenuBar*       _menuBar;
    QMenu*          _analyzeMenu;
    QMenu*          _compareWithMenu;
    QMenu*          _helpMenu;
    QMenu*          _exitMenu;
    QAction*        _perfAnalaysis;
    QAction*        _aboutProject;
    QAction*        _contact;
    QAction*        _returnToMainMenu;
    QAction*        _exitFromProgram;

    // Performance analysis
    QWidget*        _perfAnalysisWidget;
    QLabel*         _perfAnalysisImage1;
    QLabel*         _perfAnalysisImage2;

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

#endif // ALGO_MENU_HPP
