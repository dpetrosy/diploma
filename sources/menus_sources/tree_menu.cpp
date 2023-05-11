#include "tree_menu.hpp"
#include "clickablelabel.hpp"
#include "helpers.hpp"
#include "mainwindow.hpp"
#include "utils.hpp"

TreeMenu::TreeMenu(bool isRBTree, MainWindow* mainWindow, QWidget* parent) :
    QWidget(parent)
{
    _isRBTree = isRBTree;

    // Init class members
    init();

    // Make Tree Menu
    makeTreeMenu(mainWindow);
}

TreeMenu::~TreeMenu() {}

// Init
void TreeMenu::init()
{
    // Tree settings
    _settingsWidget = new QWidget(this);
    _treeSettingsText = new QLabel(_settingsWidget);
    _operationsText = new QLabel(_settingsWidget);

    _widgetForOperationsLayout = new QWidget(_settingsWidget);
    _operationsVerLayout = new QVBoxLayout(_widgetForOperationsLayout);
    _operationsButtonGroup = new QButtonGroup(_widgetForOperationsLayout);
    _findRadioButton = new QRadioButton();
    _insertRadioButton = new QRadioButton();
    _deleteRadioButton = new QRadioButton();
    _currentOperation = TreesOperations::Find;

    _widgetForSizeLayout = new QWidget(_settingsWidget);
    _sizeVerLayout = new QVBoxLayout(_widgetForSizeLayout);
    _sizeButtonGroup = new QButtonGroup(_widgetForSizeLayout);
    _smallRadioButton = new QRadioButton();
    _largeRadioButton = new QRadioButton();
    _treePicture = new QLabel(this);
    _isSmallTree = true;

    // Animation speed contrlos
    _sliderText = new QLabel(this);
    _sliderNumberText = new QLabel(this);
    _speedSlider = new QSlider(Qt::Horizontal, this);
    _animationSpeed = 1;

    // About tree
    _aboutText = new QLabel(this);
    _aboutTitleText = new QLabel(this);

    // Similar trees
    _similarText = new QTextEdit(this);
    _similarTitleText = new QLabel(this);

    // MenuBar
    _menuBar = new QMenuBar(this);
    _compareWithMenu = new QMenu();
    _analyzeMenu = new QMenu();
    _helpMenu = new QMenu();
    _exitMenu = new QMenu();
////    _compareWithBFS = new QAction(this);
////    _compareWithDFS = new QAction(this);
////    _compareWithBeam = new QAction(this);
////    _compareWithDijkstra = new QAction(this);
////    _compareWithBidirectional = new QAction(this);
////    _compareWithAll = new QAction(this);
    _perfAnalaysis = new QAction(this);
    _aboutProject = new QAction(this);
    _contact = new QAction(this);
    _returnToMainMenu = new QAction(this);
    _exitFromProgram = new QAction(this);

//    // Compare with
//    _compareWithWidget = new QWidget();
//    _compareWithImage = new QLabel(_compareWithWidget);

    // Performance analysis
    _perfAnalysisWidget = new QWidget();
    _perfAnalysisImage = new QLabel(_perfAnalysisWidget);

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
    _videosPrefix = "rb_";
    _videosExtension = ".mp4";
}

// Public util functions
void TreeMenu::prepareMenuBeforeSwitch(bool isRBTree)
{
    // Size Radio buttons
    _smallRadioButton->setChecked("true");
    sizeButtonGroupPressed(0);  // small tree

    // Direct Radio buttons
    _findRadioButton->setChecked(true);
    operationsButtonGroupPressed(0);  // find operation

    // Compare with menu
    //_compareWithMenu->clear();

    _isRBTree = isRBTree;
    if (_isRBTree)
    {
        // About title text
        _aboutTitleText->setText("About RB Tree");

        // About text
        _aboutText->setText(getTextFromFile(TextsPaths::AboutRbTreePath));

        // Complexities text
        _compText->setText(getTextFromFile(TextsPaths::CompRBTreePath));

//        // Comare with menu
//        _compareWithMenu->addAction(_compareWithDFS);
//        _compareWithMenu->addAction(_compareWithBeam);
//        _compareWithMenu->addAction(_compareWithDijkstra);
//        _compareWithMenu->addAction(_compareWithBidirectional);
//        _compareWithMenu->addAction(_compareWithAll);

        // Videos widget
        //setVideoToPlayer(VideosPaths::SmallRBTreePath, TreesOperations::Find);
        _videosPrefix = "rb_";
    }
    else
    {
        // About title text
        _aboutTitleText->setText("About AVL Tree");

        // About text
        _aboutText->setText(getTextFromFile(TextsPaths::AboutAVLTreePath));

        // Complexities text
        _compText->setText(getTextFromFile(TextsPaths::CompAVLTreePath));

//        // Comare with menu
//        _compareWithMenu->addAction(_compareWithBFS);
//        _compareWithMenu->addAction(_compareWithBeam);
//        _compareWithMenu->addAction(_compareWithDijkstra);
//        _compareWithMenu->addAction(_compareWithBidirectional);
//        _compareWithMenu->addAction(_compareWithAll);

        // Videos widget
        //setVideoToPlayer(VideosPaths::SmallAVLTreePath, TreesOperations::Find);
        _videosPrefix = "avl_";
    }
}

