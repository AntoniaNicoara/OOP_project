#include"pch.h"
#include <iostream>
#include<string>
#include <fstream>
#include<map>
#include<set>
#include<vector>
#include<list>
using namespace std;

class Participant
{
private:
	const int id;
	char numeParticipant[20] = "Anonim";
	int varsta = 0;
	int nrEditiiParticipante = 0;
	int* editiiParticipante = NULL;

public:
	Participant() :id(0)
	{}

	Participant(int id, int varsta) :id(id)
	{
		strcpy(this->numeParticipant, "Anonim");
		this->varsta = varsta;
		this->nrEditiiParticipante = 0;
		this->editiiParticipante = NULL;
	}

	Participant(int id, char numeParticipant[20], int varsta, int nrEditiiParticipante, int* editiiParticipante) :id(id)
	{
		strcpy(this->numeParticipant, numeParticipant);
		this->varsta = varsta;
		this->nrEditiiParticipante = nrEditiiParticipante;
		if (nrEditiiParticipante > 0 && editiiParticipante != NULL)
		{
			this->editiiParticipante = new int[this->nrEditiiParticipante];
			for (int i = 0; i < nrEditiiParticipante; i++)
				this->editiiParticipante[i] = editiiParticipante[i];
		}
		else
			this->editiiParticipante = 0;
	}

	Participant(const Participant& p) :id(p.id)
	{
		strcpy(this->numeParticipant, p.numeParticipant);
		this->varsta = p.varsta;
		this->nrEditiiParticipante = p.nrEditiiParticipante;
		if (p.nrEditiiParticipante != 0 && p.editiiParticipante != NULL)
		{
			this->editiiParticipante = new int[this->nrEditiiParticipante];
			for (int i = 0; i < p.nrEditiiParticipante; i++)
				this->editiiParticipante[i] = p.editiiParticipante[i];
		}
		else
			this->editiiParticipante = 0;
	}

	Participant& operator=(const Participant& p)
	{
		if (this != &p)
		{
			delete[]this->editiiParticipante;
			strcpy(this->numeParticipant, p.numeParticipant);
			this->varsta = p.varsta;
			this->nrEditiiParticipante = p.nrEditiiParticipante;
			if (p.nrEditiiParticipante != 0 && p.editiiParticipante != NULL)
			{
				this->editiiParticipante = new int[this->nrEditiiParticipante];
				for (int i = 0; i < p.nrEditiiParticipante; i++)
					this->editiiParticipante[i] = p.editiiParticipante[i];
			}
			else
				this->editiiParticipante = 0;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Participant& p)
	{
		out << "\n-----------------------------------------------";
		out << "\nNume participant:" << p.numeParticipant;
		out << "\nVarsta:" << p.varsta;
		if (p.nrEditiiParticipante > 0 && p.editiiParticipante != 0)
		{
			out << "\nNumar editii participante:" << p.nrEditiiParticipante;
			out << "\nIstoric editii participare:";
			for (int i = 0; i < p.nrEditiiParticipante; i++)
				out << p.editiiParticipante[i] << " ";
		}
		else
		{
			out << "\nNu exista editii anterioare!";
		}
		out << "\n-----------------------------------------------";
		return out;
	}

	friend istream& operator>>(istream& in, Participant& p)
	{
		delete[]p.editiiParticipante;
		cout << "\nDati nume participant:";
		//in.getline(p.numeParticipant,21);
		in >> p.numeParticipant;
		cout << "\nDati varsta participantului:";
		in >> p.varsta;
		cout << "\nDati numarul de editii la care a participat:";
		in >> p.nrEditiiParticipante;
		if (p.nrEditiiParticipante > 0)
		{
			p.editiiParticipante = new int[p.nrEditiiParticipante];
			for (int i = 0; i < p.nrEditiiParticipante; i++)
			{
				cout << "\nDati editiile in care a participat:";
				in >> p.editiiParticipante[i];
			}
		}
		return in;
	}

	char* getnumeParticipant()
	{
		return this->numeParticipant;
	}

	void setnumeParticipant(char numeParticipant[20])
	{
		if (strlen(numeParticipant) >= 3)
			strcpy(this->numeParticipant, numeParticipant);
	}

	int getvarsta()
	{
		return this->varsta;
	}

	void setvarsta(int varsta)
	{
		if (varsta > 18)
			this->varsta = varsta;
	}

	int getnrEditiiParticipante()
	{
		return this->nrEditiiParticipante;
	}

	void setnrEditiiParticipante(int nrEditiiParticipante)
	{
		if (nrEditiiParticipante > 0)
			this->nrEditiiParticipante = nrEditiiParticipante;
	}

	int* geteditiiParticipante()
	{
		return this->editiiParticipante;
	}

	void seteditiiParticipante(int nrEditiiParticipante, int* editiiParticipante)
	{
		if (this->editiiParticipante != NULL)
			delete[]this->editiiParticipante;
		if (nrEditiiParticipante > 0 && editiiParticipante != NULL)
		{
			this->nrEditiiParticipante = nrEditiiParticipante;
			this->editiiParticipante = new int[this->nrEditiiParticipante];
			for (int i = 0; i < this->nrEditiiParticipante; i++) {
				this->editiiParticipante[i] = editiiParticipante[i];
			}
		}
	}

	int& operator[](int index)
	{
		if (index >= 0 && index < this->nrEditiiParticipante)
			return this->editiiParticipante[index];
	}

	Participant& operator+=(int editie)
	{
		Participant copie = *this;
		delete[]this->editiiParticipante;
		this->nrEditiiParticipante++;
		this->editiiParticipante = new int[this->nrEditiiParticipante];
		for (int i = 0; i < copie.nrEditiiParticipante; i++)
			this->editiiParticipante[i] = copie.editiiParticipante[i];
		this->editiiParticipante[this->nrEditiiParticipante - 1] = editie;
		return *this;

	}

	Participant operator+ (int editie)
	{
		Participant rez = *this;
		rez += editie;
		return rez;
	}

	Participant& operator++()//PREINCREMENTARE
	{
		this->varsta++;
		return *this;
	}

	Participant operator++(int)//POSTINCREMENTARE
	{
		Participant rez = *this;
		this->varsta++;
		return rez;
	}

	explicit operator int()
	{
		return this->varsta;
	}

	Participant operator!()
	{
		Participant rez = *this;
		rez.nrEditiiParticipante = 0;
		delete[] rez.editiiParticipante;
		rez.editiiParticipante = NULL;
		return rez;
	}

	bool operator>(Participant p)
	{
		return this->varsta > p.varsta;
	}

	bool operator==(Participant& p)
	{
		bool ok = 0;
		if (this->numeParticipant == p.numeParticipant && this->varsta == p.varsta && this->nrEditiiParticipante == p.nrEditiiParticipante)
			for (int i = 0; i < this->nrEditiiParticipante; i++)
			{
				if (this->editiiParticipante[i] == p.editiiParticipante[i])
					ok = 1;
				else
					ok = 0;
			}
		else
			ok = 0;
		return ok;
	}

	//METODA VIRTUALA
	virtual string tipClasa()
	{
		return "\nClasa de baza!";
	}

	~Participant()
	{
		if (this->editiiParticipante != NULL)
			delete[]this->editiiParticipante;
	}

	void writeToFile(fstream& f)
	{
		//scriere sir de caractere (char static)
		//scriere lungime
		int lg = strlen(this->numeParticipant) + 1;
		f.write(this->numeParticipant, sizeof(char) * lg);
		//scriere sir de caractere
		f.write(this->numeParticipant, lg);
		//scriere valoare int
		f.write((char*)&this->varsta, sizeof(int));
		//scriere valoare int
		f.write((char*)&this->nrEditiiParticipante, sizeof(int));
		//scriere vector de int-uri
		string editiiParticipanteString;
		for (int i = 0; i < nrEditiiParticipante; i++)
		{
			editiiParticipanteString = std::to_string(editiiParticipante[i]);
			f.write(editiiParticipanteString.c_str(), sizeof(char) * (editiiParticipanteString.length() + 1));
			//.c_str() -- transforma un string intr-un const char*(adica ii adauga la final un terminator)
			f.write(" ", sizeof(char) * 2);
		}
	}

	void readFromFile(fstream& f)
	{
		//citire sir de caractere
		//citire lg
		int lg = 0;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		strcpy(this->numeParticipant, buffer);
		delete[] buffer;
		//citire valori int
		f.read((char*)&this->varsta, sizeof(int));
		f.read((char*)&this->nrEditiiParticipante, sizeof(int));
		//citire vectorul de int-uri
		delete[] this->editiiParticipante;
		if (this->nrEditiiParticipante > 0)
		{
			this->editiiParticipante = new int[this->nrEditiiParticipante];
			for (int i = 0; i < this->nrEditiiParticipante; i++)
				f.read((char*)&this->editiiParticipante[i], sizeof(int));
		}
	}
};

//CLASA ABSTRACTA CU 2 METH VIRT PURE
class Abstracta
{
	virtual int calculCastigMediu() = 0; //in FostiCastigatori
	virtual int calculPremiiInBaniTotale() = 0; //in FostiCastigatori
	virtual string descalificare() = 0; //in TraseuMontan si TraseuCampie
};

class FostiCastigatori : public Participant //CLASA DERIVATA DIN PARTICIPANT
{
	int nreditiiCastigate = 0;
	int* premiiBani = NULL;
public:
	FostiCastigatori()
	{}

	FostiCastigatori(int id, char numeParticipant[20], int varsta, int nrEditiiParticipante, int* editiiParticipante, int nreditiiCastigate, int* premiiBani) :Participant(id, numeParticipant, varsta, nrEditiiParticipante, editiiParticipante)
	{
		this->nreditiiCastigate = nreditiiCastigate;
		this->premiiBani = new int[this->nreditiiCastigate];
		for (int i = 0; i < this->nreditiiCastigate; i++)
		{
			this->premiiBani[i] = premiiBani[i];
		}

	}

