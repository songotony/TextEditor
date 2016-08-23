#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QTreeWidgetItem>

#include <vector>

#include "Text.hpp"
#include "ChoiceDialog.hpp"
#include "AddTextDialog.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void selectTab(int);
    void removeTab(int);
    void languageChosen(void);
    void textCreated(void);
    void on_addButton_clicked();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ChoiceDialog *m_choiceDial;
    AddTextDialog *m_textDial;
    std::vector<Text *> m_texts;
    int m_lastIndex;
};

#endif // MAINWINDOW_HPP
