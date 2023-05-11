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

    // Trees
    QString TreesDirPath = ImagesDirPath + "trees/";
    QString SmallRBTreeImage = TreesDirPath + "rb_small_tree.png";
    QString LargeRBTreeImage = TreesDirPath + "rb_large_tree.png";
    QString SmallAVLTreeImage = TreesDirPath + "avl_small_tree.png";
    QString LargeAVLTreeImage = TreesDirPath + "avl_large_tree.png";

    // Graphs
    QString GraphsDirPath = ImagesDirPath + "graphs/";
    QString BFSSmallGraphImage = GraphsDirPath + "bfs_small_graph.png";
    QString BFSLargeGraphImage = GraphsDirPath + "bfs_large_graph.png";
    QString DFSSmallGraphImage = GraphsDirPath + "dfs_small_graph.png";
    QString DFSLargeGraphImage = GraphsDirPath + "dfs_large_graph.png";

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
    QString PerfRBTreeImage = AnalysisDirPath + "perf_rb_tree.png";
    QString PerfAVlTreeImage = AnalysisDirPath + "perf_avl_tree.png";
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
    QString AboutRbTreePath = TextsPath + "about_rb_tree.txt";
    QString AboutAVLTreePath = TextsPath + "about_avl_tree.txt";
    QString AboutBFSPath = TextsPath + "about_bfs.txt";
    QString AboutDFSPath = TextsPath + "about_dfs.txt";
    QString SimilarTreesPath = TextsPath + "similar_trees_text.txt";
    QString SimilarAlgosPath = TextsPath + "similar_algos_text.txt";
    QString CompRBTreePath = TextsPath + "comp_rb_tree.txt";
    QString CompAVLTreePath = TextsPath + "comp_avl_tree.txt";
    QString CompBFSPath = TextsPath + "comp_bfs.txt";
    QString CompDFSPath = TextsPath + "comp_dfs.txt";
}

namespace VideosPaths
{
    QString VideosPath = "qrc:/videos/";

    // Trees videos
    QString AlgoVideosPath = VideosPath + "algo_videos/";
    QString SmallGraphPath = AlgoVideosPath + "small_graph/";
    QString LargeGraphPath = AlgoVideosPath + "large_graph/";
    QString SmallGraphBFSPath = SmallGraphPath + "bfs/";
    QString SmallGraphDFSPath = SmallGraphPath + "dfs/";
    QString LargeGraphBFSPath = LargeGraphPath + "bfs/";
    QString LargeGraphDFSPath = LargeGraphPath + "dfs/";

    // Trees videos
    QString TreeVideosPath = VideosPath + "tree_videos/";
    QString SmallTreePath = TreeVideosPath + "small_tree/";
    QString LargeTreePath = TreeVideosPath + "large_tree/";
    QString SmallRBTreePath = SmallTreePath + "rb_tree/";
    QString SmallAVLTreePath = SmallTreePath + "avl_tree/";
    QString LargeRBTreePath = LargeTreePath + "rb_tree/";
    QString LargeAVLTreePath = LargeTreePath + "avl_tree";
}
