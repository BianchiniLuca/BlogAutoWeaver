#pragma once

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void selectTemplateDir();
    void selectInputDir();
    void selectOutputDir();
    void generate();

private:
    Ui::MainWindow *ui;
    QString templateDir;
    QString inputDir;
    QString outputDir;
    void updateUI();
    bool checkDirectories();
};
