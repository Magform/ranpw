#ifndef Kraken_H_
#define Kraken_H_

class Kraken{
    private:
        int health;
        int hunger;
    public:
        int getHealth();
        int getHunger();
        void live();
        int addHunger(int hunger);
};

#endif //Kraken_H_