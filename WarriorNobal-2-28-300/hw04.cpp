#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Warrior{
private:
    string name;
    int strength;
    bool hired;

public:
    Warrior(){}

    Warrior(const string &name, int strength) : name(name), strength(strength), hired(false) {}

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Warrior::name = name;
    }

    int getStrength() const {
        return strength;
    }

    void setStrength(int strength) {
        Warrior::strength = strength;
    }

    bool isHired() const {
        return hired;
    }

    void setHired(bool hired) {
        Warrior::hired = hired;
    }


};

class Noble{
private:
    string name;
    bool alive;
    vector<Warrior*> army;
public:
    Noble() {
        alive = true;
    }

    Noble(const string &name) : name(name) {
        alive = true;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Noble::name = name;
    }

    bool isAlive() const {
        return alive;
    }

    void setAlive(bool alive) {
        Noble::alive = alive;
    }

    bool hire(Warrior& warrior)
    {
        if(!this->isAlive())
            return false;
        if(!warrior.isHired())
        {
            army.push_back(&warrior);
            warrior.setHired(true);
            return true;
        }else
        {
            return false;
        }
    }

    bool fire(Warrior& warrior)
    {
        for(size_t i = 0; i < army.size(); i++)
        {
            if(army[i] == &warrior)
            {
                if(i != army.size()-1)
                {
                    Warrior* temp = army[i];
                    army[i] = army[army.size()-1];
                    army[army.size()-1] = temp;
                }
                army.pop_back();
                warrior.setHired(false);
                cout<<warrior.getName()<<", you're fired! -- "<<this->getName()<<endl;
                return true;
            }
        }
        return false;
    }

    void display()
    {
        cout<<this->getName()<<" has an army of "<<army.size()<<endl;
        for(size_t i = 0; i < army.size(); i++)
        {
            cout<<army[i]->getName()<<": "<<army[i]->getStrength()<<endl;
        }
    }

    int get_total_strength()
    {
        int sum = 0;
        for(size_t i = 0; i < army.size(); i++)
        {
            sum += army[i]->getStrength();
        }
        return sum;
    }

    void die()
    {
        this->alive = false;
        for(size_t i = 0; i < army.size(); i++)
        {
            army[i]->setStrength(0);
        }
    }

    void decrease_strength(double percentage)
    {
        for(size_t i = 0; i < army.size(); i++)
        {
            army[i]->setStrength(static_cast<int>(army[i]->getStrength() * percentage));
        }
    }

    void battle(Noble& n2)
    {
        cout<<this->getName()<<" battles "<<n2.getName()<<endl;
        if(this->get_total_strength() == 0 && n2.get_total_strength() == 0)
        {
            cout<<"Oh, NO! They're both dead! Yuck!"<<endl;
        }else if(this->get_total_strength() == 0)
        {
            cout<<"He's dead "<<n2.get_total_strength()<<endl;
        }else if(n2.get_total_strength() == 0)
        {
            cout<<"He's dead "<<this->getName()<<endl;
        }else if(this->get_total_strength()== n2.get_total_strength())
        {
            this->die();
            n2.die();
            cout<<"Mutual Annihilation: "<<this->getName()<<" and "<<n2.getName()<<" die at each other's hands"<<endl;
        }else if(this->get_total_strength() > n2.get_total_strength())
        {
            this->decrease_strength(this->get_total_strength() / n2.get_total_strength());
            n2.die();
            cout<<this->getName()<<" defeats "<<n2.getName()<<endl;
        }else if(this->get_total_strength() < n2.get_total_strength())
        {
            n2.decrease_strength(n2.get_total_strength() / this->get_total_strength());
            this->die();
            cout<<n2.getName()<<" defeats "<<this->getName()<<endl;
        }
    }
};


int main(int argc, char* argv[])
{
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");
    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);
    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(wizard);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(cheetah);
    jim.display();
    lance.display();
    art.display();
    linus.display();
    billie.display();
    art.fire(cheetah);
    art.display();
    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);
    return 0;
}