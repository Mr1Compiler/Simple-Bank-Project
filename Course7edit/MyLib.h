#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>
#include <iomanip>
using namespace std;


namespace MyLib {

	int RandomNumber(int From, int To)
	{

		int randNum = rand() % (To - From + 1) + From;

		return randNum;
	}


	void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				arr[i][j] = RandomNumber(1, 100);
			}
		}
	}

	void PrintMatrix(int arr[3][3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				cout << setw(3) << arr[i][j] << "    ";
			}
			cout << "\n";
		}
	}

	int RowSum(int arr[3][3], short RowNumber, short Cols)
	{
		int Sum = 0;

		for (short j = 0; j < Cols; j++)
		{
			Sum += arr[RowNumber][j];
		}

		return Sum;
	}

	void PrintEachRowSum(int arr[3][3], short Rows, short Cols)
	{
		cout << "\n\nThe following are the sum of each row in the matrix : \n";

		for (short i = 0; i < Rows; i++)
		{
			cout << "Row " << i + 1 << " Sum = " << RowSum(arr, i, Cols) << endl;
		}
	}

	void SumMatrixRowsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols)
	{
		for (int i = 0; i < Rows; i++)
		{
			arrSum[i] = RowSum(arr, i, Cols);
		}
	}

	void PrintRowsSumArray(int arr[3], short Rows)
	{
		cout << "\n\nThe following are the sum of each row in the matrix : \n";

		for (short i = 0; i < Rows; i++)
		{
			cout << "Row " << i + 1 << " Sum = " << arr[i] << endl;
		}
	}

	int ColSum(int arr[3][3], short Rows, short ColNumber)
	{
		int Sum = 0;

		for (short i = 0; i < Rows; i++)
		{
			Sum += arr[i][ColNumber];
		}

		return Sum;
	}

	void PrintEachColSum(int arr[3][3], short Rows, short Cols)
	{
		cout << "\n\nThe following are the sum of each Col in the matrix : \n";

		for (short j = 0; j < Rows; j++)
		{
			cout << "Col " << j + 1 << " Sum = " << ColSum(arr, Rows, j) << endl;
		}
	}

	void SumMatrixColsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols)
	{
		for (short j = 0; j < Cols; j++)
		{
			arrSum[j] = ColSum(arr, Rows, j);
		}
	}

	void PrintColsSumArray(int arr[3], short Cols)
	{
		cout << "\n\nThe following are the sum of each Cols in the matrix : \n";

		for (short j = 0; j < Cols; j++)
		{
			cout << "Col " << j + 1 << " Sum = " << arr[j] << endl;
		}
	}

	void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols)
	{
		short Counter = 0;

		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				arr[i][j] = ++Counter;
			}
		}
	}

	void FillTransposedMatrix(int arr[3][3], int arrTransposed[3][3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				arrTransposed[i][j] = arr[j][i];
			}
		}
	}

	void PrintMatrix(int arr[3][3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				printf("%0*d  ", 2, arr[i][j]);
			}
			cout << "\n";
		}
	}

	void MultiplyMatrix(int Matrix1[3][3], int Matrix2[3][3], int MatrixResult[3][3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				MatrixResult[i][j] = Matrix1[i][j] * Matrix2[i][j];
			}
		}
	}

	void PrintMiddleRowsOfMatrix(int arr[3][3], short Rows, short Cols)
	{
		short MiddleRow = Rows / 2;

		for (short j = 0; j < Cols; j++)
		{
			printf("%0*d  ", 2, arr[MiddleRow][j]);
		}
	}

	void PrintMiddleColOfMatrix(int arr[3][3], short Rows, short Cols)
	{
		short MiddleCol = Cols / 2;

		for (int i = 0; i < Cols; i++)
		{
			printf("%0*d  ", 2, arr[i][MiddleCol]);
		}
	}

	int SumOfMatrix(int Matrix1[3][3], short Rows, short Cols)
	{
		int Sum = 0;

		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				Sum += Matrix1[i][j];
			}
		}
		return Sum;
	}

	bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
	{
		return(SumOfMatrix(Matrix1, Rows, Cols) == SumOfMatrix(Matrix2, Rows, Cols));
	}

	bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (Matrix1[i][j] != Matrix2[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}

	bool IsIdentityMarix(int Matrix1[3][3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (i == j && Matrix1[i][j] != 1)
				{
					return false;
				}
				else if (i != j && Matrix1[i][j] != 0)
				{
					return false;
				}
			}
		}
		return true;
	}

	bool IsScalarMatrix(int Matrix1[3][3], short Rows, short Cols)
	{

		int FirstDiagElemement = Matrix1[0][0];

		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (i == j && Matrix1[i][j] != FirstDiagElemement)
				{
					return false;
				}
				else if (i != j && Matrix1[i][j] != 0)
				{
					return false;
				}
			}
		}
		return true;
	}

	int CountNumberInMatrix(int Matrix[3][3], int NumberToCheck, short Rows, short Cols)
	{
		int NumberCount = 0;

		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (Matrix[i][j] == NumberToCheck)
				{
					NumberCount++;
				}
			}
		}
		return NumberCount;
	}

	bool IsSparceMatrix(int Matrix1[3][3], short Rows, short Cols)
	{
		short MatrixSize = Rows * Cols;
		return (CountNumberInMatrix(Matrix1, 0, 3, 3) >= ceil((float)MatrixSize / 2));
	}

	bool IsNumberExistsInMatrix(int Matrix[3][3], int NumberToSearchFor, short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (Matrix[i][j] == NumberToSearchFor)
				{
					return true;
				}
			}
		}
		return false;
	}

	void PrintIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
	{
		int Number = 0;

		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				Number = Matrix1[i][j];
				if (IsNumberExistsInMatrix(Matrix2, Number, 3, 3))
				{
					cout << Number << "\t";
				}
			}
		}
	}

	int MinNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
	{
		int Min = Matrix[0][0];

		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (Matrix[i][j] < Min)
				{
					Min = Matrix[i][j];
				}
			}
		}
		return Min;
	}

	int MaxNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
	{
		int Max = Matrix[0][0];

		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (Matrix[i][j] > Max)
				{
					Max = Matrix[i][j];
				}
			}
		}
		return Max;
	}

	bool IsPalindromeMatrix(int Matrix[3][3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols / 2; j++)
			{
				if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
				{
					return false;
				}
			}
		}
		return true;
	}

	void PrintFibonacciUsingLoop(short Number)
	{
		int FebNumber = 0;
		int Prev2 = 0, Prev1 = 1;

		cout << "1   ";
		for (short i = 2; i <= Number; i++)
		{
			FebNumber = Prev1 + Prev2;
			cout << FebNumber << "   ";
			Prev2 = Prev1;
			Prev1 = FebNumber;
		}
	}

	void PrintFibonacciUsingRecursion(short Number, int Prev1, int Prev2)
	{

		int FebNumber = 0;

		if (Number > 0)
		{
			FebNumber = Prev1 + Prev2;
			Prev2 = Prev1;
			Prev1 = FebNumber;
			cout << FebNumber << "   ";
			PrintFibonacciUsingRecursion(Number - 1, Prev1, Prev2);
		}
	}


	////////////////////////////////////////////////////////////////////////////////////////////////////// String Problem //////////////////////////////////////////////////////////////////////////////////////////////


	string ReadString()
	{
		string S1;

		cout << "Pleace Enter Your S1ing ? \n";
		getline(cin, S1);

		return S1;
	}

	char ReadChar()
	{
		char Ch1;
		cout << "\nPlease Enter a Character?\n";
		cin >> Ch1;
		return Ch1;
	}

	// Reading this
	void PrintFirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;
		cout << "\nFirst letters of the S1ing: \n";

		for (short i = 0; i <= S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
			{
				cout << S1[i] << endl;
			}

			IsFirstLetter = (S1[i] == ' ' ? true : false);
		}
	}

	string UpperFirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;

		for (int i = 0; i < S1.length(); i++)
		{

			if (S1[i] != ' ' && IsFirstLetter)
			{
				S1[i] = toupper(S1[i]);
			}

			IsFirstLetter = (S1[i] == ' ' ? true : false);
		}

		return S1;
	}
	
	string LowerFirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;

		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
			{
				S1[i] = towlower(S1[i]);
			}

			IsFirstLetter = (S1[i] == ' ' ? true : false);
		}

		return S1;
	}

	string UpperAllString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}

	string LowerAllString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = towlower(S1[i]);
		}
		return S1;
	}

	char InvertLetterCase(char char1)
	{
		return isupper(char1) ? tolower(char1) : toupper(char1);
	}

	string InvertAllLettersCase(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}

	enum enWhatToCount
	{
		SmallLetters = 0,
		CapitalLetters = 1,
		All = 2
	};

	short CountLetters(string S1, enWhatToCount WhatToCount)
	{
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (WhatToCount == enWhatToCount::All)
			{
				return S1.length();
			}

			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
			{
				Counter++;
			}

			if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
			{
				Counter++;
			}
		}
	}

	short CountCapitalLetters(string S1)
	{
		int Counter = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (iswupper(S1[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}

	short CountSmallLetters(string S1)
	{
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}

	short CountLetter(string S1, char Letter)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] == Letter)
			{
				Counter++;
			}
		}
		return Counter;
	}

	short CountLetter(string S1, char Letter, bool MatchCase = true)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (MatchCase)
			{
				if (S1[i] == Letter)
				{
					Counter++;
				}
			}
			else
			{
				if (tolower(S1[i]) == tolower(Letter))
				{
					Counter++;
				}
			}
		}
		return Counter;
	}

	bool IsVowel(char Letter)
	{
		Letter = tolower(Letter);
		return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));
	}

	short CountVowels(string S1)
	{
		short Counter = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (IsVowel(S1[i]))
				Counter++;
		}
		return Counter;
	}

	void PrintVowels(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (IsVowel(S1[i]))
				cout << S1[i] << "    ";
		}
	}

	void PrintEachWordInString(string S1)
	{
		string delim = " ";
		cout << "\nYour String Words are : \n\n";
		short pos = 0;
		string sWord;
		
		for (short i = 0; i < S1.length(); i++)
		{
			while ((pos = S1.find(delim)) != std::string::npos)
			{
				sWord = S1.substr(0, pos);

				if (sWord != "")
				{
					cout << sWord << endl;
				}
				S1.erase(0, pos + delim.length());
			}
		}

		if (S1 != "")
		{
			cout << S1 << endl;
		}
	}

	short CountWords(string S1)
	{
		string delim = " ";
		short pos = 0;
		string sWord;
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			while ((pos = S1.find(delim)) != std::string::npos)
			{
				sWord = S1.substr(0, pos);

				if (sWord != "")
				{
					Counter++;
				}
				S1.erase(0, pos + delim.length());
			}
		}

		if (S1 != "")
		{
			Counter++;
		}

		return Counter;
	}

	vector<string> SplitString(string S1, string Delim)
	{
		vector<string> vString;
		string sWord;
		short pos = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			while ((pos = S1.find(Delim)) != std::string::npos)
			{
				sWord = S1.substr(0, pos);

				if (sWord != "")
				{
					vString.push_back(sWord);
				}
				S1.erase(0, pos + Delim.length());
			}
		}
		if (S1 != "")
		{
			vString.push_back(S1);
		}
		return vString;
	}

	string TrimLeft(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return (S1.substr(i, S1.length() - i));
			}
		}
		return "";
	}

	string TrimRight(string S1)
	{
		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return (S1.substr(0, i + 1));
			}
		}
		return "";
	}

	string Trim(string S1)
	{
		return (TrimLeft(TrimRight(S1)));
	}

	string JoinVector(vector<string> vString, string Delim)
	{
		string S1 = "";

		for (string& s : vString)
		{
			S1 += s + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());
	}

	string JoinVector(string arrString[4], short Length, string Delim)
	{
		string S1 = "";

		for (int i = 0; i < Length; i++)
		{
			S1 += arrString[i] + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());
	}

	string ReverseWordsInString(string S1)
	{
		vector<string> vString;
		string S2 = "";

		vString = SplitString(S1, " ");

		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;

			S2 += *iter + " ";
		}

		S2 = S2.substr(0, S2.length() - 1);

		return S2;
	}

	string ReplaceWordsInsString(string S1, string StringToReplace, string sRepalceTo)
	{
		short pos = S1.find(StringToReplace);

		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
			pos = S1.find(StringToReplace);//find next  
		}

		return S1;
	}

	string ReplaceWordInStringUsingSplit(string S1, string stringStringToReplace, string sReplaceTo, bool MatchCase = true)
	{
		vector<string> vString = SplitString(S1, " ");


		for (string& s : vString)
		{
			if (MatchCase)
			{
				if (s == stringStringToReplace)
				{
					s = sReplaceTo;
				}
			}
			else
			{
				if (LowerAllString(s) == LowerAllString(stringStringToReplace))
				{
					s = sReplaceTo;
				}
			}
		}

		return  JoinVector(vString, " ");
	}

	/*
		very good work for today 28/1/2024  02:05 AM

		keep going

		i realy like it 
	*/
	struct sClient
	{
		string AccountNumber;
		string PinCode;
		string Name;
		string Phone;
		double AccountBalance;
		bool MarkForDelete = false;
	};

	sClient ConvertLineToRecord(string Line, string Seperator = "#//#")
	{
		sClient Client;

		vector<string> vClientData;

		vClientData = SplitString(Line, Seperator);

		Client.AccountNumber = vClientData[0];
		Client.PinCode = vClientData[1];
		Client.Name = vClientData[2];
		Client.Phone = vClientData[3];
		Client.AccountBalance = stod(vClientData[4]);

		return Client;
	}

	void PrintClientRecord(sClient Client)
	{
		cout << "\n\nThe following is the extracted client record:\n";
		cout << "\nAccout Number   : " << setw(2) << Client.AccountNumber;
		cout << "\nPin Code        : " << setw(2) << Client.PinCode;
		cout << "\nName            : " << setw(2) << Client.Name;
		cout << "\nPhone           : " << setw(2) << Client.Phone;
		cout << "\nAccount Balance : " << setw(2) << Client.AccountBalance;
	}

	const string ClientsFileName = "Clients.txt";

	sClient ReadNewClient()
	{
		sClient Client;

		cout << "\nEnter Account Number ? ";
		getline(cin >> ws, Client.AccountNumber);

		cout << "Enter PinCode ? ";
		getline(cin, Client.PinCode);

		cout << "Enter Name ? ";
		getline(cin, Client.Name);

		cout << "Enter Phone ? ";
		getline(cin, Client.Phone);

		cout << "Enter AccountBalance ? ";
		cin >> Client.AccountBalance;

		return Client;
	}

	string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
	{
		string stClientRecord = "";

		stClientRecord += Client.AccountNumber + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += Client.Name + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;
	}

	void AddDataLineToFile(string FileName, string stDataLine)
	{
		fstream MyFile;

		MyFile.open("MyFile.txt", ios::app); // only Write mode check it 

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}

	void AddNewClient()
	{
		sClient Client;
		Client = ReadNewClient();

		AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
	}

	void AddClients()
	{
		char AddMore = 'Y';

		do
		{
			system("cls");
			cout << "Adding New Client : \n";

			AddNewClient();

			cout << "\nClient Added Successfully, do you want to add more clients ?";
			cin >> AddMore;

		} while (toupper(AddMore) == 'Y');
	}

	sClient ConvertLineToRecord(string S1, string Seperator = "#//#")
	{
		sClient Client;

		SplitString(S1, "#//#");

		vector<string> vClientData = SplitString(S1, Seperator);

		Client.AccountNumber = vClientData[0];
		Client.PinCode = vClientData[1];
		Client.Name = vClientData[2];
		Client.Phone = vClientData[3];
		Client.AccountBalance = stod(vClientData[4]);

		return Client;
	}

	vector<sClient> LoadCleintsDataFromFile(string FileName)
	{
		vector<sClient> vClients;

		fstream MyFile;

		MyFile.open(FileName, ios::in);

		if (MyFile.is_open())
		{
			string Line;
			sClient Client;

			while (getline(MyFile, Line))
			{
				Client = ConvertLineToRecord(Line);

				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}

	void PrintClientRecord(sClient Client)
	{
		cout << "| " << setw(15) << left << Client.AccountNumber;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(40) << left << Client.Name;
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(12) << left << Client.AccountBalance;
	}

	void PrintAllClientsData(vector <sClient> vClients)
	{
		cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		for (sClient Client : vClients)
		{
			PrintClientRecord(Client);
			cout << endl;
		}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

	bool FindClientByAccountNumber(string AccountNumber, sClient& Client)
	{

		vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

		for (sClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				Client = C;
				return true;
			}
		}
		return false;
	}

	string ReadClientAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
	}

	void PrintClientCard(sClient Client)
	{
		cout << "\n\nThe following is the extracted client record:\n";
		cout << "\nAccout Number   : " << setw(2) << Client.AccountNumber;
		cout << "\nPin Code        : " << setw(2) << Client.PinCode;
		cout << "\nName            : " << setw(2) << Client.Name;
		cout << "\nPhone           : " << setw(2) << Client.Phone;
		cout << "\nAccount Balance : " << setw(2) << Client.AccountBalance;
	}

	bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient>& vClients)
	{
		for (sClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C.MarkForDelete = true;
				return true;
			}
		}
		return false;
	}

	vector<sClient> SaveCLientDataToFile(string FileName, vector<sClient> vClients)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out);

		string DataLine;

		if (MyFile.is_open())
		{
			for (sClient C : vClients)
			{
				if (C.MarkForDelete == false)
				{
					DataLine = ConvertRecordToLine(C);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}

		return vClients;
	}

	bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient& Client)
	{
		for (sClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				Client = C;
				return true;
			}
		}
		return false;
	}

	bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
	{
		sClient Client;
		char Answer = 'n';

		if (FindClientByAccountNumber(AccountNumber, vClients, Client))
		{
			PrintClientCard(Client);

			cout << "\n\nAre you sure you want to delete this client ? y/n ? ";
			cin >> Answer;

			if (Answer == 'y' || Answer == 'Y')
			{
				MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
				SaveCLientDataToFile(ClientsFileName, vClients);


				vClients = LoadCleintsDataFromFile(ClientsFileName);

				cout << "\n\nClient Deleted Successfully.";
				return true;
			}
		}

		else
		{
			cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
			return false;
		}
	}

	sClient ChangeClientRecord(string AccountNumber)
	{
		sClient Client;

		Client.AccountNumber = AccountNumber;

		cout << "\n\nEnter PinCode? ";
		getline(cin >> ws, Client.PinCode);

		cout << "Enter Name? ";
		getline(cin, Client.Name);

		cout << "Enter Phone? ";
		getline(cin, Client.Phone);

		cout << "Enter AccountBalance? ";
		cin >> Client.AccountBalance;

		return Client;
	}

	bool UpdateCLientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
	{

		sClient Client;
		char Answer = 'n';

		if (FindClientByAccountNumber(AccountNumber, vClients, Client))
		{
			PrintClientCard(Client);

			cout << "\n\nAre you sure you want to update this client ? y/n ? ";
			cin >> Answer;

			if (Answer == 'y' || Answer == 'Y')
			{
				for (sClient& C : vClients)
				{
					if (C.AccountNumber == AccountNumber)
					{
						C = ChangeClientRecord(AccountNumber);
						break;
					}
				}

				SaveCLientDataToFile(ClientsFileName, vClients);

				cout << "\n\nClient Updated Successfully.";
				return true;
			}
		}

		else
		{
			cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
			return false;
		}
	}
}


/*
1- list users
	2- add new user
	3- delete user
	4- update user
	5- find user
	5- main menue

	a new screen contain these 6 points*/