//
// Created by sunwanqi on 2018/11/22.
//

#ifndef ONEMORE_HEADER_H
#define ONEMORE_HEADER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <map>

using std::vector;
using std::string;

// 单个检测框
struct Bbox{
    int x;
    int y;
    int width;
    int height;
    int class_idx;
    string text = "空";
};

//大框和序号的检测框 200、201、202、203、102
struct Big_bbox{
    int x;
    int y;
    int width;
    int height;
    int class_idx;
};

class OneMoreOperator{

public:

    vector<string> file_content;
    vector<Bbox> bboxs;
    vector<Big_bbox> big_bboxs;
    vector<vector<Bbox>> clusters_col;
    vector<vector<vector<Bbox>>> clusters_col_row;

    vector<char> illegal_char{'(', ')', ',', ';', ':', '?', '!'};

    //集成所需解析box的所有步骤
    void run_result();

    bool part_match(string a, char c);

    //Bbox里面是否含有一拖多非法字符
    bool has_illegal_char(Bbox bbox);

    //过滤筛选之后中含有非法字符的Bbox
    void filter_illegal(vector<Bbox>& bboxs);

    //连接紧挨着的Bbox
    void splice_adjacent_box(vector<Bbox>& bboxs);

    //将列聚类的结果再行聚类一次，用字符串展示一拖多的结果
    vector<string> list_final_res(vector<vector<vector<Bbox>>>& clusters_col_row);

    //用字符串展示一拖多的结果
    vector<string> list_res(vector<vector<Bbox>>& clusters_col);

    //对列里面的Bbox再一次行聚类，合并列中同一行的Bbox
    void cluster_col_row(vector<vector<Bbox>>& clusters_col, vector<vector<vector<Bbox>>>& clusters_col_row);

    //用IOU的思想对 列 进行聚类
    void cluster_col(vector<Bbox>& bboxs, vector<vector<Bbox>>& clusters_col);

    //按照上和左的位置进行排序
    static bool compare(const Bbox &a, const Bbox &b);
    static bool compare_col(const Bbox &a, const Bbox &b);


    //过滤掉大框外面的小框
    void filter(vector<Bbox>& bboxs, Big_bbox big_bbox);

    //将拆分下来的字符串，按照内容，封装到一个bounding box结构体对象里面
    void analysis(vector<string>& file_content, vector<Bbox>& bboxs, vector<Big_bbox>& big_bboxs);

    //实现字符串的split函数
    vector<string> split_line(string single_line, char symbol);

    //从识别结果的TXT中读取数据到内存
    void ReadDataFromTxt(string filename);

};

#endif //ONEMORE_HEADER_H