	FostiCastigatori(const FostiCastigatori& fc) :Participant(fc)
	{
		this->nreditiiCastigate = fc.nreditiiCastigate;
		this->premiiBani = new int[this->nreditiiCastigate];
		for (int i = 0; i < this->nreditiiCastigate; i++)
		{
			this->premiiBani[i] = fc.premiiBani[i];
		}
	}

	friend ostream& operator<<(ostream& out, const FostiCastigatori& fc)
	{
		out << (Participant)fc;
		out << "\nNumar editii castigate:" << fc.nreditiiCastigate;
		for (int i = 0; i < fc.nreditiiCastigate; i++)
			out << "\nPremiile in bani castigate:" << fc.premiiBani[i] << " ";
		return out;
	}

	int calculCastigMediu()
	{
		cout << "\nCastigul mediu al participantului este:";
		int c = 0;
		for (int i = 0; i < this->nreditiiCastigate; i++)
			c += this->premiiBani[i];
		return c / this->nreditiiCastigate;
	}

	int calculPremiiInBaniTotale()
	{
		cout << "\nPremiul total in bani al participantului este:";
		int s = 0;
		for (int i = 0; i < this->nreditiiCastigate; i++)
			s += this->premiiBani[i];
		return s;
	}

	string tipClasa()
	{
		return "\nClasa derivata FOSTI CASTIGATORI!";
	}

	~FostiCastigatori()
	{
		delete[]this->premiiBani;
	}
};

class Traseu
{
private:
	char numeTraseu[20] = "Anonim";
	float lungimeTraseu = 0;
	int nrTururideEfectuat = 0;
	float* timpPeTurEfectuat = NULL;

public:
	Traseu()
	{}

	Traseu(float lungimeTraseu)
	{
		strcpy(this->numeTraseu, "Anonim");
		this->lungimeTraseu = lungimeTraseu;
		this->nrTururideEfectuat = 0;
		this->timpPeTurEfectuat = NULL;
	}

	Traseu(char numeTraseu[20], float lungimeTraseu, int nrTururideEfectuat, float* timpPeTurEfectuat)
	{
		strcpy(this->numeTraseu, numeTraseu);
		this->lungimeTraseu = lungimeTraseu;
		this->nrTururideEfectuat = nrTururideEfectuat;
		if (nrTururideEfectuat > 0 && timpPeTurEfectuat != NULL)
		{
			this->timpPeTurEfectuat = new float[this->nrTururideEfectuat];
			for (int i = 0; i < nrTururideEfectuat; i++)
				this->timpPeTurEfectuat[i] = timpPeTurEfectuat[i];
		}
		else
			this->timpPeTurEfectuat = 0;
	}

	Traseu(const Traseu& t)
	{
		strcpy(this->numeTraseu, t.numeTraseu);
		this->lungimeTraseu = t.lungimeTraseu;
		this->nrTururideEfectuat = t.nrTururideEfectuat;
		if (t.nrTururideEfectuat > 0 && t.timpPeTurEfectuat != NULL)
		{
			this->timpPeTurEfectuat = new float[this->nrTururideEfectuat];
			for (int i = 0; i < t.nrTururideEfectuat; i++)
				this->timpPeTurEfectuat[i] = t.timpPeTurEfectuat[i];
		}
		else
			this->timpPeTurEfectuat = 0;
	}

	Traseu& operator=(const Traseu& t)
	{
		if (this != &t)
		{
			delete[]this->timpPeTurEfectuat;
			strcpy(this->numeTraseu, t.numeTraseu);
			this->lungimeTraseu = t.lungimeTraseu;
			this->nrTururideEfectuat = t.nrTururideEfectuat;
			if (t.nrTururideEfectuat > 0 && t.timpPeTurEfectuat != NULL)
			{
				this->timpPeTurEfectuat = new float[this->nrTururideEfectuat];
				for (int i = 0; i < t.nrTururideEfectuat; i++)
					this->timpPeTurEfectuat[i] = t.timpPeTurEfectuat[i];
			}
			else
				this->timpPeTurEfectuat = 0;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Traseu& t)
	{
		out << "\n-----------------------------------------------";
		out << "\nNume traseu:" << t.numeTraseu;
		out << "\nLungime traseu in km:" << t.lungimeTraseu;
		if (t.nrTururideEfectuat > 0 && t.timpPeTurEfectuat != NULL)
		{
			out << "\nNumar ture de efectuat pe traseu:" << t.nrTururideEfectuat;
			out << "\nIstoric timpi ture(in secunde):";
			for (int i = 0; i < t.nrTururideEfectuat; i++)
				out << t.timpPeTurEfectuat[i] << " ";
		}
		else
		{
			out << "\nNu s-au efectuat ture pe acest traseu!";
		}
		out << "\n-----------------------------------------------";
		return out;
	}

	friend istream& operator>>(istream& in, Traseu& t)
	{
		delete[]t.timpPeTurEfectuat;
		cout << "\nDati numele traseului:";
		in >> t.numeTraseu;
		cout << "\nDati lungimea traseului in km:";
		in >> t.lungimeTraseu;
		cout << "\nDati numarul de ture care trebuie efectuate pe traseu:";
		in >> t.nrTururideEfectuat;
		if (t.nrTururideEfectuat > 0)
		{
			t.timpPeTurEfectuat = new float[t.nrTururideEfectuat];
			for (int i = 0; i < t.nrTururideEfectuat; i++)
			{
				cout << "\nDati timpii pe fiecare tura(in secunde):";
				in >> t.timpPeTurEfectuat[i];
			}
		}
		return in;
	}

	char* getnumeTraseu()
	{
		return this->numeTraseu;
	}

	void setnumeTraseu(char numeTraseu[20])
	{
		if (strlen(numeTraseu) >= 3)
			strcpy(this->numeTraseu, numeTraseu);
	}

	float getlungimeTraseu()
	{
		return this->lungimeTraseu;
	}

	void setlungimeTraseu(float lungimeTraseu)
	{
		if (lungimeTraseu > 1)
			this->lungimeTraseu = lungimeTraseu;
	}

	int getnrTururideEfectuat()
	{
		return this->nrTururideEfectuat;
	}

	void setnrTururiEfectuate(int nrTururideEfectuat)
	{
		if (nrTururideEfectuat > 0)
			this->nrTururideEfectuat = nrTururideEfectuat;
	}

	float* gettimpPeTurEfectuat()
	{
		return this->timpPeTurEfectuat;
	}

	void settimpPeTurEfectuat(int nrTururideEfectuat, float* timpPeTurEfectuat)
	{
		if (this->timpPeTurEfectuat != NULL)
			delete[]this->timpPeTurEfectuat;
		if (nrTururideEfectuat > 0 && timpPeTurEfectuat != NULL)
		{
			this->nrTururideEfectuat = nrTururideEfectuat;
			this->timpPeTurEfectuat = new float[this->nrTururideEfectuat];
			for (int i = 0; i < this->nrTururideEfectuat; i++)
				this->timpPeTurEfectuat[i] = timpPeTurEfectuat[i];
		}
	}

	float& operator[](int index)
	{
		if (index >= 0 && index < this->nrTururideEfectuat)
			return this->timpPeTurEfectuat[index];
	}

	Traseu& operator+=(float timp)
	{
		Traseu copie = *this;
		delete[]this->timpPeTurEfectuat;
		this->nrTururideEfectuat++;
		this->timpPeTurEfectuat = new float[this->nrTururideEfectuat];
		for (int i = 0; i < copie.nrTururideEfectuat; i++)
			this->timpPeTurEfectuat[i] = copie.timpPeTurEfectuat[i];
		this->timpPeTurEfectuat[this->nrTururideEfectuat - 1] = timp;
		return *this;

	}

	Traseu operator+ (float timp)
	{
		Traseu rez = *this;
		rez += timp;
		return rez;
	}

	Traseu& operator++()//PREINCREMENTARE
	{
		this->lungimeTraseu++;
		return *this;
	}

	Traseu operator++(int)//POSTINCREMENTARE
	{
		Traseu rez = *this;
		this->lungimeTraseu++;
		return rez;
	}

	explicit operator int()
	{
		return this->lungimeTraseu;
	}

	Traseu operator!()
	{
		Traseu rez = *this;
		rez.nrTururideEfectuat = 0;
		delete[] rez.timpPeTurEfectuat;
		rez.timpPeTurEfectuat = NULL;
		return rez;
	}

	bool operator>(Traseu t)
	{
		return this->lungimeTraseu > t.lungimeTraseu;
	}

	bool operator==(Traseu& t)
	{
		bool ok = 0;
		if (this->numeTraseu == t.numeTraseu && this->lungimeTraseu == t.lungimeTraseu && this->nrTururideEfectuat == t.nrTururideEfectuat)
			for (int i = 0; i < this->nrTururideEfectuat; i++)
			{
				if (this->timpPeTurEfectuat[i] == t.timpPeTurEfectuat[i])
					ok = 1;
				else
					ok = 0;
			}
		else
			ok = 0;
		return ok;
	}

	//METODA VIRTUALA
	virtual string tipClasa()
	{
		return "\nClasa de baza!";
	}

	~Traseu()
	{
		if (this->timpPeTurEfectuat != NULL)
			delete[]this->timpPeTurEfectuat;
	}

	void writeToFile(fstream& f)
	{
		//scriere sir de caractere (char static)
		//scriere lungime
		int lg = strlen(this->numeTraseu) + 1;
		f.write(this->numeTraseu, sizeof(char) * lg);
		//scriere sir de caractere
		f.write(this->numeTraseu, lg);
		//scriere valoare float
		f.write((char*)&this->lungimeTraseu, sizeof(float));
		//scriere valoare int
		f.write((char*)&this->nrTururideEfectuat, sizeof(int));
		//scriere vector de float-uri
		string timpPeTurEfectuatString;
		for (int i = 0; i < nrTururideEfectuat; i++)
		{
			timpPeTurEfectuatString = std::to_string(timpPeTurEfectuat[i]);
			f.write(timpPeTurEfectuatString.c_str(), sizeof(char) * (timpPeTurEfectuatString.length() + 1));
			f.write(" ", sizeof(char) * 2);
		}
	}

	void readFromFile(fstream& f)
	{
		//citire sir de caractere
		//citire lg
		int lg = 0;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		strcpy(this->numeTraseu, buffer);
		delete[] buffer;
		//citire valori float, int
		f.read((char*)&this->lungimeTraseu, sizeof(float));
		f.read((char*)&this->nrTururideEfectuat, sizeof(int));
		//citire vectorul de float-uri
		delete[] this->timpPeTurEfectuat;
		if (this->nrTururideEfectuat > 0)
		{
			this->timpPeTurEfectuat = new float[this->nrTururideEfectuat];
			for (int i = 0; i < this->nrTururideEfectuat; i++)
				f.read((char*)&this->timpPeTurEfectuat[i], sizeof(int));
		}
	}
};

//IERARHIE CARE EXEMPLIFICA O FAMILIE DE CLASE
class TraseuMontan : public Traseu //CLASA DERIVATA DIN TRASEU
{
	int tururiSuplimentare = 0;
	bool traseuNou = 0;
public:
	TraseuMontan()
	{}

