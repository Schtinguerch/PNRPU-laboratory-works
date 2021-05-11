#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QProcess>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->DrawTreePushButton, SIGNAL (clicked()), this, SLOT (DrawTree()));
    connect(ui->openFilePushButton, SIGNAL (clicked()), this, SLOT (OpenFileFiller()));
    connect(ui->ClearTreePushButton, SIGNAL (clicked()), this, SLOT (ClearCanvas()));

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1000, 1500);
    ui->graphicsView->setScene(scene);

    scene->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DrawTree()
{
    scene->clear();

    BinaryTree* balancedTree = new BinaryTree;
    balancedTree->load_tree_file(filename);

    balancedTree->create_balanced_binary_tree();
    balancedTree->print_tree(scene);

    QMessageBox box;
    box.setText("Минимальное значение = " + QString::number(balancedTree->min_value()));
    box.exec();
}

void MainWindow::OpenFileFiller()
{
    QProcess process(this);
    process.startDetached("D:\\Downloads\\Developer tools\\Lab20_qt\\run.bat");

    filename = "D:\\Downloads\\Developer tools\\Lab20_qt\\elements.txt";
}

void MainWindow::ClearCanvas()
{
    scene->clear();
}
