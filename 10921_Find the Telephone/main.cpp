#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string input;
    vector <string> main_out;
    vector <int> cap_num, hyp_out;

    while(cin >> input){

        string output;
        int cap = 0, hyp = 0;

        for(char c : input){

            switch(c){

                case 'A': case 'B': case 'C':
                    output.append("2");
                    cap++;
                    break;

                case 'D': case 'E': case 'F':
                    output.append("3");
                    cap++;
                    break;

                case 'G': case 'H': case 'I':
                    output.append("4");
                    cap++;
                    break;

                case 'J': case 'K': case 'L':
                    output.append("5");
                    cap++;
                    break;

                case 'M': case 'N': case 'O':
                    output.append("6");
                    cap++;
                    break;

                case 'P': case 'Q': case 'R': case 'S':
                    output.append("7");
                    cap++;
                    break;

                case 'T': case 'U': case 'V':
                    output.append("8");
                    cap++;
                    break;

                case 'W': case 'X': case 'Y': case 'Z':
                    output.append("9");
                    cap++;
                    break;

                case '-':
                    output.append("-");
                    hyp++;
                    break;

                default:
                    string s(1, c);
                    output.append(s);
            }
        }

        main_out.push_back(output);
        cap_num.push_back(cap);
        hyp_out.push_back(hyp);
    }

    for(int i=0; i<main_out.size(); i++){

        cout << main_out[i]; /* << " " << cap_num[i] << " " << hyp_out[i];*/

        // if(i != main_out.size()-1)
        cout << endl;
    }
    return 0;
}
