#include "search_window.h"
#include "ui_search_window.h"

search_window::search_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::search_window)
{
    ui->setupUi(this);
}

search_window::~search_window()
{
    delete ui;
}
