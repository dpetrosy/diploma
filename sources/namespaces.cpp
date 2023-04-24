#include "helpers.hpp"

namespace StylesPaths
{
    QString StylesPath = ":/styles/";
    QString MainMenuButtonStyle = StylesPath + "main_menu_button.txt";
    QString OneLineTextStyle = StylesPath + "one_line_text.txt";
    QString ComboBoxStyle = StylesPath + "combobox.txt";
    QString DimTextStyle = StylesPath + "dim_text.txt";
    QString BoldDimTextStyle = StylesPath + "bold_dim_text.txt";
    QString SliderStyle = StylesPath + "slider.txt";
    QString PseudocodeStyle = StylesPath + "pseudocode.txt";
    QString AboutTextStyle = StylesPath + "about_text.txt";
    QString AboutTitleStyle = StylesPath + "about_title.txt";
    QString SimilarTitleStyle = StylesPath + "similar_title.txt";
    QString SimilarTextStyle = StylesPath + "similar_text.txt";
    QString MenuStyle = StylesPath + "menu.txt";
    QString CompTextStyle = StylesPath + "comp_text.txt";
}

namespace ImagesPaths
{
    QString ImagesDirPath = ":/images/";
    QString BackgroundsDirPath = ImagesDirPath + "backgrounds/";
    QString MainMenuBKGImage = "background";
    QString MenusBKGImage = "white";

    // Buttons
    QString ButtonsDirPath = ImagesDirPath + "buttons/";
    QString PauseButtonImage = ButtonsDirPath + "pause_button.png";
    QString PlayButtonImage = ButtonsDirPath + "play_button.png";
    QString StopButtonImage = ButtonsDirPath + "stop_button.png";

    // Graphs
    QString GraphsDirPath = ImagesDirPath + "graphs/";
    QString SmallGraphImage = GraphsDirPath + "small_graph.png";
    QString LargeGraphImage = GraphsDirPath + "large_graph.png";

    // Comapre with
    QString AnalysisDirPath = ImagesDirPath + "analysis/";
    QString CompareWithDirPath = AnalysisDirPath + "compare_with/";
    QString BFSWithDFS = CompareWithDirPath + "bfs_with_dfs.png";
    QString BFSWithBeam = CompareWithDirPath + "bfs_with_beam.png";
    QString BFSWithDijkstra = CompareWithDirPath + "bfs_with_dijkstra.png";
    QString BFSWithBidirectional = CompareWithDirPath + "bfs_with_bidirectional.png";
    QString BFSWithAll = CompareWithDirPath + "bfs_with_all.png";

    QString DFSWithBFS = CompareWithDirPath + "dfs_with_bfs.png";
    QString DFSWithBeam = CompareWithDirPath + "dfs_with_beam.png";
    QString DFSWithDijkstra = CompareWithDirPath + "dfs_with_dijkstra.png";
    QString DFSWithBidirectional = CompareWithDirPath + "dfs_with_bidirectional.png";
    QString DFSWithAll = CompareWithDirPath + "bfs_with_all.png";

    // Performance analysis
    QString PerfBFSImage1 = AnalysisDirPath + "perf_bfs1.png";
    QString PerfBFSImage2 = AnalysisDirPath + "perf_bfs2.png";
    QString PerfDFSImage1 = AnalysisDirPath + "perf_dfs1.png";
    QString PerfDFSImage2 = AnalysisDirPath + "perf_dfs2.png";
}

namespace TextsPaths
{
    QString TextsPath = ":/texts/";
    QString BFSPseudocodePath = TextsPath + "bfs_pseudocode.txt";
    QString DFSPseudocodePath = TextsPath + "dfs_pseudocode.txt";
    QString AboutBFSPath = TextsPath + "about_bfs.txt";
    QString AboutDFSPath = TextsPath + "about_dfs.txt";
    QString SimilarAlgosPath = TextsPath + "similar_algos_text.txt";
    QString CompBFSPath = TextsPath + "comp_bfs.txt";
    QString CompDFSPath = TextsPath + "comp_dfs.txt";
}

namespace VideosPaths
{
    QString VideosPath = "qrc:/videos/";
    QString BFSVideosPath = VideosPath + "bfs_videos/";
}
