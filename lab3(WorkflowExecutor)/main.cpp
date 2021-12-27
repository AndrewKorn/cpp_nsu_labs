#include <iostream>
#include <fstream>
#include "WorkflowExecutor.h"

int main() {
    std::ifstream file;
    file.open("D:/cpp/cpp_nsu_labs/lab3(WorkflowExecutor)/in1.txt");
    WorkflowExecutor executor;
    executor.ExecuteWorkflow(file);
    file.close();
    return 0;
}
