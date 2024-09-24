//
// Created by Keijo Länsikunnas on 5.3.2024.
//

#ifndef LAB12_INTEDIT_H
#define LAB12_INTEDIT_H
#include <string>
#include "MenuItem.h"
#include "Observer.h"
#include <vector>
#include <memory>

class IntEdit : public MenuItem {
public:
    explicit IntEdit(std::string menu_title);
    bool event(menuEvent e) override;
    void show() override;
    void add_observer(std::shared_ptr<Observer> observer);
protected:
    int value;
    int backup;
    bool changed;
    void notify_observers();
private:
    std::vector<std::shared_ptr<Observer>> observers;
};


#endif //LAB12_INTEDIT_H
