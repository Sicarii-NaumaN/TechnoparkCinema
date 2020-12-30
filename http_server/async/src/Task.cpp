#include <functional>
#include <vector>

#include "HTTPClient.hpp"
#include "TaskFuncs.hpp"
#include "Task.hpp"

Task::Task() :
      preFunc(PreProcess),
      mainFunc(MainProcessBasic),
      postFunc(PostProcess) {
    this->input = std::make_shared<HTTPClient>();
    this->output = std::make_shared<HTTPClient>();
}

Task::Task(HTTPClient& input) : Task() {
    this->input = std::make_shared<HTTPClient>(input);
}

PreFuncType Task::GetPreFunc() {
    return preFunc;
}
MainFuncType Task::GetMainFunc() {
    return mainFunc;
}
PostFuncType Task::GetPostFunc() {
    return postFunc;
}

void Task::SetPreFunc(PreFuncType preFunc) { //TODO use or del
    this->preFunc = preFunc;
}
void Task::SetMainFunc(MainFuncType mainFunc) {
    this->mainFunc = mainFunc;
}
void Task::SetPostFunc(PostFuncType postFunc) { //TODO use or del
    this->postFunc = postFunc;
}

HTTPClient& Task::GetInput() {
    return *input;
}
HTTPClient& Task::GetOutput() {
    return *output;
}

void Task::SetInput(HTTPClient& input) {  //TODO use or del
    this->input = std::make_shared<HTTPClient>(input);
}
void Task::SetOutput(HTTPClient& output) {   //TODO use or del
    this->output = std::make_shared<HTTPClient>(output);
}

bool Task::HasData() {
    return input->hasData();
}