	TraseuMontan(char numeTraseu[20], float lungimeTraseu, int nrTururideEfectuat, float* timpPeTurEfectuat, int tururiSuplimentare, bool traseuNou) :Traseu(numeTraseu, lungimeTraseu, nrTururideEfectuat, timpPeTurEfectuat)
	{
		this->tururiSuplimentare = tururiSuplimentare;
		this->traseuNou = traseuNou;
	}

	TraseuMontan(const TraseuMontan& t) :Traseu(t)
	{
		this->tururiSuplimentare = t.tururiSuplimentare;
		this->traseuNou = t.traseuNou;
	}

	friend ostream& operator<<(ostream& out, const TraseuMontan& t)
	{
		out << (Traseu)t;
		out << "\nTure de efectuat in plus pe traseu: " << t.tururiSuplimentare;
		out << "\nA mai fost acest traseu si in editiile trecute?(1-Da sau 0-Nu): " << t.traseuNou;
		return out;
	}

	string descalificare()
	{
		if (this->tururiSuplimentare >= 5)
			return "\nDESCALIFICAT";
		else
			return "\nParticipantul nu a fost descalificat";
	}

	string tipClasa()
	{
		return "\nClasa derivata TRASEU MONTAN!";
	}

	~TraseuMontan()
	{

	}
};

class TraseuCampie : public Traseu //CLASA DERIVATA DIN TRASEU
{
	int tururiSuplimentare = 0;
	bool traseuNou = 0;
public:
	TraseuCampie()
	{}

	TraseuCampie(char numeTraseu[20], float lungimeTraseu, int nrTururideEfectuat, float* timpPeTurEfectuat, int tururiSuplimentare, bool traseuNou) :Traseu(numeTraseu, lungimeTraseu, nrTururideEfectuat, timpPeTurEfectuat)
	{
		this->tururiSuplimentare = tururiSuplimentare;
		this->traseuNou = traseuNou;
	}

	TraseuCampie(const TraseuCampie& t) :Traseu(t)
	{
		this->tururiSuplimentare = t.tururiSuplimentare;
		this->traseuNou = t.traseuNou;
	}

	friend ostream& operator<<(ostream& out, const TraseuCampie& t)
	{
		out << (Traseu)t;
		out << "\nTure de efectuat in plus pe traseu: " << t.tururiSuplimentare;
		out << "\nA mai fost acest traseu si in editiile trecute?(1-Da sau 0-Nu): " << t.traseuNou;
		return out;
	}

	string descalificare()
	{
		if (this->tururiSuplimentare >= 5)
			return "\nDESCALIFICAT";
		else
			return "\nParticipantul nu a fost descalificat";
	}

	string tipClasa()
	{
		return "\nClasa derivata TRASEU CAMPIE!";
	}

	~TraseuCampie()
	{

	}
};

class Sponsor
{
private:
	char* numeCompanie;
	char numeDetinator[30] = "Anonim";
	int nrEditiiSponsorizate = 0;
	float* sumeAcordate = NULL;
	static float sumaMinimaDeDonat;

public:
	Sponsor()
	{}

	Sponsor(const char* numeCompanie)
	{
		this->numeCompanie = new char[strlen(numeCompanie) + 1];
		strcpy(this->numeCompanie, numeCompanie);
	}

	Sponsor(const char* numeCompanie, char numeDetinator[30], int nrEditiiSponsorizate, float* sumeAcordate)
	{
		this->numeCompanie = new char[strlen(numeCompanie) + 1];
		strcpy(this->numeCompanie, numeCompanie);
		strcpy(this->numeDetinator, numeDetinator);
		this->nrEditiiSponsorizate = nrEditiiSponsorizate;
		if (nrEditiiSponsorizate > 0 && sumeAcordate != NULL)
		{
			this->sumeAcordate = new float[this->nrEditiiSponsorizate];
			for (int i = 0; i < nrEditiiSponsorizate; i++)
				this->sumeAcordate[i] = sumeAcordate[i];
		}
		else
			this->sumeAcordate = 0;
	}

	Sponsor(const Sponsor& s)
	{
		this->numeCompanie = new char[strlen(s.numeCompanie) + 1];
		strcpy(this->numeCompanie, s.numeCompanie);
		strcpy(this->numeDetinator, s.numeDetinator);
		this->nrEditiiSponsorizate = s.nrEditiiSponsorizate;
		if (s.nrEditiiSponsorizate > 0 && s.sumeAcordate != NULL)
		{
			this->sumeAcordate = new float[this->nrEditiiSponsorizate];
			for (int i = 0; i < s.nrEditiiSponsorizate; i++)
				this->sumeAcordate[i] = s.sumeAcordate[i];
		}
		else
			this->sumeAcordate = 0;
	}

	Sponsor& operator=(const Sponsor& s)
	{
		if (this != &s)
		{
			if (this->numeCompanie != NULL) {
				delete[]this->numeCompanie;
			}
			this->numeCompanie = new char[strlen(s.numeCompanie) + 1];
			strcpy(this->numeCompanie, s.numeCompanie);
			strcpy(this->numeDetinator, s.numeDetinator);
			this->nrEditiiSponsorizate = s.nrEditiiSponsorizate;
			if (s.nrEditiiSponsorizate > 0 && s.sumeAcordate != NULL)
			{
				this->sumeAcordate = new float[this->nrEditiiSponsorizate];
				for (int i = 0; i < s.nrEditiiSponsorizate; i++)
					this->sumeAcordate[i] = s.sumeAcordate[i];
			}
			else
				this->sumeAcordate = 0;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Sponsor& s)
	{
		out << "\n-----------------------------------------------";
		out << "\nNume companie:" << s.numeCompanie;
		out << "\nNume detinator companie:" << s.numeDetinator;
		if (s.nrEditiiSponsorizate > 0 && s.sumeAcordate != NULL)
		{
			out << "\nNumar editii de sponzorizare:" << s.nrEditiiSponsorizate;
			out << "\nSume acordate in editiile precedente(in lei):";
			for (int i = 0; i < s.nrEditiiSponsorizate; i++)
				out << s.sumeAcordate[i] << " ";
		}
		else
		{
			out << "\nSponsorul nu a acordat bani in editiile trecute!";
		}
		out << "\n-----------------------------------------------";
		return out;
	}

	friend istream& operator>>(istream& in, Sponsor& s)
	{
		delete[]s.numeCompanie;
		delete[]s.sumeAcordate;
		cout << "\nDati numele companiei:";
		char aux[100];
		//in.getline(aux, 99);
		in >> aux;
		s.numeCompanie = new char[strlen(aux) + 1];
		strcpy(s.numeCompanie, aux);
		cout << "\nDati numele detinatorului:";
		in >> s.numeDetinator;
		cout << "\nDati numarul de editii in care compania a fost sponsor:";
		in >> s.nrEditiiSponsorizate;
		if (s.nrEditiiSponsorizate > 0)
		{
			s.sumeAcordate = new float[s.nrEditiiSponsorizate];
			for (int i = 0; i < s.nrEditiiSponsorizate; i++)
			{
				cout << "\nDati sumele de bani acordate in editiile precedente(in lei):";
				in >> s.sumeAcordate[i];
			}
		}
		return in;
	}

	char* getnumeCompanie()
	{
		return this->numeCompanie;
	}

	void setnumeCompanie(const char* numeCompanie)
	{
		if (this->numeCompanie != NULL)
			delete[]this->numeCompanie;
		if (strlen(numeCompanie) >= 4)
			strcpy(this->numeCompanie, numeCompanie);
	}

	char* getnumeDetinator()
	{
		return this->numeDetinator;
	}

	void setnumeDetinator(char numeDetinator[30])
	{
		if (strlen(numeDetinator) >= 3)
			strcpy(this->numeDetinator, numeDetinator);
	}

	int getnrEditiiSponsorizate()
	{
		return this->nrEditiiSponsorizate;
	}

	void setnrEditiiSponsorizate(int nrEditiiSponsorizate)
	{
		if (nrEditiiSponsorizate >= 0)
			this->nrEditiiSponsorizate = nrEditiiSponsorizate;
	}

	float* getsumeAcordate()
	{
		return this->sumeAcordate;
	}

	void setsumeAcordate(int nrEditiiSponsorizate, float* sumeAcordate)
	{
		if (this->sumeAcordate != NULL)
			delete[]this->sumeAcordate;
		if (nrEditiiSponsorizate > 0 && sumeAcordate != NULL)
		{
			this->nrEditiiSponsorizate = nrEditiiSponsorizate;
			this->sumeAcordate = new float[this->nrEditiiSponsorizate];
			for (int i = 0; i < this->nrEditiiSponsorizate; i++)
				this->sumeAcordate[i] = sumeAcordate[i];
		}
	}

	float& operator[](int index)
	{
		if (index >= 0 && index < this->nrEditiiSponsorizate)
			return this->sumeAcordate[index];
	}

	Sponsor& operator+=(float suma)
	{
		Sponsor copie = *this;
		delete[]this->sumeAcordate;
		this->nrEditiiSponsorizate++;
		this->sumeAcordate = new float[this->nrEditiiSponsorizate];
		for (int i = 0; i < copie.nrEditiiSponsorizate; i++)
			this->sumeAcordate[i] = copie.sumeAcordate[i];
		this->sumeAcordate[this->nrEditiiSponsorizate - 1] = suma;
		return *this;

	}

	Sponsor operator+ (float suma)
	{
		Sponsor rez = *this;
		rez += suma;
		return rez;
	}

	Sponsor& operator++()//PREINCREMENTARE
	{
		this->nrEditiiSponsorizate++;
		return *this;
	}

	Sponsor operator++(int)//POSTINCREMENTARE
	{
		Sponsor rez = *this;
		this->nrEditiiSponsorizate++;
		return rez;
	}

	explicit operator int()
	{
		return this->nrEditiiSponsorizate;
	}

	Sponsor operator!()
	{
		Sponsor rez = *this;
		rez.nrEditiiSponsorizate = 0;
		delete[] rez.sumeAcordate;
		rez.sumeAcordate = NULL;
		return rez;
	}

	bool operator>(Sponsor s)
	{
		return this->nrEditiiSponsorizate > s.nrEditiiSponsorizate;
	}

	bool operator==(Sponsor& s)
	{
		bool ok = 0;
		if (this->numeCompanie == s.numeCompanie && this->numeDetinator == s.numeDetinator && this->nrEditiiSponsorizate == s.nrEditiiSponsorizate)
			for (int i = 0; i < this->nrEditiiSponsorizate; i++)
			{
				if (this->sumeAcordate[i] == s.sumeAcordate[i])
					ok = 1;
				else
					ok = 0;
			}
		else
			ok = 0;
		return ok;
	}

	~Sponsor()
	{
		if (this->sumeAcordate != NULL)
			delete[]this->sumeAcordate;
	}

	void writeToFile(fstream& f)
	{
		//scriere char*
		f.write(this->numeCompanie, sizeof(char) * (strlen(this->numeCompanie) + 1));
		//scriere sir de caractere (char static)
		//scriere lungime
		int lg = strlen(this->numeDetinator) + 1;
		f.write(this->numeDetinator, sizeof(char) * lg);
		//scriere sir de caractere
		f.write(this->numeDetinator, lg);
		//scriere valoare int
		f.write((char*)&this->nrEditiiSponsorizate, sizeof(int));
		//scriere vector de float-uri
		string sumeAcordateString;
		for (int i = 0; i < nrEditiiSponsorizate; i++)
		{
			sumeAcordateString = std::to_string(sumeAcordate[i]);
			f.write(sumeAcordateString.c_str(), sizeof(char) * (sumeAcordateString.length() + 1));
			f.write(" ", sizeof(char) * 2);
		}
	}

	void readFromFile(fstream& f)
	{
		//citire char*
		f.read((char*)&this->numeCompanie, sizeof(char) * (strlen(this->numeCompanie) + 1));
		//citire sir de caractere
		//citire lg
		int lg = 0;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		strcpy(this->numeDetinator, buffer);
		delete[] buffer;
		//citire valoare int 
		f.read((char*)&this->nrEditiiSponsorizate, sizeof(int));
		//citire vectorul de float-uri
		delete[] this->sumeAcordate;
		if (this->nrEditiiSponsorizate > 0)
		{
			this->sumeAcordate = new float[this->nrEditiiSponsorizate];
			for (int i = 0; i < this->nrEditiiSponsorizate; i++)
				f.read((char*)&this->sumeAcordate[i], sizeof(int));
		}
	}
};
float Sponsor::sumaMinimaDeDonat = 1500;

class Clasament
{
private:
	char numeArbitru[25] = "Anonim";
	char* titluSpecial;
	int traseeEfectuate = 0;
	float* punctajPeTraseu = NULL;
	static int locuri;

public:
	Clasament()
	{}

