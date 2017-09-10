#ifndef ADMIN_WINDOW_H
#define ADMIN_WINDOW_H

#include <QMainWindow>

namespace Ui {
class admin_window;
}

class admin_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit admin_window(QWidget *parent = 0);
    ~admin_window();

private slots:
    void on_pushButton_clicked();

    void on_refresh_seeall_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_refresh_vendor_clicked();

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_pushButton_7_clicked();

    void on_submit_check_clicked();

    void on_sub_clicked();

    void on_pushButton_8_clicked();

    void on_refresh_again_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_9_clicked();

private:
    Ui::admin_window *ui;
};

#endif // ADMIN_WINDOW_H
