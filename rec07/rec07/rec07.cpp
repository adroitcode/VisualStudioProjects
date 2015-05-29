#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <sstream>


using namespace std;

class Instrument {
	private:
		string name;



	public:
		Instrument(){

		}

		Instrument(string _name){
			name = _name;
		}
		


		virtual
			void makeSound() const = 0;



		virtual
			void play() const = 0;

		//void makeSound(){
		//	cout << "Basic instrument sound" << endl;
		//}

};



class Brass : public Instrument {
	private:
		unsigned size; //12,9,4'
	public:
		Brass(unsigned _size) : Instrument() {
			size = _size;
		}

		
		

		void makeSound() const {

			cout << "To make a sound... blow on a mouthpiece of size " + to_string(size) << endl;
		}


		void play() const {

			cout << "To make a sound... blow on a mouthpiece of size " + to_string(size) << endl;
		}

		
};



class Trumpet : public Brass {
public:
	Trumpet(unsigned _size) : Brass(_size){

	}

	void play() const {

		cout << "TRUMP";
	}


};


class Trombone : public Brass {
public:
	Trombone(unsigned _size) : Brass(_size) {

	}

	void play() const {

		cout << "BLAT";
	}


};


class Strings : public Instrument {
private:
	unsigned pitch;
public:
	Strings(unsigned _pitch) : Instrument() {
		pitch = _pitch;
	}


	void makeSound() const {

		cout << "To make a sound... bow a string with pitch " + to_string(pitch) << endl;
	}

	void play() const {

		cout << "To make a sound... bow a string with pitch " + to_string(pitch) << endl;
	}
};


class Violin : public Strings {
public:
	Violin(unsigned _pitch) : Strings(_pitch){

	}

	void play() const {

		cout << "SCREECH";
	}


};



class Cello : public Strings {
public:
	Cello(unsigned _pitch) : Strings(_pitch){

	}

	void play() const {

		cout << "SQWAK";
	}


};


class Percussion : public Instrument {

public:
	Percussion() : Instrument(){
	
	}


	void makeSound() const {

		cout << "To make a sound... hit me!" << endl;
	}

	void play() const {

		cout << "To make a sound... hit me!" << endl;
	}
};



class Drum : public Percussion {
	public:
		Drum() : Percussion(){

		}


		void play() const {

			cout << "BOOM";
		}

};


class Cymbal : public Percussion {
public:
	Cymbal() : Percussion(){

	}


	void play() const {

		cout << "CRASH";
	}


};



class Musician {
public:
	Musician() : instr(NULL) {}
	void acceptInstr(Instrument & i) { instr = &i; }
	Instrument* giveBackInstr() {
		Instrument* tmp(instr);
		instr = NULL;
		return tmp;
	}
	void testPlay() const {
		if (instr)
			instr->play();
		else
			cerr << "have no instr" << endl;
	}
private:
	Instrument* instr;
};



class MILL {
	private:
		vector<Instrument *> inventory;

	public:
		MILL(){

		}
		void receiveInstr(Instrument &instrument){
			instrument.makeSound();

			inventory.insert(inventory.begin(), &instrument);
		}


		Instrument* loanOut(){
			if (inventory.size() > 0){
				Instrument *instrument = inventory[0];


				inventory.erase(inventory.begin());

				return instrument;
			}
			else{
				return NULL;
			}
			
		}




		void dailyTestPlay(){
			for (size_t x = 0; x < inventory.size(); x++){
				inventory[x]->makeSound();
			}
		}

};



class Orch {
	private:
		vector<Musician *> players;
	public:
		Orch(){

		}

		void addPlayer(Musician* player){
			players.push_back(player);
		}


		void play(){
			for (size_t x = 0; x < players.size(); x++){
				players[x]->testPlay();
			}
			cout << endl;
		}
};


// PART ONE
int main()
{

	// The initialization phase

	Drum drum;
	Cello cello(673);
	Cymbal cymbal;
	Trombone tbone(4);
	Trumpet trpt(12);
	Violin violin(567);

	MILL mill;
	mill.receiveInstr(trpt);
	mill.receiveInstr(violin);
	mill.receiveInstr(tbone);
	mill.receiveInstr(drum);
	mill.receiveInstr(cello);
	mill.receiveInstr(cymbal);

	Musician bob;
	Musician sue;
	Musician mary;
	Musician ralph;
	Musician jody;
	Musician morgan;

	Orch orch;



	// THE SCENARIO

	//Bob joins the orchestra without an instrument.
	orch.addPlayer(&bob);

	//The orchestra performs
	cout << "orch performs" << endl;
	orch.play();

	//Sue gets an instrument from the MIL2 and joins the orchestra.
	sue.acceptInstr(*mill.loanOut());
	orch.addPlayer(&sue);

	//Ralph gets an instrument from the MIL2.
	ralph.acceptInstr(*mill.loanOut());

	//Mary gets an instrument from the MIL2 and joins the orchestra.
	mary.acceptInstr(*mill.loanOut());
	orch.addPlayer(&mary);

	//Ralph returns his instrument to the MIL2.
	mill.receiveInstr(*ralph.giveBackInstr());

	//Jody gets an instrument from the MIL2 and joins the orchestra.
	jody.acceptInstr(*mill.loanOut());
	orch.addPlayer(&jody);

	// morgan gets an instrument from the MIL2
	morgan.acceptInstr(*mill.loanOut());

	//The orchestra performs.
	cout << "orch performs" << endl;
	orch.play();

	//Ralph joins the orchestra.
	orch.addPlayer(&ralph);

	//The orchestra performs.
	cout << "orch performs" << endl;
	orch.play();

	// bob gets an instrument from the MIL2
	bob.acceptInstr(*mill.loanOut());

	// ralph gets an instrument from the MIL2
	ralph.acceptInstr(*mill.loanOut());

	//The orchestra performs.
	cout << "orch performs" << endl;;
	orch.play();

	//Morgan joins the orchestra.
	orch.addPlayer(&morgan);

	//The orchestra performs.
	cout << "orch performs" << endl;
	orch.play();
	system("pause");

}
