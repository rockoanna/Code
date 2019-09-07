#include <fstream>
#include <set>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

// ofstream cout{"out.txt"};

struct Book
{
    string author;
    string name;

    Book() {}

    Book(const string& _author, string& _name):
    {
        author = _author;
        name = _name;
    }

    Book(const string& name_and_author)
    {
        auto f = name_and_author.rfind('"');
        name = name_and_author.substr(0,f+1);
        author = name_and_author.substr(f+5,name_and_author.size()-(f+5) + 1);
    }


};

bool operator < (const Book& b1, const Book& b2)
{
    if(b1.author == b2.author)
    {
        return b1.name < b2.name;
    }
    else
    {
        return b1.author < b2.author;
    }
}



int main_str()
{

    string s;
    set<Book> lib;
    unordered_map<string, Book> t_b;
    while(true)
    {
        getline(cin, s);
        if(s == "END")
        {
            break;
        }
        Book b(s);
        lib.insert(b);
        t_b.insert({b.name,b});
    }

    string shelve;
    vector<Book> ret_box;
    while(true)
    {
        getline(cin, shelve);
        if(shelve == "END")
        {
            break;
        }
        if(shelve[0] == 'B')
        {
            string b_name = shelve.substr(7,shelve.size() - 7 + 1);
            auto &b = t_b[b_name];
            lib.erase(b);

        }
        else
        {
            if(shelve[0] == 'R')
            {
                string b_name = shelve.substr(7,shelve.size() - 7 + 1);
                ret_box.push_back(t_b[b_name]);
            }
            else
            {
                //shelve;
                sort(ret_box.begin(),ret_box.end());
                for(auto bk: ret_box)
                {
                    auto pos = lib.lower_bound(bk);
                    if(pos == lib.begin())
                    {
                        cout<<"Put "<<bk.name <<" first" << '\n';
                    }
                    else
                    {
                        auto l = prev(pos);
                        cout<<"Put "<<bk.name <<" after " <<  l-> name <<'\n';

                    }
                    lib.insert(pos, bk);
                }
                cout<<"END"<<'\n';
                ret_box.clear();
            }
        }
    }
    return 0;
}



int main(){
    main_str();
    return 0;
}
