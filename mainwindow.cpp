#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "WeaverCore.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionSelect_Template_Directory, &QAction::triggered, this, &MainWindow::selectTemplateDir);
    connect(ui->actionSelect_Input_Directory, &QAction::triggered, this, &MainWindow::selectInputDir);
    connect(ui->actionSelect_Output_Directory, &QAction::triggered, this, &MainWindow::selectOutputDir);
    connect(ui->generateButton, &QPushButton::clicked, this, &MainWindow::generate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectTemplateDir()
{
    templateDir = QFileDialog::getExistingDirectory(this, "Select Template Directory");
    updateUI();
}

void MainWindow::selectInputDir()
{
    inputDir = QFileDialog::getExistingDirectory(this, "Select WVR Directory");
    updateUI();
}

void MainWindow::selectOutputDir()
{
    outputDir = QFileDialog::getExistingDirectory(this, "Select Output Directory");
    updateUI();
}

void MainWindow::updateUI()
{
    ui->templateLabel->setText(templateDir);
    ui->inputLabel->setText(inputDir);
    ui->outputLabel->setText(outputDir);
    ui->generateButton->setEnabled(checkDirectories());
}

bool MainWindow::checkDirectories()
{
    return !templateDir.isEmpty() && !inputDir.isEmpty() && !outputDir.isEmpty();
}

void MainWindow::generate()
{
    if (!checkDirectories()) {
        QMessageBox::warning(this, "Error", "Please select all directories before generating.");
        return;
    }
    WeaverCore core(templateDir, inputDir, outputDir);
    core.process();
    QMessageBox::information(this, "Done", "Generation completed.");
}
