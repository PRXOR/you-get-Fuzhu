#include<bits/stdc++.h>
using namespace std;
int main()
{
	printf("Url=");
	string x;
	getline(cin,x);
	string a;
	a="you-get -o %USERPROFILE%\\downloads "+x;
	freopen("temp.bat","w",stdout);
	cout<<a;
	fclose(stdout);
	system("start temp.bat");
	return 0;
}
