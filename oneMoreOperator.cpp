//
// Created by sunwanqi on 2018/11/22.
//
#include "header.h"

//用字符串展示一拖多的结果
vector<string> OneMoreOperator::list_res(vector<vector<Bbox>>& clusters_col) {
    string tmp = "";
    vector<string> res;
    int max_row = -1;
    for (int i = 0; i < clusters_col.size(); i++){
        max_row = max(max_row, (int)clusters_col[i].size());
    }

    for (int i = 0; i < max_row; i++){

        for (int j = 0; j < clusters_col.size(); j++){
            if (clusters_col[j].empty()){
                continue;
            }
            if (clusters_col[j].size() == 1){
                tmp += " ";
                tmp += clusters_col[j][0].text;
            }
            else if (clusters_col[j].size() > i){
                tmp += " ";
                tmp += clusters_col[j][i].text;
            }
//            else if (clusters_col[j].size() <= i){
//                tmp += " ";
//                tmp += clusters_col[j].back().text;
//            }
        }
//        删除第一个空格字符
        if (tmp.length() > 1 && tmp[0] == ' '){
            tmp.erase(0, 1);
        }
        res.push_back(tmp);
        tmp = "";
    }

    return res;
}

//用IOU的思想对 列 进行聚类
void OneMoreOperator::cluster_col(vector<Bbox>& bboxs, vector<vector<Bbox>>& clusters_col)
{
    vector<Bbox> copy = bboxs;
    sort(copy.begin(), copy.end(), compare_col);
    vector<bool> flag(copy.size(), true);
    vector<Bbox> tmp;
    for (int i = 0; i < copy.size(); i++)
    {
        if (!flag[i]){
            continue;
        }
        int tmp_left = copy[i].x;
        int tmp_right = copy[i].x + copy[i].width;
        tmp.push_back(copy[i]);
        flag[i] = false;
        for (int j = 0; j < copy.size(); j++)
        {
            if (!flag[j]){
                continue;
            }
            int Iou_min = max(tmp_left, copy[j].x);
            int Iou_max = min(tmp_right, copy[j].x + copy[j].width);

            /*cout << "compare: " << copy[i].x << " " << copy[i].text << " " << copy[j].x << " " << copy[j].text << endl;
            cout << tmp_left << " " << tmp_right << endl;
            cout << (double)(Iou_max - Iou_min);
            cout << " " << (double)(0.5 * copy[j].height) << endl;*/
            if (((double)(Iou_max - Iou_min) > (0.5 * copy[j].width) && copy[j].x <= tmp_left + (tmp_right - tmp_left) * 0.5)
                    || (copy[j].x > tmp_left && copy[j].x + copy[j].width < tmp_right)){

//                cout << "lianjie: " << copy[j].text << endl;
                tmp.push_back(copy[j]);
                tmp_left = min(tmp_left, copy[j].x);
                tmp_right = max(tmp_right, copy[j].x + copy[j].width);
                flag[j] = false;
            }
        }
        sort(tmp.begin(), tmp.end(), [](const Bbox &a, const Bbox &b){return a.y < b.y;});
        clusters_col.push_back(tmp);
        tmp.clear();
    }
    sort(clusters_col.begin(), clusters_col.end(), [](const vector<Bbox> &a, const vector<Bbox> &b){ return a[0].x < b[0].x;});
}

//按照上和左的位置进行排序
bool OneMoreOperator::compare(const Bbox a, const Bbox b) {
    if (a.y < b.y)
        return true;
    else if (a.y == b.y)
        return a.x < b.x;
    else
        return false;
}

bool OneMoreOperator::compare_col(const Bbox a, const Bbox b){
    if (a.x < b.x)
        return true;
    else if (a.x == b.x)
        return a.y < b.y;
    else
        return false;
}

bool OneMoreOperator::part_match(string a, char c){
    for (char single : a){
        if (single == c){
            return true;
        }
    }
    return false;
}

bool OneMoreOperator::has_illegal_char(Bbox bbox){
    for (int i = 0; i < illegal_char.size(); i++){
        if (part_match(bbox.text, illegal_char[i])){
            return true;
        }
    }
    return false;
}

