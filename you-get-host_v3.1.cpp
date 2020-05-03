#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<tlhelp32.h>
using namespace std;
DWORD GetProcessidFromName(LPCTSTR name)
{
	PROCESSENTRY32 pe;
	DWORD id=0;
	HANDLE hSnapshot=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	pe.dwSize=sizeof(PROCESSENTRY32);
	if(!Process32First(hSnapshot,&pe)) return 0;
	while(1)
	{
		pe.dwSize=sizeof(PROCESSENTRY32);
		if(Process32Next(hSnapshot,&pe)==FALSE) break;
		if(strcmp(pe.szExeFile,name)==0)
		{
			id=pe.th32ProcessID;
			break;
		}
	}
	CloseHandle(hSnapshot);
	return id;
}
int main()
{
	HWND hwnd=GetForegroundWindow();
	ShowWindow(hwnd,0);
	freopen("temp.vbs","w",stdout);
	printf("a=inputbox(\"视频网址(请不要含空格):\")\nset fso=createobject(\"scripting.filesystemobject\").opentextfile(\"temp.txt\",2)\nfso.write a\n");
	printf("fso.write \" \"\n");
	printf("a=inputbox(\"清晰度(如480，720等),最高清晰度直接回车\")\nfso.write a");
	fclose(stdout);
	freopen("temp.txt","w",stdout);
	fclose(stdout);
	system("start temp.vbs");
	while(GetProcessidFromName("wscript.exe"))
	freopen("temp.txt","r",stdin);
	string x,bb;
	cin>>x>>bb;
	fclose(stdin);
	remove("temp.vbs");
	remove("temp.txt");
	string a;
	if(x=="") return 0;
	if(bb=="") a="you-get -o \%USERPROFILE\%\\downloads "+x;
	else a="you-get --format=flv"+bb+" -o \%USERPROFILE\%\\downloads "+x;
	freopen("temp.bat","w",stdout);
	cout<<a;
	fclose(stdout); 
	system("start temp.bat");
	while(!GetProcessidFromName("cmd.exe"));
	Sleep(1000);
	remove("temp.bat");
	return 0;
}
