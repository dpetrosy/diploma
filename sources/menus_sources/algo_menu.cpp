#include "algo_menu.hpp"
#include "helpers.hpp"
#include "utils.hpp"

AlgoMenu::AlgoMenu(bool isBFS, QWidget* parent) :
    QWidget(parent)
{
    _isBFS = isBFS;

    // Init class members
    init();

    // Make BFSMenu
    makeBFSMenu();
}

AlgoMenu::~AlgoMenu() {}

// Init
void AlgoMenu::init()
{
    // Graph settings
    _settingsWidget = new QWidget(this);

    _graphSettingsText = new QLabel(_settingsWidget);
    _vertexText = new QLabel(_settingsWidget);
    _verticesComboBox = new QComboBox(_settingsWidget);

    _widgetForSizeLayout = new QWidget(_settingsWidget);
    _sizeVerLayout = new QVBoxLayout(_widgetForSizeLayout);
    _sizeButtonGroup = new QButtonGroup(_widgetForSizeLayout);
    _smallRadioButton = new QRadioButton();
    _mediumRadioButton = new QRadioButton();
    _largeRadioButton = new QRadioButton();

    _widgetForDirectLayout = new QWidget(_settingsWidget);
    _directVerLayout = new QVBoxLayout(_widgetForDirectLayout);
    _directButtonGroup = new QButtonGroup(_widgetForDirectLayout);
    _directedRadioButton = new QRadioButton();
    _undirectedRadioButton = new QRadioButton();

    // Animation settings
    _sliderText = new QLabel(this);
    _sliderNumberText = new QLabel(this);
    _speedSlider = new QSlider(Qt::Horizontal, this);

    // Pseudocode
    _codeTitleText = new QLabel(this);
    _codeText = new QLabel(this);

    // About algo
    _aboutText = new QLabel(this);
    _aboutTitleText = new QLabel(this);

    // Similar algos
    _similarText = new QTextEdit(this);
    _similarTitleText = new QLabel(this);

    // MenuBar
    _menuBar = new QMenuBar(this);
    _compareWithMenu = new QMenu();
    _analyzeMenu = new QMenu();
    _helpMenu = new QMenu();
    _exitMenu = new QMenu();

    // Complexities
    _compText = new QLabel(this);
    _compTitleText = new QLabel(this);
}

