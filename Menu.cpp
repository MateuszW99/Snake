#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new MainWindow)
{
    parent->setFocusPolicy(Qt::FocusPolicy::TabFocus);
    board = new Board(parent);
}

MainWindow::~MainWindow()
{
    delete ui;
}

