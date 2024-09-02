#include <iostream>
#include <stdint.h>
#include <iomanip>
#include <string>
#include <string.h>


class Player
{
public:


    std::string GetName() { return name; }



    void SetName(std::string name_)
    {
        
        name = name_;
     
    }


    int Getscore()
    {
        return score;
    }

    
    void Setscore(int score_)
    {
        score = score_;
    }

    
private:
    std::string name;
    int score;
   
};


using namespace std;

void bubbleSort(Player ArrPlayers[], int listLength)
{
    while (listLength--)
    {
        bool swapped = false;

        for (int i = 0; i < listLength; i++)
        {
            if (ArrPlayers[i].Getscore() > ArrPlayers[i + 1].Getscore())
            {
                swap(ArrPlayers[i], ArrPlayers[i + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}


int main()
{

    std::cout << "Enter number of players: ";
    int num;
    std::cin >> num;
   
    Player* ArrPlayers = new Player[num];
    for (int i = 0; i < num; i++)
    {

        std::cout << "Enter " << i + 1 << " player's name: ";
        std::string name_;
        std::cin >> name_;
        ArrPlayers[i].SetName(name_);

        std::cout << "Enter " << i + 1 << " player's score: ";
        int score_;
        std::cin >> score_;
        ArrPlayers[i].Setscore(score_);
              
              

    }

    std::cout << "\n";

    for (int i = 0; i < num; i++)
    {
        std::cout << ArrPlayers[i].GetName() << " " << ArrPlayers[i].Getscore() << "\n";
    }
   
    std::cout << "\n";
    
    bubbleSort(ArrPlayers, num);
    cout << "Sorted array ..."  << endl;
    for (int i = 0; i < num; i++)
    {
        cout << ArrPlayers[i].Getscore() << " " << ArrPlayers[i].GetName() << '\t';
        cout << endl;
    }
}