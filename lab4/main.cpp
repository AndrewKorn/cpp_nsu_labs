#include "Model.h"
#include "View.h"
#include "Controller.h"

int main(){
    auto model = new Model();
    View view(model);
    Controller controller(model);
    controller.StartNewGame();
    return 0;
}
