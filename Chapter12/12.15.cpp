#include <memory>


struct destination{

};

struct connection{

};

connection connect(destination* pDest){
    return connection();
}

void disconnect(connection conn){

}

void f(destination &d){
    connection c = connect(&d);
    std::shared_ptr<connection> pConn(&c, [](connection *pConn){disconnect(*pConn);});
}


int main(){
    return 0;
}