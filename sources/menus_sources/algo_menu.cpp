#include "algo_menu.hpp"
#include "clickablelabel.hpp"
#include "helpers.hpp"
#include "mainwindow.hpp"
#include "utils.hpp"

AlgoMenu::AlgoMenu(bool isBFS, MainWindow* mainWindow, QWidget* parent) :
    QWidget(parent)
{
    _isBFS = isBFS;

    // Init class members
    init();

    // Make BFSMenu
    makeBFSMenu(mainWindow);
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
    _startVertex = (int)BFSVertices::A;

    _widgetForSizeLayout = new QWidget(_settingsWidget);
    _sizeVerLayout = new QVBoxLayout(_widgetForSizeLayout);
    _sizeButtonGroup = new QButtonGroup(_widgetForSizeLayout);
    _smallRadioButton = new QRadioButton();
    _largeRadioButton = new QRadioButton();
    _graphPicture = new QLabel(this);

    _widgetForDirectLayout = new QWidget(_settingsWidget);
    _directVerLayout = new QVBoxLayout(_widgetForDirectLayout);
    _directButtonGroup = new QButtonGroup(_widgetForDirectLayout);
    _directedRadioButton = new QRadioButton();
    _undirectedRadioButton = new QRadioButton();

    // Animation speed contrlos
    _sliderText = new QLabel(this);
    _sliderNumberText = new QLabel(this);
    _speedSlider = new QSlider(Qt::Horizontal, this);
    _animationSpeed = 1;

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
    _compareWithBFS = new QAction(this);
    _compareWithDFS = new QAction(this);
    _compareWithBeam = new QAction(this);
    _compareWithDijkstra = new QAction(this);
    _compareWithBidirectional = new QAction(this);
    _compareWithAll = new QAction(this);
    _perfAnalaysis = new QAction(this);
    _aboutProject = new QAction(this);
    _contact = new QAction(this);
    _returnToMainMenu = new QAction(this);
    _exitFromProgram = new QAction(this);

    // Compare with
    _compareWithWidget = new QWidget();
    _compareWithImage = new QLabel(_compareWithWidget);

    // Performance analysis
    _perfAnalysisWidget = new QWidget();
    _perfAnalysisImage1 = new QLabel(_perfAnalysisWidget);
    _perfAnalysisImage2 = new QLabel(_perfAnalysisWidget);

    // Complexities
    _compText = new QLabel(this);
    _compTitleText = new QLabel(this);

    // Animation control buttons
    _playButton = new ClickableLabel(this);
    _stopButton = new ClickableLabel(this);
    _isAnimationPaused = true;

    // Animation player
    _videoPlayer = new QMediaPlayer(this);
    _videoWidget = new QVideoWidget(this);
}

// Public util functions
void AlgoMenu::prepareMenuBeforeSwitch(bool isBFS)
{
    // Size Radio buttons
    _smallRadioButton->setChecked("true");

    // Direct Radio buttons
    _undirectedRadioButton->setChecked(true);

    // Speed Slider Number Text
    _sliderNumberText->setText("1x");

    // Minutes slider
    _speedSlider->setValue(2);

    // Play button
    _playButton->setPixmap(QPixmap(ImagesPaths::PlayButtonImage));

    // Stop button
    _stopButton->setEnabled(false);

    // Compare with menu
    _compareWithMenu->clear();

    _isBFS = isBFS;
    if (isBFS)
    {
        // Pseudocode text
        _codeText->setText(getTextFromFile(TextsPaths::BFSPseudocodePath));

        // About title text
        _aboutTitleText->setText("About BFS");

        // About text
        _aboutText->setText(getTextFromFile(TextsPaths::AboutBFSPath));

        // Complexities text
        _compText->setText(getTextFromFile(TextsPaths::CompBFSPath));

        // Comare with menu
        _compareWithMenu->addAction(_compareWithDFS);
        _compareWithMenu->addAction(_compareWithBeam);
        _compareWithMenu->addAction(_compareWithDijkstra);
        _compareWithMenu->addAction(_compareWithBidirectional);
        _compareWithMenu->addAction(_compareWithAll);
    }
    else
    {
        // Pseudocode text
        _codeText->setText(getTextFromFile(TextsPaths::DFSPseudocodePath));

        // About title text
        _aboutTitleText->setText("About DFS");

        // About text
        _aboutText->setText(getTextFromFile(TextsPaths::AboutDFSPath));

        // Complexities text
        _compText->setText(getTextFromFile(TextsPaths::CompDFSPath));

        // Comare with menu
        _compareWithMenu->addAction(_compareWithBFS);
        _compareWithMenu->addAction(_compareWithBeam);
        _compareWithMenu->addAction(_compareWithDijkstra);
        _compareWithMenu->addAction(_compareWithBidirectional);
        _compareWithMenu->addAction(_compareWithAll);
    }
}