//过滤筛选之后中含有非法字符的Bbox
void OneMoreOperator::filter_illegal(vector<Bbox>& bboxs){
    vector<Bbox> tmp;
    for (int i = 0; i < bboxs.size(); i++){
        if (!has_illegal_char(bboxs[i])){
            tmp.push_back(bboxs[i]);
        }
    }
    bboxs.clear();
    bboxs = tmp;
}

//过滤掉大框外面的小框
void OneMoreOperator::filter(vector<Bbox>& bboxs, Big_bbox big_bbox){
    vector<Bbox> tmp;
    for (int i = 0; i < bboxs.size(); i++){
        int Iou_min_row = max(bboxs[i].x, big_bbox.x);
        int Iou_max_row = min(bboxs[i].x + bboxs[i].width, big_bbox.x + big_bbox.width);

        int Iou_min_col = max(bboxs[i].y, big_bbox.y);
        int Iou_max_col = min(bboxs[i].y + bboxs[i].height, big_bbox.y + big_bbox.height);

//        if (Iou_max_row >= Iou_min_row && Iou_max_col >= Iou_min_col){
        //增加过滤条件
        if ((Iou_max_row - Iou_min_row >= bboxs[i].width * 0.75) && (Iou_max_col - Iou_min_col >= bboxs[i].height * 0.5)){
            tmp.push_back(bboxs[i]);
        }
    }
    bboxs.clear();
    bboxs = tmp;
}

//将拆分下来的字符串，按照内容，封装到一个bounding box结构体对象里面
void OneMoreOperator::analysis(vector<string>& file_content, vector<Bbox>& bboxs, vector<Big_bbox>& big_bboxs) {
    for (int i = 0; i < file_content.size(); i++) {
        Bbox bbox;
        Big_bbox big_bbox;
        vector<string> splitedLine = split_line(file_content[i], ' ');
        if (splitedLine.size() >= 5){
            string class_id = split_line(splitedLine[4], ':')[1];
            if (class_id == "203" || class_id == "206") {
                big_bbox.x = stoi(split_line(splitedLine[0], ':')[1]);
                big_bbox.y = stoi(split_line(splitedLine[1], ':')[1]);
                big_bbox.width = stoi(split_line(splitedLine[2], ':')[1]);
                big_bbox.height = stoi(split_line(splitedLine[3], ':')[1]);
                big_bbox.class_idx = stoi(split_line(splitedLine[4], ':')[1]);
                big_bboxs.push_back(big_bbox);
            }
            else if(class_id == "101" || class_id == "104"){
                bbox.x = stoi(split_line(splitedLine[0], ':')[1]);
                bbox.y = stoi(split_line(splitedLine[1], ':')[1]);
                bbox.width = stoi(split_line(splitedLine[2], ':')[1]);
                bbox.height = stoi(split_line(splitedLine[3], ':')[1]);
                bbox.class_idx = stoi(split_line(splitedLine[4], ':')[1]);
                if (splitedLine.size() == 6) {
                    bbox.text = split_line(splitedLine[5], ':')[1];
                }
                bboxs.push_back(bbox);
            }

        }

    }
    sort(bboxs.begin(), bboxs.end(), compare);
    sort(big_bboxs.begin(), big_bboxs.end(), [](const Big_bbox &a, const Big_bbox &b){return a.y < b.y;});
}

//实现字符串的split函数
vector<string> OneMoreOperator::split_line(string single_line, char symbol) {
    int pos = 0;
    int npos = 0;
    vector<string> result;
    while ((npos = single_line.find(symbol, pos)) != -1) {
        string tmp = single_line.substr(pos, npos - pos);
        result.push_back(tmp);
        pos = npos + 1;
    }
    result.push_back(single_line.substr(pos, single_line.length() - pos));
    return result;
}

//从识别结果的TXT中读取数据到内存
void OneMoreOperator::ReadDataFromTxt(string filename) {
    ifstream in(filename);
    string line;
    if (in.is_open()) {
        while(getline(in, line)) {
            file_content.push_back(line);
        }
    }
    else {
        cout << "no such file! " << endl;
    }
}

