#include <iostream>
#include "header.h"

int main() {


    clock_t start, end;
    string box_name = "16700f77e68578e.txt";
    OneMoreOperator oneMoreOperator;
    string file_path = "../box_info/" + box_name;
    cout << "file path: " << file_path << endl;
    oneMoreOperator.ReadDataFromTxt(file_path);

    if (oneMoreOperator.file_content.empty()){
        exit(1);
    }
    oneMoreOperator.analysis(oneMoreOperator.file_content, oneMoreOperator.bboxs, oneMoreOperator.big_bboxs);
    cout << "bboxs size: " << oneMoreOperator.bboxs.size() << "个bounding box" << endl;
    if (oneMoreOperator.big_bboxs.empty()){
        cout << "没有符合的大框；" << endl;
        exit(1);
    }
    oneMoreOperator.filter(oneMoreOperator.bboxs, oneMoreOperator.big_bboxs[1]);
    cout << "after filter: " << oneMoreOperator.bboxs.size() << endl;
    if (oneMoreOperator.bboxs.empty()){
        cout << "没有符合要求的Bbox；" << endl;
        exit(1);
    }

    oneMoreOperator.filter_illegal(oneMoreOperator.bboxs);
    cout << "after illegal filter: " << oneMoreOperator.bboxs.size() << endl;
    for (int i = 0; i < oneMoreOperator.bboxs.size(); ++i) {
        cout << oneMoreOperator.bboxs[i].text << " ";
    }
    cout << endl;

    oneMoreOperator.splice_adjacent_box(oneMoreOperator.bboxs);
    cout << oneMoreOperator.bboxs.size() << endl;

    oneMoreOperator.cluster_col(oneMoreOperator.bboxs, oneMoreOperator.clusters_col);
    cout << endl << "列内容：" << endl;
    for (int i = 0; i < oneMoreOperator.clusters_col.size(); i++){
        cout << "第" << i + 1 << "列:" << endl;
        for (int j = 0; j < oneMoreOperator.clusters_col[i].size(); j++){
            cout << oneMoreOperator.clusters_col[i][j].text << " ";
        }
        cout << endl;
    }
    cout << endl;

    oneMoreOperator.cluster_col_row(oneMoreOperator.clusters_col, oneMoreOperator.clusters_col_row);

    vector<string> res = oneMoreOperator.list_res(oneMoreOperator.clusters_col);
//    vector<string> res = oneMoreOperator.list_final_res(oneMoreOperator.clusters_col_row);
    cout << "运算：" << endl;
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }

    return 0;
}