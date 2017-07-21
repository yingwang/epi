#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef enum {
	WHITE,
	GREY,
	BLACK
} Color;

void RearrangeElements(vector<Color>& elements, int index)
{
	int smaller = 0;
	Color pivot = elements[index]; 
	for (int i = 0; i < elements.size(); i++)
	{
		if (elements[i] < pivot)
		{
			swap(elements[smaller], elements[i]);
			smaller++;
		}
	}
	int larger = elements.size() - 1;
	for (int j = elements.size() - 1; j >= 0; j--)
	{
		if (elements[j] > pivot)
		{
			swap(elements[larger], elements[j]);
			larger--;
		}
	}	
}

int main()
{
	vector<Color> input = {WHITE, GREY, BLACK, WHITE, GREY, WHITE, GREY, WHITE, GREY, BLACK, BLACK, BLACK, WHITE, GREY, BLACK};
	RearrangeElements(input, 6);
	for (const auto& i : input)
	{
		cout << (Color)i << endl;
	}
}