#ifndef FARMER_WINDOW_H
#define FARMER_WINDOW_H

#include <QMainWindow>

namespace Ui {
class farmer_window;
}

class farmer_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit farmer_window(QWidget *parent = 0);
    ~farmer_window();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_refresh_see_clicked();

private:
    Ui::farmer_window *ui;
};

#endif // FARMER_WINDOW_H