// Private slots
void TreeMenu::showPerfAnalaysis()
{
    if (_isRBTree)
        _perfAnalysisImage->setPixmap(QPixmap(ImagesPaths::PerfRBTreeImage));
    else
        _perfAnalysisImage->setPixmap(QPixmap(ImagesPaths::PerfAVlTreeImage));

    _perfAnalysisWidget->show();
}

void TreeMenu::showAboutProject()
{
    QMessageBox::information(this, "About Project", "This is my diploma project: Data structures visualizer.");
}

void TreeMenu::showContact()
{
    QMessageBox::information(this, "Contact", "You can contact with me by LinkedIn.\nMy login: dpetrosy");
}

void TreeMenu::speedSliderValueChanged(int x)
{
    _speedSlider->setValue(x);
    _animationSpeed = getSliderValueByPos(x);
    _sliderNumberText->setText(QString::number(_animationSpeed) + "x");
    _videoPlayer->setPlaybackRate(qreal(_animationSpeed));
}

void TreeMenu::playButtonClicked()
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
        _treePicture->hide();
    }
    else // Pause clicked
    {
        _videoPlayer->pause();
        _isAnimationPaused = true;
        _playButton->setPixmap(QPixmap(ImagesPaths::PlayButtonImage));
        _playButton->setToolTip("Play");
    }
}

void TreeMenu::stopButtonClicked()
{
    _videoWidget->hide();
    _videoPlayer->stop();
    _treePicture->show();
    _isAnimationPaused = true;
    _stopButton->setEnabled(false);
    _stopButton->setToolTip("");
    _playButton->setPixmap(QPixmap(ImagesPaths::PlayButtonImage));
    _playButton->setToolTip("Play");
}

void TreeMenu::operationsButtonGroupPressed(int id)
{
//    stopButtonClicked();
//    speedSliderValueChanged(2);

//    if (id == 0) // small tree choosed
//    {
//        _treePicture->setPixmap(QPixmap(ImagesPaths::SmallTreeImage));
//        _videoPlayer->setSource(QUrl(VideosPaths::RBTreeVideosPath + "video3.mp4"));
//        _videoWidget->setGeometry(302, 80, 628, 460);
//        _treePicture->setGeometry(302, 80, 628, 460);
//    }
//    else // large tree choosed
//    {
//        _treePicture->setPixmap(QPixmap(ImagesPaths::LargeTreeImage));
//        _videoPlayer->setSource(QUrl(VideosPaths::RBTreeVideosPath + "video2.mp4"));
//        _videoWidget->setGeometry(302, 80, 612, 490);
//        _treePicture->setGeometry(302, 80, 612, 490);
//    }
}

void TreeMenu::sizeButtonGroupPressed(int id)
{
    stopButtonClicked();
    speedSliderValueChanged(2);

    if (id == 0) // small tree choosed
    {
        _isSmallTree = true;

        if (_isRBTree)
        {
            //setVideoToPlayer(VideosPaths::SmallGraphBFSPath, _currentOperation);
            _treePicture->setPixmap(QPixmap(ImagesPaths::SmallRBTreeImage));
        }
        else
        {
            //setVideoToPlayer(VideosPaths::SmallGraphDFSPath, _currentOperation);
            _treePicture->setPixmap(QPixmap(ImagesPaths::SmallAVLTreeImage));
        }
    }
    else // large tree choosed
    {
        _isSmallTree = false;

        if (_isRBTree)
        {
            setVideoToPlayer(VideosPaths::LargeGraphBFSPath, _currentOperation);
            _treePicture->setPixmap(QPixmap(ImagesPaths::LargeRBTreeImage));
        }
        else
        {
            setVideoToPlayer(VideosPaths::LargeGraphDFSPath, _currentOperation);
            _treePicture->setPixmap(QPixmap(ImagesPaths::LargeAVLTreeImage));
        }
    }
}

