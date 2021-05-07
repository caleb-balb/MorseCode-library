
#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;
char alphabet[26] = { 'a','b','c','d', 'e', 'f','g','h', 'i', 'j','k','l','m','n','o','p', 'q', 'r', 's', 't', 'u','v','w','x','y','z' };
string morsealphabet[26] = { "*-", "-***", "-*-*", "-**", "*", "**-*", "--*", "****", "**", "*---", "-*-", "*-**", "--", "-*", "---", "*--*","--*-","*-*","***", "-","**-","***-","*--","-**-", "-*--","--**" };

string englishtomorseSINGLECHAR(char in)
{
	int returnINDEX;
	for (int i = 0; i <= 26; i++)
	{
		if (in == alphabet[i])
		{
			returnINDEX = i;
			break;
		}
		else if (in != alphabet[i])
		{
			returnINDEX = NULL;
		}
	}

	return morsealphabet[returnINDEX];
}
void PLAYMORSE(string playSTR)
{
	for (int i = 0; i < playSTR.size(); i++)
	{
		if (playSTR[i] == '*')
		{
			Beep(300, 150);
		}
		if (playSTR[i] == '-')
		{
			Beep(300, 275);
		}
		if (playSTR[i] == ' ' || playSTR[i] == '/')
		{
			Sleep(50);
		}
		
	}
}
string englishtomorseFULLTEXT(string in)
{
	string returnSTRING = "";
	char findchar;
	for (int x = 0; x <= in.size(); x++)
	{
		findchar = in[x];
		if (findchar == ' ')
		{
			returnSTRING = returnSTRING + " / ";
		}
		if (findchar != ' ')
		{
			for (int i = 0; i <= 26; i++)
			{
				if (findchar == alphabet[i])
				{
					returnSTRING = returnSTRING + morsealphabet[i] + " ";
					break;
				}
			}
		}	
	}
	return returnSTRING;
	
}
string morsetoenglishSINGLECHARACTER(string in)
{
	string returnstring;
	for (int i = 0; i <= 26; i++)
	{
		if (in == morsealphabet[i])
		{
			returnstring = alphabet[i];
			break;
		}
		else if (in != morsealphabet[i])
		{
			returnstring = "";
		}
	}
	return returnstring;
}
vector <string> vec;
string morsetoenglishFULLTEXT(string in) //	for (int y = 0; i < in.size(); i++)
{
	string findstring;
	string finished;
	for (int i = 0; i < in.size(); i++)
	{
		if (in[i] == '/')
		{
			vec.push_back(findstring);
			vec.push_back(" ");
			cout << "pushed back space" << endl;
			findstring = "";
		}
		if (in[i] != ' ' && in[i] != '/')
		{
			cout << "added: " << in[i] << endl;
			findstring += in[i];
		}
		if (in[i] == ' ' && in[i] != '/')
		{
			vec.push_back(findstring);
			cout << "pushed back " << findstring << endl;
			findstring = "";
		}
	}
	if (in[in.size()] != ' ')
	{
		cout << "did last part thingy " << endl;
		vec.push_back(findstring);
		findstring = "";
	}
	for (int x = 0; x < vec.size(); x++)
	{
		findstring = vec[x];
		if (vec[x] == " ")
		{
			finished = finished + " ";
		}
		for (int i = 0; i <= 26; i++)
		{

			if (findstring == morsealphabet[i])
			{
				finished = finished + alphabet[i];
				break;
			}
		}
	}
	return finished;
}
int main()
{
	/* test for translating english to morse code than playing it
	string intoSTR = "hello world";
	string out = englishtomorseFULLTEXT(intoSTR);
	cout << "returned string: " << out << endl;
	PLAYMORSE(out);
	*/
	string intoSTR = "caleb";
	string outSTR;
	outSTR = englishtomorseFULLTEXT(intoSTR);
	cout << "outstr: " << outSTR << endl;
	PLAYMORSE(outSTR);
	
}

