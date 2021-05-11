#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <binarytree.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QString filename = "D:\\Downloads\\Developer tools\\Lab20_qt\\elements.txt";

private slots:
    void DrawTree();
    void OpenFileFiller();
    void ClearCanvas();
};
#endif // MAINWINDOW_H
