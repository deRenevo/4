#include <iostream>

void AllocArr(int*& arr, const int size)
{
	delete[] arr;
	arr = nullptr;

	if (size < 0)
	{
		return;
	}

	arr = new int[size];
}

void FillRandomArr(int*& arr, const int size)
{
	if (arr == nullptr)
	{
		return;
	}

	for (int i = 0; i < size; ++i)
	{
		arr[i] = rand();
	}
}

void PrintArr(int*& arr, const int size)
{
	if (arr == nullptr)
	{
		std::cout << "Error!" << std::endl;
		return;
	}

	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

void DeleteArr(int*& arr)
{
	if (arr == nullptr)
	{
		return;
	}

	delete[] arr;
	arr = nullptr;
}

void PushBackArr(int*& arr, const int newInt, int& size)
{
	if (arr == nullptr)
	{
		return;
	}

	int* NewArr = new int[size + 1];

	for (int i = 0; i < size; ++i)
	{
		NewArr[i] = arr[i];
	}

	NewArr[size] = newInt;
	delete[] arr;
	arr = NewArr;
	++size;
}

void InsertArr(int*& arr, const int index, const int newInt, int& size)
{
	if (arr == nullptr)
	{
		return;
	}

	if (index < 0 || index > size)
	{
		return;
	}

	int* NewArr = new int[size + 1];
	for (int i = 0; i < index; ++i)
	{
		NewArr[i] = arr[i];
	}

	NewArr[index] = newInt;

	for (int i = index; i < size; ++i)
	{
		NewArr[i + 1] = arr[i];
	}

	delete[] arr;
	arr = NewArr;
	++size;
}

void RemoveArr(int*& arr, const int index, int& size)
{
	if (size <= 0 || index < 0 || index >= size)
	{
		return;
	}

	int* NewArr = new int[size - 1];

	for (int i = 0; i < index; ++i)
	{
		NewArr[i] = arr[i];
	}

	for (int i = index; i < size - 1; ++i)
	{
		NewArr[i] = arr[i + 1];
	}

	delete[] arr;
	arr = NewArr;

	--size;
}

int main()
{
	int* Arr = nullptr;
	int Size = 10;

	AllocArr(Arr, Size);
	FillRandomArr(Arr, Size);
	PrintArr(Arr, Size);
	PushBackArr(Arr, 10, Size);
	PrintArr(Arr, Size);
	InsertArr(Arr, 0, 100, Size);
	PrintArr(Arr, Size);
	RemoveArr(Arr, 1, Size);
	PrintArr(Arr, Size);
	DeleteArr(Arr);
	PrintArr(Arr, Size);

	return 0;
}
