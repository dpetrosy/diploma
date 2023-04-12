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

class AlgoMenu : public QWidget
{
    Q_OBJECT

public:
    AlgoMenu(bool isBFS, QWidget* parent = nullptr);
    virtual ~AlgoMenu();

private:
    // Init
    void init();

    // Private util functions
    void makeBFSMenu();

private:
    bool _isBFS;

    // Graph settings
    QWidget*        _settingsWidget;

    QLabel*         _graphSettingsText;
    QLabel*         _vertexText;
    QComboBox*      _verticesComboBox;

    QWidget*        _widgetForSizeLayout;
    QVBoxLayout*    _sizeVerLayout;
    QButtonGroup*   _sizeButtonGroup;
    QRadioButton*   _smallRadioButton;
    QRadioButton*   _mediumRadioButton;
    QRadioButton*   _largeRadioButton;

    QWidget*       _widgetForDirectLayout;
    QVBoxLayout*    _directVerLayout;
    QButtonGroup*   _directButtonGroup;
    QRadioButton*   _directedRadioButton;
    QRadioButton*   _undirectedRadioButton;

    // Animation settings
    QLabel*         _sliderText;
    QLabel*         _sliderNumberText;
    QSlider*        _speedSlider;

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

    // Complexities
    QLabel*         _compTitleText;
    QLabel*         _compText;











    QPushButton  _pausePushButton;
    QPushButton  _stopPushButton;
};

#endif // ALGO_MENU_HPP