// Private slots
void AlgoMenu::showCompareWith(CompareWithAlgos algo)
{
    _compareWithWidget->show();
    _compareWithImage->setFixedWidth(1000);
    _compareWithImage->setFixedHeight(430);

    if (_isBFS)
    {
        switch (algo)
        {
        default:
            _compareWithImage->setPixmap(QPixmap(ImagesPaths::BFSWithDFS));
            _compareWithWidget->setFixedSize(810, 470);
            return;
        case CompareWithAlgos::Beam:
            _compareWithImage->setPixmap(QPixmap(ImagesPaths::BFSWithBeam));
            _compareWithWidget->setFixedSize(843, 470);
            return;
        case CompareWithAlgos::Dijkstra:
            _compareWithImage->setPixmap(QPixmap(ImagesPaths::BFSWithDijkstra));
            _compareWithWidget->setFixedSize(870, 470);
            return;
        case CompareWithAlgos::Bidirectional:
            _compareWithImage->setPixmap(QPixmap(ImagesPaths::BFSWithBidirectional));
            _compareWithWidget->setFixedSize(810, 470);
            return;
        case CompareWithAlgos::All:
            _compareWithImage->setPixmap(QPixmap(ImagesPaths::BFSWithAll));
            _compareWithImage->setFixedWidth(1520);
            _compareWithImage->setFixedHeight(800);
            _compareWithWidget->setFixedSize(1560, 850);
            return;
        }
    }
    else
    {
        switch (algo)
        {
        default:
            _compareWithImage->setPixmap(QPixmap(ImagesPaths::DFSWithBFS));
            _compareWithWidget->setFixedSize(825, 470);
            return;
        case CompareWithAlgos::Beam:
            _compareWithImage->setPixmap(QPixmap(ImagesPaths::DFSWithBeam));
            _compareWithWidget->setFixedSize(1037, 463);
            return;
        case CompareWithAlgos::Dijkstra:
            _compareWithImage->setPixmap(QPixmap(ImagesPaths::DFSWithDijkstra));
            _compareWithWidget->setFixedSize(1045, 463);
            return;
        case CompareWithAlgos::Bidirectional:
            _compareWithImage->setPixmap(QPixmap(ImagesPaths::DFSWithBidirectional));
            _compareWithWidget->setFixedSize(1000, 463);
            return;
        case CompareWithAlgos::All:
            _compareWithImage->setPixmap(QPixmap(ImagesPaths::DFSWithAll));
            _compareWithImage->setFixedWidth(1520);
            _compareWithImage->setFixedHeight(800);
            _compareWithWidget->setFixedSize(1560, 850);
            return;
        }
    }
}

void AlgoMenu::showPerfAnalaysis()
{
    if (_isBFS)
    {
        _perfAnalysisImage1->setPixmap(QPixmap(ImagesPaths::PerfBFSImage1));
        _perfAnalysisImage2->setPixmap(QPixmap(ImagesPaths::PerfBFSImage2));
    }
    else
    {
        _perfAnalysisImage1->setPixmap(QPixmap(ImagesPaths::PerfDFSImage1));
        _perfAnalysisImage2->setPixmap(QPixmap(ImagesPaths::PerfDFSImage2));
    }

    _perfAnalysisWidget->show();
}

void AlgoMenu::showAboutProject()
{
    QMessageBox::information(this, "About Project", "This is my diploma project: Data structures visualizer.");
}

void AlgoMenu::showContact()
{
    QMessageBox::information(this, "Contact", "You can contact with me by LinkedIn.\nMy login: dpetrosy");
}

void AlgoMenu::speedSliderValueChanged(int x)
{
    _speedSlider->setValue(x);
    _animationSpeed = getSliderValueByPos(x);
    _sliderNumberText->setText(QString::number(_animationSpeed) + "x");
    _videoPlayer->setPlaybackRate(qreal(_animationSpeed));
}

void AlgoMenu::playButtonClicked()
{
    if (_isAnimationPaused) // Play clicked
    {
        _videoWidget->show();
        _videoPlayer->play();
        _stopButton->setEnabled(true);
        _stopButton->setToolTip("Stop");
        _isAnimationPaused = false;
        _playButton->setPixmap(QPixmap(ImagesPaths::PauseButtonImage));
        _playButton->setToolTip("Pause");
        _graphPicture->hide();
    }
    else // Pause clicked
    {
        _videoPlayer->pause();
        _isAnimationPaused = true;
        _playButton->setPixmap(QPixmap(ImagesPaths::PlayButtonImage));
        _playButton->setToolTip("Play");
    }
}

