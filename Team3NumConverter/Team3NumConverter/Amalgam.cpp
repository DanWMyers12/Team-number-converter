#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

//Kieu Nguyen
void swap(vector<int>&);
//Brady Moore
char convert_digit_to_letter(int alphanumeral);
int convert_digit_to_decimal(char alphanumeral);
//Dan Myers
bool digitValidate(int base, int num);
int convertToDecimal(vector<int>, int startBase);
//Dalton Mott
string decimalBase(int target, int intValue);


int main()
{
	
	char answer;
	int startBase = 0;
	int endBase = 0;
	int decimal = 0;
	string input;
	string output;
	vector<int> Intvalue;

	//Kieu Nguyen Kicks us off
	do {
		//empties vector for New iteration
		Intvalue.clear();
		//Clear screen for New iteration
		system("cls");
		//Restrict input to base 2-16
		do
		{
			cout << "Enter the original base: ";
			cin >> startBase;
			cout << "Enter the target base: ";
			cin >> endBase;
		} while ((startBase < 2 || startBase > 16) || (endBase < 2 || endBase>16));

		
		//Dan Myers
		bool valid = true;
		do
		{
			//Take input and convert input string to vector
			cout << "Enter the number to be converted: ";
			cin >> input;
			for (int unsigned i = 0; i < input.size(); i++)
			{
				char b = input[i];
				int c = convert_digit_to_decimal(b); //Pass to Brady
				Intvalue.push_back(c);
				if (!digitValidate(startBase, convert_digit_to_decimal(b)))
				{
					valid = false;
						break;
				}
			}
		} while (valid==false);
		//Back to Kieu
		swap(Intvalue);

		//Back to Dan
		decimal = convertToDecimal(Intvalue, startBase);

		//pass to Dalton
		output = decimalBase(endBase, decimal);

		cout << input << " in base " << startBase << ", is equal to " << output << " in base " << endBase;

		cout << "\nDo you want another conversion- (y/n): ";
		cin >> answer;
	} while ((answer == 'y') || (answer == 'Y'));
	return 0;
}



//Brady Moore
char convert_digit_to_letter(int alphanumeral) 
{
	char number;
	if (alphanumeral > 9)
	{
		alphanumeral = 'A' + alphanumeral - 10;
	}
	else
	{
		alphanumeral = '0' + alphanumeral;
	}
	number = alphanumeral;
	return number;
}
int convert_digit_to_decimal(char alphanumeral)
{
	int decimal = alphanumeral - '0';

	if (isupper(alphanumeral))					//Because 'a' and 'A' have different ASCII values
		decimal = alphanumeral - 55;

	else if (islower(alphanumeral))
		decimal = alphanumeral - 87;

	return decimal;
}
//Dan Myers
bool digitValidate(int base, int num)
{
	if (num > base-1)
	{
		cout << "Invalid in number to be converted. Please try again." << endl;
		return false;
	}
	else
	{
		return true;
	}
}
int convertToDecimal(vector<int> startNum, int startBase)
{
	int sum=0;
	for (int unsigned i = 0; i < startNum.size(); i++)
	{
		sum += (startNum.at(i)*(int)pow((double)startBase,(double)i));
	}
	return sum;
}
//Kieu N
void swap(vector<int>& v)
{
	for (unsigned int i = 0; i < v.size() / 2; i++)
	{
		int temp = v[i];
		v[i] = v[(v.size() - 1) - i];
		v[(v.size() - 1) - i] = temp;

	}
	return;

}
//Dalton Mott
//Converts from decimal to target base
string decimalBase(int target, int intValue)
{	// converts from dec to target
		int endNum[1000];
		char endChar[1000];
		int i = 0;
		while (intValue > 0)
		{
			endNum[i] = intValue % target;
			intValue /= target;
			i++;
		}
		for (int j = i - 1; j >= 0; j--)
			endChar[j]= convert_digit_to_letter(endNum[j]);//pass to Brady
		cout << endl;

	 // converts to string via stringstream
		stringstream ss;
		for (int j = i - 1; j >= 0; j--)
		{
			ss << endChar[j];
		}
		string endValue = ss.str();
		return endValue;
}