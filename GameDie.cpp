#include "GameDie.h"
#include <vector>
#include <cstdlib>
#include <ctime>

//class constructor that seeds the random number generator
GameDie::GameDie()
{
    srand(time(NULL));
    roll_counter.resize(FACES);

    for(int i=0; i<FACES; i++)
      roll_counter[i] = 0;
}

//overloaded constructor
GameDie::GameDie(unsigned int num)
{
    if( num == 0 )
    {
        roll_counter.resize(FACES);
    }
    else{
        roll_counter.resize(num);
    }
    for(int i=0; i<FACES; i++)
    {
        roll_counter[i] = 0;
    }

}

//generate a random number between 1-n where n is the counter size
// (inclusive) and return it
int GameDie::roll()
{
    int roll = rand() % roll_counter.size();
    roll_counter[roll]++;
    return roll + 1;
}

// return the count of how many times each face has been rolled, as a vector
// where each face's count is at index face-1 (i.e. Face 1 is at index 0)
vector <int> GameDie::get_distribution(){
    return roll_counter;
}

vector <double> GameDie::get_percentages(){
    vector<double> ret(roll_counter.size());
    int total = 0;
    for(int& i : roll_counter)
        total += i;
    for(int i = 0; i < (int)roll_counter.size(); ++i)
        ret.at(i) = (double)roll_counter.at(i) / (double)total;
    return ret;
}

#include <iostream>

int main() {
    GameDie* die = new GameDie();
    for(int i = 0; i < 6; ++i)
        die->roll();
    vector<int> dist = die->get_distribution();
    int j = 1;
    for(int& i : dist) {
        std::cout << "Rolled " << j << ' ' << i << " times." << std::endl;
        ++j;
    }
    delete die;
    return 0;
}
