#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int times = 0;
    cin >> times;
    vector <int> months({0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
    vector <string> week({"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday"});
    vector <string> final_out;

    for(int i=0; i<times; i++){

        int month=0, day=0, diff_day=0, week_day=0;

        cin >> month >> day;

        if(month < 4){

            diff_day += months[month] - day;
            for(int j=month+1; j<4; j++)
                diff_day += months[j];
            diff_day += 4;

            week_day = 7 - diff_day % 7;

        }else if(month == 4){

            if(day < 4){

                diff_day = 4 - day;

                week_day = 7 - diff_day;

            }else if(day == 4){

                week_day = 0;

            }else if(day > 4){

                diff_day = day - 4;

                week_day = diff_day % 7;
            }
        }else if(month > 4){

            diff_day += months[4] - 4;
            for(int j=4+1; j<month; j++)
                diff_day += months[j];
            diff_day += day;

            week_day = diff_day % 7;
        }
        try{

            final_out.push_back(week.at(week_day));

        }catch(exception const& e){

            cout << e.what() << endl;
        }
    }

    for(int i=0; i<final_out.size(); i++){

        cout << final_out[i];

        //if(i != final_out.size()-1)

        cout << endl;
    }
    return 0;
}
