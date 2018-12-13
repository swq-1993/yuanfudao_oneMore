#include <iostream>
#include "header.h"

int main() {

    clock_t start, end;
    string box_name = "163da0f7b3aea3e.txt";
    OneMoreOperator oneMoreOperator;
    string file_path = "../box_info/" + box_name;
//    std::cout << "file path: " << file_path << std::endl;
    oneMoreOperator.ReadDataFromTxt(file_path);
    if (oneMoreOperator.file_content.empty()){
        exit(1);
    }
    oneMoreOperator.analysis(oneMoreOperator.file_content, oneMoreOperator.bboxs, oneMoreOperator.big_bboxs);
//    std::cout << "bboxs size: " << oneMoreOperator.bboxs.size() << "个bounding box" << std::endl;
    if (oneMoreOperator.big_bboxs.empty()){
        std::cout << "没有符合的大框；" << std::endl;
        exit(1);
    }
//    cout << oneMoreOperator.big_bboxs.size() << endl;
    oneMoreOperator.filter(oneMoreOperator.bboxs, oneMoreOperator.big_bboxs[0]);
//    std::cout << "after filter: " << oneMoreOperator.bboxs.size() << std::endl;
    if (oneMoreOperator.bboxs.empty()){
        std::cout << "没有符合要求的Bbox；" << std::endl;
        exit(1);
    }

    /*oneMoreOperator.filter_illegal(oneMoreOperator.bboxs);
    std::cout << "after illegal filter: " << oneMoreOperator.bboxs.size() << std::endl;
    for (int i = 0; i < oneMoreOperator.bboxs.size(); ++i) {
        std::cout << oneMoreOperator.bboxs[i].text << " ";
    }
    std::cout << std::endl;

    oneMoreOperator.splice_adjacent_box(oneMoreOperator.bboxs);
    std::cout << oneMoreOperator.bboxs.size() << std::endl;

    oneMoreOperator.cluster_col(oneMoreOperator.bboxs, oneMoreOperator.clusters_col);
    std::cout << std::endl << "列内容：" << std::endl;
    for (int i = 0; i < oneMoreOperator.clusters_col.size(); i++){
        std::cout << "第" << i + 1 << "列:" << std::endl;
        for (int j = 0; j < oneMoreOperator.clusters_col[i].size(); j++){
            std::cout << oneMoreOperator.clusters_col[i][j].text << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    oneMoreOperator.cluster_col_row(oneMoreOperator.clusters_col, oneMoreOperator.clusters_col_row);

    vector<string> res = oneMoreOperator.list_res(oneMoreOperator.clusters_col);
//    vector<string> res = oneMoreOperator.list_final_res(oneMoreOperator.clusters_col_row);
    std::cout << "运算：" << std::endl;
    for (int i = 0; i < res.size(); i++){
        std::cout << res[i] << std::endl;
    }*/

    oneMoreOperator.run_result();
    /*for (int i = 0; i < oneMoreOperator.hand_write_index.size(); i++){
        for (int j = 0; j < oneMoreOperator.hand_write_index[i].size(); j++){
            cout << oneMoreOperator.hand_write_index[i][j] << " ";
        }
        cout << endl;
    }*/

    /*for (int i = 0; i < oneMoreOperator.find_oper.size(); i++){
        for (int j = 0; j < oneMoreOperator.find_oper[i].size(); j++){
            cout << oneMoreOperator.find_oper[i][j] << " ";
        }
        cout << "$";
        for (int j = 0; j < oneMoreOperator.find_equal[i].size(); j++){
            cout << oneMoreOperator.find_equal[i][j] << " ";
        }
        cout << endl;
    }*/

    for (int i = 0; i < oneMoreOperator.final_res.size(); i++){
//        cout << oneMoreOperator.final_res[i].y << " ";
        for (int j = 0; j < oneMoreOperator.final_res[i].splice_result.size(); j++){
            cout << oneMoreOperator.final_res[i].splice_result[j] << " ";
        }
        cout << endl;
    }

    return 0;
}