	Clasament(const char* titluSpecial)
	{
		this->titluSpecial = new char[strlen(titluSpecial) + 1];
		strcpy(this->titluSpecial, titluSpecial);
	}

	Clasament(char numeArbitru[25], const char* titluSpecial, int traseeEfectuate, float* punctajPeTraseu)
	{
		strcpy(this->numeArbitru, numeArbitru);
		this->titluSpecial = new char[strlen(titluSpecial) + 1];
		strcpy(this->titluSpecial, titluSpecial);
		this->traseeEfectuate = traseeEfectuate;
		if (traseeEfectuate > 0 && punctajPeTraseu != NULL)
		{
			this->punctajPeTraseu = new float[this->traseeEfectuate];
			for (int i = 0; i < traseeEfectuate; i++)
				this->punctajPeTraseu[i] = punctajPeTraseu[i];
		}
		else
			this->punctajPeTraseu = 0;
	}

	Clasament(const Clasament& c)
	{
		strcpy(this->numeArbitru, c.numeArbitru);
		this->titluSpecial = new char[strlen(c.titluSpecial) + 1];
		strcpy(this->titluSpecial, c.titluSpecial);
		this->traseeEfectuate = c.traseeEfectuate;
		if (c.traseeEfectuate > 0 && c.punctajPeTraseu != NULL)
		{
			this->punctajPeTraseu = new float[this->traseeEfectuate];
			for (int i = 0; i < c.traseeEfectuate; i++)
				this->punctajPeTraseu[i] = c.punctajPeTraseu[i];
		}
		else
			this->punctajPeTraseu = 0;
	}

	Clasament& operator=(const Clasament& c)
	{
		if (&c != this)
		{
			delete[]this->punctajPeTraseu;
			strcpy(this->numeArbitru, c.numeArbitru);
			this->titluSpecial = new char[strlen(c.titluSpecial) + 1];
			strcpy(this->titluSpecial, c.titluSpecial);
			this->traseeEfectuate = c.traseeEfectuate;
			if (c.traseeEfectuate > 0 && c.punctajPeTraseu != NULL)
			{
				this->punctajPeTraseu = new float[this->traseeEfectuate];
				for (int i = 0; i < c.traseeEfectuate; i++)
					this->punctajPeTraseu[i] = c.punctajPeTraseu[i];
			}
			else
				this->punctajPeTraseu = 0;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Clasament& c)
	{
		out << "\n-----------------------------------------------";
		out << "\nNume arbitru:" << c.numeArbitru;
		out << "\nTitlu special care se acorda:" << c.titluSpecial;
		if (c.traseeEfectuate > 0 && c.punctajPeTraseu != NULL)
		{
			out << "\nNumar de trasee efectuate:" << c.traseeEfectuate;
			out << "\nPunctaj acordat pe fiecare traseu:";
			for (int i = 0; i < c.traseeEfectuate; i++)
				out << c.punctajPeTraseu[i] << " ";
		}
		else
		{
			out << "\nDin cauza unei defectiuni participantul nu a efectuat nici un traseu si nu exista punctaj final!";
		}
		out << "\n-----------------------------------------------";
		return out;
	}

	friend istream& operator>>(istream& in, Clasament& c)
	{
		delete[]c.punctajPeTraseu;
		cout << "\nDati numele arbitrului:";
		in >> c.numeArbitru;
		cout << "\nDati numele tilului special:";
		char aux[100];
		in.getline(aux, 99);
		c.titluSpecial = new char[strlen(aux) + 1];
		strcpy(c.titluSpecial, aux);
		cout << "\nDati numarul de trasee efectuate:";
		in >> c.traseeEfectuate;
		if (c.traseeEfectuate > 0)
		{
			c.punctajPeTraseu = new float[c.traseeEfectuate];
			for (int i = 0; i < c.traseeEfectuate; i++)
			{
				cout << "\nDati punctajul pe fiecare traseu:";
				in >> c.punctajPeTraseu[i];
			}
		}
		return in;
	}

	char* getnumeArbitru()
	{
		return this->numeArbitru;
	}

	void setnumeArbitru(char numeArbitru[25])
	{
		if (strlen(numeArbitru) >= 3)
			strcpy(this->numeArbitru, numeArbitru);
	}

	char* gettitluSpecial()
	{
		return this->titluSpecial;
	}

	void settitluSpecial(const char* titluSpecial)
	{
		if (strlen(titluSpecial) >= 3)
			strcpy(this->titluSpecial, titluSpecial);
	}

	int gettraseeEfectuate()
	{
		return this->traseeEfectuate;
	}

	void settraseeEfectuate(int traseeEfectuate)
	{
		if (traseeEfectuate > 0)
			this->traseeEfectuate = traseeEfectuate;
	}

	float* getpunctajPeTraseu()
	{
		return this->punctajPeTraseu;
	}

	void setpunctajPeTraseu(int traseeEfectuate, float* punctajPeTraseu)
	{
		if (this->punctajPeTraseu != NULL)
			delete[]this->punctajPeTraseu;
		if (traseeEfectuate > 0 && punctajPeTraseu != NULL)
		{
			this->traseeEfectuate = traseeEfectuate;
			this->punctajPeTraseu = new float[this->traseeEfectuate];
			for (int i = 0; i < this->traseeEfectuate; i++)
				this->punctajPeTraseu[i] = punctajPeTraseu[i];
		}
	}

	float& operator[](int index)
	{
		if (index >= 0 && index < this->traseeEfectuate)
			return this->punctajPeTraseu[index];
	}

	Clasament& operator+=(float punctaj)
	{
		Clasament copie = *this;
		delete[]this->punctajPeTraseu;
		this->traseeEfectuate++;
		this->punctajPeTraseu = new float[this->traseeEfectuate];
		for (int i = 0; i < copie.traseeEfectuate; i++)
			this->punctajPeTraseu[i] = copie.punctajPeTraseu[i];
		this->punctajPeTraseu[this->traseeEfectuate - 1] = punctaj;
		return *this;

	}

	Clasament operator+ (float punctaj)
	{
		Clasament rez = *this;
		rez += punctaj;
		return rez;
	}

	explicit operator int()
	{
		return this->traseeEfectuate;
	}

	Clasament operator!()
	{
		Clasament rez = *this;
		rez.traseeEfectuate = 0;
		delete[] rez.punctajPeTraseu;
		rez.punctajPeTraseu = NULL;
		return rez;
	}

	bool operator>(Clasament c)
	{
		return this->traseeEfectuate > c.traseeEfectuate;
	}

	bool operator==(Clasament c)
	{
		bool ok = 0;
		if (this->numeArbitru == c.numeArbitru && this->titluSpecial == c.titluSpecial && this->traseeEfectuate == c.traseeEfectuate)
			for (int i = 0; i < this->traseeEfectuate; i++)
			{
				if (this->punctajPeTraseu[i] == c.punctajPeTraseu[i])
					ok = 1;
				else
					ok = 0;
			}
		else
			ok = 0;
		return ok;
	}

	~Clasament()
	{
		if (this->punctajPeTraseu != NULL)
			delete[]this->punctajPeTraseu;
	}

	void writeToFile(fstream& f)
	{
		//scriere sir de caractere (char static)
		//scriere lungime
		int lg = strlen(this->numeArbitru) + 1;
		f.write(this->numeArbitru, sizeof(char) * lg);
		//scriere sir de caractere
		f.write(this->numeArbitru, lg);
		//scriere char*
		f.write(this->titluSpecial, sizeof(char) * (strlen(this->titluSpecial) + 1));
		//scriere valoare int
		f.write((char*)&this->traseeEfectuate, sizeof(int));
		//scriere vector de float-uri
		string punctajPeTraseuString;
		for (int i = 0; i < traseeEfectuate; i++)
		{
			punctajPeTraseuString = std::to_string(punctajPeTraseu[i]);
			f.write(punctajPeTraseuString.c_str(), sizeof(char) * (punctajPeTraseuString.length() + 1));
			f.write(" ", sizeof(char) * 2);
		}
	}

	void readFromFile(fstream& f)
	{
		//citire sir de caractere
		//citire lg
		int lg = 0;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		strcpy(this->numeArbitru, buffer);
		delete[] buffer;
		//citire char*
		f.read((char*)&this->titluSpecial, sizeof(char) * (strlen(this->titluSpecial) + 1));
		//citire int
		f.read((char*)&this->traseeEfectuate, sizeof(int));
		//citire vectorul de float-uri
		delete[] this->punctajPeTraseu;
		if (this->traseeEfectuate > 0)
		{
			this->punctajPeTraseu = new float[this->traseeEfectuate];
			for (int i = 0; i < this->traseeEfectuate; i++)
				f.read((char*)&this->punctajPeTraseu[i], sizeof(int));
		}
	}
};
int Clasament::locuri = 3;

class Masina
{
private:
	const string serieMasina;
	char* marca;
	char culoare[10] = "Anonim";
	int nrAniParticipare = 0;
	int* AniParticipare = NULL;

public:
	Masina() :serieMasina("ZZZ")
	{}

