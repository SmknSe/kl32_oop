#ifndef BASE_H
#define BASE_H
#include <string>
#include <vector>
using namespace std;

class base
{
protected:
	string name;
	base* head;
	int status;
	vector<base*> ar_p;
public:

	base(base*, string = "Def_name");
	void set_name(string);
	string get_name();
	void display();
	void rebase(base* new_per);
	base* get_head_p();
	~base();
	base* find_n(string);
	void print();
	void print_ready();
	void set_readiness(int);
	base* find_cord(string);
};
#endif