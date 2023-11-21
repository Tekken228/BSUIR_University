#include <iostream>

class String;
class unique_ptr;
int strleen(const char* str);

/*
// = strrcmp
int strcooll(const char* s1, const char* s2)
{
	setlocale(LC_COLLATE, "");
	return strcoll(s1, s2);
}

int strxxfrm(char* s1, const char* s2, int n)
{
	int len = strlen(s2);
	int i = 0;
	for (i; i < n; i++)
	{
		s1[i] = s2[i];
	}
	s1[i] = '\0';

	return i;
}


*/

// �� ����� ������������
void* memmcpy(void* s1, const void* s2, int n)
{
	char* dest = (char*)s1;
	const char* src = (const char*)s2;
	int i = 0;
	for (i; i < n; ++i)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return s1;
}
// ����� ������������
void* memmmove(void* s1, const void* s2, int n)
{
	char* first = (char*)s1;
	const char* second = (const char*)s2;
	if (first == second)
	{
		return s1;
	}
	if (first < second)
	{
		for (int i = 0; i < n; i++)
		{
			first[i] = second[i];
		}
	}
	else
	{
		for (int i = n; i > 0; i--)
		{
			first[i - 1] = second[i - 1];
		}
	}

	return s1;
}
char* strrcpy(char* s1, const char* str)
{
	if (strleen(s1) < strleen(str))
	{
		s1 = new char[strleen(str) + 2];
	}
	int i = 0;
	while (str[i] != '\0')
	{
		s1[i] = str[i];
		i++;
	}
	s1[i] = '\0';
	return s1;
}
char* strnncpy(char* s1, const char* str, int n)
{
	if (strleen(s1) < n)
	{
		s1 = new char[n + 1];
	}
	int i = 0;
	for (i; i < n && str[i] != '\0'; i++)
	{
		s1[i] = str[i];
	}
	s1[i] = '\0';
	return s1;
}
char* strrcat(char* s1, const char* s2)
{
	char* p = s1;
	while (*p != '\0')
	{
		p++;
	}
	while (*s2 != '\0')
	{
		*p = *s2;
		p++;
		s2++;
	}
	*p = '\0';

	return s1;
}
char* strnncat(char* s1, const char* s2, int n)
{
	if (n > strleen(s2))
	{
		return 0;
	}
	char* p = s1;
	while (*p != '\0')
	{
		p++;
	}
	int i = 0;
	while (i != n)
	{
		*p = *s2;
		p++;
		s2++;
		i++;
	}
	*p = '\0';

	return s1;
}
int memmcmp(const void* s1, const void* s2, int n)
{
	const char* first = (const char*)s1;
	const char* second = (const char*)s2;

	if (n > strleen(first) || n > strleen(second))
	{
		return 1234;
	}

	for (int i = 0; i < n; i++)
	{
		if (first[i] > second[i])
		{
			return 1;
		}
		if (first[i] < second[i])
		{
			return -1;
		}
	}

	return 0;
}
int strrcmp(const char* s1, const char* s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 < *s2)
	{
		return -1;
	}
	else if (*s1 > *s2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int strnccmp(const char* s1, const char* s2, int n)
{
	if (n > strleen(s1) || n > strleen(s2))
	{
		return 1234;
	}
	for (int i = 0; i < n; i++, s1++, s2++)
	{
		if (*s1 < *s2)
		{
			return -1;
		}
		if (*s1 > *s2)
		{
			return 1;
		}
	}
	return 0;
}
char* mystrtok(char* str, const char* delim)
{
	static char* p = 0;
	if (str)
	{
		p = str;
	}
	else if (!p)
	{
		return 0;
	}
	str = p + strspn(p, delim);
	p = str + strcspn(str, delim);
	if (p == str)
	{
		return p = 0;
	}
	if (*p)
	{
		*p = 0;
		p++;
	}
	else
	{
		p = 0;
	}

	return str;
}
void* memmset(void* s, int c, int n)
{
	char* p = (char*)s;
	while (n > 0)
	{
		*p = (char)c;
		p++;
		n--;
	}
	return s;
}
const char* streerror(int errnum)
{
	switch (errnum)
	{
	case 0:
		return "�������";
	case 1:
		return "� ���������� ��������";
	case 2:
		return "�������� �� ���������";
	case 3:
		return "������ �� ��������";
	case 4:
		return "������ ����� ��� �������� ���";
	default:
		return "����������� ������";
	}
}
int strleen(const char* str)
{
	int length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return length;
}

class unique_ptr
{
private:
	char* ptr;
public:
	operator bool() const
	{
		return ptr != nullptr;
	}
	unique_ptr(char* pointer = nullptr)
	{
		ptr = pointer;
	}
	~unique_ptr()
	{
		if (ptr != nullptr)
			delete ptr;
	}
	unique_ptr(unique_ptr&& x)
	{
		ptr = x.ptr;
		x.ptr = nullptr;
	}
	unique_ptr& operator=(unique_ptr&& x)
	{
		if (&x == this)
		{
			return *this;
		}
		if (ptr == nullptr)
			delete ptr;
		ptr = x.ptr;
		x.ptr = nullptr;
		return *this;
	}
	// ��������� ����� �����������
	unique_ptr(const unique_ptr& x) = delete;
	unique_ptr& operator=(unique_ptr& a) = delete;

	char& operator[](int index)
	{
		return *(get() + index);
	}

	void swap(unique_ptr& other)
	{
		std::swap(ptr, other.ptr);
	}
	// ����������� ����� ���������
	char* release()
	{
		char* tmp = ptr;
		ptr = nullptr;
		return tmp;
	}
	// �������� ������
	void reset(char* data = nullptr)
	{
		if (ptr != nullptr)
		{
			delete ptr;
			ptr = data;
		}
	}
	char& operator*() const
	{
		return *ptr;
	}
	char* operator->() const
	{
		return ptr;
	}
	bool isNull() const
	{
		return ptr == nullptr;
	}
	char* get() const
	{
		return ptr;
	}
};

class iterator
{
private:
	char* ptr;
public:
	iterator()
	{
		ptr = nullptr;
	}
	iterator(char* p)
	{
		ptr = p;
	}
	bool operator==(const iterator& rhs) const
	{
		return ptr == rhs.ptr;
	}
	bool operator!=(const iterator& rhs) const
	{
		return !(*this == rhs);
	}
	bool operator >(const iterator& rhs) const
	{
		return (*this > rhs);
	}
	bool operator <(const iterator& rhs) const
	{
		return (*this < rhs);
	}
	bool operator >=(const iterator& rhs) const
	{
		return (*this >= rhs);
	}
	bool operator <=(const iterator& rhs) const
	{
		return (*this <= rhs);
	}
	const char& operator*()
	{
		return *ptr;
	}
	iterator& operator= (const iterator& other)
	{
		ptr = other.ptr;
		return  *this;
	}
	iterator& operator++()
	{
		++ptr;
		return *this;
	}
	iterator operator++(int)
	{
		iterator temp(*this);
		++* this;
		return temp;
	}
	iterator& operator--()
	{
		--ptr;
		return *this;
	}
	iterator operator--(int)
	{
		iterator temp(*this);
		--* this;
		return temp;
	}
	iterator operator+(int n)
	{
		return iterator(ptr + n);
	}
	iterator operator-(int n)
	{
		return iterator(ptr - n);
	}
	const iterator cend() const;
	const iterator cbegin() const;
	iterator begin();
	iterator rbegin();
	iterator rend();
	iterator end() const;
};

class String : public iterator
{
public:
	unique_ptr arr;
	int Size;
	int Capacity;
public:
	const iterator cend() const
	{
		return iterator(arr.get() + Size);
	};
	const iterator cbegin() const
	{
		return iterator(arr.get());
	};
	iterator begin()
	{
		return iterator(arr.get());
	};
	iterator rbegin()
	{
		return iterator(arr.get() + Size);
	};
	iterator rend()
	{
		return iterator(arr.get());
	};
	iterator end() const
	{
		return iterator(arr.get() + Size);
	};
	char& operator[](int index)
	{
		return *(arr.get() + index);
	}
	String()
	{
		Size = 0;
		Capacity = 5;
		arr = new char[Capacity];
	}
	String(String&& other) noexcept
	{
		arr = std::move(other.arr);
		Size = std::move(other.Size);
	}
	String(const char* str)
	{
		Size = strleen(str);
		arr = new char[Size + 1];
		strcpy(str);
		Capacity = Size;
	}
	String(const String& other)
	{
		Size = other.Size;
		arr = new char[other.Capacity + 1];
		strcpy(other.arr.get());
		Capacity = Size;
	}
	String& operator=(const char* other)
	{
		Size = strleen(other);
		arr = new char[Size + 1];
		strcpy(other);
		Capacity = Size;
		return *this;
	}
	String& operator=(const String& other)
	{
		Size = strleen(other.arr.get());
		arr = new char[Size + 1];
		strcpy(other.arr.get());
		Capacity = Size;
		return *this;
	}
	String& operator+(String& other)
	{
		String dop;
		int otherLength = strlen(other.arr.get());
		int thisLength = strlen();
		dop.arr = new char[otherLength + thisLength + 1];
		int i = 0;
		for (; i < thisLength; i++)
		{
			dop[i] = arr[i];
		}
		for (int j = 0; j < otherLength; j++, i++)
		{
			dop[i] = other.arr[j];
		}
		dop.arr[otherLength + thisLength] = '\0';
		return dop;
	}
	String& operator+=(String& other)
	{
		String dop;
		int otherLength = strlen(other.arr.get());
		int thisLength = strlen();
		dop.arr = new char[otherLength + thisLength + 1];
		char* new_str = new char[otherLength + thisLength + 1];
		int i = 0;
		for (; i < thisLength; i++)
		{
			dop[i] = arr[i];
			new_str[i] = arr[i];
		}
		for (int j = 0; j < otherLength; j++, i++)
		{
			dop[i] = other.arr[j];
			new_str[i] = other.arr[j];
		}
		dop.arr[otherLength + thisLength] = '\0';
		new_str[otherLength + thisLength] = '\0';
		delete[] arr.get();
		arr = new_str;
		Size = otherLength + thisLength;
		Capacity = Size;

		return *this;
	}
	bool operator==(String& other)
	{
		if (Size != other.Size)
		{
			return false;
		}
		for (int i = 0; i < Size; i++)
		{
			if (arr[i] != other.arr[i])
			{
				return false;
			}
		}
		return true;
	}
	bool operator!=(String& other)
	{
		if (Size != other.Size)
		{
			return true;
		}
		for (int i = 0; i < Size; i++)
		{
			if (arr[i] != other.arr[i])
			{
				return true;
			}
		}
		return false;
	}
	void print()
	{
		for (int i = 0; i < Size; i++)
		{
			std::cout << arr[i];
		}
	}
	int length() const
	{
		return Size;
	}
	int capacity() const
	{
		return Capacity;
	}
	const char* c_str() const
	{
		return arr.get();
	}
	void push_back(char a)
	{
		if (Size >= Capacity)
		{
			reserve(Capacity * 2);
		}
		char* str = new char[Capacity + 1];
		for (int i = 0; i < Size; i++)
		{
			str[i] = arr[i];
		}
		str[Size] = '\0';
		Size++;
		arr = new char[Size + 1];
		arr = str;
		arr[Size - 1] = a;
		arr[Size] = '\0';
	}
	void reserve(int new_capacity)
	{
		if (new_capacity <= Capacity)
		{
			return;
		}
		char* new_arr = new char[new_capacity];
		for (int i = 0; i < Size; i++)
		{
			new_arr[i] = arr[i];
		}
		new_arr[Size] = '\0';
		delete[] arr.get();
		arr = new_arr;
		Capacity = new_capacity;
	}
	void resize(int n, char value = ' ')
	{
		if (n < Size)
		{
			Size = n;
		}
		else if (n > Capacity)
		{
			reserve(n);
			for (int i = Size; i < n; i++)
			{
				arr[i] = value;
			}
			Size = n;
			arr[Size] = '\0';
		}
		else
		{
			for (int i = Size; i < n; i++)
			{
				arr[i] = value;
			}
			Size = n;
			arr[Size] = '\0';
		}
	}
	void pop_back()
	{
		if (Size != 0)
		{
			char* str = new char[Capacity];
			for (int i = 0; i < Size - 1; i++)
			{
				str[i] = arr[i];
			}
			Size--;
			arr = new char[Capacity + 1];
			arr = str;
			arr[Size] = '\0';
		}
	}
	bool empty()
	{
		return Size == 0;
	}
	size_t max_size()
	{
		return (size_t)-1 / sizeof(char);
	}
	char& back()
	{
		if (empty())
		{
			throw std::out_of_range("String is empty.");
		}
		else
		{
			return arr[Size - 1];
		}
	}
	char& front()
	{
		if (empty())
		{
			throw std::out_of_range("String is empty.");
		}
		else
		{
			return arr[0];
		}
	}
	char* data()
	{
		if (empty())
		{
			throw std::out_of_range("Vector is empty.");
		}
		else
		{
			return &arr[0];
		}
	}
	char& at(int index)
	{
		if (index < 0 || index >= Size)
		{
			throw std::out_of_range("Vector is empty.");
		}
		else
		{
			return arr[index];
		}
	}
	void clear()
	{
		Size = 0;
		Capacity = 5;
		delete[] arr.get();
		arr = new char[Capacity];
	}
	void erase(int index)
	{
		if (index < 0 || index >= Size)
		{
			throw std::out_of_range("Out of ranfe.");
		}
		for (int i = index; i < Size - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		char* new_arr = new char[Size];
		for (int i = 0; i < Size - 1; i++)
		{
			new_arr[i] = arr[i];
		}
		new_arr[Size - 1] = '\0';
		delete[] arr.get();
		arr = new_arr;
		--Size;
	}
	void erase(int index, int count)
	{
		if (index < 0 || index >= Size || index + count >= Size)
		{
			std::cout << "����� �� �������\n";
			return;
		}
		if (count < 0)
		{
			std::cout << "�� �� ��������\n";
			return;
		}
		for (int i = index + count; i < Size; i++)
		{
			arr[i - count] = arr[i];
		}
		char* new_arr = new char[Size];
		for (int i = 0; i < Size - 1; i++)
		{
			new_arr[i] = arr[i];
		}
		new_arr[Size - count] = '\0';
		delete[] arr.get();
		arr = new_arr;
		Size -= count;
	}
	void insert(int index, char value)
	{
		if (index < 0 || index > Size)
		{
			throw std::out_of_range("Out of ranfe.");
		}
		if (Capacity <= Size + 1)
		{
			reserve(Capacity * 2);
		}
		for (int i = Size; i > index; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[index] = value;
		Size++;
		arr[Size] = '\0';
	}
	void insert(int index, int amount, char value)
	{
		if (amount <= 0)
		{
			std::cout << "����������� ����������";
			return;
		}
		if (index < 0 || index > Size)
		{
			throw std::out_of_range("Out of ranfe.");
		}
		if (Capacity < Size + amount)
		{
			reserve(Capacity * 2);
		}
		Size += amount;
		for (int i = Size - 1; i >= index + amount; i--)
		{
			arr[i] = arr[i - amount];
		}
		for (int i = index; i < index + amount; i++)
		{
			arr[i] = value;
		}
		arr[Size] = '\0';
	}
	void swap(String& other)
	{
		std::swap(this->Capacity, other.Capacity);
		std::swap(this->Size, other.Size);
		std::swap(this->arr, other.arr);
	}
	void assign(int count, char values)
	{
		clear();
		reserve(count);
		for (int i = 0; i < count; i++)
		{
			push_back(values);
		}
	}
	void assign(int count, String& values)
	{
		clear();
		reserve(count);
		for (int i = 0; i < count; i++)
		{
			push_back(values[i]);
		}
	}
	void assign(String& values)
	{
		clear();
		reserve(values.Size);
		for (int i = 0; i < values.Size; i++)
		{
			push_back(values[i]);
		}
	}
	void shrink_to_fit() 
	{
		if (Size == Capacity) 
		{
			return;
		}
		char* new_arr = new char[Size + 1];
		for (int i = 0; i < Size; i++)
		{
			new_arr[i] = arr[i];
		}
		new_arr[Size] = '\0';
		delete[] arr.get();
		arr = new_arr;
		Capacity = Size;
	}
	void append(String& str) 
	{
		reserve(Size + str.Size);
		for (int i = 0; i < str.Size; i++) 
		{
			push_back(str[i]);
		}
	}
	void append(const char* s) 
	{
		reserve(Size + strleen(s));
		while (*s != '\0') 
		{
			push_back(*s);
			s++;
		}
	}
	void append(const char* s, int n) 
	{
		reserve(Size + n);
		for (int i = 0; i < n && *s != '\0'; i++) 
		{
			push_back(*s);
			s++;
		}
	}
	int copy(char* dest, int count, int pos) const 
	{
		int len = length();
		if (pos >= len)
		{
			return 0;
		}
		int n = std::min(count, len - pos);
		memmcpy(dest, arr.get() + pos, n);
		dest[n] = '\0';
		return n;
	}
	// �� ����� ������������
	void* memcpy(const void* s2, int n)
	{
		char* dest = (char*)arr.get();
		const char* src = (const char*)s2;
		int i = 0;
		for (i; i < n; ++i)
		{
			dest[i] = src[i];
		}
		dest[i] = '\0';
		return arr.get();
	}
	// ����� ������������
	void* memmmove(const void* s2, int n)
	{
		char* first = (char*)arr.get();
		const char* second = (const char*)s2;
		if (first == second)
		{
			return arr.get();
		}
		if (first < second)
		{
			for (int i = 0; i < n; i++)
			{
				first[i] = second[i];
			}
		}
		else
		{
			for (int i = n; i > 0; i--)
			{
				first[i - 1] = second[i - 1];
			}
		}

		return arr.get();
	}
	char* strcpy(const char* str)
	{
		int i = 0;
		arr = new char[strleen(str) + 1];
		Size = 0;
		while (str[i] != '\0')
		{
			arr[i] = str[i];
			i++;
			Size++;
		}
		arr[Size] = '\0';
		return arr.get();
	}
	char* strncpy(const char* str, int n)
	{
		if (strleen(arr.get()) < n)
		{
			arr = new char[n + 1];
		}
		int i = 0;
		for (i; i < n && str[i] != '\0'; i++)
		{
			arr.get()[i] = str[i];
		}
		arr.get()[i] = '\0';
		return arr.get();
	}
	char* strrcat(const char* s2)
	{
		char* p = arr.get();
		while (*p != '\0')
		{
			p++;
		}
		while (*s2 != '\0')
		{
			*p = *s2;
			p++;
			s2++;
		}
		*p = '\0';

		return arr.get();
	}
	char* strncat(const char* s2, int n)
	{
		if (n > strleen(s2))
		{
			return 0;
		}
		char* p = arr.get();
		while (*p != '\0')
		{
			p++;
		}
		int i = 0;
		while (i != n)
		{
			*p = *s2;
			p++;
			s2++;
			i++;
		}
		*p = '\0';

		return arr.get();
	}
	int memcmp(const void* s2, int n)
	{
		const char* first = (const char*)arr.get();
		const char* second = (const char*)s2;

		if (n > strleen(first) || n > strleen(second))
		{
			return 1234;
		}

		for (int i = 0; i < n; i++)
		{
			if (first[i] > second[i])
			{
				return 1;
			}
			if (first[i] < second[i])
			{
				return -1;
			}
		}

		return 0;
	}
	int strcmp(const char* s2)
	{
		const char* first = (const char*)arr.get();
		while (*first && *s2 && *first == *s2)
		{
			first++;
			s2++;
		}
		if (*first < *s2)
		{
			return -1;
		}
		else if (*first > *s2)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	// = strrcmp
	/*
	int strcoll(const char* s2)
	{
		setlocale(LC_COLLATE, "");
		return std::strcoll(arr.get(), s2);
	}
	*/
	int strncmp(const char* s2, int n)
	{
		const char* first = (const char*)arr.get();
		if (n > strleen(first) || n > strleen(s2))
		{
			return 1234;
		}
		for (int i = 0; i < n; i++, first++, s2++)
		{
			if (*first < *s2)
			{
				return -1;
			}
			if (*first > *s2)
			{
				return 1;
			}
		}
		return 0;
	}
	/*
	int strxfrm(const char* s2, int n)
	{
		int len = strleen(s2);
		int i = 0;
		for (i; i < n; i++)
		{
			arr[i] = s2[i];
		}
		arr[i] = '\0';

		return i;
	}
	*/
	char* mystrtok(char* str, const char* delim)
	{
		static char* p = 0;
		if (str)
		{
			p = str;
		}
		else if (!p)
		{
			return 0;
		}
		str = p + strspn(p, delim);
		p = str + strcspn(str, delim);
		if (p == str)
		{
			return p = 0;
		}
		if (*p)
		{
			*p = 0;
			p++;
		}
		else
		{
			p = 0;
		}

		return str;
	}
	void* memmset(int c, int n)
	{
		char* p = (char*)arr.get();
		while (n-- > 0)
		{
			*p = static_cast<char>(c);
			p++;
		}
		return arr.get();
	}
	const char* strerror(int errnum)
	{
		switch (errnum)
		{
		case 0:
			return "�������";
		case 1:
			return "� ���������� ��������";
		case 2:
			return "�������� �� ���������";
		case 3:
			return "������ �� ��������";
		case 4:
			return "������ ����� ��� �������� ���";
		default:
			return "����������� ������";
		}
	}
	int strlen(const char* str)
	{
		int length = 0;
		while (str[length] != '\0')
		{
			length++;
		}
		return length;
	}
	int strlen()
	{
		int length = 0;
		while (arr[length] != '\0')
		{
			length++;
		}
		return length;
	}
};




int main()
{
	std::string a;
	a.push_back('f');
	

	setlocale(LC_ALL, "ru");
	char arr[] = "Hello, world!";
	char dest[] = "123455";

	String bb;
	bb.push_back('1');
	bb.push_back('2');
	bb.push_back('3');
	bb.push_back('4');

	//bb.print();

	String qwef;
	qwef.append(bb);
	qwef.print();
//	std::cout << bb.front();

	std::cout << '\n';
	std::cout << '\n';
	std::cout << '\n';


	std::cout << strrcpy(dest, arr) << '\n';
	std::cout << dest << '\n';
	std::cout << strnncpy(dest, arr, 13) << '\n';

	memmcpy(dest, arr, 5);
	std::cout << arr << '\n';

	char str[] = "123456";
	std::cout << str << '\n';
	memmmove((void*)(str + 1), ((void*)(str + 2)), 2);
	std::cout << str << '\n';

	char s1[50] = "Hello";
	char s2[] = ", PIVOOO!";
	strrcat(s1, s2);
	std::cout << s1 << '\n';

	char ss[50] = "Hello";
	char ss2[] = "PIVOOO!";
	strnncat(ss, ss2, 7);
	std::cout << ss << '\n';

	char str1[] = "Hello";
	char str2[] = "Hello";
	char str3[] = "Hells";
	int result1 = memmcmp(str1, str2, 6);
	int result2 = memmcmp(str1, str3, 5);
	result1 = 111;
	result2 = 111;
	//result1 = strcooll(str1, str2);
	//result2 = strcooll(str1, str3);

	char z[] = "hello world";
	char x[] = "hello worla";
	char c[] = "hello worlf";
	std::cout << strnccmp(z, x, 12) << '\n';
	std::cout << strnccmp(z, c, 11) << '\n';
	std::cout << strnccmp(c, z, 11) << '\n';

	char qwe[20];
	char fff[] = "AFGG, world!";
	//int len = strxxfrm(qwe, fff, 5);
	std::cout << qwe << "\n";
	//std::cout << len << "\n";

	char strr[] = "Hello, world! How are you?";
	char delims[] = " ,!?";
	char* tok;
	tok = mystrtok(strr, delims);
	while (tok != nullptr)
	{
		std::cout << tok << '\n';
		tok = mystrtok(nullptr, delims);
	}

	char myArr[] = "12345678910111213";
	memmset(myArr, '_', 10);
	std::cout << myArr << '\n';

	int n = 3;
	std::cout << streerror(54) << '\n';

	String v("qwe");
	String q(v);
	std::cout << q.c_str() << "\n";
	q = "zxcc";
	std::cout << q.c_str() << '\n';
	q = "zzz";

	String zxc;
	zxc = "132";
	//zxc.strcpy(myArr);
	//std::cout << zxc.strcoll("132");

	zxc += q;
	zxc.push_back('u');
	zxc.pop_back();
	//zxc.resize(10, '-');
	std::cout << zxc.c_str();

	std::cout << (zxc == q);

	String res;
	res = v + zxc;
	std::cout << '\n' << res.c_str() << '\n';

	v += zxc;
	std::cout << '\n' << v.c_str() << '\n';
	v.print();
	std::cout << '\n';

	std::cout << v.empty() << '\n';
	std::cout << v.max_size() << '\n';
	std::cout << v.back() << '\n';
	v.back() = 'a';
	std::cout << v.back() << '\n';
	std::cout << v.front() << '\n';
	v.front() = 'b';
	std::cout << v.front() << '\n';

	String qw("Hello Wolrd");
	char buffer[6];

	qw.copy(buffer, 5, 7);
	//buffer[5] = '\0';
	
	std::cout << buffer << '\n';

	std::cout << v.c_str() << '\n';
	v.print();

	return 0;
}