	Masina(string serieMasina, const char* marca) :serieMasina(serieMasina)
	{
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
	}

	Masina(string serieMasina, const char* marca, char culoare[10], int nrAniParticipare, int* AniParticipare) :serieMasina(serieMasina)
	{
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
		strcpy(this->culoare, culoare);
		this->nrAniParticipare = nrAniParticipare;
		if (nrAniParticipare > 0 && AniParticipare != NULL)
		{
			this->AniParticipare = new int[this->nrAniParticipare];
			for (int i = 0; i < nrAniParticipare; i++)
				this->AniParticipare[i] = AniParticipare[i];
		}
		else
			this->AniParticipare = 0;

	}

	Masina(const Masina& m) :serieMasina(m.serieMasina)
	{
		this->marca = new char[strlen(m.marca) + 1];
		strcpy(this->marca, m.marca);
		strcpy(this->culoare, m.culoare);
		this->nrAniParticipare = m.nrAniParticipare;
		if (m.nrAniParticipare > 0 && m.AniParticipare != NULL)
		{
			this->AniParticipare = new int[this->nrAniParticipare];
			for (int i = 0; i < m.nrAniParticipare; i++)
				this->AniParticipare[i] = m.AniParticipare[i];
		}
		else
			this->AniParticipare = 0;
	}

	Masina& operator=(const Masina& m)
	{
		if (this != &m)
		{
			delete[]this->AniParticipare;
			this->marca = new char[strlen(m.marca) + 1];
			strcpy(this->marca, m.marca);
			strcpy(this->culoare, m.culoare);
			this->nrAniParticipare = m.nrAniParticipare;
			if (m.nrAniParticipare > 0 && m.AniParticipare != NULL)
			{
				this->AniParticipare = new int[this->nrAniParticipare];
				for (int i = 0; i < m.nrAniParticipare; i++)
					this->AniParticipare[i] = m.AniParticipare[i];
			}
			else
				this->AniParticipare = 0;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Masina& m)
	{
		out << "\n-----------------------------------------------";
		out << "\nMarca masinii:" << m.marca;
		out << "\nCuloarea: " << m.culoare;
		if (m.nrAniParticipare > 0 && m.AniParticipare != NULL)
		{
			out << "\nNumarul anilor in care masina a fost pe traseu:" << m.nrAniParticipare;
			out << "\nAnii in care masina a concurat sunt:";
			for (int i = 0; i < m.nrAniParticipare; i++)
				out << m.AniParticipare[i] << " ";
		}
		else
		{
			out << "\nMasina nu a mai fost pe traseu!";
		}
		out << "\n-----------------------------------------------";
		return out;
	}

	friend istream& operator>>(istream& in, Masina& m)
	{
		delete[]m.AniParticipare;
		cout << "\nDati marca masinii:";
		char aux[100];
		in.getline(aux, 99);
		m.marca = new char[strlen(aux) + 1];
		strcpy(m.marca, aux);
		cout << "\nDati culoarea masinii:";
		in.getline(m.culoare, 11);
		cout << "\nDati numarul anilor de participare:";
		in >> m.nrAniParticipare;
		if (m.nrAniParticipare > 0)
		{
			m.AniParticipare = new int[m.nrAniParticipare];
			for (int i = 0; i < m.nrAniParticipare; i++)
			{
				cout << "\nDati anii in care a participat:";
				in >> m.AniParticipare[i];
			}
		}
		return in;
	}

	char* getmarca()
	{
		return this->marca;
	}

	void setmarca(const char* marca)
	{
		if (strlen(marca) >= 4)
			strcpy(this->marca, marca);
	}

	char* getculoare()
	{
		return this->culoare;
	}

	void setculoare(char culoare[10])
	{
		if (strlen(culoare) >= 3)
			strcpy(this->culoare, culoare);
	}

	int getnrAniParticipare()
	{
		return this->nrAniParticipare;
	}

	void setnrAniParticipare(int nrAniParticipare)
	{
		if (nrAniParticipare > 0)
			this->nrAniParticipare = nrAniParticipare;
	}

	int* getAniParticipare()
	{
		return this->AniParticipare;
	}

	void setAniParticipare(int nrAniParticipare, int* AniParticipare)
	{
		if (this->AniParticipare != NULL)
			delete[]this->AniParticipare;
		if (nrAniParticipare > 0 && AniParticipare != NULL)
		{
			this->nrAniParticipare = nrAniParticipare;
			this->AniParticipare = new int[this->nrAniParticipare];
			for (int i = 0; i < this->nrAniParticipare; i++)
				this->AniParticipare[i] = AniParticipare[i];
		}
	}

	int& operator[](int index)
	{
		if (index >= 0 && index < this->nrAniParticipare)
			return this->AniParticipare[index];
	}

	Masina& operator+=(int an)
	{
		Masina copie = *this;
		delete[]this->AniParticipare;
		this->nrAniParticipare++;
		this->AniParticipare = new int[this->nrAniParticipare];
		for (int i = 0; i < copie.nrAniParticipare; i++)
			this->AniParticipare[i] = copie.AniParticipare[i];
		this->AniParticipare[this->nrAniParticipare - 1] = an;
		return *this;

	}

	Masina operator+ (int an)
	{
		Masina rez = *this;
		rez += an;
		return rez;
	}

	explicit operator int()
	{
		return this->nrAniParticipare;
	}

	Masina operator!()
	{
		Masina rez = *this;
		rez.nrAniParticipare = 0;
		delete[] rez.AniParticipare;
		rez.AniParticipare = NULL;
		return rez;
	}

	bool operator>(Masina m)
	{
		return this->nrAniParticipare > m.nrAniParticipare;
	}

	bool operator==(Masina m)
	{
		bool ok = 0;
		if (this->marca == m.marca && this->culoare == m.culoare && this->nrAniParticipare == m.nrAniParticipare)
			for (int i = 0; i < this->nrAniParticipare; i++)
			{
				if (this->AniParticipare[i] == m.AniParticipare[i])
					ok = 1;
				else
					ok = 0;
			}
		else
			ok = 0;
		return ok;
	}

	~Masina()
	{
		if (this->AniParticipare != NULL)
			delete[]this->AniParticipare;
	}

	void writeToFile(fstream& f)
	{
		//scriere char*
		f.write(this->marca, sizeof(char) * (strlen(this->marca) + 1));
		//scriere sir de caractere (char static)
		//scriere lungime
		int lng = strlen(this->culoare) + 1;
		f.write(this->culoare, sizeof(char) * lng);
		//scriere sir de caractere
		f.write(this->culoare, lng);
		//scriere valoare int
		f.write((char*)&this->nrAniParticipare, sizeof(int));
		//scriere vector de int-uri
		string AniParticipareString;
		for (int i = 0; i < nrAniParticipare; i++)
		{
			AniParticipareString = std::to_string(AniParticipare[i]);
			f.write(AniParticipareString.c_str(), sizeof(char) * (AniParticipareString.length() + 1));
			f.write(" ", sizeof(char) * 2);
		}
	}

	void readFromFile(fstream& f)
	{
		//citire char*
		f.read((char*)&this->marca, sizeof(char) * (strlen(this->marca) + 1));
		//citire sir de caractere
		//citire lg
		int lg = 0;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		strcpy(this->culoare, buffer);
		delete[] buffer;
		//citire int
		f.read((char*)&this->nrAniParticipare, sizeof(int));
		//citire vectorul de int-uri
		delete[] this->AniParticipare;
		if (this->nrAniParticipare > 0)
		{
			this->AniParticipare = new int[this->nrAniParticipare];
			for (int i = 0; i < this->nrAniParticipare; i++)
				f.read((char*)&this->AniParticipare[i], sizeof(int));
		}
	}
};

class Garaj
{
	int nrMasini = 0;
	Masina** listaMasini = NULL;
public:
	Garaj()
	{}

