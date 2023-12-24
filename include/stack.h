// ���������� � ���������� ���������� �����
// ���� ������������ ��������: 
// - ������� ��������, 
// - ���������� ��������, 
// - �������� �������� �������� (��� ��������)
// - �������� �� �������, 
// - ��������� ���������� ��������� � �����
// - ������� �����
// ��� ������� � ������ ���� ������ �������������� ������

using namespace std;

template <class T>
class TStack {
private:
	T* data;
	size_t size;
	size_t capacity;
	void resize() {
		T* tmp = new T[size * 2];
		for (int i = 0; i < size; i++) {
			tmp[i] = data[i];
		}
		delete[] data;
		data = tmp;
		capacity = size * 2;
	}
public:
	TStack() {
		data = new T[10];
		capacity = 10;
		size = 0;
	}
	~TStack() {
		delete[] data;
		size = 0;
		capacity = 0;
		data = nullptr;
	}
	bool isEmpty() {
		return size == 0;
	}
	T top() {
		if (isEmpty()) {
			throw std::out_of_range("stack is empty");
		}
		else {
			return data[size - 1];
		}
	}
	T pop()
	{
		if (isEmpty()){
			throw out_of_range("stack is empty");
		}
		else {
			return data[--size];
		}
	}
	void push(const T& el) {
		if (size == capacity){
			resize();
		}
		data[size++] = el;
	}

	size_t get_size()
	{
		return size; 
	}
	void clear() {
		size = 0;
		capacity = 10;
		T* tmp = new T[capacity];
		delete[] data;
		data = tmp;
	}
};