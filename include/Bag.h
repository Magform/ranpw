#ifndef Bag_H_
#define Bag_H_


class Bag {
private:
    int Pie = 0;    //Food type 0
    int Egg = 0;    //Food type 1
public:
    void addFood(int foodType);
    int useFood(int foodType);
    int getFood(int foodType);
    void addRandomFood();
};

#endif // Bag_H_
