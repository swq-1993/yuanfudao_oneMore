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
#include <sstream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

//最后要的数据结构结果
struct Res{
    int x;
    int y;
    int width;
    int height;
    vector<string> splice_result;
};

// 单个检测框
struct Bbox{
    int x;
    int y;
    int width;
    int height;
    int class_idx;
    string text = "$BNK$";
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
    vector<string> splice_mid_res;
    vector<vector<string>> splice_res;

    vector<vector<int>> find_oper;
    vector<vector<bool>> find_equal;

    vector<char> illegal_char{'(', ')', ',', ';', ':', '?', '!'};

    vector<char> one_more_oper{'+', '-', '*', '/'};
    vector<string> oper_str{"+", "-", "*", "/", "="};

    //手写体框的位置记录
    vector<vector<bool>> hand_write_index;

    //手写体框的存储
    vector<Bbox> result_boxs;

    //最后要的结果
    vector<Res> final_res;

    //判断两个bbox是否属于同一行
    bool is_in_one_row(Bbox &a, Bbox &b);

    //中间字符串前处理
    void pre_process_mid_res();

    //判断字符串含有哪种运算符号
    vector<int> compute_symbol(string a);

    //判断字符串是否是运算符号
    bool is_compute_symbol(string a);

    //查找字符串数组里是否是有运算符号和等号
    void find_oper_equal();

    //拆分组好的string，添加运算符号，到新的数据结构
    void process_str_res();

    //重新整理输出结构体
    void arrange_res();

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
    void list_res(vector<vector<Bbox>>& clusters_col, vector<string> & splice_res);

    //用字符串展示一拖多的结果
    void list_res(vector<vector<vector<Bbox>>>& clusters_col_row, vector<string>& splice_res);

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