	Garaj(int nrMasini, Masina** listaMasini)
	{
		if (nrMasini > 0 && listaMasini != NULL)
		{
			this->nrMasini = nrMasini;
			this->listaMasini = new Masina * [this->nrMasini];
			for (int i = 0; i < this->nrMasini; i++)
			{
				this->listaMasini[i] = new Masina(*listaMasini[i]);
			}
		}
	}

	Garaj(const Garaj& g)
	{
		if (g.nrMasini > 0 && g.listaMasini != NULL)
		{
			this->nrMasini = g.nrMasini;
			this->listaMasini = new Masina * [this->nrMasini];
			for (int i = 0; i < this->nrMasini; i++)
			{
				this->listaMasini[i] = new Masina(*g.listaMasini[i]);
			}
		}
	}

	Garaj& operator=(const Garaj& g)
	{
		if (this != &g)
		{
			if (g.nrMasini > 0 && g.listaMasini != NULL)
			{
				for (int i = 0; i < this->nrMasini; i++)
				{
					delete this->listaMasini[i];
				}
				delete[] this->listaMasini;

				this->nrMasini = g.nrMasini;
				this->listaMasini = new Masina * [this->nrMasini];
				for (int i = 0; i < this->nrMasini; i++)
				{
					this->listaMasini[i] = new Masina(*listaMasini[i]);
				}
			}
		}
		else
		{
			this->listaMasini = NULL;
			this->nrMasini = 0;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Garaj& g)
	{
		out << "\nNumar masini in garaj:" << g.nrMasini;
		for (int i = 0; i < g.nrMasini; i++)
		{
			out << "\nMasina" << i;
			out << *g.listaMasini[i];
		}
		return out;
	}

	friend istream& operator>>(istream& in, Garaj& g)
	{
		for (int i = 0; i < g.nrMasini; i++)
		{
			delete g.listaMasini[i];
		}
		delete[] g.listaMasini;

		in >> g.nrMasini;
		g.listaMasini = new Masina * [g.nrMasini];
		for (int i = 0; i < g.nrMasini; i++)
		{
			g.listaMasini[i] = new Masina();
			in >> *g.listaMasini[i];
		}
		return in;
	}

	~Garaj()
	{
		for (int i = 0; i < this->nrMasini; i++)
		{
			delete this->listaMasini[i];
		}
		delete[] this->listaMasini;
	}

};

class Menu
{
private:
	static Participant** ListaParticipanti;
	static int nrParticipanti;
	static Traseu** ListaTrasee;
	static int nrTrasee;
	static Sponsor** ListaSponsori;
	static int nrSponsori;
public:
	static void Meniu()
	{
		cout << "\n********************************************************************************\n";
		cout << "\n" << "-*-*-*-*-*- CONCURSUL DE MASINI EDITIA 2022 // MENIU -*-*-*-*-*-\n\n";
		cout << "1) Raport/baza de date participanti.\n";
		cout << "2) Raport/lista lista trasee.\n";
		cout << "3) Raport/baza de date sponsori\n";
		cout << "4) Adaugare participant.\n";
		cout << "5) Adaugare traseu.\n";
		cout << "6) Adaugare sponsor.\n";
		cout << "0) EXIT\n";
		cout << "\nIntroduceti un numar din meniul afisat: ";

		int optiune;
		while (cin >> optiune)
		{
			Participant* p = new Participant();
			Traseu* t = new Traseu();
			Sponsor* s = new Sponsor();
			switch (optiune)
			{
			case 1:
				system("cls");
				afisareListaParticipanti();
				cout << endl << "Pentru revenirea la meniu apasati orice tasta!";
				cin.get();
				cin.get();
				system("cls");
				break;
			case 2:
				system("cls");
				afisareListaTrasee();
				cout << endl << "Pentru revenirea la meniu apasati orice tasta!";
				cin.get();
				cin.get();
				system("cls");
				break;
			case 3:
				system("cls");
				afisareListaSponsori();
				cout << endl << "Pentru revenirea la meniu apasati orice tasta!";
				cin.get();
				cin.get();
				system("cls");
				break;
			case 4:
				system("cls");
				cin >> *p;
				adaugaParticipantLaLista(p);
				afisareListaParticipanti();
				cout << endl << "Pentru revenirea la meniu apasati orice tasta!";
				cin.get();
				cin.get();
				system("cls");
				break;
			case 5:
				system("cls");
				cin >> *t;
				adaugaTraseuLaLista(t);
				afisareListaTrasee();
				cout << endl << "Pentru revenirea la meniu apasati orice tasta!";
				cin.get();
				cin.get();
				system("cls");
				break;
			case 6:
				system("cls");
				cin >> *s;
				adaugaSponsorLaLista(s);
				afisareListaSponsori();
				cout << endl << "Pentru revenirea la meniu apasati orice tasta!";
				cin.get();
				cin.get();
				system("cls");
				break;
			case 0:
				return;
				break;
			default: cout << "EROARE! INPUT INVALID!";
				cin.get();
				cin.get();
				system("cls");
				break;
			}

			cout << "\n********************************************************************************\n";
			cout << "\n" << "-*-*-*-*-*- CONCURSUL DE MASINI EDITIA 2022 // MENIU -*-*-*-*-*-\n\n";
			cout << "1) Raport/baza de date participanti.\n";
			cout << "2) Raport/lista lista trasee.\n";
			cout << "3) Raport/baza de date sponsori\n";
			cout << "4) Adaugare participant.\n";
			cout << "5) Adaugare traseu.\n";
			cout << "6) Adaugare sponsor.\n";
			cout << "0) EXIT\n";
			cout << "\nIntroduceti un numar din meniul afisat: ";
		}
	}

	static void adaugaParticipantLaLista(Participant* part)
	{
		Participant** copieListaParticipanti = NULL;
		if (ListaParticipanti != NULL)
		{
			copieListaParticipanti = new Participant * [nrParticipanti];
			for (int i = 0; i < nrParticipanti; i++)
			{
				copieListaParticipanti[i] = ListaParticipanti[i];
			}
			delete[] ListaParticipanti;
		}
		ListaParticipanti = new Participant * [nrParticipanti + 1];
		for (int i = 0; i < nrParticipanti; i++)
		{
			ListaParticipanti[i] = copieListaParticipanti[i];
		}
		delete[] copieListaParticipanti;
		ListaParticipanti[nrParticipanti] = part;
		nrParticipanti++;
	}

	static void adaugaTraseuLaLista(Traseu* tr)
	{
		Traseu** copieListaTrasee = NULL;
		if (ListaTrasee != NULL)
		{
			copieListaTrasee = new Traseu * [nrTrasee];
			for (int i = 0; i < nrTrasee; i++)
			{
				copieListaTrasee[i] = ListaTrasee[i];
			}
			delete[] ListaTrasee;
		}
		ListaTrasee = new Traseu * [nrTrasee + 1];
		for (int i = 0; i < nrTrasee; i++)
		{
			ListaTrasee[i] = copieListaTrasee[i];
		}
		delete[] copieListaTrasee;
		ListaTrasee[nrTrasee] = tr;
		nrTrasee++;
	}

	static void adaugaSponsorLaLista(Sponsor* sp)
	{
		Sponsor** copieListaSponsori = NULL;
		if (ListaSponsori != NULL)
		{
			copieListaSponsori = new Sponsor * [nrSponsori];
			for (int i = 0; i < nrSponsori; i++)
			{
				copieListaSponsori[i] = ListaSponsori[i];
			}
			delete[] ListaSponsori;
		}
		ListaSponsori = new Sponsor * [nrSponsori + 1];
		for (int i = 0; i < nrSponsori; i++)
		{
			ListaSponsori[i] = copieListaSponsori[i];
		}
		delete[] copieListaSponsori;
		ListaSponsori[nrSponsori] = sp;
		nrSponsori++;
	}

	static void afisareListaParticipanti()
	{
		ofstream fOut("RaportParticipanti.txt", ios::out);

		for (int i = 0; i < nrParticipanti; i++) {
			cout << *ListaParticipanti[i] << endl;
			fOut << *ListaParticipanti[i] << endl;
		}
		fOut.close();
	}

	static void afisareListaTrasee()
	{
		ofstream fOut("RaportTrasee.txt", ios::out);

		for (int i = 0; i < nrTrasee; i++) {
			cout << *ListaTrasee[i] << endl;
			fOut << *ListaTrasee[i] << endl;
		}
		fOut.close();
	}

	static void afisareListaSponsori()
	{
		ofstream fOut("RaportSponsori.txt", ios::out);

		for (int i = 0; i < nrSponsori; i++) {
			cout << *ListaSponsori[i] << endl;
			fOut << *ListaSponsori[i] << endl;
		}
		fOut.close();
	}

	static void scriereBinaraParticipanti()
	{
		fstream fIn("Participanti.bin", ios::out | ios::binary);
		for (int i = 0; i < nrParticipanti; i++)
			ListaParticipanti[i]->writeToFile(fIn);
		fIn.close();
	}

	static void scriereBinaraTrasee()
	{
		fstream fIn("Trasee.bin", ios::out | ios::binary);
		for (int i = 0; i < nrParticipanti; i++)
			ListaTrasee[i]->writeToFile(fIn);
		fIn.close();
	}

