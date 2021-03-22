#include <iostream>
#include <string>
using namespace std;

int main()
{
	/*
	https://nypc.github.io/2019/2019_online_1.html
	링크
	비밀번호는 8자 이상 15자 이하이어야 한다.
	비밀번호에 영어 대문자가 반드시 포함되어야 한다.
	비밀번호에 영어 소문자가 반드시 포함되어야 한다.
	비밀번호에 숫자가 반드시 포함되어야 한다.
	비밀번호에 특수문자가 반드시 포함되어야 한다.
	*/
	
	// 65 90 97 + 25
	// 대문자 65 ~ 90
	// 소문자 97 ~ 122
	// 숫자 48 ~ 57
	// 특수문자 33 ~ 47 , 58 ~ 64 , 91 ~ 96 , 123 ~ 126

	string str;
	cin >> str;

	bool Can = true;
	bool little = false;
	bool big = false;
	bool special = false;
	bool bnum = false;
	// 대문자, 소문자 검사
	if (str.length() < 8 || str.length() > 15)
	{
		cout << "vaild" << endl;
	}
	else
	{
		for (int i = 0; i < str.length(); i++)
		{
			cout << (int)str[i] << endl;
			if (65 <= (int)str[i] && 90 >= (int)str[i])
			{
				big = true;
			}
			else if (97 <= (int)str[i] && 122 >= (int)str[i])
			{
				little = true;
			}
			else if (48 <= (int)str[i] && 57 >= (int)str[i])
			{
				bnum = true;
			}
			else if ((33 <= (int)str[i] && 47 >= (int)str[i]) ||
				(58 <= (int)str[i] && 64 >= (int)str[i]) || 
				(91 <= (int)str[i] && 96 >= (int)str[i]) || 
				(123 <= (int)str[i] && 126 >= (int)str[i]))
			{
				special = true;
			}
		}

		if (little && big && special && bnum)
			cout << "vaild" << endl;
		else
			cout << "invaild" << endl;
	}
	

	return 0;
}