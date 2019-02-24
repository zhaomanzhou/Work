#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    int num_post, feet_between_post, distance;
    int total_sign = 0;
    cout<<"How many posts do you want to use?";
    cin>>num_post;
    cout<<"How many feet between posts?";
    cin>>feet_between_post;
    cout<<"What is the minimum distance between signs (in feet)";
    cin>>distance;
    stringstream ss;
    ss<<"|";
    int cur_distance = 0;
    for(int i = 0; i < num_post - 1; i++)
    {
        for(int j = 0; j < feet_between_post; j++)
        {
            cur_distance++;
            if(cur_distance >= distance + 1 && j != 0 && j != feet_between_post-1)
            {
                ss<<"S";
                cur_distance = 0;
                total_sign++;
            }else
            {
                ss<<"-";
            }
        }
        ss<<"|";
    }

    string output;
    ss>>output;
    cout<<output<<endl;
    cout<<"Total Signs: "<<total_sign<<endl;
    return 0;
}