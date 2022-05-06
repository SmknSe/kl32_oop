#include "app.h"
#include <iostream>
#include <string>

app::app(base* p):base(p, "root")
{
}

void app::build_tree_objects()
{
	base* temp = nullptr;
	string n_a, n_b;
	int class_n;
	cin >> n_a;
	set_name(n_a);
	do{
		cin >> n_a;
		if(n_a!="endtree") {
			cin >> n_b >> class_n;
			base* t = find_cord(n_a);
			if (t == nullptr) {
				cout << "Object tree\n";
				print();
				cout << "\nThe head object " << n_a << " is not found";
				exit(0);
			}
			switch (class_n)
			{
			case 2:
				temp = new base_c2(t, n_b);
				break;
			case 3:
				temp = new base_c3(t, n_b);
				break;
			case 4:
				temp = new base_c4(t, n_b);
				break;
			case 5:
				temp = new base_c5(t, n_b);
				break;
			case 6:
				temp = new base_c6(t, n_b);
				break;
			default:
				break;
			}
		}
	} while (n_a != "endtree");

}

int app::exec_app()
{
	cout << "Object tree" << endl;
	if (name != "") {
		print();
		string cmd, pt;
		base* now = this;
		base* tmp = nullptr;
		do {
			cin >> cmd;
			if (cmd != "END") {
				cin >> pt;
				if (cmd == "SET") {
					tmp = now->find_cord(pt);
					if (tmp == nullptr) {
						cout << "\nObject is not found: " << now->get_name() << " " << pt;
					}
					else {
						now = tmp;
						cout << "\nObject is set: " << now->get_name();
					}
				}
				else if (cmd == "FIND") {
					tmp = now->find_cord(pt);
					if (tmp == nullptr) {
						cout << endl << pt << "     Object is not found";
					}
					else {
						cout << endl << pt << "     Object name: " << tmp->get_name();
					}
				}
			}
		} while (cmd != "END");
	}
	return 0;
}