#include <iostream>
#include "header.h"

int main() {

    string box_name = "";
    OneMoreOperator oneMoreOperator;
    string file_path = "./" + box_name;
    cout << file_path << endl;
    oneMoreOperator.ReadDataFromTxt(file_path);

    if (oneMoreOperator.file_content.empty()){
        cout << "未从识别文档中解析出结果；" << endl;
        exit(1);
    }
    oneMoreOperator.analysis(oneMoreOperator.file_content, oneMoreOperator.bboxs, oneMoreOperator.big_bboxs);
    cout << "bboxs size: " << oneMoreOperator.bboxs.size() << endl;
    oneMoreOperator.filter(oneMoreOperator.bboxs, oneMoreOperator.big_bboxs[0]);
    cout << "after filter: " << oneMoreOperator.bboxs.size() << endl;
    for (int i = 0; i < oneMoreOperator.bboxs.size(); ++i) {
        cout << oneMoreOperator.bboxs[i].text << " ";
    }
    cout << endl;

    oneMoreOperator.cluster_col(oneMoreOperator.bboxs, oneMoreOperator.clusters_col);
    cout << "列内容：" << endl;
    for (int i = 0; i < oneMoreOperator.clusters_col.size(); i++){
        for (int j = 0; j < oneMoreOperator.clusters_col[i].size(); j++){
            cout << oneMoreOperator.clusters_col[i][j].text << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}