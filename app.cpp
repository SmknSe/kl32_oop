#include "app.h"
#include <iostream>
#include <string>
using namespace std;
app::app(base_c2* p) :base(p, "root")
{
}

void app::build_tree_objects()
{
	base* temp = nullptr;
	std::string n_a, n_b;
	int class_n;
	std::cin >> n_a;
	if(n_a !="endtree"){
	this->set_name(n_a);
	
	do {
		std::cin >> n_a;

		if (n_a != "endtree") {
			cin >> n_b >> class_n;
			base* to_push = find_cord(n_a);
			if (to_push == nullptr) {
				cout<<"Object tree"<<endl;
				print();
				cout<<endl<<"The head object "<<n_a<<" is not found";
				exit(0);
			}
			switch (class_n)
			{
			case 2:
				temp = new base_c2(to_push, n_b);
				break;
			case 3:
				temp = new base_c3(to_push, n_b);
				break;
			case 4:
				temp = new base_c4(to_push, n_b);
				break;
			case 5:
				temp = new base_c5(to_push, n_b);
				break;
			case 6:
				temp = new base_c6(to_push, n_b);
				break;
			default:
				break;
			}
		}
	} while (n_a != "endtree");
	}
}

int app::exec_app()
{
	cout << "Object tree" << endl;
	if(this->name!=""){

	print();
	std::string com="", p="";
	base* now = this;
	base* tem = nullptr;
	do {
		cin >> com;
		if(com!="END"){
			p = "";
			cin >> p;
			if (com == "SET") {
				tem = now->find_cord(p);
				if (tem == nullptr) {
					cout <<endl<< "Object is not found: " << now->get_name() <<" "<< p;
				}
				else {
					now = tem;
					cout << endl << "Object is set: " << now->get_name();
				}
			}
			if (com == "FIND") {
				tem = now->find_cord(p);
				if (tem == nullptr) {
					cout << endl << p<<"     Object is not found";
				}
				else {
					cout << endl << p << "     Object name: " << tem->get_name();
				}
			}
		}
	} while (com != "END");
	}
	return 0;
}