void AlgoMenu::makeBFSMenu()
{
    // Settings Widget
    _settingsWidget->setObjectName("myWidget");
    _settingsWidget->setGeometry((int)AlgoMenuProps::settingsWidgetX, (int)AlgoMenuProps::settingsWidgetY, (int)AlgoMenuProps::settingsWidgetW, (int)AlgoMenuProps::settingsWidgetH);
    _settingsWidget->setStyleSheet("#myWidget { background-color: #f7f6f5; border: 1px solid #d2d2d2; border-radius: 4px; }");

    // Settings text
    _graphSettingsText->setText("Choose graph settings");
    ::setStyleSheet(StylesPaths::OneLineTextStyle , _graphSettingsText);
    setLabelTextFont(_graphSettingsText, 11);
    _graphSettingsText->move((int)AlgoMenuProps::settingsTextX, (int)AlgoMenuProps::settingsTextY);

    // Vertex text
    _vertexText->setText("Start vertex");
    ::setStyleSheet(StylesPaths::OneLineTextStyle , _vertexText);
    _vertexText->move((int)AlgoMenuProps::vertexTextX, (int)AlgoMenuProps::vertexTextY);
    setLabelTextFont(_vertexText, 10);

    // Vertices ComboBox
    _verticesComboBox->setGeometry((int)AlgoMenuProps::VerticesComboBoxX, (int)AlgoMenuProps::VerticesComboBoxY, (int)AlgoMenuProps::VerticesComboBoxW, (int)AlgoMenuProps::VerticesComboBoxH);
    ::setStyleSheet(StylesPaths::ComboBoxStyle, _verticesComboBox);

    // Size Radio buttons
    _smallRadioButton->setText("Small Graph");
    _smallRadioButton->setFont(QFont("Segoe UI ", 12));
    _mediumRadioButton->setText("Medium Graph");
    _mediumRadioButton->setFont(QFont("Segoe UI ", 12));
    _largeRadioButton->setText("Large Graph");
    _largeRadioButton->setFont(QFont("Segoe UI ", 12));
    _sizeButtonGroup->addButton(_smallRadioButton, (int)SizeRadioButtons::SmallButton);
    _sizeButtonGroup->addButton(_mediumRadioButton, (int)SizeRadioButtons::MediumButton);
    _sizeButtonGroup->addButton(_largeRadioButton, (int)SizeRadioButtons::LargeButton);
    _sizeVerLayout->addWidget(_smallRadioButton);
    _sizeVerLayout->addWidget(_mediumRadioButton);
    _sizeVerLayout->addWidget(_largeRadioButton);
    _widgetForSizeLayout->setLayout(_sizeVerLayout);
    _widgetForSizeLayout->setGeometry((int)AlgoMenuProps::SizeWidgetX, (int)AlgoMenuProps::SizeWidgetY, (int)AlgoMenuProps::SizeWidgetW, (int)AlgoMenuProps::SizeWidgetH);

    // Direct Radio buttons
    _directedRadioButton->setText("Directed Graph");
    _directedRadioButton->setFont(QFont("Segoe UI ", 12));
    _undirectedRadioButton->setText("Undirected Graph");
    _undirectedRadioButton->setFont(QFont("Segoe UI ", 12));
    _directButtonGroup->addButton(_directedRadioButton, (int)SizeRadioButtons::SmallButton);
    _directButtonGroup->addButton(_undirectedRadioButton, (int)SizeRadioButtons::MediumButton);
    _directVerLayout->addWidget(_directedRadioButton);
    _directVerLayout->addWidget(_undirectedRadioButton);
    _widgetForDirectLayout->setLayout(_directVerLayout);
    _widgetForDirectLayout->setGeometry((int)AlgoMenuProps::DirectWidgetX, (int)AlgoMenuProps::DirectWidgetY, (int)AlgoMenuProps::DirectWidgetW, (int)AlgoMenuProps::DirectWidgetH);

    // Speed Slider Text
    _sliderText->setText("Animation speed:");
    ::setStyleSheet(StylesPaths::DimTextStyle, _sliderText);
    _sliderText->move((int)AlgoMenuProps::SliderTextX, (int)AlgoMenuProps::SliderTextY);

    // Speed Slider Number Text
    _sliderNumberText->setText("1x");
    ::setStyleSheet(StylesPaths::BoldDimTextStyle, _sliderNumberText);
    _sliderNumberText->move((int)AlgoMenuProps::SliderTextNumberX, (int)AlgoMenuProps::SliderTextNumberY);

    // Minutes slider
    _speedSlider->setGeometry((int)AlgoMenuProps::SliderX, (int)AlgoMenuProps::SliderY, (int)AlgoMenuProps::SliderW, (int)AlgoMenuProps::SliderH);
    ::setStyleSheet(StylesPaths::SliderStyle, _speedSlider);
    _speedSlider->setCursor(Qt::PointingHandCursor);
    _speedSlider->setRange(0, 4);
    _speedSlider->setValue(2);

    // Pseudocode title text
    _codeTitleText->setText("Pseudocode");
    ::setStyleSheet(StylesPaths::OneLineTextStyle, _codeTitleText);
    setLabelTextFont(_codeTitleText, 14);
    _codeTitleText->move((int)AlgoMenuProps::CodeTitleTextX, (int)AlgoMenuProps::CodeTitleTextY);

    // Pseudocode text
    _codeText->setText(getTextFromFile(TextsPaths::BFSPseudocodePath));
    ::setStyleSheet(StylesPaths::PseudocodeStyle, _codeText);
    _codeText->setGeometry((int)AlgoMenuProps::CodeTextX, (int)AlgoMenuProps::CodeTextY, (int)AlgoMenuProps::CodeTextW, (int)AlgoMenuProps::CodeTextH);

    // About title text
    _aboutTitleText->setText("About BFS");
    ::setStyleSheet(StylesPaths::AboutTitleStyle, _aboutTitleText);
    setLabelTextFont(_aboutTitleText, 11);
    _aboutTitleText->move((int)AlgoMenuProps::AboutTitleTextX, (int)AlgoMenuProps::AboutTitleTextY);

    // About text
    _aboutText->setText(getTextFromFile(TextsPaths::AboutBFSPath));
    ::setStyleSheet(StylesPaths::AboutTextStyle, _aboutText);
    _aboutText->setGeometry((int)AlgoMenuProps::AboutTextX, (int)AlgoMenuProps::AboutTextY, (int)AlgoMenuProps::AboutTextW, (int)AlgoMenuProps::AboutTextH);

    // Similar title text
    _similarTitleText->setText("Similar algorithms");
    ::setStyleSheet(StylesPaths::SimilarTitleStyle, _similarTitleText);
    _similarTitleText->move((int)AlgoMenuProps::SimilarTitleTextX, (int)AlgoMenuProps::SimilarTitleTextY);

    // Similar text
    _similarText->setReadOnly(true);
    _similarText->setPlainText(deleteNewlineAtEnd(getTextFromFile(TextsPaths::SimilarAlgosPath)));
    ::setStyleSheet(StylesPaths::SimilarTextStyle, _similarText);
    QTextBlockFormat blockFormat;
    blockFormat.setLineHeight(130, QTextBlockFormat::ProportionalHeight);
    QTextCursor cursor = _similarText->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.setBlockFormat(blockFormat);
    _similarText->setGeometry((int)AlgoMenuProps::SimilarTextX, (int)AlgoMenuProps::SimilarTextY, (int)AlgoMenuProps::SimilarTextW, (int)AlgoMenuProps::SimilarTextH);

    // MenuBar
    _analyzeMenu->setTitle("Analyze");
    _compareWithMenu->setTitle("Comapre With...");
    _helpMenu->setTitle("Help");
    _exitMenu->setTitle("Exit");
    _analyzeMenu->addMenu(_compareWithMenu);
    _analyzeMenu->addAction("Time Complexity Analysis");
    _analyzeMenu->addAction("Space Complexity Analysis");
    _compareWithMenu->addAction("All Algorithms");
    _helpMenu->addAction("About Project");
    _helpMenu->addAction("Contact");
    _exitMenu->addAction("Return to Main Menu");
    _exitMenu->addAction("Exit From Program");
    _menuBar->addMenu(_analyzeMenu);
    _menuBar->addMenu(_helpMenu);
    _menuBar->addMenu(_exitMenu);
    ::setStyleSheet(StylesPaths::MenuStyle, _menuBar);
    _menuBar->setFixedWidth((int)MainWindowProps::windowSizeW);
    _menuBar->setFixedHeight(22);




























    // Complexities title text
    _compTitleText->setText("Complexities");
    ::setStyleSheet(StylesPaths::SimilarTitleStyle, _compTitleText);
    _compTitleText->move((int)AlgoMenuProps::CompTitleTextX, (int)AlgoMenuProps::CompTitleTextY);

    // Complexities text
    _compText->setText(getTextFromFile(TextsPaths::CompBFSPath));
    ::setStyleSheet(StylesPaths::CompTextStyle, _compText);
    _compText->setGeometry((int)AlgoMenuProps::CompTextX, (int)AlgoMenuProps::CompTextY, (int)AlgoMenuProps::CompTextW, (int)AlgoMenuProps::CompTextH);























}