void AlgoMenu::stopButtonClicked()
{
    _videoWidget->hide();
    _videoPlayer->stop();
    _graphPicture->show();
    _isAnimationPaused = true;
    _stopButton->setEnabled(false);
    _stopButton->setToolTip("");
    _playButton->setPixmap(QPixmap(ImagesPaths::PlayButtonImage));
    _playButton->setToolTip("Play");
}

void AlgoMenu::verticesComboBoxIndexChanged(int index)
{
    _startVertex = getVertexByIndex(index);
}

void AlgoMenu::sizeButtonGroupPressed(int id)
{
    stopButtonClicked();
    speedSliderValueChanged(2);

    if (id == 0) // small graph choosed
    {
        _graphPicture->setPixmap(QPixmap(ImagesPaths::SmallGraphImage));
        _videoPlayer->setSource(QUrl(VideosPaths::BFSVideosPath + "video1.mp4"));
        _videoWidget->setGeometry(302, 80, 628, 460);
        _graphPicture->setGeometry(302, 80, 628, 460);
    }
    else // large graph choosed
    {
        _graphPicture->setPixmap(QPixmap(ImagesPaths::LargeGraphImage));
        _videoPlayer->setSource(QUrl(VideosPaths::BFSVideosPath + "video.mp4"));
        _videoWidget->setGeometry(302, 80, 612, 490);
        _graphPicture->setGeometry(302, 80, 612, 490);
    }
}

