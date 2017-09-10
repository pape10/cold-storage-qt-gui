#ifndef VENDOR_WINDOW_H
#define VENDOR_WINDOW_H

#include <QMainWindow>

namespace Ui {
class vendor_window;
}

class vendor_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit vendor_window(QWidget *parent = 0);
    ~vendor_window();

private slots:
    void on_refresh_seeall_clicked();

    void on_pushButton_2_clicked();

    void on_refresh_clicked();

    void on_pushButton_100_clicked();

    void on_refresh_vendor_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_check_status_clicked();

private:
    Ui::vendor_window *ui;
};

#endif // VENDOR_WINDOW_H
