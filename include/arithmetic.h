// ���������� ������� � ������� ��� ���������� �������������� ���������

#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "stack.h"

using namespace std;

class TPostfix
{
private:
	class Lexeme
	{
	public:
		int type_of_lex; //1 - �������� ��������, 2 - '(', 3 - ')',
		//4 - ����������, 5 - ������� �����, 6 - �������: 6, 1 - sin,
		//6, 2 - cos; 6, 3 - tan; 6, 4 - exp; 6, 5 - ln; 7 - �����
		void* lex;
		size_t pos=0; //������ �������� (�� ��������� = 0)
		Lexeme() noexcept {
			lex = nullptr;
			type_of_lex = 0;
			pos = 0;
		}

		Lexeme(const Lexeme&& rv) : type_of_lex(rv.type_of_lex), pos(rv.pos) {
			lex = rv.lex;
		}

		Lexeme(const Lexeme& rv) : type_of_lex(rv.type_of_lex), pos(rv.pos) {
			if (rv.type_of_lex == 1 || rv.type_of_lex == 2 || rv.type_of_lex == 3 || rv.type_of_lex == 5)
			{
				char* tmp = new char((*(char*)rv.lex));
				lex = tmp;
			}
			else if (rv.type_of_lex == 4)
			{
				size_t* tmp = new size_t((*(size_t*)rv.lex));
				lex = tmp;
			}
			else if (rv.type_of_lex == 6)
			{
				int* tmp = new int((*(int*)rv.lex));
				lex = tmp;
			}
			else if (rv.type_of_lex == 7)
			{
				double* tmp = new double((*(double*)rv.lex));
				lex = tmp;
			}
		}

		template <typename T>
		Lexeme(int t_of_l, T op, size_t position=0) : type_of_lex(t_of_l), pos(position)
		{
			lex = new T(op);
		}

		Lexeme& operator=(const Lexeme & rv)
		{
			if (this == &rv)
				return *this;
			pos = rv.pos;
			type_of_lex = rv.type_of_lex;
			if (rv.type_of_lex == 1 || rv.type_of_lex == 2 || rv.type_of_lex == 3 || rv.type_of_lex == 5)
			{
				char* tmp = new char((*(char*)rv.lex));
				lex = tmp;
			}
			else if (rv.type_of_lex == 4)
			{
				size_t* tmp = new size_t((*(size_t*)rv.lex));
				lex = tmp;
			}
			else if (rv.type_of_lex == 6)
			{
				int* tmp = new int((*(int*)rv.lex));
				lex = tmp;
			}
			else if (rv.type_of_lex == 7)
			{
				double* tmp = new double((*(double*)rv.lex));
				lex = tmp;
			}
			return *this;
		}
	};

	Lexeme* Rev_Pol_Notation;  //���
	Lexeme* copy_Rev_Pol_Notation;  //����� ���
	int* arr_num_variable; //������ � �������� ����������
	double* arr_value_variable;//������ �� ���������� ����������
	size_t i = 0, ind_RPN = 0, cap_RPN, ind_variable = 0, cap_variable;
	TStack <Lexeme> ops;	   //stack ������

public:

	TPostfix(string& inp);							//�������, ����� ������� ������������� ��������� ��������� � �����������, �� �� ������, ���
	void duplicate_RPN();							//�������, ����� ������� ����������� ���
	void insert_result(const Lexeme& lex);			//�������, ����� ������� ������ ��������� ������� � ���, �� �� ������, ���
	void insert_variable(int xi);					//�������, ����� ������� ������ ��������� ���������� � ������ ����, �� �� ������, ���
	void asker();									//�������, ����� ������� ������ �������� ����������, �� �� ������, ���
	void input_variables(double* arr, size_t ind); //�������, ����� ������� � ����� ������ ���������� �� �������
	size_t Get_ind_variable();						//�������, ����� ������� ������ ���������� ����������, �� �� ������, ���
	double count();									//�������, ����� ������� ���������� ���������, �� �� ������, ���
};