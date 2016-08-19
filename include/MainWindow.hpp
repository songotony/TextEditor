#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include <vector>

#include "Text.hpp"
#include "LanguageDialog.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void selectTab(int);
    void removeTab(int);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::vector<Text *> m_texts;
};

#endif // MAINWINDOW_HPP
