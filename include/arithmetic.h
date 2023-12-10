// ���������� ������� � ������� ��� ���������� �������������� ���������

#include "stack.h"
#include <map>
#include <string>

class TPostfix
{
public:
	TPostfix();

	// ���������� �������� ��������������� ���������
	double evaluate(const std::string& s);
	const std::map<std::string, double>& getVariables() noexcept;
	void clearVariables();

private:
	// �������� ���������������� ����������
	std::map<std::string, double> variables;

	// ���� �������
	enum TokenType
	{
		UN_OP, // ������� ��������
		BIN_OP, // �������� ��������
		FUNC, // �������
		NUM, // �����
		VAR, // ����������
		ASSGN, // �������� ������������, ������������ ��� �������� ���������� � ���������� �� ��������
		LEFT_PARS, // ����� ������� ������
		RIGHT_PARS, // ������ ������� ������
		UNRECG, // �������������� ��������� ��������
	};

	// ����� ����� ����� ����������� ��� ������������ ��������, ��� ����������, ��� ��� � ��� ��������� ��������.
	// �� ��������� ���� ���������� ������� � ��������� �������� ������������� NaN
	struct Token
	{
		std::string s;
		TokenType type;
		double val;
	};
	
	// ����� Parser ������������ ������� ��������� ����� ������ � �����������
	class Parser
	{
	public:
		Parser() noexcept { }
		Token* convertToPostfix(Token* tokens, size_t& sz);

	private:
		inline int operatorPriority(const Token& t) noexcept;
		inline bool isLeftAssoc(const Token& t) noexcept;
	};

	// ����� Tokenizer ������������ ��������� ��������� ��������� �� ������
	class Tokenizer
	{
	public:
		Tokenizer() noexcept { }
		Token* tokenize(const std::string& expr, std::map<std::string, double>& vars, size_t& sz);
		Token tokenizeNumber(const std::string& s, size_t& cur_pos);
		Token tokenizeOperation(const std::string& s, size_t& cur_pos, bool unary);
		Token tokenizeWord(const std::string& s, size_t& cur_pos);

	private:
		// ��������� ��������� ��������, ������������� � �������� �����������
		enum TokenizerState
		{
			TOKEN_INIT,
			TOKENIZE_NUM,
			TOKENIZE_OP,
			TOKENIZE_ASSGN,
			TOKENIZE_LEFT_PAR,
			TOKENIZE_RIGHT_PAR,
			TOKENIZE_WORD, // ��������� ��������������
		};

		// ��������� ��������� ��������, ������������� ��� ��������� �����
		enum NumberTokenizerState
		{
			NT_INIT,
			ZERO_FIRST, // ������ ����� - ����
			NUM1, // ����� ����� �� �����
			NUM2, // ����� ����� ����� �����
			EXP, // ��������� ����� �������
			NUM3, // �������
		};

		inline bool isInvalidVariableName(const std::string& s) noexcept;
	};

	Parser p;
	Tokenizer t;
};