// Private util functions
void AlgoMenu::makeBFSMenu(MainWindow* mainWindow)
{
    // Settings Widget
    _settingsWidget->setObjectName("SettingsWidget");
    _settingsWidget->setGeometry((int)AlgoMenuProps::settingsWidgetX, (int)AlgoMenuProps::settingsWidgetY, (int)AlgoMenuProps::settingsWidgetW, (int)AlgoMenuProps::settingsWidgetH);
    _settingsWidget->setStyleSheet("#SettingsWidget { background-color: #f7f6f5; border: 1px solid #d2d2d2; border-radius: 4px; }");

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
    _verticesComboBox->addItem(QString::number((int)BFSVertices::A));
    _verticesComboBox->addItem(QString::number((int)BFSVertices::B));
    _verticesComboBox->addItem(QString::number((int)BFSVertices::C));
    _verticesComboBox->addItem(QString::number((int)BFSVertices::D));
    _verticesComboBox->addItem(QString::number((int)BFSVertices::E));
    _verticesComboBox->setCurrentIndex(0);
    _verticesComboBox->setCursor(Qt::PointingHandCursor);
    connect(_verticesComboBox, &QComboBox::currentIndexChanged, this, &AlgoMenu::verticesComboBoxIndexChanged);

    // Size Radio buttons
    _smallRadioButton->setText("Small Graph");
    _smallRadioButton->setFont(QFont("Segoe UI ", 12));
    _smallRadioButton->setCursor(Qt::PointingHandCursor);
    _largeRadioButton->setText("Large Graph");
    _largeRadioButton->setFont(QFont("Segoe UI ", 12));
    _largeRadioButton->setCursor(Qt::PointingHandCursor);
    _sizeButtonGroup->addButton(_smallRadioButton, (int)SizeRadioButtons::SmallButton);
    _sizeButtonGroup->addButton(_largeRadioButton, (int)SizeRadioButtons::LargeButton);
    _sizeVerLayout->addWidget(_smallRadioButton);
    _sizeVerLayout->addWidget(_largeRadioButton);
    _widgetForSizeLayout->setLayout(_sizeVerLayout);
    _widgetForSizeLayout->setGeometry((int)AlgoMenuProps::SizeWidgetX, (int)AlgoMenuProps::SizeWidgetY, (int)AlgoMenuProps::SizeWidgetW, (int)AlgoMenuProps::SizeWidgetH);
    connect(_sizeButtonGroup, &QButtonGroup::idPressed, this, &AlgoMenu::sizeButtonGroupPressed);

    // Graph picture
    _graphPicture->setPixmap(QPixmap(ImagesPaths::SmallGraphImage));
    _graphPicture->move(302, 80);

    // Direct Radio buttons
    _directedRadioButton->setText("Directed Graph");
    _directedRadioButton->setFont(QFont("Segoe UI ", 12));
    _directedRadioButton->setCursor(Qt::PointingHandCursor);
    _undirectedRadioButton->setText("Undirected Graph");
    _undirectedRadioButton->setChecked(true);
    _undirectedRadioButton->setFont(QFont("Segoe UI ", 12));
    _undirectedRadioButton->setCursor(Qt::PointingHandCursor);
    _directButtonGroup->addButton(_directedRadioButton, (int)SizeRadioButtons::SmallButton);
    _directButtonGroup->addButton(_undirectedRadioButton, (int)SizeRadioButtons::LargeButton);
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
    _sliderNumberText->setFixedWidth(50);

    // Speed slider
    _speedSlider->setGeometry((int)AlgoMenuProps::SliderX, (int)AlgoMenuProps::SliderY, (int)AlgoMenuProps::SliderW, (int)AlgoMenuProps::SliderH);
    ::setStyleSheet(StylesPaths::SliderStyle, _speedSlider);
    _speedSlider->setCursor(Qt::PointingHandCursor);
    _speedSlider->setRange(0, 4);
    _speedSlider->setValue(getSliderPosByValue(_animationSpeed));
    connect(_speedSlider, &QSlider::valueChanged, this, &AlgoMenu::speedSliderValueChanged);

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
    _aboutTitleText->setGeometry((int)AlgoMenuProps::AboutTitleTextX, (int)AlgoMenuProps::AboutTitleTextY, 100, 21);

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
    _analyzeMenu->addMenu(_compareWithMenu);
    _analyzeMenu->addAction(_perfAnalaysis);
    _perfAnalaysis->setText("Performance Analysis");
    connect(_perfAnalaysis, &QAction::triggered, this, &AlgoMenu::showPerfAnalaysis);

    _compareWithMenu->setTitle("Comapre With...");
    _compareWithBFS->setText("BFS Algorithm");
    _compareWithDFS->setText("DFS Algorithm");
    _compareWithBeam->setText("Beam Search");
    _compareWithDijkstra->setText("Dijkstra's Algorithm");
    _compareWithBidirectional->setText("Bidirectional Search");
    _compareWithAll->setText("All Algorithms");
    connect(_compareWithBFS, &QAction::triggered, this, std::bind(&AlgoMenu::showCompareWith, this, CompareWithAlgos::BFS));
    connect(_compareWithDFS, &QAction::triggered, this, std::bind(&AlgoMenu::showCompareWith, this, CompareWithAlgos::DFS));
    connect(_compareWithBeam, &QAction::triggered, this, std::bind(&AlgoMenu::showCompareWith, this, CompareWithAlgos::Beam));
    connect(_compareWithDijkstra, &QAction::triggered, this, std::bind(&AlgoMenu::showCompareWith, this, CompareWithAlgos::Dijkstra));
    connect(_compareWithBidirectional, &QAction::triggered, this, std::bind(&AlgoMenu::showCompareWith, this, CompareWithAlgos::Bidirectional));
    connect(_compareWithAll, &QAction::triggered, this, std::bind(&AlgoMenu::showCompareWith, this, CompareWithAlgos::All));

    _helpMenu->setTitle("Help");
    _helpMenu->addAction(_aboutProject);
    _helpMenu->addAction(_contact);
    _aboutProject->setText("About Project");
    _contact->setText("Contact");
    connect(_aboutProject, &QAction::triggered, this, &AlgoMenu::showAboutProject);
    connect(_contact, &QAction::triggered, this, &AlgoMenu::showContact);

    _exitMenu->setTitle("Exit");
    _exitMenu->addAction(_returnToMainMenu);
    _exitMenu->addAction(_exitFromProgram);
    _returnToMainMenu->setText("Return to Main Menu");
    _exitFromProgram->setText("Exit From Program");
    connect(_returnToMainMenu, &QAction::triggered, mainWindow, std::bind(&MainWindow::switchMenu, mainWindow, Menus::MainMenu));
    connect(_exitFromProgram, &QAction::triggered, mainWindow, &MainWindow::showQuitWindow);

    _menuBar->addMenu(_analyzeMenu);
    _menuBar->addMenu(_helpMenu);
    _menuBar->addMenu(_exitMenu);
    ::setStyleSheet(StylesPaths::MenuStyle, _menuBar);
    _menuBar->setFixedWidth((int)MainWindowProps::windowSizeW);
    _menuBar->setFixedHeight(22);
    //

    // Compare with
    _compareWithWidget->hide();
    _compareWithWidget->setWindowTitle("Comapare With");
    _compareWithWidget->setWindowModality(Qt::ApplicationModal);
    _compareWithWidget->setFixedSize((int)AlgoMenuProps::CompareWidgetW, (int)AlgoMenuProps::CompareWidgetH);
    _compareWithWidget->setObjectName("CompareWidget");
    _compareWithWidget->setStyleSheet("#CompareWidget { background-color: #ffffff; }");
    _compareWithImage->setPixmap(QPixmap(ImagesPaths::DFSWithBeam));
    _compareWithImage->move((int)AlgoMenuProps::CompareImageX, (int)AlgoMenuProps::CompareImageY);

    // Performance analysis
    _perfAnalysisWidget->hide();
    _perfAnalysisWidget->setWindowTitle("Performance Analysis");
    _perfAnalysisWidget->setWindowModality(Qt::ApplicationModal);
    _perfAnalysisWidget->setFixedSize((int)AlgoMenuProps::PerfWidgetW, (int)AlgoMenuProps::PerfWidgetH);
    _perfAnalysisWidget->setObjectName("PerfWidget");
    _perfAnalysisWidget->setStyleSheet("#PerfWidget { background-color: #ffffff; }");
    _perfAnalysisImage1->setPixmap(QPixmap(ImagesPaths::PerfBFSImage1));
    _perfAnalysisImage1->move((int)AlgoMenuProps::PerfImage1X, (int)AlgoMenuProps::PerfImage1Y);
    _perfAnalysisImage2->setPixmap(QPixmap(ImagesPaths::PerfBFSImage2));
    _perfAnalysisImage2->move((int)AlgoMenuProps::PerfImage2X, (int)AlgoMenuProps::PerfImage2Y);

    // Complexities title text
    _compTitleText->setText("Complexities");
    ::setStyleSheet(StylesPaths::SimilarTitleStyle, _compTitleText);
    _compTitleText->move((int)AlgoMenuProps::CompTitleTextX, (int)AlgoMenuProps::CompTitleTextY);

    // Complexities text
    _compText->setText(getTextFromFile(TextsPaths::CompBFSPath));
    ::setStyleSheet(StylesPaths::CompTextStyle, _compText);
    _compText->setGeometry((int)AlgoMenuProps::CompTextX, (int)AlgoMenuProps::CompTextY, (int)AlgoMenuProps::CompTextW, (int)AlgoMenuProps::CompTextH);

    // Play button
    _playButton->setPixmap(QPixmap(ImagesPaths::PlayButtonImage));
    _playButton->setCursor(Qt::PointingHandCursor);
    _playButton->move((int)AlgoMenuProps::PlayButtonX, (int)AlgoMenuProps::PlayButtonY);
    _playButton->setToolTip("Play");
    connect(_playButton, &ClickableLabel::clickedLeftButton, this, &AlgoMenu::playButtonClicked);

    // Stop button
    _stopButton->setPixmap(QPixmap(ImagesPaths::StopButtonImage));
    _stopButton->setCursor(Qt::PointingHandCursor);
    _stopButton->setToolTip("");
    _stopButton->move((int)AlgoMenuProps::StopButtonX, (int)AlgoMenuProps::StopButtonY);
    connect(_stopButton, &ClickableLabel::clickedLeftButton, this, &AlgoMenu::stopButtonClicked);

    // Animation player
    _videoPlayer->setSource(QUrl(VideosPaths::BFSVideosPath + "video1.mp4"));
    _videoPlayer->setVideoOutput(_videoWidget);
    _videoWidget->setGeometry(302, 80, 628, 460);
    _videoWidget->hide();
    _videoPlayer->stop();
}

