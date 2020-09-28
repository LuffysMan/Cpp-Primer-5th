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

void close(connection* pConn){
    disconnect(*pConn);
}

void f(destination &d){
    connection c = connect(&d);
    std::shared_ptr<connection> pConn(&c, close);
}


int main(){
    return 0;
}