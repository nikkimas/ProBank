
int main(void){

    Clear();
    system("pause");

}

void Clear(void){

    #ifdef linux
        system("clear");
    #endif

    #ifdef _WIN32
        system("cls);
    #endif

}