double AlgoMenu::getSliderValueByPos(int x)
{
    switch (x)
    {
    case 0:
        return 0.25;
    case 1:
        return 0.5;
    case 2:
        return 1;
    case 3:
        return 2;
    case 4:
        return 4;
    default:
        return 1;
    }
}

int AlgoMenu::getSliderPosByValue(double x)
{
    if (x == 0.25)
        return 0;
    else if (x == 0.5)
        return 1;
    else if (x == 1)
        return 2;
    else if (x == 2)
        return 3;
    else if (x == 4)
        return 4;
    else
        return 1;
}

int AlgoMenu::getVertexByIndex(int index)
{
    switch (index)
    {
    default:
        if (_isBFS)
            return (int)BFSVertices::A;
        else
            return (int)DFSVertices::A;
    case 1:
        if (_isBFS)
            return (int)BFSVertices::B;
        else
            return (int)DFSVertices::B;
    case 2:
        if (_isBFS)
            return (int)BFSVertices::C;
        else
            return (int)DFSVertices::C;
    case 3:
        if (_isBFS)
            return (int)BFSVertices::D;
        else
            return (int)DFSVertices::D;
    case 4:
        if (_isBFS)
            return (int)BFSVertices::E;
        else
            return (int)DFSVertices::E;
    }
}
