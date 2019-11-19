#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new MainWindow)
{
    board = new Board();
}

MainWindow::~MainWindow()
{
    delete ui;
}

