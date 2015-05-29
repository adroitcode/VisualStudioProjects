#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <sstream>


using namespace std;









class Sandwhich{

	protected:
		static const int bread = 2;
		float mayo;
		float mustard;
		int tomatoes;
		int cheese;

	public:
		Sandwhich();
		Sandwhich(int);
		Sandwhich(float);
		Sandwhich(int, int, float, float);
		
		void set_tomatoes(int _tomatoes){
			tomatoes = _tomatoes;
		}

		void set_cheese(int _cheese){
			cheese = _cheese;
		}

		void set_mayo(float _mayo){
			mayo = _mayo;
		}

		void set_mustard(float _mustard){
			mustard = _mustard;
		}




		int get_tomatoes(){
			return tomatoes;
		}

		int get_cheese(){
			return cheese;
		}

		float get_mayo(){
			return mayo;
		}

		float get_mustard(){
			return mustard;
		}

		int get_bread(){
			return bread;
		}



		string print(){
			return "Sandwhich - tomatoes: " + to_string(tomatoes) + ", cheese: " + to_string(cheese) + ", mayo: " + to_string(mayo) + ", mustard: " + to_string(mustard);
		}
};

Sandwhich::Sandwhich()
{
	tomatoes = 2;
	cheese = 1;
	mayo = 1.0;
	mustard = 0.05;
}

Sandwhich::Sandwhich(int _tomatoes)
{
	tomatoes = _tomatoes;
	cheese = 1;
	mayo = 1.0;
	mustard = 0.05;
}


Sandwhich::Sandwhich(int _tomatoes, int _cheese, float _mayo, float _mustard){
	tomatoes = _tomatoes;
	cheese = _cheese;
	mayo - _mayo;
	mustard = _mustard;
}



class Truck {
	protected:
		vector<Sandwhich> sandwhiches;

	public:
		Truck();

		void add_sandwhich(Sandwhich sandwhich){
			sandwhiches.push_back(sandwhich);
		}


		string check(){
			string check_string = "";
			for (int x = 0; x < sandwhiches.size(); x++){
				check_string += sandwhiches[x].print() + '\n';
			}
			return check_string;
		}
};


Truck::Truck() {}




int main(){


	Truck truck;

	Sandwhich sandwhich_1;

	Sandwhich sandwhich_2;

	sandwhich_2.set_mustard(0);

	Sandwhich sandwhich_3;
	sandwhich_3.set_cheese(2);

	Sandwhich sandwhich_4;



	truck.add_sandwhich(sandwhich_1);
	truck.add_sandwhich(sandwhich_2);
	truck.add_sandwhich(sandwhich_3);
	truck.add_sandwhich(sandwhich_4);




	cout << "Checking delivery truck... " << endl;
	cout << truck.check() << endl;

	cout << "Checking sandwhich 2 mustard " + to_string(sandwhich_2.get_mustard()) << endl;




	system("pause");

}