	static void scriereBinaraSponsori()
	{
		fstream fIn("Sponsori.bin", ios::out | ios::binary);
		for (int i = 0; i < nrParticipanti; i++)
			ListaSponsori[i]->writeToFile(fIn);
		fIn.close();
	}

};
Participant** Menu::ListaParticipanti = NULL;
int Menu::nrParticipanti = 0;
Traseu** Menu::ListaTrasee = NULL;
int Menu::nrTrasee = 0;
Sponsor** Menu::ListaSponsori = NULL;
int Menu::nrSponsori = 0;

int main()
{
	//FAZA 1
	cout << "\n\n-----------------------------------------------CLASA PARTICIPANT-----------------------------------------------\n\n";
	//CONSTRUCTORI
	cout << "\nApel constructori cu parametri:";
	Participant p1(1, 27);
	cout << p1;
	int editii1[] = { 14,15 };
	char nume1[] = "Popescu Ion";
	Participant p2(2, nume1, 25, 2, editii1);
	cout << p2;
	cout << "\nApel constructor de copiere:";
	Participant p3(p1);
	cout << p3;

	//OPERATOR =
	cout << "\nApel operator =";
	Participant p4 = p2;

	//OPERATORI >> SI <<
	//cin >> p4;
	cout << "\nApel operatori << si >>";
	cout << p4;

	//METODE ACCESOR
	cout << "\nApel metode accesor\n";
	cout << "\nNumele participantului p1:";
	cout << p1.getnumeParticipant() << endl;
	char pnou[] = "Tiberiu Marian";
	p1.setnumeParticipant(pnou);

	cout << "\nVarsta participantului p3:";
	cout << p3.getvarsta() << endl;
	p3.setvarsta(29);

	cout << "\nNumarul de editii la care a participat p4: ";
	cout << p4.getnrEditiiParticipante() << endl;
	p4.setnrEditiiParticipante(1);

	cout << "\nEditiile la care a concurat p2:";
	for (int i = 0; i < p2.getnrEditiiParticipante(); i++)
	{
		cout << p2.geteditiiParticipante()[i] << " | ";
	}
	int editii2[] = { 13 };
	p2.seteditiiParticipante(1, editii2);
	cout << endl;

	//OPERATOR INDEX
	cout << "\nApel operator de indexare";
	float editie = p4[0];
	cout << "\nEditia de pe poz 0 pentru p4: " << editie << endl;

	//OPERATOR +
	cout << "\nApel operator +";
	p1 = p2 + 3;
	cout << p1 << endl;

	//OPERATOR ++ (mareste varsta cu o unitate)
	cout << "\nApel operator ++ forma de preincrementare";
	p2 = ++p3;
	cout << p2 << endl;
	cout << p3 << endl;

	cout << "\nApel operator ++ forma de postincrementare";
	p2 = p3++;
	cout << p2 << endl;
	cout << p3 << endl;

	//OPERATOR CAST EXPLICIT
	cout << "\nApel operator cast";
	cout << "\nVarsta lui p1 este: " << (int)p1 << "ani" << endl;

	//OPERATOR NOT
	cout << "\nApel operator pentru negatie";
	p2 = !p3;
	cout << p2 << endl;

	//OPERATOR >
	cout << "\nApel operator >";
	if (p1 > p4)
		cout << "\np1 are varsta mai mare decat p4" << endl;
	else
		cout << "\np4 are varsta mai mare decat p1" << endl;

	//OPERATOR ==
	cout << "\nApel operator ==";
	if (p1 == p2)
		cout << "\nCei doi participanti sunt identici";
	else
		cout << "\nCei doi participanti NU sunt identici";


	cout << "\n\n-----------------------------------------------CLASA TRASEU-----------------------------------------------\n\n";
	//CONSTRUCTORI
	cout << "\nApel constructori cu parametri:";
	Traseu t1(2.5);
	cout << t1;
	char numetraseu1[] = "Montana";
	float timptururi1[] = { 120, 118 };
	Traseu t2(numetraseu1, 1.7, 2, timptururi1);
	cout << t2;
	cout << "\nApel constructor de copiere:";
	Traseu t3(t2);
	cout << t3;

	//OPERATOR =
	cout << "\nApel operator =";
	Traseu t4 = t1;

	//OPERATORI >> SI <<
	cout << "\nApel operatori << si >>";
	//cin >> t4;
	cout << t4;

	//METODE ACCESOR
	cout << "\nApel metode accesor\n";
	cout << "\nNumele tarseului t2:";
	cout << t2.getnumeTraseu() << endl;
	char numenou[] = "Jurassic";
	t2.setnumeTraseu(numenou);

	cout << "\nLungimea traseului t1:";
	cout << t1.getlungimeTraseu() << endl;
	t1.setlungimeTraseu(2.6);

	cout << "\nNr tururi pe traseul t3: ";
	cout << t3.getnrTururideEfectuat() << endl;
	t3.setnrTururiEfectuate(4);

	cout << "\nTimpii pe traseul t2:";
	for (int i = 0; i < t2.getnrTururideEfectuat(); i++)
	{
		cout << t2.gettimpPeTurEfectuat()[i] << " | ";
	}
	cout << endl;
	float timpi[] = { 140 };
	t1.settimpPeTurEfectuat(1, timpi);

	//OPERATOR INDEX
	cout << "\nApel operator de indexare";
	float timp = t2[1];
	cout << "\nTimpul de pe pozitia 1 pentru t1: " << timp << endl;

	//OPERATOR +
	cout << "\nApel operator +";
	t1 = t2 + 178;
	cout << t1 << endl;

	//OPERATOR ++ (mareste lungimea traseului cu o unitate)
	cout << "\nApel operator ++ forma de preincrementare";
	t2 = ++t1;
	cout << t2 << endl;
	cout << t1 << endl;

	cout << "\nApel operator ++ forma de postincrementare";
	t2 = t1++;
	cout << t2 << endl;
	cout << t1 << endl;

	//OPERATOR CAST EXPLICIT
	cout << "\nApel operator cast explicit";
	cout << "\nLungimea traseului t3: " << (int)t3 << " km" << endl;

	//OPERATOR NOT
	cout << "\nApel operator pentru negatie";
	t2 = !t1;
	cout << t2 << endl;

	//OPERATOR >
	cout << "\nApel operator >";
	if (t1 > t4)
		cout << "\nt1 este un traseu mai lung decat t4" << endl;
	else
		cout << "\nt4 este un traseu mai lung decat t1" << endl;

	//OPERATOR ==
	cout << "\nApel operator ==";
	if (t1 == t2)
		cout << "\nCele doua trasee sunt identice";
	else
		cout << "\nCele doua trasee NU sunt identice";

	cout << "\n\n-----------------------------------------------CLASA SPONSOR-----------------------------------------------\n\n";
	//CONSTRUCTORI
	cout << "\nApel constructori cu parametri:";
	Sponsor s1("Fratelli");
	cout << s1;
	char detinator1[] = "Popescu Razvan";
	float sumeacordate1[] = { 2000,2500,2600 };
	Sponsor s2("5togo", detinator1, 3, sumeacordate1);
	cout << s2;
	cout << "\nApel constructor de copiere:";
	Sponsor s3(s1);
	cout << s3;

	//OPERATOR =
	cout << "\nApel operator =";
	Sponsor s4 = s2;

	//OPERATORI >> SI <<
	cout << "\nApel operatori << si >>";
	//cin >> s4;
	cout << s4;

	//METODE ACCESOR
	cout << "\nApel metode accesor\n";
	cout << "\nNumele companiei care sponsorizeaza pentru s1:";
	cout << s1.getnumeCompanie() << endl;
	char companie1[] = "Dove";
	s1.setnumeCompanie(companie1);

	cout << "\nNumele detinatorului pentru s2:";
	cout << s2.getnumeDetinator() << endl;
	char detinator2[] = "Avramescu Ionut";
	s2.setnumeDetinator(detinator2);

	cout << "\nNr editii sponsorizate pentru s4: ";
	cout << s4.getnrEditiiSponsorizate() << endl;
	s4.setnrEditiiSponsorizate(4);

	cout << "\nSumele acordate de catre s2:";
	for (int i = 0; i < s2.getnrEditiiSponsorizate(); i++)
	{
		cout << s2.getsumeAcordate()[i] << " | ";
	}
	cout << endl;
	float sumeacordate2[] = { 3000,4000,2700,2350 };
	s2.setsumeAcordate(4, sumeacordate2);

	//OPERATOR INDEX
	cout << "\nApel operator de indexare";
	float suma = s2[2];
	cout << "\nSuma de pe pozitia 2 pentru s2: " << suma << endl;

	//OPERATOR +
	cout << "\nApel operator +";
	s4 = s2 + 1600.5;
	cout << s4 << endl;

	//OPERATOR CAST EXPLICIT
	cout << "\nApel operator cast";
	cout << "\nNumarul editiilor sponsorizate de s4 este: " << (int)s4 << " editii" << endl;

	//OPERATOR NOT
	cout << "\nApel operator pentru negatie";
	s2 = !s3;
	cout << s2 << endl;

	//OPERATOR >
	cout << "\nApel operator >";
	if (s1 > s4)
		cout << "\ns1 a fost spor in mai multe editii decat s4" << endl;
	else
		cout << "\ns4 a fost spor in mai multe editii decat s1" << endl;

	//OPERATOR ==
	cout << "\nApel operator ==";
	if (s1 == s2)
		cout << "\nCei doi sponsori sunt identici";
	else
		cout << "\nCei doi sponsori NU sunt identici";


	cout << "\n\n-----------------------------------------------CLASA CLASAMENT-----------------------------------------------\n\n";
	//CONSTRUCTORI
	cout << "\nApel constructori cu parametri:";
	Clasament c1("Premiu de participare");
	cout << c1;
	char arbitru1[] = "Arbitrul Cuza Marian";
	float punctaje1[] = { 134, 47, 88.5, 108.9 };
	Clasament c2(arbitru1, "Cele mai bune skilluri", 4, punctaje1);
	cout << c2;
	cout << "\nApel constructor de copiere:";
	Clasament c3(c2);
	cout << c3;

	//OPERATOR =
	cout << "\nApel operator =";
	Clasament c4 = c2;

	//OPERATORI >> SI <<
	cout << "\nApel operatori << si >>";
	//cin >> c4;
	cout << c4;

	//METODE ACCESOR
	cout << "\nApel metode accesor\n";
	cout << "\nNumele arbitrului pentru c2:";
	cout << c2.getnumeArbitru() << endl;
	char arbitru2[] = "Ionel Marin";
	c2.setnumeArbitru(arbitru2);

	cout << "\nTitlul special pentru c1:";
	cout << c1.gettitluSpecial() << endl;
	char titlu1[] = "Cea mai rezistenta masina";
	c1.settitluSpecial(titlu1);

	cout << "\nNr trasee efectuate pentru c1: ";
	cout << c1.gettraseeEfectuate() << endl;
	c1.settraseeEfectuate(2);

	cout << "\nPunctajele pentru fiecare traseu pentru c4:";
	for (int i = 0; i < c4.gettraseeEfectuate(); i++)
	{
		cout << c4.getpunctajPeTraseu()[i] << " | ";
	}
	cout << endl;
	float punctaje2[] = { 22.4, 55 };
	c1.setpunctajPeTraseu(2, punctaje2);

	//OPERATOR INDEX
	cout << "\nApel operator de indexare";
	float punctaj = c1[0];
	cout << "\nPunctajul de pe pozitia 0 pentru c1: " << punctaj << endl;

	//OPERATOR +
	cout << "\nApel operator +";
	c2 = c4 + 38.9;
	cout << c2 << endl;

	//OPERATOR CAST EXPLICIT
	cout << "\nApel operator cast explicit";
	cout << "\nNumarul traseelor efectuate de c1: " << (int)c1 << " trasee" << endl;

	//OPERATOR NOT
	cout << "\nApel operator pentru negatie";
	c2 = !c3;
	cout << c2 << endl;

	//OPERATOR >
	cout << "\nApel operator >";
	if (c1 > c4)
		cout << "\nc1 a efectuate mai multe trasee decat c4" << endl;
	else
		cout << "\nc4 a efectuate mai multe trasee decat c1" << endl;

	//OPERATOR ==
	cout << "\nApel operator ==";
	if (c1 == c2)
		cout << "\nCele doua clasamente sunt identice";
	else
		cout << "\nCele doua clasamente NU sunt identice";


	cout << "\n\n-----------------------------------------------CLASA MASINA-----------------------------------------------\n\n";
	//CONSTRUCTORI
	cout << "\nApel constructori cu parametri:";
	Masina m1("A107Q", "ALPINE 110");
	cout << m1;
	char culoare1[] = "Negru";
	int aniparticipare1[] = { 2017,2018,2021 };
	Masina m2("776BR", "FORD GT X", culoare1, 3, aniparticipare1);
	cout << m2;
	cout << "\nApel constructor de copiere:";
	Masina m3(m1);
	cout << m3;

	//OPERATOR =
	cout << "\nApel operator=";
	Masina m4 = m2;

	//OPERATORI >> SI <<
	cout << "\nApel operatori << si >>";
	//cin >> m4;
	cout << m4;

	//METODE ACCESOR
	cout << "\nApel metode accesor\n";
	cout << "\nMarca masinii m1:";
	cout << m1.getmarca() << endl;
	char marca1[] = "ALPINE 115";
	m1.setmarca(marca1);

	cout << "\nCuloare masinii m4:";
	cout << m4.getculoare() << endl;
	char culoare2[] = "Gri";
	m4.setculoare(culoare2);

	cout << "\nNr ani participare m1:";
	cout << m1.getnrAniParticipare() << endl;
	m1.setnrAniParticipare(1);

	cout << "\nAnii in care a participat m2 sunt:";
	for (int i = 0; i < m2.getnrAniParticipare(); i++)
	{
		cout << m2.getAniParticipare()[i] << " | ";
	}
	cout << endl;
	int aniparticipare2[] = { 2018 };
	m2.setAniParticipare(1, aniparticipare2);

	//OPERATOR INDEX
	int an = m2[0];
	cout << "\nApel operator de indexare";
	cout << "\nAnul de pe pozitia 0 pentru m2 este: " << an << endl;

	//OPERATOR +
	cout << "\nApel operator +";
	m3 = m2 + 2017;
	cout << m3 << endl;

	//OPERATOR CAST EXPLICIT
	cout << "\nApel operator cast explicit";
	cout << "\nNr ani participare pentru m2 : " << (int)m2 << " ani" << endl;

	//OPERATOR NOT
	cout << "\nApel operator pentru negatie";
	m2 = !m3;
	cout << m2 << endl;

	//OPERATOR >
	cout << "\nApel operator >";
	if (m1 > m4)
		cout << "\nm1 a participat in mai multi ani decat m4" << endl;
	else
		cout << "\nm4 a participat in mai multi ani decat m1" << endl;

	//OPERATOR ==
	cout << "\nApel operator ==";
	if (m1 == m2)
		cout << "\nCele doua masini sunt identice";
	else
		cout << "\nCele doua masini NU sunt identice\n";

	//FAZA 2
	//MENIU + AFISARE RAPOARTE
	Menu meniu;
	meniu.Meniu();
	cout << "\nMeniul a fost inchis!" << endl << endl;

	//SCRIERE RAPOARTE IN FISIERE BINARE
	meniu.scriereBinaraParticipanti();
	meniu.scriereBinaraTrasee();
	meniu.scriereBinaraSponsori();

	//FAZA 3
	//CLASE DERIVATE, CONCEPTUL DE IS A 
	cout << "\n\n------------------------------------MOSTENIRE/CONCEPTUL DE IS A/FAMILIE DE CLASE-----------------------------------\n\n";
	TraseuMontan tm;
	cout << tm;

	char numeTraseu[] = "Alpino777";
	float timpPeTurMontan[] = { 120,180 };
	TraseuMontan tm1(numeTraseu, 4.7, 2, timpPeTurMontan, 5, 1);
	cout << tm1;
	TraseuMontan tm2 = tm1;
	cout << tm2;

	char numeTraseu1[] = "Campas";
	float timpPeTurCampie[] = { 60, 80 };
	TraseuCampie tc1(numeTraseu1, 2.3, 3, timpPeTurCampie, 2, 0);
	cout << tc1;

	FostiCastigatori fc;
	cout << fc;

	char numefc1[] = "Adelin";
	int editiifc1[] = { 11,12,13,14,15 };
	int premiibani[] = { 4000, 5000 };
	FostiCastigatori fc1(5, numefc1, 30, 5, editiifc1, 2, premiibani);
	cout << fc1;
	FostiCastigatori fc2 = fc1;
	cout << fc2;

	cout << "\n\nMETODE VIRTUALE PURE\n";
	cout << fc1.calculCastigMediu();
	cout << fc2.calculPremiiInBaniTotale();
	cout << tm1.descalificare();
	cout << tc1.descalificare();

	cout << "\n\n--------------------------------------------------VIRTUALIZARE---------------------------------------------------\n\n";
	cout << t1.tipClasa() << endl;
	cout << tm1.tipClasa() << endl;
	cout << tc1.tipClasa() << endl;

	Traseu* pTraseu = new Traseu(t1);
	Traseu* pTraseu1 = new TraseuMontan(tm1);
	Traseu* pTraseu2 = new TraseuCampie(tc1);

	cout << pTraseu->tipClasa() << endl;
	cout << pTraseu1->tipClasa() << endl;
	cout << pTraseu2->tipClasa() << endl;

	cout << p1.tipClasa() << endl;
	cout << fc1.tipClasa() << endl;

	Participant* pParticipant = new Participant(p1);
	Participant* pParticipant1 = new FostiCastigatori(fc1);

	cout << pParticipant->tipClasa() << endl;
	cout << pParticipant1->tipClasa() << endl;

	cout << "\nVECTOR DE POINTERI LA CLASA DE BAZA A IERARHIEI";
	int nrObTr = 2;
	Traseu** vectDin = new Traseu * [nrObTr];
	vectDin[0] = &tm1;
	vectDin[1] = &tc1;
	for (int i = 0; i < 2; i++)
	{
		cout << vectDin[i]->tipClasa() << endl;
	}

	cout << "\n\n-------------------------------------------COMPUNERE/CONCEPTUL DE HAS A-------------------------------------------\n\n";
	cout << "\nApel constructor fara parametri";
	Garaj g;
	cout << g << endl;

	cout << "\nApel constructor cu toti parametri";
	Masina* vectMasiniGaraj[3];
	vectMasiniGaraj[0] = &m1;
	vectMasiniGaraj[1] = &m3;
	vectMasiniGaraj[2] = &m4;
	Garaj g1(3, vectMasiniGaraj);
	cout << g1 << endl;

	cout << "\n\n-----------------------------------------STL (Standard Template Library)------------------------------------------\n\n";
	cout << "\nVector STL marci masini STL\n";
	vector<char*> vectm;
	vectm.push_back(m1.getmarca());
	vectm.insert(vectm.begin() + 1, m2.getmarca());
	vectm.push_back(m3.getmarca());
	vectm.insert(vectm.begin() + 3, m4.getmarca());
	vector<char*>::iterator it1;
	for (it1 = vectm.begin(); it1 != vectm.end(); it1++)
		cout << *it1 << " ";
	cout << endl;

	cout << "\nLista STL varste participanti STL\n";
	list<int> lp;
	lp.push_back(p1.getvarsta());
	lp.push_back(p2.getvarsta());
	lp.push_back(p3.getvarsta());
	lp.push_back(p4.getvarsta());
	list<int>::iterator it2;
	for (it2 = lp.begin(); it2 != lp.end(); it2++)
		cout << *it2 << " ";
	cout << endl;

	cout << "\nMap STL clasa Participant\n";
	map<int, Participant> sp;
	sp[1] = p1;
	sp[2] = p2;

	map<int, Participant>::iterator it3;
	for (it3 = sp.begin(); it3 != sp.end(); it3++)
		cout << endl << it3->first << " " << it3->second;

	cout << "\nSet STL nume companii care au fost sponsori\n";
	set<char*> ss;
	ss.insert(s1.getnumeCompanie());
	ss.insert(s3.getnumeCompanie());

	set<char*>::iterator it4;
	for (it4 = ss.begin(); it4 != ss.end(); it4++)
		cout << *it4 << " ";

	return 0;
}

