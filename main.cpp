#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
using namespace std;

// layout floors
void addFloors(QMainWindow& simulation) {
    QLabel *f1 = new QLabel("----------------------------------------------------------------------------------------------------------------", &simulation);
    QLabel *f2 = new QLabel("----------------------------------------------------------------------------------------------------------------", &simulation);
    QLabel *f3 = new QLabel("----------------------------------------------------------------------------------------------------------------", &simulation);
    QLabel *f4 = new QLabel("----------------------------------------------------------------------------------------------------------------", &simulation);
    QLabel *f5 = new QLabel("----------------------------------------------------------------------------------------------------------------", &simulation);
    f1->setGeometry(0, -100, 500, 500);
    f2->setGeometry(0, -50, 500, 500);
    f3->setGeometry(0, 0, 500, 500);
    f4->setGeometry(0, 50, 500, 500);
    f5->setGeometry(0, 100, 500, 500);
}

// passengers enteer elevator(s)
void enterElevator(QLabel& p1, QLabel& p2, QLabel& p3, QLabel& p4, int e1x, int e2x, int e1y, int e2y) {
    p1.setGeometry(e1x - 10, e1y - 10, 500, 500);
    p2.setGeometry(e1x + 10, e1y - 10, 500, 500);
    p3.setGeometry(e2x - 10, e2y - 10, 500, 500);
    p4.setGeometry(e2x + 10, e2y - 10, 500, 500);
}

// elevator moving through floors
void moveElevator(QLabel& e1, QLabel& e2, QLabel& p1, QLabel& p2, QLabel& p3, QLabel& p4, int e1x, int e2x, int e1y, int e2y) {
    p1.setGeometry(e1x - 10, e1y - 10, 500, 500);
    p2.setGeometry(e1x + 10, e1y - 10, 500, 500);
    p3.setGeometry(e2x - 10, e2y - 10, 500, 500);
    p4.setGeometry(e2x + 10, e2y - 10, 500, 500);
    e1.setGeometry(e1x, e1y, 500, 500);
    e2.setGeometry(e2x, e2y, 500, 500);
}