// Private util functions
void TreeMenu::makeTreeMenu(MainWindow* mainWindow)
{
    // Settings Widget
    _settingsWidget->setObjectName("SettingsWidgetInTree");
    _settingsWidget->setGeometry((int)TreeMenuProps::SettingsWidgetX, (int)TreeMenuProps::SettingsWidgetY, (int)TreeMenuProps::SettingsWidgetW, (int)TreeMenuProps::SettingsWidgetH);
    _settingsWidget->setStyleSheet("#SettingsWidgetInTree { background-color: #f7f6f5; border: 1px solid #d2d2d2; border-radius: 4px; }");

    // Settings text
    _treeSettingsText->setText("Choose Tree Settings");
    ::setStyleSheet(StylesPaths::OneLineTextStyle , _treeSettingsText);
    setLabelTextFont(_treeSettingsText, 11);
    _treeSettingsText->move((int)TreeMenuProps::SettingsTextX, (int)TreeMenuProps::SettingsTextY);

    // Operations text
    _operationsText->setText("Tree Operations");
    ::setStyleSheet(StylesPaths::OneLineTextStyle , _operationsText);
    _operationsText->move((int)TreeMenuProps::OperationsTextX, (int)TreeMenuProps::OperationsTextY);
    setLabelTextFont(_operationsText, 10);

    // Operations Radio buttons
    _findRadioButton->setText("Find");
    _findRadioButton->setFont(QFont("Segoe UI ", 12));
    _findRadioButton->setCursor(Qt::PointingHandCursor);
    _insertRadioButton->setText("Insert");
    _insertRadioButton->setFont(QFont("Segoe UI ", 12));
    _insertRadioButton->setCursor(Qt::PointingHandCursor);
    _deleteRadioButton->setText("Delete");
    _deleteRadioButton->setFont(QFont("Segoe UI ", 12));
    _deleteRadioButton->setCursor(Qt::PointingHandCursor);
    _operationsButtonGroup->addButton(_findRadioButton, (int)OperationsRadioButtons::FindButton);
    _operationsButtonGroup->addButton(_insertRadioButton, (int)OperationsRadioButtons::InsertButton);
    _operationsButtonGroup->addButton(_deleteRadioButton, (int)OperationsRadioButtons::DeleteButton);
    _operationsVerLayout->addWidget(_findRadioButton);
    _operationsVerLayout->addWidget(_insertRadioButton);
    _operationsVerLayout->addWidget(_deleteRadioButton);
    _widgetForOperationsLayout->setLayout(_operationsVerLayout);
    _widgetForOperationsLayout->setGeometry((int)TreeMenuProps::OperationsWidgetX, (int)TreeMenuProps::OperationsWidgetY, (int)TreeMenuProps::OperationsWidgetW, (int)TreeMenuProps::OperationsWidgetH);
    connect(_operationsButtonGroup, &QButtonGroup::idPressed, this, &TreeMenu::operationsButtonGroupPressed);

    // Size Radio buttons
    _smallRadioButton->setText("Small Tree");
    _smallRadioButton->setFont(QFont("Segoe UI ", 12));
    _smallRadioButton->setCursor(Qt::PointingHandCursor);
    _largeRadioButton->setText("Large Tree");
    _largeRadioButton->setFont(QFont("Segoe UI ", 12));
    _largeRadioButton->setCursor(Qt::PointingHandCursor);
    _sizeButtonGroup->addButton(_smallRadioButton, (int)SizeRadioButtons::SmallButton);
    _sizeButtonGroup->addButton(_largeRadioButton, (int)SizeRadioButtons::LargeButton);
    _sizeVerLayout->addWidget(_smallRadioButton);
    _sizeVerLayout->addWidget(_largeRadioButton);
    _widgetForSizeLayout->setLayout(_sizeVerLayout);
    _widgetForSizeLayout->setGeometry((int)TreeMenuProps::SizeWidgetX, (int)TreeMenuProps::SizeWidgetY, (int)TreeMenuProps::SizeWidgetW, (int)TreeMenuProps::SizeWidgetH);
    connect(_sizeButtonGroup, &QButtonGroup::idPressed, this, &TreeMenu::sizeButtonGroupPressed);

    // Speed Slider Text
    _sliderText->setText("Animation speed:");
    ::setStyleSheet(StylesPaths::DimTextStyle, _sliderText);
    _sliderText->move((int)TreeMenuProps::SliderTextX, (int)TreeMenuProps::SliderTextY);

    // Speed Slider Number Text
    _sliderNumberText->setText("1x");
    ::setStyleSheet(StylesPaths::BoldDimTextStyle, _sliderNumberText);
    _sliderNumberText->move((int)TreeMenuProps::SliderTextNumberX, (int)TreeMenuProps::SliderTextNumberY);
    _sliderNumberText->setFixedWidth(50);

    // Speed slider
    _speedSlider->setGeometry((int)TreeMenuProps::SliderX, (int)TreeMenuProps::SliderY, (int)TreeMenuProps::SliderW, (int)TreeMenuProps::SliderH);
    ::setStyleSheet(StylesPaths::SliderStyle, _speedSlider);
    _speedSlider->setCursor(Qt::PointingHandCursor);
    _speedSlider->setRange(0, 4);
    _speedSlider->setValue(getSliderPosByValue(_animationSpeed));
    connect(_speedSlider, &QSlider::valueChanged, this, &TreeMenu::speedSliderValueChanged);

    // About title text
    _aboutTitleText->setText("About RB Tree");
    ::setStyleSheet(StylesPaths::AboutTitleStyle, _aboutTitleText);
    setLabelTextFont(_aboutTitleText, 11);
    _aboutTitleText->setFixedWidth(115);
    _aboutTitleText->setGeometry((int)TreeMenuProps::AboutTitleTextX, (int)TreeMenuProps::AboutTitleTextY, 100, 21);

    // About text
    _aboutText->setText(getTextFromFile(TextsPaths::AboutRbTreePath));
    ::setStyleSheet(StylesPaths::AboutTextStyle, _aboutText);
    _aboutText->setGeometry((int)TreeMenuProps::AboutTextX, (int)TreeMenuProps::AboutTextY, (int)TreeMenuProps::AboutTextW, (int)TreeMenuProps::AboutTextH);

    // Similar title text
    _similarTitleText->setText("Similar Trees");
    ::setStyleSheet(StylesPaths::SimilarTitleStyle, _similarTitleText);
    _similarTitleText->move((int)TreeMenuProps::SimilarTitleTextX, (int)TreeMenuProps::SimilarTitleTextY);

    // Similar text
    _similarText->setReadOnly(true);
    _similarText->setPlainText(deleteNewlineAtEnd(getTextFromFile(TextsPaths::SimilarTreesPath)));
    ::setStyleSheet(StylesPaths::SimilarTextStyle, _similarText);
    QTextBlockFormat blockFormat;
    blockFormat.setLineHeight(130, QTextBlockFormat::ProportionalHeight);
    QTextCursor cursor = _similarText->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.setBlockFormat(blockFormat);
    _similarText->setGeometry((int)TreeMenuProps::SimilarTextX, (int)TreeMenuProps::SimilarTextY, (int)TreeMenuProps::SimilarTextW, (int)TreeMenuProps::SimilarTextH);

    // Complexities title text
    _compTitleText->setText("Complexities");
    ::setStyleSheet(StylesPaths::SimilarTitleStyle, _compTitleText);
    _compTitleText->move((int)TreeMenuProps::CompTitleTextX, (int)TreeMenuProps::CompTitleTextY);

    // Complexities text
    _compText->setText(getTextFromFile(TextsPaths::CompRBTreePath));
    ::setStyleSheet(StylesPaths::CompTextStyle, _compText);
    _compText->setGeometry((int)TreeMenuProps::CompTextX, (int)TreeMenuProps::CompTextY, (int)TreeMenuProps::CompTextW, (int)TreeMenuProps::CompTextH);

    // MenuBar
    _analyzeMenu->setTitle("Analyze");
    _analyzeMenu->addMenu(_compareWithMenu);
    _analyzeMenu->addAction(_perfAnalaysis);
    _perfAnalaysis->setText("Performance Analysis");
    connect(_perfAnalaysis, &QAction::triggered, this, &TreeMenu::showPerfAnalaysis);

    _compareWithMenu->setTitle("Comapre With...");
    _compareWithMenu->addAction("AVL Tree");
    _compareWithMenu->addAction("B Tree");
    _compareWithMenu->addAction("2-3 Tree");
    _compareWithMenu->addAction("Binary Search Tree");
    _compareWithMenu->addAction("All Trees");
    //    _compareWithBFS->setText("BFS Algorithm");
    //    _compareWithDFS->setText("DFS Algorithm");
    //    _compareWithBeam->setText("Beam Search");
    //    _compareWithDijkstra->setText("Dijkstra's Algorithm");
    //    _compareWithBidirectional->setText("Bidirectional Search");
    //    _compareWithAll->setText("All Algorithms");
    //    connect(_compareWithBFS, &QAction::triggered, this, std::bind(&TreeMenu::showCompareWith, this, CompareWithAlgos::BFS));
    //    connect(_compareWithDFS, &QAction::triggered, this, std::bind(&TreeMenu::showCompareWith, this, CompareWithAlgos::DFS));
    //    connect(_compareWithBeam, &QAction::triggered, this, std::bind(&TreeMenu::showCompareWith, this, CompareWithAlgos::Beam));
    //    connect(_compareWithDijkstra, &QAction::triggered, this, std::bind(&TreeMenu::showCompareWith, this, CompareWithAlgos::Dijkstra));
    //    connect(_compareWithBidirectional, &QAction::triggered, this, std::bind(&TreeMenu::showCompareWith, this, CompareWithAlgos::Bidirectional));
    //    connect(_compareWithAll, &QAction::triggered, this, std::bind(&TreeMenu::showCompareWith, this, CompareWithAlgos::All));

    _helpMenu->setTitle("Help");
    _helpMenu->addAction(_aboutProject);
    _helpMenu->addAction(_contact);
    _aboutProject->setText("About Project");
    _contact->setText("Contact");
    connect(_aboutProject, &QAction::triggered, this, &TreeMenu::showAboutProject);
    connect(_contact, &QAction::triggered, this, &TreeMenu::showContact);

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

    // Tree picture
    _treePicture->setPixmap(QPixmap(ImagesPaths::SmallRBTreeImage));
    _treePicture->move(302, 80);

//    // Compare with
//    _compareWithWidget->hide();
//    _compareWithWidget->setWindowTitle("Comapare With");
//    _compareWithWidget->setWindowModality(Qt::ApplicationModal);
//    _compareWithWidget->setFixedSize((int)TreeMenuProps::CompareWidgetW, (int)TreeMenuProps::CompareWidgetH);
//    _compareWithWidget->setObjectName("CompareWidget");
//    _compareWithWidget->setStyleSheet("#CompareWidget { background-color: #ffffff; }");
//    _compareWithImage->setPixmap(QPixmap(ImagesPaths::DFSWithBeam));
//    _compareWithImage->move((int)TreeMenuProps::CompareImageX, (int)TreeMenuProps::CompareImageY);

    // Performance analysis
    _perfAnalysisWidget->hide();
    _perfAnalysisWidget->setWindowTitle("Performance Analysis");
    _perfAnalysisWidget->setWindowModality(Qt::ApplicationModal);
    _perfAnalysisWidget->setFixedSize((int)TreeMenuProps::PerfWidgetW, (int)TreeMenuProps::PerfWidgetH);
    _perfAnalysisWidget->setObjectName("PerfWidgetForTrees");
    _perfAnalysisWidget->setStyleSheet("#PerfWidgetForTrees { background-color: #ffffff; }");
    _perfAnalysisImage->setPixmap(QPixmap(ImagesPaths::PerfRBTreeImage));
    _perfAnalysisImage->move((int)TreeMenuProps::PerfImageX, (int)TreeMenuProps::PerfImageY);

    // Play button
    _playButton->setPixmap(QPixmap(ImagesPaths::PlayButtonImage));
    _playButton->setCursor(Qt::PointingHandCursor);
    _playButton->move((int)TreeMenuProps::PlayButtonX, (int)TreeMenuProps::PlayButtonY);
    _playButton->setToolTip("Play");
    connect(_playButton, &ClickableLabel::clickedLeftButton, this, &TreeMenu::playButtonClicked);

    // Stop button
    _stopButton->setPixmap(QPixmap(ImagesPaths::StopButtonImage));
    _stopButton->setCursor(Qt::PointingHandCursor);
    _stopButton->setToolTip("");
    _stopButton->move((int)TreeMenuProps::StopButtonX, (int)TreeMenuProps::StopButtonY);
    connect(_stopButton, &ClickableLabel::clickedLeftButton, this, &TreeMenu::stopButtonClicked);

    // Animation player
    _videoPlayer->setSource(QUrl(VideosPaths::SmallRBTreePath + "video.mp4"));
    _videoPlayer->setVideoOutput(_videoWidget);
    _videoWidget->setGeometry(302, 150, 710, 240);
    _videoWidget->hide();
    _videoPlayer->stop();
}

double TreeMenu::getSliderValueByPos(int x)
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

int TreeMenu::getSliderPosByValue(double x)
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

QString TreeMenu::getOperStrByValue(TreesOperations operation)
{
    switch (operation)
    {
    default:
        return "find";
    case TreesOperations::Insert:
        return "insert";
    case TreesOperations::Delete:
        return "delete";
    }
}

void TreeMenu::setVideoToPlayer(QString path, TreesOperations operation)
{
    QString operStr = getOperStrByValue(operation);
    _videoPlayer->setSource(QUrl(path + _videosPrefix + operStr + _videosExtension));
}
