#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QHash>
#include <QDir>

#include <cardlist.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow(); 

private slots:
    void on_actionCard_Preview_triggered();

    void on_actionEdit_Create_Dict_triggered();

    void on_actionEdit_Create_Cardlist_triggered();

    void on_actionView_Cards_triggered();

    void on_actionChange_Directory_triggered();

    void on_actionEdit_Create_Cardlists_triggered();

    void on_actionShuffle_toggled(bool is_shuffled);

    void on_menuDictionaries_triggered(QAction* action);

    void on_actionFlipped_toggled(bool flipped);

private:
    Ui::MainWindow *ui;

    QString def_dir_; //TODO: Use a proper dir type?
    QString def_type_dir_;
    QStackedWidget* cont_;
    bool is_shuffled_;

    QWidget* makeCardPreview(QWidget *parent);
    QString getNewDir(QString dir_to_ask_for = "data");
    void reloadDir(); //Update files based on def_dir_
    bool addFiles(QMenu *menu, QDir &files);
    bool addDirs(QMenu *parent, QDir &dirs);
    bool populateMenu(QMenu *menu, QDir &path);
    void reloadWidgets(); //Update widgets
    void reloadCardlist(); //Update cardlist
    void recursiveAddCards(QMenu *menu, std::shared_ptr<Cardlist> list);
    void recursiveSetActionChecked(QMenu *menu, bool checked);

    //Manage cards in cardlist
    std::shared_ptr<Cardlist> addCards(QAction *action);
    void removeCards(QAction *action);
    //QHash<QString, QList<Cardlist::card_ptr>> card_cache_;
};

#endif // MAINWINDOW_H