// elevator
void exitElevator(QLabel& p1, QLabel& p2, QLabel& p3, QLabel& p4, int e1x, int e2x, int e1y, int e2y) {
    p1.setGeometry(e1x - 20, e1y, 500, 500);
    p2.setGeometry(e1x - 40, e1y, 500, 500);
    p3.setGeometry(e2x - 20, e2y, 500, 500);
    p4.setGeometry(e2x - 40, e2y, 500, 500);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // create main window
    QMainWindow mainWindow;
    QMainWindow start;
    QMainWindow simulation;
    mainWindow.resize(700, 50);

    // default GUI coordinates
    int e1x = 150;
    int e2x = 350;
    int e1y = -105;
    int e2y = -105;

    // main menu buttons
    QPushButton *UseCase1 = new QPushButton("Use Case 1", &mainWindow);
    UseCase1->setGeometry(0, 0, 100, 50);
    QPushButton *UseCase2 = new QPushButton("Use Case 2", &mainWindow);
    UseCase2->setGeometry(100, 0, 100, 50);
    QPushButton *Help = new QPushButton("Help", &mainWindow);
    Help->setGeometry(200, 0, 100, 50);
    QPushButton *DoorObstacles = new QPushButton("Door \n Obstacles", &mainWindow);
    DoorObstacles->setGeometry(300, 0, 100, 50);
    QPushButton *Fire = new QPushButton("Fire", &mainWindow);
    Fire->setGeometry(400, 0, 100, 50);
    QPushButton *Overload = new QPushButton("Overload", &mainWindow);
    Overload->setGeometry(500, 0, 100, 50);
    QPushButton *PowerOut = new QPushButton("Power Out", &mainWindow);
    PowerOut->setGeometry(600, 0, 100, 50);

    // start button
    start.resize(700, 50);
    QPushButton *Start = new QPushButton("Start", &start);
    Start->setGeometry(300, 0, 100, 50);

    // generate elevator and passenger labels
    QLabel *simulate = new QLabel("", &simulation);
    simulation.resize(500, 500);
    QLabel *e1 = new QLabel("E1", &simulation);
    QLabel *e2 = new QLabel("E2", &simulation);
    QLabel *p1 = new QLabel("P1", &simulation);
    QLabel *p2 = new QLabel("P2", &simulation);
    QLabel *p3 = new QLabel("P3", &simulation);
    QLabel *p4 = new QLabel("P4", &simulation);

    // first success scenario
    QObject::connect(UseCase1, &QPushButton::clicked, [&]() {
        mainWindow.close();
        start.show();
        // simulate scenario
        QObject::connect(Start, &QPushButton::clicked, [&]() {
            start.close();
            simulate->setText("Success Scenario 1");
            simulate->setGeometry(200, 0, 500, 50);
            addFloors(simulation);
            simulation.show();
            e1->setGeometry(e1x, e1y, 500, 500);
            e2->setGeometry(e2x, e2y, 500, 500);
            p1->setGeometry(110, e1y, 500, 500);
            p2->setGeometry(130, e1y, 500, 500);
            p3->setGeometry(310, e1y, 500, 500);
            p4->setGeometry(330, e1y, 500, 500);
            enterElevator(*p1, *p2, *p3, *p4, e1x, e2x, e1y, e2y);
            for (int i = 5; i > 1; i--) {
                sleep(1);
                e1y = e1y + 50;
                e2y = e2y + 50;
                moveElevator(*e1, *e2, *p1, *p2, *p3, *p4, e1x, e2x, e1y, e2y);
            }
            exitElevator(*p1, *p2, *p3, *p4, e1x, e2x, e1y, e2y);
        });
    });
    // second success scenario
    QObject::connect(UseCase2, &QPushButton::clicked, [&]() {
        mainWindow.close();
        start.show();
        // simulate scenario
        QObject::connect(Start, &QPushButton::clicked, [&]() {
            start.close();
            simulate->setText("Success Scenario 2");
            simulate->setGeometry(200, 0, 500, 50);
            addFloors(simulation);
            e1->setGeometry(e1x, e1y, 500, 500);
            e2->setGeometry(e2x, e2y, 500, 500);
            p1->setGeometry(110, e1y, 500, 500);
            p2->setGeometry(130, e1y, 500, 500);
            p3->setGeometry(110, e1y + 100, 500, 500);
            p4->setGeometry(130, e1y + 100, 500, 500);
            simulation.show();
        });
    });
    // help safety feature
    QObject::connect(Help, &QPushButton::clicked, [&]() {
        mainWindow.close();
        start.show();
        // simulate scenario
        QObject::connect(Start, &QPushButton::clicked, [&]() {
            start.close();
            simulate->setText("Help");
            simulate->setGeometry(250, 0, 500, 50);
            addFloors(simulation);
            e1->setGeometry(e1x, e1y + 50, 500, 500);
            e2->setGeometry(e2x, e2y + 50, 500, 500);
            p1->setGeometry(120, e1y + 40, 500, 500);
            p2->setGeometry(140, e1y + 40, 500, 500);
            p3->setGeometry(160, e1y + 40, 500, 500);
            p4->setGeometry(180, e1y + 40, 500, 500);
            simulation.show();
        });
    });
    // door obstacles safety feature
    QObject::connect(DoorObstacles, &QPushButton::clicked, [&]() {
        mainWindow.close();
        start.show();
        // simulate scenario
        QObject::connect(Start, &QPushButton::clicked, [&]() {
            start.close();
            simulate->setText("Door Obstacles");
            simulate->setGeometry(200, 0, 500, 50);
            addFloors(simulation);
            e1->setGeometry(e1x, e1y, 500, 500);
            e2->setGeometry(e2x, e2y, 500, 500);
            p1->setGeometry(130, e1y, 500, 500);
            p2->setGeometry(110, e1y, 500, 500);
            p3->setGeometry(90, e1y, 500, 500);
            p4->setGeometry(70, e1y, 500, 500);
            simulation.show();
        });
    });
    // fire safety  feature
    QObject::connect(Fire, &QPushButton::clicked, [&]() {
        mainWindow.close();
        start.show();
        // simulate scenario
        QObject::connect(Start, &QPushButton::clicked, [&]() {
            start.close();
            simulate->setText("Fire");
            simulate->setGeometry(250, 0, 500, 50);
            addFloors(simulation);
            e1->setGeometry(e1x, e1y + 50, 500, 500);
            e2->setGeometry(e2x, e2y + 50, 500, 500);
            p1->setGeometry(120, e1y + 40, 500, 500);
            p2->setGeometry(140, e1y + 40, 500, 500);
            p3->setGeometry(160, e1y + 40, 500, 500);
            p4->setGeometry(180, e1y + 40, 500, 500);
            simulation.show();
        });
    });
    // overload safety feature
    QObject::connect(Overload, &QPushButton::clicked, [&]() {
        mainWindow.close();
        start.show();
        // simulate scenario
        QObject::connect(Start, &QPushButton::clicked, [&]() {
            start.close();
            simulate->setText("Overload");
            simulate->setGeometry(225, 0, 500, 50);
            addFloors(simulation);
            e1->setGeometry(e1x, e1y, 500, 500);
            e2->setGeometry(e2x, e2y, 500, 500);
            p1->setGeometry(130, e1y, 500, 500);
            p2->setGeometry(110, e1y, 500, 500);
            p3->setGeometry(90, e1y, 500, 500);
            p4->setGeometry(70, e1y, 500, 500);
            simulation.show();
        });
    });
    // power out saffety feature
    QObject::connect(PowerOut, &QPushButton::clicked, [&]() {
        mainWindow.close();
        start.show();
        // simulate scenario
        QObject::connect(Start, &QPushButton::clicked, [&]() {
            start.close();
            simulate->setText("Power Out");
            simulate->setGeometry(225, 0, 500, 50);
            addFloors(simulation);
            e1->setGeometry(e1x, e1y + 50, 500, 500);
            e2->setGeometry(e2x, e2y + 50, 500, 500);
            p1->setGeometry(120, e1y + 40, 500, 500);
            p2->setGeometry(140, e1y + 40, 500, 500);
            p3->setGeometry(160, e1y + 40, 500, 500);
            p4->setGeometry(180, e1y + 40, 500, 500);
            simulation.show();
        });
    });

    mainWindow.show();

    return app.exec();
}
