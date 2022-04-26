#include "base.h"
#include <iostream>
#include <algorithm>
using namespace std;
base::base(base* h, std::string n)
{
	status = 0;
	head = h;
	name = n;
	if (head != nullptr) {
		head->ar_p.emplace(head->ar_p.end(), this);
	}
}

void base::set_name(std::string n)
{
	name = n;
}

std::string base::get_name()
{
	return name;
}
void base::display()
{
	base* now = this;
	while (now->get_head_p() != nullptr) {
		now = now->get_head_p();
	}
	std::cout << now->get_name();
	if (now->ar_p.size() != 0) cout << endl;
	while (now->ar_p.size() != 0) {
		std::cout << now->name;
		for (int i = 0; i < now->ar_p.size(); i++) {
			std::cout << "  " << now->ar_p[i]->get_name();
		}
		now = now->ar_p[now->ar_p.size() - 1];
		if (now->ar_p.size() != 0)
			std::cout << std::endl;
	}
}


void base::rebase(base* new_per)
{
	if (head != nullptr) {
		head->ar_p.erase(find(head->ar_p.begin(), head->ar_p.end(), this));
	}
	if (new_per != nullptr) {
		new_per->ar_p.emplace_back(this);
	}
	head = new_per;
}


base* base::get_head_p()
{
	return head;
}

base::~base() {
	for (int i = 0; i < ar_p.size(); i++) {
		delete ar_p[i];
	}
}

base* base::find_n(std::string n)
{
	if (this->name == n)
		return this;
	base* res=nullptr;
	for (int i = 0; i < ar_p.size(); i++) {
		res = ar_p[i]->find_n(n);
		if (res != nullptr) {
			return res;
		}
	}
	return nullptr;
}

void base::set_readiness(int stat)
{
	if (head==nullptr || head->status!=0) {
		if (stat != 0)
			status = stat;
		else {
			for (int i = 0; i < ar_p.size(); i++) {
				ar_p[i]->set_readiness(0);
			}
			status = 0;
		}
	}
}


void base::print() {
	if (this->get_head_p() == nullptr) {
		cout << name;
	}
	for (int i = 0; i < ar_p.size(); i++) {
		base* now = ar_p[i];
		string tabs = "";
		while (now->get_head_p() != nullptr) {
			now = now->get_head_p();
			tabs =tabs+ " " + " " + " " + " ";
		}
		cout << endl<<tabs << ar_p[i]->get_name();
		ar_p[i]->print();
	}
}
void base::print_ready() {
	if (this->get_head_p() == nullptr) {
		if (this->status != 0) cout << name << " is ready";
			else cout << name << " is not ready";
	}
	for (int i = 0; i < ar_p.size(); i++) {
		base* now = ar_p[i];
		string tabs = "";
		while (now->get_head_p() != nullptr) {
			now = now->get_head_p();
			tabs = tabs + " " + " " + " " + " ";
		}
		cout << endl << tabs << ar_p[i]->get_name();
		if (ar_p[i]->status != 0) cout << " is ready";
		else cout << " is not ready";
		ar_p[i]->print_ready();
	}
}
base* base::find_cord(string path) {
	if (path.empty()) return nullptr;
	if (path[0] == '.') return this;
	base* root = this;
	if (path[0] == '/') {
		while (root->get_head_p() != nullptr) root = root->get_head_p();
	}
	if (path.size() > 1 && path[0] == '/' && path[1] == '/') {
		path.erase(0, 2);
		return root->find_n(path);
	}
	else if (path[0] == '/') {
		if (path.size() == 1) return root;
		path.erase(0, 1);
	}
	int id = path.find('/');
	string ss = path.substr(0, id == -1 ? path.size() : id);
	for (int i = 0; i < root->ar_p.size(); i++) {
		base* qq = root->ar_p[i];
		if (qq->get_name() == ss) {
			if (id == -1) {
				return qq;
			}
			else {
				path.erase(0, id + 1);
				return qq->find_cord(path);
			}
		}
	}
	return nullptr;
}