#include <iostream>
using namespace std;

class basePage{
public:
    void header(){
        cout<<"公共头部"<<endl;
    }
    void footer(){
        cout<<"公共底部"<<endl;
    }
    void leftList(){
        cout<<"公共左侧列表"<<endl;
    }
};

// 游戏页面
class GamePage: public basePage{
public:
    void content(){
        cout<<"T1零封WBG"<<endl;
    }
};

// 新闻页面
class NewsPage: public basePage{
public:
    void content(){
        cout<<"两会新闻"<<endl;
    }
};

void test1(){
    GamePage game;
    game.header();
    game.footer();
    game.leftList();
    game.content();

    cout<<"-----------------"<<endl;

    NewsPage news;
    news.header();
    news.footer();
    news.leftList();
    news.content();
}

int main(){
    test1();

    system("pause");
    return 0;
}