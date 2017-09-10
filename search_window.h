#ifndef SEARCH_WINDOW_H
#define SEARCH_WINDOW_H

#include <QMainWindow>

namespace Ui {
class search_window;
}

class search_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit search_window(QWidget *parent = 0);
    ~search_window();

private:
    Ui::search_window *ui;
};

#endif // SEARCH_WINDOW_H
