#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QString>
#include <Set.h>

Set<int> a;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_empty_clicked()
{
    QString pas = ui->pushLine_3->text();
    if (pas.toInt())
    {
        a.insert(pas.toInt());
        QMessageBox::information(this,"Ура","Успешно");
    }
    else
    {
        QMessageBox::warning(this,"Беда","Ошибка в заполнении");
        ui->pushLine_3->clear();
        return;
    }
}




void MainWindow::on_size_clicked()
{
    QString pas = ui->pushLine_3->text();
    if (!pas.toInt())
    {
        QMessageBox::warning(this,"Беда","Ошибка в заполнении");
        ui->pushLine_3->clear();
        return;
    }
    int x = pas.toInt();
    auto str = a.search(x);
    if (str != nullptr)
    {
        QMessageBox::information(this, "Найдено", QString::number(str->key));
    }
    else
    {
        QMessageBox::information(this,"Пусто","Не найдено");
    }
    ui->pushLine_3->clear();
    return;
}


void MainWindow::on_capacity_clicked()
{
    QString pas = ui->pushLine_3->text();
    if (!pas.toInt())
    {
        QMessageBox::warning(this,"Беда","Ошибка в заполнении");
        ui->pushLine_3->clear();
        return;
    }
    int x = pas.toInt();
    a.remove(x);
    ui->pushLine_3->clear();
    QMessageBox::information(this,"Ура","Успешно");
    return;
}


void MainWindow::on_insert_3_clicked()
{
    QString str = "";
    a.print(str);
    ui->output_2->setText(str);
    return;
}


void MainWindow::on_erase_clicked()
{
    QString str = "";
    a.print_prefix(str);
    ui->output_2->setText(str);
    return;
}


void MainWindow::on_clear_clicked()
{
    QString str = "";
    a.print_postfix(str);
    ui->output_2->setText(str);
    return;
}


void MainWindow::on_insert_clicked()
{
    QString str = "";
    a.print_infix(str);
    ui->output_2->setText(str);
    return;
}

